#include <iostream>
#include <cmath>

class Point2D {
    double x, y;

public:
    // Constructor
    Point2D(double xVal = 0, double yVal = 0) : x(xVal), y(yVal) {}

    void set(double xVal, double yVal) {
        x = xVal;
        y = yVal;
    }

    double distanceFromOrigin() const {
        return std::sqrt(x * x + y * y);
    }

    double distanceFrom(const Point2D& other) const {
        return std::sqrt(std::pow(other.x - x, 2) +
                         std::pow(other.y - y, 2));
    }

    void translate(double dx, double dy) {
        x += dx;
        y += dy;
    }

    void print() const {
        std::cout << "(" << x << ", " << y << ")" << std::endl;
    }
};

int main() {
    Point2D p1(3, 4);
    Point2D p2(6, 8);

    std::cout << "Point 1: ";
    p1.print();

    std::cout << "Point 2: ";
    p2.print();

    std::cout << "Distance of p1 from origin: "
              << p1.distanceFromOrigin() << std::endl;

    std::cout << "Distance between p1 and p2: "
              << p1.distanceFrom(p2) << std::endl;

    p1.translate(1, 2);
    std::cout << "After translating p1: ";
    p1.print();

    return 0;
}
