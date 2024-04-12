// CREATE A PROGRAM OF  CAR SERVICE RELATED PROGRAM
#include <iostream> // STREAM INPUT/OUTPUT HEADER FILE
#include "details.h" // INCLUDING DETAILS HEADER FILE
#include <fstream> // FILESTREAM
#include "CarDetails.h"
#include "Date.h"
#include "get_carName.h"

// ENABLE REQUIRED STD NAMESPACE METHOD TO USE
using std::cout; // STANDARD FUNCTION METHOD FOR OUTPUT
using std::cin; // STANDARD FUNCTION METHOD FOR INPUT
using std::string; // STANDARD FUNCTION METHOD FOR STRING
using std::ofstream;
using std::ifstream;
using std::fstream;

// MACROS CONTANT
#define MAX_LENGTH 10

// HEADING OF THE MAIN () FUNCTION 
int main (void) {

   // OPEN A FILE Name as Register
   // ifstream input ("register.dat"); // OPEN FILE BY USING IFSTREAM OBJECT
    string carModel, carNumber, carColor,owner; // VARIABLE DECLARATION
    string service[5];

    // INSTANTIATE YOUR CLASS HERE
    cout << "Enter Model Name : "; // CAR MODEL 
    getline (cin,carModel); // GETLINE 
    cout << "Enter Model Number : "; // CAR NUMBER
    getline (cin,carNumber); // GETLINE
    cout << "Enter Model Color : "; // CAR COLOR
    getline (cin,carColor); // GETLINE
    cout << "Enter car owner name : ";
    getline (cin,owner);
    int count; // VARIABLE DECLARATION
    cout << "How many services did : ";
    cin >> count;

    for (int i = 0; i < count; i++) {
     cout << "Enter services No : " << i + 1 << endl;
     cin >> service[i]; 
    }
     
    cout << "Enter rate of services : ";
    int length = count;
    int rate[count];
    cin.ignore();
    for (int i = 0; i < length; i++) {
        cout << "Enter rate of servies : " << service[i] << endl;
        cin >> rate[i];
    }
     // VARIABLE DECLARATIONS
     char *day;
     char *month;
     char *year;

     day = new char [MAX_LENGTH];
     cin >> day;
     month = new char [MAX_LENGTH];
     cin >> month;

     year = new char [MAX_LENGTH];
     cin >> year;
    
    // INSTANTIATE  DATE OBJECT
    Date date (day,month,year);

    // INSTANTIATE CAR CLASS
     Car<string,int> objCar (
        carModel,
        carNumber,
        carColor,
        service,
        owner,
        rate,
        count
        );    
    // BASE CLASS POINTER TO DERIVED CLASS REFERENCES
     // ABSTRACTED BASE CLASS
     Details<string,int> *ptr = &objCar;
     ptr->display();
      
   // friend function 
     showCar (objCar);


     
     // DE-ALLOCATION OF MEMORY
     delete[] day;
     delete[] month;
     delete[] year;
    return 0; // IT INDICATE THAT PROGRAM EXECUTE SUCCESSFULLY
}