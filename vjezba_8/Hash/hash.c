#include "hash.h"
#include <malloc.h>
#include <stdio.h>
#include <string.h>

#define HCONST 3567892

HashTable *NewTable(int size)
{
	// kreira novu hash tablicu (alocira samu strukturu i niz pokaziva�a)
	HashTable *dict = (HashTable*)malloc(sizeof(HashTable));
	dict->table = (Bin**)malloc(sizeof(Bin*) * size);	
	dict->size = size;
	return dict;
}

unsigned int hash(char *word)
{
	// od kljuca generira hash kod
	unsigned int key = 0;
	while(*word != '\0')
	{
		key = key*HCONST + *word;
		word++;
	}
	return key;
}

void Insert(HashTable *ht, char *word)
{
	// dodaje novu rijec u listu na odgovarajucem pretincu
	unsigned int key = hash(word)%ht->size;
	if(ht->table[key] == NULL) ht->table[key] = NewItem(word);
	else {
		Bin *item = ht->table[key];
		while(item->next != NULL) {
			item = item->next;
		}
		item->next = NewItem(word);
	}

}

int Get(HashTable *ht, char *word)
{
	// vraca 0 ili 1 ovisno o tome da li rijec postoji u tablici
	unsigned int key = hash(word)%ht->size;
	Bin *item = ht->table[key];
	if(item != NULL) {

		if(strcmp(item->word, word) == 0 ) return 1;
		else {
			while(item->next != NULL) {
				if(strcmp(item->word, word) == 0 ) return 1;
				item = item->next;
			}
		}
	}

	return 0;
}

void DeleteTable(HashTable *ht)
{
	// brise cijelu hash tablicu (liste na svim pretincima (rijec i element liste), pretince ...)
	for(int i = 0; i < ht->size; i++) {
		Bin *item = ht->table[i];
		while(item != NULL) {
			Bin *obrisi = item;
			item = item->next;
			free(obrisi->word);
			free(obrisi);
		}
	}
	free(ht->table);
	free(ht);
}

Bin *NewItem(char *word) {
	Bin *item = (Bin*)malloc(sizeof(Bin));
	item->word = word;
	item->next = NULL;
	return item;
}
