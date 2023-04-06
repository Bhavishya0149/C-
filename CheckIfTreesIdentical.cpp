#include<iostream>
using namespace std;

class Solution{
    void check(Node *r1, Node *r2, bool &ans){
        if(r1 == NULL && r2 == NULL)
            return;
            
        if(r1 == NULL || r2 == NULL){
            ans = false; return;
        }
            
        if(r1->data != r2->data){
            ans = false; return;
        }

        check(r1->left, r2->left, ans);
        check(r1->right, r2->right, ans);
    }
    public:
    //Function to check if two trees are identical.
    bool isIdentical(Node *r1, Node *r2){
        bool ans = true;
        
        check(r1, r2, ans);
        return ans;
    }
};


int main()
{
    
    return 0;
}
