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

void insert(Queue *pq, int data, int priority)
{
    Node *newNode = (Node *)malloc(sizeof(Node));
    newNode->data = data;
    newNode->priority = priority;

    if (pq->front == NULL) 
    {
        pq->front = newNode;
        pq->rear = newNode;
    } 

    else 
    {
        if (priority > pq->front->priority) 
        {
            newNode->next = pq->front;
            pq->front->prev = newNode;
            pq->front = newNode;

        } 

        else if (priority < pq->rear->priority) 
        {
            newNode->prev = pq->rear;
            pq->rear->next = newNode;
            pq->rear = newNode;
        } 
        
        else 
        {
            Node *curr = pq->front;
            while (curr->next != NULL && priority < curr->next->priority) 
            {
                curr = curr->next;
            }
            newNode->next = curr->next;
            if (curr->next != NULL) 
            {
                curr->next->prev = newNode;
            }
            curr->next = newNode;
            newNode->prev = curr;
        }
    }
}

int pop(Queue *head, int priority)
{
    Node *tmp, *buf;
    int data = -1;

    if(head == NULL)
    {
        printf("Queue empty!");
        return 0;
    }

    tmp = head->rear;

    if(priority == 0)
    {
        data = tmp->data;
        head->rear = head->rear->prev;
        head->rear->next = NULL;
        free(tmp);
    }

    else if(priority < 0)
    {
        priority = abs(priority);

        if(head->rear->priority <= priority)
        {
            data = tmp->data;
            head->rear = head->rear->prev;
            head->rear->next = NULL;
            free(tmp);
        }
    
        else
        {
            printf("Wrong priority");
        }
    }

    else
    {
        if(head->rear->priority == priority)
        {
            data = tmp->data;
            head->rear = head->rear->prev;
            head->rear->next = NULL;
            free(tmp);
        }
        
        else if(head->front->priority == priority && head->front->next->priority != priority)
        {
            data = head->front->data;
            buf = head->front;
            head->front = head->front->next;
            head->front->prev = NULL;
            free(buf);
            return data;
        }

        while(tmp->prev != NULL)
        {
            if(tmp->priority == priority)
            {
                data = tmp->data;
                tmp->next->prev = tmp->prev;
                tmp->prev->next = tmp->next;

                free(tmp);
                return data;
            }
            tmp = tmp->prev;
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