#include "double_linked_list.h"

ListNode *InitializeList(int init_data)
{
    ListNode *head = malloc(sizeof(ListNode));

    head->data = init_data;
    head->prev = NULL;          // Important to set it NULL, when not used
    head->next = NULL;          // Set to NULL
    return head;
}

void InsertAtHead(ListNode **linked_list, int data)
{

    ListNode *head = *linked_list;  // Dereference double pointer to single pointer first.
                                    // To make it easier to read 

    // Step 1:  Create new node first
    ListNode *new_node = malloc(sizeof(ListNode));
    new_node->data =  data;
    new_node->next =  head;        // Since we want to put new node in front head, 
                                   // we want to put next field of new_node to head pointer
    new_node->prev =  NULL;
 

    // Step 2:  Don't forget need to do something with head
    //          prev field of head, should now pointed to new_node
    head->prev = new_node;

    // Step 3:  Update step, 
    //          This step will update original linked_list 
    //          such that it will be pointed to new_node instead
    //          (Important in this step, to use linked_list instead of head, otherwise memory address won't be updated in caller side)
    *linked_list = new_node;

}

void InsertAtTail(ListNode *linked_list, int data)
{

    // Step 1 : Iterate linked_list until NULL is found on next field
    //          and store last node prior next is NULL inside curr_node_ptr
    ListNode *curr_node_ptr = linked_list;

    while(curr_node_ptr->next != NULL)
    {
        curr_node_ptr = curr_node_ptr->next;
    }


    // Step 2 : Allocate memory for new_node, and populate it 
    ListNode *new_node = malloc(sizeof(ListNode));
    new_node->data = data;
    new_node->next = NULL;              // I put next as NULL, because new_node is supposed to be a tail
    new_node->prev = curr_node_ptr;     // Remember that curr_node_ptr is last node prior tail before,


    // Step 3: Do something with curr_node_ptr
    curr_node_ptr->next =  new_node;
}


void InsertAfter(ListNode* node, int data)
{
    ListNode *new_node = malloc(sizeof(ListNode));

    new_node->data = data;    // Populate new node with data first.
    
    // Case # 1 : The node that is given by ListNode *node is tail node
    
    if (node->next == NULL)   // Detecting if it is tail-node
    {
        // Update node->next to point to new_node
        node->next = new_node;

        // Update new_node itself
        new_node->next = NULL;
        new_node->prev = node;

        return;   // Done for the day, we go home
    }

    // Case 2: This logic below will handle everything else that isn't fall under category Case #1
    
    ListNode *next_node = node->next;  // First we want to get next node that is pointed to by node
    
    // Step 1: We want to update new_node->next to point to next_node
    //         and point next_node->prev to new_node
    new_node->next = next_node;  
    next_node->prev=  new_node;

    // Step 2 : We want to do something with node 
    new_node->prev = node;
    node->next = new_node;
    
    // I guess we are done here,  go home 
    return;
}

void PrintFwdLinkedList(ListNode *head)
{

    int cnt = 0;
    while (head != NULL)
    {
        printf("%d", head->data);
        printf("-->");
        

        head  = head->next;
        cnt += 1;
    }

    printf("\n");
}



void PrintBckwdLinkedList(ListNode *head)
{
    // Find the tail node first

    ListNode *tail = head;

    while(tail->next != NULL)
    {
        tail = tail->next;
    }

    // Once tail is found, print out in reverse
    while (tail != NULL)
    {
        printf("%d", tail->data);
        printf("--->");
        tail = tail->prev;

    }

    printf("\n");
}


void CleanLinkedList(ListNode **linked_list)
{
    // First dereference **linked_list, into *head to make code easier to read 
    ListNode *head = *linked_list;
    ListNode *temp_ptr = NULL;

    while(head != NULL)   // We trust that node is NULL when it reaches termination
    {
        temp_ptr = head->next;
        free(head); 
        head = temp_ptr;
    }

    // Last step,  we want to set *linked_list = NULL, back to caller
    *linked_list = NULL;








}
