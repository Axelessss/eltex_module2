typedef struct Node
{
    unsigned priority;
    int data;
    struct Node *next;
}Node;

typedef struct Queue
{
    Node *front;
    Node *rear;
}Queue;

Queue *new_list();
void insert( Queue *head, int x, unsigned priority);
int pop(Queue *front, int priority);
void print_queue(Queue *head);