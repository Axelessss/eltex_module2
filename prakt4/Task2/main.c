#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "queue.h"

int main()
{
    Queue *head = NULL;
    int action;
    int data;
    unsigned priority;
    unsigned size;
    head = new_list();

    while(true)
    {
        printf("Выберите желаемое действие:\n1-добавить элемент в очередь\n2-извлечь первый элемент\n3-извлечь элемент с указанным приоритетом");
        printf("\n4-извлечь элемент с приоритетом не ниже заданного\n5-сгенерировать очередь\n6-просмотреть очередь\nВыйти из программы - другой символ\n");
        scanf("%d", &action);

        switch(action)
        {
            case 1:
                printf("\nВведите элемент: ");
                scanf("%d", &data);

                printf("\nВведите приоритет(целое число от 0 до 255): ");
                scanf("%u", &priority);

                if(priority > 255)
                {
                    printf("\nПриоритет должен быть в диапазоне от 0 до 255\n");
                    continue;
                }

                insert(head, data, priority);
                break;
            
            case 2:
                printf("\nИзвлечённый элемент: %d\n", pop(head));
                break;

            case 3:
                printf("\nВведите приоритет(целое число от 0 до 255): ");
                scanf("%u", &priority);

                if(priority > 255)
                {
                    printf("\nПриоритет должен быть в диапазоне от 0 до 255\n");
                    continue;
                }

                printf("\nИзвлечённый элемент: %d\n", pop_priority(head, priority));
                break;
            
            case 4:
                printf("\nВведите приоритет(целое число от 0 до 255): ");
                scanf("%u", &priority);

                if(priority > 255)
                {
                    printf("\nПриоритет должен быть в диапазоне от 0 до 255\n");
                    continue;
                }

                printf("\nИзвлечённый элемент: %d\n", pop_under_priority(head, priority));
                break;

            case 5:
                printf("\nВведите размер очереди: ");
                scanf("%u", &size);

                for(unsigned i = 0; i < size; i++)
                {
                    data = rand()%1000;
                    priority = 0 + rand()%255;
                    
                    insert(head, data, priority);
                }
                break;

            case 6:
                print_queue(head);
                break;
            
            default:
                return 0;
        }
    }
}  