#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>
//definicia makra
#define MAX 200
//definicia funkcii
char* desiatkova_binarna(char *cislo);
long long int binarna_desiatkova(char *cislo);
char* binarna_osmickova(char*cislo);
int kontrola2(char cislo[]);
int kontrola10(char cislo[]);
char* binarna_sestnastkova(char* cislo);
int main(void)
{
    char predvolba;
    char cislo[MAX];

    while(1)
    {
        //menu
        printf("|--------------------------------|\n");
        printf("| Zadajte volbu konverzie cisel: |\n");
        printf("| 1:Z desiatkovej do binarnej    |\n");
        printf("| 2:Z binarnej do desiatkovej    |\n");
        printf("| 3:Z binarnej do osmickovej     |\n");
        printf("| 4:Z binarnej do sestnastkovej  |\n");
        printf("| Q:  Koniec programu            |\n");
        printf("|________________________________|\n");
        scanf("%c",&predvolba);
        fflush(stdin);
        system("cls");
        if (predvolba=='q' || predvolba=='Q')
        {
            printf("Koniec programu.\n");
            break;
        }
        switch (predvolba)
        {
        //vypisy, ovladaniie menu a programu, cistenia obrazovky
        case '1':
            printf("zadajte desiatkove cislo v pripade neuspechu budete musiet zadat znova\n");
            scanf("%s",cislo);
            fflush(stdin);
            if (kontrola10(cislo)==1)
            {
                printf("Binarne cislo je %s\n",desiatkova_binarna(cislo));
                fflush(stdin);
                printf("Stlacte klaves pre pokracovanie\n");
                getch();
                system("cls");
            }
            else
            {
                printf("Cislo je chybne,pre navrat do menu stlacte klavesu\n");
                getch();
                system("cls");
                continue;
            }
            break;
        case '2':
            printf("Zadajte dvojkove cislo v pripade neuspechu budete musiet zadat znova\n");
            scanf("%s",cislo);
            fflush(stdin);
            if (kontrola2(cislo)==1)
            {
                printf("Desiatkove cislo je %lld\n",binarna_desiatkova(cislo));
                fflush(stdin);
                printf("Stlacte klaves pre pokracovanie\n");
                getch();
                system("cls");
            }
            else
            {
                printf("Cislo je chybne,pre navrat do menu stlacte klavesu\n");
                getch();
                system("cls");
                continue;
            }
            break;
        case '3':
            printf("Zadajte dvojkove cislo v pripade neuspechu budete musiet zadat znova\n");
            scanf("%s",cislo);
            fflush(stdin);
            if (kontrola2(cislo)==1)
            {
                printf("Osmickove cislo je %s\n",binarna_osmickova(cislo));
                fflush(stdin);
                printf("Stlacte klaves pre pokracovanie\n");
                getch();
                system("cls");
            }
            else
            {
                printf("Cislo je chybne,pre navrat do menu stlacte klavesu\n");
                getch();
                system("cls");
                continue;
            }
            break;
        case '4':
            printf("Zadajte dvojkove cislo v pripade neuspechu budete musiet zadat znova\n");
            scanf("%s",cislo);
            fflush(stdin);
            if (kontrola2(cislo)==1)
            {
                printf("Sestnastkove cislo je %s\n",binarna_sestnastkova(cislo));
                fflush(stdin);
                printf("Stlacte klaves pre pokracovanie\n");
                getch();
                system("cls");
            }
            else
            {
                printf("Cislo je chybne,pre navrat do menu stlacte klavesu\n");
                getch();
                system("cls");
                continue;
            }
            break;

        default:

            printf("Neplatna volba, zadajte znova, pre pokraovanie stlacte klavesu\n");
            getch();
            system("cls");
            continue;
            break;
        }
    }
    return 0;
}
//funkcia na kontrolovanie desiatkoveho cisla
int kontrola10(char cislo[])
{
    int i;
    int dlzka, kontrola;
    dlzka=strlen(cislo);
    //kontrola spravnosti cisla

    for (i=0; i<dlzka; i++)
    {
        if (cislo[i]<'0' || cislo[i]>'9')
        {
            kontrola=0;
            break;
        }
        else
            kontrola = 1;
    }
    return kontrola;
}
//kontrola dvojkovych cisel
int kontrola2(char cislo[])
{
    int i;
    int dlzka, kontrola;
    dlzka=strlen(cislo);
    for (i=0; i<dlzka; i++)
    {

        if (cislo[i]<'0' || cislo[i]>'1')
        {
            kontrola=0;
            break;
        }
        else
            kontrola = 1;
        //kontrola pretecenia long long int cez strlen
        if (kontrola==1)
            if (dlzka>63)
                kontrola=0;
            else
                kontrola=1;
        if (kontrola==1)
            // kontrola zaciatocnej nuly
            if (cislo[0]=='0'&& dlzka>1)
                kontrola=0;
            else
                kontrola=1;
    }
    return kontrola;
}
//funkcia konvertuje desiatkove na binarne
char* desiatkova_binarna(char *cislo)
{
    int i;
    int j=0;
    int repeat=0;
    int realokacia=1;
    long long int num;
    int* zvysok;
    char* navratove_cislo;
    zvysok=(int*) calloc(realokacia,sizeof(int));
    if(zvysok == NULL)
    {
        printf("Nedostatok pamate calloc.\n");
        exit(1);
    }
    num=  atoll(cislo);

//vypocet zvyskov, teda binarnych cisel
    do
    {
        zvysok[repeat]=num%2;
        num=num/2;
        repeat++;
        if (repeat+1>=realokacia)
        {
            realokacia=3*repeat;
            zvysok=(int*) realloc(zvysok,realokacia*sizeof(int));
            if(zvysok == NULL)
            {
                printf("Nedostatok pamate realloc.\n");
                exit(1);
            }
        }
    }
    while (num > 0);
    navratove_cislo = (char*) calloc(2*repeat,sizeof(char));
    if(navratove_cislo == NULL)
    {
        printf("Nedostatok pamate calloc.\n");
        exit(1);
    }


//prevod vystupneho cisla na string
    for (i=repeat-1; i>=0; i--)
    {
        if (zvysok[i]==0)
        {
            navratove_cislo[j]='0';
        }
        else
            navratove_cislo[j]='1';
        j++;
    }
    navratove_cislo[repeat]='\0';
    //uvolnenie pamate a navrat retazca cez pointer
    free(  (void *)  zvysok);
    zvysok=NULL;
    return navratove_cislo;
}
//vypocet desiatkoveho cisla z binmarneho
long long int binarna_desiatkova(char *cislo)
{
    long long int pom_mocnina=1;
    int i, dlzka;
    int* konvertovane_cislo;
    long long int navratove_cislo=0;
    dlzka=strlen(cislo);

    konvertovane_cislo = ( int*)calloc(dlzka, sizeof(int));
    if(konvertovane_cislo == NULL)
    {
        printf("Nedostatok pamate calloc.\n");
        exit(1);
    }//konverzia retazca na pole int
    for (i=0; i<dlzka; i++)
    {
        if (cislo[i]=='0')
            konvertovane_cislo[i]=0;
        else
            konvertovane_cislo[i]=1;
    }
    for (i=dlzka-1; i>=0; i--)
    {
        navratove_cislo=navratove_cislo+(konvertovane_cislo[i]*pom_mocnina);
        pom_mocnina= pom_mocnina*2;
    }
//uvolnenie pamate a navrat retazca cez pointer
    free(  (void *)  konvertovane_cislo);
    konvertovane_cislo=NULL;
    return navratove_cislo;
}
//vzpocey osmickoveho cisla z binarneho
char* binarna_osmickova(char*cislo)
{
    int k=0;
    int i, j, dlzka, dlzka_kon, dlzka_ret,  pom;
    const int pom_mocnina[]= {4,2,1};
    int* konvertovane_cislo;
    int* navratove_cislo_int;
    char* navratove_cislo_char;
    dlzka=strlen(cislo);
    pom=3-(dlzka%3);
    //dlzka pola pre konvertovany string niekedy je nutne pridat nuly na zaciatok
    if (dlzka%3!=0)
        dlzka_kon=dlzka+pom;
    else
        dlzka_kon=dlzka;
    dlzka_ret=dlzka_kon/3;

    konvertovane_cislo = (int*)calloc(dlzka_kon, sizeof(int));
    if(konvertovane_cislo == NULL)
    {
        printf("Nedostatok pamate calloc.\n");
        exit(1);
    }
//inicializacie navratovzch hodnot
    navratove_cislo_char = (char*)calloc((2*dlzka_ret), sizeof(char));
    if(navratove_cislo_char == NULL)
    {
        printf("Nedostatok pamate calloc.\n");
        exit(1);
    }
    navratove_cislo_int = (int*)calloc((1+dlzka_ret), sizeof(int));
    if(navratove_cislo_int == NULL)
    {
        printf("Nedostatok pamate calloc.\n");
        exit(1);
    }
//pridanie zaciatocnych nul a konverzia
    if (dlzka%3!=0)
    {
        for(i=0; i<pom; i++)
            konvertovane_cislo[i]=0;
        j=0;
        for (i=pom; i<dlzka_kon; i++)
        {
            if (cislo[j]=='0')
                konvertovane_cislo[i]=0;
            else
                konvertovane_cislo[i]=1;
            j++;
        }
    }
//konverzia zavisla na dlzke vstupu
    if (dlzka%3==0)
        for (i=0; i<dlzka; i++)
        {
            if (cislo[i]=='0')
                konvertovane_cislo[i]=0;

            else
                konvertovane_cislo[i]=1;
        }
//vypocet jednotlivych osmickovych cislic
    for (i=0; i<dlzka_ret; i++)
    {
        for (j=0; j<3; j++)
        {
            navratove_cislo_int[i]=navratove_cislo_int[i]+(konvertovane_cislo[k]*pom_mocnina[j]);
            k++;
        }
    }
//prevod pola int na retazec
    for (i=0; i<dlzka_ret; i++)
    {
        navratove_cislo_char[i]=navratove_cislo_int[i]+48;
    }
//uvolnenie pamate a navrat retazca cez pointer
    free(  (void *)  navratove_cislo_int);
    navratove_cislo_int=NULL;
    free(  (void *)  konvertovane_cislo);
    konvertovane_cislo=NULL;
    navratove_cislo_char[dlzka_ret]='\0';
    return navratove_cislo_char;
}

