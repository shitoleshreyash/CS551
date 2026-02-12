#include <iostream>
using namespace std;

class Matrix {
    int rows, cols;
    float* data;

public:
    Matrix(int r, int c) {
        rows = r;
        cols = c;
        data = new float[rows * cols];
    }

    ~Matrix() {
        delete[] data;
    }

    void set(int i, int j, float value) {
        if (i >= 0 && i < rows && j >= 0 && j < cols)
            data[i * cols + j] = value;
    }

    float get(int i, int j) const {
        return data[i * cols + j];
    }

    void print() {
        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++)
                cout << data[i * cols + j] << " ";
            cout << endl;
        }
    }
};

int main() {
    Matrix m(2, 3);

    m.set(0, 0, 1);
    m.set(0, 1, 2);
    m.set(0, 2, 3);
    m.set(1, 0, 4);
    m.set(1, 1, 5);
    m.set(1, 2, 6);

    m.print();

    return 0;
}
