#include <locale.h>
#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>

#define N 20


/*void access_permissions(char *permissions, struct stat *st)
{
    char *path;
    printf("Введите путь до файла: ");
    scanf("%s", &path);
}*/

void oct_to_binary(int num, char (*binary)[N], char (*letters)[N])
{
    int number;
    for(int i = 2; i >= 0; i--)
    {
        number = num % 10;
        switch(number)
        {
            case 0:
                strcpy(binary[i], "000");
                strcpy(letters[i], "---");
                break;

            case 1:
                strcpy(binary[i], "001");
                strcpy(letters[i], "--x");
                break;

            case 2:
                strcpy(binary[i], "010");
                strcpy(letters[i], "-w-");
                break;

            case 3:
                strcpy(binary[i], "011");
                strcpy(letters[i], "-wx");
                break;

            case 4:
                strcpy(binary[i], "100");
                strcpy(letters[i], "r--");
                break;

            case 5:
                strcpy(binary[i], "101");
                strcpy(letters[i], "r-x");
                break;

            case 6:
                strcpy(binary[i], "110");
                strcpy(letters[i], "rw-");
                break;

            case 7:
                strcpy(binary[i], "111");
                strcpy(letters[i], "rwx");
                break;
        }
        num /= 10;
    }

}

int decimal_to_oct(int num)
{
    int oct[N];
    int i = 0;

    if(num <= 7)
        return num;

    while(num / 8 != 0)
    {
        oct[i] = num % 8;
        num/=8;
        i++;
    }

    num = oct[2]*100 + oct[1]*10 + oct[0];
    return num;
}

bool all_digits(const char *str) 
{
    while (*str) 
    {
        if (!isdigit(*str++)) 
        {
            return false;
        }
    }
    return true;
}

void letter_to_binary(char* letters, char (*binary)[N])
{

    int bin_c = 0;
    for(int i = 2; i < strlen(letters); i+=3)
    {

        if(letters[i-2]=='-')
        {
            if(letters[i-1]=='-')
            {
                if(letters[i]=='-')
                    strcpy(binary[bin_c], "000");
                else if(letters[i]=='x')
                    strcpy(binary[bin_c], "001");
            }
            else if(letters[i]=='w')
            {
                if(letters[i]=='-')
                    strcpy(binary[bin_c], "010");
                else if(letters[i]=='x')
                    strcpy(binary[bin_c], "011");
            }
        }

        else if(letters[i-2]=='r')
        {
            if(letters[i-1]=='-')
            {
                if(letters[i]=='-')
                    strcpy(binary[bin_c], "100");
                else if(letters[i]=='x')
                    strcpy(binary[bin_c], "101");
            }
            else if(letters[i]=='w')
            {
                if(letters[i]=='-')
                    strcpy(binary[bin_c], "110");
                else if(letters[i]=='x')
                    strcpy(binary[bin_c], "111");
            }
        }
        bin_c++;
    }
}

int main(int argc, char* argv[])
{

    struct stat st;
    char permissions[3][N];
    char binary[3][N];
    int action;
    int stmode;
    //char permissions[3][N];

    while(true)
    {
        printf("\n\nВыберите действие:\n1-получить права доступа в битовом представлении\n2-представление прав доступа к файлу");
        printf("\nВыход-любая другая цифра\n");
        scanf("%d", &action);

        switch(action)
        {
            case 1:
                if(argc != 2)
                {
                    printf("Нужен один параметр\n");
                    return 1;
                }
                
                if(all_digits(argv[1]))
                {
                    stmode = atoi(argv[1]);
                    oct_to_binary(stmode, binary, permissions);
                }

                else
                {
                    if(strlen(argv[1]) != 9)
                    {
                        printf("Длина текстовых прав доступа не должна превышать 9 символов!");
                        return 1;
                    }
                        
                    //letter_to_binary(argv[1], binary);
                }

                printf("\nБинарное представление: ");

                for (int i = 0; i < 3; i++)
                    printf("%s", binary[i]);

                break;
            
            case 2:
                if(argc != 2)
                {
                    printf("Нужен один параметр\n");
                    return 1;
                }
                
                if (stat(argv[1], &st) == -1) 
                {
                    perror("stat");
                    return 1;
                }
                //printf("Permissions: %o\n", st.st_mode);
                stmode = st.st_mode;
                stmode = decimal_to_oct(stmode);
                
                oct_to_binary(stmode, binary, permissions);

                printf("\nБуквенное представление: ");
                for (int i = 0; i < 3; i++)
                    printf("%s", permissions[i]);

                printf("\nЦифровое представление: %d", stmode);

                printf("\nБинарное представление: ");
                for (int i = 0; i < 3; i++)
                    printf("%s", binary[i]);

                break;
                
                
            
            default:
                return 0;
        }

        /*printf("Желаете изменить права доступа? 1-да 0-нет");
        scanf("%d", &action);

        if(action == 1)
        {
            
        }*/
    }
}