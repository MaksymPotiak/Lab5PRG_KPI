
/*
Використовуючи метод «бульбашки», впорядкувати посліду зростання
значення, що складається в рядках двовимірного масиву C з робочим розміром
n х m.Вивести масив C на екран.
Масив C повинен складатися з цілих чисел.Значення n і m, а також
значення елементів масиву C вводяться користувачем з клавіатури.
Елементи в кожному рядку масиву C не повинні повторюватися.
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
    SetConsoleOutputCP(65001);
    SetConsoleCP(65001);

    /*Цикл для вводу значень n та m з перевірками на правильність вводу.
     *Якщо користувач введе такі n та m які в добутку дадуть значення більше або рівне MAX_ARRAY_SIZE то програма попро�
     *Якщо користувач введе 1 то значення будуть підтверджені якщо 2 то користувача перекине на повторний ввід n
     *Якщо будуть введені якісь інші значення то програма попросить ввести ще раз.
     *logick перевіряє чи добуток n та m не більше за MAX_ARRAY_SIZE
     */
    while (!inputControlGeneral)
    {
        while (!controlInput_n)
        {
            printf("Введіть кількість рядків n: ");
            if (scanf("%d", &n) != 1 || n <= 0 || n >= INT_MAX)
            {
                printf("Довжина рядка не може бути від'ємною, символічною чи більше цього %d значення\n", INT_MAX);
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
            printf("Введіть кількість стовпців m: ");
            if (scanf("%d", &m) != 1 || m <= 0 || m >= INT_MAX)
            {
                printf("Довжина стовпця не може бути від'ємною, символічною чи більше цього %d значення\n", INT_MAX);
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
                printf("Розмірність вашого масиву складає більше 50 елементів!\n");
                printf("Ви впевнені що хочете продовжити?\n");
                printf("!!! - Меню - !!! \n");
                printf("Ведіть '1' якщо все вірно! \n");
                printf("Введіть '2' якщо хочете змінити значення рядків чи стовпців! \n");
                printf("Вибір: ");
                if (scanf("%d", &controlSizeMassiv) != 1)
                {
                    printf("Ви ввели некоректне значення! Спробуйте ще раз.\n");
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
                    printf("Ви ввели невірне значення\n");
                    scanf("%*[^\n]");
                }
            }
        }
        else
        {
            inputControlGeneral = true;
        }
    }
    printf("Ви ввели розмірність масиву %d на %d\n", n, m);

    int** C = (int**)malloc(n * sizeof(int*));
    if (C == NULL)
    {
        printf("Пам'ять не виділена\n");
        return 1;
    }
    for (int i = 0; i < n; i++)
    {
        C[i] = (int*)malloc(m * sizeof(int));
        if (C[i] == NULL)
        {
            printf("Пам'ять не виділена\n");
            return 1;
        }
    }
    // Введення елементів масиву з перевіркою на унікальність у рядку а також на коректність вводу
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            int inputElement;
            while (1)
            {
                printf("Введіть елемент масиву C[%d][%d]: ", i + 1, j + 1);
                if (scanf("%d", &inputElement) != 1)
                {
                    printf("Введено не коректне значення, спробуйте ще раз.\n");
                    scanf("%*[^\n]");
                }
                else
                {
                    // Перевірка на унікальність в поточному рядку
                    bool unikValue = true;
                    for (int q = 0; q < j; q++)
                    {
                        if (C[i][q] == inputElement)
                        {
                            unikValue = false;
                            break;
                        }
                    }

                    // Якщо елемент унікальний, зберігаємо його в масив в противному випадку просимо ввести інший
                    if (unikValue)
                    {
                        C[i][j] = inputElement;
                        break;
                    }
                    else
                    {
                        printf("Елемент %d вже існує в цьому рядку. Введіть інший.\n", inputElement);
                    }
                }
            }
        }
    }
    printf("\nВведений масив:\n");

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

    // Сортування кожного рядка масиву методом бульбашки по зростанню згідно завдання
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

    printf("\nВідсортований масив:\n");

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


