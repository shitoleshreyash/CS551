#include <iostream>
using namespace std;

class DL {
    struct N {
        int d;
        N* n;
        N* p;
        N(int v) : d(v), n(nullptr), p(nullptr) {}
    };

    N* h;

public:
    DL() : h(nullptr) {}

    void insert(int v) {
        N* x = new N(v);
        if (h) h->p = x;
        x->n = h;
        h = x;
    }

    void show() {
        N* t = h;
        while (t) {
            cout << t->d << " ";
            t = t->n;
        }
        cout << endl;
    }
};

int main() {
    DL d;
    d.insert(1);
    d.insert(2);
    d.insert(3);
    d.show();
}