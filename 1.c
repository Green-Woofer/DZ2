#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <malloc.h>
#include <stdlib.h>
#include <string.h>
#include <locale.h>
#pragma warning(disable : 4996)

int main()
{
<<<<<<< HEAD
	system("chcp 1251");
	system("cls");
	char cc;
	int k = 1;
	int n;
	int length = 0;	//n - height, length - length
	int ones_in_column;
	FILE* file;
	int sum = 1;

=======
	system("chcp 1251");        
	system("cls");				
	char cc;				
	int k = 1;						
	int n;
	int length = 0;	//n - height, length - length
	int ones_in_column;                   
	FILE* file;					
	int sum = 1;

	
	//			Input
	printf("Enter number of dots: ");
	scanf_s("%d", &n);	
>>>>>>> 3f078fd31e02f314cd3772d874a0fb2d59aaaee6

	//			Input
	printf("Enter number of dots: ");
	scanf_s("%d", &n);


	int** a = (int**)malloc(n * sizeof(int*));
	for (int arr = 0; arr < n; arr++)
	{
		a[arr] = (int*)malloc(sizeof(int));
	}
<<<<<<< HEAD
	cc = getchar();
=======
	cc = getchar();									
>>>>>>> 3f078fd31e02f314cd3772d874a0fb2d59aaaee6
	for (int i = 0; i < n; i++)
	{
		printf("%d  : ", i);
		cc = getchar();
		for (int j = 0; cc != '\n'; j++)
		{
			if ((cc == '1') || (cc == '0'))
			{
				a[i] = (int*)realloc(a[i], sizeof(int) * k);
				a[i][k - 1] = (int)cc - '0';
				k++;
			}
			cc = getchar();
		}
		cc = '\0';
		length = k - 1;
		k = 1;
	}
	printf("\n\n");
<<<<<<< HEAD

=======
	
>>>>>>> 3f078fd31e02f314cd3772d874a0fb2d59aaaee6
	//Output the table

	printf("\n\n   ");
	printf(" ");
	for (int lit = 'a'; lit < length + 'a'; lit++)
	{

		printf("  %c", lit);
	}
	printf("\n");
	for (int j = 1; j <= ((3 * length) + 8); j++)
	{
		printf("-");
	}
	printf("\n");

	for (int i = 0; i < n; i++)
	{
		printf("%i| ", (i + 1));
		for (int j = 0; j < length; j++)
		{
			printf("%3d", a[i][j]);
		}
		printf("\n");
	}
<<<<<<< HEAD

	//examine for connection

=======
	
	//examine for connection
	
>>>>>>> 3f078fd31e02f314cd3772d874a0fb2d59aaaee6
	int* flag = (int*)malloc(n * sizeof(int));
	flag[0] = 1;
	for (int i = 1; i < n; i++)
		flag[i] = 0;
	for (int i = 0; i < n; i++)
	{

		if (flag[i] == 1)
		{
<<<<<<< HEAD

=======
			
>>>>>>> 3f078fd31e02f314cd3772d874a0fb2d59aaaee6
			for (int j = 0; j < n; j++)
			{
				if (flag[j] != 1)
				{

					for (int m = 0; m < length; m++)
					{
						if ((a[i][m] == 1) && (a[j][m] == 1))
						{
							flag[j] = 1;
							sum++;

							break;
						}
					}
				}
			}
		}
	}
	if (sum == n)
		printf("Graph is connected\n");
	else printf("Graph is not connected");
<<<<<<< HEAD


=======
>>>>>>> 3f078fd31e02f314cd3772d874a0fb2d59aaaee6

	// Dot file

<<<<<<< HEAD
	if ((file = fopen("Dot_file.txt", "w")) == NULL) {
		printf("Cannot open file.\n");
		exit(1);
=======
	
	// Dot file
	
	if ((file = fopen("Dot_file.txt", "w")) == NULL) {		
		printf("Cannot open file.\n");						
		exit(1);											
>>>>>>> 3f078fd31e02f314cd3772d874a0fb2d59aaaee6
	}
	fprintf(file, "graph G{\n");


	int t = -1;
	ones_in_column = 0;
<<<<<<< HEAD

	int zero = 0;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < length; j++) {
			if (a[i][j] == 1)
				zero = 1;
		}
		if (zero == 0)
			fprintf(file, "%d;\n", (i + 1));
		zero = 0;
	}

	for (int j = 0; j < length; j++)
	{
		for (int i = 0; i < n; i++)
=======
	for (int j = 0; j < length; j++)			
	{
		for (int i = 0; i < n; i++)				
>>>>>>> 3f078fd31e02f314cd3772d874a0fb2d59aaaee6
		{
			if ((a[i][j] == 1) && (ones_in_column > 2))

			{
				printf("One edge cannot connect more than 2 graphs");
				exit(-1);
			}
			else
			{
				if ((a[i][j] == 1) && (ones_in_column == 0))
				{
					fprintf(file, "%d", (i + 1));
					fprintf(file, " -- ");
					ones_in_column++;
					t = i;
				}
				else
				{
					if ((a[i][j] == 1) && (ones_in_column == 1))
					{
						fprintf(file, "%d", (i + 1));
						fprintf(file, " [label=%c];\n", (('a' - 1) + j + 1));
						ones_in_column++;
					}
				}
			}
		}
		if (ones_in_column == 1)
		{
			fprintf(file, "%d", (t + 1));
			fprintf(file, " [label=%c];\n", (('a' - 1) + t + 1));
		}
		ones_in_column = 0;
		t = -1;
	}
	fprintf(file, "}");
	fclose(file);
	system("dot C:\\Projects\\DZ2\\Dot_file.txt -Tbmp -o Dot_file.bmp");
	system("rundll32  \"%ProgramFiles%\\Windows Photo Viewer\\PhotoViewer.dll\", ImageView_Fullscreen C:\\Projects\\DZ2\\Dot_file.bmp");

<<<<<<< HEAD

	for (int i = 0; i < n; i++)
=======
	for (int i = 0; i < n; i++) 
>>>>>>> 3f078fd31e02f314cd3772d874a0fb2d59aaaee6
	{
		free(a[i]);
	}
	free(a);
	getchar();
	return 0;
}
