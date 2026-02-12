#include <iostream>
using namespace std;

int main() {
  int num;

  cout << "Number? ";
  cin >> num;
  if (num < 0) {
    cout << "Incorrect input, require positive integer" << endl;
    return 1;
  }

  int prod = 1;
  for (int i = 2; i <= num; i++) {
    prod *= i;
  }

  cout << num << "! = " << prod << endl;
  return 0;
}
