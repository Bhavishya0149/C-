//{ Driver Code Starts
// driver

// #include <bits/stdc++.h>
#include<iostream>
#include<vector>
using namespace std;

/* Linked list Node */
struct Node {
    int data;
    struct Node* next;
    Node(int x) {
        data = x;
        next = NULL;
    }
};

struct Node* buildList(int size)
{
    int val;
    cin>> val;
    
    Node* head = new Node(val);
    Node* tail = head;
    
    for(int i=0; i<size-1; i++)
    {
        cin>> val;
        tail->next = new Node(val);
        tail = tail->next;
    }
    
    return head;
}

void printList(Node* n)
{
    while(n != NULL)
    {
        cout<< n->data << " ";
        n = n->next;
    }
    cout<< endl;
}


// } Driver Code Ends
/* node for linked list:

struct Node {
    int data;
    struct Node* next;
    Node(int x) {
        data = x;
        next = NULL;
    }
};

*/

class Solution
{
    public:
    //Function to add two numbers represented by linked list.
    struct Node* addTwoLists(struct Node* first, struct Node* second){
        vector <int> v1;
        vector <int> v2;
        vector <int> v3;
        
        struct Node * curr = first;
        while(curr != NULL){
            v1.push_back(curr->data);
            curr = curr->next;
        }
        
        curr = second;
        while(curr != NULL){
            v2.push_back(curr->data);
            curr = curr->next;
        }
        
        int i = v1.size() - 1; int j = v2.size() - 1; int carry = 0; int res;
        
        while(i >= 0 && j >= 0){
            res = v1[i] + v2[j] + carry;
            if(res >= 10){
                carry = res / 10;
                res = res % 10;
            } else {
                carry = 0;
            }
            v3.push_back(res);
            i--; j--;
        }
        
        while(i >= 0){
            int res = v1[i] + carry;
            if(res >= 10){
                carry = res / 10;
                res = res % 10;
            } else {
                carry = 0;
            }
            
            v3.push_back(res);
            i--;
        }
        
        while(j >= 0){
            int res = v2[j] + carry;
            if(res >= 10){
                carry = res / 10;
                res = res % 10;
            } else {
                carry = 0;
            }
            v3.push_back(res);
            j--;
        }
        
        if(carry > 0){
            v3.push_back(carry);
        }
        
        i = v3.size() - 1;
        
        struct Node * head;
        struct Node * temp;
        
        if(v3.size() > 0){
            head = new Node(v3[i]);
            i--; temp = head;
        }
        
        if(v3.size() == 1){
            head->next = NULL;
            return head;
        }
        
        for(int i = v3.size() - 2; i >=  0; i--){
            temp->next = new Node(v3[i]);
            temp = temp->next;
        }
        
        temp->next = NULL;
        return head;
    }
};


//{ Driver Code Starts.

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n, m;
        
        cin>>n;
        Node* first = buildList(n);
        
        cin>>m;
        Node* second = buildList(m);
        Solution ob;
        Node* res = ob.addTwoLists(first,second);
        printList(res);
    }
    return 0;
}

// } Driver Code Ends