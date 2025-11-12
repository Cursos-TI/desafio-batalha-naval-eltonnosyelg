#include <stdio.h>

#define TAM_NOVATO 5
#define TAM_AVENTUREIRO 10
#define TAM_MESTRE 5

// Desafio Batalha Naval - MateCheck
// Este código inicial serve como base para o desenvolvimento do sistema de Batalha Naval.

void imprimirMatriz(int linhas, int colunas, int matriz[linhas][colunas]) {
    for (int i = 0; i < linhas; i++) {
        for (int j = 0; j < colunas; j++) {
            printf("%d ", matriz[i][j]);
        }
        printf("\n");
    }
    printf("\n");
}

    // Nível Novato - Posicionamento dos Navios

void nivelNovato() {
    int tabuleiro[TAM_NOVATO][TAM_NOVATO] = {0};
    int x_vertical, y_vertical, tamanho_vertical;
    int x_horizontal, y_horizontal, tamanho_horizontal;

    printf("=== Nível Novato ===\n");
    printf("Digite a posição inicial do navio vertical (x y): ");
    scanf("%d %d", &x_vertical, &y_vertical);
    printf("Digite o tamanho do navio vertical: ");
    scanf("%d", &tamanho_vertical);

    printf("Digite a posição inicial do navio horizontal (x y): ");
    scanf("%d %d", &x_horizontal, &y_horizontal);
    printf("Digite o tamanho do navio horizontal: ");
    scanf("%d", &tamanho_horizontal);

    // Posiciona navio vertical
    printf("\nCoordenadas do Navio Vertical:\n");
    for (int i = 0; i < tamanho_vertical; i++) {
        int x = x_vertical + i;
        int y = y_vertical;
        tabuleiro[x][y] = 1;
        printf("Parte %d: (%d, %d)\n", i + 1, x, y);
    }

    // Posiciona navio horizontal
    printf("\nCoordenadas do Navio Horizontal:\n");
    for (int i = 0; i < tamanho_horizontal; i++) {
        int x = x_horizontal;
        int y = y_horizontal + i;
        tabuleiro[x][y] = 2;
        printf("Parte %d: (%d, %d)\n", i + 1, x, y);
    }
}

    // Nível Aventureiro - Expansão do Tabuleiro e Posicionamento Diagonal
void nivelAventureiro() {
    int tabuleiro[TAM_AVENTUREIRO][TAM_AVENTUREIRO] = {0};
    int x, y, tamanho;

    printf("\n=== Nível Aventureiro ===\n");

    // 4 navios: vertical, horizontal e 2 diagonais
    for (int navio = 1; navio <= 4; navio++) {
        printf("Digite a posição inicial do navio %d (x y): ", navio);
        scanf("%d %d", &x, &y);
        printf("Digite o tamanho do navio %d: ", navio);
        scanf("%d", &tamanho);

        for (int i = 0; i < tamanho; i++) {
            if (navio == 1) { // vertical
                tabuleiro[x + i][y] = 3;
            } else if (navio == 2) { // horizontal
                tabuleiro[x][y + i] = 3;
            } else if (navio == 3) { // diagonal principal
                tabuleiro[x + i][y + i] = 3;
            } else if (navio == 4) { // diagonal secundária
                tabuleiro[x + i][y - i] = 3;
            }
        }
    }

    printf("\nTabuleiro 10x10 com navios posicionados:\n");
    imprimirMatriz(TAM_AVENTUREIRO, TAM_AVENTUREIRO, tabuleiro);
}

    // Nível Mestre - Habilidades Especiais com Matrizes
void nivelMestre() {
    int matriz[TAM_MESTRE][TAM_MESTRE] = {0};
    int escolha;

    printf("\n=== Nível Mestre ===\n");
    printf("Escolha a habilidade:\n");
    printf("1 - Cone\n");
    printf("2 - Octaedro\n");
    printf("3 - Cruz\n");
    printf("Digite sua escolha: ");
    scanf("%d", &escolha);

    if (escolha == 1) {
        matriz[0][2] = 1;
        matriz[1][1] = matriz[1][2] = matriz[1][3] = 1;
        for (int j = 0; j < TAM_MESTRE; j++) matriz[2][j] = 1;
        printf("\nHabilidade: Cone\n");
    } else if (escolha == 2) {
        matriz[0][2] = 1;
        matriz[1][1] = matriz[1][2] = matriz[1][3] = 1;
        matriz[2][2] = 1;
        printf("\nHabilidade: Octaedro\n");
    } else if (escolha == 3) {
        matriz[0][2] = 1;
        for (int j = 0; j < TAM_MESTRE; j++) matriz[1][j] = 1;
        matriz[2][2] = 1;
        printf("\nHabilidade: Cruz\n");
    } else {
        printf("Opção inválida.\n");
        return;
    }

    imprimirMatriz(TAM_MESTRE, TAM_MESTRE, matriz);
}

//FUNÇÃO PRINCIPAL
int main() {
    int nivel;
    printf("Escolha o nível do desafio marujo:\n");
    printf("1 - Novato\n");
    printf("2 - Aventureiro\n");
    printf("3 - Mestre\n");
    printf("Digite sua escolha: ");
    scanf("%d", &nivel);

    if (nivel == 1) {
        nivelNovato();
    } else if (nivel == 2) {
        nivelAventureiro();
    } else if (nivel == 3) {
        nivelMestre();
    } else {
        printf("Opção inválida.\n");
    }

    return 0;
}

