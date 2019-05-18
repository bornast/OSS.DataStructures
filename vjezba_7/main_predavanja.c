#include <stdio.h>

typedef struct _Tree {
	int b;
	struct _Tree *left;
	struct _Tree *right;
} Tree;

void ispisi(Tree *root) {
	// uvjet zaustavljana
	if (root == NULL)
		return;
	ispisi(root->left);
	printf("%d ", root->b);
	ispisi(root->right);
}
/*
void ispisi(Tree *root) {
	// uvjet zaustavljana
	//if (root == NULL)
	//	return;
	if (root->left != NULL)
		ispisi(root->left);
	printf("%d ", root->b);
	if (root->right != NULL)
		ispisi(root->right);
}
*/

int max(Tree *root) {
	if (root->right == NULL)
		return root->b;
	else
		return max(root->right);
}

int trazi(Tree *root, int b) {
	if (!root)
		return 0;
	if (root->b > b)
		return trazi(root->left, b);
	else if (root->b < b)
		return trazi(root->right, b);
	else
		return 1;
}

int trazi_iter(Tree *root, int b) {
	while (root != NULL) {
		if (root->b > b)
			root = root->left;
		else if (root->b < b)
			root = root->right;
		else
			return 1;
	}
	return 0;
}

void obrisi_najmanjeg(Tree *root) {
	if (root == NULL)
		return;
	if (root->left == NULL) {
		Tree *brisi = root;
		root = NULL; // nema efekta van funkcije
		// free(brisi);
	}
	if (root->left->left == NULL) {
		Tree *brisi = root->left;
		root->left = root->left->right;
		// free(brisi);
	}
	else {
		obrisi_najmanjeg(root->left);
	}
}

int prebroji_cvorove(Tree *root) {
	if (!root)
		return 0;
	int broj_lijevih = prebroji_cvorove(root->left);
	int broj_desnih = prebroji_cvorove(root->right);
	return 1 + broj_lijevih + broj_desnih;
}

void ispisi_listove(Tree *root) {
	if (!root)
		return;
	if (root->left == NULL && root->right == NULL) {
		printf("%d ", root->b);
		return;
	}
	ispisi_listove(root->left);
	ispisi_listove(root->right);
}

int prebroji_izmedju(Tree *root, int d, int g) {
	if (root == NULL)
		return 0;
	if (root->b < d) {
		int r = prebroji_izmedju(root->right, d, g);
		return r;
	}
	else if (root->b > g) {
		int l = prebroji_izmedju(root->left, d, g);
		return l;
	}
	else {
		int l = prebroji_izmedju(root->left, d, g);
		int r = prebroji_izmedju(root->right, d, g);
		return 1 + l + r;
	}
}


void main() {
	Tree root, b, c, d, e, f, g;
	root.b = 12;
	b.b = 8;
	c.b = 20;
	d.b = 5;
	e.b = 10;
	f.b = 15;
	g.b = 50;

	root.left = &b;
	root.right = &c;
	b.left = &d;
	b.right = &e;
	c.left = &f;
	c.right = &g;

	d.left = d.right = e.left = e.right = f.left = f.right = g.left = g.right = NULL;

	ispisi(&root);
	printf("\n");

	printf("%d\n", trazi_iter(&root, 25));
	printf("%d\n", trazi_iter(&root, 20));

	obrisi_najmanjeg(&root);
	ispisi(&root);
	printf("\n");

	printf("broj cvorova = %d\n", prebroji_cvorove(&root));

	printf("broj izmedju = %d\n", prebroji_izmedju(&root, 10, 30));
}
