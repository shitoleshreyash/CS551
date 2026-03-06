
#include<iostream>
using namespace std;
class Node{
    public:
    int  data;
    Node* left;
    Node* right;


    Node(int val)
    {
        data =val;
        left=nullptr;
        right=nullptr;

    }
    friend ostream& operator<<(ostream& out, const Node& n)

{
    out<<n.data;
    return out;
}
};

int main()
{
    Node *n=new Node('a');

cout<<*n<<endl;
return 0;
}