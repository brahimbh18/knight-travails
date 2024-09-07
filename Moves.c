#include "Moves.h"
#include <stdlib.h>
#include <stdio.h>

MovesList *MovesListInit()
{
    MovesList *l = malloc(sizeof(*l));
    l->first = NULL;
    l->last == NULL;
    return l;
}

Move *MoveInit(int l, int c)
{
    Move *move = malloc(sizeof(*move));
    move->Coords[0] = l;
    move->Coords[1] = c;
    move->next = NULL;
    return move;
}


void MovesListAppend(MovesList *list, int l, int c)
{
    Move *new = MoveInit(l, c);
    
    if (list->first == NULL)
        list->first = new;
    else
        list->last->next = new;    
    list->last = new;
}

void printBoard(int *t)
{
    char board[8][8];
    for (int i = 0; i < 8; i++)
        for (int j = 0; j < 8; j++)
            board[i][j] = '-';

    if (t)
        
        printf("(%d, %d)\n", 8-t[0], t[1]);//board[8-t[0]][t[1]] = 'X';
    

    for (int i = 0; i < 8; i++) 
    {
        printf("%d|", 8 -i);
        for (int j = 0; j < 8; j++)
            printf("%c|", board[i][j]);
        printf("\n");
    }   
    printf(" "); 
    for (int i = 97; i < 105; i++)
        printf(" %c", i);       
    printf("\n");
}

void MovesPrint(MovesList *list)
{
    for (Move *tmp = list->first; tmp != NULL; tmp = tmp->next)
        printBoard(tmp->Coords);
}


MovesList *MovesCopy(MovesList *l)
{
    MovesList *tmp = MovesListInit();
    for (Move *m = l->first; m != NULL; m = m->next)
    {
        MovesListAppend(tmp, m->Coords[0], m->Coords[1]);
    }

    return tmp;
}

void MovesDel(MovesList *l)
{
    for (Move *m = l->first; m != NULL; m = m->next)
    {
        
    }
}
/*
int main()
{
    int t[2] = {4, 4};
    //printBoard(NULL);
    printBoard(t);  

    return 0;
}*/