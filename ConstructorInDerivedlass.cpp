#include<iostream>
using namespace std;

class Base1{
    protected:
        int A;
    public:
        Base1(int W){
            A = W; cout<<"Base1 constructor called . . ."<<endl;
        }

        Base1(void){
            // Default constructor
        }
};


class Base2{
    protected:
        int B;
    public:
        Base2(int X){
            B = X; cout<<"Base2 constructor called . . ."<<endl;
        }

        Base2(void){
            // Default constructor
        }
};

class Derived : protected Base2, protected Base1{
    protected:
        int C, D;
    public:
        Derived(int W, int X, int Y, int Z) : Base1(W), Base2(X){
            C = Y; D = Z;
            cout<<"Derived class constructor called . . ."<<endl;
        }

        void GetData(void){
            cout<<"The value of A is "<<A<<endl;
            cout<<"The value of B is "<<B<<endl;
            cout<<"The value of C is "<<C<<endl;
            cout<<"The value of D is "<<D<<endl;
        }

        Derived(void){
            // Default constructor 
        }

};

int main()
{
    Derived Voldo(1,2,3,4);
    Voldo.GetData();

    Derived Eshaan;

    return 0;
}