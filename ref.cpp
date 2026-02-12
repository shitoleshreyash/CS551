#include <iostream>

using namespace std;

int main() {
  int a = 5;
  int &b = a;

  b += 20;

  cout << "a = " << a << endl;

  return 0;
}