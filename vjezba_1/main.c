#include <stdio.h>
#include <stdlib.h>

int* podniz(int *niz, int start, int stop) {
    int *newArr = (int*)malloc( (stop-start) *sizeof(int) );
    int j =0;
    for(int i = start; i < stop+1; i++,j++)
        newArr[j] = niz[i];
    return newArr;

}

int* filtriraj(int *niz, int n, int th, int *nth) {

    int *newArr = (int*)malloc(n * sizeof(int)); //alociraj duzinu niza jednaku duzini prvog, kasnije cemo realocirati ako je potrebno
    if(!newArr) {
        printf("ERROR");
        return NULL;
    }

    for(int i = 0; i < n; i++) { //spremaj sve u novi niz
        if(niz[i] < th) {
            newArr[*nth] = niz[i];
            (*nth)++;
        }
    }
    if(*nth != n) //realociraj ako je novonastali niz kraci od prvog
        newArr = realloc(newArr,*nth*sizeof(int));
    return newArr;
}

int** podijeli(int *niz, int n) {
    int arrCount = n/2; //duzina pojedinacnog niza je pola od ukupnog
    int *firstArr = (int*)malloc(arrCount * sizeof(int));
    int *secondArr = (int*)malloc(arrCount * sizeof(int));
    int **pointerArray = (int**)malloc(2 * sizeof(int*));

    for(int i = 0, j = 0; i < arrCount * 2; i++) { //(n/2) *2 jer je 9/2 = 4.5 => 4 * 2 = 8 sto znaci da ne koristimo zadnji clan u slucaju da je niz neprane duzine
        if(i < arrCount) firstArr[i] = niz[i];
        else secondArr[j] = niz[i], j++;
    }
    pointerArray[0] = firstArr;
    pointerArray[1] = secondArr;
    return pointerArray;

}

typedef struct {
    float x;
    float y;
}Tocka;

typedef struct {
    Tocka niz_vrhova[100];
    int n;
}Poligon;

Poligon* novi_poligon(float *niz_x, float *niz_y, int n) {
    if(n < 3) return NULL;
    Poligon *newPoligon = (Poligon*)malloc(sizeof(Poligon));
    for(int i = 0; i < n; i++) {
        newPoligon->niz_vrhova[i].x = niz_x[i];
        newPoligon->niz_vrhova[i].y = niz_y[i];
        newPoligon->n = n;
    }

    return newPoligon;
}

Tocka** pozitivni(Poligon *p, int *np)  {
    Tocka **poz = (Tocka**)malloc(p->n * sizeof(Tocka*));
    int j = 0;
    for(int i = 0; i < p->n; i++) {
        if(p->niz_vrhova[i].x > 0 && p->niz_vrhova[i].y > 0){
            poz[j] = &p->niz_vrhova[i];
            j++;
            *np+=1;

        }
    }
    return poz;

}

int main()
{

    /* ---- PODNIZ PROVJERA ---- */
    /*int arr[] = {1,2,3,4,5,6,7,8};
    int start = 3;
    int stop = 6;
    stop +=1; //jer zelimo dohvatit i vrijednost na indexu od stopa
    int *newArr = podniz(arr, 3, 6);
    for(int i = 0; i < (stop-start); i++) {
        printf("%d\n", newArr[i]);
    }
    free(newArr);*/
    /* ---- FILTRIRAJ PROVJERA ----- */
    /*int arr1[] = {1,2,3,4,5,6,7,8};
    int arr1Count = sizeof(arr1) / sizeof(int);
    int arr1Restriction = 5;
    int newSize = 0;
    int *newArr = filtriraj(arr1,arr1Count, arr1Restriction, &newSize);
    free(newArr);*/
    /* ---- PODIJELI PROVJERA ----- */
    /*int arr2[] = {1,2,3,4,5,6,7};
    int arr2Count = sizeof(arr2) / sizeof(int);
    int **newArr = podijeli(arr2, arr2Count);
    for(int i = 0; i < 2; i++) {
        for(int j = 0; j < arr2Count/2; j++) {
            printf("%d\t", newArr[i][j]);
        }
    }*/
    /* ---- NOVI POLIGON PROVJERA ----- PROUCIT I KOMENTIRAT*/
    /*float x[] = {2.1, 2.5, 2.7};
    float y[] = {5.1, 1.5, 7.7};
    int n = 3;
    Poligon *newPoligon = novi_poligon(&x, &y,3);
    for(int i = 0; i < n; i++) {
        printf("vrijednost x: %.2f\n", newPoligon->niz_vrhova[i].x);
        printf("vrijednost y: %.2f\n", newPoligon->niz_vrhova[i].y);
    }
    printf("vrijednost n: %.d\n", newPoligon->n);
    //free(newPoligon);*/
    /* ---- POZITIVNI PROVJERA ----- */
    /*int np = 0;
    Tocka **t = pozitivni(newPoligon, &np);
    printf("vrijednost od t %.2f\n", t[1]->x);
    printf("vrijednost adrese od t %p\n", &newPoligon->niz_vrhova[1].x);
    printf("vrijednost adrese od t %p\n", &t[1]->x);
    free(t);
    free(newPoligon);*/
    return 0;
}

