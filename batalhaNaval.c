#include <stdio.h>

// Tamanho fixo do tabuleiro e valor que representa um navio no tabuleiro
const int TAMANHO = 10;
const int NAVIO = 3;

// Função para exibir o tabuleiro no console de forma organizada
void exibirTabuleiro(int tabuleiro[TAMANHO][TAMANHO]) {
    printf("Tabuleiro de Batalha Naval:\n");
    for (int i = 0; i < TAMANHO; i++) {
        for (int j = 0; j < TAMANHO; j++) {
            printf("%d ", tabuleiro[i][j]);
        }
        printf("\n");
    }
}

/*
 * Função para validar e posicionar um navio no tabuleiro.
 * Parâmetros:
 * - tabuleiro: matriz 10x10 representando o tabuleiro.
 * - linha, coluna: coordenadas iniciais onde o navio será posicionado.
 * - tamanho: tamanho do navio (quantidade de posições ocupadas).
 * - direcao: direção do navio:
 *      'H' = horizontal (linha fixa, coluna aumenta)
 *      'V' = vertical (coluna fixa, linha aumenta)
 *      'D' = diagonal descendente (linha e coluna aumentam simultaneamente)
 *      'A' = diagonal ascendente (linha aumenta, coluna diminui)
 *
 * A função verifica se o navio cabe dentro dos limites do tabuleiro
 * e se não há sobreposição com outros navios já posicionados.
 * Retorna 1 se o posicionamento foi bem-sucedido, 0 caso contrário.
 */
int posicionarNavio(int tabuleiro[TAMANHO][TAMANHO], int linha, int coluna, int tamanho, char direcao) {
    // Verifica todas as posições que o navio ocupará para garantir validade
    for (int i = 0; i < tamanho; i++) {
        int r = linha;
        int c = coluna;

        // Calcula a posição atual do navio conforme a direção
        if (direcao == 'H') c += i;
        else if (direcao == 'V') r += i;
        else if (direcao == 'D') { r += i; c += i; }
        else if (direcao == 'A') { r += i; c -= i; }
        else return 0; // Direção inválida

        // Valida se está dentro dos limites do tabuleiro
        if (r < 0 || r >= TAMANHO || c < 0 || c >= TAMANHO) {
            return 0; // Fora dos limites
        }

        // Verifica se a posição já está ocupada (não deve haver sobreposição)
        if (tabuleiro[r][c] != 0) {
            return 0; // Sobreposição detectada
        }
    }

    // Se passou pelas validações, posiciona o navio
    for (int i = 0; i < tamanho; i++) {
        int r = linha;
        int c = coluna;

        if (direcao == 'H') c += i;
        else if (direcao == 'V') r += i;
        else if (direcao == 'D') { r += i; c += i; }
        else if (direcao == 'A') { r += i; c -= i; }

        tabuleiro[r][c] = NAVIO; // Marca a posição como ocupada pelo navio
    }

    return 1; // Posicionamento bem-sucedido
}

int main() {
    int tabuleiro[TAMANHO][TAMANHO] = {0}; // Inicializa o tabuleiro com zeros (água)

    // Posiciona dois navios na horizontal e vertical
    if (!posicionarNavio(tabuleiro, 2, 4, 3, 'H')) 
        printf("Falha ao posicionar navio horizontal\n");
    if (!posicionarNavio(tabuleiro, 5, 7, 3, 'V')) 
        printf("Falha ao posicionar navio vertical\n");

    // Posiciona dois navios na diagonal (descendente e ascendente)
    if (!posicionarNavio(tabuleiro, 0, 0, 3, 'D')) 
        printf("Falha ao posicionar navio diagonal descendente\n");
    if (!posicionarNavio(tabuleiro, 0, 9, 3, 'A')) 
        printf("Falha ao posicionar navio diagonal ascendente\n");

    // Exibe o tabuleiro final com os navios posicionados
    exibirTabuleiro(tabuleiro);

    return 0;
}
