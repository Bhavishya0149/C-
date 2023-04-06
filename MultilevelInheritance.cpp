#include<iostream>
using namespace std;

// Student --> Exam --> Result . . . 

class Student{
    protected:
        string Address;
        string Gender;
    
    public:
        int RollNo;

        Student(void){
            // Default constructor            
        }

        Student(string B, string C, int D){
            Address = B; Gender = C; RollNo = D;
        }

        void GetData(void){
            cout<<"The Address of the student is : "<<Address<<endl;
            cout<<"The Gender of the student is : "<<Gender<<endl;
            cout<<"The Roll No of the student is : "<<RollNo<<endl;
        };
};


class Exam : public Student{
    protected:
        int MarksP;
        int MarksC;
        int MarksM;

    public:
        Exam(void){
            // Default Constructor
        }

        Exam(int A, int B, int C, int D){
            MarksP = A; MarksC = B; MarksM = C; RollNo = D;
        }

        void GetData(void){
                cout<<"Marks of student in Physics are : "<<MarksP<<endl;
                cout<<"Marks of student in Chemistry are : "<<MarksC<<endl;
                cout<<"Marks of student in Maths are : "<<MarksM<<endl;
                cout<<"Roll no of student in Maths are : "<<RollNo<<endl;
        };
};

class Result : private Exam{
    public:
        Result(void){
            // Default constructors
        }

        Result(int A, int B, int C, int D){
            MarksP = A; MarksC = B; MarksM = C; RollNo = D;
        }

        void GetData(void){
                cout<<"Marks of student in Physics are : "<<MarksP<<endl;
                cout<<"Marks of student in Chemistry are : "<<MarksC<<endl;
                cout<<"Marks of student in Maths are : "<<MarksM<<endl;
                cout<<"Roll no of student in Maths are : "<<RollNo<<endl;
        };

};


int main()
{
    // string Add, Gender;
    // cout<<"Enter the address of the student : "; cin.ignore(0); getline(cin, Add);
    // cout<<"Enter the Gender of the student : "; cin.ignore(0); getline(cin, Gender);

    // int RN = 1;

    // Student Voldo(Add, Gender, RN);
    // Voldo.GetData();

    Result PT1(12, 13, 14, 1);
    PT1.GetData();

    return 0;
}