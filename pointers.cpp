#include<iostream>
using namespace std;

void Swap(int &X, int &Y){
    int temp; temp = Y; Y = X; X = temp;
}

int main()
{
    int a = 10; // This is a variable
    int b = 5;
    int* aAdd = &a; // Storing Add(a) in aAdd (have to use star in front . . .)
                    // also have to use & in front of a to find it's address . . .
    cout<<a<<endl<<aAdd<<endl;

    // Swap(a, b);
    // cout<<"\nValues are "<<a<<" and "<<b;

    // New keyword . . .
    int* p = new int(420);
    cout<<"The address of new integer variable with val 420 is : "<<p<<endl;
    cout<<"The  value stored at the address *p is : "<<*p<<endl;

    // Allocating block of memory . . 
    int* Arr = new int [3];
    Arr[0] = 10; Arr[1] = 20; Arr[2] = 30;
    cout<<"The value of Arr[0] is : "<<Arr[0]<<endl;
    cout<<"The value of Arr[1] is : "<<Arr[1]<<endl;
    cout<<"The value of Arr[2] is : "<<Arr[2]<<endl;
    delete[] Arr;
    cout<<"The value of Arr[0] is : "<<Arr[0]<<endl;
    cout<<"The value of Arr[1] is : "<<Arr[1]<<endl;
    cout<<"The value of Arr[2] is : "<<Arr[2]<<endl;

    // int Voldo = 4;
    // // delete Voldo; Will not work, delete only for pointer . . .
    // cout<<Voldo; 
}