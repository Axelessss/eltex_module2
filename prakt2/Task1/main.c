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

    char buffer[N];
    char buffer2[N];

    contact->id = id;

    while (true)
    {
        printf("Введите фамилию: ");
        scanf("%s", &buffer);

        if (strlen(buffer)==0)
        {
            printf("Поле не должно быть пустым!");
            continue;
        }

        else
            strcpy(contact->fio.surname, buffer);
        
        printf("Введите имя: ");
        scanf("%s", &buffer2);
        if (strlen(buffer2)==0)
            printf("Поле не должно быть пустым!");
        else
        {
            strcpy(contact->fio.name, buffer2);
            break;
        }
    }
    
    printf("Желаете ли продолжить заполнение? 1-да/другая кнопка-нет\n");
    scanf("%d", &con);
    if (con == 1)
        while (true)
        {       

            printf("Что заполнить:\n1-Отчество\n2-Место работы и должность\n3-Номер телефона\n4-E-mail\n5-Соцсети\n6-Мессенджеры\nЛюбая другая кнопка - Выход\n");
            scanf("%d", &operation);
            switch(operation)
            {
                case 1:
                    printf("Введите отчество: ");
                    scanf("%s", &contact->fio.partonymic);
                    break;
                
                case 2:
                    printf("Введите  место работы: ");
                    scanf("%s", &contact->job.corp);

                    printf("Введите  должность: ");
                    scanf("%s", &contact->job.title);
                    break;
                
                case 3:
                    printf ("Введите количество номеров телефона: ");
                    scanf("%d", &count);
                    for(int i=0;i<count;i++)
                    {
                        contact->phone[i].count = count;
                        contact->phone[i].ID = i;

                        printf("Укажите тип телефона: ");      
                        scanf("%s", &contact->phone[i].phone_type);

                        printf("Укажите номер телефона: ");      
                        scanf("%s", &contact->phone[i].number);
                    }
                    break;

                case 4:
                    printf ("Введите количество e-mail адресов: ");
                    scanf("%d", &count);
                    for(int i=0;i<count;i++)
                    {
                        contact->email[i].count = count;
                        contact->email[i].ID = i;

                        printf("Введите электронный адрес: ");      
                        scanf("%s", &contact->email[i].email);
                    }
                    break;

                case 5:
                    printf ("Введите количество профилей в соцсетях: ");
                    scanf("%d", &count);
                    for(int i=0;i<count;i++)
                    {
                        contact->socials[i].count = count;
                        contact->socials[i].ID = i;

                        printf("Укажите название соцсети: ");      
                        scanf("%s", &contact->socials[i].name);

                        printf("Укажите ссылку на ваш профиль: ");      
                        scanf("%s", &contact->socials[i].url);
                    }
                    break;

                case 6:
                    printf ("Введите количество профилей в мессенджерах: ");
                    scanf("%d", &count);
                    for(int i=0;i<count;i++)
                    {
                        contact->messengers[i].count = count;
                        contact->messengers[i].ID = i;

                        printf("Укажите название мессенджера: ");      
                        scanf("%s", &contact->messengers[i].name);

                        printf("Укажите имя пользователя: ");      
                        scanf("%s", &contact->messengers[i].nickname);
                    }
                    break;
                
                default:
                    return;
            }
        }
}

