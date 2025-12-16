/*🔥 Queimada com Pilha: Tocando fogo na floresta
🧩 Contexto
Refaça o problema da queimada utilizando pilha no lugar da recursão.

Imagine uma floresta representada por uma matriz de caracteres. Cada posição dessa matriz pode conter:

# — uma árvore 🌲
. — um espaço vazio 🌾
Um raio caiu e iniciou um incêndio em uma posição específica da floresta. O fogo se espalha rapidamente para as árvores adjacentes nas quatro direções cardeais (acima, abaixo, esquerda e direita), mas não nas diagonais.

Seu objetivo é simular a propagação do fogo até que todas as árvores conectadas ao ponto inicial estejam queimadas.

📥 Entrada
1ª linha: nl nc l c
nl: número de linhas da matriz
nc: número de colunas da matriz
l: linha inicial do fogo
c: coluna inicial do fogo
Nas linhas seguintes: a matriz da floresta, composta por # e ..
📤 Saída
A matriz resultante após o incêndio, substituindo cada árvore queimada pelo caractere o.

💡 Exemplo ilustrativo
Entrada:

3 4 1 1
####
.#.#
..#.
Processo: o fogo começa na posição (1,1). Ele queima a árvore nessa posição e se espalha nas quatro direções, alcançando as árvores conectadas diretamente.

Saída:

####
.o.#
..#.
As árvores marcadas com o foram queimadas.


Auxílio (HELP)
Você pode utilizar esse algoritmo.

verifique a primeira posição e queime-o
inicie a pilha com esse elemento
enquanto a pilha não estiver vazia faça
    pegue topo da pilha

    faça uma lista com todos os vizinhos de topo que podem ser queimados
    se lista eh vazia
        desempilhe
    senão
        escolha um dos vizinhos
        queime
        empilhe
>>>>>>>> 01
2 3 1 1
#.#
.##
========
#.o
.oo
<<<<<<<<

>>>>>>>> 02
5 5 0 0
#..#.
#...#
###..
..#.#
..###
========
o..#.
o...#
ooo..
..o.o
..ooo
<<<<<<<<

>>>>>>>> 03
5 7 2 0
#..#.#.
#..####
###...#
..#.###
#.###..
========
o..o.o.
o..oooo
ooo...o
..o.ooo
#.ooo..
<<<<<<<<

>>>>>>>> 04
5 5 0 0
...#.
#...#
###..
..#.#
..###
========
...#.
#...#
###..
..#.#
..###
<<<<<<<<

>>>>>>>> 05
10 40 0 3
..####..##.##.#..#.#####.##.####.#.#.###
.##.####..#####.##..##.#.###...##.#.#.#.
.#....#..##.#...#.#.#..#.##.#.###.#.###.
.###.#.##.##.######.###..##..#####.#..##
.##########.##########.########.######.#
.########.#####.###.########.#..##.####.
###.###..##.#..###.#.##.##.###..####.###
..######..#.#..#.###.##......####..#.###
######.##.##.#.####.####.##############.
##.##.#.###.###........###.##.####.###..
========
..oooo..##.oo.o..o.ooooo.oo.oooo.#.#.###
.oo.oooo..ooooo.oo..oo.o.ooo...oo.#.#.#.
.o....o..oo.o...o.o.o..o.oo.#.ooo.#.###.
.ooo.o.oo.oo.oooooo.ooo..oo..ooooo.o..##
.oooooooooo.oooooooooo.oooooooo.oooooo.#
.oooooooo.ooooo.ooo.oooooooo.o..oo.oooo.
ooo.ooo..oo.o..ooo.o.oo.oo.ooo..oooo.ooo
..oooooo..o.o..o.ooo.oo......oooo..o.ooo
oooooo.oo.oo.#.oooo.oooo.oooooooooooooo.
oo.oo.#.ooo.###........ooo.oo.oooo.ooo..
<<<<<<<<*/

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "CStack.h"

typedef struct {
    int l;
    int c;
} Posicao;

bool pode_queimar(int l, int c, int nl, int nc, char mat[nl][nc]) {
    // Verificar se está fora dos limiter da matriz
    if(l < 0 || l >= nl) return false;
    if(c < 0 || c >= nc) return false;
    return mat[l][c] == '#';
}

int main() {
    int nl, nc, l, c;
    scanf("%d%d%d%d", &nl, &nc, &l, &c);
    char mat[nl][nc];
    for(int i = 0; i < nl; i++) {
        for(int j = 0; j < nc; j++) {
            scanf("%s", mat[i][j]);
        }
    }
    // Se posição inicial não for árvore, não faz nada
    if(mat[0][0] != '#') {
        for (int i = 0; i < nl; i++)
        printf("%s\n", mat[i]);
        return 0;
    }

    Stack p = stack_create();

    // Queima a primeira posição
    mat[0][0] = 'o';
    Posicao inicio;
    inicio.l = 0;
    inicio.c = 0;
    cstack_push(p, inicio);

    while(stack_empty(p) == false) {
        Posicao atual = stack_top(p);
        bool flag = false; // Caso verdadeira, significa que achou um vizinho da posição atual

        // Verificando ao norte
        if(pode_queimar(atual.l - 1, atual.c, nl, nc, mat)) {
            mat[atual.l - 1][atual.c] = 'o'; // Se for possível queimar, marca como queimado
            Posicao pos;
            pos.l = atual.l - 1;
            pos.c = atual.c;
            cstack_push(p, pos);
            flag = true;
        }
    
        // Verificando ao sul
        else if(pode_queimar(atual.l + 1, atual.c, nl, nc, mat)) {
            mat[atual.l + 1][atual.c] = 'o'; // Se for possível queimar, marca como queimado
            Posicao pos;
            pos.l = atual.l + 1;
            pos.c = atual.c;
            cstack_push(p, pos);
            flag = true;
        }
    
        // Verificando ao leste
        else if(pode_queimar(atual.l, atual.c + 1, nl, nc, mat)) {
            mat[atual.l][atual.c + 1] = 'o'; // Se for possível queimar, marca como queimado
            Posicao pos;
            pos.l = atual.l;
            pos.c = atual.c + 1;
            cstack_push(p, pos);
            flag = true;
        }
    
        // Verificando ao oeste
        else if(pode_queimar(atual.l, atual.c - 1, nl, nc, mat)) {
            mat[atual.l][atual.c + 1] = 'o'; // Se for possível queimar, marca como queimado
            Posicao pos;
            pos.l = atual.l;
            pos.c = atual.c - 1;
            cstack_push(p, pos);
            flag = true;
        }

        if(flag == false)
            stack_pop(p);
    }

    for(int i = 0; i < nl; i++) {
        for(int j = 0; j < nc; j++) {
            printf("%c", mat[i][j]);
        }
    }

    stack_free(p);
    return 0;
}