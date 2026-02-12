#include <iostream>

using namespace std;

template <class T>
class CircularQueue {
private:
  T   *_arr;
  int _front, _rear, _capacity;

public:
  CircularQueue(int size) {
    _capacity = size + 1;  // 1 extra space to differentiate full from empty
    _arr = new T[_capacity];
    _front = _rear = 0;
  }

  bool is_empty() {
    return _front == _rear;
  }

  bool is_full() {
    return (_rear + 1) % _capacity == _front;
  }

  void enqueue(const T& val) {
    if (is_full()) {
      cout << "Queue is full\n";
      return;
    }
    _arr[_rear] = val;
    _rear = (_rear + 1) % _capacity;
   }

   T& dequeue() {
     if (is_empty()) {
       throw std::underflow_error("Queue is empty");
     }

     T& ret = _arr[_front];
     _front = (_front + 1) % _capacity;

      return ret;
   }

   void print(){
     for(int i = _front; i < _rear; i++) {
       cout << _arr[i] << " ";
     }
     cout << endl;
   }
};

int main() {
  CircularQueue<int> q(10);
  q.enqueue(1);
  q.enqueue(2);
  q.enqueue(3);
  q.print();
  q.dequeue();
  q.enqueue(4);
  q.print();
  return 0;
}