#include <iostream>

using namespace std;

void swap1(int x, int y) {
  int temp = x;
  x = y;
  y = temp;
}

int main() {
  int a = 5, b = 6;
  cout << "a = " << a << " b = " << b << endl;
  swap1(a, b);
  cout << "a = " << a << " b = " << b << endl;
  return 0;
}