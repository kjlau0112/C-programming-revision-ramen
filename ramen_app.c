#include <stdio.h>
#include <unistd.h>  
#include <stdlib.h>
#include <time.h>
#include <string.h>

struct node
{
    char data;
    struct node* nextPtr;
};

typedef struct
{
    int *values;
    int head, tail,number_entries,size;
}queue;

// student structure
struct student 
{
    char id[15];
    char firstname[64];
    char lastname[64];
    float points;
};


struct master_student 
{
    struct student  *student_ptr;
    char major[15];
};

void init_que(queue *q, int max_size)
{
    q->size = max_size;
    q->values = malloc(sizeof(int)*q->size);
    q->number_entries = 0;
    q->head = 0 ;
    q->tail = 0;
}


void deleteParticularChar(struct node **head_ref, char targetChar)
{
 // Store head node
    struct node *temp = *head_ref, *prev;
 
    // If head node itself holds the key to be deleted
    if (temp != NULL && temp->data == targetChar) {
        *head_ref = temp->nextPtr; // Changed head
        free(temp); // free old head
        return;
    }
 
    // Search for the key to be deleted, keep track of the
    // previous node as we need to change 'prev->next'
    while (temp != NULL && temp->data != targetChar) {
        prev = temp;
        temp = temp->nextPtr;
    }
 
    // If key was not present in linked list
    if (temp == NULL)
        return;
    
    if(temp->data == targetChar)
    {
            // Unlink the node from linked list
        prev->nextPtr = temp->nextPtr;
 
        free(temp); // Free memory
    }
}

void deleteEntireLinkList(struct node** head_ref)
{
   /* deref head_ref to get the real head */
   struct node* current = *head_ref;
   struct node* next;
 
   while (current != NULL)
   {
       next = current->nextPtr;
       free(current);
       current = next;
   }
   
   /* deref head_ref to affect the real head back
      in the caller. */
   *head_ref = NULL;
}

void initializeNode (struct node ** head, char val)
{
    struct node*  initial_node = malloc(sizeof(struct node));
    initial_node -> data = val;
    initial_node -> nextPtr = NULL;
    *head = initial_node; 
}

void insertAtBegining (struct node ** head, char val)
{
    struct node*  initial_node = malloc(sizeof(struct node));
    initial_node -> data = val;
    initial_node -> nextPtr = *head;
    *head = initial_node; 
}

void insertAtEnd(struct node ** head, char val)
{
    struct node * current = *head;
    if(current!= NULL)
    {
        while (current->nextPtr != NULL)
        {
            current= current ->nextPtr;
        }
        current->nextPtr = malloc (sizeof(struct node));
        current->nextPtr->data = val;
        current->nextPtr->nextPtr = NULL;
    }
    else 
    {
        current = malloc (sizeof(struct node));
        current -> data = val;
        current ->nextPtr = NULL;
    }
}

void printfList(struct node* currentPtr)
{
    while(currentPtr != NULL)
    {
        printf("the head -> data is  %c\n", currentPtr-> data);
        currentPtr = currentPtr->nextPtr;
    }
}

void link_list_demo()
{
    struct node* head = NULL;  // be aware that this is pointer

    initializeNode(&head, 'C');

    insertAtBegining(&head, 'A');

    insertAtBegining(&head, 'D');

    insertAtEnd(&head, 'L');

    insertAtEnd(&head, 'O');

    insertAtEnd(&head, 'L');

    deleteParticularChar(&head,'L');
    
    printfList(head);
}

int queu_empty(queue *q)
{
    return (q->number_entries == 0);
}

int queu_full(queue *q)
{
    return (q->number_entries == q->size) && (q->number_entries == 0);
}

void queue_destroy(queue *q)
{
    free(q->values);
}

int enqueue(queue* q, int value)
{
    if(queu_full(q))
    {
        return -1;
    }
    q->values[q->tail] = value;
    q->number_entries++;
    q->tail =q->tail +1;
    
    if(q->tail >= q->size)
    {
        q->tail = 0;
    }
    // alternatively
    // q->tail = (q->tail +1) % q->size; 

    return 1;
}

int dequeue(queue *q)
{
    int result = 0;

    if(queu_empty(q))
    {
        return 0;
    }
    
    result =  q->values[q->head];

    q->head =q->head +1;
    
    // alternatively
    // q->head = (q->head +1) % q->size; 

    if(q->head >= q->size)
    {
        q->head = 0;
    }

    q->number_entries--;

    return result;
}

void circular_que_demo()
{
    queue obj;
    int number = 0;
    init_que(&obj,5);

    enqueue(&obj, 1);
    enqueue(&obj, 2);
    enqueue(&obj, 3);
    enqueue(&obj, 4);
    enqueue(&obj, 5);
    enqueue(&obj, 6);


    while((number = dequeue(&obj)) != 0)
    {
        printf("enque number is %d\n", number);

    }

}

void  demo_array()
{
    int array[5] = {1,2,3,4,5};
  
   // address  of first index of the array
   // address  of  the whole array of 5 int start with index 1
   // both the same in this case.
   printf("array=%p : &array=%p\n", array, &array);  
  
   //array+1 mean first array address = address +4
   //&array mean whole  array address + (5*4 =20) = 0x14
   printf("array+1 = %p : &array + 1 = %p \n", array+1, &array+1); 

   printf("*(&array + 1) %p\n", *(&array + 1));
    
    printf("diff %ld\n", *(&array + 1) -array);
}

