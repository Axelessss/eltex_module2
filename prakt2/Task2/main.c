#include <stdio.h>
#include <math.h>
#include <stdbool.h>

bool input(int operation, bool shutdown)
{
    float a, b;
    float result;
    if (!shutdown);
        printf("Введите первый аргумент: ");
        scanf("%f", &a);

    switch(operation)
        {
            case 1:
                printf("Введите второй аргумент: ");
                scanf("%f", &b);
                result = sum(a, b);
                break;
            
            case 2:
                printf("Введите второй аргумент: ");
                scanf("%f", &b);
                result = subtract(a, b);
                break;
            
            case 3:
                printf("Введите второй аргумент: ");
                scanf("%f", &b);
                result = mul(a, b);
                break;
            
            case 4:
                printf("Введите второй аргумент: ");
                scanf("%f", &b);
                result = div(a, b);
                break;
            
            case 5:
                printf("Введите второй аргумент: ");
                scanf("%f", &b);
                result = deg(a, b);
                break;
            
            case 6:
                printf("Введите второй аргумент: ");
                scanf("%f", &b);
                result = root(a, b);
                break;
            
            case 7:
                
                result = e(a);
                break;
            
            case 8:
                shutdown=true;
                break;
            
            default:
                printf("Неопознанная команда");
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

void sum(float a, float b)
{
    return a+b;
}

void subtract(float a, float b)
{
    float a, b;
    printf("Введите первый аргумент: ");
    scanf("%f", &a);
    printf("Введите второй аргумент: ");
    scanf("%f", &b);
}

void mul(float a, float b)
{
    float a, b;
    printf("Введите первый аргумент: ");
    scanf("%f", &a);
    printf("Введите второй аргумент: ");
    scanf("%f", &b);
    printf("Результат = %f\n", a*b);
}

void div(float a, float b)
{
    float a, b;
    printf("Введите первый аргумент: ");
    scanf("%f", &a);
    printf("Введите второй аргумент: ");
    scanf("%f", &b);
    printf("Результат = %f\n", a/b);
}

void deg(float a, float b)
{
    float a, b;
    printf("Введите основание степени: ");
    scanf("%f", &a);
    printf("Введите показатель степени: ");
    scanf("%f", &b);
    printf("Результат = %f\n", pow(a, b));
}

void root(float a, float b)
{
    float a, b;
    printf("Введите подкоренной аргумент: ");
    scanf("%f", &a);
    printf("Введите показатель корня: ");
    scanf("%f", &b);
    printf("Результат = %f\n", pow(a, 1/b));
}

void e(float a, float b)
{
    float a, b;
    printf("Введите аргумент: ");
    scanf("%f", &a);
    printf("Результат = %f\n", exp(a));
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
        printf("\n1-сложение\n2-вычитание\n3-умножение\n4-деление\n5-возведение в степень\n6-корень n-й степени\n7-экспонента\n8-завершить работу\n");
        scanf("%d", &operation);
        shutdown = input(operation, shutdown);
    }
}