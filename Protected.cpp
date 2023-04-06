// There is another type of data in class : Protected 
// A protected member is private, the only difference being that it can be inherited . . . 

#include<iostream>
using namespace std;

class Base{
    private:
        int A = 3;
        int B = 5;
    
    protected:
        int P;

    public: 
        int X;
        int Y;

        Base(void){
            // Default constructor
        }
};

class Derived : public Base{
    public:
        Derived(void){
            // Default constructor
        }

        Derived(int A, int B, int C){
            P = A;
            X = B;
            Y = C;
        }

        void GetData(void){
            cout<<"The value of P is : "<<P<<endl;
            cout<<"The value of P is : "<<X<<endl;
            cout<<"The value of P is : "<<Y<<endl;
        }

};

int main()
{
    Derived Voldo(1, 2, 3);
    
    // cout<<Voldo.P;  // Cant do because P is protected . . .  
    
    // Voldo.GetData();
    // return 0;

    Base X;
    cout<<X.P;
}