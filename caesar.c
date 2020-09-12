#include <stdio.h>
#include <cs50.h>
#include <string.h>
#include <stdlib.h>

int errorFunction();

int main(int argc, char* argv[]){
    if(argc != 2) return errorFunction();
    string message = get_string("Mesajinizi giriniz: \n");

    int step = atoi(argv[1]);

    for (unsigned long i = 0; i < strlen(message); i++){
        ((message[i] > 64 && message[i] < 91)) ? message[i] = (((message[i] + step - 65) %26) + 65) : message[i];
        ((message[i] > 96 && message[i] < 123)) ? message[i] = (((message[i] + step - 97) %26) + 97) : message[i];
    }
    printf("ciphertext: %s\n",message);

}

int errorFunction(){
    printf("Hata. Giriş argümanı sayısını kontrol ediniz.\n");
    return 1;
}