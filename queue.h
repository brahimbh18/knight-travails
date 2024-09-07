#ifndef knightMoves
#define knightMoves
#include "Moves.h"
#endif  // knightMoves

typedef struct Node Node;
struct Node
{
    MovesList *moves;
    Node *next;
};

typedef struct Queue
{
    Node *head;
    Node *tail;
}Queue;


Queue *QueueInit();
void QueueAdd(Queue *, MovesList *);
void QueuePop(Queue *);
Node *QueueFirstElement(Queue *queue); 
unsigned QueueEmpty(Queue *queue);