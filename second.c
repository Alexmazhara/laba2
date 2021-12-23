#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <malloc.h>
#include <time.h>
#include "Header.h"

	//���� ����� � �����
	int sc(FILE* fnumbers) {
	int result = 0;
	rewind(fnumbers);
	while (!ferror(fnumbers) && !feof(fnumbers)) {
		if (fgetc(fnumbers) == '\n') ++result;
	}
	return result;
}

  int main() {

	  setlocale(LC_ALL, "Rus");

	  FILE* fnumbers;
	  int i = 0, j = 0, n = 0, cmd = 0, sort = 0;
	  double b = 0.0;
	  double* a;
	  double t = 0;

	  fnumbers = fopen("C:\\Users\\prive\\Desktop\\numbers.txt", "r");

	  n = sc(fnumbers); //������� ���-�� �����

	  a = (double*)malloc(n * sizeof(double));
	  if (a == 0)
	  {
		  printf("������ 1!\n");
		  return 0;
	  }

	  rewind(fnumbers);
	  for (i = 0; i < n; i++)
	  {
		  fscanf_s(fnumbers, "%lf", &a[i]);
	  }

	  do
	  {
		  printf("�������� ��������:\n1. ������\n2. ����������\n3. �����\n4. �����\n");
		  printf("������� � �������: ");
		  scanf_s("%d", &cmd);

		  if (cmd == 1)
		  {
			  for (i = 0; i < n; i++)
			  {
				  printf("a[%d] = %lf\n", i, a[i]);
			  }
		  }

		  else if (cmd == 2)
		  {
			  printf("�������� ����� ����������:\n1. ���������\n2. ��������\n3. �������\n");
			  printf("������� � ����������: ");
			  scanf_s("%d", &sort);
			  if (sort == 1)  //���������� ���������
			  {
				  clock_t start = clock();
				  BubbleSort(n, a);
				  clock_t end = clock();
				  t = ((double)(end - start)) / CLOCKS_PER_SEC;
				  printf("�����, ������� �����������: %lf\n", t);
			  }

			  else if (sort == 2) //���������� ��������
			  {
				  rewind(fnumbers);
				  clock_t start = clock();
				  InsertionSort(n, a);
				  clock_t end = clock();
				  t = ((double)(end - start)) / CLOCKS_PER_SEC;
				  printf("�����, ������� �����������: %lf\n", t);
			  }

			  else if (sort == 3) //������� ����������
			  {
				  clock_t start = clock();
				  qs(a, 0, n - 1);
				  clock_t end = clock();
				  t = ((double)(end - start)) / CLOCKS_PER_SEC;
				  printf("�����, ������� �����������: %lf\n", t);
			  }
		  }

		  else if (cmd == 3)
		  {
			  rewind(fnumbers);
			  for (i = 0; i < n; i++)
			  {
				  fscanf_s(fnumbers, "%lf", &a[i]);
			  }
			  printf("������ ������� � ���������.\n");
		  }

		  else if (cmd == 4)
		  {
			  printf("���������� ������.\n");
		  }

		  else
		  {
			  printf("Error.\n");
		  }
	  } while (cmd != 4);
	  fclose(fnumbers);
	  free(a);
	  return 0;
  }