void change(Contact *contact)
{
    int operation;
    int sub_operation;
    int ID;
    int count;
    char buffer[N];
    int count_phones, count_email, count_socials, count_messengers;
    while (true)
    {       

        printf("Что заполнить:\n1-Фамилия\n2-Имя\n3-Отчество\n4-Место работы и должность\n5-Номер телефона\n6-E-mail\n7-Соцсети\n8-Мессенджеры\n");
        printf("Любая другая кнопка - Выход\n");
        scanf("%d", &operation);
        
        switch(operation)
        {
            case 1:
                while (true)
                {
                    printf("Введите фамилию: ");
                    scanf("%s", &buffer);
                    if (strlen(buffer)==0)
                        printf("Поле не должно быть пустым!");
                    else
                    {
                        strcpy(contact->fio.surname, buffer);
                        break;
                    }
                }
                break;

            case 2:
                while (true)
                {
                    printf("Введите имя: ");
                    scanf("%s", &buffer);
                    if (strlen(buffer)==0)
                        printf("Поле не должно быть пустым!");
                    else
                    {
                        strcpy(contact->fio.name, buffer);
                        break;
                    }
                }
                break;

            case 3:
                printf("Введите отчество: ");
                scanf("%s", &contact->fio.partonymic);
                break;
                
            case 4:
                printf("Введите  место работы: ");
                scanf("%s", &contact->job.corp);

                printf("Введите  должность: ");
                scanf("%s", &contact->job.title);
                break;

            case 5:
                printf("1-изменить номер телефона 2-добавить номер телефона\n");
                scanf("%d", &sub_operation);

                count_phones = contact->phone[0].count;

                if (sub_operation==1)
                {
                    printf("Введите ID телефона для изменения: ");
                    scanf("%d", &ID);

                    if(ID >= count_phones)
                        printf("Данного номера не существует!");

                    else
                    {
                        printf("Укажите тип телефона: ");      
                        scanf("%s", &contact->phone[ID].phone_type);

                        printf("Укажите номер телефона: ");      
                        scanf("%s", &contact->phone[ID].number);
                    }
                }

                else if (sub_operation==2)
                {
                    if(count_phones == 5)
                        printf("Достигнуто максимальное количество номеров телефона!");
                    else
                    {    
                        printf("Укажите тип телефона: ");      
                        scanf("%s", &contact->phone[count_phones].phone_type);

                        printf("Укажите номер телефона: ");      
                        scanf("%s", &contact->phone[count_phones].number);

                        for(int i = 0; i <= count_phones; i++)
                            contact->phone[i].count++;
                        
                    }
                }
                break;

            case 6:
                printf("1-изменить адрес 2-добавить адрес\n");
                scanf("%d", &sub_operation);

                count_email = contact->email[0].count;

                if (sub_operation==1)
                {
                    printf("Введите ID электронного адреса для удаления: ");
                    scanf("%d", &ID);
                    
                    if(ID >= count_email)
                        printf("Данного адреса не существует!");

                    else
                    {
                        printf("Укажите номер телефона: ");      
                        scanf("%s", &contact->email[ID].email);
                    }
                }

                else if (sub_operation==2)
                {
                    if(count_email == 5)
                        printf("Достигнуто максимальное количество адресов!");
                    else    
                            printf("Укажите адрес: ");      
                            scanf("%s", &contact->email[count_email].email);

                            for(int i = 0; i <= count_email; i++)
                                contact->email[i].count++;
                }
                break;

            case 7:
                printf("1-изменить соцсеть 2-добавить соцсеть\n");
                scanf("%d", &sub_operation);

                count_socials = contact->socials[0].count;

                if (sub_operation==1)
                {
                    printf("Введите ID соцсети для удаления: ");
                    scanf("%d", &ID);
                    
                    if(ID >= count_socials)
                        printf("Данной соцсети не существует!");

                    else
                    {
                        printf("Укажите соцсеть: ");      
                        scanf("%s", &contact->socials[ID].name);

                        printf("Укажите ссылку на страницу: ");      
                        scanf("%s", &contact->socials[ID].url);
                    }
                    
                }

                else if (sub_operation==2)
                {
                    if(count_socials == 5)
                        printf("Достигнуто максимальное количество соцсетей!");
                    else    
                            printf("Укажите название соцсети: ");      
                            scanf("%s", &contact->socials[count_socials].name);

                            printf("Укажите ссылку на страницу: ");      
                            scanf("%s", &contact->socials[count_socials].url);

                            for(int i = 0; i <= count_socials; i++)
                                contact->socials[i].count++;
                }
                break;

            case 8:
                printf("1-изменить мессенджер 2-добавить мессенджер\n");
                scanf("%d", &sub_operation);

                count_messengers = contact->messengers[0].count;

                if (sub_operation==1)
                {
                    printf("Введите ID мессенджера для удаления: ");
                    scanf("%d", &ID);
                    
                    if(ID >= count_messengers)
                        printf("Данной соцсети не существует!");

                    else
                    {
                        printf("Укажите мессенджер: ");      
                        scanf("%s", &contact->messengers[ID].name);

                        printf("Укажите ник: ");      
                        scanf("%s", &contact->messengers[ID].nickname);
                    }
                    
                }

                else if (sub_operation==2)
                {
                    if(count_messengers == 5)
                        printf("Достигнуто максимальное количество номеров телефона!");
                    else    
                            printf("Укажите мессенджер: ");      
                            scanf("%s", &contact->messengers[count_messengers].name);

                            printf("Укажите ник: ");      
                            scanf("%s", &contact->messengers[count_messengers].nickname);

                            for(int i = 0; i <= count_messengers; i++)
                                contact->messengers[i].count++;
                }
                break;
                
            default:
                return;     
        }
    }
}

