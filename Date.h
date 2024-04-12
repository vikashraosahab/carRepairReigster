// PREPROCESSOR WRAPPER 
#ifndef DATE_H
#define DATE_H

#include <iostream> // PREPROCESSOR DIRECTIVE HEADER FILE
#include <iomanip>
#include <string.h>

// ENABLE REQUIRED 
using std::cout;
using std::cin;
using std::endl;
using std::setw;
using std::setfill;
// CREATE AN DATE CLASS
class Date {
  
  public: // PUBLIC ACCESS SPECIFIER
  Date (
    char *,
    char *,
    char*
    );
    // CONSTRUCTOR
   ~Date (); // DESTRUCTOR
   
  void print () const;

   /* PRIVATE DATA MEMBER */ 
  private:
  char *day;
  char *month;
  char *year;
};
// CLASS DEFINITION
Date::Date (
    char* d, 
    char* m, 
    char * y
    ){
    // GET LENGTH 
     int length = strlen (d);

     day = new char [length];

     strcpy (day,d);

     length = strlen (m);

     month = new char [length];

     strcpy (month,m);

     length = strlen (y);

     year = new char [length];

     strcpy (year,y);
    }

Date::~Date()
{
    delete[] day;
    delete[] month;
    delete[] year;
}

void Date::print () const {
    cout << "Register Date : ";
    cout << setfill ('0')  << setw (2) << day << ":"
         << setw (2) << month << ":" << setw (2) <<
         year;
}
#endif