#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "queue.h"

Queue *new_list() 
{
    Queue *head = (Queue*)malloc(sizeof(Queue));
    head->front = NULL;
    head->rear = NULL;
    return head;
}

void insert(Queue *head, int data, unsigned priority)
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

int pop(Queue *head, int priority)
{
    Node *tmp, *buf;
    int data;

    if(head == NULL)
    {
        printf("Queue empty!");
        return 0;
    }

    tmp = head->front;

    if(priority == 0)
    {
        
        data = tmp->data;
        head->front = head->front->next;
        free(tmp);
    }

    else if(priority < 0)
    {
        priority = abs(priority);

        if(head->front->priority <= priority)
        {
            data = tmp->data;
            head->front = head->front->next;
            free(tmp);
        }
    
        else
        {
            printf("Wrong priority");
            return -1;
        }
    }

    else
    {
        if(tmp->priority == priority)
        {
            data = tmp->data;
            head->front = head->front->next;
            free(tmp);
            return data;
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
    
    }
    
    return data;
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