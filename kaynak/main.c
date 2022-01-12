#include <stdio.h>
#include <stdlib.h>
#include<string.h>
struct node
{
    char kelime[1000];
    char cocuk[1000][1000];
    struct node *next;
};
typedef struct node node;
node *ilk=NULL,*son=NULL;
void ilerle(char substring[100])
{
    node *yeni=(node*)malloc(sizeof(node));
    strcpy(yeni->kelime,substring);
    yeni->next=NULL;
    if(ilk==NULL)
    {
        ilk=yeni;
        son=yeni;
    }
    else
    {
        son->next=yeni;
        son=yeni;
    }
}
void dalla(char substring[1000])
{
    node *iter=ilk;
    int indis=0;
    while(iter!=NULL)
    {
        if(iter->kelime[0]==substring[0])
        {
            while(iter->cocuk[indis][0]!='\0')
            {
                indis++;
            }
            strcpy(iter->cocuk[indis],substring+1);
            break;
        }
        iter=iter->next;
    }
}
void bastir()
{
    printf("\n\nAgac Goruntuleniyor...\n\n");
    node *iter=ilk;
    while(iter!=NULL)
    {
        int a=204,b=186,c=196;
        for(int i=0; i<strlen(iter->kelime); i++)
        {
            printf("%c",c);
        }
        printf("\n");
        printf("#%s\n",iter->kelime);
        int indis=0;
        while(iter->cocuk[indis][0]!='\0')
        {
            int sayac=0;
            for(int j=1; j<strlen(iter->kelime); j++)
            {
                if(iter->kelime[j]==iter->cocuk[indis][j-1])
                {
                    sayac++;
                    printf(" ");
                }
                else
                {
                    printf(" %c\n",b);
                    break;
                }
            }
            for(int i=0; i<sayac; i++)
                printf(" ");
            printf(" %c%s\n",a,iter->cocuk[indis]+sayac);
            int kontrol1=indis+1;
            int kontrol2=0;
            while(iter->cocuk[kontrol1][0]!='\0')
            {
                if(iter->cocuk[indis][0]==iter->cocuk[kontrol1][0])
                {
                    char tmp[1000];
                    strcpy(tmp,iter->cocuk[indis+1]);
                    strcpy(iter->cocuk[indis+1],iter->cocuk[kontrol1]);
                    strcpy(iter->cocuk[kontrol1],tmp);
                    kontrol2=1;
                    break;
                }
                kontrol1++;
            }
            if(kontrol2==1)
            {
                indis++;
                int sayac=0;
                for(int j=0; j<strlen(iter->cocuk[indis-1]); j++)
                {
                    if(iter->cocuk[indis-1][j]==iter->cocuk[indis][j])
                    {
                        sayac++;
                        printf(" ");
                    }
                    else
                    {
                        printf(" %c\n",b);
                        break;
                    }
                }
                for(int i=0; i<sayac; i++)
                    printf(" ");
                printf(" %c%s\n",a,iter->cocuk[indis]+sayac);
            }
            indis++;
            if(iter->cocuk[indis][0]=='\0')break;
            printf("#%s\n",iter->kelime);
        }
        iter=iter->next;
    }
}
int hasSuffix(char text[1000])
{
    int boyut=strlen(text);
    char prefix[boyut][1000];
    char suffix[boyut][1000];
    char tmp[boyut];
    strcpy(tmp,text);
    for(int i=0; i<boyut; i++)
    {
        tmp[boyut-i]='\0';
        strcpy(suffix[i],text+i);
        strcpy(prefix[i],tmp);

    }
    printf("\n\nSuffix   -  Prefix\n------------------\n");
    int kontrol=0;
    for(int i=0; i<boyut; i++)
    {
        printf("%-10s-%-10s",suffix[i],prefix[i]);
        if(strcmp(suffix[i],prefix[i])==0&&i!=0)
        {
            printf("--> Bu esitlik %s kelimesinin sonek agaci olusturmasini engeller.",prefix[0]);
            kontrol=1;
        }
        printf("\n");
    }
    return kontrol;
}
void katarArama(char text[1000])
{
    char aranan[1000];
    printf("Aramak istediginiz katari giriniz=");
    scanf("%s",aranan);
    printf("\n");
    int indis=0;
    int sayac=0,j;
    for(int i=0; i<strlen(text); i++)
    {
        for( j=0; j<strlen(aranan); j++)
        {
            if(text[i+j]!=aranan[j])
            {
                break;
            }
        }
        if(j==strlen(aranan))
        {
            printf("%s\n",text);
            for(int a=0; a<i; a++)
            {
                printf("*");
            }
            printf("%s",aranan);
            for(int a=0; a<strlen(text)-(i+strlen(aranan)); a++)
            {
                printf("*");
            }
            printf("\n");
            sayac++;
        }
    }
    if(sayac==0)
    {
        printf("\nAranan katar bulunamadi.\n");
    }
    else
    {
        printf("\nAranan katar bulundu.(katar icinde %d tane geciyor.)\n",sayac);
    }

}
void tekrariEnUzunKatar(char text[1000])
{
    int boyut=strlen(text);
    char enUzun[1000];
    strcpy(enUzun,"");
    for(int i=0; i<boyut; i++)
    {
        for(int j=i+1; j<boyut; j++)
        {
            char test1[boyut];
            char test2[boyut];
            strcpy(test1,text+i);
            strcpy(test2,text+j);
            int minBoyut=strlen(test2);
            char tmp[boyut];
            strcpy(tmp,"");
            for(int a=0; a<minBoyut; a++)
            {
                if(test1[a]!=test2[a])
                {
                    test1[a]='\0';
                    strcpy(tmp,test1);
                }
            }
            if(strlen(tmp)>=strlen(enUzun))
            {
                strcpy(enUzun,tmp);
            }
        }
    }
    if(strlen(enUzun)==0)
    {
         printf("\nTekrarlanan katar bulunamadi.\n");
    }
    else
    {
        printf("\n\nTekrarlanan En Uzun Katar \"%s\" Goruntuleniyor..\n\n",enUzun);
        int sayac=0;
        for(int i=0; i<boyut; i++)
        {
            int j;
            for( j=0; j<strlen(enUzun); j++)
            {
                if(text[i+j]!=enUzun[j])
                {
                    break;
                }
            }
            if(j==strlen(enUzun))
            {
                sayac++;
                printf("kelime->%s\ntekrar->",text);
                for(int a=0; a<i; a++)
                {
                    printf("*");
                }
                printf("%s",enUzun);
                for(int a=0; a<boyut-(strlen(enUzun))-i; a++)
                {
                    printf("*");
                }
                printf("\n");
            }
        }
        printf("(%d tane var.)\n",sayac);
    }

}
void enCokTekrarEdenKatar(char text[1000])
{
    int boyut=strlen(text);
    int i,j,sayac,enb=0;
    char tmp[boyut];
    char enCok[boyut];
    for(i=0; i<boyut; i++)
    {
        strcpy(tmp,text+i);
        for(j=1; j<strlen(tmp); j++)
        {
            tmp[j]='\0';
            sayac=0;
            int x;
            for(int a=0; a<boyut; a++)
            {
                for(x=0; x<strlen(tmp); x++)
                {
                    if(text[a+x]!=tmp[x])
                    {
                        break;
                    }
                }
                if(x==strlen(tmp))
                {
                    sayac++;
                }
            }
            if(sayac>=enb)
            {
                enb=sayac;
                strcpy(enCok,tmp);
            }
            strcpy(tmp,text+i);
        }
    }
    if(enb==1||enb==0){
        printf("\nTekrarlanan katar bulunamadi.\n");
    }else{
    printf("\nEn Cok Tekrar Eden \"%s\" Katari goruntuleniyor...(%d tane geciyor.)\n",enCok,enb);
    for(i=0; i<boyut; i++)
    {
        int a;
        for(a=0; a<strlen(enCok); a++)
        {
            if(enCok[a]!=text[a+i])
            {
                break;
            }
        }
        if(a==strlen(enCok))
        {
            printf("Kelime=>%s\nTekrar=>",text);
            for(int x=0; x<i; x++)
            {
                printf("*");
            }
            printf("%s",enCok);
            for(int x=0; x<strlen(text)-i-strlen(enCok); x++)
            {
                printf("*");
            }
            printf("\n");
        }
    }
    }

}
int main()
{
    char dosyayaYaz[1000];
    FILE *dosya=fopen("text.txt","w");
    printf("Kelimeyi Giriniz=");
    scanf("%s",dosyayaYaz);
    fprintf(dosya,"%s",dosyayaYaz);
    fclose(dosya);
    dosya=fopen("text.txt","r");
    char text[1000];
    if(dosya==NULL)
    {
        exit(1);
    }
    else
    {
        fscanf(dosya,"%s",text);
         if(text[strlen(text)-1]!='$'){
             strcat(text,"$");
             printf("Girilen kelime sonuna '$' isareti eklenmistir.");
         }
    }
    fclose(dosya);
    while(1)
    {
        printf("\nSecimler\n");
        printf("1->Suffix Tree olusturulabilirmi.\n");
        printf("2->%s katari icinde katar arama\n",text);
        printf("3->%s katari icinde tekrar eden en uzun alt katari bulma\n",text);
        printf("4->%s katari icinde en cok tekrar eden alt katari bulma\n",text);
        printf("5->cikis\n");
        int secim=0;
        printf("Bir secim yapiniz=...");
        scanf("%d",&secim);
        switch(secim)
        {
        case 1:
            if(hasSuffix(text)==0)
            {
                printf("\nHicbir suffix ve prefix esit olmadigindan Sonek Agaci Olusturulabilir.\n");
                char substring[strlen(text)][100];
                for(int i=0; i<strlen(text); i++)
                {
                    strcpy(substring[i],text+i);
                    char yedek[strlen(text)];
                    itoa(i+1,yedek,10);
                    strcat(substring[i]," ->[");
                    strcat(substring[i],yedek);
                    strcat(substring[i],"]");
                }
                for(int i=0; i<strlen(text); i++)
                {
                    if(substring[i][0]=='\0')
                    {
                        continue;
                    }
                    ilerle(substring[i]);
                    for(int j=i+1; j<strlen(text); j++)
                    {
                        if(substring[i][0]==substring[j][0])
                        {
                            dalla(substring[j]);
                            substring[j][0]='\0';
                        }
                    }
                }
                bastir();
            }
            else
            {
                printf("Sonek Agaci olusturulamaz.\n");

            }
            break;
        case 2:
            katarArama(text);
            break;
        case 3:
            tekrariEnUzunKatar(text);
            break;
        case 4:
            enCokTekrarEdenKatar(text);
            break;
        case 5:
            printf("Programdan cikiliyor...\n");
            exit(1);
            break;
        default :
            printf("Hatali Giris!\n");
        }
    }
    return 0;
}

