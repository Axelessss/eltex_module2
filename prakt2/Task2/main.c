#include <stdio.h>
#include <math.h>
#include <stdbool.h>

void sum()
{
    printf("Введите первый аргумент: ");
    scanf("%f", &a);
    printf("Введите второй аргумент: ");
    scanf("%f", &b);
    printf("Результат = %f\n", a+b);
}

void subtract()
{
    printf("Введите первый аргумент: ");
    canf("%f", &a);
    printf("Введите второй аргумент: ");
    scanf("%f", &b);
}

void mul()
{
    printf("Введите первый аргумент: ");
    scanf("%f", &a);
    printf("Введите второй аргумент: ");
    scanf("%f", &b);
    printf("Результат = %f\n", a*b);
}

void div()
{
    printf("Введите первый аргумент: ");
    scanf("%f", &a);
    printf("Введите второй аргумент: ");
    scanf("%f", &b);
    printf("Результат = %f\n", a/b);
}

void deg()
{
    printf("Введите основание степени: ");
    scanf("%f", &a);
    printf("Введите показатель степени: ");
    scanf("%f", &b);
    printf("Результат = %f\n", pow(a, b));
}

void root()
{
    printf("Введите подкоренной аргумент: ");
    scanf("%f", &a);
    printf("Введите показатель корня: ");
    scanf("%f", &b);
    printf("Результат = %f\n", pow(a, 1/b));
}

void e()
{
    printf("Введите аргумент: ");
    canf("%f", &a);
    printf("Результат = %f\n", exp(a));
}

int main()
{
    float a;
    float b;
    bool shutdown=false;
    int operation;

    while (true)
    {
        if (shutdown)
            break;

        printf("\nВыберите действие: ");
        printf("\n1-сложение\n2-вычитание\n3-умножение\n4-деление\n5-возведение в степень\n6-корень n-й степени\n7-экспонента\n8-завершить работу\n");
        scanf("%d", &operation);

        switch(operation)
        {
            case 1:
                sum();
                break;
            
            case 2:
                subtract();
                break;
            
            case 3:
                mul();
                break;
            
            case 4:
                
                div();
                break;
            
            case 5:
                
                deg();
                break;
            
            case 6:
                root();
                break;
            
            case 7:
                
                e();
                break;
            
            case 8:
                shutdown=true;
                break;
            
            default:
                printf("Неопознанная команда");
                break;
        }
    }
}