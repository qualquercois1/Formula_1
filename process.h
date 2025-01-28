#ifndef __PROCESS_H
#define __PROCESS_H

#include "read.h"

void processTeamPoints(Team *setTeams, int numTeams);

Pilot* createPilotsArray(Team *setTeams, int numTeams, int numPilots);

#endif