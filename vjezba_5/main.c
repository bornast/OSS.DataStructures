#include <stdio.h>
#include <ctype.h>
#include "dictionary.h"

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
	return 1;
}

void main()
{
	FILE *fd;
	char buffer[1024];
	Dictionary dict;

	fd = fopen("liar.txt", "rt");
	if(fd == NULL)
	{
		printf("Error opening file.\n");
		return;
	}

	dict = create();
	int i = 0;
	while(readWord(fd, buffer))
	{
		//printf("duzina stringa %s je %d\n", buffer, strlen(buffer));
		add(dict, buffer);
	}

	fclose(fd);

	printf("\n\n\n----------------prije filtriranja----------------\n\n\n");
	//print(dict);

	dict = filterDictionary(dict, filter);
	printf("\n\n\n----------------poslje filtriranja----------------\n\n\n");
	print(dict);
	//printf("najduza rijec je %s\n", pronadi_najduzu_rijec(dict));
	//printf("ukupan broj rijeci je %d\n", ukupan_broj_rijeci(dict));
	// char str[] = "test";
	// char str1[] = "asd";
	// dodaj_na_pocetak_liste(dict, str);
	// dodaj_na_kraj_liste(dict, str1);
	printf("\n\n\n----------------teeeesttt----------------\n\n\n");
	dict = okreni_listu(dict);
	print(dict);

	printf("\n\n\n----------------brisanje----------------\n\n\n");
	destroy(dict);
}
