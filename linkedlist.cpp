#include <iostream>
#include <vector>
#include <stack>
using namespace std;

class LList {
private:
    struct N {
        int d;
        N* n;
        N(int v) : d(v), n(nullptr) {}
    };

    N* h;
    int sz;

public:
    LList() : h(nullptr), sz(0) {}

    int length() { return sz; }

    void insertAt(int i, int v) {
        if (i < 0 || i > sz) return;
        N* x = new N(v);
        if (i == 0) {
            x->n = h;
            h = x;
        } else {
            N* t = h;
            for (int k = 0; k < i - 1; k++) t = t->n;
            x->n = t->n;
            t->n = x;
        }
        sz++;
    }

    void removeFirst() {
        if (!h) return;
        N* t = h;
        h = h->n;
        delete t;
        sz--;
    }

    void removeLast() {
        if (!h) return;
        if (!h->n) {
            delete h;
            h = nullptr;
        } else {
            N* t = h;
            while (t->n->n) t = t->n;
            delete t->n;
            t->n = nullptr;
        }
        sz--;
    }

    void removeAt(int i) {
        if (i < 0 || i >= sz) return;
        if (i == 0) {
            removeFirst();
            return;
        }
        N* t = h;
        for (int k = 0; k < i - 1; k++) t = t->n;
        N* r = t->n;
        t->n = r->n;
        delete r;
        sz--;
    }

    N* getNode(int i) {
        if (i < 0 || i >= sz) return nullptr;
        N* t = h;
        for (int k = 0; k < i; k++) t = t->n;
        return t;
    }

    bool isPresent(int v) {
        N* t = h;
        while (t) {
            if (t->d == v) return true;
            t = t->n;
        }
        return false;
    }

    int count(int v) {
        int c = 0;
        N* t = h;
        while (t) {
            if (t->d == v) c++;
            t = t->n;
        }
        return c;
    }

    void revIter() {
        N* p = nullptr;
        N* c = h;
        while (c) {
            N* nx = c->n;
            c->n = p;
            p = c;
            c = nx;
        }
        h = p;
    }

    N* revRec(N* x) {
        if (!x || !x->n) return x;
        N* r = revRec(x->n);
        x->n->n = x;
        x->n = nullptr;
        return r;
    }

    void reverseRecursive() {
        h = revRec(h);
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

class DLList {
private:
    struct N {
        int d;
        N* n;
        N* p;
        N(int v) : d(v), n(nullptr), p(nullptr) {}
    };

    N* h;

public:
    DLList() : h(nullptr) {}

    void pushFront(int v) {
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

class StackX {
private:
    vector<int> a;

public:
    void push(int x) { a.push_back(x); }
    void pop() { if (!a.empty()) a.pop_back(); }
    int top() { return a.empty() ? -1 : a.back(); }
    bool empty() { return a.empty(); }
};

class QueueX {
private:
    struct N {
        int d;
        N* n;
        N(int v) : d(v), n(nullptr) {}
    };

    N* f;
    N* r;

public:
    QueueX() : f(nullptr), r(nullptr) {}

    void push(int x) {
        N* t = new N(x);
        if (!r) {
            f = r = t;
            return;
        }
        r->n = t;
        r = t;
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

bool check(string s) {
    stack<char> st;
    for (char c : s) {
        if (c == '(' || c == '{' || c == '[') st.push(c);
        else {
            if (st.empty()) return false;
            char t = st.top(); st.pop();
            if ((c == ')' && t != '(') ||
                (c == '}' && t != '{') ||
                (c == ']' && t != '[')) return false;
        }
    }
    return st.empty();
}

int main() {
    LList x;
    x.insertAt(0, 1);
    x.insertAt(1, 2);
    x.insertAt(2, 3);
    x.show();

    x.removeFirst();
    x.show();

    x.revIter();
    x.show();

    cout << x.isPresent(2) << endl;
    cout << x.count(2) << endl;

    DLList y;
    y.pushFront(5);
    y.pushFront(10);
    y.show();

    StackX s;
    s.push(10);
    s.push(20);
    cout << s.top() << endl;

    QueueX q;
    q.push(7);
    q.push(8);
    cout << q.front() << endl;

    cout << check("{[()]}") << endl;

    return 0;
}
