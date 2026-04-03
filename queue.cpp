#include <iostream>
using namespace std;

class Q {
    struct N {
        int d;
        N* n;
        N(int v) : d(v), n(nullptr) {}
    };

    N* f;
    N* r;

public:
    Q() : f(nullptr), r(nullptr) {}

    void push(int x) {
        N* t = new N(x);
        if (!r) f = r = t;
        else {
            r->n = t;
            r = t;
        }
    }

    void pop() {
        if (!f) return;
        N* t = f;
        f = f->n;
        if (!f) r = nullptr;
        delete t;
    }

    int front() {
        return f ? f->d : -1;
    }
};

int main() {
    Q q;
    q.push(5);
    q.push(6);
    cout << q.front();
}