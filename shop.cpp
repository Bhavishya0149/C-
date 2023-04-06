#include<iostream>
using namespace std;

class shop
{
    private:
        string ShopName;
        string Address;
        int Counter;
        int ItemID[100];
        int Price[100];
        static int Count;
    public:
        

        void SetName(void) 
        {
            cout<<"Enter the name of your shop :\n"; 
            //cin.ignore();
            getline(cin, ShopName);
        }

        void PrintName(void) { cout<<"The name of your shop is : "<<ShopName<<endl;}

        void SetAddress(void)
        {
            cout<<"Enter the address of your shop :\n"; 
            //cin.ignore();
            getline(cin, Address);
        }
        
        void PrintAdd(void) { cout<<"The address of your shop is : "<<Address<<endl;}

        void SetCounter(void) { Counter = 0;}

        void SetValues(int N)
        {
            int Cint = 0;
            for (int i = Counter; i < Counter + N; i++)
            {
                cout<<"Enter item id for item : ";
                cin>>ItemID[i];
                cout<<"Enter the price of item with id "<<ItemID[Counter + Cint]<<" : ";
                cin>>Price[i];
                Cint++;               
            }
            Counter = Counter + N;

        }

        void ShowVal(int N)
        {
            for (int j = 0; j < N; j++)
            {
                cout<<"The price of item with id "<<ItemID[j]<<" is "<<Price[j]<<endl;
            }
        }
};

int shop :: Count; // Default val is 0. It is shared between different objects of the same class (here shop!)
// default vall = 0;


int main()
{
    shop Dukaan;
    Dukaan.SetName();
    Dukaan.PrintName();
    // Dukaan.SetAddress();
    // Dukaan.PrintAdd();
    // Dukaan.SetCounter();
    // Dukaan.SetValues(3);
    // Dukaan.ShowVal(3);
    // Dukaan.SetValues(3);
    // Dukaan.ShowVal(6);



    return 0;
}