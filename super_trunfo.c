#include <stdio.h>
#include <string.h>

// Definindo a estrutura que representa um território
typedef struct {
    char nome[30];     // Nome do território
    char cor[10];      // Cor do exército
    int tropas;        // Quantidade de tropas
} Territorio;

#define TOTAL_TERRITORIOS 5  // Número de territórios a serem cadastrados

int main() {
    Territorio territorios[TOTAL_TERRITORIOS];  // Vetor de structs para armazenar os territórios

    // Cadastro dos territórios
    for (int i = 0; i < TOTAL_TERRITORIOS; i++) {
        printf("\nCadastro do território %d:\n", i + 1);

        // Entrada do nome do território
        printf("Nome: ");
        scanf(" %[^\n]", territorios[i].nome);  // Lê string com espaços

        // Entrada da cor do exército
        printf("Cor do exército: ");
        scanf(" %[^\n]", territorios[i].cor);

        // Entrada da quantidade de tropas
        printf("Quantidade de tropas: ");
        scanf("%d", &territorios[i].tropas);
    }

    // Exibição dos dados cadastrados
    printf("\n--- Territórios cadastrados ---\n");
    for (int i = 0; i < TOTAL_TERRITORIOS; i++) {
        printf("Território %d:\n", i + 1);
        printf("Nome: %s\n", territorios[i].nome);
        printf("Cor do exército: %s\n", territorios[i].cor);
        printf("Tropas: %d\n\n", territorios[i].tropas);
    }

    return 0;
}
