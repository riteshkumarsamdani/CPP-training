#include <iostream>
#include <memory>
using namespace std;

class Rectangle
{
        int length;
        int breadth;

    public:
        Rectangle(int l, int b)
        {
            length = l;
            breadth = b;
        }

        int area() { return length * breadth; }
};

int main()
{
    shared_ptr<Rectangle> P1(new Rectangle(10, 5));
    weak_ptr<Rectangle> P2 (P1);
    cout << P1->area() << endl;
    cout << P2.use_count();
    return 0;
}
