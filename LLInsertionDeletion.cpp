#include<iostream>
using namespace std;

class Node{
    public:
        int Data;
        Node * Next;
};

Node * head;

void InsertFront(int D, Node * Ptr = head){
	Node * NewEleF;
	Node * Temp;

	NewEleF = new Node();
	
	NewEleF->Data = D; NewEleF->Next = Ptr;

	Temp = head; head = NewEleF; NewEleF = Temp;
}


void InsertMiddle(int DATA, int INDEX){
    Node * Current_Pointer, * New_Element; 
    New_Element = new Node(); Current_Pointer = head;

    New_Element->Data = DATA;

    for (int i = 0; i < INDEX - 1; i++)
    {
        Current_Pointer = Current_Pointer->Next;
    }
    New_Element->Next = Current_Pointer->Next;
    Current_Pointer->Next = New_Element;
}

void InsertLast(int DATA, Node * CPtr = head){
    Node * Current_Pointer = head, * NewPtr;
    NewPtr = new Node();
    // cout<<"RUNIING FUNC\n";
    while (Current_Pointer->Next != NULL)
    {
        Current_Pointer = Current_Pointer->Next;
    }
    // cout<<Current_Pointer->Data;
    NewPtr->Data = DATA; NewPtr->Next = NULL;
    Current_Pointer->Next = NewPtr;
}

void DeleteFirst(Node * Ptr = head){
    Node * New_First_Ele = head->Next;
    head = New_First_Ele;
}

void DeleteLast(Node * Ptr = head){
    Node * Current_Pointer = head;
    while (Current_Pointer->Next->Next != NULL)
    {
        Current_Pointer = Current_Pointer->Next;
    }
    Current_Pointer->Next = NULL;
}

void RemoveMiddle(int INDEX, Node * Ptr = head){
    Node * Current_Pointer = head; Node * Next_Pointer; Node * Temp;
    for (int i = 0; i < INDEX - 1; i++)
    {
        Current_Pointer = Current_Pointer->Next;
    }
    // cout<<Current_Pointer->Data<<endl;
    Current_Pointer->Next = Current_Pointer->Next->Next;
}

void Printlist(Node * Pointer){
    while (Pointer != NULL)
    {
        cout<<Pointer->Data<<" ";
        Pointer = Pointer->Next;
    }
};



int main()
{
    Node * Final;
    Final = new Node();
    Final->Data = 9;
    Final->Next = NULL;
    head = Final;

    int A, B, C, D, E, F; 
    A = 7; B = 6; C = 3; D = 10; E = 69; F = 4;

    InsertFront(A);
    InsertFront(B);
    InsertFront(C);
    // head = InsertFront(D);
    // InsertMiddle(2, D);
    InsertLast(D);
    InsertLast(E);
    InsertMiddle(F, 2);
    // Printlist(head);
    // DeleteFirst();
    // cout<<endl;
    // Printlist(head);
    cout<<endl;
    // DeleteFirst();
    // DeleteLast();
    // DeleteLast();
    // RemoveMiddle(2);
    // RemoveMiddle(2);
    Printlist(head);

    return 0;
}