//funcia vypocita sestnastkove cislo z binarneho
char* binarna_sestnastkova(char* cislo)
{
    int k=0;
    int i, j, dlzka, dlzka_kon, dlzka_ret,  pom;
    const int pom_mocnina[]= {8,4,2,1};
    int* konvertovane_cislo;
    int* navratove_cislo_int;
    char* navratove_cislo_char;
    dlzka=strlen(cislo);
    pom=4-(dlzka%4);
    //dlzka zavisla od vstupu, uprava pre vypocet
    if (dlzka%4!=0)
        dlzka_kon=dlzka+pom;
    else
        dlzka_kon=dlzka;
//dlzka navratoveho retazca
    dlzka_ret=dlzka_kon/4;
    konvertovane_cislo = (int*)calloc(dlzka_kon, sizeof(int));
    if(konvertovane_cislo == NULL)
    {
        printf("Nedostatok pamate calloc.\n");
        exit(1);
    }

    navratove_cislo_char = (char*)calloc((2*dlzka_ret), sizeof(char));
    if(navratove_cislo_char == NULL)
    {
        printf("Nedostatok pamate calloc.\n");
        exit(1);
    }
    //alokacia cisla pre navrat
    navratove_cislo_int = (int*)calloc((dlzka_ret), sizeof(int));
    if(navratove_cislo_int == NULL)
    {
        printf("Nedostatok pamate calloc.\n");
        exit(1);
    }
//konverzia na pole int pridavanie nul na zaciatok podla dlzky
    if (dlzka%4!=0)
    {
        for(i=0; i<pom; i++)
            konvertovane_cislo[i]=0;

        j=0;
        for (i=pom; i<dlzka_kon; i++)
        {
            if (cislo[j]=='0')

                konvertovane_cislo[i]=0;

            else
                konvertovane_cislo[i]=1;

            j++;
        }
    }
//nuly sa nepridavaju
    if (dlzka%4==0)
        for (i=0; i<dlzka; i++)
        {
            if (cislo[i]=='0')
                konvertovane_cislo[i]=0;

            else
                konvertovane_cislo[i]=1;
        }
//vypocet jednotliych cisel
    for (i=0; i<dlzka_ret; i++)
    {
        for (j=0; j<4; j++)
        {
            navratove_cislo_int[i]=navratove_cislo_int[i]+(konvertovane_cislo[k]*pom_mocnina[j]);
            k++;
        }
    }
//prevod pola int na retazec
    for (i=0; i<dlzka_ret; i++)
    {
        navratove_cislo_char[i]=navratove_cislo_int[i]+48;
        switch (navratove_cislo_int[i])
        {
        case 10:
            navratove_cislo_char[i]='A';
            break;
        case 11:
            navratove_cislo_char[i]='B';
            break;
        case 12:
            navratove_cislo_char[i]='C';
            break;
        case 13:
            navratove_cislo_char[i]='D';
            break;
        case 14:
            navratove_cislo_char[i]='E';
            break;
        case 15:
            navratove_cislo_char[i]='F';
            break;
        }
    }
    //uvolnenie pamate a navrat retazca cez pointer a ukoncovacia nula
    navratove_cislo_char[dlzka_ret]='\0';
    free(  (void *)  navratove_cislo_int);
    navratove_cislo_int=NULL;
    free(  (void *)  konvertovane_cislo);
    konvertovane_cislo=NULL;
    return navratove_cislo_char;
}
