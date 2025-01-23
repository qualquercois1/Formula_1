#include "process.h"
#include "read.h"

void processTeamPoints(Team *setTeams, int numTeams) {
    for(int i=0; i<numTeams; i++) {
        int sum = 0;
        sum += (setTeams)[i].pilots[0].points;
        sum += (setTeams)[i].pilots[1].points;
        setTeams[i].points = sum;
    }
}

