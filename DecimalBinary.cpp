#include<iostream>
using namespace std;

// Program to convert binary to decimal and vice versa.

// Binary to decimal
long long int BinaryToDecimal(long long int Num){
    long long int Result = 0; int count = 1;
    // cout<<"Hello";
    while (Num != 0){
        int Temp2Pow = 1;
        if ((Num % 10) != 0){
            for (int i = 1; i < count; i++){
                Temp2Pow = Temp2Pow * 2;
            }
            Result = Result + Temp2Pow; count++;
        } else
            count++;
        Num = Num / 10;
    }
    return Result;
}

// Decimal to binary
void DecimalToBinary(int X){
    int Remainders[31]; int count = 0;

    while (X != 0){
        Remainders[count] = X % 2;
        X = X / 2; count++; 
    }
    for (int i = (count - 1); i >= 0; i--){
        cout<<Remainders[i];
    }
    cout<<endl;
}

int main()
{
    int INPUT;
    cout<<"This program converts decimal numbers to binary and vice versa.\n";
    cout<<"1. Binary to decimal.\n2. Decimal to binary.\n3. Exit\n";
    cout<<"Pick your option : ";
    int LoopCheck = 1;

    while (LoopCheck == 1)
    {
        cin.ignore(0); cin>>INPUT;
        switch (INPUT){
        case 1:
            long long int NumInput; cout<<"Enter the BINARY NUMBER YOU WANT TO BE CONVERTED : ";
            cin.ignore(0); cin>>NumInput; cout<<"The decimal number is : ";
            cout<<BinaryToDecimal(NumInput); cout<<"\nEnter next option : ";
            break;
        case 2:
            int NumInput2; cout<<"Enter the DECIMAL NUMBER YOU WANT TO BE CONVERTED : ";
            cin.ignore(0); cin>>NumInput2; cout<<"The binary number is : ";
            DecimalToBinary(NumInput2);
            cout<<"\nEnter next option : ";
            break;
        case 3:
            cout<<"Exiting the program. Press any key to exit . . ."; LoopCheck = 0;
            break;
        }
    }
    
    int KillTime; cin>>KillTime;
    return 0;
}
