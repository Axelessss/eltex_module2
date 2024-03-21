#include <stdio.h>
#include <stdbool.h>
#include <string.h>

#define N 50
#define M 20
#define U 100

typedef struct FIO
{
    char surname[N];
    char name[N];
    char partonymic[N];
}FIO;

typedef struct Job
{
    char corp[N];
    char title[N];
}Job;

typedef struct Phone
{
    char phone_type[M];
    char number[M];
}Phone;

typedef struct Email
{
    char email[N];
}Email;

typedef struct Social
{
    char name[M];
    char url[U];
}Social;

typedef struct Messenger
{
    char name[M];
    char nickname[M];
}Messenger;

typedef struct Contact
{
    int id;
    FIO fio;
    Job job;
    Phone phone[5];
    Email email[5];
    Social socials[5];
    Messenger messengers[5];
}Contact;


void add(Contact &contacts)
{

}

void add()
{
    char con;
    short operation;
    Contact contact;
    contact.id = 0;
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
            strncpy(contact.fio.surname, buffer, N);
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
            strncpy(contact.fio.name, buffer, N);
            break;
        }
    }
    

    printf("Желаете ли продолжить заполнение? Д/н");
    scanf("%c", &con);
    if (con == 'Д'||con == 'д')
        while (true)
        {       
            if (shutdown)
                break;

            printf("Что заполнить:\n1-Отчество\n2-Место работы\n3-Должность\n4-Номер телефона\n5-E-mail\n6-Соцсети\n7-Мессенджеры\nЛюбая другая кнопка - Выход");
            scanf("%d", &operation);
            switch(operation)
            {
                case 1:
                    printf("Введите отчество");
                    fgets(contact.fio.partonymic, sizeof(contact.fio.partonymic), stdin);
                    break;
                
                case 2:
                    printf("Введите  место работы");
                    fgets(contact.job.corp, sizeof(contact.job.corp), stdin);

                    printf("Введите  должность");
                    fgets(contact.job.title, sizeof(contact.job.title), stdin);
                    break;
                
                case 3:
                    printf ("Введите количество номеров телефона: ");
                    scanf("%d", &count);
                    for(int i=0;i<count;i++)
                    {
                        printf("Укажите тип телефона: ");      
                        fgets(contact.phone[i].phone_type, sizeof(contact.phone[i].phone_type), stdin);

                        printf("Укажите номер телефона: ");      
                        fgets(contact.phone[i].number, sizeof(contact.phone[i].number), stdin);
                    }
                    break;

                case 4:
                    printf ("Введите количество номеров телефона: ");
                    scanf("%d", &count);
                    for(int i=0;i<count;i++)
                    {
                        printf("Укажите тип телефона: ");      
                        fgets(contact.phone[i].phone_type, sizeof(contact.phone[i].phone_type), stdin);

                        printf("Укажите номер телефона: ");      
                        fgets(contact.phone[i].number, sizeof(contact.phone[i].number), stdin);
                    }
                    break;

                case 5:
                    printf ("Введите количество e-mail адресов: ");
                    scanf("%d", &count);
                    for(int i=0;i<count;i++)
                    {
                        printf("Введите электронный адрес: ");      
                        fgets(contact.phone[i].number, sizeof(contact.phone[i].number), stdin);
                    }
                    break;

                case 6:
                    printf ("Введите количество профилей в соцсетях: ");
                    scanf("%d", &count);
                    for(int i=0;i<count;i++)
                    {
                        printf("Укажите название соцсети: ");      
                        fgets(contact.phone[i].phone_type, sizeof(contact.phone[i].phone_type), stdin);

                        printf("Укажите ссылку на ваш профиль: ");      
                        fgets(contact.phone[i].number, sizeof(contact.phone[i].number), stdin);
                    }
                    break;

                case 7:
                    printf ("Введите количество профилей в мессенджерах: ");
                    scanf("%d", &count);
                    for(int i=0;i<count;i++)
                    {
                        printf("Укажите название мессенджера: ");      
                        fgets(contact.phone[i].phone_type, sizeof(contact.phone[i].phone_type), stdin);

                        printf("Укажите имя пользователя: ");      
                        fgets(contact.phone[i].number, sizeof(contact.phone[i].number), stdin);
                    }
                    break;
                
                default:
                    shutdown = true;
                    break;
                
            }
        }
}

int main()
{
    Contact contacts[21];


}