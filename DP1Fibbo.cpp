#include<iostream>
using namespace std;

int DPArray[1000];

// Without DP
int Fibbo(int N){
    if (N == 0)
        return 0;
    if (N == 1)
        return 0;
    if (N == 2)
        return 1;
    return (Fibbo(N-1) + Fibbo(N-2));
}

int FIbboDP(int N){
    if (N == 1)
        return 1;
    if (N == 2)
        return 1;

    if (DPArray[N] != -1)
        return DPArray[N];

    DPArray[N] = (FIbboDP(N-1) + FIbboDP(N-2));
    return DPArray[N];
}

int main()
{
    int NthTerm; cout<<"Enter the Fibbo term you want displayed : ";
    cin.ignore(0); cin>>NthTerm;

    for (int i = 0; i < 1000; i++)
        DPArray[i] = -1;
    
    // cout<<Fibbo(NthTerm);
    
    

    cout<<FIbboDP(NthTerm);

    int KillTime; cin>>KillTime;
    return 0;
}