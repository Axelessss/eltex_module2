#include <dlfcn.h>
#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include "operations.h"
#define N 20

void input(int action, bool *shutdown, char *path, char *operation, float *a, float *b)
{
    switch(action)
        {
            case 1:
                strcpy(path, "./libsum.so");
                strcpy(operation, "sum");
                break;
            
            case 2:
                strcpy(path, "./libsubtract.so");
                strcpy(operation, "subtract");
                break;
            
            case 3:
                strcpy(path, "./libmul.so");
                strcpy(operation, "mul");
                break;
            
            case 4:
                strcpy(path, "./libdiv.so");
                strcpy(operation, "div");
                break;
            
            case 5:
                strcpy(path, "./libdeg.so");
                strcpy(operation, "deg");
                break;
            
            case 6:
                strcpy(path, "./libroot.so");
                strcpy(operation, "root");
                break;
            
            default:
                *shutdown=true;
                break;
        }

    if (*shutdown)
        return;
    
    else
    {
        printf("Введите первый аргумент: ");
        scanf("%f", a);
        printf("Введите второй аргумент: ");
        scanf("%f", b);
    }
}

int main()
{
    bool shutdown=false;
    int action;
    float a, b;
    void *handle;
    char *error;
    char lib[N];
    char operation[N];
    float (*result) (float, float);

    while (true)
    {
        printf("\nВыберите действие: ");
        printf("\n1-сложение\n2-вычитание\n3-умножение\n4-деление\n5-возведение в степень\n6-корень n-й степени\nЛюбая другая кнопка-завершить работу\n");
        scanf("%d", &action);
        input(action, &shutdown, lib, operation, &a, &b);

        if (shutdown)
            break;

        handle = dlopen (lib, RTLD_LAZY);

        if (!handle) 
        {
            fputs (dlerror(), stderr);
            exit(1);
        }

        result = dlsym(handle, operation);
        if ((error = dlerror()) != NULL) 
        {
            fprintf (stderr, "%s\n", error);
            exit(1);
        }

        printf ("%f\n", (*result)(a, b));
        dlclose(handle);

        sleep(2);
    } 
}
