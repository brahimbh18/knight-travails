#ifndef MOVE_H
#define MOVE_H
typedef struct Move Move;
struct Move
{
    int Coords[2];
    Move *next;
};

typedef struct MovesList MovesList;
struct MovesList
{
    Move *first, *last;
};   

#endif // MOVE_H

MovesList *MovesListInit();
void MovesListAppend(MovesList *, int, int);
void MovesPrint(MovesList *);
MovesList *MovesCopy(MovesList *);
void printBoard(int *);
