#include <iostream>
using namespace std;

class HashTable {
    int size;
    int *table;

public:
    HashTable(int s) {
        size = s;
        table = new int[size];
        for (int i = 0; i < size; i++)
            table[i] = -1; // -1 means empty
    }

    int hash1(int key) {
        return key % size; // primary hash
    }

    int hash2(int key) {
        return 1 + (key % (size - 1)); // for double hashing
    }

    // ----------------- Linear Probing -----------------
    void insertLinear(int key) {
        int idx = hash1(key);
        int start = idx;
        while (table[idx] != -1) {
            idx = (idx + 1) % size; // linear probe
            if (idx == start) return; // table full
        }
        table[idx] = key;
    }

    // ----------------- Quadratic Probing -----------------
    void insertQuadratic(int key) {
        int idx = hash1(key);
        int i = 0;
        while (table[(idx + i*i) % size] != -1) {
            i++;
            if (i == size) return; // table full
        }
        table[(idx + i*i) % size] = key;
    }

    // ----------------- Double Hashing -----------------
    void insertDoubleHash(int key) {
        int idx = hash1(key);
        int step = hash2(key);
        int i = 0;
        while (table[(idx + i*step) % size] != -1) {
            i++;
            if (i == size) return; // table full
        }
        table[(idx + i*step) % size] = key;
    }

    void display() {
        for (int i = 0; i < size; i++) {
            if (table[i] == -1)
                cout << i << ": " << "NULL" << endl;
            else
                cout << i << ": " << table[i] << endl;
        }
    }

    void resetTable() {
        for (int i = 0; i < size; i++)
            table[i] = -1;
    }
};

int main() {
    int size = 7;
    HashTable ht(size);

    cout << "----- Linear Probing -----\n";
    ht.insertLinear(10);
    ht.insertLinear(20);
    ht.insertLinear(15);
    ht.insertLinear(7);
    ht.display();

    ht.resetTable();
    cout << "\n----- Quadratic Probing -----\n";
    ht.insertQuadratic(10);
    ht.insertQuadratic(20);
    ht.insertQuadratic(15);
    ht.insertQuadratic(7);
    ht.display();

    ht.resetTable();
    cout << "\n----- Double Hashing -----\n";
    ht.insertDoubleHash(10);
    ht.insertDoubleHash(20);
    ht.insertDoubleHash(15);
    ht.insertDoubleHash(7);
    ht.display();

    return 0;
}
