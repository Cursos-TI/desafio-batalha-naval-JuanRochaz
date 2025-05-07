#include <stdio.h>

#define TAMANHO_TABULEIRO 10
#define TAMANHO_NAVIO 3

int main() {
    // Declaração e inicialização do tabuleiro
    int tabuleiro[TAMANHO_TABULEIRO][TAMANHO_TABULEIRO] = {0};

    // Coordenadas iniciais dos navios
    int linhaNavioHorizontal = 2;
    int colunaNavioHorizontal = 1;

    int linhaNavioVertical = 5;
    int colunaNavioVertical = 3;

    // Posiciona o navio horizontal
    for (int i = 0; i < TAMANHO_NAVIO; i++) {
        tabuleiro[linhaNavioHorizontal][colunaNavioHorizontal + i] = 3; // 3 representa parte do navio
    }

    // Posiciona o navio vertical
    for (int i = 0; i < TAMANHO_NAVIO; i++) {
        tabuleiro[linhaNavioVertical + i][colunaNavioVertical] = 3; // 3 representa parte do navio
    }

    // Exibe o título do jogo
    printf("=== Jogo de Batalha Naval ===\n\n");

    // Exibe o cabeçalho com letras
    printf("   A B C D E F G H I J\n");
    
    // Exibe o tabuleiro com números na lateral
    for (int i = 0; i < TAMANHO_TABULEIRO; i++) {
        printf("%2d ", i + 1); // Exibe o número da linha
        for (int j = 0; j < TAMANHO_TABULEIRO; j++) {
            printf("%d ", tabuleiro[i][j]); // Exibe cada posição do tabuleiro
        }
        printf("\n"); // Nova linha após cada linha do tabuleiro
    }

    return 0;
}

    // Nível Aventureiro - Expansão do Tabuleiro e Posicionamento Diagonal
    #include <stdio.h>
#include <stdbool.h>

#define TAMANHO_TABULEIRO 10
#define TAMANHO_NAVIO 3

// Função para verificar se a posição do navio é válida
bool posicaoValida(int tabuleiro[TAMANHO_TABULEIRO][TAMANHO_TABULEIRO], int linha, int coluna, int orientacao) {
    for (int i = 0; i < TAMANHO_NAVIO; i++) {
        int l = linha;
        int c = coluna;

        if (orientacao == 0) {        // Horizontal
            c += i;
        } else if (orientacao == 1) { // Vertical
            l += i;
        } else if (orientacao == 2) { // Diagonal crescente
            l += i;
            c += i;
        } else if (orientacao == 3) { // Diagonal decrescente
            l += i;
            c -= i;
        }

        if (l < 0 || l >= TAMANHO_TABULEIRO || c < 0 || c >= TAMANHO_TABULEIRO)
            return false;
        if (tabuleiro[l][c] != 0)
            return false;
    }
    return true;
}

// Função para posicionar o navio no tabuleiro
void posicionarNavio(int tabuleiro[TAMANHO_TABULEIRO][TAMANHO_TABULEIRO], int linha, int coluna, int orientacao) {
    for (int i = 0; i < TAMANHO_NAVIO; i++) {
        int l = linha;
        int c = coluna;

        if (orientacao == 0) {        // Horizontal
            c += i;
        } else if (orientacao == 1) { // Vertical
            l += i;
        } else if (orientacao == 2) { // Diagonal crescente
            l += i;
            c += i;
        } else if (orientacao == 3) { // Diagonal decrescente
            l += i;
            c -= i;
        }

        tabuleiro[l][c] = 3;
    }
}

// Função para exibir o tabuleiro
void exibirTabuleiro(int tabuleiro[TAMANHO_TABULEIRO][TAMANHO_TABULEIRO]) {
    printf("   A B C D E F G H I J\n");
    for (int i = 0; i < TAMANHO_TABULEIRO; i++) {
        printf("%2d ", i + 1);
        for (int j = 0; j < TAMANHO_TABULEIRO; j++) {
            printf("%2d ", tabuleiro[i][j]);
        }
        printf("\n");
    }
}

int main() {
    int tabuleiro[TAMANHO_TABULEIRO][TAMANHO_TABULEIRO] = {0};

    // Define os navios: linha, coluna, orientacao
    int navios[4][3] = {
        {0, 0, 0}, // Navio horizontal em linha 0, coluna 0
        {3, 4, 1}, // Navio vertical em linha 3, coluna 4
        {6, 6, 2}, // Navio diagonal crescente em 6,6
        {3, 9, 3}  // Navio diagonal decrescente em 3,9
    };

    for (int i = 0; i < 4; i++) {
        int linha = navios[i][0];
        int coluna = navios[i][1];
        int orientacao = navios[i][2];

        if (posicaoValida(tabuleiro, linha, coluna, orientacao)) {
            posicionarNavio(tabuleiro, linha, coluna, orientacao);
        } else {
            printf("Posição inválida para o navio %d na linha %d coluna %d orientacao %d\n", i+1, linha, coluna, orientacao);
        }
    }

    printf("=== Jogo de Batalha Naval ===\n\n");
    exibirTabuleiro(tabuleiro);

    return 0;
}

    // Nível Mestre - Habilidades Especiais com Matrizes
    // Sugestão: Crie matrizes para representar habilidades especiais como cone, cruz, e octaedro.
    // Sugestão: Utilize estruturas de repetição aninhadas para preencher as áreas afetadas por essas habilidades no tabuleiro.
    // Sugestão: Exiba o tabuleiro com as áreas afetadas, utilizando 0 para áreas não afetadas e 1 para áreas atingidas.

    // Exemplos de exibição das habilidades:
    // Exemplo para habilidade em cone:
    // 0 0 1 0 0
    // 0 1 1 1 0
    // 1 1 1 1 1
    
    // Exemplo para habilidade em octaedro:
    // 0 0 1 0 0
    // 0 1 1 1 0
    // 0 0 1 0 0 

    // Exemplo para habilidade em cruz:
    // 0 0 1 0 0
    // 1 1 1 1 1
    // 0 0 1 0 0

   
}
