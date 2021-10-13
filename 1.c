#define _CRT_SECURE_NO_WARNINGS
#define DEBUG 0
#include <stdio.h>
#include <malloc.h>
#include <stdlib.h>
#include <string.h>
#include <locale.h>
#pragma warning(disable : 4996)

int main()
{
	system("chcp 1251");        
	system("cls");				
	char cc;				
	int k = 1;						
	int i;
	int j;
	int n;
	int length = 0;	// n - ���������� �����, length - ���������� ����
	int ones_in_column;                   
	FILE* file;					
	int sum = 1;

	
	//				  ���� �������
	printf("������� ���������� �����: ");
	scanf_s("%d", &n);	

			
	int** a = (int**)malloc(n * sizeof(int*));		
	for (int arr = 0; arr < n; arr++)				
	{
		a[arr] = (int*)malloc(sizeof(int));
	}
	cc = getchar();									
	for (i = 0; i < n; i++)
	{
		printf("%d  : ", i);
		cc = getchar();								
		for (j = 0; cc != '\n'; j++)					
		{
			if ((cc == '1') || (cc == '0'))		
			{
				a[i] = (int*)realloc(a[i], sizeof(int) * k);
				(a[i])[k - 1] = (int)cc - '0';			
				k++;										
			}
			cc = getchar();	
		}
		cc = '\0';				
		length = k - 1;				
		k = 1;						
	}
	printf("\n\n");
	
	//�����  � �������

	printf("\n\n   ");
	printf(" ");
	for (int lit = 'a'; lit < length + 'a'; lit++)
	{
		
		printf("  %c", lit);
	}
	printf("\n");
	for (j = 1; j <= ((3 * length) + 8); j++)
	{
		printf("-");
	}
	printf("\n");

	for (i = 0; i < n; i++)
	{
		printf("%i| ", (i + 1));
		for (j = 0; j < length; j++)
		{
			printf("%3d", a[i][j]);
		}
		printf("\n");
	}
	
	//���������
	
	int* flag = (int*)malloc(n * sizeof(int));
	flag[0] = 1;
	for (i = 1; i < n; i++)
		flag[i] = 0;
	for (i = 0; i < n; i++)
	{
		
		if (flag[i] == 1)
		{
			
			for (j = 0; j < n; j++)
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
		printf("���� ������\n");
	else printf("���� �� ������");


	
	// ������ � dot ������
	
	if ((file = fopen("Dot_file.txt", "w")) == NULL) {		
		printf("Cannot open file.\n");						
		exit(1);											
	}
	fprintf(file, "graph G{\n");				


	int t = -1;							    
	ones_in_column = 0;
	for (j = 0; j < length; j++)			
	{
		for (i = 0; i < n; i++)				
		{
			if ((a[i][j] == 1) && (ones_in_column > 2))
																	  
			{
				printf("������ ������� ������ 2 ������� � �������");
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
	

	for (i = 0; i < n; i++) 
	{
		free(a[i]);
	}
	free(a);				
	getchar();
	return 0;
}