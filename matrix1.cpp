#include <iostream>

using namespace std;

class Matrix {
  private:
    float *_mat;
    int    _rows;
    int    _cols;

  public:
    Matrix(int r, int c): _rows(r), _cols(c) {
      _mat = new float[_rows * _cols];
    }

   ~Matrix() {
      delete [] _mat;
   }

   int rows() const { return _rows; }
   int cols() const { return _cols; }

   float* operator[](const int i) {
    return &_mat[i * _cols];
   }

   friend ostream& operator<<(ostream& out, const Matrix& m) {
     int c = 0;
     for(int i = 0; i < m.rows(); i++) {
       for(int j = 0; j < m.cols(); j++) {
         out << " " << m._mat[c];
         c++;
       }
       out << endl;
     }
     return out;
   }
};

int main() {
  Matrix m(4, 5);
  for (int i = 0; i < m.rows(); i++) {
    for (int j = 0; j < m.cols(); j++) {
      m[i][j] = i + j + 1;
    }
  }
  cout << m;
  return 0;
}