#include<iostream>
using namespace std;

// Using pointer to set data in a class object!

class Complex{
    protected:
        int A, B;
    public:
        Complex(void){
            // Default constructor . . .
        }
        Complex(int X, int Y) : A(X), B(Y){ cout<<"Constructor called!\n";}
        void GetData(void){
            cout<<"Your complex no. is "<<A<<" + i"<<B<<".\n";
        }
        void SetData(int X, int Y){
            A = X; B = Y;
        }
};

int main()
{
    Complex Voldo;
    // Voldo.GetData();

    Complex* Pointer = &Voldo;
    
    // (*Pointer).SetData(2,3);
    // (*Pointer).GetData();   // This is exactly same as . . .

    Pointer->SetData(2,3);
    Pointer->GetData();

    // "->" operator deferences a pointer variable . . .

    return 0;
}