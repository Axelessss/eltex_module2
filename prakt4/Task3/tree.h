#include "contact.h"

typedef struct btree 
{
    char val[20];
    Contact contact;
    struct btree *left, *right;
} btree;

void Ins_Btree(Contact *new_contact, btree **q);
void Print_Btree(btree *p);
int Delete(char *surname, char *name, btree **node);
void Change_Contact(char *surname, char *name, btree **node);
void Print_Contact(char *surname, char *name, btree **node);