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
    head = enqueue(head, 17, 1);
    head = enqueue(head, 13, 6);
    head = enqueue(head, 55, 4);
    head = enqueue(head, 90, 8);
    head = enqueue(head, 102, 10);
    
    print_queue(head);
    
    printf("\n%d\n", pop(head));
    printf("\n%d\n\n", pop(head));
    
    
    print_queue(head);
    printf("\n%d\n\n", pop(head));
    printf("\n%d\n\n", pop(head));
}  