void process_data_Structure()
{
    // student structure variable
    struct student std[2];
    struct student *ptr = NULL;
    strcpy(std[0].id,"5523224");
    strcpy(std[0].firstname,"william");
    strcpy(std[0].lastname,"jackson");
    std[0].points = 1525.23;

    strcpy(std[1].id,"123456");
    strcpy(std[1].firstname,"Donald");
    strcpy(std[1].lastname,"Trumph");
    std[2].points = 552.23;

    ptr = std;

    printf("ptr ->id %s\n",ptr->id);
    printf("ptr ->id %s\n",ptr->firstname);
    printf("ptr ->id %s\n",ptr->lastname);

    ptr++;

    printf("ptr ->id %s\n",ptr->id);
    printf("ptr ->id %s\n",ptr->firstname);
    printf("ptr ->id %s\n",ptr->lastname);

    struct master_student *MasterInfo = (struct master_student *) malloc(sizeof(struct master_student *));
    MasterInfo->student_ptr = (struct student*) malloc(sizeof(struct student *));
    strcpy(MasterInfo->student_ptr->firstname,"Joe");
    strcpy(MasterInfo->student_ptr->lastname,"Biden");
    strcpy(MasterInfo->student_ptr->id,"46");
    strcpy(MasterInfo->major,"Physics");

    printf("MasterInfo->student_ptr->firstname %s\n",MasterInfo->student_ptr->firstname);
    printf("MasterInfo->student_ptr->lastname %s\n",MasterInfo->student_ptr->lastname);
    printf("MasterInfo->student_ptr->id %s\n",MasterInfo->student_ptr->id);
    printf("MasterInfo->major %s\n",MasterInfo->major );
    
    free(MasterInfo->student_ptr);
    free(MasterInfo);
}

int *setValueDynamically()
{
    int *ptr =(int*)malloc(sizeof(int*));
    *ptr = random()%100;
    return ptr;
}
void pointerGetvaluefromReturn()
{
    int *p = NULL;
    p = setValueDynamically();
    printf("p value is %d\n", *p);
    free(p);
}

void pointer2PointerDemo()
{
    int **ipp = NULL;
    int i = 5, j = 6, k = 7;
	int *ip1 = &i, *ip2 = &j;
    int value =0;
    printf("NOTE &var is getting address of the variables.\nif the variable is *ptr, printing ptr may yield address of the variable  it poiting to via ptr=&variable\n");
    printf("We usually confused when a pointer is with '&' or without '&' operator,refer INfO 2 to recall\n");
    printf("--------------------------------------\n");
    printf("INFO 1\n");
    printf("i,j,k is just constant variable\n");
    printf("adress of  i is %p\n",&i);
    printf("adress of  j is %p\n",&j);
    printf("adress of  k is %p\n",&k);
    printf("--------------------------------------\n");
    printf("INFO 2\n");
    printf("adress of pointer &ip1 is %p\n",&ip1);
    printf("adress of pointer &ip2 is %p\n",&ip2);
    printf("adress of pointer &ipp is %p\n",&ipp);
    printf("--------------------------------------\n");
    printf("INFO 3\n");
    printf("*ip1 = &i:");
    printf("adress of  ip1 is %p\n",ip1);
    printf("*ip2 = &j:");
    printf("adress of  ip2 is %p\n",ip2);
     printf("ipp is not doing anything yet:");
    printf("adress of  ipp is %p\n",ipp);
    printf("--------------------------------------\n");
    printf("INFO 4\n");
    ipp = &ip1;
    printf("Now ipp = &ip1:");
    printf("&ipp is still equal %p\n",&ipp);
    printf("This is just to demonstrate regardless how ipp pointing, it address won't change, what change is address it pointing to\n");
    printf("--------------------------------------\n");
    printf("INFO 5\n");
    printf("*ipp is equal to print ip1 value -> %p\n",*ipp);
    printf("ipp is equal to print &ip1 is %p\n",ipp);
    printf("**ipp is %d\n", **ipp);
}

void b_changePointerValuewithPtr2Ptr(int ** ptr)
{
    int *local = (int*)malloc(sizeof(int*));
    *local = random()%20;
    printf("locla function value is %d\n", *local);
    *ptr = &(*local);
    // free(local); if you free withhin this function will result 0 in outside.
}

void changePointerValueViaDoublePtrFunctionPara()
{
    int * p = NULL;
    b_changePointerValuewithPtr2Ptr(&p);
    printf("updated value is %d\n", *p);
    free(p);
}

void a_changePointerValue(int * value)
{
    *value = rand()% 10;
}

void changePointerValueviaFunctionpara()
{
    int * p = NULL;
    p = (int*)malloc(sizeof(int*));
    *p =150;
    printf("dereference value p is %d\n", *p);
    a_changePointerValue(p);
    printf("updated dereference value p is %d\n", *p);
    if(p != NULL)
    {
        printf("free dynamic alloccated memory\n");
        free(p);
    }
}

int main(int argc, char *argv[])
{
    int opt = 0;
    srand(time(NULL)); 

    while((opt = getopt(argc, argv,"abcdefgh")) != -1)
    {
        switch(opt)
        {
            case'a':
                changePointerValueviaFunctionpara();
            break;

            case'b':
                changePointerValueViaDoublePtrFunctionPara();
            break;

            case'c':
                pointer2PointerDemo();
            break;
 
            case'd':
                pointerGetvaluefromReturn();
            break;
                        
            case'e':
                process_data_Structure();
            break;
            
            case'f':
                demo_array();
            break;

            case'g':
                circular_que_demo();
            break;

            case'h':
                link_list_demo();
            break;

            default :
                printf("unable to parse cli\n");
            break;
        }
    }  

    return 0;
}
