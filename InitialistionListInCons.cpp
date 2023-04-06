#include<iostream>
using namespace std;
// Dynamic initialisation of list in constructor . . .
class Test{
    private:
        int I, J;
    
    public:
        // This is also how constructor can be used, to save space in code . . . ehe
        Test(int A, int B) : I(A), J(B) { cout<<"Constructor executed . . ."<<endl; }
        void GetData(void){
            cout<<"The value of I is : "<<I<<endl; 
            cout<<"The value of J is : "<<J<<endl; 
        }
};


int main()
{
    Test Voldo(2,3);
    Voldo.GetData();
    return 0;
}