#include<iostream>
#include<list>
using namespace std;

list <int> Elements;

class Node{
    public:
        int Data;
        Node * Left;
        Node * Right;
};

Node * Root;

void Traverse(Node * Ptr){
    
    if (Ptr->Left != NULL){
        Traverse(Ptr->Left);
    }
    Ptr->Left = NULL;
    
    cout<<Ptr->Data; Elements.push_back(Ptr->Data);
    
    if (Ptr->Right!= NULL){
        Traverse(Ptr->Right);
    }
    
    if (Ptr == Root){
        return;
    }
    
    Ptr->Right = NULL;
    return;
}

int main()
{
    Node * A, * B, * C, * D, * E, * F;                                                                
    A = new Node(); B = new Node(); C = new Node(); D = new Node(); E = new Node(); F = new Node();   //      BINARY TREE DRAWN
    A->Left = B; A->Right = E;                                                                        //  
    B->Left = C; B->Right = D;                                                                        //             A
    C->Left = NULL; C->Right = NULL; D->Left = NULL; D->Right = NULL;                                 /*           /   \         */
    E->Left = NULL; E->Right = F;                                                                     /*          B     E        */
    F->Left = NULL; F->Right = NULL;                                                                  /*         /  \    \       */
    //                                                                                                /*        C    D    F      */
    A->Data = 4; B->Data = 2; C->Data = 1; D->Data = 3; E->Data = 5; F->Data = 6;                     //

    Root = A;
    // cout<<Root->Data<<endl;
    // cout<<A->Data;
    Traverse(Root); cout<<endl;
    int Size = Elements.size();
    int Array[Size];

    list<int> :: iterator iter;
    int Var1 = 0; int Current_Element;
    for (iter = Elements.begin(); iter != Elements.end(); iter++){
        cout<<*iter<<endl; Current_Element = *iter; 
        Array[Var1] = Current_Element; Var1++;
    }

    for (int i = 0; i < Size - 1; i++){
        if (Array[i] >= Array[i + 1]){
            cout<<"Not a binary search tree!"<<endl; return 0;
        }
    }
    
    cout<<"The structure is a binary search tree.";
    return 0;
}