void remove_contact(Contact *contact)
{
    strcpy(contact->fio.surname, "");
    strcpy(contact->fio.name, "");
    strcpy(contact->fio.partonymic, "");
    strcpy(contact->job.corp, "");
    strcpy(contact->job.title, "");
    contact->phone[0].count = 0;
    contact->email[0].count = 0;
    contact->socials[0].count = 0;
    contact->messengers[0].count = 0;
}

int elem_in_arr(int *deleted, int count)
{
    bool flag = false;
    int elem;

    for(int i = 0; i < 21; i++)
        if (deleted[i] != -1)
        {
            flag = true;
            elem = deleted[i];
            deleted[i] = -1;
            break;
        }
    if (flag)
        return elem;
    else
        return count;
}

int main()
{
    Contact contacts[21];
    int deleted_list[21];
    int action;
    int count = 0;
    //bool shutdown = false;
    int ID;

    for (int i = 0; i < 21; i++)
    {
        deleted_list[i] = -1;
    }

    while (true)
    {
        //if (shutdown)
          //  break;

        printf("\nДобро пожаловать в список контактов! Выберите желаемое действие:\n1-добавить контакт\n2-редактировать контакт\n3-удалить контакт\n4-просмотр списка контактов\n");
        printf("Для закрытия программы нажмите любую другую кнопку\n");
        scanf("%d", &action);

        switch(action)
        {
            case 1:
                add(&contacts[elem_in_arr(deleted_list, count)], elem_in_arr(deleted_list, count));
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

                remove_contact(&contacts[ID]);
                

                for(int i = 0; i < 21; i++)
                    if(deleted_list[i]==-1)
                    {
                        deleted_list[i] = ID;
                        break;
                    }

                break;

            case 4:
                for (int i = 0; i < count; i++)
                {
                    int phone_count = contacts[i].phone[0].count;
                    int email_count = contacts[i].email[0].count;
                    int social_count = contacts[i].socials[0].count;
                    int messenger_count = contacts[i].messengers[0].count;

                    printf("\nID: %d\n", contacts[i].id);
                    printf("%s\n", contacts[i].fio.surname);
                    printf("%s\n", contacts[i].fio.name);
                    printf("%s\n", contacts[i].fio.partonymic);
                    printf("%s\n", contacts[i].job.corp);
                    printf("%s\n", contacts[i].job.title);

                    for (int j = 0; j < phone_count; j++)
                    {
                        printf("Phone ID: %d\n", contacts[i].phone[j].ID);
                        printf("%s\n", contacts[i].phone[j].phone_type);
                        printf("%s\n", contacts[i].phone[j].number);
                    }

                    for (int j = 0; j < email_count; j++)
                    {
                        printf("Email ID: %d\n", contacts[i].email[j].ID);
                        printf("%s\n", contacts[i].email[j].email);
                    }

                    for (int j = 0; j < social_count; j++)
                    {
                        printf("Social ID: %d\n", contacts[i].socials[j].ID);
                        printf("%s\n", contacts[i].socials[j].name);
                        printf("%s\n", contacts[i].socials[j].url);
                    }

                    for (int j = 0; j < messenger_count; j++)
                    {
                        printf("Messenger ID: %d\n", contacts[i].messengers[j].ID);
                        printf("%s\n", contacts[i].messengers[j].name);
                        printf("%s\n", contacts[i].messengers[j].nickname);
                    }
                    
                }
                break;
            
            default:
                return 0;
        }
    }
}