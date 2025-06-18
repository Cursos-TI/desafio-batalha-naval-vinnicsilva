#include <stdio.h>

int main() {
    int tabuleiro[10][10];
    int i, j;

    // Inicializa o tabuleiro com 0 (água)
    for (i = 0; i < 10; i++) {
        for (j = 0; j < 10; j++) {
            tabuleiro[i][j] = 0;
        }
    }

    // Definição dos navios (vetores unidimensionais)
    int navio_h[3] = {3, 3, 3};  // Navio horizontal
    int navio_v[3] = {3, 3, 3};  // Navio vertical

    // Coordenadas iniciais (definidas diretamente no código)
    int linha_h = 2;  // linha para navio horizontal
    int coluna_h = 4; // coluna inicial do navio horizontal

    int linha_v = 5;  // linha inicial do navio vertical
    int coluna_v = 7; // coluna para navio vertical

    // Validação para o navio horizontal
    if (coluna_h + 3 <= 10) {
        for (i = 0; i < 3; i++) {
            tabuleiro[linha_h][coluna_h + i] = navio_h[i];
        }
    } else {
        printf("Navio horizontal está fora dos limites do tabuleiro!\n");
    }

    // Validação para o navio vertical (e checar sobreposição)
    if (linha_v + 3 <= 10) {
        int sobreposicao = 0;
        for (i = 0; i < 3; i++) {
            if (tabuleiro[linha_v + i][coluna_v] != 0) {
                sobreposicao = 1;
            }
        }

        if (!sobreposicao) {
            for (i = 0; i < 3; i++) {
                tabuleiro[linha_v + i][coluna_v] = navio_v[i];
            }
        } else {
            printf("Navio vertical está sobrepondo outro navio!\n");
        }
    } else {
        printf("Navio vertical está fora dos limites do tabuleiro!\n");
    }

    // Exibe o tabuleiro
    printf("\nTabuleiro de Batalha Naval:\n");
    for (i = 0; i < 10; i++) {
        for (j = 0; j < 10; j++) {
            printf("%d ", tabuleiro[i][j]);
        }
        printf("\n");
    }

    return 0;
}
