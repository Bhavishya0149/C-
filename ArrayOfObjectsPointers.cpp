#include<iostream>
using namespace std;

class Complex{
    protected:
        int A, B;
    public:
        Complex(void){
            // Default constructor . . .
        }
        Complex(int X, int Y) : A(X), B(Y){ cout<<"Constructor called!\n";}
        void GetData(void){
            cout<<"Your complex no. is "<<A<<" + "<<B<<"i.\n";
        }
        void SetData(int X, int Y){
            A = X; B = Y;
        }
};

int main()
{
    Complex *Pointer = new Complex[3];
    Pointer->SetData(2,3);
    Pointer->GetData();
    return 0;
}