#include "hash.h"
#include <malloc.h>
#include <stdio.h>
#include <string.h>

#define HCONST 3567891

unsigned int hash(char *word)
{
	// od kljuca generira hash kod na 32 bita
	unsigned int key = 0;
	while (*word != '\0') {
		key = key*HCONST + *word;
		word++;
	}
	return key;
}

HashTable *NewTable(int size)
{
	// kreira novu hash tablicu (alocira samu strukturu i niz pokazivaèa)
	// postaviti sve pretince (pokazivaèe) na NULL
	return NULL
}

void Insert(HashTable *ht, char *word)
{
	// dodaje novu rijec u listu na odgovarajucem pretincu
	// povecava load tablice
}

int Get(HashTable *ht, char *word)
{
	// vraca 0 ili 1 ovisno o tome da li rijec postoji u tablici
}

void DeleteTable(HashTable *ht)
{
	// brise cijelu hash tablicu: liste na svim pretincima (rijec i element liste), pretince i samu hash tablicu
}