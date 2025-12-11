/*Motivação
A Torre de Hanói é um quebra-cabeça clássico que desafia tanto o raciocínio lógico quanto a habilidade de pensar recursivamente.
O jogo foi inventado em 1883 pelo matemático francês Édouard Lucas, que o apresentou com uma lenda fascinante:

Em um antigo templo hindu, há três torres de ouro. Na primeira torre, estão empilhados 64 discos de tamanhos diferentes, do maior (na base) ao menor (no topo). Os monges têm a missão de mover todos os discos da primeira torre para a terceira, obedecendo a regras sagradas. Quando terminarem, o mundo chegará ao fim.

Felizmente, para fins didáticos, você não precisa mover 64 discos — apenas programar a solução! 😄

Regras do jogo
Existem três torres: A, B e C.

Todos os discos começam empilhados na torre A, em ordem decrescente de tamanho (maior embaixo, menor em cima).

O objetivo é mover todos os discos da torre A para a torre C.

As regras para os movimentos são:

Apenas um disco pode ser movido por vez.

Um disco só pode ser movido se estiver no topo de uma torre.

Nenhum disco maior pode ser colocado sobre um disco menor.

O objetivo do jogo das torres de hanói é mover todos os discos da torre inicial para a torre final, sem colocar disco maior sobre disco menor. Inicialmente, a torre final e a torre auxiliar estão vazias. Você pode usar a torre auxiliar para lhe ajudar a mover os discos.

Exemplo
            ++                  ++                 ++
            ||                  ||                 ||
            ||                  ||                 ||
            ||                  ||                 ||
            ||                  ||                 ||
          +-++-+                ||                 ||
          |    |                ||                 ||
        +-+----+-+              ||                 ||
        |        |              ||                 ||
      +-+--------+-+            ||                 ||
      |            |            ||                 ||
      +------------+            ++                 ++
      Torre inicial        Torre auxiliar      Torre final
            A                   B                  C
Solução: 

A -> C 

A -> B 

C -> B 

A -> C 

B -> A 

B -> C 

A -> C

🎯 Sua tarefa
Escreva um programa recursivo que resolva o jogo das Torres de Hanói para um número n de discos informado pelo usuário.
O programa deve exibir a sequência completa de movimentos necessários para transferir todos os discos da torre A para a torre C.

Este problema parece difícil de resolver para o caso geral com n discos. Porém, como acontece em vários problemas, utilizando recursão chegamos em um algoritmo simples e elegante. Mova recursivamente os n−1
 primeiros discos para a torre auxiliar, depois mova o último disco da torre inicial para a torre final, e então mova recursivamente os n−1
 discos da torre auxiliar para a torre final.

Entrada
Número de discos n para mover da torre 'A' para a torre 'C'.
Saída
Sequência de movimentos para mover todos os discos (um movimento por linha).
Notação do movimento do disco no topo da torre:
torre de origem -> torre de destino.
💡 Dica
Pense de forma recursiva:
Mover n discos de A para C é o mesmo que:

Mover os n-1 primeiros discos (os menores) de A para B;

Mover o maior disco de A para C;

Mover os n-1 menores discos de B para C.

Exemplos
>>>>>>>>
3
========
A -> C
A -> B
C -> B
A -> C
B -> A
B -> C
A -> C
<<<<<<<<

Arquivos Requeridos
#include <stdio.h>

//Imprime os passos para solução da Torre de Hanoi.
//Entrada:
//- qte: números de discos que devem ser movidos da torre inicial para a torre final
//- ini: torre que é considerada como torre inicial
//- aux: torre que é considerada como torre auxiliar
//- fim: torre que é considerada como torre final
//Pseudocódigo:
   //se existe apenas 1 disco para mover
      //mova este único disco da torre inicial para a torre final
   //senão
      //recursivamente mova qte-1 discos da torre inicial para a torre auxiliar
      //mova o disco que sobrou da torre inicial para a torre final
      //recursivamente mova qte-1 discos da torre auxiliar para a torre final
//void hanoi(int qte, char ini, char aux, char fim)
//{
    //  //fazer
//}

int main()
{
   int qte;
   scanf("%d", &qte);
   hanoi(qte, 'A', 'B', 'C');
   return 0;
}*/

#include <stdio.h>

/*
Imprime os passos para solução da Torre de Hanoi.
Entrada:
- qte: números de discos que devem ser movidos da torre inicial para a torre final
- ini: torre que é considerada como torre inicial
- aux: torre que é considerada como torre auxiliar
- fim: torre que é considerada como torre final
Pseudocódigo:
   se existe apenas 1 disco para mover
      mova este único disco da torre inicial para a torre final
   senão
      recursivamente mova qte-1 discos da torre inicial para a torre auxiliar
      mova o disco que sobrou da torre inicial para a torre final
      recursivamente mova qte-1 discos da torre auxiliar para a torre final
*/
void hanoi(int qte, char ini, char aux, char fim){
   if(qte == 1){
      printf("%c -> %c\n", ini, fim);
   }
   else{
      hanoi(qte-1, ini, fim, aux);
      printf("%c -> %c\n", ini, fim);
      hanoi(qte-1, aux, ini, fim);
   }
}

int main(){
   int qte;
   scanf("%d", &qte);
   hanoi(qte, 'A', 'B', 'C');
   return 0;
}

/* ANOTAÇÕES

Assumindo:
1 <= ini <= 3
1 <= fim <= 3
ini != fim
n >= 1

Caso base: se n == 1, mover para a torre final.
Caso geral: mover n-1 discos para a torre auxiliar; 
mover discos da torre auxiliar para a final.
*/