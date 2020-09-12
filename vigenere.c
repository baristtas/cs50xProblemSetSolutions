#include <stdio.h>
#include <cs50.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>

    //CS50 problem set 2 Vigenere Task solution.

int errorFunction(int argc);

int main(int argc, char* argv[]){
    if (argc != 2) return errorFunction(argc);
    for (int i = 0, x = strlen(argv[1]); i < x; i++){
        if(isalpha(argv[1][i]) == 0) return 1 && printf("HATA: Alfabetik olmayan bir karakter girdiniz. \n");
    }

    string message = get_string("Mesajinizi giriniz:\n");
    int keyLength = strlen(argv[1]);
    int messageLength = strlen(message);
    string key = argv[1];

    for(int i = 0, x = 0; i < messageLength; i++){
        if(isalpha(message[i])){
            int offset = islower(message[i]) != 0 ? 97 : 65; //ill remove offset with this.
            int pi = message[i] - offset;
            int ki = key[(x + keyLength) %keyLength];
            message[i] = (((pi + (toupper(ki) - 65)) %26) + offset);
            x++;
        }
    }


    printf("ciphertext: %s\n",message);
}

int errorFunction(int argc){
    printf("HATA: Giriş argümanı sayısını kontrol ediniz. Girilen argüman sayisi:%d\n",argc-1);
    return 1;
}
