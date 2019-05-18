#include "dictionary.h"
#include <string.h>
#include <stdlib.h>
#include <stdio.h>

// kreaira novi prazni rjecnik
Dictionary create() {
  Dictionary dictionary = (Dictionary)malloc(sizeof(Word));
  dictionary->next = NULL;
  dictionary->word = NULL;
  dictionary->count = 0;
  return dictionary;
};

// dodaje rijec ili uvecava broj pojavljivanja rijeci u rjecniku
// rijeci se dodaju u abecednom redu
void add(Dictionary dict, char *str) {

  Dictionary p = dict;
  Dictionary n = dict->next;

  Dictionary novi = (Dictionary)malloc(sizeof(Word));
  novi->word = (char*)malloc(sizeof(char) * (strlen(str) + 1));
  strcpy(novi->word, str);
  novi->count = 1;

  while(n != NULL) {
    if( strcmp(n->word,str) == 0) {
      n->count++;
      free(novi->word);
      free(novi);
      return;
    }
    else if( n->word == NULL || strcmp(n->word, str) > 0) {
      novi->next = n;
      p->next = novi;
      return;
    }
    n = n->next;
    p = p->next;
  }

  novi->next = NULL;
  p->next = novi;
}

// ispisuje sve rijeci i broj pojavljivanja svake rijeci
void print(Dictionary dict) {
  dict = dict->next;
  while(dict != NULL) {
    printf("string: %s, ponavljanja:%d\n", dict->word, dict->count);
    dict = dict->next;
  }
}

// briše cijeli rječnik
void destroy(Dictionary dict) {
  Dictionary tmp = dict;
  dict = dict->next;
  free(tmp);
  while(dict != NULL) {
    tmp = dict;
    dict = dict->next;
    free(tmp->word);
    free(tmp);
  }
}

Dictionary filterDictionary(Dictionary indict, int (*filter)(Word *w)) {

  Dictionary tmp = NULL;
  Dictionary p = indict;
  Dictionary n = indict->next;

  while(n != NULL) {
    if(filter(n) != 1) {
      p->next = n->next;
      free(n->word);
      free(n);
      n = p->next;
    }
    else {
      p = p->next;
      n = n->next;
    }
  }
  return indict;
}

int filter(Word *w) {
  if(w == NULL) return 0;
  if( (w->count > 5 && w->count < 10) && strlen(w->word) > 3 ){
    return 1;
  }
  else return 0;
}

char *pronadi_najduzu_rijec(Dictionary dict) {

  char *p = NULL;
  Dictionary n = dict->next;
  if(n == NULL) return p;
  p = n->word;

  while(n != NULL) {
    if(strlen(n->word) < strlen(p)) {
      p = n->word;
    }
    n = n->next;
  }

  return p;
}

int ukupan_broj_rijeci(Dictionary dict) {

	int ukupno = 0;
	while(dict != NULL) {
		ukupno += dict->count;
    dict = dict->next;
	}
	return ukupno;

}

void dodaj_na_pocetak_liste(Dictionary dict, char *str) {

  Dictionary n = dict->next;
  while(n != NULL) {
    if(strcmp(n->word, str) == 0 ) {
      return;
    }
    if(strcmp(n->word, str) > 0) break;
    n = n->next;
  }
  Dictionary nova = (Dictionary)malloc(sizeof(Word));
  nova->word = (char*)malloc(sizeof(char) * strlen(str) + 1);
  strcpy(nova->word, str);
  nova->count = 1;
  nova->next = dict->next;
  dict->next = nova;

}

void dodaj_na_kraj_liste(Dictionary dict, char *str) {

  Dictionary n = dict->next;
  while(n != NULL) {
    if(strcmp(n->word,str) == 0) return;
    n = n->next;
    dict = dict->next;
  }


  Dictionary nova = (Dictionary)malloc(sizeof(Word));
  nova->count = 1;
  nova->word = (char*)malloc(sizeof(char) * strlen(str) + 1);
  strcpy(nova->word, str);
  nova->next = NULL;
  dict->next = nova;
}

Dictionary okreni_listu(Dictionary dict) {

  Dictionary p = dict->next;
  if(p == NULL) return dict;
  Dictionary n = dict->next->next;
  Dictionary tmp = n;
  p->next = NULL;
  while(tmp != NULL) {
    tmp = tmp->next;
    n->next = p;
    p = n;
    n = tmp;
  }

  printf("!!!%s\n", p->word);
  dict->next = p;

  return dict;

}
