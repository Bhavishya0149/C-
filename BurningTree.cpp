//{ Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

struct Node {
    int data;
    Node *left;
    Node *right;

    Node(int val) {
        data = val;
        left = right = NULL;
    }
};


Node *buildTree(string str) {
    // Corner Case
    if (str.length() == 0 || str[0] == 'N')
        return NULL;

    // Creating vector of strings from input
    // string after spliting by space
    vector<string> ip;

    istringstream iss(str);
    for (string str; iss >> str;)
        ip.push_back(str);

    // Create the root of the tree
    Node *root = new Node(stoi(ip[0]));

    // Push the root to the queue
    queue<Node *> queue;
    queue.push(root);

    // Starting from the second element
    int i = 1;
    while (!queue.empty() && i < ip.size()) {

        // Get and remove the front of the queue
        Node *currNode = queue.front();
        queue.pop();

        // Get the current Node's value from the string
        string currVal = ip[i];

        // If the left child is not null
        if (currVal != "N") {

            // Create the left child for the current Node
            currNode->left = new Node(stoi(currVal));

            // Push it to the queue
            queue.push(currNode->left);
        }

        // For the right child
        i++;
        if (i >= ip.size())
            break;
        currVal = ip[i];

        // If the right child is not null
        if (currVal != "N") {

            // Create the right child for the current Node
            currNode->right = new Node(stoi(currVal));

            // Push it to the queue
            queue.push(currNode->right);
        }
        i++;
    }

    return root;
}


// } Driver Code Ends
//User function Template for C++
class Solution {
    int minT, maxD, tempD;
    stack <Node *> s;
    vector <Node *> path;
    
    void findPath(Node * root, int target){
        if(root == NULL) return;
        
        if(root->data == target){
            s.push(root);
            while(!s.empty()){
                path.push_back(s.top());
                s.pop();
            }
            return;
        }
        
        s.push(root);
        findPath(root->left, target);
        findPath(root->right, target);
        
        if(!s.empty()){
            s.pop();
        }
    }
  
    void findMaxD(Node * root, int count){
        if(root == NULL){
            if(count + tempD > maxD){
                maxD = count + tempD; 
            }
            return;
        }
        
        count++;
        
        findMaxD(root->left, count);
        findMaxD(root->right, count);
    }
  
    
    void getD(void){
        maxD = 0;
        
        for(int i = path.size() - 1; i > 0; i--){
    
            tempD = i;
            
            if(path[i]->left == path[i - 1]){
                findMaxD(path[i]->right, 0);
            } else {
                findMaxD(path[i]->left, 0);
            }
        }
        
        tempD = 0;
        findMaxD(path[0]->left, 0);
        findMaxD(path[0]->right, 0);
    }
  
  public:
    int minTime(Node* root, int target){
        minT = 0;
        if(root == NULL) return minT; 
        
        findPath(root, target); // Finding path of target . . . 
        
        getD();
        return maxD;
    }
};

//{ Driver Code Starts.

int main() 
{
    int tc;
    scanf("%d ", &tc);
    while (tc--) 
    {    
        string treeString;
        getline(cin, treeString);
        // cout<<treeString<<"\n";
        int target;
        cin>>target;
        // cout<<target<<"\n";

        Node *root = buildTree(treeString);
        Solution obj;
        cout<<obj.minTime(root, target)<<"\n"; 

        cin.ignore();

    }


    return 0;
}

// } Driver Code Ends