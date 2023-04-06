#include<iostream>
#include<vector>
#include<map>
using namespace std;

struct Node
{
    int data;
    struct Node* left;
    struct Node* right;
    
    Node(int x){
        data = x;
        left = right = NULL;
    }
};

int maxh;

void mapNodes(Node * root, map <int, pair <int, int>> &m, int h, int VD){
    if(root == NULL) return;
    
    // if(m[h].second > 0){
    //     if(VD < m[h].first){
    //         m[h] = make_pair(VD, root->data);
    //     }
    // } 
    
    if(h > maxh){
        m[h] = make_pair(VD, root->data);
        maxh = h;
    }
    
    // Switch for right view . . .
    mapNodes(root->left, m, h + 1, VD - 1);
    mapNodes(root->right, m, h + 1, VD + 1);
}

void buildAns(map <int, pair <int, int>> m, vector <int> &ans){
    for(int i = 0; i <= maxh; i++){
        ans.push_back(m[i].second);
    }
}


//Function to return a list containing elements of left view of the binary tree.
vector<int> leftView(Node *root){
   vector <int> ans;
   if(root == NULL) return ans;
   //    h         VD   data
   map <int, pair <int, int>> m;
   
   m[0] = make_pair(0, root->data); maxh = 0;
   
   // MapNodes // Switch for right view . . .
   mapNodes(root->left, m, 1, -1);
   mapNodes(root->right, m, 1, 1);
   
   // buildAns
   buildAns(m, ans);
   return ans;
}

int main(){

    return  0;
}