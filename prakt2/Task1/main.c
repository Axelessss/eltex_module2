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
    char phone[M];
}Phone;

typedef struct Email
{
    char email[N];
}Email

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


void add(struct contact &contacts)
{

}

void add()
{
    char con;
    short operation;
    new_contact = new contact();
    new_contact.id = 0;
    printf("Введите фамилию: ");
    fgets(new_contact.surname, sizeof(new_contact.surname, stdin));
    printf("Введите имя: ");
    fgets(new_contact.name, sizeof(new_contact.name, stdin));

    printf("Желаете ли продолжить заполнение? Д/н")
    scanf("%c", &con);
    if (con == 'Д'||con == 'д')
        while (true)
        {       
            printf("Что заполнить:\n1-Отчество\n2-Место работы\n3-Должность\n4-Номер телефона\n5-E-mail\n6-Соцсети\n7-Мессенджеры");
            scanf("%d", &operation);
            switch(operation)
            {
                case 1:
                    printf("Введите отчество");
                    fgets(new_contact.partonymic, sizeof(new_contact.partonymic), stdin);
                    break;
                
                case 2:
                    printf("Введите  место работы");
                    fgets(new_contact.partonymic, sizeof(new_contact.partonymic), stdin);
                    break;
                
                case 2:
                    printf("Введите должность");
                    fgets(new_contact.partonymic, sizeof(new_contact.partonymic), stdin);
                    break;

                case 2:
                    printf("Введите отчество");
                    fgets(new_contact.partonymic, sizeof(new_contact.partonymic), stdin);
                    break;

                case 2:
                    printf("Введите отчество");
                    fgets(new_contact.partonymic, sizeof(new_contact.partonymic), stdin);
                    break;

                case 2:
                    printf("Введите отчество");
                    fgets(new_contact.partonymic, sizeof(new_contact.partonymic), stdin);
                    break;

                case 2:
                    printf("Введите отчество");
                    fgets(new_contact.partonymic, sizeof(new_contact.partonymic), stdin);
                    break;
                
            }
        }
}

int main()
{
    struct contact contacts[21];


}