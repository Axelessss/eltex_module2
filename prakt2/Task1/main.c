#pragma once
#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include "contact.h"

#define N 50
#define M 20
#define U 100

void add(Contact *contact, int id)
{
    char con;
    int operation;
    int count;
    bool shutdown = false;

    char buffer[N];
    //char buffer2[N];

    while (true)
    {
        printf("Введите фамилию: ");
        fgets(buffer, sizeof(buffer), stdin);
        if (strlen(buffer)==0)
            printf("Поле не должно быть пустым!");
        else
        {
            strncpy(contact->fio.surname, buffer, N);
            break;
        }
    }

    while (true)
    {
        printf("Введите имя: ");
        fgets(buffer, sizeof(buffer), stdin);
        if (strlen(buffer)==0)
            printf("Поле не должно быть пустым!");
        else
        {
            strncpy(contact->fio.name, buffer, N);
            break;
        }
    }
    

    printf("Желаете ли продолжить заполнение? +/-");
    scanf("%c", &con);
    if (con == '+')
        while (true)
        {       
            if (shutdown)
                break;

            printf("Что заполнить:\n1-Отчество\n2-Место работы и должность\n3-Номер телефона\n4-E-mail\n5-Соцсети\n6-Мессенджеры\nЛюбая другая кнопка - Выход");
            scanf("%d", &operation);
            switch(operation)
            {
                case 1:
                    printf("Введите отчество");
                    fgets(contact->fio.partonymic, sizeof(contact->fio.partonymic), stdin);
                    break;
                
                case 2:
                    printf("Введите  место работы");
                    fgets(contact->job.corp, sizeof(contact->job.corp), stdin);

                    printf("Введите  должность");
                    fgets(contact->job.title, sizeof(contact->job.title), stdin);
                    break;
                
                case 3:
                    printf ("Введите количество номеров телефона: ");
                    scanf("%d", &count);
                    for(int i=0;i<count;i++)
                    {
                        contact->phone[i].count = count;

                        printf("Укажите тип телефона: ");      
                        fgets(contact->phone[i].phone_type, sizeof(contact->phone[i].phone_type), stdin);

                        printf("Укажите номер телефона: ");      
                        fgets(contact->phone[i].number, sizeof(contact->phone[i].number), stdin);
                    }
                    break;

                case 4:
                    printf ("Введите количество e-mail адресов: ");
                    scanf("%d", &count);
                    for(int i=0;i<count;i++)
                    {
                        contact->email[i].count = count;

                        printf("Введите электронный адрес: ");      
                        fgets(contact->email[i].email, sizeof(contact->email[i].email), stdin);
                    }
                    break;

                case 5:
                    printf ("Введите количество профилей в соцсетях: ");
                    scanf("%d", &count);
                    for(int i=0;i<count;i++)
                    {
                        contact->socials[i].count = count;

                        printf("Укажите название соцсети: ");      
                        fgets(contact->socials[i].name, sizeof(contact->socials[i].name), stdin);

                        printf("Укажите ссылку на ваш профиль: ");      
                        fgets(contact->socials[i].url, sizeof(contact->socials[i].url), stdin);
                    }
                    break;

                case 6:
                    printf ("Введите количество профилей в мессенджерах: ");
                    scanf("%d", &count);
                    for(int i=0;i<count;i++)
                    {
                        contact->messengers[i].count = count;

                        printf("Укажите название мессенджера: ");      
                        fgets(contact->messengers[i].name, sizeof(contact->messengers[i].name), stdin);

                        printf("Укажите имя пользователя: ");      
                        fgets(contact->messengers[i].nickname, sizeof(contact->messengers[i].nickname), stdin);
                    }
                    break;
                
                default:
                    shutdown = true;
                    break;
                
            }
        }
}

