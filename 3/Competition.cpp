//  Author: Shokhsanam Mubashirova
//  Course: CSCI-135
//  Instructor: Tong Yi
//  Assignment: Project 3 Task D
//  This program implements Competition class.

#include "Competition.hpp"
#include <iostream>
#include <string>
using namespace std;

// Default constructor
Competition::Competition()
{
}
  
// Non-default constructor
Competition::Competition(Hare coney, Tortoise cooter, int length)
{
    rabbit = coney; 
    tor = cooter;   
    lane = Road(length); 
}

// Method to play the competition
void Competition::play() 
{
    // Find out the last block of the road
    int lastBlock = lane.length() - 1;
    int round = 1; // Initialize round number

    // Compete as long as neither rabbit nor tor reaches the last block of lane
    while (rabbit.getPosition() < lastBlock && tor.getPosition() < lastBlock) 
    {
        // Move rabbit and mark its position on the road
        rabbit.move();
        int rabbitPos = rabbit.getPosition();
        if (rabbitPos < 0)
            rabbit.setPosition(0);
        else if (rabbitPos > lastBlock)
            rabbit.setPosition(lastBlock);
        lane.mark(rabbit.getPosition(), 'H');

        // Move tortoise and mark its position on the road
        tor.move();
        int torPos = tor.getPosition();
        if (torPos < 0)
            tor.setPosition(0);
        else if (torPos > lastBlock)
            tor.setPosition(lastBlock);
        lane.mark(tor.getPosition(), 'T');

        // Display round number and the values of each element of lane
        cout << "round   "<< round << ": ";
        lane.display();
        
        if (rabbitPos==torPos)
            cout << "Ouch. Tortoise bites hare." << endl;
        round++;
        // Clear rabbit's and tortoise's previous positions on the road
        lane.mark(rabbit.getPosition(), ' ');
        lane.mark(tor.getPosition(), ' ');
    }

    // Print competition result
    if (rabbit.getPosition() == lastBlock && tor.getPosition() == lastBlock)
        cout << "It is a tie." << endl;
    else if (rabbit.getPosition() == lastBlock)
        cout << "Yuck. Hare wins." << endl;
    else
        cout << "Yay!!! Tortoise wins." << endl;
}

