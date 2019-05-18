#ifndef TREE_H
#define TREE_H
#include <string.h>

// �vor stabla sa pokaziva�om na rije� i na djecu �vora
typedef struct Node {
	char *word;
	struct Node *left, *right;
} Node;

// Stablo odnosno pokaziva� na korijen stabla
typedef Node* BSTree;

BSTree NewBSTree();

void AddNode(BSTree *bst, char *word);

int BSTHeight(BSTree bst);

void PrintBSTree(BSTree bst);

void SaveBSTree(BSTree bst, FILE *fd);

void DeleteBSTree(BSTree bst);

BSTree LoadBSTree(FILE *fd);

void CreateNode(BSTree *bst, char *word);

int wordSearch(BSTree *bst, char *word);

int readWord(FILE *fd, char *buffer);

void ispisatiKojeZavrsavaju(BSTree bst);

#endif
