#include<iostream>
using namespace std;

// class Calculator;
class Complex; // Have to declare here cause we have to define complex for the compiler to not throw error in line 9!

class Calculator{
    public:
        void CalSum(Complex, Complex);       // Declaring here, will be written properly later as
                                             // Private data members R and I haven't been created
                                             // And compiler would throw another error
        void CalSum2(Complex, Complex);

};                                     
class Complex{
    private:
        int R;
        int I;

        friend void Sum(Complex A, Complex B);
        friend void Calculator :: CalSum(Complex, Complex); // HAve defined that said function of class is a friend!
        friend class Calculator;

    public:
        void SetData(int a, int b){
            R = a;
            I = b;
        }

        void GetData(void){
            cout<<"Complex number is : "<<R<< " + i"<<I<<"."<<endl;
        }

        
};

void Sum(Complex A, Complex B){    // This is a friend function without any class
    int X = A.R + B.R;
    int Y = A.I + B.I;
    cout<<"The complex number is "<<X<<" + i"<<Y<<".\n";
}
                                                     // WIll code friend function here cause now both classes,
void Calculator :: CalSum(Complex A, Complex B){     // all data (R and I) have been defined 
    int X = A.R + B.R;
    int Y = A.I + B.I;
    cout<<"The complex number is "<<X<<" + i"<<Y<<".\n";
}

void Calculator :: CalSum2(Complex A, Complex B){
    int X = A.R + B.R;
    int Y = A.I + B.I;
    cout<<"The complex number is "<<X<<" + i"<<Y<<".\n";
        

}

int main()
{
    Complex C1,C2;
    int A = 1; int B = 2; int C = 3; int D = 4;

    C1.SetData(A, B);
    C1.GetData();

    C2.SetData(C,D);
    C2.GetData();
    Calculator Item;
    // Item.CalSum(C1, C2); // Indivisual friend function
    Item.CalSum2(C1, C2);

    return 0;
}