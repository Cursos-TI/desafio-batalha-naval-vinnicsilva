#include <stdio.h>

// Dimensão do tabuleiro
int tabuleiro[10][10] = {0};

// Função para exibir o tabuleiro
void exibirTabuleiro() {
    printf("Tabuleiro:\n");
    for (int i = 0; i < 10; i++) {
        for (int j = 0; j < 10; j++) {
            printf("%d ", tabuleiro[i][j]);
        }
        printf("\n");
    }
}

// Função para criar e aplicar uma matriz de habilidade no tabuleiro
void aplicarHabilidade(int origemLinha, int origemColuna, int tamanho, char tipo) {
    int habilidade[tamanho][tamanho];

    // Inicializa matriz de habilidade com 0
    for (int i = 0; i < tamanho; i++) {
        for (int j = 0; j < tamanho; j++) {
            habilidade[i][j] = 0;
        }
    }

    // Preenche a matriz de acordo com o tipo
    for (int i = 0; i < tamanho; i++) {
        for (int j = 0; j < tamanho; j++) {
            int centro = tamanho / 2;

            if (tipo == 'C') {
                // Cone apontando para baixo
                if (i >= j - centro && i >= centro - j) {
                    habilidade[i][j] = 1;
                }
            } else if (tipo == '+') {
                // Cruz
                if (i == centro || j == centro) {
                    habilidade[i][j] = 1;
                }
            } else if (tipo == 'O') {
                // Octaedro (losango) sem usar abs
                int distLinha = i > centro ? i - centro : centro - i;
                int distColuna = j > centro ? j - centro : centro - j;
                if (distLinha + distColuna <= centro) {
                    habilidade[i][j] = 1;
                }
            }
        }
    }

    // Sobrepõe a matriz da habilidade ao tabuleiro
    for (int i = 0; i < tamanho; i++) {
        for (int j = 0; j < tamanho; j++) {
            int linhaTab = origemLinha - tamanho / 2 + i;
            int colTab = origemColuna - tamanho / 2 + j;

            if (linhaTab >= 0 && linhaTab < 10 && colTab >= 0 && colTab < 10) {
                if (habilidade[i][j] == 1 && tabuleiro[linhaTab][colTab] == 0) {
                    tabuleiro[linhaTab][colTab] = 5;
                }
            }
        }
    }
}

int main() {
    // Posiciona alguns navios (valor 3)
    tabuleiro[2][4] = 3;
    tabuleiro[5][7] = 3;
    tabuleiro[7][2] = 3;
    tabuleiro[1][1] = 3;

    // Aplica habilidades em pontos fixos
    aplicarHabilidade(4, 4, 5, 'C'); // Cone com origem em (4,4)
    aplicarHabilidade(6, 6, 5, '+'); // Cruz com origem em (6,6)
    aplicarHabilidade(3, 7, 5, 'O'); // Octaedro com origem em (3,7)

    // Exibe o tabuleiro final
    exibirTabuleiro();

    return 0;
}
