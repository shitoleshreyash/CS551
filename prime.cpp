#include <iostream>
using namespace std;

int main() {
  int num = 121;
  int i = 2;

  while (i < num  && num % i != 0) {
    i++;
  }

  cout << num << " is ";
  if (i == num) {
    cout << "prime" << endl;
  }
  else {
    cout << "not prime, has factor " << i << endl;
  }

  return 0;
}