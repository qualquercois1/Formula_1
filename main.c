#include <stdio.h>
#include "read.h"
#include "write.h"
#include "process.h"
#include "order.h"

#define MAX_TEAMS 20
#define MAX_PILOTS 40

int main(int argc, char *argv[]) {
    char *inputFile = argv[1];
    char *outputFile = argv[2];
    
    Team *setTeams = (Team *)malloc((MAX_TEAMS+1) * sizeof(Team));
    int numTeams = 0;
    
    Pilot *pilots = NULL;
    int numPilots = 0;
    
    readFile(inputFile, setTeams, &numTeams, &numPilots);
    processTeamPoints(setTeams, numTeams);
    pilots = createPilotsArray(setTeams, numTeams, numPilots);
    orderPilots(pilots, numPilots);
    orderTeams(setTeams, numTeams);
    writeResult(outputFile, setTeams, pilots, numTeams, numPilots);
    
    //liberando memoria alocada
    for(int i=0; i<numTeams; i++) {
        for(int j=0; j<2; j++) {
            free(setTeams[i].pilots[j].name);
            free(setTeams[i].pilots[j].pos);
        }
        free(setTeams[i].name);
    }
    free(setTeams);
    free(pilots);
    return 0;  
}