/*******************************************************************************
Author:         Navneet Reddy
CS Login:       navneet
Course:         CS 368, Fall 2014
Assignment:     Programming Assignment 4
*******************************************************************************/

#include "Date.h"
#include <iostream>

using namespace std;

/*
 *Main function to run the date program.
 */
int main() {
    Date dtc, dt2, dt3;
    int x, n;
    bool run = true;
    bool compare = false;
    
    cout << "Enter a date: ";
    cin >> dtc;
    
    cout << "The date entered was: " << dtc << endl;
    
    //Main program loop
    while (run) {
    
        cout << "What would you like to do? ";
        cout << "\n1. Set Date";
        cout << "\n2. Days after current date";
        cout << "\n3. Days before current date";
        cout << "\n4. Date not equal to current date";
        cout << "\n5. Current date is less than date";
        cout << "\n6. Current date is less than or equal to date";
        cout << "\n7. Current date is greater than date";
        cout << "\n8. Current date is greater than or equal to date";
        cout << "\n9. Exit" << endl;
    
        cin >> x;
    
        //Switch statements to complete each user command
        switch (x) {
            //Set the date
            case 1: 
                cout << "What should the current date be? ";
                cin >> dt2;
            
                dtc = dt2; 
                cout << "The current date is: " << dtc << endl;
            
                break;
            //Set the date x number of days after current date
            case 2: 
                cout << "Enter number of days. ";
                cin >> n;
            
                dt3 = (dtc + n);
                cout << "The new date is: " << dt3 << endl;
            
                break;
            //Set the date x number of days before current date
            case 3: 
                cout << "Enter number of days. ";
                cin >> n;
        
                dt3 = (dtc - n);
                cout << "The new date is: " << dt3 << endl;
            
                break;
            //Check if the given date is the current date
            case 4: 
                cout << "Enter date to compare current date to. ";
                cin >> dt2;
                
                compare = (dtc != dt2);
                if (compare == true) {
                    cout << "Date is not equal to the current date." << endl;
                }
                else {
                    cout << "Date is equal to the current date." << endl;
                }
                
                break;
            //Check if the current date is before the given date
            case 5: 
                cout << "Enter date to compare current date to. ";
                cin >> dt2;
            
                compare = (dtc < dt2);
                if (compare == true) {
                    cout << "Current date is before the given date." << endl;
                }
                else {
                    cout << "Current date is not before the given date." << endl;
                }
                
                break;
            //Check if the current date is on or before the given date
            case 6: 
                cout << "Enter date to compare current date to. ";
                cin >> dt2;
        
                compare = (dtc <= dt2);
                if (compare == true) {
                    cout << "Current date is on or before the given date." << endl;
                }
                else {
                    cout << "Current date is not on or before the given date." << endl;
                }
            
                break;
            //Check if the current date is after the given date
            case 7: 
                cout << "Enter date to compare current date to. ";
                cin >> dt2;
        
                compare = (dtc > dt2);
                if (compare == true) {
                    cout << "Current date is after the given date." << endl;
                }
                else {
                    cout << "Current date is not after the given date." << endl;
                }
            
                break;
            //Check if the current date is on or after the given date
            case 8: 
                cout << "Enter date to compare current date to. ";
                cin >> dt2;
    
                compare = (dtc >= dt2);
                if (compare == true) {
                    cout << "Current date is on or after the given date." << endl;
                }
                else {
                    cout << "Current date is not on or after the given date." << endl;
                }
                
                break;
            //Exit the program
            case 9: 
                cout << "Exiting" << endl;
                run = false;
                break;
            default:
                cout << "Exiting" << endl;
                run = false;
                break;
        }
    }
    
    return 0;
}
