//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;
#define MAX_HEIGHT 100000

// Tree Node
struct Node
{
    int data;
    Node* left;
    Node* right;
};

// Utility function to create a new Tree Node
Node* newNode(int val)
{
    Node* temp = new Node;
    temp->data = val;
    temp->left = NULL;
    temp->right = NULL;

    return temp;
}


vector <int> bottomView(Node *root);

// Function to Build Tree
Node* buildTree(string str)
{
    // Corner Case
    if(str.length() == 0 || str[0] == 'N')
        return NULL;

    // Creating vector of strings from input
    // string after spliting by space
    vector<string> ip;

    istringstream iss(str);
    for(string str; iss >> str; )
        ip.push_back(str);

    // Create the root of the tree
    Node* root = newNode(stoi(ip[0]));

    // Push the root to the queue
    queue<Node*> queue;
    queue.push(root);

    // Starting from the second element
    int i = 1;
    while(!queue.empty() && i < ip.size()) {

        // Get and remove the front of the queue
        Node* currNode = queue.front();
        queue.pop();

        // Get the current node's value from the string
        string currVal = ip[i];

        // If the left child is not null
        if(currVal != "N") {

            // Create the left child for the current node
            currNode->left = newNode(stoi(currVal));

            // Push it to the queue
            queue.push(currNode->left);
        }

        // For the right child
        i++;
        if(i >= ip.size())
            break;
        currVal = ip[i];

        // If the right child is not null
        if(currVal != "N") {

            // Create the right child for the current node
            currNode->right = newNode(stoi(currVal));

            // Push it to the queue
            queue.push(currNode->right);
        }
        i++;
    }

    return root;
}


// } Driver Code Ends
//Function to return a list containing the bottom view of the given tree.

class Solution {
  int maxpos, minpos; 
  
  void mapNodes(Node * root, map <int, pair <int, vector <int>>> &m, int h, int VD){
      if(root == NULL) return;
      
      if(VD < minpos || VD > maxpos){
          vector <int> evec; evec.push_back(root->data);
          m[VD] = make_pair(h, evec); evec.clear();
          
          if(VD < minpos) minpos = VD;
          else maxpos = VD;
      }
      
      if(m[VD].first > 0){
          if(m[VD].first < h){
              vector <int> evec; evec.push_back(root->data);
              m[VD] = make_pair(h, evec); evec.clear();
          } else if (m[VD].first == h){
            //   m[VD].second.push_back(root->data);
            //   int swapIndex = m[VD].second.size() - 1;
            //   for(int i = 0; i < m[VD].second.size() - 1; i++){
            //       if(m[VD].second[i] < root->data) swapIndex = i;
            //   }
            //   swap(m[VD].second[swapIndex], m[VD].second[m[VD].second.size() - 1]);
            m[VD].second.clear();
            m[VD].second.push_back(root->data);
          }
      }
      
      mapNodes(root->left, m, h + 1, VD - 1);
      mapNodes(root->right, m, h + 1, VD + 1);
  }
  
  void buildAns(vector <int> &ans, map <int, pair <int, vector <int>>> m){
      for(int i = minpos; i <= maxpos; i++){
          ans.push_back(m[i].second[0]);
      }
  }
  
  public:
    vector <int> bottomView(Node *root){
        vector <int> ans;
        if(root == NULL) return ans;
        
        maxpos = 0; minpos = 0;
        
        //   VD         h            datalist
        map <int, pair <int, vector <int>>> m;
        vector <int> evec; evec.push_back(root->data);
        m[0] = make_pair(1, evec); evec.clear();
        
        mapNodes(root->left, m, 2, -1);
        mapNodes(root->right, m, 2, 1);
        
        buildAns(ans, m);
        return ans;
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    string tc;
    getline(cin, tc);
    t=stoi(tc);
    while(t--)
    {
        string s ,ch;
        getline(cin, s);
        Node* root = buildTree(s);
        Solution ob;
        vector <int> res = ob.bottomView(root);
        for (int i : res) cout << i << " ";
        cout << endl;
    }
    return 0;
}



// } Driver Code Ends