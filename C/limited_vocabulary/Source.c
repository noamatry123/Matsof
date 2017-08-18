#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX_LINES 20
#define MAX_CHARS 256
#define ORIGINAL_WORD 0
#define _SYNONYM 1
void remove_newlines(char* str)
{
	int i = 0;
	while (str[i] != 0)
	{
		if (str[i] == '\n')
		{
			str[i] = 0;
			break;
		}
		i++;
	}
}
int main(int argc, char* argv[])
{
	if (argc != 3)
	{
		printf("Please enter exactly 2 arguments.");
		return 1;
	}
	else
	{
		//print args
		printf("args:\n%s\n%s\n", argv[1], argv[2]);
	}

	FILE* textfile = fopen(argv[1], "r");
	FILE* synonymsfile = fopen(argv[2], "r");
	if (!textfile || !synonymsfile)
	{
		printf("Error %d \n", errno);
		getchar();
		return 1;
	}
	//print file to screen
	char buffer[256], *line;
	char file[MAX_LINES][MAX_CHARS] = {0};
	char new_file[MAX_LINES][MAX_CHARS] = { 0 };
	char synonym_file[MAX_CHARS][MAX_CHARS] = { 0 };
	char synonym_discionary[MAX_CHARS][MAX_CHARS] = { 0 };
	int lines_i = 0;
	//getting text file.
	while (1)
	{
		if ((line=fgets(buffer, MAX_CHARS, textfile)) == NULL)
			break;
		printf("%s", line);
		strcpy(file[lines_i], line);
		lines_i++;
	}
	//getting synonyms dictionary
	int syns_num = 0;
	while (1)
	{
		if ((line = fgets(buffer, MAX_CHARS, synonymsfile)) == NULL)
			break;
		//printf("%s", line);
		remove_newlines(line);
		strcpy(synonym_file[syns_num], line);
		syns_num++;
	}
	printf("\n\n");

	//lets get to splitting.
	//first iterate every word per every line..
	for (int i = 0; i < lines_i; i++)
	{
		//now iterate every work using strtok
		for (char *tok = strtok(file[i], " "); tok != NULL; tok = strtok(NULL, " "))
		{
			//now we need to check for swap.
			//int tok_length = strlen(tok);
			for (int j = 0; j < syns_num; j+=2)
			{
				if (!strcmp(tok, synonym_file[j])) //we have a match
					tok = synonym_file[j + 1];
			}
			strcat(new_file[i], tok);
			strcat(new_file[i], " ");
		}
		printf(new_file[i]);
	}

	_fcloseall();
	getchar();
	return 0;
}