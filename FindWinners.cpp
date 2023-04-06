#include<iostream>
#include<map>
#include<vector>
#include<algorithm>
using namespace std;

class Solution {
public:
    vector<vector<int>> findWinners(vector<vector<int>>& matches) {
        
        vector <vector <int>> ans;
        vector <int> v1; vector <int> v2;
        ans.push_back(v1); ans.push_back(v2);
        
        map <int, int> m1;
        
        int num_match = matches.size() - 1;
        
        for(int i = 0; i <= num_match; i++){
            m1[matches[i][1]]++;
        }
        
        map <int, int> inserted;
        
        for(int i = 0; i < matches.size(); i++){
            if(m1[matches[i][0]] == 0 and inserted[matches[i][0]] == 0){
                ans[0].push_back(matches[i][0]); inserted[matches[i][0]]++;
            }
            if(m1[matches[i][1]] == 1 and inserted[matches[i][1]] == 0){
                ans[1].push_back(matches[i][1]); inserted[matches[i][1]]++;
            }
        }
        
        sort(ans[0].begin(), ans[0].end());
        sort(ans[1].begin(), ans[1].end());
        return ans;
    }
};

int main()
{
    
    return 0;
}