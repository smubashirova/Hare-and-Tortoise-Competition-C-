//  Author: Shokhsanam Mubashirova
//  Course: CSCI-135
//  Instructor: Tong Yi
//  Assignment: Project 3 Task C
//  This program implements Road class.

#include "Road.hpp"
#include <iostream>
#include <iomanip>
using namespace std;

// Constructor without arguments
Road::Road() {
    // Initialize blocks with 70 spaces
    blocks.assign(70, ' ');
}

// Constructor with specified length
Road::Road(int length) {
    // Ensure length is non-negative
    if (length < 0)
        length = 70; // Default length is 70 if negative
    // Initialize blocks with specified length
    blocks.assign(length, ' ');
}

// Method to mark a block at a given index with a character
void Road::mark(int index, char ch) {
    // Ensure index is non-negative and within the size of blocks
    if (index >= 0 && index < blocks.size())
        blocks[index] = ch;
}

// Method to display the road
void Road::display() const {
    // Display data member blocks
    for (char block : blocks) {
        cout << block << "";
    }
    cout << endl;

    // Print separation line
    for (int i = 0; i < blocks.size(); i++) {
        cout << "-";
    }
    cout << endl;
}

// Method to get the length of the road
int Road::length() const {
    return blocks.size();
}