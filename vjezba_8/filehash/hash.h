#ifndef HASH_H
#define HASH_H

// pretinac kao element vezane liste
typedef struct Bin {
	char *word;
	struct Bin *next;
} Bin;

// tablica sa nizom pokazivaca na pretince, velicinom niza i brojem unesenih zapisa
typedef struct {
	Bin **table;
	int size, load;
} HashTable;

unsigned int hash(char *word);

HashTable *NewTable(int size);

void Insert(HashTable *ht, char *word);

int Get(HashTable *ht, char *word);

void DeleteTable(HashTable *ht);

#endif