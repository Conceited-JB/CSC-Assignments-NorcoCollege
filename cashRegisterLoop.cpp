// ============================================================================
// file: cashRegisterLoop.cpp
// ============================================================================
// Programmer: Jerry Brazzle
// Date: 9/30/2025
// Class: CSCI 123 ("Intro to C++ Programming")
// Time: 8:52
// Instructor: Dr. Rodriguez
// Project: Cash Register While Loop
//
// Description:
//      This program allows the user to enter the cost of however many items the
// user chooses, calculates the subtotal, tax, and total.  Then it will take the
// payment and display the proper change.
//
// ============================================================================

#include <iostream>
#include <iomanip>
using namespace std;

// ==== main ==================================================================
//
// ============================================================================

int main()
{
    cout << endl; // Blank line before everything

    int items;
    double subtotal = 0.0;
    double tax = 0.0775; // 7.75% tax

    cout << "How many items?: ";
    cin >> items;

    for (int i = 1; i <= items; i++)
    {
        double price;
        cout << "Please enter the cost of item #" << i << ": $";
        cin >> price;
        subtotal += price;
    }

    cout << endl; // Ensure subtotal is on its own line
    cout << "Subtotal: $" << fixed << setprecision(2) << subtotal << endl;
    double totalTax = subtotal * tax;
    cout << "Tax(7.75%): $" << fixed << setprecision(2) << totalTax << endl;
    double total = subtotal + totalTax;
    cout << "Total: $" << fixed << setprecision(2) << total << endl;

    cout << endl; // Blank line after totals

    cout << "Cash or credit? Enter 'C' for Cash or 'T' for Credit: " << endl;

    char paymentType;
    cin >> paymentType;

    if (paymentType == 'C' || paymentType == 'c')
    {
        double cash = 100;
        // Print Cash: $ and Change: $ on the same line, no value after first $
        cout << "Cash: $";
        if (cash < total)
        {
            cout << "Please enter the correct amount of cash: ";
            cin >> cash;
        }
        cout << "Change: $" << fixed << setprecision(2) << cash - total << endl;
    }
    else if (paymentType == 'T' || paymentType == 't')
    {
        cout << "Card Payment: $" << fixed << setprecision(2) << total << endl;
    }
    else
    {
        cout << "Invalid payment type." << endl;
    }

    return 0;
}   // end of "main"
