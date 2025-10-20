/*🔥 L2 - Queimada: Tocando fogo na floresta
Imagem ilustrando uma floresta em chamas
O fogo se espalha pela floresta!
🧩 Contexto
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

🧠 Dica de implementação
A matriz é definida como uma matriz de caracteres bidimensional mat[rows][columns]. Você deve implementar a função recursiva tocar_fogo no arquivo fogo.c.

Use as seguintes regras recursivas:

Se a posição for fora dos limites da matriz → retorne.
Se a posição não contiver uma árvore (#) → retorne.
Queime a árvore atual (substitua # por o).
Chame recursivamente a função para os 4 vizinhos (acima, abaixo, esquerda, direita).
🧪 Casos de teste
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
5 7 2 3
#..#.#.
#..####
####..#
..#.#..
#.###.#
========
o..o.o.
o..oooo
oooo..o
..o.o..
#.ooo.#
<<<<<<<<

Arquivos Requeridos
main.c
// Nao mexa neste arquivo, ele ja esta pronto para compilar
#include <stdio.h>
#include "fogo.h"

void show_mat(int rows, int columns, char mat[rows][columns]);
void read_mat(int rows, int columns, char mat[rows][columns]);

int main(){
    int nl = 0, nc = 0, lfire = 0, cfire = 0;
    scanf("%d%d%d%d", &nl, &nc, &lfire, &cfire);

    getchar(); // descarta o '\n' do buffer de leitura

    char mat[nl][nc];
    
    read_mat(nl, nc, mat);

    tocar_fogo(nl, nc, mat, lfire, cfire);
    
    show_mat(nl, nc, mat);
}

void show_mat(int rows, int columns, char mat[rows][columns]){
    for(int l = 0; l < rows; l++) {
        for(int c = 0; c < columns; c++) {
            printf("%c", mat[l][c]);
        }
        printf("\n");
    }
}

void read_mat(int rows, int columns, char mat[rows][columns]){
    for(int l = 0; l < rows; l++) {
        for(int c = 0; c < columns; c++) {
            mat[l][c] = (char) getchar();
        }
        getchar(); // descarta o '\n' do buffer de leitura
    }
}
    
fogo.h
// Nao mexa neste arquivo, ele ja esta pronto para compilar
#pragma once

#include <stdio.h>

// Função recursiva que recebe como entrada a matriz de caracteres mat juntamente com as suas dimensões.
// E recebe também a posição (l,c) a ser analisada. 
void tocar_fogo(int rows, int columns, char[rows][columns], int l, int c);

fogo.c
#include "fogo.h"

void tocar_fogo(int rows, int columns, char mat[rows][columns], int l, int c) {
    // fazer
}*/