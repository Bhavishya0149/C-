#include<iostream>
using namespace std;

class Node{
    public:
        int Data;
        Node * Left;
        Node * Right;
};

// Node * Root;

Node * buildTree(void){
    // cout<<"Enter data for node : ";
    int data; cin>>data;
    
    if (data == -1)
        return NULL;

    Node * head = new Node();
    head->Data = data;


    cout<<"Enter data for "<<data<<"' left node : ";
    head->Left = buildTree();
    
    cout<<"Enter data for "<<data<<"' right node : ";
    head->Right = buildTree();

    return head;
}



void Traverse(Node * Ptr){
    if (Ptr == NULL)
        return;
    
    cout<<Ptr->Data<<" ";

    Traverse(Ptr->Left);
    Traverse(Ptr->Right);
    return;
}

int main()
{
    // Node * A, * B, * C, * D, * E, * F;                                                                
    // A = new Node(); B = new Node(); C = new Node(); D = new Node(); E = new Node(); F = new Node();   //      BINARY TREE DRAWN
    // A->Left = B; A->Right = E;                                                                        //  
    // B->Left = C; B->Right = D;                                                                        //             A
    // C->Left = NULL; C->Right = NULL; D->Left = NULL; D->Right = NULL;                                 /*           /   \         */
    // E->Left = NULL; E->Right = F;                                                                     /*          B     E        */
    // F->Left = NULL; F->Right = NULL;                                                                  /*         /  \    \       */
    // //                                                                                                /*        C    D    F      */
    // A->Data = 1; B->Data = 2; C->Data = 3; D->Data = 4; E->Data = 5; F->Data = 6;                     //

    // Root = A;
    // cout<<Root->Data<<endl;
    // cout<<A->Data;

    cout<<"Enter data for root Node : ";   
    Node * root = buildTree();
    
    Traverse(root);



    return 0;
}