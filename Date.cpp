/*******************************************************************************
Author:         Navneet Reddy
CS Login:       navneet
Course:         CS 368, Fall 2014
Assignment:     Programming Assignment 4
*******************************************************************************/

#include <iostream>
#include <iomanip>
#include "Date.h"

using namespace std;

/*
 * Default constructor
 */
Date::Date() {
    day = 1;
    month = 1;
    year = 1900;
}

/*
 * Constructor with given parameters
 */
Date::Date(int month, int day, int year) {
    this->day = day;
    this->month = month;
    this->year = year;
}

/*
 * Copy constructor
 */
Date::Date(const Date& dt) {
    day = dt.day;
    month = dt.month;
    year = dt.year;
}

/*
 * Destructor
 */
Date::~Date() {
    cout << "Date destructor called on date " << day << ", " << month 
                                                       << ", " << year << endl;
}

/*
 * Return the day of the current date
 */
int Date::getDay() const {
    return day;
}

/*
 * Return the month of the current date
 */
int Date::getMonth() const {
    return month;
}

/*
 * Return the year of the current date
 */
int Date::getYear() const {
    return year;
}

/*
 * Set the current date
 *
 * @return true if the date was set successfully
 */
bool Date::setDate(int m, int d, int y) {
    day = d;
    month = m;
    year = y;
    
    return true;
}

/*
 * Print the current date
 */
void Date::print(ostream& out) const {
    out << day << "/" << month << "/" << year << endl;
}

/*
 * Assignment operator
 *
 * @param dt date to assign the current date
 * @return pointer to the current date
 */
const Date& Date::operator=(const Date& dt) {
    day = dt.getDay();
    month = dt.getMonth();
    year = dt.getYear();
    
    return *this;
}

/*
 * Not equals operator
 * 
 * @param date1 current date
 * @param date2 date to compare the current date to
 * @return true if the dates are not equal, otherwise false
 */
bool operator!=(const Date& date1, const Date& date2) {
    //Check if the dates are equal
    if (date1.getDay() == date2.getDay() &&
            date1.getMonth() == date2.getMonth() &&
            date1.getYear() == date2.getYear()) {
        return false;
    }
    
    return true;
}

/*
 * Less than operator
 * 
 * @param date1 current date
 * @param date2 date to compare the current date to
 * @return true if the current date is less than the given date, 
 * otherwise false
 */
bool operator < (const Date& date1, const Date& date2) {
    //Check if the current year is less than the given year
    if (date1.getYear() < date2.getYear()) {
        return true;
    }
    //Check if the current year is equal to the given year
    else if (date1.getYear() == date2.getYear()) {
        //Check if the current month is less than the given month
        if (date1.getMonth() < date2.getMonth()) {
            return true;
        }
        //Check if the current month is equal to the given month
        else if (date1.getMonth() == date2.getMonth()) {
            //Check if the current day is less than the given day
            if (date1.getDay() < date2.getDay()) {
                return true;
            }
        }
    }
    
    return false;
}

/*
 * Less than or equal to operator
 * 
 * @param date1 current date
 * @param date2 date to compare the current date to
 * @return true if the current date is less than or equal to the given date, 
 * otherwise false
 */
bool operator <= (const Date& date1, const Date& date2) {
    //Check if the current year is less than the given year
    if (date1.getYear() < date2.getYear()) {
        return true;
    }
    //Check if the current year is equal to the given year
    else if (date1.getYear() == date2.getYear()) {
        //Check if the current month is less than the given month
        if (date1.getMonth() < date2.getMonth()) {
            return true;
        }
        //Check if the current month is equal to the given month
        else if (date1.getMonth() == date2.getMonth()) {
            //Check if the current day is less than or equal to the given day
            if (date1.getDay() <= date2.getDay()) {
                return true;
            }
        }
    }
    
    return false;
}

/*
 * Greater than operator
 * 
 * @param date1 current date
 * @param date2 date to compare the current date to
 * @return true if the current date is greater than the given date, 
 * otherwise false
 */
bool operator > (const Date& date1, const Date& date2) {
    //Check if the current year is greater than the given year
    if (date1.getYear() > date2.getYear()) {
        return true;
    }
    //Check if the current year is equal to the given year
    else if (date1.getYear() == date2.getYear()) {
         //Check if the current month is greater than the given month
        if (date1.getMonth() > date2.getMonth()) {
            return true;
        }
        //Check if the current month is equal to the given month
        else if (date1.getMonth() == date2.getMonth()) {
            //Check if the current day is greater than the given day
            if (date1.getDay() > date2.getDay()) {
                return true;
            }
        }
    }
    
    return false;
}

