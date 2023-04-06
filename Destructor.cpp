#include<iostream>
using namespace std;

class Point{
    int A;
    public:
        Point(){}

        // A destructor takes no argumaants nor does it return any value . . . 
        ~Point(){
            cout<<"Destructor called!"<<endl;
        }
};



int main()
{
    Point X;
    Point Y;

    int A = 1;
    
    if (A != 1){
        Point Z;
        Point C;
    }

    // cout<<"Exited  the if statement . . ."<<endl;

    // Destructor called twice when program ends . . .
    return 0;
}