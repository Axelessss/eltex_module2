#include <stdio.h>
#include <stdlib.h>
#include "queue.h"

Queue *new_list() 
{
    Queue *head = (Queue*)malloc(sizeof(Queue));
    head->front = NULL;
    head->rear = NULL;
    return head;
}

void insert( Queue *head, int data, unsigned priority)
{
    Node* buf = (Node*)malloc(sizeof(Node));
    Node* tmp;

	buf->data = data;
    buf->priority = priority;
    buf->next = NULL;

    if(head->front == NULL)
    {
        head->front = buf;
        head->rear = buf;
        return;
    }
    

    if(head->front->priority > buf->priority)
    {
        buf->next = head->front;
        head->front = buf;
        return;
    }

    tmp = head->front;

    while(tmp->next != NULL)
    {
        if(buf->priority < tmp->next->priority)
        {
            buf->next = tmp->next;
            tmp->next = buf;
            return;
        }
        tmp = tmp->next;
    }
    tmp->next = head->rear = buf;
    
    return;
}

int pop(Queue *head)
{
    Node *tmp;
    int data;

    if(head == NULL)
    {
        printf("Queue empty!");
        return 0;
    }
        tmp = head->front;
        data = tmp->data;
        head->front = head->front->next;
        free(tmp);
    return data;
}

int pop_priority(Queue *head, unsigned priority)
{
    Node *tmp, *buf;
    int data;

    if(head == NULL)
    {
        printf("Queue empty!");
        return 0;
    }

    tmp = head->front;

    if(tmp->priority == priority)
    {
        return pop(head);
    }

    while(tmp->next != NULL)
    {
        if(tmp->next->priority == priority)
        {
            if(tmp->next == head->rear)
            {
                head->rear = tmp;
            }

            buf = tmp->next;
            data = buf->data;
            tmp->next = tmp->next->next;
            free(buf);
            return data;
        }
        tmp = tmp->next;
    }

    if(tmp->next == NULL)
    {
        printf("Wrong priority");
    }
    return -1;
}

int pop_under_priority(Queue *head, unsigned priority)
{

    if(head == NULL)
    {
        printf("Queue empty!");
        return 0;
    }

    if(head->front->priority <= priority)
        return pop(head);
    
    else
        printf("Wrong priority");

    return -1;
}

void print_queue(Queue *head)
{
    Node* tmp = head->front;
    printf("\n");
    if (NULL == head) 
    {
        printf("List empty!\n");
        return;
    }

    do 
    {
        printf("Данные: %d  Приоритет: %d\n", tmp->data, tmp->priority);
        tmp = tmp->next;
    } while (tmp != NULL);

    printf("\n");
}