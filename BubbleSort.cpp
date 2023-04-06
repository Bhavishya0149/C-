#include<iostream>
using namespace std;

// Program to perform a bubble sort on an array.

int main()
{
    int Size; cout<<"Enter the size of your array : "; cin.ignore(0); cin>>Size;
    int ArrayMain[Size];

    cout<<"Enter the elements of your array : ";
    for (int i = 0; i < Size; i++)
        cin>>ArrayMain[i];
    
    int LoopCount = 0; int RunSize = Size;

    while (LoopCount < Size){
        for (int i = 0; i < RunSize - 1; i++){
            if (ArrayMain[i] > ArrayMain[i + 1])
                swap(ArrayMain[i], ArrayMain[i + 1]);
        }
        LoopCount++; RunSize--;
    }
    
    for (int o = 0; o < Size; o++)
        cout<<ArrayMain[o]<<" ";
    
    

    return 0;
}