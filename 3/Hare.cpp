//  Author: Shokhsanam Mubashirova
//  Course: CSCI-135
//  Instructor: Tong Yi
//  Assignment: Project 3 Task A
//  This program implements Hare class.

#include "Hare.hpp"
#include <iostream>
#include <cstdlib>
using namespace std;

// Constructor without arguments
Hare::Hare()
{
    //int[arr]={0,0,9,9-12,1,1,1,-2,-2};
    //int size=sizeof(arr)/sizeoff(arr[0]);
    //for(int i=0; i<size; i++)
    //patterns.push_back(arr[i]);

    // Initialize patterns and position
    patterns={0, 0, 9, 9, -12, 1, 1, 1, -2, -2}; 
    position=0;
}
// Constructor with vector argument
Hare::Hare(vector<int>patterns, int position)
{
    for(int i=0; i<patterns.size(); i++)
        this->patterns.push_back(patterns[i]);
    this->position=position;
    // Copy patterns and set position

    //or we can also use this->patterns=patterns;
    // this->position=position;
    //
}

// Constructor with array argument
Hare::Hare(int* arr, int size, int position)
{
    // Copy array elements to patterns and set position
    for (int i = 0; i < size; ++i)
    {
        this->patterns.push_back(arr[i]);
    }
    this->position = position;
}

// Method to simulate hare's movement
void Hare::move()
{
    // Generate a random index within the size of patterns
    int index = rand() % patterns.size();
    // Get the number of steps to move based on the random index
    int stepsToMove = patterns[index];
    // Update position
    position += stepsToMove;
}

// Getter method for position
int Hare::getPosition() const
{
    return position;
}

// Setter method for position
void Hare::setPosition(int position)
{
    this->position = position;
}

