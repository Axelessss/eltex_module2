typedef struct Node
{
    int priority;
    int data;
    struct Node *next;
    struct Node *prev;
}Node;

typedef struct Queue
{
    Node *front;
    Node *rear;
}Queue;

Queue *new_list();
void insert( Queue *head, int x, int priority);
int pop(Queue *front, int priority);
void print_queue(Queue *head);