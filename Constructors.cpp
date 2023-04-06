#include<iostream>
using namespace std;

class Complex{
    private:
        int R;
    public:
        int I;
        void SetData(int a, int b){
            R = a;
            I = b;
        }

        void GetData(void){
            cout<<"Complex number is : "<<R<< " + i"<<I<<"."<<endl;
        }

        void SetData(Complex a, Complex b){
            R = a.R + b.R;
            I = a.I + b.I;
        }

        // We can make multiple constructors and the ccompiler is wise enough to choose the most appropriate one!

        Complex(int X, int Y){
            cout<<"Calling constructor one!"<<endl;
            R = X;
            I = Y;
        }

        Complex(int X){
            cout<<"Calling constructor two!"<<endl;
            R = X;
        }

        // This is a destructor and it is automatically called by the coompiler 
        // When it is needed!

        ~Complex(){    
            cout<<"Calling destructor!"<<endl;
        }
};


int main()
{
    Complex C1(2, 3);  // Using constructor one!
    C1.GetData();

    Complex C2(3);     // Using constructor two!
    C2.I = 2;
    C2.GetData();

    return 0;
}