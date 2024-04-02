#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>
#include <curses.h>
#include "tree.h"

// Поиск с включением
void Ins_Btree(Contact *new_contact, btree **q) 
{
    if(*q == NULL) 
    {
        *q = (btree*)malloc(sizeof(btree));

        (*q)->left = (*q)->right = NULL;
        copy_contact(new_contact, &((*q)->contact));
        return;
    }

    if(cmp_contacts(&(*q)->contact, new_contact) == 1)
        Ins_Btree(new_contact, &(*q)->left);
    else
        Ins_Btree(new_contact, &(*q)->right);

}

// Печать содержимого дерева
void Print_Btree(btree *p) 
{
    if (p == NULL) 
        return;

    Print_Btree(p->left);
    printf("\n");
    print_contact(&(p->contact));//printf("%d ", p->value);
    printf("\n");
    Print_Btree(p->right);
}

// Удаление вершины с заданным значением key
int Delete(char *surname, char *name, btree **node) 
{
    btree *t, *up;

    Contact new_contact;

    strcpy(new_contact.fio.surname, surname);
    strcpy(new_contact.fio.name, name);

    if(*node == NULL) 
        return 0; // нет такого значения в дереве

    if(cmp_contacts(&(*node)->contact, &new_contact) == 0)  
    {
        // если значение находится в листе, то удаляем лист
        if(((*node)->left == NULL) && ((*node)->right == NULL)) 
        {
            free(*node);
            *node = NULL;
            printf("Delete List\n");
            return 1;
        }

        // если у вершины только правый потомок, то перебрасываем
        // связь на вершину ниже удаляемой в правом поддереве
        if((*node)->left == NULL) 
        {
            t = *node;
            *node =(*node)->right;
            free(t);
            printf("Delete Left = 0\n");
            return 1;
        }

        // если у вершины только левый потомок, то перебрасываем
        // связь на вершину ниже удаляемой в левом поддереве
        if((*node)->right == NULL) 
        {
            t = *node;
            *node =(*node)->left;
            free(t);
            printf("Delete Right = 0\n");
            return 1;
        }

        // если у вершины два потомка, то заменяем удаляемое значение
        // на значение самого правого элемента в левом поддереве
        up = *node;
        t = (*node)->left; // идем в левое поддерево

        //спускаемся до крайнего правого узла
        while (t->right != NULL) 
        {
            up = t;
            t = t-> right;
        }

        //копируем значение из правого узла вместо удаляемого значения
        copy_contact(&(t->contact), &((*node)->contact));

        // если ниже удаляемого больше, чем одна вершина
        if (up != (*node)) 
        {
            // если крайний правый не лист, то «отбрасываем» его из дерева
            if(t->left != NULL) 
                up->right = t->left;

            else 
                up->right = NULL; // удаляем лист
        }

        // если ниже удаляемого одна вершина, удаляем лист
        else 
            (*node)->left = t->left;

        // освобождаем память – удаляем крайнюю
        // правую вершину
        free(t);
        printf("Delete Two\n");
        return 1;
    }

    // поиск ключа в левом или правом поддереве
    if(cmp_contacts(&((*node)->contact), &new_contact) == -1)
        return Delete(new_contact.fio.surname, new_contact.fio.name, &(*node)->right);

    return Delete(new_contact.fio.surname, new_contact.fio.name, &(*node)->left);
}