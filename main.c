#include <stdio.h>
#include "read.h"
#include "write.h"
#include "process.h"
#include "order.h"

#define MAX_TEAMS 20
#define MAX_PILOTS 40

void printSetTeams(Team *setTeams, int numTeams, int numPilots) {
    for (int i = 0; i < numTeams; i++) {
        printf("Time %d: %s\n", i + 1, setTeams[i].name);
        printf("  Pontuação total: %d\n", setTeams[i].points);
        
        for (int j = 0; j < 2; j++) {
            printf("    Piloto %d: %s\n", j + 1, setTeams[i].pilots[j].name);
            printf("    Pontuação: %d\n", setTeams[i].pilots[j].points);
            printf("        Posições:\n");
            for(int k=0; k<numPilots; k++) {
                printf("        %dº: %d\n", k+1, setTeams[i].pilots[j].pos[k]);
            }
        }
        printf("\n");
    }
}

int main() {
    char *inputFile = "input.md";
    //char *outputFile = "output.md";
    
    Team *setTeams = (Team *)malloc((MAX_TEAMS+1) * sizeof(Team));
    int numTeams = 0;
    
    Pilot *pilots = (Pilot *)malloc((MAX_PILOTS+1) * sizeof(Pilot));
    int numPilots = 0;
    
    readFile(inputFile, setTeams, &numTeams, pilots, &numPilots);
    printSetTeams(setTeams, numTeams, numPilots);
    
    
    free(setTeams);
    free(pilots);
    return 0;
}