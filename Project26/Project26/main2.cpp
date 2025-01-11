#include <iostream>
#include <cmath>     
#include <vector>    
#include <memory>    

const double PI = 3.14;

class Shape {
public:
    virtual double Area() const = 0; 
    virtual ~Shape() {}             
};

class Rectangle : public Shape {
    double width, height;
public:
    Rectangle(double w, double h) : width(w), height(h) {}  
    double Area() const override {  
        return width * height;  
    }
};

class Circle : public Shape {
    double radius;
public:
    Circle(double r) : radius(r) {}  
    double Area() const override {  
        return PI * radius * radius;  
    }
};

class RightTriangle : public Shape {
    double base, height;
public:
    RightTriangle(double b, double h) : base(b), height(h) {}  
    double Area() const override {  
        return 0.5 * base * height;  
    }
};

class Trapezoid : public Shape {
    double base1, base2, height;
public:
    Trapezoid(double b1, double b2, double h) : base1(b1), base2(b2), height(h) {}  
    double Area() const override {  
        return 0.5 * (base1 + base2) * height;  
    }
};

int main() {
    std::vector<std::unique_ptr<Shape>> shapes;
    
    shapes.push_back(std::make_unique<Rectangle>(5.0, 3.0));  
    shapes.push_back(std::make_unique<Circle>(2.0));          
    shapes.push_back(std::make_unique<RightTriangle>(3.0, 4.0));  
    shapes.push_back(std::make_unique<Trapezoid>(3.0, 5.0, 4.0));  

    for (const auto& shape : shapes) {
        std::cout << "Area: " << shape->Area() << std::endl;
    }

    return 0;
}
