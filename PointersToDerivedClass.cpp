#include<iostream>
using namespace std;


class Base{
    public:
        int Var1;
        void Display(void){
            cout<<"Var1 value : "<<Var1<<endl;
        }

};

class Derived : public Base{
    public:
        int Var2;
        void Display(void){
            cout<<"Var1 value : "<<Var1<<endl;
            cout<<"Var2 value : "<<Var2<<endl;
        }

};

int main()
{
    
    Base * Pointer;
    Base Object;

    Derived ObjDerived;
    Pointer = &ObjDerived;  // Pointing base class pointer to derived class

    // All this shhows that a base class's pointer can lock on to an object of a derived class . . .
    // This also means that . . . if we call a function, the  base class's will be clled!!!

    Pointer->Var1 = 10;
    Pointer->Display();  // See, the function of the base class has been called . . .
    // Because  of the pointer, the object has been binded to the base class, even the derivved's functions and methods CANNOT be accessed
    Derived DerObj2;
    Derived * DerPointer;
    DerPointer = &DerObj2;
    DerPointer->Var2 = 420;
    DerPointer->Var1 = 42006;
    DerPointer->Display();

    return 0;
}