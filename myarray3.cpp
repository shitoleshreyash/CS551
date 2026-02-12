
#include <iostream>
using namespace std;

class MyArray {
    int* arr;
    int size;
    int capacity;

public:
    MyArray(int cap) {
        capacity = cap;
        size = 0;
        arr = new int[capacity];
    }

    ~MyArray() {
        delete[] arr;
    }

    void insertAt(int index, int value) {
        if (size >= capacity || index < 0 || index > size) {
            cout << "Invalid index or array full\n";
            return;
        }

        for (int i = size; i > index; i--)
            arr[i] = arr[i - 1];

        arr[index] = value;
        size++;
    }

    void remove(int index) {
        if (index < 0 || index >= size) {
            cout << "Invalid index\n";
            return;
        }

        for (int i = index; i < size - 1; i++)
            arr[i] = arr[i + 1];

        size--;
    }

    void reverse() {
        for (int i = 0; i < size / 2; i++) {
            int temp = arr[i];
            arr[i] = arr[size - i - 1];
            arr[size - i - 1] = temp;
        }
    }

    void sort() {   // Selection Sort
        for (int i = 0; i < size - 1; i++) {
            int minIndex = i;
            for (int j = i + 1; j < size; j++) {
                if (arr[j] < arr[minIndex])
                    minIndex = j;
            }
            int temp = arr[i];
            arr[i] = arr[minIndex];
            arr[minIndex] = temp;
        }
    }

    void print() {
        for (int i = 0; i < size; i++)
            cout << arr[i] << " ";
        cout << endl;
    }
};

int main() {
    MyArray a(10);

    a.insertAt(0, 5);
    a.insertAt(1, 3);
    a.insertAt(2, 8);
    a.insertAt(1, 6);

    cout << "Array: ";
    a.print();

    a.remove(2);
    cout << "After remove: ";
    a.print();

    a.reverse();
    cout << "After reverse: ";
    a.print();

    a.sort();
    cout << "After sort: ";
    a.print();

    return 0;
}
