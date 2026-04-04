#include <iostream>
#include <random>
#include <bits/stdc++.h>

using namespace std;

int method2(string str) {
    int val = 0;
    int i = 0;
    for (const auto &c : str) {
        val += (c * (i + 1));
        i++;
    }
    return val;
}

string generate_random_string(size_t length) {
    static const string chars =
        "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789";

    static mt19937 generator(894);
    static uniform_int_distribution<> dist(0, chars.size() - 1);

    string result;
    for (size_t i = 0; i < length; ++i)
        result += chars[dist(generator)];

    return result;
}

class HashTable {
private:
    class Cell {
    public:
        string data;
        bool is_empty;
        bool is_deleted;

        Cell() {
            data = "";
            is_empty = true;
            is_deleted = false;
        }
    };

    Cell *table;
    int size;

    int hash(string s, int i) {
        return (method2(s) % size + i) % size;  // linear probing
    }

public:
    HashTable(int n) {
        size = n;
        table = new Cell[n];
    }

    ~HashTable() {
        delete[] table;
    }

    bool search(string s) {
        int seq = 0;

        while (seq < size) {
            int ind = hash(s, seq);

            if (!table[ind].is_empty && !table[ind].is_deleted && table[ind].data == s)
                return true;

            if (table[ind].is_empty && !table[ind].is_deleted)
                return false;

            seq++;
        }
        return false;
    }

    void insert(string s) {
        if (search(s)) return;

        int seq = 0;
        while (seq < size) {
            int ind = hash(s, seq);

            if (table[ind].is_empty || table[ind].is_deleted) {
                table[ind].data = s;
                table[ind].is_empty = false;
                table[ind].is_deleted = false;
                return;
            }
            seq++;
        }

        cout << "Hash table is full!\n";
    }

    void remove(string s) {
        int seq = 0;

        while (seq < size) {
            int ind = hash(s, seq);

            if (!table[ind].is_empty && !table[ind].is_deleted && table[ind].data == s) {
                table[ind].is_deleted = true;
                return;
            }

            if (table[ind].is_empty && !table[ind].is_deleted)
                return;

            seq++;
        }
    }

    friend ostream& operator<<(ostream& out, const HashTable& h) {
        for (int i = 0; i < h.size; i++) {
            out << i << ": ";
            if (!h.table[i].is_empty && !h.table[i].is_deleted)
                out << h.table[i].data;
            else
                out << "NULL";
            out << endl;
        }
        return out;
    }
};

int main() {
    cout << "Linear Probing Hash Table\n";

    HashTable ht(50);
    ht.insert("ravi");
    ht.insert("avir");

    for (int i = 0; i < 50; i++) {
        string s = generate_random_string(10);
        ht.insert(s);
    }

    cout << ht << endl;

    string s = "UPlqDBL3ez";

    if (ht.search(s)) {
        cout << s << " is present in the table\n";
        ht.remove(s);
        cout << "After deletion:\n";
        cout << ht << endl;
    } else {
        cout << s << " is not present in the table\n";
    }

    return 0;
}