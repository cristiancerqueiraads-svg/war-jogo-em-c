#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define TOTAL_TERRITORIOS 5

// Estrutura que representa um território
typedef struct {
    char nome[30];
    char cor[10];
    int tropas;
} Territorio;

// Estrutura que representa uma missão
typedef struct {
    char descricao[100];
    int (*verificar)(Territorio *, int);  // Ponteiro para função de verificação
} Missao;

// Função para cadastrar territórios
void cadastrarTerritorios(Territorio *territorios, int total) {
    for (int i = 0; i < total; i++) {
        printf("\nCadastro do território %d:\n", i + 1);
        printf("Nome: ");
        scanf(" %[^\n]", territorios[i].nome);
        printf("Cor do exército: ");
        scanf(" %[^\n]", territorios[i].cor);
        printf("Quantidade de tropas: ");
        scanf("%d", &territorios[i].tropas);
    }
}

// Função para exibir os territórios
void exibirTerritorios(Territorio *territorios, int total) {
    printf("\n--- Territórios cadastrados ---\n");
    for (int i = 0; i < total; i++) {
        printf("Território %d:\n", i + 1);
        printf("Nome: %s\n", territorios[i].nome);
        printf("Cor do exército: %s\n", territorios[i].cor);
        printf("Tropas: %d\n\n", territorios[i].tropas);
    }
}

// Função para realizar ataque entre territórios
void atacarTerritorio(Territorio *atacante, Territorio *defensor) {
    if (atacante->tropas > 1) {
        int tropasUsadas = atacante->tropas / 2;
        atacante->tropas -= tropasUsadas;
        defensor->tropas -= tropasUsadas;
        if (defensor->tropas < 0) defensor->tropas = 0;

        printf("\nAtaque realizado!\n");
        printf("%s atacou %s com %d tropas.\n", atacante->nome, defensor->nome, tropasUsadas);
    } else {
        printf("\nAtaque não permitido: tropas insuficientes.\n");
    }
}

// Função que verifica se há 3 territórios vermelhos com tropas
int verificarConquistaVermelha(Territorio *territorios, int total) {
    int count = 0;
    for (int i = 0; i < total; i++) {
        if (strcmp(territorios[i].cor, "vermelho") == 0 && territorios[i].tropas > 0) {
            count++;
        }
    }
    return count >= 3;
}

int main() {
    // Alocação dinâmica dos territórios
    Territorio *territorios = (Territorio *)malloc(sizeof(Territorio) * TOTAL_TERRITORIOS);
    if (territorios == NULL) {
        printf("Erro ao alocar memória.\n");
        return 1;
    }

    // Cadastro e exibição
    cadastrarTerritorios(territorios, TOTAL_TERRITORIOS);
    exibirTerritorios(territorios, TOTAL_TERRITORIOS);

    // Simulação de ataque
    atacarTerritorio(&territorios[0], &territorios[1]);

    // Definição da missão
    Missao missao1;
    strcpy(missao1.descricao, "Conquistar 3 territórios vermelhos");
    missao1.verificar = verificarConquistaVermelha;

    // Verificação de vitória
    if (missao1.verificar(territorios, TOTAL_TERRITORIOS)) {
        printf("\n🎉 Missão cumprida: %s\n", missao1.descricao);
    } else {
        printf("\nMissão ainda não concluída.\n");
    }

    // Liberação da memória
    free(territorios);
    return 0;
}
