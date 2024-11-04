#include "hash.h"

// A basic hash function: Sum of ASCII values of the string characters.
int hash_function(string text) {
    int hash_value = 0;
    for (char ch : text) {
        hash_value += static_cast<int>(ch);  // Convert character to its ASCII value
    }
    return hash_value;
}

// HashTable constructor
HashTable::HashTable(int size) {
    this->size = size;
    table = new Node*[size];  // Allocate an array of pointers to Nodes
    for (int i = 0; i < size; i++) {
        table[i] = nullptr;  // Initialize each slot to nullptr
    }
}

// Insert a key into the hash table
void HashTable::insert(string key) {
    int index = hash_function(key) % size;  // Get the slot index using hash function
    Node* newNode = new Node(key);
    if (!table[index]) {
        table[index] = newNode;  // No collision, directly place the new node
    } else {
        // Collision: Insert at the head of the linked list
        newNode->next = table[index];
        table[index] = newNode;
    }
}

// Print the contents of the first 5 slots
void HashTable::print_first_five() {
    cout << "==== Printing the contents of the first 5 slots ====" << endl;
    for (int i = 0; i < 5 && i < size; i++) {
        cout << "Slot " << i << ": ";
        Node* current = table[i];
        while (current) {
            cout << current->key << " ";
            current = current->next;
        }
        cout << endl;
    }
}

// Print the length of each slot
void HashTable::print_slot_lengths() {
    cout << "==== Printing the slot lengths ====" << endl;
    for (int i = 0; i < size; i++) {
        int length = 0;
        Node* current = table[i];
        while (current) {
            length++;
            current = current->next;
        }
        cout << "Slot " << i << ": " << length << endl;
    }
}

// Calculate and print standard deviation of slot lengths
void HashTable::print_standard_deviation() {
    double mean = 0;
    int total_entries = 0;
    int* slot_lengths = new int[size];

    // First calculate the mean (average)
    for (int i = 0; i < size; i++) {
        int length = 0;
        Node* current = table[i];
        while (current) {
            length++;
            current = current->next;
        }
        slot_lengths[i] = length;
        total_entries += length;
    }
    mean = static_cast<double>(total_entries) / size;

    // Then calculate the variance
    double variance = 0;
    for (int i = 0; i < size; i++) {
        variance += pow(slot_lengths[i] - mean, 2);
    }
    variance /= size;

    // Standard deviation is the square root of variance
    double stddev = sqrt(variance);
    cout << "==== Printing the standard deviation ====" << endl;
    cout << stddev << endl;

    delete[] slot_lengths;
}

// Destructor to free memory
HashTable::~HashTable() {
    for (int i = 0; i < size; i++) {
        Node* current = table[i];
        while (current) {
            Node* temp = current;
            current = current->next;
            delete temp;
        }
    }
    delete[] table;
}
