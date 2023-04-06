#include<iostream>
#include<vector>
#include<string>
using namespace std;

void findSubstrings(string Str, vector <string> &SolnVec, string SolnStr, int index){
    if (index == Str.size() - 1){
        SolnVec.push_back(SolnStr);
        SolnStr += Str[index];
        SolnVec.push_back(SolnStr);
        return;
    }
    
    findSubstrings(Str, SolnVec, SolnStr, index + 1);
    SolnStr += Str[index];
    findSubstrings(Str, SolnVec, SolnStr, index + 1);
}


vector <string> allSubstrings(string Str){
    vector <string> SolnVec; 
    string SolnStr = ""; 

    findSubstrings(Str, SolnVec, SolnStr, 0);

    // Un-comment to remove enpty subsering . . .
    // for(int i = 0; i < SolnVec.size(); i++){
    //     if(SolnVec[i].size() == 0){
    //         SolnVec.erase(SolnVec.begin() + i);
    //     }
    // }

    return SolnVec;
}


int main()
{
    string Str = "abcd";

    vector <string> vec1 = allSubstrings(Str);

    for (int i = 0; i < vec1.size(); i++){
        cout<<vec1[i]<<endl;
    }
    

    return 0;
}