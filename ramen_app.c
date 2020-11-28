#include <stdio.h>
#include <unistd.h>  
#include <stdlib.h>
#include <time.h>


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
    int **ipp;
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

    while((opt = getopt(argc, argv,"abcdef")) != -1)
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
            break;
            
            case'f':
            break;

            default :
                printf("unable to parse cli\n");
            break;
        }
    }  

    return 0;
}
