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

void orderPilots(Pilot *pilots, int numPilots) { 
    //vou usar o bubblesort mesmo
    //deixar me ordem decrescente
    for(int i=0; i<numPilots-1; i++) {
        for(int j=i+1; j<numPilots; j++) {
            if(pilots[i].points < pilots[j].points) {
                swapPilots(pilots, i, j);
            } //else if ... fazer o caso em que eles empatam
        }
    }
}

void orderTeams(Team *teams, int numTeams) { 
    //mesma ideia
    for(int i=0; i<numTeams-1; i++) {
        for(int j=i+1; j<numTeams; j++) {
            if(teams[i].points < teams[j].points) {
                swapTeams(teams, i, j);
            } //else if ... fazer o caso em que eles empatam
        }
    }
}