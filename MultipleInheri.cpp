#include<iostream>
using namespace std;

// class   {{Class-Derived}}   :   {{visibility-mode-1}}  {{base-class-1}},  {{visibility-mode-2}}  {{base-class-2}}


// {
//      // Class body . . .  
// }
// Syntax for multiple ingeritance --> One class derived from two base classes . . . 


class Base1{
    protected:
        int A;
    public:
        Base1(void){
            // Default Constructor 
        }

        Base1(int X){
            A = X;
        }

        void SetA(int Z){
            A = Z;
        }
};

class Base2{
    protected:
        int B;
    public:
        Base2(void){
            // Default constructor
        }

        Base2(int X){
            B = X;
        }

        void SetB(int Z){
            B = Z;
        }
};

class Derived : public Base1, public Base2{
    protected:
        int C;
    public:
        Derived(void){
            //  Default constructor
        }

        Derived(int X, int Y, int Z){
            A = X;
            B = Y;
            C = Z;
        }

        void GetData(void){
            cout<<"The value of A is : "<<A<<endl;
            cout<<"The value of B is : "<<B<<endl;
            cout<<"The value of C is : "<<C<<endl;
        }

        void SetC(int Z){
            C = Z;
        }
};


int main()
{
    Derived Obj;
    Obj.SetA(1);
    Obj.SetB(2);
    Obj.SetC(3);
    Obj.GetData();
    // Obj.A = 1;
    return 0;
}