#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include <string.h>

int mystrlen(char *first) {
    char *firstPointer = first; //uhvati pocetnu adresu
    while(*(++first)) //vrti do kraja stringa
        ;
    return first-firstPointer; //oduzmi adresu
}

void mystrcpy(char *first, char *second) {
    while(*second) { //dok se vrti drugi string
        *first++ = *second++; //kopiraj drugi u prvi
    }
    *first = '\0';
}

int mystrcmp(char *first, char *second) {

    while(*first) { //vrti do kraja prvog stringa
        if( (int)*first != (int)*second ){ //ako su razliciti vrati razliku
            return (int)*first - (int)*second;
        }
        first++;
        second++;
    }
    return (int)*first - (int)*second; //ako je drugi duzi od prvog ili su zavrsila oba vrtit
}

void mystrcat(char *first, char *second) {
    while(*++first) //dodi do kraja stringa
        ;
    while(*second) {
        *first++ = *second++; //stavljaj drugi string na kraj prvog
    }
    *first = '\0';
}

void reverse(char *first, char *second) {

    for(int i = strlen(first) -1 ; i >= 0; i--) { //len -1 jer je ukupna duzina 5 ali krecemo od indexa 0
        *second++ = *(first+i);
    }

    *second = '\0';
}

int *mystrstr(char *first, char *second) {

    char *firstPointer;
    char *secondPointer = second;
    int secondLength = strlen(second);
    int counter = strlen(second);

    while(*first++) {
        firstPointer = first; //sljedeci char koji usporedujemo
        while(*firstPointer++ == *second++) { //ako su jednaki charovi
            counter--; //dekrementiraj counter
            if(counter == 0) return firstPointer-secondLength; //kad je counter 0 vrati pointer na pocetak substringa
        }
        second = secondPointer; //ako nije naden substring, resetiraj counter i drugi string;
        counter = secondLength;
    }

    return NULL;
}

int main() {

    /* ---- mystrlen PROVJERA ---- */
    //char str[] = "testiram";
    //printf("duzina stringa %s je %d\n", str, mystrlen(str));
    /* ---- mystrcpy PROVJERA ---- */
    //char str1[] = "test";
    //char str2[] = " 1234";
    //mystrcpy(str1, str2);
    //printf("rezultat kopiranja stringa: %s\n", str1);
    /* ---- mystrcmp PROVJERA ---- */
    //char str1[] = "teSt";
    //char str2[] = "test";
    //printf("rezultat usporedbe stringova %s i %s daje rezultat: %d\n", str1, str2, mystrcmp(str1,str2));
    /* ---- mystrcat PROVJERA ---- */
    //char str1[] = "test1";
    //char str2[] = "test2";
    //mystrcat(str1, str2);
    //printf("rezultat kopiranja drugog stringa na kraj prvog: %s\n", str1);
    /* ---- reverse PROVJERA ---- */
    //char str1[] = "testiram";
    //char str2[] = "12345";
    //reverse(str1, str2);
    //printf("rezultat kopiranja naopakog prvog stringa u drugi string: %s\n", str2);
    /* ---- mystrstr PROVJERA ---- */
    //char str1[] = "123123born aje bborna test";
    //char str2[] = "borna";
    //char *p = mystrstr(str1, str2);
    //if(p != NULL)
        //printf("string %s nalazi se u string %s: %s\n",str2, str1, p);
    //else printf("nije pronaden podstring");

    return 0;
}
