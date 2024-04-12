// PREPROCESSOR WRAPPER 
#ifndef CARDETAILS_H
#define CARDETAILS_H

/* PREPROCESSOR WRAPPER PREVANT MULTIPLE TIME CLASS REDEFINITION */
#include "details.h" // INCLUDE DETAILS HEADER FILE
#include <iostream>
#include <iomanip>

using std::cout;
using std::endl;
using std::string;
using std::cin;
using std::setw;
using std::setfill;
using std::operator+;

// CREATE A TEMPLATE 
template <class S, class I> 
// CAR CLASS IS INHERITED OR DERIVED FROM DETAILS BASE CLASS
class Car: public Details<S,I> {

  // FRIEND FUNCTION 
   friend void showCar (Car <S, I> &val) {
     cout << "total Amount : " << val.totalAmount << endl;  
   }
 public: // PUBLIC ACCESS SPECIFIER
  Car (S &name, S &number, S &color, S *s, S &own, I r[], I size):
  Details <S,I>(name,number,color),
  services (s),
  length (size),
  owner (own), rates (r) {};

  void display (){
    Car::print();
    cout << "Services : \n";
    for (int i = 0; i < length; i++) {
      cout << setw (10) << services[i] << endl;
    }
    cout << "Rate list : \n";
    for (int i = 0; i < length; i++) {
      cout << setw (4) << rates [i] << endl;
    }
   
   cout << "Amount : " << gettotalAmount() << endl;
   // cout << "Total Amount : " << totalAmount << endl;
   cout << "Gst :" << getGst () << endl;
   cout << "\n\n Total Amount that debited : " << gettotalAmount () + getGst () << endl;
    cout << "Owner : " << this->owner << endl;
  }

  // OPERATOR OVERLOADING

  int getGst () {
    int gst = 0;
    gst = totalAmount / 10;
    return gst;
  }

  int gettotalAmount ();
 private: // PRIVATE ACCESS SPECIFIER
 /* PRIVATE DATA MEMBER */
 S *services;
 S owner;
 I *rates;
 I length;
 I totalAmount = 0;
};

template <class S, class I>
 int Car<S,I>::gettotalAmount () {
   for (int i= 0; i < length; i++) 
    totalAmount += rates[i];

    return totalAmount;
}
#endif