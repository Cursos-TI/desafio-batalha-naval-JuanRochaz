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
#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

// Constantes
#define TAMANHO_TABULEIRO 10
#define TAMANHO_NAVIO 3
#define TAMANHO_HABILIDADE 5

// Exibe o tabuleiro com os valores (0 = água, 3 = navio, 5 = habilidade)
void exibirTabuleiro(int tabuleiro[TAMANHO_TABULEIRO][TAMANHO_TABULEIRO]) {
    printf("   A B C D E F G H I J\n");
    for (int i = 0; i < TAMANHO_TABULEIRO; i++) {
        printf("%2d ", i + 1);
        for (int j = 0; j < TAMANHO_TABULEIRO; j++) {
            printf("%d ", tabuleiro[i][j]);
        }
        printf("\n");
    }
}

// Verifica se a posição do navio é válida
bool posicaoValida(int tabuleiro[TAMANHO_TABULEIRO][TAMANHO_TABULEIRO], int linha, int coluna, int orientacao) {
    for (int i = 0; i < TAMANHO_NAVIO; i++) {
        int l = linha;
        int c = coluna;

        if (orientacao == 0)       c += i;            // Horizontal
        else if (orientacao == 1)  l += i;            // Vertical
        else if (orientacao == 2) { l += i; c += i; } // Diagonal crescente
        else if (orientacao == 3) { l += i; c -= i; } // Diagonal decrescente

        if (l < 0 || l >= TAMANHO_TABULEIRO || c < 0 || c >= TAMANHO_TABULEIRO || tabuleiro[l][c] != 0)
            return false;
    }
    return true;
}

// Posiciona o navio no tabuleiro
void posicionarNavio(int tabuleiro[TAMANHO_TABULEIRO][TAMANHO_TABULEIRO], int linha, int coluna, int orientacao) {
    if (!posicaoValida(tabuleiro, linha, coluna, orientacao)) {
        printf("Posição inválida para o navio!\n");
        return;
    }

    for (int i = 0; i < TAMANHO_NAVIO; i++) {
        int l = linha;
        int c = coluna;

        if (orientacao == 0)       c += i;
        else if (orientacao == 1)  l += i;
        else if (orientacao == 2) { l += i; c += i; }
        else if (orientacao == 3) { l += i; c -= i; }

        tabuleiro[l][c] = 3;
    }
}

// Cria habilidade em formato de cone corrigido
void criarHabilidadeCone(int habilidade[TAMANHO_HABILIDADE][TAMANHO_HABILIDADE]) {
    // Zera tudo
    for (int i = 0; i < TAMANHO_HABILIDADE; i++) {
        for (int j = 0; j < TAMANHO_HABILIDADE; j++) {
            habilidade[i][j] = 0;
        }
    }

    // Define a forma do cone (com a base mais larga)
    habilidade[0][2] = 1; // topo do cone
    habilidade[1][1] = 1; habilidade[1][2] = 1; habilidade[1][3] = 1; // segunda linha
    habilidade[2][0] = 1; habilidade[2][1] = 1; habilidade[2][2] = 1; habilidade[2][3] = 1; habilidade[2][4] = 1; // base do cone
}

// Cria habilidade em formato de cruz
void criarHabilidadeCruz(int habilidade[TAMANHO_HABILIDADE][TAMANHO_HABILIDADE]) {
    for (int i = 0; i < TAMANHO_HABILIDADE; i++) {
        for (int j = 0; j < TAMANHO_HABILIDADE; j++) {
            habilidade[i][j] = (i == TAMANHO_HABILIDADE / 2 || j == TAMANHO_HABILIDADE / 2) ? 1 : 0;
        }
    }
}

// Cria habilidade em formato de octaedro (losango em 2D)
void criarHabilidadeOctaedro(int habilidade[TAMANHO_HABILIDADE][TAMANHO_HABILIDADE]) {
    // Zera tudo
    for (int i = 0; i < TAMANHO_HABILIDADE; i++) {
        for (int j = 0; j < TAMANHO_HABILIDADE; j++) {
            habilidade[i][j] = 0;
        }
    }

    // Define forma de losango (octaedro em 2D)
    habilidade[0][2] = 1;
    habilidade[1][1] = 1;
    habilidade[1][2] = 1;
    habilidade[1][3] = 1;
    habilidade[2][2] = 1;
}

// Aplica habilidade no tabuleiro com valor definido
void aplicarHabilidade(int tabuleiro[TAMANHO_TABULEIRO][TAMANHO_TABULEIRO], int linha, int coluna, int habilidade[TAMANHO_HABILIDADE][TAMANHO_HABILIDADE], int valor) {
    for (int i = 0; i < TAMANHO_HABILIDADE; i++) {
        for (int j = 0; j < TAMANHO_HABILIDADE; j++) {
            if (habilidade[i][j] == 1) {
                int l = linha + i - (TAMANHO_HABILIDADE / 2);
                int c = coluna + j - (TAMANHO_HABILIDADE / 2);
                if (l >= 0 && l < TAMANHO_TABULEIRO && c >= 0 && c < TAMANHO_TABULEIRO) {
                    tabuleiro[l][c] = valor;
                }
            }
        }
    }
}

// Função principal
int main() {
    int tabuleiro[TAMANHO_TABULEIRO][TAMANHO_TABULEIRO] = {0};
    int habilidade[TAMANHO_HABILIDADE][TAMANHO_HABILIDADE];

    // Posicionar navio
    posicionarNavio(tabuleiro, 0, 0, 0);

    // Cone (valor 5)
    criarHabilidadeCone(habilidade);
    aplicarHabilidade(tabuleiro, 2, 2, habilidade, 5);

    // Cruz (valor 6)
    criarHabilidadeCruz(habilidade);
    aplicarHabilidade(tabuleiro, 2, 7, habilidade, 6);

    // Octaedro (valor 7)
    criarHabilidadeOctaedro(habilidade);
    aplicarHabilidade(tabuleiro, 7, 2, habilidade, 7);

    // Cone novamente no canto inferior direito
    criarHabilidadeCone(habilidade);
    aplicarHabilidade(tabuleiro, 7, 7, habilidade, 5);

    // Exibir tabuleiro
    exibirTabuleiro(tabuleiro);
    return 0;
}
