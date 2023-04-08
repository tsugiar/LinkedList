#include "double_linked_list.h"

int main()
{
    ListNode *head = InitializeList(1);  // Initialize node and put number 1
    PrintFwdLinkedList(head);            // Print out result, expected output should be 1

    InsertAtHead(&head, 0);              // Modify content of head, such that the first element will be 0 instead of 1
    InsertAtHead(&head, -1);             // Modify content of head, such that the first element will be -1 instead of 0
    InsertAtHead(&head, -2);             // Modify content of head, such that the first element will be -2 instead of -1        
    PrintFwdLinkedList(head);            // Print out result, expected output should be -2 -> -1 -> 0 -> 1
    PrintBckwdLinkedList(head);          // Print out result in reverse, expected output should be 1 -> 0 -> -1 -> -2

    // Pick node at 3rd element of linked-list (data == 0) and insert data = 40
    ListNode *ThirdElementNode = head->next->next;
    InsertAfter(ThirdElementNode, 40); 
    PrintFwdLinkedList(head);            // Print out fwd, expected output -2 -> -1 -> 0 -> 40 -> 1 

    // Free up memory, make sure use address of head
    CleanLinkedList(&head);

    printf("Test");
}