#include <iostream>
using namespace std;

class Node {
private:
    int _data;
    Node* _next;

public:
    // Default constructor
    Node() : _data(0), _next(nullptr) {}

    // Parameterized constructor
    Node(int val) : _data(val), _next(nullptr) {}

    ~Node() {}

    friend ostream& operator<<(ostream& out, const Node& n)
    {
        out << n._data;
        return out;
    }
};

int main()
{
    Node *a=new Node(10);
    Node *b=new Node(20);
    Node *c=new Node(30);
a->next=b;
b->next=c;
cout<<*a<<endl;
cout<<*b<<endl
cout<<*c<<endl

    Node n[10];  // now works because default constructor exists

    cout << "hello:" << endl;

    Node* v = new Node(20);

    cout << n[0] << endl;  // print first element
    cout << *v << endl;

    delete v;

    return 0;
}