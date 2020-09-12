#include <stdio.h>
#include <cs50.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>

    //CS50 problem set 2 Vigenere Task solution.

    //Usage: ./vigenere <key word>
    //Kullanım: ./vigenere <anahtar kelime>

int errorFunction(int argc);

int main(int argc, char* argv[]){
    if (argc != 2) return errorFunction(argc);
    for (int i = 0, x = strlen(argv[1]); i < x; i++){
        if(isalpha(argv[1][i]) == 0) return printf("HATA: Alfabetik olmayan bir karakter girdiniz. \n");
    }

    string message = get_string("Mesajinizi giriniz:\n");
    int abc = strlen(argv[1]);
    string step = argv[1];

    for (unsigned long i = 0; i < strlen(message); i++){
        ((message[i] > 64 && message[i] < 91)) ? message[i] = (((message[i] - 65) + (step[(i + abc)%abc]-65)%26)%26) + 65 : message[i];
        ((message[i] > 96 && message[i] < 123)) ? message[i] = (((message[i] - 97) + (step[(i + abc)%abc]-65)%26)%26) + 97 : message[i];
    }
    printf("Bitiste message stringi: %s\n",message);
}

int errorFunction(int argc){
    printf("HATA: Giriş argümanı sayısını kontrol ediniz. Girilen argüman sayisi:%d\n",argc-1);
    return 0;
}
