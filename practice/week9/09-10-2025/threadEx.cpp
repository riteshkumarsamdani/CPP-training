#include <iostream>
#include <thread>
#include <deque>
#include <vector>
#include <condition_variable>
#include <mutex>

using namespace std;

const int NUM_LANES = 4;
const int LANE_CAPACITY = 5;

class ThreadSafeLanes {
public:
    void insert(const std::vector<int>& job) {
        int lane_id = -1;
        {
            unique_lock<mutex> lock(headMutex);
            cv_has_space.wait(lock, [this, &lane_id] {
                return (lane_id = getFreeBufferId()) != -1;
            });
            VecOfQue[lane_id].push_back(job[lane_id]);
        }
        cv_has_data.notify_one();
    }

    void remove() {
        while (true) {
            int lane_id = -1;
            int item;
            {
                unique_lock<mutex> lock(headMutex);
                cv_has_data.wait(lock, [this, &lane_id] {
                    for (int i = 0; i < NUM_LANES; ++i) {
                        if (!VecOfQue[i].empty()) {
                            lane_id = i;
                            return true;
                        }
                    }
                    return false;
                });
                
                item = VecOfQue[lane_id].front();
                VecOfQue[lane_id].pop_front();
            }
            
            cout << "Consumed item " << item << " from lane " << lane_id << endl;
            cv_has_space.notify_one();
            this_thread::sleep_for(chrono::milliseconds(500));
        }
    }

private:
    int getFreeBufferId() {
        for (int i = 0; i < NUM_LANES; ++i) {
            if (VecOfQue[i].size() < LANE_CAPACITY) {
                return i;
            }
        }
        return -1;
    }

    std::mutex headMutex;
    std::condition_variable cv_has_space;
    std::condition_variable cv_has_data;
    std::deque<int> VecOfQue[NUM_LANES];
};

void producer_task(ThreadSafeLanes& lanes, const std::vector<int>& job) {
    lanes.insert(job);
}


int main() {
    ThreadSafeLanes lanes;
    std::thread con(&ThreadSafeLanes::remove, &lanes);
    std::vector<std::thread> producerThreads;
    for (int i = 0; i < 10; ++i) {
        std::vector<int> job = {i * 1, i * 2, i * 3, i * 4};
        producerThreads.push_back(std::thread(producer_task, std::ref(lanes), std::ref(job)));
    }
    for (auto& thread : producerThreads) {
        thread.join();
    }
    con.detach();
    return 0;
}