void change(Contact *contact)
{
    int operation;
    int sub_operation;
    int ID;
    int count;
    bool shutdown = false;
    char buffer[N];

    while (true)
    {       
        if (shutdown)
            break;

        printf("Что заполнить:\n1-Фамилия\n2-Имя\n3-Отчество\n4-Место работы\n5-Должность\n6-Номер телефона\n7-E-mail\n8-Соцсети\n9-Мессенджеры\n");
        printf("Любая другая кнопка - Выход\n");
        scanf("%d", &operation);
        
        switch(operation)
        {
            case 1:
                while (true)
                {
                    printf("Введите фамилию: ");
                    fgets(buffer, sizeof(buffer), stdin);
                    if (strlen(buffer)==0)
                        printf("Поле не должно быть пустым!");
                    else
                    {
                        strncpy(contact->fio.surname, buffer, N);
                        break;
                    }
                }
                break;

            case 2:
                while (true)
                {
                    printf("Введите фамилию: ");
                    fgets(buffer, sizeof(buffer), stdin);
                    if (strlen(buffer)==0)
                        printf("Поле не должно быть пустым!");
                    else
                    {
                        strncpy(contact->fio.surname, buffer, N);
                        break;
                    }
                }
                break;

            case 3:
                printf("Введите отчество");
                fgets(contact->fio.partonymic, sizeof(contact->fio.partonymic), stdin);
                break;
                
            case 4:
                printf("Введите  место работы");
                fgets(contact->job.corp, sizeof(contact->job.corp), stdin);

                printf("Введите  должность");
                fgets(contact->job.title, sizeof(contact->job.title), stdin);
                break;
                
            case 5:
                printf ("Введите количество номеров телефона: ");
                scanf("%d", &count);
                for(int i=0;i<count;i++)
                {
                    printf("Укажите тип телефона: ");      
                    fgets(contact->phone[i].phone_type, sizeof(contact->phone[i].phone_type), stdin);

                    printf("Укажите номер телефона: ");      
                        fgets(contact->phone[i].number, sizeof(contact->phone[i].number), stdin);
                }
                break;

            case 6:
                printf("1-удалить номер телефона 2-добавить номер телефона 3-удалить все телефоны");
                scanf("%d", &sub_operation);

                if (sub_operation==1)
                {
                    printf("Введите ID телефона для удаления: ");
                    scanf("%d", &ID);
                }

                else if (sub_operation==2)
                {
                    printf ("Введите количество номеров телефона: ");
                    scanf("%d", &count);
                for(int i=0;i<count;i++)
                {
                    printf("Укажите тип телефона: ");      
                    fgets(contact->phone[i].phone_type, sizeof(contact->phone[i].phone_type), stdin);

                    printf("Укажите номер телефона: ");      
                    fgets(contact->phone[i].number, sizeof(contact->phone[i].number), stdin);
                }
                }
                
                break;

            case 7:
                printf ("Введите количество e-mail адресов: ");
                scanf("%d", &count);
                for(int i=0;i<count;i++)
                {
                    printf("Введите электронный адрес: ");      
                    fgets(contact->phone[i].number, sizeof(contact->phone[i].number), stdin);
                }
                break;

            case 8:
                printf ("Введите количество профилей в соцсетях: ");
                scanf("%d", &count);
                for(int i=0;i<count;i++)
                {
                    printf("Укажите название соцсети: ");      
                    fgets(contact->phone[i].phone_type, sizeof(contact->phone[i].phone_type), stdin);

                    printf("Укажите ссылку на ваш профиль: ");      
                    fgets(contact->phone[i].number, sizeof(contact->phone[i].number), stdin);
                }
                break;

            case 9:
                printf ("Введите количество профилей в мессенджерах: ");
                scanf("%d", &count);
                for(int i=0;i<count;i++)
                {
                    printf("Укажите название мессенджера: ");      
                    fgets(contact->phone[i].phone_type, sizeof(contact->phone[i].phone_type), stdin);

                    printf("Укажите имя пользователя: ");      
                    fgets(contact->phone[i].number, sizeof(contact->phone[i].number), stdin);
                }
                break;
                
            default:
                shutdown = true;
                break;
                
        }
    }
}

void remove(Contact *contact, int index)
{

}

int main()
{
    Contact contacts[21];
    int action;
    int count = 0;
    bool shutdown = false;
    int ID;
    while (true)
    {
        if (shutdown)
            break;

        printf("Добро пожаловать в список контактов! Выберите желаемое действие:\n1-добавить контакт\n2-редактировать контакт\n3-удалить контакт\n4-просмотр списка контактов\n");
        printf("Для закрытия программы нажмите любую другую кнопку\n");
        scanf("%d", &action);

        switch(action)
        {
            case 1:
                add(&contacts[count], count);
                count++;
                break;

            case 2:
                printf("Введите ID контакта, который хотите отредактировать: ");
                scanf("%d", &ID);

                change(&contacts[ID]);
                break;
            
            case 3:
                printf("Введите ID контакта, который хотите удалить: ");
                scanf("%d", &ID);

                remove(&contacts[ID], ID);
                break;
        }
    }
    add(&contacts[0]);
    puts(contacts[0].fio.name);

}