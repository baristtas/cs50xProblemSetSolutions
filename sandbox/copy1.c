#include <stdio.h>
#include <stdlib.h>
#include <cs50.h>
#include <string.h>

void copy(char *s1, char *s2);

int main(int argc, char *argv[])
{
    char *str1 = get_string("String1'i gir.");
    char *str2 = get_string("String2'yi gir.");
    copy(str1,str2);
    printf("1:%s\n",str1);
    printf("2:%s\n",str2);
}

void copy(char *str1, char *str2){
    char *ptr1 = malloc((strlen(str1) + 1) * sizeof(char));
    for (int i = 0, n = strlen(str1); i <= n; i++ ){
            ptr1[i] = str1[i];
            str1[i] = str2[i];
            str2[i] = ptr1[i];
    }
    free(ptr1);
}

