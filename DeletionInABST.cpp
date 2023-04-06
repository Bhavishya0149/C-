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

Node * Root; Node * Node_Before_Element = NULL; Node * Node_Current_Element = NULL;

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

void FindNode(Node * Ptr, int DATA){
    // if (Ptr->Data == DATA && Ptr == Root){
    //     Node_Current_Element = Root; return;
    // }

    if (DATA == Ptr->Data){
        Node_Current_Element = Ptr; return;
    }

    if (Node_Current_Element == NULL){
        Node_Before_Element = Ptr;
    }
//  && Node_Current_Element == NULL && (Ptr->Left) != NULL
    if (DATA < (*Node_Before_Element).Data){
        cout<<"Went Left"<<endl; FindNode(Ptr->Left, DATA);
    }
//  && Node_Current_Element == NULL && (Ptr->Right) != NULL
    if (DATA > (*Node_Before_Element).Data){
        cout<<"Went right"<<endl; FindNode(Ptr->Right, DATA);
    }
    
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
    F->Left = NULL; F->Right = NULL;                                                                  /*         / \     \       */
    //                                                                                                /*        C   D     F      */
    A->Data = 4; B->Data = 2; C->Data = 1; D->Data = 3; E->Data = 6; F->Data = 7;                     //

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
            cout<<"Not a binary search tree!\nCant proceed further."<<endl; return 0;
        }
    }
    
    cout<<"The structure is a binary search tree.\n";
    int Char_To_Delete; cout<<"Enter the character you want deleted. "; cin.ignore(0); cin>>Char_To_Delete;

    int While_Check = 0; int Num_Search = 0;
    while (While_Check == 0){
        while (Num_Search < Size){
            if (Array[Num_Search] == Char_To_Delete){
                While_Check = 1;
            }
            Num_Search++;
        }
        if (While_Check == 0){
            cout<<"Element not found in BST."; return 0;
        }
    }
    
    FindNode(Root, Char_To_Delete);
    if (Node_Before_Element != NULL)
    {
        cout<<Node_Before_Element->Data<<"  1  "<<endl;
    }
    
    if (Node_Current_Element != NULL)
    {
        cout<<Node_Current_Element->Data<<"  2  "<<endl;
    }

    int KIllTime;
    cin>>KIllTime;
    return 0;
}