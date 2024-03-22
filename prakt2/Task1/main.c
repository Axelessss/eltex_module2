//#pragma once
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
    char buffer2[N];

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
        fgets(buffer2, sizeof(buffer), stdin);
        if (strlen(buffer2)==0)
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
    int count_phones, count_email, count_socials, count_messengers;
    while (true)
    {       
        if (shutdown)
            break;

        printf("Что заполнить:\n1-Фамилия\n2-Имя\n3-Отчество\n4-Место работы и должность\n5-Номер телефона\n6-E-mail\n7-Соцсети\n8-Мессенджеры\n");
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
                printf("1-удалить номер телефона 2-добавить номер телефона");
                scanf("%d", &sub_operation);

                count_phones = contact->phone[0].count;

                if (sub_operation==1)
                {
                    printf("Введите ID телефона для удаления: ");
                    scanf("%d", &ID);
                    
                    if (ID == 0)
                        for (int i = 0; i < count_phones-1; i++)
                            contact->phone[i] = contact->phone[i+1];   
                    

                    else if (ID == count_phones)
                        printf("");
                    

                    else
                        for(int i = ID; i < count_phones; i++)
                            contact->phone[i] = contact->phone[i+1];
                    
                    for(int i = 0; i < count_phones-1; i++)
                        contact->phone[i].count--;
                }

                else if (sub_operation==2)
                {
                    if(count_phones == 5)
                        printf("Достигнуто максимальное количество номеров телефона!");
                    else
                    {    
                        printf("Укажите тип телефона: ");      
                        fgets(contact->phone[count_phones].phone_type, sizeof(contact->phone[count_phones].phone_type), stdin);

                        printf("Укажите номер телефона: ");      
                        fgets(contact->phone[count_phones].number, sizeof(contact->phone[count_phones].number), stdin);

                        contact->phone[count_phones].count++;
                        
                    }
                }
                break;

            case 6:
                printf("1-удалить адрес 2-добавить адрес");
                scanf("%d", &sub_operation);

                count_email = contact->email[0].count;

                if (sub_operation==1)
                {
                    printf("Введите ID электронного адреса для удаления: ");
                    scanf("%d", &ID);
                    
                    if (ID == 0)
                        for (int i = 0; i < count_email-1; i++)
                            contact->email[i] = contact->email[i+1];   
                    

                    else if (ID == count_email)
                        printf("");

                    else
                        for(int i = ID; i < count_email; i++)
                            contact->email[i] = contact->email[i+1];
                    
                    for(int i = 0; i < count_email-1; i++)
                        contact->email[i].count--;
                    
                }

                else if (sub_operation==2)
                {
                    if(count_email == 5)
                        printf("Достигнуто максимальное количество адресов!");
                    else    
                            printf("Укажите адрес: ");      
                            fgets(contact->email[count_email].email, sizeof(contact->email[count_email].email), stdin);
                }
                break;

            case 7:
                printf("1-удалить соцсеть 2-добавить соцсеть");
                scanf("%d", &sub_operation);

                count_socials = contact->socials[0].count;

                if (sub_operation==1)
                {
                    printf("Введите ID соцсети для удаления: ");
                    scanf("%d", &ID);
                    
                    if (ID == 0)
                        for (int i = 0; i < count_socials-1; i++)
                            contact->socials[i] = contact->socials[i+1];   
                    

                    else if (ID == count_socials)
                        printf("");

                    else
                        for(int i = ID; i < count_socials; i++)
                            contact->socials[i] = contact->socials[i+1];
                    
                }

                else if (sub_operation==2)
                {
                    if(count_socials == 5)
                        printf("Достигнуто максимальное количество соцсетей!");
                    else    
                            printf("Укажите тип телефона: ");      
                            fgets(contact->socials[count_socials].name, sizeof(contact->socials[count_socials].name), stdin);

                            printf("Укажите номер телефона: ");      
                            fgets(contact->socials[count_socials].url, sizeof(contact->socials[count_socials].url), stdin);
                }
                break;

            case 8:
                printf("1-удалить мессенджер 2-добавить мессенджер");
                scanf("%d", &sub_operation);

                count_messengers = contact->messengers[0].count;

                if (sub_operation==1)
                {
                    printf("Введите ID мессенджера для удаления: ");
                    scanf("%d", &ID);
                    
                    if (ID == 0)
                        for (int i = 0; i < count_messengers-1; i++)
                            contact->messengers[i] = contact->messengers[i+1];   
                    

                    else if (ID == count_messengers)
                        printf("");

                    else
                        for(int i = ID; i < count_messengers; i++)
                            contact->messengers[i] = contact->messengers[i+1];
                    
                }

                else if (sub_operation==2)
                {
                    if(count_messengers == 5)
                        printf("Достигнуто максимальное количество номеров телефона!");
                    else    
                            printf("Укажите тип телефона: ");      
                            fgets(contact->messengers[count_messengers].name, sizeof(contact->messengers[count_messengers].name), stdin);

                            printf("Укажите номер телефона: ");      
                            fgets(contact->messengers[count_messengers].nickname, sizeof(contact->messengers[count_messengers].nickname), stdin);
                }
                break;
                
            default:
                shutdown = true;
                break;
                
        }
    }
}

void remove_contact(Contact contact[], int count, int ID)
{
    if (ID == 0)
        for (int i = 0; i < count-1; i++)
            contact[i] = contact[i+1];
    else if (ID>0 && ID<count)
        for (int i = ID; i < count-1; i++)
            contact[i] = contact[i+1];
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
        printf("Для закрытия программы нажмите любую другую кнопку");
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

                remove_contact(&contacts[ID], count, ID);
                break;

            case 4:
                for (int i = 0; i < count; i++)
                {
                    int phone_count = contacts[i].phone[0].count;
                    int email_count = contacts[i].email[0].count;
                    int social_count = contacts[i].socials[0].count;
                    int messenger_count = contacts[i].messengers[0].count;

                    printf("ID: %d", contacts[i].id);
                    puts(contacts[i].fio.surname);
                    puts(contacts[i].fio.name);
                    puts(contacts[i].fio.partonymic);
                    puts(contacts[i].job.corp);
                    puts(contacts[i].job.title);

                    for (int j = 0; j < phone_count; j++)
                    {
                        printf("ID: %d", contacts[i].phone[j].ID);
                        puts(contacts[i].phone[j].phone_type);
                        puts(contacts[i].phone[j].number);
                    }

                    for (int j = 0; j < email_count; j++)
                    {
                        printf("ID: %d", contacts[i].email[j].ID);
                        puts(contacts[i].email[j].email);
                    }

                    for (int j = 0; j < social_count; j++)
                    {
                        printf("ID: %d", contacts[i].socials[j].ID);
                        puts(contacts[i].socials[j].name);
                        puts(contacts[i].socials[j].url);
                    }

                    for (int j = 0; j < messenger_count; j++)
                    {
                        printf("ID: %d", contacts[i].messengers[j].ID);
                        puts(contacts[i].messengers[j].name);
                        puts(contacts[i].messengers[j].nickname);
                    }
                    
                }
        }
    }
}