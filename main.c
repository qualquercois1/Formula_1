#include <stdio.h>
#include "read.h"
#include "write.h"
#include "process.h"
#include "order.h"

#define MAX_TEAMS 20
#define MAX_PILOTS 40

void printSetTeams(Team *setTeams, int numTeams, int numPilots) {
    for (int i = 0; i < numTeams; i++) {
        printf("%d %s %d\n", i+1, (setTeams)[i].name, (setTeams)[i].points);
    }
    printf("---\n");
}

void printPilots(Pilot *pilots, int numPilots) {
    for(int i=0; i<numPilots; i++) {
        printf("%d %s %d %d %d\n", i+1, pilots[i].name, pilots[i].points, pilots[i].vic, pilots[i].podium);
    }
    printf("---\n");
}

int main() {
    char *inputFile = "input.md";
    //char *outputFile = "output.md";
    
    Team *setTeams = (Team *)malloc((MAX_TEAMS+1) * sizeof(Team));
    int numTeams = 0;
    
    Pilot *pilots = NULL;
    int numPilots = 0;
    
    readFile(inputFile, setTeams, &numTeams, &numPilots);
    processTeamPoints(setTeams, numTeams);
    pilots = createPilotsArray(setTeams, numTeams, numPilots);
    orderPilots(pilots, numPilots);
    orderTeams(setTeams, numTeams);
    printPilots(pilots, numPilots);
    printSetTeams(setTeams, numTeams, numPilots);
    
    free(setTeams);
    free(pilots);
    return 0;
}