#include <iostream>
#include <cmath>


// Abstract base class
class Vehicle {
public:
    // Pure virtual functions
    virtual double calculateArea() const = 0;
    virtual double calculatePerimeter() const {
        return 2*PI;
    }

    // Virtual destructor
    virtual ~Shape() = default;
};

// Circle class
class Circle : public Shape {
private:
    double radius;

public:
    Circle(double rad) : radius(rad) {}

    double calculateArea() const override {
        return PI * pow(radius, 2);
    }

    double calculatePerimeter() const override {
        return 2 * PI * radius;
    }
};

// Rectangle class
class Rectangle : public Shape {
private:
    double length;
    double width;

public:
    Rectangle(double len, double wid) : length(len), width(wid) {}

    double calculateArea() const override {
        return length * width;
    }

    double calculatePerimeter() const override {
        return 2 * (length + width);
    }
};

// Triangle class
class Triangle : public Shape {
private:
    double side1;
    double side2;
    double side3;

public:
    Triangle(double s1, double s2, double s3)
        : side1(s1), side2(s2), side3(s3) {}

    double calculateArea() const override {
        // Heron's formula
        double s = (side1 + side2 + side3) / 2;

        return sqrt(s * (s - side1) *
                    (s - side2) * (s - side3));
    }

    double calculatePerimeter() const override {
        return side1 + side2 + side3;
    }
};

int main() {
    // Create objects
    Circle circle(7.0);
    Rectangle rectangle(4.2, 8.0);
    Triangle triangle(4.0, 4.0, 3.2);

    // Circle
    std::cout << "Circle:" << std::endl;
    std::cout << "Area: " << circle.calculateArea() << std::endl;
    std::cout << "Perimeter: " << circle.calculatePerimeter() << std::endl;

    // Rectangle
    std::cout << "\nRectangle:" << std::endl;
    std::cout << "Area: " << rectangle.calculateArea() << std::endl;
    std::cout << "Perimeter: " << rectangle.calculatePerimeter() << std::endl;

    // Triangle
    std::cout << "\nTriangle:" << std::endl;
    std::cout << "Area: " << triangle.calculateArea() << std::endl;
    std::cout << "Perimeter: " << triangle.calculatePerimeter() << std::endl;

    return 0;
}