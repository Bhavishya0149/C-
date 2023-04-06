#include<iostream>
using namespace std;


class Base{
    public:
        int Var1;
        virtual void Display(void) = 0; // This is how to make a pure virtual function . . .
        // When a pure virtual func is declared, objects cannot be created in that class . . . . . . .
        // {
        //     cout<<"Var1 value : "<<Var1<<endl;
        // }
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
    Base * Base_Class_Pointer;
    // Base BaseClassObject;
    Derived DerivedClassObject;

    Base_Class_Pointer = &DerivedClassObject;
    Base_Class_Pointer->Var1 = 7; // Base_Class_Pointer->Var2 = 14;
    Base_Class_Pointer->Display();

    return 0;
}


