#include<iostream>
using namespace std;

class Solution{
    int h;
    
    void findheight(struct Node * Ptr, int count){
        if(Ptr == NULL){
            if(count > h){
                h = count;
            }       
            return;
        }
        count++;
        // For left . . .
        findheight(Ptr->left, count);
        
        // For right . . .
        findheight(Ptr->right, count);
        return;
    }

public:
    //Function to find the height of a binary tree.
    int height(struct Node* node){
        h = 0;
        
        findheight(node, 0);
        return h;
    }
};

int main()
{
    
    return 0;
}