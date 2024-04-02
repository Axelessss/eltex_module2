typedef struct Queue
{
    unsigned priority;
    int data;
    struct Queue *front;
    struct Queue *rear;
    struct Queue *next;
}Queue;

Queue* enqueue( Queue *head, int x, unsigned priority);
int pop(Queue *front);
int pop_max_priority(Queue *head);
void print_queue(Queue *head);