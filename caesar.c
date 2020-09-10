#include <stdio.h>
#include <cs50.h>
#include <string.h>
#include <stdlib.h>

// https://ide.cs50.io/ adresine gidin. caesar.c adında yeni bir dosya açın. kodu içeri kopyalayın. make caesar yazarak kodu derleyin. ./caesar ve bir sayı yazarak programı başlatın. örneğin => ./caesar 13

// Sezar Algoritması. CS50 problem set2.
// prensip olarak açıklamaların ve değişkenlerin ingilizce olması lazım fakat bu seferlik böyle oldu.

int errorFunction(); //Main fonksiyonunun altına yazdığım fonksiyonu burada tanıttım.

int main(int argc, char* argv[]){
    if(argc != 2) return errorFunction(); //argüman sayısı kontrolü. fonksiyonsuz da sadece return printf ile yapılabilirdi fakat int main altında fonksiyon tanımlama yapılabildiğini göstermek için böyle yaptım.
    string message = get_string("Mesajinizi giriniz: \n");

    //Stringi aldık. Şimdi ascii tablosuna göre kelimenin indis değerini argv[1] kadar ilerleteceğiz. argv[1] func çağrıldıktan sonraki ilk parametredir.
    //Stringin her karakterini artırmamız için stringin uzunluğu kadar tekrar yapmamız gerek. strlen() unsigned long döndürüyor.

    int step = atoi(argv[1]); //atoi ile parametre değeri integer değere çeviriyoruz.

    for (unsigned long i = 0; i < strlen(message); i++){
        ((message[i] > 64 && message[i] < 91)) ? message[i] = (((message[i] + step - 65) %26) + 65) : message[i];
        ((message[i] > 96 && message[i] < 123)) ? message[i] = (((message[i] + step - 97) %26) + 97) : message[i];
    }
    printf("Bitiste message stringi: %s\n",message);
}

int errorFunction(){
    printf("Hata. Giriş argümanı sayısını kontrol ediniz.\n");
    return 0;
}