#include<iostream>
using namespace std;

class Node{
    public:
        int Data;
        Node * Next;
        Node * Prev;
};

Node * head, * tail; Node * NullPtr = NULL;

void AddFront(int DATA){
    Node * New_Element; New_Element = new Node();
    New_Element->Next = head;
    New_Element->Prev = NULL;
    New_Element->Data = DATA;
    New_Element->Next->Prev = New_Element;
    head = New_Element;
}

void AddBack(int DATA){
    Node * New_Element; New_Element = new Node();
    New_Element->Next = NULL;
    New_Element->Prev = tail;
    New_Element->Data = DATA;
    New_Element->Prev->Next = New_Element;
    tail = New_Element;
}

void AddMiddleFromFront(int DATA, int INDEX){
    Node * New_Element; New_Element = new Node();
    Node * Current_Pointer = head;

    for (int i = 0; i < INDEX - 1; i++)
    {
        Current_Pointer = Current_Pointer->Next;
    }
    
    New_Element->Data = DATA; 
    New_Element->Prev = Current_Pointer; 
    New_Element->Next = Current_Pointer->Next;
    Current_Pointer->Next->Prev = New_Element;
    Current_Pointer->Next = New_Element;
    // New_Element->Next->Prev = New_Element;
}

void AddMiddleFromBack(int DATA, int INDEX){
    Node * New_Element = new Node();
    Node * Current_Pointer = tail;

    for (int i = 0; i < INDEX - 1; i++)
    {
        Current_Pointer = Current_Pointer->Prev;
    }
    New_Element->Data = DATA;
    New_Element->Next = Current_Pointer;
    New_Element->Prev = Current_Pointer->Prev;
    Current_Pointer->Prev->Next = New_Element;
    Current_Pointer->Prev = New_Element;
}

void DeleteLast(void){
    Node * New_Pointer = tail->Prev;
    New_Pointer->Next = NULL;
    tail = New_Pointer;
}

void DeleteFront(void){
    Node * New_Pointer = head->Next;
    New_Pointer->Prev = NULL;
    head = New_Pointer;
}

void DeleteMiddleFromFront(int INDEX){
    Node * current_Pointer = head; Node * Temp;
    for (int i = 0; i < INDEX - 1; i++)
    {
        current_Pointer = current_Pointer->Next;
    }
    Temp = current_Pointer->Next->Next;
    current_Pointer->Next = Temp;
    current_Pointer->Next->Prev = current_Pointer;
}

void DeleteMiddleFromBack(int INDEX){
    Node * Current_Pointer = tail; Node * Temp;
    for (int i = 0; i < INDEX - 1; i++)
    {
        Current_Pointer = Current_Pointer->Prev;
    }
    Temp = Current_Pointer->Prev->Prev;
    Current_Pointer->Prev = Temp;
    Current_Pointer->Prev->Next = Current_Pointer;
}

void ReadFront(void){
    Node * Current_Pointer = head;
    while (Current_Pointer != NULL)
    {
        cout<<Current_Pointer->Data<<" ";
        Current_Pointer = Current_Pointer->Next;
    }
}

void ReadLast(void){
    Node * Current_Pointer = tail;
    while (Current_Pointer != NULL)
    {
        cout<<Current_Pointer->Data<<" ";
        Current_Pointer = Current_Pointer->Prev;
    }
}

void ReverseList(Node * Ptr, Node * PrevPtr){
    if (Ptr->Next == NULL){
        Ptr->Prev = NULL;
        Ptr->Next = PrevPtr; head = Ptr; 
        return;
    }
    // cout<<"HELLO\n";
    if (Ptr == head){
        tail = Ptr;
    }
    // cout<<"HELLO\n";
    Ptr->Prev = Ptr->Next;
    Ptr->Next = PrevPtr;
    PrevPtr = Ptr;
    ReverseList(PrevPtr->Prev, PrevPtr);
}


int main()
{
    Node * A, * B, * C; A = new Node(); B = new Node(); C = new Node();
    A->Data = 4; B->Data = 6; C->Data = 7;
    A->Next = B; B->Next = C; C->Next = NULL;
    A->Prev = NULL; B->Prev = A; C->Prev = B;
    head = A; tail = C;

    cout<<"1.  Read from front. \n";
    cout<<"2.  Read from back. \n";
    cout<<"3.  Add from front. \n";
    cout<<"4.  Add from back. \n";
    cout<<"5.  Add middle from front. \n";
    cout<<"6.  Add middle from back. \n";
    cout<<"7.  Delete from front. \n";
    cout<<"8.  Delete from back. \n";
    cout<<"9.  Delete middle from front. \n";
    cout<<"10. Delete middle from back. \n";
    cout<<"11. Reverse list. \n";
    cout<<"12. Reverse list in pairs. \n";
    cout<<"13. Exit. \n";


    int Input; cout<<"ENTER FIRST INPUT : "; Input = 0; int Cnum; int Pos;

    while (Input != 13){
        cin>>Input;
        switch (Input){
        
        case 1:
            ReadFront();
            cout<<"\nReady to take another input : ";
            break;
        case 2:
            ReadLast();
            cout<<"\nReady to take another input : ";
            break;
        case 3:
            cout<<"What element would you like to add? : "; cin>>Cnum;
            AddFront(Cnum); cout<<"Number added.\n";
            cout<<"\nReady to take another input : ";
            break;
        case 4:
            cout<<"What element would you like to add? : "; cin>>Cnum;
            AddBack(Cnum); cout<<"Number added.\n";
            cout<<"\nReady to take another input : ";
            break;
        case 5:
            cout<<"What element would you like to add? : "; cin>>Cnum;
            cout<<"What psoition from front would you like to add to? : "; cin>>Pos;
            AddMiddleFromFront(Cnum, Pos); cout<<"Number added.\n";
            cout<<"\nReady to take another input : ";
            break;
        case 6:
            cout<<"What element would you like to add? : "; cin>>Cnum;
            cout<<"What psoition from front would you like to add to? : "; cin>>Pos;
            AddMiddleFromBack(Cnum, Pos); cout<<"Number added.\n";
            cout<<"\nReady to take another input : ";
            break;
        case 7:
            DeleteFront(); cout<<"Element deleted.\n";
            cout<<"\nReady to take another input : ";
            break;
        case 8:
            DeleteLast(); cout<<"Element deleted.\n";
            cout<<"\nReady to take another input : ";
            break;
        case 9:
            cout<<"What psoition from front would you like to delete from? : "; cin>>Pos;
            DeleteMiddleFromFront(Pos); cout<<"Number added.\n";
            cout<<"\nReady to take another input : ";
            break;
        case 10:
            cout<<"What psoition from back would you like to delete from? : "; cin>>Pos;
            DeleteMiddleFromBack(Pos); cout<<"Number added.\n";
            cout<<"\nReady to take another input : ";
            break;
        case 11:
            ReverseList(head, NullPtr);
            cout<<"List reversed. \n"; cout<<"\nReady to take another input : ";
            break;
        case 12:
            cout<<"ENter the length of pairs : "; int Pairs; cin>>Pairs;
            // ReverseListPairs(head, Pairs);
            cout<<"List reversed. \n"; cout<<"\nReady to take another input : ";
            break;
        default:
            cout<<"Wrong input  . . "; cout<<"\nReady to take another input : ";
            break;
        }
    }
    return 0;
}