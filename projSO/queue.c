
#include "queue.h"

 int queue_size (queue_t *queue)
{
    int size = 0;
    queue_t *aux = queue;

    if(queue == NULL){
        return 0;
    }
    else{
        while(queue->next != aux){
            queue = queue->next;
            size++;
            printf("%d",size);
        }
    }
    return 0;
}

void queue_print (char *name, queue_t *queue, void print_elem (void*) )
{
    queue_t *aux = queue;
    if(queue == NULL){
        printf("Fila vazia!");
    }
    else{
        while(queue->next != aux){
            print_elem (queue);
            queue = queue->next;
        }
    }
}

int queue_append (queue_t **queue, queue_t *elem)
{
    queue_t *aux = elem;
    queue_t *fim = (*queue);
    if( queue == NULL && elem != NULL){
        (*queue) = elem;
        (*queue)->prev = (*queue);
        (*queue)->next = (*queue);
        return 0;
    }
    else if ((*queue) != NULL && elem != NULL) {
        while((*queue)->next != fim){
            (*queue) = (*queue)->next;
        }
        aux->prev = (*queue);
        (*queue)->next = aux;
        return 0;
    }
    else{
        return 1;
    }
}

int queue_remove (queue_t **queue, queue_t *elem)
{
    queue_t *aux  = elem;
    queue_t *fim = (*queue);
    if( queue != NULL && elem != NULL){
        while((*queue)->next != fim){
            if((*queue) == elem){
                (*queue)->prev->next = aux->next;
                (*queue)->next->prev = aux->prev;
                aux->next = NULL;
                aux->prev = NULL;
            }
            else{
                (*queue)->next = (*queue)->next->next;
            }
        }
        return 0;
    }
    else{
        return 1;
    }
}
