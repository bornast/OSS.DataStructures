#include <stdbool.h>

bool choose_pivot;
int n_min;
int* generate(int n);

// selection sort
void selectionsort(int *niz, int n);

// insertion sort
void insertionsort(int *niz, int n);

// quick sort
int partition(int *niz, int n);

void quicksort(int *niz, int n);

// merge sort
void merge(int *niz, int *niza, int na, int *nizb, int nb);

// alocira i vra�a kopiju niza
int* duplicate(int *niz, int n);

void mergesort(int *niz, int n);

double measure(void(*sort)(int *niz, int n), int *niz, int n);
