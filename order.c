#include "order.h"

void swapTeams(Team *teams, int a, int b) {
    //troca dois times de lugar no vetor
    Team temp = teams[a];
    teams[a] = teams[b];
    teams[b] = temp;
}

void swapPilots(Pilot *pilots, int a, int b) {
    //troca dois pilotos de lugar no vetor
    Pilot temp = pilots[a];
    pilots[a] = pilots[b];
    pilots[b] = temp;
}

int firstPlace (Pilot a, Pilot b, int numPilots) {
    //verifica quem vem primeiro de acordo com o numero de chegadas
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
    //deixar em ordem decrescente
    for(int i=0; i<numPilots-1; i++) {
        for(int j=i+1; j<numPilots; j++) {
            if(pilots[i].points < pilots[j].points) {
                swapPilots(pilots, i, j);
            } else if (pilots[i].points == pilots[j].points) {
                //caso empatem deve-se avaliar o numero de chegadas
                if(firstPlace(pilots[i],pilots[j], numPilots)==2){
                    swapPilots(pilots, i, j);
                }
            }
        }
    }
}

void orderTeams(Team *teams, int numTeams) { 
    //mesma ideia da ordenação dos pilots so que agora não tem desempate
    for(int i=0; i<numTeams-1; i++) {
        for(int j=i+1; j<numTeams; j++) {
            if(teams[i].points < teams[j].points) {
                swapTeams(teams, i, j);
            }
        }
    }
}