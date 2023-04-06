#include<iostream>
using namespace std;

class Employee
{
    private:
        int a, b, c;
    public:
        int d, e;
        void setData(int a, int b, int c);
        void getData()
        {
            cout<<"The value of a, b, c, d, e are "<<a<<endl<<b<<endl<<c<<endl<<d<<endl<<e<<endl;
        }


};

void Employee :: setData(int a1, int b1, int c1)
{
    a = a1;
    b = b1;
    c = c1;
}   // This can be initiated in the class itself but yahaan bahaar karne ka tareeka hai ye bas :)

class binary
{
    string s;

    public:
        void read();
        void Checl_bin();

};

void binary :: read(){
    cout<<"Enter a binary number : ";
    cin>>s;
}

void binary :: Checl_bin(){
    for (int i = 0; i < s.length(); i++)
    {
        if ((s.at(i)!= '0') && (s.at(i)!= '1'))
        {
            cout<<"Incorrect binary format! "<<endl;
            exit(0);
        }
        
    }
}



int main()
{
/*    Employee Voldo;
    Voldo.setData(1,2,3);
    Voldo.getData(); */

    binary B;
    B.read();
    B.Checl_bin();
    return 0;
}