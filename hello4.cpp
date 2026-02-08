#include <iostream>
using namespace std;

int main() {
  const int MAX_SIZE = 100;
  char input[MAX_SIZE]; // array size is fixed to be 100

  cout << "Who are you? ";
  cin.getline(input, MAX_SIZE); // read at most MAX_SIZE chars or till '\n'

  cout << "What is your age? ";
  int age;
  cin >> age;

  cout << "Hello " << input << " with age " << age << endl;
  return 0;
}
