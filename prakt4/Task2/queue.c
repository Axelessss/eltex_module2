#include <stdio.h>
#include <stdlib.h>
#include "queue.h"

Queue* enqueue( Queue *head, int data, unsigned priority)
{
    Queue* buf = (Queue*)malloc(sizeof(Queue));
    Queue* tmp;

	buf->data = data;
    buf->priority = priority;
    buf->next = NULL;

    if(head == NULL)
    {
        buf->rear = buf;
        buf->front = buf;
        return buf;
    }
    tmp = head->front;

    if(head->front->priority > buf->priority)
    {
        buf->next = head->front;
        head->front = buf;
        return head;
    }

    while(tmp->next != NULL)
    {
        if(buf->priority < tmp->next->priority)
        {
            buf->next = tmp->next;
            tmp->next = buf;
            return head;
        }
        tmp = tmp->next;
    }
    
    head->rear = head->rear->next = buf;
    
    return head;
}

int pop(Queue *head)
{
    if(head == NULL)
    {
        printf("Queue empty!");
        return 0;
    }

    Queue *tmp = head->front;
    int data = tmp->data;
    head->front = head->front->next;
    free(tmp);

    return data;
}

void print_queue(Queue *head)
{
    Queue* tmp = head->front;
    if (NULL == head) 
    {
        printf("List empty!\n");
        return;
    }

    do 
    {
        printf("%d\n", tmp->data);
        tmp = tmp->next;
    } while (tmp != NULL);

    printf("\n");
}