#include <iostream>
using namespace std;

int main() {
    int a, b, c;

    cout << "Enter three sides of the triangle: ";
    cin >> a >> b >> c;

    // Check if it's a valid triangle
    if (a + b <= c || a + c <= b || b + c <= a) {
        cout << "Not a valid triangle" << endl;
    }
    else if (a == b && b == c) {
        cout << "Equilateral triangle" << endl;
    }
    else if (a == b || b == c || a == c) {
        cout << "Isosceles triangle" << endl;
    }
    else {
        cout << "Scalene triangle" << endl;
    }

    return 0;
}

