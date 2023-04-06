#include<iostream>
#include<climits>
using namespace std;

// Program to find the minimum and maximum number in am array.

int main()
{
    int LenArray;
    cout<<"Enter the number of terms in your array : "; cin.ignore(0); cin>>LenArray;
    
    int ArrayMain[LenArray]; cout<<"\nEnter the elements : "; cin.ignore(0);

    for (int i = 0; i < LenArray; i++){
        cin>>ArrayMain[i];
    }
    
    int LeastEle = INT_MAX, MostEle = INT_MIN;

    for (int j = 0; j < LenArray; j++){
        if (ArrayMain[j] < LeastEle){
            LeastEle = ArrayMain[j];
        }
    }
    
    for (int k = 0; k < LenArray; k++){
        if (ArrayMain[k] > MostEle){
            MostEle = ArrayMain[k];
        }
    }
    
    cout<<"The smallest and the biggest element in the array are "<<LeastEle<<" and "<<MostEle<<" resspectively.\n";
    int Killtime; cin>>Killtime;

    return 0;
}