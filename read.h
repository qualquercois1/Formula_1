#ifndef __READ_H
#define __READ_H
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    //nome do piloto
    char *name;
    //pontuação, numero de vitorias e numero de podiums
    int points, vic, podium;
    //vetor de posições, (indice)1 = quantas vezes chegou em primeiro lugar e assim por diante
    int *pos;
} Pilot;

typedef struct {
    //nome da equipe
    char *name;
    //pontuação total da equipe
    int points;
    //ponteiro para os pilotos da equipe
    Pilot pilots[2];
} Team;

void readFile(char *fileName, Team *setTeams, int *numTeams, int *numPilots);

void insertSet(char *pilotName, char *teamName, Team *setTeams, int *numTeams, int *numPilots);

void stepRead(Team *setTeams, int numTeams, int position, char *name);

#endif