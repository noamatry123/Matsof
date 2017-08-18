#include <stdio.h>
#include <stdlib.h>
void printMatrix(char matrix[20][20])
{
	system("cls");
	for (int i = 0; i < 20; i++)
	{
		for (int j = 0; j < 20; j++)
		{
			//"fancy" printing
			if (matrix[i][j] == ' ')
				printf("%c ", matrix[i][j]);
			else
				printf("%c", matrix[i][j]);
		}
		printf("\n");
	}
}
int main()
{
	char matrix[20][20] = {
		{ ' ' , ' ' , ' ' , ' ' , ' ' , ' ' , ' ' , ' ' , ' ' , ' ' , ' ' , ' ' , ' ' , ' ' , ' ' , ' ' , ' ' , ' ' , ' ' , ' ' },
		{ ' ' , ' ' , ' ' , ' ' , ' ' , ' ' , ' ' , ' ' , ' ' , ' ' , ' ' , ' ' , ' ' , ' ' , ' ' , ' ' , ' ' , ' ' , ' ' , ' ' },
		{ ' ' , ' ' , ' ' , ' ' , ' ' , ' ' , ' ' , ' ' , ' ' , ' ' , ' ' , ' ' , ' ' , ' ' , ' ' , ' ' , ' ' , ' ' , ' ' , ' ' },
		{ ' ' , ' ' , ' ' , ' ' , ' ' , ' ' , ' ' , ' ' , ' ' , ' ' , ' ' , ' ' , ' ' , ' ' , ' ' , ' ' , ' ' , ' ' , ' ' , ' ' },
		{ ' ' , ' ' , ' ' , ' ' , ' ' , ' ' , ' ' , ' ' , ' ' , ' ' , ' ' , ' ' , ' ' , ' ' , ' ' , ' ' , ' ' , ' ' , ' ' , ' ' },
		{ ' ' , ' ' , ' ' , ' ' , ' ' , ' ' , ' ' , ' ' , ' ' , ' ' , ' ' , ' ' , ' ' , ' ' , ' ' , ' ' , ' ' , ' ' , ' ' , ' ' },
		{ ' ' , ' ' , ' ' , ' ' , ' ' , ' ' , ' ' , ' ' , ' ' , ' ' , ' ' , ' ' , ' ' , ' ' , ' ' , ' ' , ' ' , ' ' , ' ' , ' ' },
		{ ' ' , ' ' , ' ' , ' ' , ' ' , ' ' , '#' , ' ' , '#' , ' ' , ' ' , ' ' , ' ' , ' ' , ' ' , ' ' , ' ' , ' ' , ' ' , ' ' },
		{ ' ' , ' ' , ' ' , ' ' , ' ' , ' ' , ' ' , '#' , '#' , ' ' , ' ' , ' ' , ' ' , ' ' , ' ' , ' ' , ' ' , ' ' , ' ' , ' ' },
		{ ' ' , ' ' , ' ' , ' ' , ' ' , ' ' , ' ' , '#' , ' ' , ' ' , ' ' , ' ' , ' ' , ' ' , ' ' , ' ' , ' ' , ' ' , ' ' , ' ' },
		{ ' ' , ' ' , ' ' , ' ' , ' ' , ' ' , ' ' , ' ' , ' ' , ' ' , ' ' , ' ' , ' ' , ' ' , ' ' , ' ' , ' ' , ' ' , ' ' , ' ' },
		{ ' ' , ' ' , ' ' , ' ' , ' ' , ' ' , ' ' , ' ' , ' ' , ' ' , ' ' , ' ' , ' ' , ' ' , ' ' , ' ' , ' ' , ' ' , ' ' , ' ' },
		{ ' ' , ' ' , ' ' , ' ' , ' ' , ' ' , ' ' , ' ' , ' ' , ' ' , ' ' , ' ' , ' ' , ' ' , ' ' , ' ' , ' ' , ' ' , ' ' , ' ' },
		{ ' ' , ' ' , ' ' , ' ' , ' ' , ' ' , ' ' , ' ' , ' ' , ' ' , ' ' , ' ' , ' ' , ' ' , ' ' , ' ' , ' ' , ' ' , ' ' , ' ' },
		{ ' ' , ' ' , ' ' , ' ' , ' ' , ' ' , ' ' , ' ' , ' ' , ' ' , ' ' , ' ' , ' ' , ' ' , ' ' , ' ' , ' ' , ' ' , ' ' , ' ' },
		{ ' ' , ' ' , ' ' , ' ' , ' ' , ' ' , ' ' , ' ' , ' ' , ' ' , ' ' , ' ' , ' ' , ' ' , ' ' , ' ' , ' ' , ' ' , ' ' , ' ' },
		{ ' ' , ' ' , ' ' , ' ' , ' ' , ' ' , ' ' , ' ' , ' ' , ' ' , ' ' , ' ' , ' ' , ' ' , ' ' , ' ' , ' ' , ' ' , ' ' , ' ' },
		{ ' ' , ' ' , ' ' , ' ' , ' ' , ' ' , ' ' , ' ' , ' ' , ' ' , ' ' , ' ' , ' ' , ' ' , ' ' , ' ' , ' ' , ' ' , ' ' , ' ' },
		{ ' ' , ' ' , ' ' , ' ' , ' ' , ' ' , ' ' , ' ' , ' ' , ' ' , ' ' , ' ' , ' ' , ' ' , ' ' , ' ' , ' ' , ' ' , ' ' , ' ' },
		{ ' ' , ' ' , ' ' , ' ' , ' ' , ' ' , ' ' , ' ' , ' ' , ' ' , ' ' , ' ' , ' ' , ' ' , ' ' , ' ' , ' ' , ' ' , ' ' , ' ' },
	};
	printMatrix(matrix);

	//update matrix
	while (1)
	{
		char new_matrix[20][20];
		//initalize new matrix
		for (int i = 0; i < 20; i++)
		{
			for (int j = 0; j < 20; j++)
			{
				new_matrix[i][j] = ' ';
			}
		}
		//check old matrix
		for (int i = 0; i < 20; i++)
		{
			for (int j = 0; j < 20; j++)
			{
				int counter = 0;
				//account for edge travel.
				int up = i - 1, down = i + 1, left = j - 1, right = j + 1, curI = i, curJ=j;
				if (up == -1)
					up = 19;
				if (down == 20)
					down = 0;
				if (left == -1)
					left = 19;
				if (right == 20)
					right = 0;
				//8 checks
				if (matrix[up][left] == '#') //top left
					counter++;
				if (matrix[up][curJ] == '#') //top
					counter++;
				if (matrix[up][right] == '#') //top right
					counter++;
				if (matrix[curI][right] == '#') //right
					counter++;
				if (matrix[down][right] == '#') //down right
					counter++;
				if (matrix[down][curJ] == '#') //down
					counter++;
				if (matrix[down][left] == '#') //down left
					counter++;
				if (matrix[curI][left] == '#') //left
					counter++;
				//determine status
				if (counter == 3) //birth or survival
					new_matrix[i][j] = '#';
				else if (counter == 2 && matrix[i][j] == '#') //survival
					new_matrix[i][j] = '#';
				else //death
					new_matrix[i][j] = ' ';

			}
		}
		//make the switch
		for (int i = 0; i < 20; i++)
		{
			for (int j = 0; j < 20; j++)
			{
				matrix[i][j] = new_matrix[i][j];
			}
		}
		getchar();
		printMatrix(matrix);
	}
	getchar();
	return 0;
}