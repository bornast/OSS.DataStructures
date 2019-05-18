#include <stdio.h>
#include <malloc.h>
#include <ctype.h>
#include "bstree.h"

BSTree NewBSTree()
{
	// Novo prazno stablo
	return NULL;
}

void AddNode(BSTree *bst, char *word)
{
	// Rekurzivno se tra�i mjesto za novi �vor u stablu. Ako rije� postoji u stablu, ne dodaje se.
	// bst parametar je dvostruki pokaziva�.
	if(*bst == NULL) {
		return CreateNode(bst, word);
	}
	else if(strcmp((*bst)->word, word) > 0) {
		return AddNode(&(*bst)->left, word);
	}
	else if(strcmp((*bst)->word, word) < 0) {
		return AddNode(&(*bst)->right, word);
	}
}

void CreateNode(BSTree *bst, char *word)
{
	*bst = (BSTree)malloc(sizeof(Node));
	(*bst)->left = NULL;
	(*bst)->right = NULL;
	(*bst)->word = word;
}

int wordSearch(BSTree *bst, char *word)
{
	if(*bst == NULL) return 0;
	else if(strcmp((*bst)->word, word) > 0) return wordSearch(&(*bst)->left, word);
	else if(strcmp((*bst)->word, word) < 0) return wordSearch(&(*bst)->right, word);
	else return 1;
}

int BSTHeight(BSTree bst)
{
	// Rekurzivno se prolazi cijelo stablo da bi se prona�la najdu�a grana (visina stabla).
	if (bst == NULL) return 0;

	int dubina_lijevih = BSTHeight(bst->left);
	int dubina_desnih = BSTHeight(bst->right);

	if (dubina_lijevih > dubina_desnih) return(dubina_lijevih + 1);
	else return(dubina_desnih + 1);
}

void PrintBSTree(BSTree bst)
{
	// Ispisuje rije�i u stablu na ekran po abecednom redu.
	// In-order �etnja po stablu (lijevo dijete, �vor, desno dijete)
	if (bst == NULL) return;
	PrintBSTree(bst->left);
	printf("%s ", bst->word);
	PrintBSTree(bst->right);
}

void SaveBSTree(BSTree bst, FILE *fd)
{
	// Snima rije� po rije� iz stabla u tekstualnu datoteku. Rije�i su odvojene razmakom.
	// Pre-order �etnja po stablu (ttenutni �vor pa djeca)
	if(bst == NULL) return;
	fprintf(fd, "%s ", bst->word);
	SaveBSTree(bst->left, fd);
	SaveBSTree(bst->right, fd);

}

void DeleteBSTree(BSTree bst)
{
	// Bri�e stablo (string word i sam �vor) iz memorije.
	// Post-order �etnja po stablu (prvo djeca pa trenutni �vor)
	if(bst == NULL) return;
	DeleteBSTree(bst->left);
	DeleteBSTree(bst->right);
	// printf("\n Briše se čvor: %s", bst->word);

	free(bst->word);
	free(bst);
}

BSTree LoadBSTree(FILE *fd)
{

	// U�itava rije� po rije� iz tekstualne datoteke i dodaje ih u stablo preko AddNode() funkcije.
	// Rije� duplicirati sa strdup().
	BSTree bst;
	bst = NewBSTree();
	char buffer[1024];
	while(readWord(fd, buffer))
	{
		printf("%s\n", buffer);
		AddNode(&bst, strdup(buffer));
	}
	return bst;
}

int readWord(FILE *fd, char *buffer)
{
	int c;

	do {
		c = fgetc(fd);
		if(c == EOF)
			return 0;
	} while(!isalpha(c));

	do {
		*buffer = tolower(c);
		buffer++;
		c = fgetc(fd);
		if(c == 146)
			c = '\'';
	} while(isalpha(c) || c == '\'');

	*buffer = '\0';
}




void ispisatiKojeZavrsavaju(BSTree bst) {
	if(bst == NULL) return;
	ispisatiKojeZavrsavaju(bst->left);
	ispisatiKojeZavrsavaju(bst->right);
	if(bst->word[strlen(bst->word)-1] == 'a' ) {
		printf("%s\n", bst->word);
	}


}
