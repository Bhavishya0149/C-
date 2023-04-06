#include<iostream>
using namespace std;

class Dukaan{
    private:
        int ShopNum;
        string Address;
        string Ownername;

    public:
        void SetData(void){
            cout<<"Enter the shop number : "<<endl; cin>>ShopNum;
            cout<<"Enter the Address : "<<endl; 
            cin.ignore();
            getline(cin, Address);
            cout<<"Enter the name of the owner of the shop : "<<endl;
            cin.ignore();
            getline(cin, Ownername);
        }

        void GetData(void);


};

void Dukaan :: GetData(void){
    cout<<"Shop number is : "<<ShopNum;
    cout<<"\nAddress is :"<<Address;
    cout<<"\nOwnername is :"<<Ownername;
}


class Complex{
    private:
        int R;
        int I;
    public:
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
};


class Employee{
    private:
        int EMPID[100];
        int EMPSal[100];
        int Count;
        int GCount;

    public:
        void SetData(void){
            cout<<"Enter Employee ID : ";
            cin>>EMPID[Count];
            cout<<"ENter Employee Salary : ";
            cin>>EMPSal[Count];
            Count++;
        }

        void SetCount(void){
            Count = 0;
            GCount = 0;
        }

        void SetMultiple(int a){
            int x = Count;
            for (int i = x; i < x + a; i++)
            {
                cout<<"Enter Employee ID : ";
                cin>>EMPID[i];
                cout<<"ENter Employee Salary : ";
                cin>>EMPSal[i];
            }
            Count = Count + a;
        }

        void GetData(int x){
            int z = GCount;
            for (int y = z; y < z + x; y++)
            {
                cout<<"\nID of employee "<<y + 1<<" is : "<<EMPID[y];
                cout<<"\nSalary of employee "<<y + 1<<" is : "<<EMPSal[y];
            }
            GCount = GCount + x;

        }



};


// Practicing static data values 
class Book{
    private:
        string BAuthor;
        string BName;
        static int Count;

    public:
        void SetData(void){
            cout<<"Enter book name : \n";
            getline(cin, BName);
            cout<<"Enter author name : \n";
            getline(cin, BAuthor);
        }

        void GetData(void){
            cout<<"Book name : "<<BName<<endl;
            cout<<"Book author : "<<BAuthor<<endl;

        }
};

int Book :: Count; // Have to declae static variable outside class
                   // A static  variables is only initialised once amongst all the items in a class!
                   // 

int main()
{
    // Dukaan D1;
    // 
    // D1.SetData();
    // D1.GetData();
    // 
    // Complex C1;
    // int x = 2;
    // int y = 4;
// 
    // C1.SetData(x, y);
    // 
    // Complex C2;
    // C2.SetData(x, y);
// 
    // Complex C3;
    // C3.SetData(C1 , C2);
    // C3.GetData();

    // Employee Voldo;

    // Voldo.SetCount(); 
    // Voldo.SetData();
    // Voldo.SetMultiple(2);
    // Voldo.SetData();
    // Voldo.GetData(3); 
    // Voldo.GetData(1);

    Book B1;
    B1.SetData();
    B1.GetData();


    return 0;
}