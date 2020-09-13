#include <stdio.h>
#include <iostream>
using namespace std;

int var1Ex1()
{
	FILE* file1;
	FILE* file2;
	fopen_s(&file1, "file1.txt", "r+");
	fopen_s(&file2, "file2.txt", "r+");

	int sizeMatrix1, sizeMatrix2;
	fscanf_s(file1, "%i", &sizeMatrix1);
	fscanf_s(file2, "%i", &sizeMatrix2);
	fseek(file1, 0, 0);
	fseek(file2, 0, 0);

	if (sizeMatrix1 != 3)
	{
		printf("Умножение матриц невозможно!");
		return 0;
	}
	else
	{
		printf("Матрицы умножать можно!\n");
	}

	int** Matrix1 = new int* [sizeMatrix1];
	for (int i = 0; i < sizeMatrix1; i++)
	{
		Matrix1[i] = new int[sizeMatrix1];
	}
	int** Matrix2 = new int* [sizeMatrix2];
	for (int i = 0; i < sizeMatrix2; i++)
	{
		Matrix2[i] = new int[sizeMatrix2];
	}


	printf(" Матрица 1:\n");
	for (int i = 0; i < sizeMatrix1; i++)
	{
		for (int j = 0; j < sizeMatrix1; j++)
		{
			fscanf_s(file1, "%i", &Matrix1[i][j]);
			printf(" %i  ", Matrix1[i][j]);
		}
		printf("\n");
	}
	printf("\n Матрица 2:\n");
	for (int i = 0; i < sizeMatrix2; i++)
	{
		for (int j = 0; j < sizeMatrix2; j++)
		{
			fscanf_s(file2, "%i", &Matrix2[i][j]);
			printf(" %i  ", Matrix2[i][j]);
		}
		printf("\n");
	}
	

	int** MatrixResult = new int* [3];
	for (int i = 0; i < 3; i++)
	{
		MatrixResult[i] = new int[3];
		for (int j = 0; j < 3; j++)
		{
			MatrixResult[i][j] = 0;
			for (int k = 0; k < 3; k++)
			{
				MatrixResult[i][j] += Matrix1[i][k] * Matrix2[k][j];
			}
		}
	}
	
	printf("\nПолученная матрица при умножении первой на вторую:\n");
	for (int i = 0; i < 3; i++)
	{
		for (int j = 0; j < 3; j++)
		{
			printf(" %i  ", MatrixResult[i][j]);
		}
		printf("\n");
	}
	
	
	FILE* fileResult;
	errno_t err;

	err = fopen_s(&fileResult, "fileResult.txt", "w");
	if (err != 0)
	{
		perror("Невозможно создать файл с полученной матрицей");
		return EXIT_FAILURE;
	}

	for (int i = 0; i < 3; i++)
	{
		for (int j = 0; j < 3; j++)
		{
			fprintf(fileResult, " %i  ", MatrixResult[i][j]);
		}
		fprintf(fileResult, "\n");
	}
	fclose(fileResult);

	printf("\nПолученная матрица записана в файл fileResult.txt\n\n\n");



	for (int i = 0; i < 3; i++)
	{
		delete[] Matrix1[i];
		delete[] Matrix2[i];
		delete[] MatrixResult[i];
	}
	delete[] Matrix1;
	delete[] Matrix2;
	delete[] MatrixResult;

	return 0;
}


int var1Ex2()
{
	int K;
	printf("Введите число K которому будут кратны числа в файле: ");
	scanf_s("%i", &K);

	int numbers[20];
	FILE* file;
	fopen_s(&file, "file.txt", "r+");
	fseek(file, 0, 0);

	printf("Ваши числа:\n");
	for (int i = 0; i < 20; i++)
	{
		fscanf_s(file, "%i", &numbers[i]);
		printf("  %i ", numbers[i]);
	}

	errno_t err;
	FILE* fileG;

	err = fopen_s(&fileG, "fileG.txt", "w");
	if (err != 0)
	{
		perror("Невозможно создать файл с полученной матрицей");
		return EXIT_FAILURE;
	}

	printf("\nЧисла которые будут записаны в файл fileG:\n");
	for (int i = 0; i < 20; i++)
	{
		if (numbers[i] % K == 0)
		{
			fprintf(fileG, " %i  ", numbers[i]);
			printf("  %i ", numbers[i]);
		}
	}
	printf("\n");
}




int main()
{
	setlocale(LC_CTYPE, "ru");

	cout << "change" << endl;

	printf("Задание №1\n");
	var1Ex1();

	printf("Задание №2\n");
	var1Ex2();
}
