#include <iostream>

class IShape {
public:
    virtual void draw() = 0; 
    virtual double area() = 0;
    virtual ~IShape() {} 
};

class Circle : public IShape {
    double radius;
public:
    Circle(double r) : radius(r) {}
    void draw() override {
        std::cout << "Drawing a Circle\n";
    }
    double area() override {
        return 3.14159 * radius * radius;
    }
};

class Rectangle : public IShape {
    double width, height;
public:
    Rectangle(double w, double h) : width(w), height(h) {}
    void draw() override {
        std::cout << "Drawing a Rectangle\n";
    }
    double area() override {
        return width * height;
    }
};

int main() {
    IShape* shape1 = new Circle(5.0);
    IShape* shape2 = new Rectangle(4.0, 6.0);
    shape1->draw();
    std::cout << "Area: " << shape1->area() << "\n";
    shape2->draw();
    std::cout << "Area: " << shape2->area() << "\n";
    delete shape1;
    delete shape2;
    return 0;
}
