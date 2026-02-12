#include<iostream>

using namespace std;

int main(void) {
  float a = 5.5;
  float b = 9.2;
  float c = 3.4;

  if (a >= b && b >= c) {
    cout << "a is largest" << endl;
  }
  else {
    cout << "a is not largest" << endl;
  }

  return 0;
}