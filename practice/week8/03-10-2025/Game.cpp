#include <iostream>
#include <vector>
#include <algorithm>

class Game
{
    private:
        int mStrength;
        int mPower;
    public:
        Game(int strength, int power) : mStrength(strength), mPower(power){};
        bool operator<(const Game& rh)
        {
            return this->mStrength < rh.mStrength;
        }
        int getStrength() const
        {
            return mStrength;
        }
        int getPower() const
        {
            return mPower;
        }
};

class Comparator
{
    public:
        bool operator()(const Game& a, const Game& b) 
        {
            return a.getPower() < b.getPower();
        }
};

int main()
{
    std::vector<Game> objects = {Game(10,60), Game(70,40), Game(50,40)};
    std::sort(objects.begin(),objects.end(), Comparator());
    for(auto i : objects)
    {
        std::cout << i.getStrength() << " ";
    }
    return 0;
}