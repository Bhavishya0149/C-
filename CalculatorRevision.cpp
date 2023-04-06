#include<iostream>
#include<cmath>
using namespace std;

class SimpCal{
    protected:
        float A, B;
    public:
        SimpCal(void){
            // Default COnstructor
        }
        
        void SetNums(float X, float Y){
            A = X; B = Y;
        }

        void GetNums(void){
            cout<<"The numbers you entered are "<<A<<" and "<<B<<endl;
        }

        float Sum(void){
            return A + B;
        }

        float Substract(void){
            return A - B;
        }

        float Multiply(void){
            return A*B;
        }

        float Divide(void){
            return A / B;
        }
};

class ScientificCal{
    protected:
        float C, D;
    public:
        ScientificCal(void){
            // Default COnstructor
        }
        
        void SetNums(float X, float Y){
            C = X; D = Y;
        }

        void GetNums(void){
            cout<<"The numbers you entered are "<<C<<" and "<<D<<endl;
        }

        float Power(void){
            float result = 1;
            for (int i = 0; i < D; i++)
            {
                result = result * C;
                // cout<<"Hello!";
            }
            return result;
        }

        float SRootA(void){
            return (sqrt(C));
        }

        float SRootB(void){
            return sqrt(D);
        }

        // float Sum(void){
        //     return A + B;
        // }
};

class HbdCalc : public ScientificCal, public SimpCal{
    public:
        HbdCalc(void){
            // Default COnstructor
        }

        HbdCalc(int Y, int Z){
            A = Y;
            B = Z;
            C = Y;
            D = Z;
        }

};

int main()
{
    // SimpCal Voldo;
    // Voldo.SetNums(1, 2.2);
    // Voldo.GetNums();
    // cout<<Voldo.Sum()<<endl;
    // cout<<Voldo.Substract()<<endl;
    // cout<<Voldo.Multiply()<<endl;
    // cout<<Voldo.Divide()<<endl;

    // Voldo.SetNums(2,4);
    // cout<<Voldo.Power()<<endl6;
    // cout<<"The square root of A is : "<<Voldo.SRootA()<<endl;
    // cout<<"The square root of B is : "<<Voldo.SRootB()<<endl;    
    // return 0;

    HbdCalc Voldo(2, 3);
    
    
    cout<<Voldo.Sum()<<endl;
    cout<<Voldo.Power()<<endl;
}
