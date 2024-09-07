#include <stdio.h>
#include <stdlib.h>
#include "queue.h"
#include "Moves.h"

int KNIGHT_MOVES[8][2] = {
    { 1, 2}, 
    { 1,-2}, 
    {-1, 2}, 
    {-1,-2}, 
    { 2, 1},    
    { 2,-1}, 
    {-2, 1}, 
    {-2,-1} 
    };

int BOARD[8][8]; 

void printBoard();
unsigned isValidMove(int, int);
void shortestKnightPath(int *, int *);
void BoardInit();

int main()
{
    printf("Welcome to knight travails\n");
    BoardInit();
    printBoard(NULL);

    int *start, *dest;
    start = (int *)malloc(2 * sizeof(int));
    dest = (int *)malloc(2 * sizeof(int));
    start[0] = 0; 
    start[1] = 0; 
    dest[0] = 1; 
    dest[1] = 2; 
    shortestKnightPath(start, dest);

    
}

/*

void printBoard(int *i, int *j)
{
    char board[8][8];
    for (int i = 0; i < 8; i++)
        for (int j = 0; j < 8; j++)
            board[i][j] = '-';

    if (i && j)
        board[*i][*j] = 'X';

    for (int i = 0; i < 8; i++) 
    {
        printf("%d|", 8 -i);
        for (int j = 0; j < 8; j++)
            printf("-|");
        printf("\n");
    }   
    printf(" "); 
    for (int i = 97; i < 105; i++)
        printf(" %c", i);       
    printf("\n");
}
*/

void markVisited(int i, int j)
{
    BOARD[i][j] = 1;
}

unsigned visited(int i, int j)
{
    return BOARD[i][j] == 1;
}

unsigned isValidMove(int i, int j)
{
    return i >= 0 && i < 8 && j >= 0 && j < 8 && !visited(i, j);
}

void shortestKnightPath(int *start, int *dest)
{
    if (start[0] == dest[0] && start[1] == dest[1])
    {
        printf("You are already there!");
        return;
    }
    
    MovesList *moves = MovesListInit();
    MovesListAppend(moves, start[0], start[1]);
    Queue *queue = QueueInit();
    
    //MovesListAppend(moves, 7, 7);
    QueueAdd(queue, moves); 
    Node *tmp;
 
    
    while (!QueueEmpty(queue))
    {
        tmp = QueueFirstElement(queue);
        QueuePop(queue);
        int l = tmp->moves->last->Coords[0];
        int c = tmp->moves->last->Coords[1];
        
        //printf("%d \n", tmp->moves->last->Coords[1]);

      
        for (int i = 0; i < 8; i++)
        {
            int l2 = KNIGHT_MOVES[i][0] + l;
            int c2 = KNIGHT_MOVES[i][1] + c;
         
            if (isValidMove(l2, c2))
            {
                markVisited(l2, c2);
                MovesList *cpy = MovesCopy(tmp->moves);
                MovesListAppend(cpy, l2, c2);
                //MovesDel(cpy);
                if (l2 == dest[0] && c2 == dest[1])
                    MovesPrint(cpy);
                else
                    QueueAdd(queue, cpy);
            }   
        }
    } 
    
    
    
    /* 
    while (!QueueEmpty(queue))
    {

        tmp = QueueFirstElement(queue);
        
        int l = tmp->moves->last->Coords[0];
        int c = tmp->moves->last->Coords[1];
        
        for (int i = 0; i < 8; i++)
        {
            int l2 = KNIGHT_MOVES[i][0] + l;
            int c2 = KNIGHT_MOVES[i][1] + c;
            if (isValidMove(l2, c2))
            {
                
                
                MovesListAppend(tmp->moves, l2, c2);
                if (l == dest[0] && c == dest[1])
                    printf("haha\n");//MovesPrint(moves);
                else 
                    QueueAdd(queue, tmp->moves); 
                
            }
        }
        
        QueuePop(queue);
    }
         */
         
  
}

void BoardInit()
{
    for (int i = 0; i < 8; i++)
        for (int j = 0; j < 8; j++)
            BOARD[i][j] = 0;
 
}