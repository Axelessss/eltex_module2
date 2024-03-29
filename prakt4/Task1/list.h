#include "contact.h"
typedef struct List
{
    Contact contact;
    struct List* next;
    struct List* prev;
}List;