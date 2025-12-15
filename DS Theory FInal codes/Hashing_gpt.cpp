#include <iostream>
using namespace std;

class HashTable {
    int size;
    int *table;
    const int EMPTY = -1;
    const int DELETED = -2; // special marker for deleted entries

public:
    HashTable(int s) {
        size = s;
        table = new int[size];
        resetTable();
    }

    void resetTable() {
        for (int i = 0; i < size; i++)
            table[i] = EMPTY;
    }

    // ================= Hash Functions =================
    int hash1(int key) { return key % 13; }           // new primary hash
    int hash2(int key) { return 7 - (key % 7); }     // new step size for double hashing

    // ================= Linear Probing =================
    void insertLinear(int key) {
        int idx = key % size;
        int start = idx;
        while (table[idx] != EMPTY && table[idx] != DELETED) {
            idx = (idx + 1) % size;
            if (idx == start) return; // table full
        }
        table[idx] = key;
    }

    bool searchLinear(int key) {
        int idx = key % size;
        int start = idx;
        while (table[idx] != EMPTY) {
            if (table[idx] == key)
                return true;
            idx = (idx + 1) % size;
            if (idx == start) break;
        }
        return false;
    }

    void removeLinear(int key) {
        int idx = key % size;
        int start = idx;
        while (table[idx] != EMPTY) {
            if (table[idx] == key) {
                table[idx] = DELETED;
                return;
            }
            idx = (idx + 1) % size;
            if (idx == start) break;
        }
        cout << "Key not found\n";
    }

    // ================= Quadratic Probing =================
    void insertQuadratic(int key) {
        int idx = key % size;
        int i = 0;
        while (table[(idx + i*i) % size] != EMPTY && table[(idx + i*i) % size] != DELETED) {
            i++;
            if (i == size) return; // table full
        }
        table[(idx + i*i) % size] = key;
    }

    bool searchQuadratic(int key) {
        int idx = key % size;
        int i = 0;
        while (table[(idx + i*i) % size] != EMPTY && i < size) {
            if (table[(idx + i*i) % size] == key)
                return true;
            i++;
        }
        return false;
    }

    void removeQuadratic(int key) {
        int idx = key % size;
        int i = 0;
        while (table[(idx + i*i) % size] != EMPTY && i < size) {
            if (table[(idx + i*i) % size] == key) {
                table[(idx + i*i) % size] = DELETED;
                return;
            }
            i++;
        }
        cout << "Key not found\n";
    }

    // ================= Double Hashing =================
    void insertDoubleHash(int key) {
        int idx = hash1(key);
        int step = hash2(key);
        int i = 0;
        while (table[(idx + i*step) % size] != EMPTY && table[(idx + i*step) % size] != DELETED) {
            i++;
            if (i == size) return; // table full
        }
        table[(idx + i*step) % size] = key;
    }

    bool searchDoubleHash(int key) {
        int idx = hash1(key);
        int step = hash2(key);
        int i = 0;
        while (table[(idx + i*step) % size] != EMPTY && i < size) {
            if (table[(idx + i*step) % size] == key)
                return true;
            i++;
        }
        return false;
    }

    void removeDoubleHash(int key) {
        int idx = hash1(key);
        int step = hash2(key);
        int i = 0;
        while (table[(idx + i*step) % size] != EMPTY && i < size) {
            if (table[(idx + i*step) % size] == key) {
                table[(idx + i*step) % size] = DELETED;
                return;
            }
            i++;
        }
        cout << "Key not found\n";
    }

    // ================= Display =================
    void display() {
        for (int i = 0; i < size; i++) {
            if (table[i] == EMPTY)
                cout << i << ": " << "NULL" << endl;
            else if (table[i] == DELETED)
                cout << i << ": " << "DELETED" << endl;
            else
                cout << i << ": " << table[i] << endl;
        }
    }
};

int main() {
    int size = 13;  // updated table size
    HashTable ht(size);

    cout << "----- Linear Probing -----\n";
    ht.insertLinear(10);
    ht.insertLinear(20);
    ht.insertLinear(15);
    ht.insertLinear(7);
    ht.display();
    cout << "Search 15: " << ht.searchLinear(15) << endl;
    ht.removeLinear(15);
    ht.display();

    ht.resetTable();
    cout << "\n----- Quadratic Probing -----\n";
    ht.insertQuadratic(10);
    ht.insertQuadratic(20);
    ht.insertQuadratic(15);
    ht.insertQuadratic(7);
    ht.display();
    cout << "Search 7: " << ht.searchQuadratic(7) << endl;
    ht.removeQuadratic(7);
    ht.display();

    ht.resetTable();
    cout << "\n----- Double Hashing -----\n";
    ht.insertDoubleHash(10);
    ht.insertDoubleHash(20);
    ht.insertDoubleHash(15);
    ht.insertDoubleHash(7);
    ht.display();
    cout << "Search 20: " << ht.searchDoubleHash(20) << endl;
    ht.removeDoubleHash(20);
    ht.display();

    return 0;
}
