#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_NAMES 100
#define MAX_LENGTH 100

typedef struct {
    char firstNames[MAX_NAMES][MAX_LENGTH];
    char lastNames[MAX_NAMES][MAX_LENGTH];
    int firstCount;
    int lastCount;
} NameList;

void generateFullName(NameList names, char fullName[], int tam) {
    // Escolhe um nome aleatório
    int randomIndex = rand() % names.firstCount;
    strcpy(fullName, names.firstNames[randomIndex]);

    // Adiciona sobrenomes únicos
    char uniqueLastNames[MAX_NAMES][MAX_LENGTH]; // Array para armazenar sobrenomes únicos
    int uniqueCount = 0;

    while (uniqueCount < tam - 1) {
        int lastIndex = rand() % names.lastCount;
        char *lastName = names.lastNames[lastIndex];

        // Verifica se o sobrenome já foi adicionado
        int alreadyExists = 0;
        for (int i = 0; i < uniqueCount; i++) {
            if (strcmp(uniqueLastNames[i], lastName) == 0) {
                alreadyExists = 1;
                break;
            }
        }

        // Se não existe, adiciona
        if (!alreadyExists) {
            strcpy(uniqueLastNames[uniqueCount], lastName);
            uniqueCount++;
        }
    }

    // Concatena os sobrenomes únicos com espaços
    for (int i = 0; i < uniqueCount; i++) {
        strcat(fullName, " "); // Adiciona espaço antes do sobrenome
        strcat(fullName, uniqueLastNames[i]);
    }
}

int main() {
    // Inicializa os dados
    NameList names = {
        .firstNames = {"Alice", "Bob", "Charlie", "Diana", "Eva", "Frank", "Grace", "Hannah", "Ian", "Jack", 
                       "Kate", "Leo", "Mia", "Nina", "Oscar", "Paula", "Quinn", "Rachel", "Sam", "Tina"},
        .lastNames = {"Smith", "Johnson", "Williams", "Jones", "Brown", "Davis", "Miller", "Wilson", 
                      "Moore", "Taylor", "Anderson", "Thomas", "Jackson", "White", "Harris", "Martin", 
                      "Thompson", "Garcia", "Martinez", "Robinson"},
        .firstCount = 20,
        .lastCount = 20
    };

    char fullName[MAX_LENGTH]; // Buffer para armazenar o nome completo

    // Inicializa o gerador de números aleatórios uma vez
    srand(time(NULL));

    printf("Generated Full Names:\n");
    for (int i = 0; i < 30; i++) {
        generateFullName(names, fullName, 3); // 1 primeiro + 2 sobrenomes
        printf("%d: %s\n", i + 1, fullName);
    }

    return 0;
}
