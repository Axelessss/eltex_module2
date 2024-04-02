#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>
#include "list.h"

List* InsertContact(List* head) 
{
    List* newItem = (List*)malloc(sizeof(struct List));
    List* tmp = head;
    add(&(newItem->contact));

    // Вставка элемента в пустой список
    if(NULL == head) 
    {
        newItem->prev = newItem;
        newItem->next = newItem;
        head = newItem;
        return head;
    }

    // Вставка элемента в начало или середину списка
    do 
    {   
        if(cmp_contacts(&(newItem->contact), &(tmp->contact))<=0) 
        {
            newItem->next = tmp;
            newItem->prev = tmp->prev;
            tmp->prev->next = newItem;
            tmp->prev = newItem;

            if(tmp == head)
                head = newItem;

            return head;
            
        }
        tmp = tmp->next;

    } while(tmp != head);

    // Вставка элемента в конец списка
    newItem->next = tmp;
    newItem->prev = tmp->prev;
    tmp->prev->next = newItem;
    tmp->prev = newItem;
    return head;
}

List* ChangeContact(char* surname, char* name, List* head)
{
    List* tmp = head;

    if(NULL == head) 
    {
        printf("\nList empty!\n");
        return head;
    }

    // Вставка элемента в начало или середину списка
    do 
    {
        if(strcmp(tmp->contact.fio.surname, surname)==0 && strcmp(tmp->contact.fio.name, name)==0) 
        {
            change(&(tmp->contact));
            return head;
        }

        tmp = tmp->next;

    } while(tmp != head);

    printf("\nContact doesn\'t exists\n");
    return head;
}

List* DeleteContact(char *surname, char *name, List* head) 
{
    List *tmp = head;
    // Если пытаемся удалить элемент из пустого списка
    if (NULL == head) 
    {
        printf("\nList empty!\n");
        return head;
    }
    // Поиск и удаление элемента
    do 
    {
        if (strcmp(tmp->contact.fio.surname, surname)==0 && strcmp(tmp->contact.fio.name, name)==0) 
        {
            // Если удаляется единственный элемент списка
            if (tmp->next == tmp->prev)
            {
                free(tmp);
                return NULL;
            }
            // Перестраиваем связи
            tmp->next->prev = tmp->prev;
            tmp->prev->next = tmp->next;
            // Если элемент удаляется из начала списка, изменяем head
            if(tmp == head) 
                head = head->next;
            // Удаляем найденный элемент
            free(tmp);
            return head;
        }  
        tmp = tmp->next;
    } while (tmp != head);

    // Если элемент не найден, выводим сообщение
    printf("\nContact doesn\'t exists\n");
    return head;
}

List* DeleteList(List* head) 
{
    List* tmp = head;
    List* itemForRemove;
    if (NULL == head) 
    {
        return NULL;
    }   

    do 
    {
        itemForRemove = tmp;
        tmp = tmp->next;
        free(itemForRemove);
    } while (tmp != head);

    return NULL;
}

void PrintList(List* head) 
{
    List* tmp = head;
    if (NULL == head) 
    {
        printf("\nList empty!\n");
        return;
    }

    do 
    {
        print_contact(&(tmp->contact));
        printf("\n\n");
        tmp = tmp->next;
    } while (tmp != head);

    
}

void PrintContact(char* surname, char* name, List* head)
{
    List *tmp = head;
    // Если пытаемся удалить элемент из пустого списка
    if (NULL == head) 
    {
        printf("\nList empty!\n");
        return;
    }
    // Поиск и удаление элемента
    do 
    {
        if (strcmp(tmp->contact.fio.surname, surname)==0 && strcmp(tmp->contact.fio.name, name)==0) 
        {
            print_contact(&tmp->contact);
            return;
        }  
        tmp = tmp->next;
    } while (tmp != head);

    // Если элемент не найден, выводим сообщение
    printf("\nContact doesn\'t exists\n");
}
