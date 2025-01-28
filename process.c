#include "process.h"
#include "read.h"

void processTeamPoints(Team *setTeams, int numTeams) {
    for(int i=0; i<numTeams; i++) {
        int sum = 0;
        sum += (setTeams)[i].pilots[0].points + (setTeams)[i].pilots[1].points;
        setTeams[i].points = sum;
    }
    
    for(int i=0; i<numTeams; i++) {
        (setTeams)[i].pilots[0].vic = (setTeams)[i].pilots[0].pos[0];
        (setTeams)[i].pilots[1].vic = (setTeams)[i].pilots[1].pos[0];
    
        (setTeams)[i].pilots[0].podium += (setTeams)[i].pilots[0].pos[0] + (setTeams)[i].pilots[0].pos[1] + (setTeams)[i].pilots[0].pos[2];
        (setTeams)[i].pilots[1].podium += (setTeams)[i].pilots[1].pos[0] + (setTeams)[i].pilots[1].pos[1] + (setTeams)[i].pilots[1].pos[2];
    }
}

Pilot* createPilotsArray(Team *setTeams, int numTeams, int numPilots) {
    //cria o vetor de pilotos para ordenar depois
    Pilot *arr = malloc(numPilots * sizeof(Pilot));
    int j=0;
    for(int i=0; i<numTeams; i++) {
        arr[j++] = (setTeams)[i].pilots[0];
        arr[j++] = (setTeams)[i].pilots[1];
    }
    return arr;
}