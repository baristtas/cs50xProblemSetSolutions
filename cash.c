#include <stdio.h>
#include <cs50.h>
#include <math.h>

int main()
{       
    
    float tutar;
    float nakit;
    
    while(true)
    {
    tutar = get_float("Urunlerinizin tutarini giriniz: \n");
    if(tutar < 0)
    {
        printf("Dogru deger giriniz.\n");
    }
    else if(tutar >= 0)
    {
        break;
    }
    }
    while(true)
    {
        nakit = get_float("Nakiti veriniz\n");
        if((tutar > nakit) || (nakit < 0)){
            printf("Verdiginiz ucret yetersiz. Tekrar giriniz\n");
        }
        else break;
        
    }
    float paraUstu = (nakit - tutar) * 100;
    int giris = round(paraUstu);
    int elliKurus = giris/50;
    int yirmibesKurus =  (giris%50)/25;
    int onKurus = ((giris%50)%25)/10;
    int besKurus = (((giris%50)%25)%10)/5;
    int birKurus = ((((giris%50)%25)%10)%5);
    int cikantop = elliKurus + yirmibesKurus + onKurus + besKurus + birKurus;
    printf("elli kurus: %d\nyirmibes kurus:%d\non kurus:%d\nbeskurus:%d\nbirkurus:%d\n",elliKurus,yirmibesKurus,onKurus,besKurus,birKurus);

}
