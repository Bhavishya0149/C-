#include<iostream>
using namespace std;

// Binary Search in an array.
int BinarySearch(int arr[], int Key, int size){
    int CurrentSize = size/2; int PreviousSize;
    int UpperLimit = size; int LowerLimit = 0;
    while (CurrentSize != PreviousSize){
        if (arr[CurrentSize] == Key)
            return (CurrentSize);
        if (arr[CurrentSize] < Key){
            PreviousSize = CurrentSize; LowerLimit = CurrentSize; CurrentSize = (UpperLimit + LowerLimit) / 2;
        } else {
            PreviousSize = CurrentSize; UpperLimit = CurrentSize; CurrentSize = (UpperLimit + LowerLimit) / 2;
        }
    }
    // REturns -1 if element not found
    return -1;
}

int BinarySearchRecursion(int Arr[], int UpperLimit, int LowerLimit, int Key){
    if (UpperLimit == LowerLimit || LowerLimit > UpperLimit)
        return -1;
    
    int mid = LowerLimit + ((UpperLimit - LowerLimit )/ 2);
    if (Arr[mid] == Key)
        return mid;
    
    if (Key > Arr[mid])
        BinarySearchRecursion(Arr, UpperLimit, mid + 1, Key); // right
    else 
        BinarySearchRecursion(Arr, mid, LowerLimit, Key); // Left
}

int main(){
    cout<<"This program looks for an element in a sorted array using binary search.";
    cout<<" Enter the number of elements you want in your array : "; cin.ignore(0);
    int ArrayLength; cin>>ArrayLength; int ArrayMain[ArrayLength];

    cout<<"\nEnter the elements for your array (sorted) : "; cin.ignore(0);
    for (int z = 0; z < ArrayLength; z++){
        cin>>ArrayMain[z];
    }
    int EleToSearch; cout<<"Enter the element you want searched : ";
    cin.ignore(0); cin>>EleToSearch;

    int size = sizeof(ArrayMain)/sizeof(ArrayMain[0]);

    // cout<<BinarySearch(ArrayMain, EleToSearch, size);
    cout<<BinarySearchRecursion(ArrayMain, size, 0, EleToSearch);
    return 0;
}