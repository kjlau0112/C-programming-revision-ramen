#include <stdio.h>
#include <stdlib.h>
#include <string.h>


void findDuplicates(char *str) {
    int len = strlen(str);
    printf("Duplicate characters:\n");

    for (int i = 0; i < len; i++) {
        if (str[i] == '\0') continue;  // Skip characters already processed
        int count = 1;

        for (int j = i + 1; j < len; j++) {
            if (str[i] == str[j]) {
                count++;
                str[j] = '\0';  // COMMENT THIS TO SEE THE WRONG OUTPUT
            }
        }

        if (count > 1) {
            printf("%c appears %d times\n", str[i], count);
        }
    }
}

int main(int argc, char *argv[])
{
    char *ptr ="review C string";
    char *duplicatedString ="kjlau0112";
    char mutableString[] = "kjlau0112";
    char *mystring ="hello worldLLLLLLLLLLLLLLLLLLLLLLLLLL!";

    int i;
    
    printf("string length %lu\n", strlen(duplicatedString));

    for(i=0; i<strlen(duplicatedString);i++)
    {
        printf("%c", *(duplicatedString+i));

    }
    printf("\n");
    findDuplicates(mutableString);

    printf("size of %ld\n", sizeof(mutableString));
     
}