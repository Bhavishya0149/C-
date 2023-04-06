#include<iostream>
#include<vector>
#include<stack>
using namespace std;

bool isCelebrity(vector <vector <int>> vec1, int R){
        
    for(int i = 0; i < vec1.size(); i++){
        
        if (i == R){
            continue;
        } else if(vec1[i][R] == 1){
            continue;
        } else {
            return false;
        }
        
    }
    for(int j = 0; j < vec1[0].size(); j++){
        if(vec1[R][j] == 1){
            return false;
        }
    }
    return true;
}

int celebrity(vector<vector<int> >& M, int N){
    // Using stack
    stack <int> s;
    
    // Pushing all indexes into stack
    for(int i = 0; i <= N - 1; i++){
        s.push(i);            
    }
    
    // Taking two 'people' and seeing if one knows thhe other. If they do, THEY CANNOT BE THE CELEBRITY  . . .
    while(s.size() > 1){
        int i = s.top();     s.pop(); 
        int j = s.top();     s.pop();
        
        // The one who knows other person will not be added back to stack
        if(M[j][i] == 1){
            s.push(i);
        } else if (M[i][j] == 1){
            s.push(j);
        } else {
            continue;
        }
    }
    
    // If one candidateis left, check if they celebrity or not
    if(s.size() > 0){
        int cand = s.top();
        if(isCelebrity(M, cand)){
            return cand;
        }
    }

    // if not, return -1
    return -1;
}


int main()
{
    vector <vector <int>> vec1;
    vector <int> vec2;
    
    vec2.push_back(0);
    vec2.push_back(1);
    vec2.push_back(1);
    vec2.push_back(1);
    vec1.push_back(vec2);
    vec2.clear();

    vec2.push_back(0);
    vec2.push_back(0);
    vec2.push_back(0);
    vec2.push_back(0);
    vec1.push_back(vec2);
    vec2.clear();
    
    vec2.push_back(1);
    vec2.push_back(1);
    vec2.push_back(0);
    vec2.push_back(1);
    vec1.push_back(vec2);
    vec2.clear();

    vec2.push_back(0);
    vec2.push_back(1);
    vec2.push_back(0);
    vec2.push_back(0);
    vec1.push_back(vec2);
    vec2.clear();

    cout<<celebrity(vec1, 4);

    return 0;
}