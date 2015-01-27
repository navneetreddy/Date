/*******************************************************************************
Author:         Navneet Reddy
CS Login:       navneet
Course:         CS 368, Fall 2014
Assignment:     Programming Assignment 4
*******************************************************************************/

#ifndef DATE_H
#define DATE_H

#include <iostream>
using namespace std;

class Date {

  public:

    // constructors
    Date();
    Date(int month, int day, int year);
    Date(const Date& dt); //copy constructor
    ~Date();
    
    // Member functions
      void print(ostream& out = cout) const;
      
    //Accessor and setter functions
      int getDay() const; 
      int getMonth() const;
      int getYear() const;
      bool setDate(int m, int d, int y);
      Date earliestDate();

   // Assignment operators
      const Date& operator=(const Date& dt);

   // Relational operators
      friend bool operator!=(const Date& date1, const Date& date2);
      friend bool operator < (const Date& date1, const Date& date2);
      friend bool operator <= (const Date& date1, const Date& date2);
      friend bool operator > (const Date& date1, const Date& date2);
      friend bool operator >= (const Date& date1, const Date& date2);
          
    
  private:
    int day;      
    int month; 
    int year;
};

// Arithmetic operators
Date operator+(const Date&, const int n);
Date operator- (const Date&, const int n);

// I/O operators
ostream& operator<< (ostream& out, const Date& n);
istream& operator >> (istream& in, Date& dt);

#endif
