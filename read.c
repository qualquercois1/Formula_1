#include "read.h"

void insertSet(char *pilotName, char *teamName, Team *setTeams, int *numTeams, Pilot *pilots, int *numPilots) {
    Team *tempTeam = (Team *)malloc(sizeof(Team));
    Pilot *tempPilot = (Pilot *)malloc(sizeof(Pilot));
    
    // Cria o piloto 
    tempPilot->name = (char *)malloc((strlen(pilotName) + 1) * sizeof(char));
    strcpy(tempPilot->name, pilotName);
    tempPilot->points = 0; 
    
    // Cria o time e insere o piloto
    tempTeam->name = (char *)malloc((strlen(teamName) + 1) * sizeof(char));
    strcpy(tempTeam->name, teamName);
    tempTeam->points = 0;
    tempTeam->pilots[0] = *tempPilot;
    
    (pilots)[*numPilots] = *tempPilot;
    (*numPilots)++;


    
    int findName = 0;
    int i;
    for (i = 0; i < *numTeams; i++) {
        if (!strcmp(teamName, (setTeams)[i].name)) {
            findName = 1;
            break;
        }
    }
    if (!findName) {
        (setTeams)[*numTeams] = *tempTeam;
        (*numTeams)++;
    } else {
        (setTeams)[i].pilots[1] = *tempPilot;
    }
    
    free(tempPilot);
    free(tempTeam);
}

void readFile(char *fileName, Team *setTeams, int *numTeams, Pilot *pilots, int *numPilots) {
    // Abre o arquivo no modo de leitura
    FILE *file = fopen(fileName, "r");
    
    // Se o arquivo não abrir, ele termina a execução
    if (file == NULL) {
        perror("Erro ao abrir o arquivo");
        exit(EXIT_FAILURE);
    }
    // Número de pilotos e etapas
    int n, m;
    // Strings temporárias para armazenar o nome dos pilotos e times
    char *pilotName = (char *)malloc(31 * sizeof(char));
    char *teamName = (char *)malloc(31 * sizeof(char));
    
    // Lê os dois primeiros números do arquivo (n e m)
    fscanf(file, "%d %d", &n, &m);
    
    // Lê os nomes dos pilotos e seus times
    for (int i = 0; i < n; i++) {
        fscanf(file, "%s %s", pilotName, teamName);
        // Vale lembrar que cada linha é um piloto único, já os times podem se repetir
        insertSet(pilotName, teamName, setTeams, numTeams, pilots, numPilots);
    }
    
    free(pilotName);
    free(teamName);
    fclose(file);
}
