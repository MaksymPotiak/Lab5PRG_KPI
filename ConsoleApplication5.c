
/*
�������������� ����� ����������, ������������ �� ���������
��������, �� �������� � ������ ����������� ������ C � ������� �������
n � m.������� ����� C �� �����.
����� C ������� ���������� � ����� �����.�������� n � m, � �����
�������� �������� ������ C ��������� ������������ � ���������.
�������� � ������� ����� ������ C �� ������ �������������.
*/

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#include <limits.h>
#include <stdbool.h>
#define MAX_ARRAY_SIZE 50

int main(void)
{
	int n;
	int m;
	int controlSizeMassiv;
	bool controlInput_n = false;
	bool controlInput_m = false;
	bool inputControlGeneral = false;
	SetConsoleOutputCP(1251);
	SetConsoleCP(1251);

	/*���� ��� ����� ������� n �� m � ���������� �� ����������� �����.
	 *���� ���������� ����� ��� n �� m �� � ������� ������ �������� ����� ��� ���� MAX_ARRAY_SIZE �� �������� ��������� ������������.
	 *���� ���������� ����� 1 �� �������� ������ ���������� ���� 2 �� ����������� �������� �� ��������� ��� n �� m.
	 *���� ������ ������ ���� ���� �������� �� �������� ��������� ������ �� ���.
	 *logick �������� �� ������� n �� m �� ����� �� MAX_ARRAY_SIZE
	 */
	while (!inputControlGeneral)
	{
		while (!controlInput_n)
		{
			printf("������ ������� ����� n: ");
			if (scanf("%d", &n) != 1 || n <= 0 || n >= INT_MAX)
			{
				printf("������� ����� �� ���� ���� ��'�����, ���������� �� ����� ����� %d ��������\n", INT_MAX);
				scanf("%*[^\n]");
			}
			else
			{
				printf("n = %d!\n", n);
				controlInput_n = true;
			}
		}

		while (!controlInput_m)
		{
			printf("������ ������� �������� m: ");
			if (scanf("%d", &m) != 1 || m <= 0 || m >= INT_MAX)
			{
				printf("������� ������� �� ���� ���� ��'�����, ���������� �� ����� ����� %d ��������\n", INT_MAX);
				scanf("%*[^\n]");
			}
			else
			{
				printf("m = %d!\n", m);
				controlInput_m = true;
			}
		}

		int logick = n * m;

		if (logick >= MAX_ARRAY_SIZE)
		{
			while (1)
			{
				printf("��������� ������ ������ ������ ����� 50 ��������!\n");
				printf("�� ������� �� ������ ����������?\n");
				printf("!!! - ���� - !!! \n");
				printf("����� '1' ���� ��� ����! \n");
				printf("������ '2' ���� ������ ������ �������� ����� �� ��������! \n");
				printf("����: ");
				if (scanf("%d", &controlSizeMassiv) != 1)
				{
					printf("�� ����� ���������� ��������! ��������� �� ���.\n");
					scanf("%*[^\n]");
				}
				else if (controlSizeMassiv == 1)
				{
					inputControlGeneral = true;
					break;
				}
				else if (controlSizeMassiv == 2)
				{
					controlInput_n = false;
					controlInput_m = false;
					break;
				}
				else
				{
					printf("�� ����� ������ ��������\n");
					scanf("%*[^\n]");
				}
			}
		}
		else
		{
			inputControlGeneral = true;
		}
	}
	printf("�� ����� ��������� ������ %d �� %d\n", n, m);

	int** C = (int**)malloc(n * sizeof(int*));
	if (C == NULL)
	{
		printf("���'��� �� �������\n");
		return 1;
	}
	for (int i = 0; i < n; i++)
	{
		C[i] = (int*)malloc(m * sizeof(int));
		if (C[i] == NULL)
		{
			printf("���'��� �� �������\n");
			return 1;
		}
	}
	// �������� �������� ������ � ��������� �� ���������� � ����� � ����� �� ���������� �����
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			int inputElement;
			while (1)
			{
				printf("������ ������� ������ C[%d][%d]: ", i + 1, j + 1);
				if (scanf("%d", &inputElement) != 1)
				{
					printf("������� �� �������� ��������, ��������� �� ���.\n");
					scanf("%*[^\n]");
				}
				else
				{
					// �������� �� ���������� � ��������� �����
					bool unikValue = true;
					for (int q = 0; q < j; q++)
					{
						if (C[i][q] == inputElement)
						{
							unikValue = false;
							break;
						}
					}

					// ���� ������� ���������, �������� ���� � ����� � ���������� ������� ������� ������ �����
					if (unikValue)
					{
						C[i][j] = inputElement;
						break;
					}
					else
					{
						printf("������� %d ��� ���� � ����� �����. ������ �����.\n", inputElement);
					}
				}
			}
		}
	}
	printf("\n�������� �����:\n");

	printf("+");
	for (int j = 0; j < m; j++)
	{
		printf("--------+");
	}
	printf("\n");

	for (int i = 0; i < n; i++)
	{
		printf("|");
		for (int j = 0; j < m; j++)
		{
			printf(" %6d |", C[i][j]);
		}
		printf("\n");

		printf("+");
		for (int j = 0; j < m; j++)
		{
			printf("--------+");
		}
		printf("\n");
	}

	// ���������� ������� ����� ������ ������� ��������� �� ��������� ����� ��������
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m - 1; j++)
		{
			for (int k = 0; k < m - j - 1; k++)
			{
				if (C[i][k] > C[i][k + 1])
				{
					int temp = C[i][k];
					C[i][k] = C[i][k + 1];
					C[i][k + 1] = temp;
				}
			}
		}
	}


	printf("\n³����������� �����:\n");

	printf("+");
	for (int j = 0; j < m; j++)
	{
		printf("--------+");
	}
	printf("\n");

	for (int i = 0; i < n; i++)
	{
		printf("|");
		for (int j = 0; j < m; j++)
		{
			printf(" %6d |", C[i][j]);
		}
		printf("\n");

		printf("+");
		for (int j = 0; j < m; j++)
		{
			printf("--------+");
		}
		printf("\n");
	}

	for (int i = 0; i < n; i++)
	{
		free(C[i]);
	}
	free(C);
	return 0;
}

