//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

struct Node
{
    int data;
    struct Node *left;
    struct Node *right;
};
Node* newNode(int val)
{
    Node* temp = new Node;
    temp->data = val;
    temp->left = NULL;
    temp->right = NULL;
    
    return temp;
}
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
int kthAncestor(Node *root, int k, int node);

int main()
{
    int t;
	scanf("%d ",&t);
    while(t--)
    {
        int k , node;
        scanf("%d ",&k);
        scanf("%d ",&node);
        string s;
		getline(cin,s);
		Node* root = buildTree(s);
		cout<<kthAncestor(root,k,node)<<endl;
    }
    return 0;
}

// } Driver Code Ends


//User function Template for C++
/*
Structure of the node of the binary tree is as
struct Node
{
	int data;
	struct Node *left, *right;
};
*/
// your task is to complete this function
void getAns(vector <int> &path, int &ans, int K){
    
    int count = 0;
    for(int i = 0; i < path.size(); i++){
        
        if(count == K){
            ans = path[i]; return;
        } count++;
    }
}

void saveAns(stack <Node *> &s, vector <int> &p){
    
    while(!s.empty()){
        Node * temp = s.top();
        p.push_back(temp->data); s.pop();
    }
    
}

void findNode(Node * root, int Key, stack <Node *> &s, vector <int> &path){
    if(root == NULL) return;
    
    if(root->data == Key){
        s.push(root); 
        
        saveAns(s, path);
        return;
    }
    
    s.push(root);
    findNode(root->left, Key, s, path);
    findNode(root->right, Key, s, path);
    
    if(!s.empty()){
        s.pop();    
    }
    return;
}

int kthAncestor(Node *root, int k, int node){
    if(root == NULL) return -1;
    
    int ans = -1;
    
    stack <Node *> s;
    vector <int> path;
    
    findNode(root, node, s, path);
    getAns(path, ans, k);
    
    return ans;
}
