#include <stdio.h>
#include <math.h>
#include <stdbool.h>
#include <unistd.h>
#include "header.h"


bool input(int operation, bool shutdown)
{
    float a, b;
    float result;

    switch(operation)
        {
            case 1:
                printf("Введите первый аргумент: ");
                scanf("%f", &a);
                printf("Введите второй аргумент: ");
                scanf("%f", &b);
                result = sum(a, b);
                break;
            
            case 2:
                printf("Введите первый аргумент: ");
                scanf("%f", &a);
                printf("Введите второй аргумент: ");
                scanf("%f", &b);
                result = subtract(a, b);
                break;
            
            case 3:
                printf("Введите первый аргумент: ");
                scanf("%f", &a);
                printf("Введите второй аргумент: ");
                scanf("%f", &b);
                result = mul(a, b);
                break;
            
            case 4:
                printf("Введите делимое: ");
                scanf("%f", &a);
                printf("Введите делитель: ");
                scanf("%f", &b);
                result = div(a, b);
                break;
            
            case 5:
                printf("Введите основание: ");
                scanf("%f", &a);
                printf("Введите показатель: ");
                scanf("%f", &b);
                result = deg(a, b);
                break;
            
            case 6:
                printf("Введите подкоренной аргумент: ");
                scanf("%f", &a);
                printf("Введите степень корня: ");
                scanf("%f", &b);
                result = root(a, b);
                break;
            
            default:
                shutdown=true;
                break;
        }

    if (shutdown)
        return true;
    else
    {
        printf("Результат = %f\n", result);
        return false;
    }
}

float sum(float a, float b)
{
    return a+b;
}

float subtract(float a, float b)
{
    return a-b;
}

float mul(float a, float b)
{
    return a*b;
}

float div(float a, float b)
{
    return a/b;
}

float deg(float a, float b)
{
    return pow(a, b);
}

float root(float a, float b)
{
    return pow(a, 1/b);
}

float e(float a)
{
    return exp(a);
}

int main()
{
    bool shutdown=false;
    int operation;

    while (true)
    {
        if (shutdown)
            break;

        printf("\nВыберите действие: ");
        printf("\n1-сложение\n2-вычитание\n3-умножение\n4-деление\n5-возведение в степень\n6-корень n-й степени\nЛюбая другая кнопка-завершить работу\n");
        scanf("%d", &operation);
        shutdown = input(operation, shutdown);

        if(!shutdown)
            sleep(5);
    }
}
