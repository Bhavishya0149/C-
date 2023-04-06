#include<iostream>
#include<cmath>
using namespace std;

// This program looks at use of parametarised and default constructors
// Aldo a friend function :)
// Also cmath header file :)

class Point{
    int X,Y;
    friend void Distance(Point, Point);
    public:
        void SetPoint(int A, int B){
            X = A;
            Y = B;
        }

        void GetPoint(){
            cout<<"Your Point is "<<X<<"x + "<<Y<<"y."<<endl;
        }

        // Constructor with parameters . . .   
        Point(int A, int B){
            X = A; Y = B;
        }

        // Default Constructor 
        Point(void){
            //cout<<"Hello xd!";
        };
};

void Distance(Point A, Point B){
    float Dist;
    Dist = sqrt(((B.X - A.X)*(B.X - A.X)) + ((B.Y - A.Y)*(B.Y - A.Y)));
    cout<<"The distance between the points is "<<Dist<<" units."<<endl;
}

int main()
{
    Point A;
    A.SetPoint(4,5);
    A.GetPoint();
    
    Point B(6,6);
    B.GetPoint();

    Distance(A,B);


    return 0;
}