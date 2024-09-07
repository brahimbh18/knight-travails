#include "queue.h"

#include <stdlib.h>
#include <stdio.h>

Queue *QueueInit()
{
    Queue *tmp = malloc(sizeof(*tmp));
    tmp->head = NULL; 
    tmp->tail = NULL;
    return tmp;
}


void QueueAdd(Queue *queue, MovesList *moves)
{
    Node *new = (Node *)malloc(sizeof(Node));
    new->moves = moves;
    new->next = NULL;
    if (queue->head == NULL)
        queue->head = new;
    else
        queue->tail->next = new;
    queue->tail = new;
}

unsigned QueueEmpty(Queue *queue)
{
    return queue->head == NULL;
}

void QueuePop(Queue *queue)
{
    Node *tmp;
    if (QueueEmpty(queue))
        return;
    
    tmp = queue->head;
    if (queue->head == queue->tail)
    {
        queue->head = NULL;
        queue->tail = NULL;
    }
    else
        queue->head = tmp->next;
    
   free(tmp);
}

Node *QueueFirstElement(Queue *queue)
{
    if (!queue)
        return NULL;
    Node *head = malloc(sizeof(*head));
    head->moves = queue->head->moves;
    head->next = queue->head->next;
    return head;
}
/*
int main()
{
    Queue *q = QueueInit();
    MovesList *l = MovesListInit();
    MovesListAppend(l, 1, 2); 
    QueueAdd(q, l);
    
    //QueuePop(q);
    
    Node *n = QueueFirstElement(q);

    printf("%d \n", n->moves->last->Coords[1]);
    
    QueuePop(q);
    
    
    
    //MovesPrint(n->moves);
    while (!QueueEmpty(q))
    {
        QueuePop(q);
        if (n->moves)
            if (n->moves->last)
                if (n->moves->last->Coords)
                    printf("%d \n", n->moves->last->Coords[1]);
    }
    return 0;
}*/