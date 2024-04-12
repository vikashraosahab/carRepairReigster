// CREATE DETIALS AS ABSTRACT CLASS 
// IT'S A BASE CLASS THAT HAVE ONLY IMPORTANT DATA
#ifndef DETAILS_H
#define DETAILS_H

#include <iostream> // INPUT/OUTPUT STREAM HEADER FILE
#include "Date.h"
#include "get_carName.h"

// DECLARE REQUIRED NAMESPACE STD
using std::cout;
using std::cin;
using std::string;
using std::endl;


// CREATING CLASS NAMED AS DETAILS

template <class S, class I> // DECLARE TEMPLATE OF THE CLASS
class Details {
   public: /* MEMBER FUNCTIONS */
    Details (S &, S &, S &); // CLASS CONSTRUCTOR
    virtual void print (); // CREATE A VIRTUAL CLASS 
    virtual void display () = 0; // PURE-VIRTUAL CLASS
   
   private: /* DATA MEMBERS */
    S modelName;
    S modelNumber;
    S modelColor;
};

// CLASS DEFINITION
template <class S, class I>
Details <S, I>::Details (S &name, S &number, S &color) {
   this->modelName = name;
   this->modelNumber = number;
   this->modelColor = color;
}

// CLASS DEFINITIN 
template <class S, class I>
void Details<S,I>::print(){
  cout << "Model Name : " << this->modelName << endl;
  cout << "Model Number : " << this->modelNumber << endl;
  cout << "Model Color  : " << this->modelColor << endl;
 }

#endif