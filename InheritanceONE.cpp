/* First tutorial of Inheritance! There are mainly four types of inheritence!
// 1. Single Inheritance!
// 2. Multiple Inheritance!
// 3. Hierarchical Inheritance!
// 4. Mulltilevel Inheritance!
// 5. Hybrid Inheritance!


    Single :               One derived class with one Base class
//                         eg: Employee class extended to Programmer class.
    
    Multiple :             One derived class with multiple base classes
//                         eg: USE YO BRAIN

    Hierarchical :         One base class with multiple derived classes
//                         eg: USE YO BRAIN

    Multilevel :           Deriiving a class from an already derived classes
//                         eg: Animal -> Fish -> Shark

    Hybrid :               Combination of multiple and multilevel Hs!
//                                           ________________
//                                          |                |
//                                          |       A        | Animal
//                                          |________________|
//                                            |            |
//                                            |            |
//                                       _____|___      ___|_____ 
//                                      |         |    |         |
//                               Mammal |    B    |    |    C    | Bird
//                                      |_____.___|    |___._____|
//                                            |            |
//                                            |            |
//                                           _|____________|_                                           
//                                          |                |
//                                          |       D        | Bat
//                                          |________________|
//
*/
#include<iostream>
using namespace std;

// Simple example of inheritance -->
// Base Class is Employee
class Employee{
        

    public:
        int ID;
        float Salary;
        
        Employee(int X){
            ID = X;
            Salary = 17.7;
        }

        Employee(){
            // Default constructor . . .
        }
};


/* Derived Class                     // Default visibility mode is private . . .
class {{ derived-class-name }} : {{ visibility-mode }} {{ base class name }}

Text in the double bracket is meant to be replaced . . .   */
// Creating a derived base class (Programmer) from base class (Employee).

class Programmer : private Employee{
    public:
        int LanguageCode = 9;

        Programmer(int Y, float Z){
            ID = Y;
            Salary = Z;
        }

        GetData(){
            cout<<ID<<endl;
            cout<<Salary<<endl;
            cout<<LanguageCode<<endl;
        }

};

// Private VM : Public members of BC become private members of DC
// Public VM : Public members of BC become public members of derived class
//PRIVATE MEMBBERS CANNOT BE INHERITED! 



int main(){
    
    // Employee Voldo(1), Eshaan(2);
    // cout<<Voldo.Salary<<endl<<Eshaan.Salary<<endl;

    Programmer WallE(3, 7.1);
    WallE.GetData();

    return 0;
}