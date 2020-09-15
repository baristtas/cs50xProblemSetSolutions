#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

void collatz (int *a, int *counter);
int main(int argc,char *argv[])
{
    for (int i = 0, x = strlen(argv[1]); i < x; i++){
        if(isalpha(argv[1][i]) != 0) return 1 && printf("Error at argument. Only numeric inputs are accepted.\n");
    }
    int input = atoi(argv[1]);
    int counter = 0;
    printf("%d\n",input);
    collatz(&input, &counter);
    printf("A:'%i', Counter:'%i'\n",input,counter);
}
void collatz(int *a, int *counter)
{
    while (*a != 1){
        if ((*a %2) == 0) {
            *a = *a/2;
            *counter += 1;
            collatz(a,counter);
         }
         else if((*a %2) == 1){
             *a = ((*a) * 3) + 1;
             *counter += 1;
             collatz(a,counter);
         }
    }
}
