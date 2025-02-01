#include <stdio.h>
#include "read.h"
#include "write.h"
#include "process.h"
#include "order.h"

#define MAX_TEAMS 20
#define MAX_PILOTS 40

int main() {
    char *inputFile = "input.md";
    char *outputFile = "output.md";
    
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
    
    free(setTeams);
    free(pilots);
    return 0;
}