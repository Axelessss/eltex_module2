#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "queue.h"

int main()
{
    Queue *head = NULL;

    head = enqueue(head, 100, 2);
    head = enqueue(head, 8, 4);
    head = enqueue(head, 4, 3);
    head = enqueue(head, 3, 2);
    head = enqueue(head, 6, 1);
    head = enqueue(head, 10, 1);
    //head = enqueue(head, 20, 2);

    //printf("%d", head->front->data);
    print_queue(head);
    printf("\n%d\n\n", pop(head));
    //printf("\n%d\n", head->front->data);
    //printf("\n%d\n", head->rear->data);
    print_queue(head);
    printf("\n\n%d\n\n", pop(head));
    print_queue(head);
    //printf("%d\n", pop(head));
}