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
    head->front->rear = head->rear;
    head->rear->front = head->front;
    //head=head->front;
    //head = head->rear;
    return head;
}

int pop(Queue *head)
{
    Queue *tmp;
    int data;

    if(head == NULL)
    {
        printf("Queue empty!");
        return 0;
    }
        //printf("%p: %p", head, head->front);
        tmp = head->front;
        data = tmp->data;
        head->front = head->front->next;
        head = head->rear;
        free(tmp);
    return data;
}

int pop_priority(Queue *head, unsigned priority)
{
    Queue *tmp;
    Queue *buf;
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
        //head->front = head->front->next;
    }
    while(tmp->next != NULL)
    {
        if(tmp->priority == priority)
        {
            data = tmp->next->data;
            buf = tmp;
            tmp = tmp->next;
            //data = buf->data;
            free(buf);
            return data;
        }
        tmp = tmp->next;
    }

    if(tmp->next == NULL)
    {
        printf("Wrong priority");
        return 0;
    }
    return 0;
}

int pop_under_priority(Queue *head, unsigned priority)
{
    //Queue *tmp;
    //int data;

    if(head == NULL)
    {
        printf("Queue empty!");
        return 0;
    }
    printf("Priority: %d\n", head->front->priority);

    if(head->front->priority <= priority)
        return pop(head);
    
    else
        printf("Wrong priority");

    return 0;
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