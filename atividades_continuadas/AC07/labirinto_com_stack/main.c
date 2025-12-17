/*Você vai tentar fugir do labirinto usando uma pilha no lugar da recursão.

Um labirinto perfeito é um labirinto no qual entre dois quaisquer pontos existe apenas um único caminho.

Leia uma matriz que representa um labirinto perfeito, os pontos de inicio e fim e imprima o labirinto mostrando o caminho entre os pontos.

Entrada
Linha 1: número de linhas e das colunas da matriz
Linhas subsequentes: matriz composta por 4 caracteres
uma célula com # representa uma parede
uma célula com espaço em branco representa um corredor por onde se pode andar
I representa o início
F representa o fim
Saída
Imprima a matriz utilizando o caractere ponto ( . ) para mostrar o caminho entre início e fim
OBS
Para resolver esta questão, você deve utilizar uma pilha (stack). Está proibido usar recursão!
Em sala de aula nós implementamos uma pilha de inteiros. Porém, nessa questão você terá que mudar o tipo de dado que a sua pilha vai armazenar.
marque e empilhe a posição inicio
inicie a pilha com esse elemento
enquanto a pilha não estiver vazia faça
    pegue topo da pilha
    se ele for o destino
        retorne

    faça uma lista com todos os vizinhos de topo que ainda não foram percorridos
    se lista eh vazia
        desempilhe
    senão
        escolha um dos vizinhos
        marque
        empilhe
Testes
>>>>>>>>
10 20
####################
#   # # # #   # ## #
### #     ###      #
##  ## ##   # ### ##
# I##   ### ###    #
# ##### #   #   ## #
# #     ## ### ##  #
# ## ####   #  #  ##
#   F#    #   ## ###
####################
========
####################
#   # # # #   # ## #
### #     ###      #
##  ## ##   # ### ##
#..##   ### ###    #
#.##### #   #   ## #
#.#     ## ### ##  #
#.## ####   #  #  ##
#....#    #   ## ###
####################
<<<<<<<<


>>>>>>>>
10 30
##############################
#  #        ## # # ##       ##
## # ## ## ##    # #  ## ##  #
## ###  #I    ##   ####   ## #
#  ##  ###########   #  #  # #
# ##  ## F # #   ### ####### #
# ## ### ###   #   # ##   #  #
#  # # # #   ##### # #  # # ##
##   #     #     #     ##    #
##############################
========
##############################
#  #        ## # # ##       ##
## # ## ## ##....# #  ## ##  #
## ###  #.....##...####   ## #
#  ##  ###########...#  #  # #
# ##  ##.. # #...###.####### #
# ## ###.###...#...#.##   #  #
#  # # #.#...#####.#.#  # # ##
##   #  ...#     #...  ##    #
##############################
<<<<<<<<
Help
Você pode usar esse código como ajuda. Ele carrega a matriz e mostra. O método get_vizinhos é bem útil para iterar nos vizinhos de um ponto.


#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
     int l; // linha
     int c; // coluna
} Posicao;

typedef struct {
     Posicao norte;
     Posicao sul;
     Posicao leste;
     Posicao oeste;
} Vizinhos;

//retorna um vetor com todos os vizinhos da posição p
Vizinhos get_vizinhos(Posicao p){
    Vizinhos v = {
        .oeste = {p.l,     p.c - 1},
        .norte = {p.l - 1, p.c    },
        .leste = {p.l,     p.c + 1},
        .sul   = {p.l + 1, p.c    }
    };
    return v;
}


int main() {
    int nl = 0, nc = 0;

    if(scanf("%d %d", &nl, &nc) != 2) {
        fprintf(stderr, "Erro ao ler nl e nc.\n");
        return 1;
    }

    getchar(); // consome '\n' após nc

    // Alocar vetor de strings (matriz de chars)
    char **mat = malloc(nl * sizeof(char*));
    for(int i = 0; i < nl; i++) {
        mat[i] = malloc((nc + 1) * sizeof(char)); // +1 para '\0'
    }

    Posicao inicio = {-1, -1};
    Posicao fim = {-1, -1};

    // Ler matriz linha a linha
    for (int i = 0; i < nl; i++) {
        fgets(mat[i], nc + 1, stdin);
        getchar(); // remover '\n'
    }

    // Procurar inicio (I) e fim (F)
    for (int l = 0; l < nl; l++) {
        for (int c = 0; c < nc; c++) {
            if (mat[l][c] == 'I') {
                mat[l][c] = ' ';
                inicio.l = l;
                inicio.c = c;
            }
            if (mat[l][c] == 'F') {
                mat[l][c] = ' ';
                fim.l = l;
                fim.c = c;
            }
         }
    }

    // Imprimir matriz
    for (int i = 0; i < nl; i++) {
        printf("%s\n", mat[i]);
    }

    printf(" nl=%d nc=%d\n", nl, nc);
    printf("inicio: l=%d , c=%d\n", inicio.l, inicio.c);
    printf(" fim: l=%d , c=%d\n", fim.l, fim.c);

    // Liberar memória
    for (int i = 0; i < nl; i++)
        free(mat[i]);
    free(mat);

    return 0;
}*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include "CStack.h"

typedef struct {
    Posicao norte;
    Posicao sul;
    Posicao leste;
    Posicao oeste;
} Vizinhos;

//retorna um vetor com todos os vizinhos da posição p
Vizinhos get_vizinhos(Posicao p){
    Vizinhos v = {.oeste = {p.l,     p.c - 1},
        .norte = {p.l - 1, p.c    },
        .leste = {p.l,     p.c + 1},
        .sul   = {p.l + 1, p.c    }
    };
    return v;
}

bool vizinho_valido(Posicao p, int nl, int nc, char **mat) {
    return p.l >= 0 && p.l < nl && p.c >= 0 && p.c < nc && mat[p.l][p.c] == ' ';
}

int main() {
    int nl = 0, nc = 0;

    if(scanf("%d %d", &nl, &nc) != 2) {
        fprintf(stderr, "Erro ao ler nl e nc.\n");
        return 1;
    }

    getchar(); // consome '\n' após nc

    // Alocar vetor de strings (matriz de chars)
    char **mat = malloc(nl * sizeof(char*));
    for(int i = 0; i < nl; i++) {
        mat[i] = malloc((nc + 1) * sizeof(char)); // +1 para '\0'
    }

    Posicao inicio = {-1, -1};
    Posicao fim = {-1, -1};

    // Ler matriz linha a linha
    for(int i = 0; i < nl; i++) {
        fgets(mat[i], nc + 1, stdin);
        getchar(); // remover '\n'
    }

    // Procurar inicio (I) e fim (F)
    for(int l = 0; l < nl; l++) {
        for (int c = 0; c < nc; c++) {
            if (mat[l][c] == 'I') {
                mat[l][c] = ' ';
                inicio.l = l;
                inicio.c = c;
            }
            if (mat[l][c] == 'F') {
                mat[l][c] = ' ';
                fim.l = l;
                fim.c = c;
            }
         }
    }

    // Cria stack e marca a posição que inicia
    CStack *p = cstack_create();
    cstack_push(p, inicio);
    mat[inicio.l][inicio.c] = '.';

    while(cstack_empty(p) == false) {
        Posicao top = cstack_top(p);
        
        // Acha o fim do labirinto
        if(top.l == fim.l && top.c == fim.c) {
            mat[top.l][top.c] = '.';
            break;
        }
        
        Vizinhos v = get_vizinhos(top);
        bool flag = false; // flag que diz se avançou ou não em uma posição

        Posicao direcoes[] = {v.norte, v.leste, v.sul, v.oeste};
        // Testas direções
        for(int i = 0; i < 4; i++) {
            if(flag == false && vizinho_valido(direcoes[i], nl, nc, mat) == true) {
                cstack_push(p, direcoes[i]);
                mat[direcoes[i].l][direcoes[i].c] = '.';
                flag = true;
                break;
            }
        }

        if(flag == false) {
            cstack_pop(p);
        }
    }
    
    // Desmarca todos os locais
    for(int i = 0; i < nl; i++) {
        for(int j = 0; j < nc; j++) {
            if(mat[i][j] == '.')
                mat[i][j] = ' ';
        }
    }
    
    // Marca o caminho certo através da pilha
    while(!cstack_empty(p)) {
        Posicao pos = cstack_top(p);
        cstack_pop(p);
        mat[pos.l][pos.c] = '.';
    }

    // Imprimir matriz
    for(int i = 0; i < nl; i++) {
        printf("%s\n", mat[i]);
    }

    // Liberar memória
    for(int i = 0; i < nl; i++)
        free(mat[i]);
    free(mat);

    return 0;
}