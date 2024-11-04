#ifndef HASH_H
#define HASH_H

#include <string>
#include <cmath>
#include <iostream>

using namespace std;

// Forward declaration of the hash function
int hash_function(string text);

// Node struct for chaining
struct Node {
    string key;
    Node* next;
    Node(string key) : key(key), next(nullptr) {}
};

// HashTable class with chaining
class HashTable {
private:
    int size;  // Number of slots in the table
    Node** table;  // Array of pointers to Nodes (linked lists)

public:
    HashTable(int size);
    void insert(string key);
    void print_first_five();
    void print_slot_lengths();
    void print_standard_deviation();
    ~HashTable();
};

#endif
