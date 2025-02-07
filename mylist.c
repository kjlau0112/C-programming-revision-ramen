#include <stdio.h>
#include <unistd.h>  
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include <stdint.h>
#include <stdbool.h> 
#include <inttypes.h>


typedef struct node
{
    int data;
    struct node* nextPtr;
}myNode;

void display(struct node * var)
{
    struct node *temp=var;
    int number =0;
    if(temp==NULL)
    {
        printf("\nLinked list is empty.");
        return;
    }
    while(temp->nextPtr !=NULL)
    {
        printf("%d -> ",temp->data);
        temp=temp->nextPtr;
        number++;
    }
    printf("%d",temp->data);
}


// Function to delete the head node
myNode* deleteNode(myNode* head)
{
    // Base case if linked list is empty
    if (head == NULL)
        return NULL;

    // Store the current head in a temporary variable
    myNode* temp = head;

    // Move the head to the next node
    head = head->nextPtr;
        
    // Free the memory of the old head node
    free(temp);

    // Return the new head
    return head;
}
 
//function to delete targetted node
 myNode* deleteTargetedNode(myNode* head, int expectValue)
{
    // Base case: empty list
    if (head == NULL)
        return NULL;

    // Case 1: If the head itself is the node to be deleted
    if (head->data == expectValue)
    {
        myNode* newHead = head->nextPtr; // Store new head
        free(head);                      // Delete old head
        return newHead;                   // Return new head
    }

    // Case 2: Traverse the list to find the node to delete
    myNode* prev = head;
    while (prev->nextPtr != NULL && prev->nextPtr->data != expectValue)
    {
        prev = prev->nextPtr;
    }

    // If we reach the end without finding the value
    if (prev->nextPtr == NULL)
        return head;

    // Unlink and delete the node
    
    myNode* toDelete = prev->nextPtr;
    //toDelete->data = expectValue
    //said a list 20, 200 , 120 and 200 expected to be deleted
    //toDelete Node is having data of 200, toDelete->nextPtr is actually pointing 120
    prev->nextPtr = toDelete->nextPtr;
    free(toDelete);

    return head;
}
 
myNode * createNode(int value)
{
    myNode *Node = (struct node*)malloc(sizeof(myNode));
    
    Node -> data =value;
    Node -> nextPtr= NULL;

    return Node;
}

int main(int argc, char *argv[])
{
    myNode* head= NULL;

    myNode * kjNode = createNode(20);

    myNode* kjNode2 = createNode(120);
    kjNode->nextPtr =kjNode2;

    myNode * kjNewNode = createNode(200);

    kjNode->nextPtr = kjNewNode;
    kjNewNode->nextPtr = kjNode2;
    
    
    head= kjNode;

    head= deleteHead(head, 200);


    display(head);

}