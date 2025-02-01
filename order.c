#include "order.h"

void swapTeams(Team *teams, int a, int b) {
    Team temp = teams[a];
    teams[a] = teams[b];
    teams[b] = temp;
}

void swapPilots(Pilot *pilots, int a, int b) {
    Pilot temp = pilots[a];
    pilots[a] = pilots[b];
    pilots[b] = temp;
}

int firstPlace (Pilot a, Pilot b, int numPilots) {
    int i=0;
    do {
        if(a.pos[i] > b.pos[i]) {
            return 1;
        } else if (a.pos[i] > b.pos[i]) {
            return 2;
        } else {
            i++;
        }
    } while (i < numPilots);
    return 0;
}

void orderPilots(Pilot *pilots, int numPilots) { 
    //vou usar o bubblesort mesmo
    //deixar me ordem decrescente
    for(int i=0; i<numPilots-1; i++) {
        for(int j=i+1; j<numPilots; j++) {
            if(pilots[i].points < pilots[j].points) {
                swapPilots(pilots, i, j);
            } else if (pilots[i].points == pilots[j].points) {
                if(firstPlace(pilots[i],pilots[j], numPilots)==2){
                    swapPilots(pilots, i, j);
                }
            }
        }
    }
}

void orderTeams(Team *teams, int numTeams) { 
    //mesma ideia
    for(int i=0; i<numTeams-1; i++) {
        for(int j=i+1; j<numTeams; j++) {
            if(teams[i].points < teams[j].points) {
                swapTeams(teams, i, j);
            }
        }
    }
}