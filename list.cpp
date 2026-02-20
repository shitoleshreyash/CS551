

#include <iostream>
using namespace std;

template <typename T>
class LinkedList {
private:
  class Node {    // Internal Node class
  public:
      T data;
      Node* next;

      Node(const T& value) : data(value) {  // Constructor
          next = nullptr;
      }
  };

  Node* head;
  Node* tail;

public:
  LinkedList() { head = tail = nullptr; }  // Constructor

  ~LinkedList() { // Destructor to free memory
      Node* temp;
      while (head) {
          temp = head;
          head = head->next;
          delete temp;
      }
  }

  void append(const T& value) { // Insert at the end in O(1) time
      Node* newNode = new Node(value);
      if (!head) {  // If list is empty
          head = newNode;
          tail = newNode;
      } else {
          tail->next = newNode;
          tail = newNode;
      }
  }

  void prepend(const T& value) { // Insert at the beginning in O(1) time
      Node* newNode = new Node(value);
      if (!head) {  // If list is empty
          head = tail = newNode;
      } else {
          newNode->next = head;
          head = newNode;
      }
  }

  void remove(const T& value) { // Delete a node with a given value
      if (!head) return;

      if (head->data == value) {  // If head needs to be deleted
          Node* temp = head;
          head = head->next;
          if (!head) tail = nullptr;  // If list becomes empty
          delete temp;
          return;
      }

      Node* temp = head;
      while (temp->next && temp->next->data != value) {
          temp = temp->next;
      }

      if (temp->next) {  // If found
          Node* toDelete = temp->next;
          temp->next = temp->next->next;
          if (!temp->next) tail = temp;  // If last node was deleted
          delete toDelete;
      }
  }

  void updateLast(const T& value) {
    tail->data = value;
  }

  void display() {    // Display the linked list
      Node* temp = head;
      while (temp) {
          cout << temp->data << " -> ";
          temp = temp->next;
      }
      cout << "NULL" << endl;
  }
};

int main() {
  LinkedList<int> intList;
  intList.append(10);
  intList.append(20);
  intList.append(30);
  intList.prepend(5);

  cout << "Integer Linked List: ";
  intList.updateLast(50);
  intList.display();

  intList.remove(20);
  cout << "After deleting 20: ";
  intList.display();

  LinkedList<string> stringList;
  stringList.append("Hello");
  stringList.append("World");
  stringList.prepend("First");

  cout << "\nString Linked List: ";
  stringList.display();

  stringList.remove("World");
  cout << "After deleting 'World': ";
  stringList.display();

  return 0;
}

