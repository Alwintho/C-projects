Name: Alwin Thomas
Team: YES
Description: This program implements a hash table with chaining to handle collisions. The hash table stores string keys, and it uses a custom hash function based on the sum of the ASCII values of the characters in the string.
Key Features:
Hash Table: The hash table uses an array of linked lists (chaining) to store the keys.
Custom Hash Function: The hash function sums the ASCII values of the characters in each string and then calculates the modulus with the size of the hash table to determine the appropriate slot.
Print Functions:
First 5 Slots: Outputs the contents of the first 5 slots in the hash table.
Slot Lengths: Prints the number of entries in each slot (i.e., the length of the linked list in each slot).
Standard Deviation: Calculates and prints the standard deviation of the lengths of all the slots.

Files: hash.cpp, hash.h, main.cpp,and makefile

