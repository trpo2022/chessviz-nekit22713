#include <stdio.h>
#define deskside 8

char desk[deskside][deskside] = {
	{'r', 'n', 'b', 'q', 'k', 'b', 'n', 'r'},
	{'p', 'p', 'p', 'p', 'p', 'p', 'p', 'p'},
	{' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '},
	{' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '},
	{' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '},
	{' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '},
	{'P', 'P', 'P', 'P', 'P', 'P', 'P', 'P'},
	{'R', 'N', 'B', 'Q', 'K', 'B', 'N', 'R'}};

void printdesk(char Desk[8][8])
{
	int i, j;
	for(i = 0; i < deskside; i++)
	{
		printf("%d", 8 - i);
		for (j = 0; j < deskside; j++)
		{
			printf(" %c", desk[i][j]);
		}
		printf("\n");
	}
	printf("  a b c d e f g h");
}


int main()
{
	printdesk(desk);
}
