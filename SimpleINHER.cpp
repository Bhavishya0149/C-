#include<iostream>
using namespace std;

class McDonald{
    private:
        int OrgRevenue;
    public:
        int ShopID;
        string ShopAdress;

        McDonald(void){
            // Default constructor
        }

        void McSetRevenue(int A){
            OrgRevenue = A;
            cout<<"The organisation revenue has been set to "<<OrgRevenue<<"."<<endl;
        }
};


class IndShop : private McDonald{
    public:
        int ItemMenu;
    
    IndShop(void){
        // Default constructor
    }
    
    IndShop(int A, string B, int C){
        ShopID = A;
        ShopAdress = B;
        ItemMenu = C;
    }

    ShopGetdata(void){
        cout<<"Shop ID is : "<<ShopID<<endl;
        cout<<"Shop Address is : "<<ShopAdress<<endl;
        cout<<"No. of itemms on the mmenu are : "<<ItemMenu<<endl;
    }
};

// There is another type of data in class : Protected 
// A protected member is private, the only difference being that it can be inherited . . . 


int main()
{
    string Add;

    cout<<"Enter shop address : "; cin.ignore(0); getline(cin, Add);

    IndShop LuckyDept(1, Add, 10);
    LuckyDept.ShopGetdata();

    return 0;
}