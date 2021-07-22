#include <stdio.h>
#include <unistd.h>  
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include <stdint.h>
#include <stdbool.h> 
#include <inttypes.h>

enum week
{
    monday,
    tuesday,
    wednesday
}week_obj;

struct test_Struct_style_2
{
    int a;
    int b;
};

struct test_Struct_style_1
{
    int x:1;
    int y:2;
};

struct node
{
    int data;
    struct node* nextPtr;
};

typedef struct
{
    int *values;
    int head, tail,number_entries,size,counter;
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

typedef struct {
    uint8_t * const buffer;
    int head;
    int tail;
    const int maxlen;
} circ_bbuf_t;

int x;

void double_pointer_again()
{
    int **ptr;
    int value = 150;
    ptr = (int**)malloc(sizeof(int*));
    *ptr = &value;
    printf("%d\n",**ptr);
}

void array_again()
{
    int arr[5] ={}; 
    int i ;
    for(i=0; i<5; i++)
    {
        if(i ==3)
        {
            arr[i] =150;
        }
    }
    
    printf("%d\n", arr[1]);

    char my_string_arr[10] = "";
    my_string_arr[0]= 'L';
    printf("%c\n",my_string_arr[0]);
    
    char * mystring = "hello wolrd";
    //mystring[2]='b'; <----segmentation fault
    printf("%c\n",mystring[1]);


}

int link_list_node_counter(struct node * var)
{
    struct node *temp=var;
    int count =0;
    if(temp==NULL)
    {
        printf("\nLinked list is empty.");
        return count;
    }
    while(temp->nextPtr !=NULL)
    {
        count++;
        temp=temp->nextPtr;   
    }

    return count;
}

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

void my_link_list()
{
    int option;
    struct node* head  = NULL;
    struct node* head2 = NULL;
    struct node* head3 = NULL;
    struct node* head4 = NULL;
    struct node* temp  = NULL;
    struct node* temp2 = NULL;
    struct node* temp3 = NULL;
    struct node* temp4 = NULL;
    int count = 0;
    int position = (3+1)/2;

    
    printf("Insertion : \n1. Beginning  2. Middle   3. Ending   4. display  5. Exit");
    while(1)
    {
        printf("\nEnter your option : ");
        scanf("%d",&option);
        switch(option)
        {
            case 1:
                head = (struct node*)malloc(sizeof(struct node));
                head->data= 5;
                head->nextPtr =NULL;
            
                struct node * newNode = (struct node*)malloc(sizeof(struct node));
                newNode->data =10;
                newNode->nextPtr = head;
            
                head = newNode;
           
                struct node * anotherNewNode =(struct node*)malloc(sizeof(struct node));
            
                anotherNewNode->data =100;
                anotherNewNode-> nextPtr = newNode;
            
                head = anotherNewNode;
                display(head);
                
                printf("\n");
                printf("Deleteting head node\n");
                temp = head;
                head = head->nextPtr;
                free(temp);
                display(head);
            break;
            
            case 2 :    
                //Ins_middle();
                head3 = (struct node*)malloc(sizeof(struct node));
                head3->data= 5;
                head3->nextPtr =NULL;
            
                struct node * newNode3 = (struct node*)malloc(sizeof(struct node));
                newNode3->data =10;
                newNode3->nextPtr = NULL;
            
                head3->nextPtr = newNode3;
            
                struct node * anotherNewNode3 =(struct node*)malloc(sizeof(struct node));
            
                anotherNewNode3->data =100;
                anotherNewNode3-> nextPtr = NULL;
                
                newNode3-> nextPtr =anotherNewNode3;
                
                struct node * anotherNewNode4 =(struct node*)malloc(sizeof(struct node));
                anotherNewNode4->data=20;
                anotherNewNode4->nextPtr =NULL;

                anotherNewNode3 ->nextPtr=anotherNewNode4;
                display(head3);
                printf("\nnumber of link list is %d\n",link_list_node_counter(head3)); 

                printf("\n");
                printf("inserting new node 250\n");
                struct node * anotherNewNode5 =(struct node*)malloc(sizeof(struct node));

                anotherNewNode5->data =250;
                anotherNewNode5 ->nextPtr = NULL; 

                temp3 = head3;

                // printf("\n");
                // display(temp3); // Output: 5 -> 10 -> 100 -> 20
 
                // temp3 =temp3->nextPtr; //move to next node.
                // printf("\n");
                // display(temp3);// Output: 10 -> 100 -> 20

                // temp3 =temp3->nextPtr; // move to next node
                // printf("\n");
                // display(temp3);//Output: 100 -> 20

                // anotherNewNode5->nextPtr =temp3->nextPtr; // temp3->nextPtr point to 20
                // display(anotherNewNode5->nextPtr);
                // temp3->nextPtr =anotherNewNode5; // update temp3->next to new node
                // display(head3);

                while (count<2)
                {
                    count++;
                    temp3 = temp3->nextPtr;
                }

                anotherNewNode5->nextPtr =temp3->nextPtr;  // temp3->nextPtr point to 20
                temp3->nextPtr = anotherNewNode5;         // update temp3->next to new node
                
                printf("\n");
                display(head3);               
                break;
            
            case 3 :      
                head2 = (struct node*)malloc(sizeof(struct node));
                head2->data= 5;
                head2->nextPtr =NULL;
            
                struct node * newNode2 = (struct node*)malloc(sizeof(struct node));
                newNode2->data =10;
                newNode2->nextPtr = NULL;
            
                head2->nextPtr = newNode2;
           
                struct node * anotherNewNode2 =(struct node*)malloc(sizeof(struct node));
            
                anotherNewNode2->data =100;
                anotherNewNode2-> nextPtr = NULL;
                
                newNode2-> nextPtr =anotherNewNode2;
                display(head2);

                printf("\n");
                printf("Deleteting end node\n");
                
                temp2 = head2;
                while(temp2->nextPtr->nextPtr != NULL)
                {
                    temp2 = temp2->nextPtr;
                }
                temp2 = head2->nextPtr;
                free(temp2->nextPtr);
                temp2->nextPtr = NULL;
                display(head2);
            
            break;
            
            case 4 :    
            //delete in the middle

            head4 = (struct node*)malloc(sizeof(struct node));
            head4->data= 2;
            head4->nextPtr = NULL;
        
            struct node * new_Node = (struct node*)malloc(sizeof(struct node));
            new_Node->data =10;
            new_Node->nextPtr = NULL;
        
            head4->nextPtr = new_Node;
        
            struct node * new_Node2 =(struct node*)malloc(sizeof(struct node));
        
            new_Node2->data =100;
            new_Node2-> nextPtr = NULL;
            
            new_Node-> nextPtr = new_Node2;
            
            struct node * new_Node3 =(struct node*)malloc(sizeof(struct node));
            new_Node3->data=20;
            new_Node3->nextPtr = NULL;

            new_Node2 ->nextPtr=new_Node3;
    
            printf("\n");
            printf("inserting new node\n");
            struct node * new_Node4 =(struct node*)malloc(sizeof(struct node));

            new_Node4->data =250;
            new_Node4 ->nextPtr = NULL; 

            new_Node3->nextPtr = new_Node4;
            temp4 = head4;

            display(head4);

            printf("Deleting a node before last node");
            while (count<2)
            {
                //navigate to the node before last node 
                count++;
                temp4 = temp4->nextPtr;
            }
            struct node* ptr = temp4->nextPtr;
            printf("\n");
            display(ptr); //20->250 NOTE! display(temp4->nextPtr) is equal 250
            temp4->nextPtr = ptr->nextPtr;
            free(ptr); // delete data 20
            printf("\n");
            display(head4);
            

            break;
            case 5 :    
            exit(1);
            default :   
            printf("Enter valid option.");
                        break;
        }
        
    }
}


void arrayPosition_remove()
{
    int arr[] = {1,2,3,4,5,6};

    int i;
    int target_position =2;
    int arrSize= sizeof(arr)/sizeof(arr[0]);
    
    for(i = target_position -1; i < arrSize;i++)
    {
        arr[i] = arr[i+1];
    }
    arrSize--;

    for(i =0; i < arrSize;i++)
    {
        printf("%d\n",arr[i]);
    }
}

void autoStorageClass()
{
 
    printf("\nDemonstrating auto class\n\n");
 
    // declaring an auto variable (simply
    // writing "int a=32;" works as well)
    auto int a = 32;
 
    // printing the auto variable 'a'
    printf("Value of the variable 'a'"
           " declared as auto: %d\n",
           a);
 
    printf("--------------------------------");
}
 
void registerStorageClass()
{
 
    printf("\nDemonstrating register class\n\n");
 
    // declaring a register variable
    register char b = 'G';
 
    // printing the register variable 'b'
    printf("Value of the variable 'b'"
           " declared as register: %d\n",
           b);
 
    printf("--------------------------------");
}
 
void externStorageClass()
{
 
    printf("\nDemonstrating extern class\n\n");
 
    // telling the compiler that the variable
    // z is an extern variable and has been
    // defined elsewhere (above the main
    // function)
    extern int x;
 
    // printing the extern variables 'x'
    printf("Value of the variable 'x'"
           " declared as extern: %d\n",
           x);
 
    // value of extern variable x modified
    x = 2;
 
    // printing the modified values of
    // extern variables 'x'
    printf("Modified value of the variable 'x'"
           " declared as extern: %d\n",
           x);
 
    printf("--------------------------------");
}
 
void staticStorageClass()
{
    int i = 0;
 
    printf("\nDemonstrating static class\n\n");
 
    // using a static variable 'y'
    printf("Declaring 'y' as static inside the loop.\n"
           "But this declaration will occur only"
           " once as 'y' is static.\n"
           "If not, then every time the value of 'y' "
           "will be the declared value 5"
           " as in the case of variable 'p'\n");
 
    printf("\nLoop started:\n");
 
    for (i = 1; i < 5; i++) {
 
        // Declaring the static variable 'y'
        static int y = 5;
 
        // Declare a non-static variable 'p'
        int p = 10;
 
        // Incrementing the value of y and p by 1
        y++;
        p++;
 
        // printing value of y at each iteration
        printf("\nThe value of 'y', "
               "declared as static, in %d "
               "iteration is %d\n",
               i, y);
 
        // printing value of p at each iteration
        printf("The value of non-static variable 'p', "
               "in %d iteration is %d\n",
               i, p);
    }
 
    printf("\nLoop ended:\n");
 
    printf("--------------------------------");
}

void C_storageClassdemo()
{
     printf("A program to demonstrate"
           " Storage Classes in C\n\n");
 
    // To demonstrate auto Storage Class
    autoStorageClass();
 
    // To demonstrate register Storage Class
    registerStorageClass();
 
    // To demonstrate extern Storage Class
    externStorageClass();
 
    // To demonstrate static Storage Class
    staticStorageClass();
 
    // exiting
    printf("\n\nStorage Classes demonstrated");

}

void  ptr_2_array()
{
    int array[5] = {1,2,3,4,5};
    int array2[] = {6,7,8,9,10};
    int i;
    int *ptr = array;

    printf("ptr = array;\n");
    for(i = 0; i< 5; i++)
    {
        printf("%d\n", ptr[i]);
    }

    printf("ptr = array2;\n");
    ptr = array2;
    //ptr = &array2; incompatible data type

    for(i = 0; i< 5; i++)
    {
        printf("%d\n", ptr[i]);
    }

    printf("print *(ptr+ i) \n");

    for(i = 0; i< 5; i++)
    {
        printf("%d\n", *(ptr +i));
    }

    printf("print (*ptr+ i) \n");

    for(i = 0; i< 5; i++)
    {
        printf("%d\n", *ptr +i);
    }
}

unsigned int countSetBits(unsigned int n)
{
	unsigned int count = 0;
	while (n) {
		count += n & 1;
		n >>=1;
	}
	return count;
}

void count_set_bit()
{
    unsigned int value= 0;
    value = countSetBits(9);

     printf("%d\n", value);
}

int decToBinary(int n)
{
    char character;
    // Size of an integer is assumed to be 32 bits
    for (int i = 31; i >= 0; i--) {
        int k = n >> i;
        if (k & 1)
        {
            character= '1';
            printf("%c", character);
        }
        else
        {
            character ='0';
            printf("%c", character);
        }

    }
     printf("\n");
}

int count_repeated_arr_occurence(int arr[],int arrSize,int target)
{
    int counter = 0;

    for (int i=0; i<arrSize; i++)
    {
        if (target == arr[i])
        counter++;

    }

    return counter;    
}

void check_repeated_arr()
{
    //int arr[] ={1,2,3,4,4,5,5,5,5,7,8};
    int arr[] = {4, 7,7,7,2, 4, 5, 2, 3, 1};
    int Size = sizeof(arr)/sizeof(arr[0]);
    int i,j, count,temp; 

    for (i = 0; i < Size; i++)
	{
		for(j = i + 1; j < Size; j++)
		{
            if(arr[i] == arr[j])
            {
                printf(" repeated arr is %d\n", arr[i]);
            }
    	}   
    }

    count = count_repeated_arr_occurence(arr,Size,7);
    printf(" 7 have how many %d  repeatition\n", count);

}

void remove_duplicate_arr()
{
    int arr[10] ={1,2,3,4,5,5,5,5,7,8};
    int Size = sizeof(arr)/sizeof(arr[0]);
	int i,j,k; 
 
	for (i = 0; i < Size; i++)
	{
		for(j = i + 1; j < Size; j++)
		{
    		if(arr[i] == arr[j])
    		{
    			for(k = j; k < Size; k++)
    			{
    				arr[k] = arr[k + 1];
				}
				Size--;
				j--;
			}
		}
	}

 	printf("\n Final Array after Deleteing Duplicate Array Elements is:\n");
 	for (i = 0; i < Size; i++)
  	{
        if(i == Size -1)
        {
            printf("%d\n", arr[i]);
        }
        else
        {
            printf("%d\t", arr[i]);
        }
  	}
    printf("size of arr is %d\n", Size);	     
}

void post_incre_pre_incre()
{
    int x = 0;
    printf("pre increment is %d\n", ++x);
    printf("post increment is %d\n", x++);
    printf("post increment 2 is %d\n", x++);
    printf("value of x after twice post increment is %d\n", x);
}

void c_style_enum()
{
    week_obj;
    week_obj++;
    printf("post increment of enum is %d\n",week_obj);
    week_obj++;
    printf("post increment again of enum is %d\n",week_obj);
}


void bitwise()
{
    int num, position, newNum, bitStatus;
    uint32_t targetbit = 0;

    /* Input number from user */
    printf("Enter any number: ");
    scanf("%d", &num);

    /* Input bit position you want to set */
    printf("Enter nth bit to check and set (0-31): ");
    scanf("%d", &position);

    printf("CHECK INDIVIDUAL BIT\n");
    decToBinary(num);
    printf("\n");
    /* Right shift num, position times and perform bitwise AND with 1 */
    bitStatus = (num >> position) & 1;
    
    if(bitStatus)
    {
        printf("Position bit %d  of num %d is set\n",position, num);
    }
    else
    {
        printf("Position bit %d  of num %d is not set\n",position, num);
    }
    
    printf("Set Bit\n");
    printf("\n");
    /* Left shift 1, n times and perform bitwise OR with num */
    newNum = (1 << position) | num;
    printf("\nBit set successfully.\n\n");

    printf("Number before setting %d bit: %d (in decimal)\n", position, num);
    printf("Number after setting %d bit: %d (in decimal)\n", position, newNum);

    targetbit = 1 << 12;
    printf("%" PRIu32 "\n",targetbit);
    decToBinary((int)targetbit);

}

void micron_code_test()
{
    int test[4][4];
    int i,j,a;
    for (i =0; i <4; i++)
    {
        for(j=0; j<4;j++)
        {
           if(i == j)
           {
               test[i][j] = 1;
           }
           else 
           {
               test[i][j] = 0;
           }
        }
        printf("\n");
    }
    for (i =0; i <4; i++)
    {
        for(j=0; j<4;j++)
        {
            printf(" test[i][j] is %d\n",  test[i][j]);
        }
        printf("\n");
    
    }
}

void structure_style_demo()
{
    struct test_Struct_style_1 style1;
    style1.x = 1;
    style1.y =1;

    struct test_Struct_style_2 style2 =
    {
        .a = 10,
        .b =100
    };

    printf("style2.a is %d\n", style2.a);
    printf("style2.b is %d\n", style2.b);
}

void sort_2D_array()
{
    int i,j,k;
    int oneDarr[16];
    int count=0;
    int step;
    int size;
    int matrix[4][4];
    int disp[4][4] = 
    {
        {10, 11, 12, 13},
        {14, 15, 16, 17},
        {25, 100, 21, 213},
        {134, 43, 64, 75}
    };

    int row_number= sizeof(disp)/sizeof(disp[0]);
    printf("row_number %d\n", row_number);
    int column = sizeof(disp[0])/sizeof(disp[0][0]);
    printf("column %d\n", column);
    printf("sizeof(disp[0]) %ld\n", sizeof(disp[0]));
    printf("sizeof(disp[0][0]) %ld\n", sizeof(disp[0][0]));
    return;
    
    for (i = 0; i < 4; ++i) 
    {
        for (j = 0; j < 4; ++j)
        {
            // mapping 1D array to 2D array
            oneDarr[count++] = disp[i][j];
        }
    }

    printf("before sort\n");
    for(i =0; i<16;i++)
    {
        printf("%d\n",oneDarr[i]);
    }

    size =sizeof(oneDarr)/sizeof(oneDarr[0]);
    
    for(step =0; step<size-1; step++)
    {
        for (int arrIndex = 0; arrIndex< size -step - 1; arrIndex++) 
        {
      
            // To sort in descending order, change">" to "<".
            if (oneDarr[arrIndex] > oneDarr[arrIndex + 1]) 
            {    
                // swap if greater is at the rear position
                int temp = oneDarr[arrIndex];
                oneDarr[arrIndex] = oneDarr[arrIndex + 1];
                oneDarr[arrIndex + 1] = temp;
            } 
        }
    }

    printf("after sort\n");
    for(i =0; i<16;i++)
    {
        
        printf("%d\n",oneDarr[i]);
    }

    int index =0;
    for(i=0;i<4;i++)
     {
         for(j=0;j<4;j++)
         {
             matrix[i][j] = oneDarr[index++];
         }
     }

    printf("2D arr\n");
    for(i=0;i<4;i++)
    {
        for(j=0;j<4;j++)
        {
            printf("%d,", matrix[i][j]);
            
            if(j == 3)
            {
               printf("\n");              
            }
            
        }
    }
}

void sort_1D_array()
{
    int arr[]={0,100,20,30,50};
    int step;
    int arrIndex;
    int size= sizeof(arr)/sizeof(arr[0]);

    for(step =0; step<size-1; step++)
    {
        for (int arrIndex = 0; arrIndex< size -step - 1; arrIndex++) 
        {      
            // To sort in descending order, change">" to "<".
            if (arr[arrIndex] > arr[arrIndex + 1]) 
            {    
                // swap if greater is at the rear position
                int temp = arr[arrIndex];
                arr[arrIndex] = arr[arrIndex + 1];
                arr[arrIndex + 1] = temp;
            } 
        }
    }
        
    for(step =0; step<size; step++)
    {
        printf("%d\n", arr[step]);
    }
}

int circ_bbuf_push(circ_bbuf_t *c, uint8_t data)
{
    int next;

    next = c->head + 1;  // next is where head will point to after this write.
    printf("maxlen %d\n",c->maxlen);
    if (next > c->maxlen)
        next = 0;

    if (next == c->tail)  // if the head + 1 == tail, circular buffer is full
        return -1;

    c->buffer[c->head] = data;  // Load data and then move
    c->head = next;             // head to next data offset.
    return 0;  // return success to indicate successful push.
}

#define CIRC_BBUF_DEF(x,y)                \
    uint8_t x##_data_space[y];            \
    circ_bbuf_t x = {                     \
        .buffer = x##_data_space,         \
        .head = 0,                        \
        .tail = 0,                        \
        .maxlen = y                       \
    }

int circ_bbuf_pop(circ_bbuf_t *c, uint8_t *data)
{
    int next;

    if (c->head == c->tail)  // if the head == tail, we don't have any data
        return -1;

    next = c->tail + 1;  // next is where tail will point to after this read.
    if(next > c->maxlen)
        next = 0;

    *data = c->buffer[c->tail];  // Read data and then move
    c->tail = next;              // tail to next offset.
    return 0;  // return success to indicate successful push.
}

CIRC_BBUF_DEF(my_circ_buf, 5);

int your_application()
{
    uint8_t out_data=0, in_data = 0x55;
    int i;
    for (i =0;i<=5; i++)
    {
        in_data=i;
        
        if (circ_bbuf_push(&my_circ_buf, in_data)) 
        {
            printf("Out of space in CB\n");
            return -1;
        }

        if (circ_bbuf_pop(&my_circ_buf, &out_data)) 
        {
            printf("CB is empty\n");
            return -1;
        }

        // here in_data = in_data = 0x55;
        printf("Push: 0x%x\n", in_data);
        printf("Pop:  0x%x\n", out_data);
    }

    return 0;
}

void deleteAllOccurrences(struct node** head_ref, int key)
{
    // Store head node
    struct node *temp = *head_ref, *prev;
 
    // If head node itself holds the key or multiple
    // occurrences of key
    while (temp != NULL && temp->data == key)
    {
        *head_ref = temp->nextPtr; // Changed head
        free(temp); // free old head
        temp = *head_ref; // Change Temp
    }
 
    // Delete occurrences other than head
    while (temp != NULL)
    {
        // Search for the key to be deleted, keep track of
        // the previous node as we need to change
        // 'prev->next'
        while (temp != NULL && temp->data != key)
        {
            prev = temp;
            temp = temp->nextPtr;
        }
 
        // If key was not present in linked list
        if (temp == NULL)
            return;
 
        // Unlink the node from linked list
        prev->nextPtr = temp->nextPtr;
 
        free(temp); // Free memory
 
        // Update Temp for next iteration of outer loop
      //   temp = prev->nextPtr;
    }
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
    insertAtEnd(&head, 'M');

    deleteAllOccurrences(&head,'L');
    
    printfList(head);
}

void init_que(queue *q, int max_size)
{
    q->size = max_size;
    q->values = malloc(sizeof(int)*q->size);
    q->number_entries = 0;
    q->head = 0 ;
    q->tail = 0;
    q->counter = 0;
}

int queu_empty(queue *q)
{
    return (q->number_entries == 0);
}

int queu_full(queue *q)
{
    return (q->number_entries == q->size);
}

int wrap_around_required(queue *q)
{
    return (q->number_entries >= q->size);
}

void queue_destroy(queue *q)
{
    free(q->values);
}

int enqueue(queue* q, int value)
{
    q->counter++;

    if(wrap_around_required(q))
    {
        if(q->counter >= q->size)
        {
            q->tail = 0;
            q->counter = 0;
        }

        q->values[q->tail] = value;
    }
    else
    {
        q->values[q->tail] = value;
        q->number_entries++;
    }
    
    q->tail =q->tail + 1;
    
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
    int number;

    init_que(&obj,5);

    enqueue(&obj, 1);
    enqueue(&obj, 2);
    enqueue(&obj, 3);
    enqueue(&obj, 4);
    enqueue(&obj, 5);
    enqueue(&obj, 6);
    enqueue(&obj, 7);
    enqueue(&obj, 8);
    enqueue(&obj, 9);


    printf("deeeeeee 1 = %d \n", dequeue(&obj));
    printf("deeeeeee 2 = %d \n", dequeue(&obj));
    printf("deeeeeee 3 = %d \n", dequeue(&obj));
    printf("deeeeeee 4 = %d \n", dequeue(&obj));
    printf("deeeeeee 5 = %d \n", dequeue(&obj));

    // while((number = dequeue(&obj)) != 0)
    // {
    //     printf("enque number is %d\n", number);

    // }
    // your_application();
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
    printf("NOTE &var is getting address of the variables  address of the variable on the  computer.\nif the pointer is *ptr and it pointing to some variable such as *ptr=&variable , printing ptr only may yield address of the variable  it poiting to.\n");
    printf("We usually confused when a pointer is with '&' or without '&' operator,refer INfO 2 & INFO 3 to recall\n");
    printf("--------------------------------------\n");
    printf("INFO 1\n");
    printf(" **ipp = NULL ,*ip1 = &i, *ip2 = &j ,i = 5,j = 6,k = 7 is just constant variable\n");
    printf("printing &i -> adress of  i is %p\n",&i);
    printf("printing &j -> adress of  j is %p\n",&j);
    printf("printing &k -> adress of  k is %p\n",&k);
    printf("--------------------------------------\n");
    printf("INFO 2\n");
    printf("printing &ip1 -> adress of pointer &ip1 is %p\n",&ip1);
    printf("printing &ip2 -> adress of pointer &ip2 is %p\n",&ip2);
    printf("printing &ipp -> adress of pointer &ipp is %p\n",&ipp);   
    printf("printing ip1 -> adress of pointer ip1 is %p\n",ip1);
    printf("printing ip2 -> adress of pointer ip2 is %p\n",ip2);
    //printf("adress of pointer ipp is %p\n",&ipp);
    printf("--------------------------------------\n");
    printf("INFO 3\n");
    printf("*ip1 = &i:");
    printf("printing ip1 -> adress of  ip1 is %p\n",ip1);
    printf("*ip2 = &j:");
    printf("printing ip2 -> adress of  ip2 is %p\n",ip2);
    printf("ipp is not doing anything yet:");
    printf("printing ipp -> adress of  ipp is %p\n",ipp);
    printf("printing &ipp -> adress of  &ipp is %p\n",&ipp);
    printf("--------------------------------------\n");
    printf("INFO 4\n");
    ipp = &ip1;
    printf("Now ipp = &ip1:");
    printf("printing &ipp -> &ipp is still equal %p\n",&ipp);
    printf("This is just to demonstrate regardless how ipp pointing, it address won't change, what change is address it pointing to\n");
    printf("--------------------------------------\n");
    printf("INFO 5\n");
    printf("printing *ipp -> *ipp is equal to print ip1 value -> %p\n",*ipp);
    printf("ipp is equal to print &ip1 is %p\n",ipp);
    printf("printing **ipp -> **ipp is %d\n", **ipp);
}

void b_changePointerValuewithPtr2Ptr(int ** ptr)
{
    int *local = (int*)malloc(sizeof(int*));
    *local = random()%20;
    printf("locla function value is %d\n", *local);
    printf("adress of  local is %p\n",local);
    printf("adress of  &(*local) is %p\n", &(*local));
    // *ptr = &(*local);
    *ptr = local;
     printf("debug *ptr is %d\n", **ptr);
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

    while((opt = getopt(argc, argv,"abcdefghijklmnopqrst")) != -1)
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
                double_pointer_again();
                //pointer2PointerDemo();
            break;
 
            case'd':
                pointerGetvaluefromReturn();
            break;
                        
            case'e':
                process_data_Structure();
            break;
            
            case'f':
              //  demo_array();
              array_again();
            break;

            case'g':
                circular_que_demo();
            break;

            case'h':
               // link_list_demo();
               my_link_list();
            break;

            case'i':
                sort_1D_array();      
            break;

            case'j':
                sort_2D_array();      
            break;

            case'k':
                structure_style_demo();
            break;

            case 'l':
                micron_code_test();
            break;

            case 'm':
                bitwise();
            break;

            case 'n':
                c_style_enum();
            break;

            case 'o':
                post_incre_pre_incre();
            break;

            case'p':
                arrayPosition_remove();
            break;

            case 'q':
                check_repeated_arr();
            break;

            case 'r':
                count_set_bit();
            break;

            case 's':
                ptr_2_array();
            break;

            case 't':
                C_storageClassdemo();
            break;

            default :
                printf("unable to parse cli\n");
            break;
        }
    }  

    return 0;
}
