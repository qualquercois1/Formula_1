#include "write.h"
#include <stdio.h>

void printTeams(FILE *file, Team *setTeams, int numTeams) {
    for (int i = 0; i < numTeams; i++) {
        fprintf(file,"%d %s %d\n", i+1, (setTeams)[i].name, (setTeams)[i].points);
    }
    fprintf(file, "---\n");
}

void printPilots(FILE *file, Pilot *pilots, int numPilots) {
    for(int i=0; i<numPilots; i++) {
        fprintf(file, "%d %s %d %d %d\n", i+1, pilots[i].name, pilots[i].points, pilots[i].vic, pilots[i].podium);
    }
    fprintf(file, "---\n");
}

void writeResult(const char *fileName, Team *teams, Pilot *pilots, int numTeams, int numPilots){
    FILE *file = fopen(fileName, "w");

    printPilots(file, pilots, numPilots);
    printTeams(file, teams, numTeams);
}