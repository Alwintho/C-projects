#include <iostream>
#include <fstream>
#include <string>
#include "hash.h"

using namespace std;

int main() {
    int numSlots;
    cin >> numSlots;  // Read number of hash table slots

    HashTable ht(numSlots);

    string token;
    while (cin >> token) {
        ht.insert(token);  // Insert each token into the hash table
    }

    // Print the required outputs
    ht.print_first_five();         // Contents of first 5 slots
    ht.print_slot_lengths();       // Slot lengths
    ht.print_standard_deviation(); // Standard deviation of slot lengths

    return 0;
}