/*
 * Greater than or equal to operator
 * 
 * @param date1 current date
 * @param date2 date to compare the current date to
 * @return true if the current date is greater than or equal to the given date, 
 * otherwise false
 */
bool operator >= (const Date& date1, const Date& date2) {
    //Check if the current year is greater than the given year
    if (date1.getYear() > date2.getYear()) {
        return true;
    }
    //Check if the current year is equal to the given year
    else if (date1.getYear() == date2.getYear()) {
        //Check if the current month is greater than the given month
        if (date1.getMonth() > date2.getMonth()) {
            return true;
        }
        //Check if the current month is equal to the given month
        else if (date1.getMonth() == date2.getMonth()) {
            //Check if the current day is greater than or equal to the given day
            if (date1.getDay() >= date2.getDay()) {
                return true;
            }
        }
    }
    
    return false;
}

/*
 * Returns a new Date object that represents the date that is n days 
 * after the current Date object
 * 
 * @param date1 current date
 * @param n number of days to add
 * @return Date object with the new date
 */
Date operator+(const Date& dt, const int n) {
    Date date;
    //Set the new date to the current date
    date.setDate(dt.getMonth(),dt.getDay(),dt.getYear());
    
    //Increment day by day and check if the month exceeds 30 days
    //or the year exceeds 12 months
    for (int i = 0; i < n; i++) {
        if (date.getDay() == 30) {
            if (date.getMonth() == 12) {
                date.setDate(1,date.getDay(),date.getYear() + 1);
            }
            else {
                date.setDate(date.getMonth() + 1,date.getDay(),date.getYear());
            }
            
            date.setDate(date.getMonth(),1,date.getYear());
        }
        else {
            date.setDate(date.getMonth(),date.getDay() + 1,date.getYear());
        }
    }
    
    Date edt;
    edt.setDate(1,1,1900);
    
    //Check if the date is valid
    if (date < edt) {
        cerr << "Date is before earliest date." << endl;
        date = edt;
    }
    
    return date;
}

/*
 * Returns a new Date object that represents the date that was n days 
 * before the current Date object
 * 
 * @param date1 current date
 * @param n number of days to add
 * @return Date object with the new date
 */
Date operator- (const Date& dt, const int n) {
    Date date;
    //Set the new date to the current date
    date.setDate(dt.getMonth(),dt.getDay(),dt.getYear());
    
    //Decrement day by day and check if the month exceeds 30 days
    //or the year exceeds 12 months
    for (int i = 0; i < n; i++) {
        if (date.getDay() == 1) {
            if (date.getMonth() == 1) {
                date.setDate(12,date.getDay(),date.getYear() - 1);
            }
            else {
                date.setDate(date.getMonth() - 1,date.getDay(),date.getYear());
            }
            
            date.setDate(date.getMonth(),30,date.getYear());
        }
        else {
            date.setDate(date.getMonth(),date.getDay() - 1,date.getYear());
        }
    }
    
    Date edt;
    edt.setDate(1,1,1900);
    
    //Check if the date is valid
    if (date < edt) {
        cerr << "Date is before earliest date." << endl;
        date = edt;
    }
    
    return date;
}

/*
 * Output the date 
 * 
 * @param out reference to the output stream
 * @param n reference to the date object
 * @return reference to the output stream
 */
ostream& operator<< (ostream& out, const Date& n) {
    n.print(out);
    return out;
}

/*
 * Input the date 
 * 
 * @param in reference to the input stream
 * @param n reference to the date object
 * @return reference to the output stream
 */
istream& operator >> (istream& in, Date& dt) {
    char ch;
    int x, y, z;
    
    ch = in.get();
    //Check for spaces
	while (ch == ' ' || ch == '\t' || ch == '\n') {
		ch = in.get();
    }
    
	in >> x;
    
	ch = in.get();
    //Check for spaces
	while (ch == ' ' || ch == '\t' || ch == '\n') {
		ch = in.get();
    }
    
    //Check for invalid input
	if (ch != '/') {
		cerr << "invalid input, missing '/'" << endl;
		return in;
	}
    
	in >> y;
    
	ch = in.get();
    //Check for spaces
	while (ch == ' ' || ch == '\t' || ch == '\n') {
		ch = in.get();
    }
    
    //Check for invalid input
	if (ch != '/') {
		cerr << "invalid input, missing '/'" << endl;
		return in;
	}
    
	in >> z;
    
    dt.setDate(y,x,z);
    
    return in;
}
