#include <stdio.h>
#include <malloc.h>

struct ListNode_S
{
    int data;
    struct ListNode_S * next;
    struct ListNode_S * prev;
};

typedef struct ListNode_S ListNode;


// The function will receive initial data point for
// linked list and return head of linked list 
ListNode *InitializeList(int init_data);
  

// =================================================================================================
// Input arguments:
// ListNode **linked_list -->  Address of head linked list data structure 
//                    Note : we use ** instead *, because we need to modify head when function 
//                           return. So, from the caller, we use this statement below: 
//                           InsertAtHead(&head, data);
//
//  int data              -->  Get data where we want the new head looks like
//
//  Output --> void
//
// ========================================================================================
void InsertAtHead(ListNode **linked_list, int data);


// ==========================================================================================
// Similar InsertAtHead, except we want to insert at tail
// *linked_list --> head of linked_list,  
//                  (Note: I intentionally use * on linked_list instead of **, why ??
//  data        --> New node will be inserted at tail of linked_list.
//========================================================================================== 
void InsertAtTail(ListNode *linked_list, int data);



// =======================================================================================
//  We were given node from linked-list (node), and we are supposed to insert new node that 
//  place after node
// ==========================================================================================
void InsertAfter(ListNode* node, int data);


void CleanLinkedList(ListNode **head);

void PrintFwdLinkedList(ListNode *);
void PrintBckwdLinkedList(ListNode *);
