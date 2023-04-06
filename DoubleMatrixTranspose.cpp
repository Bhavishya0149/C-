#include<iostream>
using namespace std;

int main()
{

    int N,M; // Defined rows and colums
    cout<<"Enter no of rows and colums :";
    cin>>N>>M; // Taking size of rows and colums from user DO REMEMBER N = M FOR THIS!
    
    int ArrayMain[N][M];
    
    for (int INVal = 0; INVal < N; INVal++) // Taking elements input into arrays
    {
        for (int x = 0; x < M; x++)
        {
            cin>>ArrayMain[INVal][x];
        }
    }
    for (int ArP = 0; ArP < N; ArP++)  // Printinng the array out
    {
        for (int ArPP = 0; ArPP < M; ArPP++)
        {
            cout<<ArrayMain[ArP][ArPP]<<" ";
        }
        cout<<endl;
    }
    int TArrayMain[N][M]; // Making transpose
    for (int TR = 0; TR < N; TR++)
    {
        for (int TC = 0; TC < M; TC++)
        {
            int temp = ArrayMain[TR][TC];
            TArrayMain[TC][TR] = temp;
        }
        
    }
    cout<<endl<<"----------------------------"<<endl<<endl;
    for (int PR = 0; PR < N; PR++)
    {
        for (int PC = 0; PC < M; PC++)
        {
            cout<<TArrayMain[PR][PC]<<" ";
        }
        cout<<endl;
    }
    
    
    
    
    
    
    int KillTime;
    cin>>KillTime;
     // TO COMPLETE! Print elements out in spiral format . . .
    return 0;
}