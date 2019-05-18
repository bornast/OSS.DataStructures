#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "sortiranja.h"

int main() {

  srand(time(NULL));
  int n1 = 1000 + rand()%9000;
  int *niz1 = generate(n1);
  int n2 = 1000 + rand()%9000;
  int *niz2 = generate(n2);
  // vrijeme izvodenja s pivotom
  choose_pivot = true;
  double vrijeme1 = measure(quicksort, niz1, n1);
  double vrijeme2 = measure(quicksort, niz1, n1);
  printf("vrijeme sortiranja ne sortirang niza s odabiron pivota je %f\n", vrijeme1);
  printf("vrijeme sortiranja sortirang niza s odabiron pivota je %f\n", vrijeme2);

  //vrijeme izvodenja bez pivota
  choose_pivot = false;
  double vrijeme3 = measure(quicksort, niz2, n2);
  double vrijeme4 = measure(quicksort, niz2, n2);
  printf("vrijeme sortiranja ne sortirang niza bez odabira pivota je %f\n", vrijeme1);
  printf("vrijeme sortiranja sortirang niza bez odabira pivota je %f\n", vrijeme2);

  free(niz1);
  free(niz2);

}
