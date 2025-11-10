// Description : You are to write a program that prompts the user
// for their full name. However, the user can enter only their first
// name, or first and last name, or first, middle, and last name. 
// Your objective is to read the entire name that is given at once 
// (using the getline function) and be able to extract the first, 
// middle, and last name appropriately given that there is whitespace 
// in between.  Then you’ll display on the screen what their first, 
// middle, and last name are if all the names are given with the total
//  length of their full name (without white spaces).  For simplicity, 
// we will assume that a person can have a max of 3 names (first, 
// middle, and last).  As a note, each name string is to be saved in
// its own character array.

#include <iostream>
#include <cstring>
using namespace std;

// prototype functions
void extractNames(const char fullName[], char firstName[], char middleName[], char lastName[]);
int calculateLength(const char firstName[], const char middleName[], const char lastName[]);

int main(){
    const int MAX_LENGTH = 100;
    char fullName[MAX_LENGTH];
    char firstName[MAX_LENGTH] = "";
    char middleName[MAX_LENGTH] = "";
    char lastName[MAX_LENGTH] = "";

    // prompt user for full name
    cout << "Please enter your full name: ";
    cin.getline(fullName, MAX_LENGTH);
    cout << endl;
    // extract names
    extractNames(fullName, firstName, middleName, lastName);

    // calculate total length without spaces
    int totalLength = calculateLength(firstName, middleName, lastName);

    // display results
    cout << "First Name: " << firstName << endl;
    if (strlen(middleName) > 0) {
        cout << "Middle Name: " << middleName << endl;
    }
    if (strlen(lastName) > 0) {
        cout << "Last Name: " << lastName << endl;
    }
    cout << "The total number of characters in your name is: " << totalLength << endl;

    return 0;
}

void extractNames(const char fullName[], char firstName[], char middleName[], char lastName[]) {
    int len = strlen(fullName);
    int i = 0, j = 0;
    int wordCount = 0;
    
    // Count words in the full name
    bool inWord = false;
    for(int k = 0; k < len; k++) {
        if(fullName[k] != ' ' && !inWord) {
            wordCount++;
            inWord = true;
        }
        else if(fullName[k] == ' ') {
            inWord = false;
        }
    }

    // Extract first name
    while (i < len && fullName[i] != ' ') {
        firstName[j++] = fullName[i++];
    }
    firstName[j] = '\0';

    // Skip spaces
    while (i < len && fullName[i] == ' ') {
        i++;
    }

    // If there are 3 words, extract middle name
    if(wordCount == 3) {
        j = 0;
        while (i < len && fullName[i] != ' ') {
            middleName[j++] = fullName[i++];
        }
        middleName[j] = '\0';

        // Skip spaces
        while (i < len && fullName[i] == ' ') {
            i++;
        }
    }
    else {
        middleName[0] = '\0';  // No middle name
    }

    // Extract last name (if any remaining text)
    j = 0;
    if(wordCount >= 2) {  // If there's more than just first name
        while (i < len) {
            lastName[j++] = fullName[i++];
        }
    }
    lastName[j] = '\0';
}

int calculateLength(const char firstName[], const char middleName[], const char lastName[]) {
    return strlen(firstName) + strlen(middleName) + strlen(lastName);
}

//End of lab_06.cpp
