#include<iostream>
using namespace std;

int DP[1000];

int WaysToClimbDP(int Src, int Target){
    int Distance = Target - Src;

    if (Src == Target)
        return 1;
    
    if (Src > Target)
        return 0;

    if (DP[Distance] != -1)
        return DP[Distance];
    
    DP[Distance] = (WaysToClimbDP(Src + 1, Target) + WaysToClimbDP(Src + 2, Target));
    return DP[Distance];
}

int WaysToClimb(int Src, int Target){

    if (Src == Target)
        return 1;
    
    if (Src > Target)
        return 0;
    
    return WaysToClimb(Src + 1, Target) + WaysToClimb(Src + 2, Target);
}

int main()
{
    int Source, Destination;
    cout<<"The program will tell how many ways to climb the stairs . . . \n";
    
    for (int i = 0; i < 1000; i++)
        DP[i] = -1;

    // for (int j = 0; j < 1000; j++){
    //     cout<<DP[j]<<" ";
    // }
    

    // cout<<"How many stairs are there? : "; cin>>Destination; 
    // cout<<"What stair are you on? : "; cin>>Source;

    // if (Source >= 0 && Source < Destination){
    //     cout<<"The total number of ways are : "<<WaysToClimb(Source, Destination);
    // } else if ( Source < 0 || Source > Destination){
    //     cout<<"Invalid source . . . ";
    // } else {
    //     cout<<"Already at the destination!";
    // }
     
    cout<<WaysToClimbDP(3,10);
    return 0;
}