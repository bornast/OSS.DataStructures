#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void print_niz(int *niz, int n) {
  for(int i = 0; i < n; i++) {
    printf("%d\n", niz[i]);
  }
}

int* generiraj(int n) {
	int *niz = (int*)malloc(n * sizeof(int));
	niz[0] = rand() % 3;
	for (int i = 1; i < n; i++) {
		niz[i] = niz[i - 1] + 1 + rand() % 3;
	}
	return niz;
}

void shuffle(int *niz, int n) {
	for (int i = 0; i < n; i++) {
		int ia = i;
		int ib = rand() % n;
		int tmp = niz[ia];
		niz[ia] = niz[ib];
		niz[ib] = tmp;
	}
}

int *presjek(int *niz1, int n1, int *niz2, int n2, int *n3) {
  int *niz3 = (int*)malloc(n1* sizeof(int));
  for(int i = 0; i < n1; i++) {
    for(int j = 0; j < n2; j++) {
      if(niz1[i] == niz2[j]) {
        niz3[*n3] = niz1[i];
        (*n3)++;
        break;
      }
    }
  }
  niz3 = (int*)realloc(niz3, *n3 * sizeof(int));
  return niz3;
}

int cmpfunc(const void * a, const void * b) {
   return ( *(int*)a - *(int*)b );
}

int *presjek_sortirani(int *niz1, int n1, int *niz2, int n2, int *n4) {

  int *niz4 = (int*)malloc(n1 * sizeof(int));
  int *p;
  for(int i = 0; i < n1; i++) {
    p = (int*) bsearch (&(niz1[i]), niz2, n2, sizeof (int), cmpfunc);
    if(p != NULL){
      niz4[*n4] = *p;
      (*n4)++;
    }
  }
  niz4 = (int*)realloc(niz4, *n4 * sizeof(int));
  return niz4;
}

int main() {
	srand(time(NULL));

  int n1 = 30000, n2 = 10000, n3 = 0, n4 = 0, i = 1;
  int *niz1, *niz2, *niz3, *niz4;


  printf("---------------prvi krug---------------\n");
  for(;n2 <= 50000; n2+=5000){

    printf("%d:", i++);
    niz1 = generiraj(n1);
    niz2 = generiraj(n2);
    shuffle(niz1, n1);
    shuffle(niz2, n2);

    //izracun dva nesortirana niza

    clock_t start1 = clock();
    niz3 = presjek(niz1, n1, niz2, n2, &n3);
    clock_t end1 = clock();
    double time_spent1 = (double)(end1 - start1) / CLOCKS_PER_SEC;
    printf("Ukupno vrijeme izvršavanja za funckiju presjek: %f\n", (double)time_spent1);
    free(niz3);

    //izracun nesortiranog i sortiranog niza

    clock_t start2 = clock();
    qsort(niz2, n2, sizeof(int), cmpfunc);
    clock_t start3 = clock();
    niz4 = presjek_sortirani(niz1, n1, niz2, n2, &n4);
    clock_t end2 = clock();
    clock_t end3 = clock();
    double time_spent2 = (double)(end2 - start2) / CLOCKS_PER_SEC;
    double time_spent3 = (double)(end3 - start3) / CLOCKS_PER_SEC;
    printf("Ukupno vrijeme izvršavanja za funckiju presjek_sortirani ukljucujuci qsortom: %f\n", (double)time_spent2);
    printf("Ukupno vrijeme izvršavanja za funckiju presjek_sortirani ne ukljucujuci qsorta: %f\n", (double)time_spent3);
    free(niz4);



    free(niz1);
    free(niz2);
    n3 = 0;
    n4 = 0;
    printf("\n");
  }

  printf("---------------drugi krug---------------\n");
  n1 = 10000;
  n2 = 30000;
  for(;n1 <= 50000; n1+=5000){

    printf("%d:", i++);
    niz1 = generiraj(n1);
    niz2 = generiraj(n2);
    shuffle(niz1, n1);
    shuffle(niz2, n2);


    //izracun dva nesortirana niza
    clock_t start1 = clock();
    niz3 = presjek(niz1, n1, niz2, n2, &n3);
    clock_t end1 = clock();
    double time_spent1 = (double)(end1 - start1) / CLOCKS_PER_SEC;
    printf("Ukupno vrijeme izvršavanja za funckiju presjek: %f\n", (double)time_spent1);
    free(niz3);

    //izracun nesortiranog i sortiranog niza
    clock_t start2 = clock();
    qsort(niz2, n2, sizeof(int), cmpfunc);
    clock_t start3 = clock();
    niz4 = presjek_sortirani(niz1, n1, niz2, n2, &n4);
    clock_t end2 = clock();
    clock_t end3 = clock();
    double time_spent2 = (double)(end2 - start2) / CLOCKS_PER_SEC;
    double time_spent3 = (double)(end3 - start3) / CLOCKS_PER_SEC;
    printf("Ukupno vrijeme izvršavanja za funckiju presjek_sortirani ukljucujuci qsortom: %f\n", (double)time_spent2);
    printf("Ukupno vrijeme izvršavanja za funckiju presjek_sortirani ne ukljucujuci qsorta: %f\n", (double)time_spent3);
    free(niz4);



    free(niz1);
    free(niz2);
    n3 = 0;
    n4 = 0;
    printf("\n");
  }

  return 0;

}
