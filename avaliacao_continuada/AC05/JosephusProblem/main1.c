/*Um problema bem interessante e antigo da matemática é conhecido como Josephus Problem. 

Nosso objetivo aqui será apenas implementar seu funcionamento.

No problema, N pessoas se colocam numa fila circular e assumem valores de 1 até N. Um número E é escolhido para iniciar o jogo. E pega a espada, mata o elemento à sua frente e passa a espada uma posição à frente. O jogo continua até que um único elemento permaneça vivo.

Entrada:
Os valores de N e E na primeira linha.
Saída:
Etapa a etapa, os elementos que estão vivos na fila circular, indicando com um > quem está com a espada.
Implementação usando vetor

Abordagem I
marcando os elementos que morrem.
toda vez que alguém morrer, marque 0 no vetor
procure pelo próximo elemento vivo a direita
int elementos[size];
//matar equivale a fazer
vivos[pos] = false;
//o próximo vivo seria uma busca pelo próximo vivo depois de pos
int prox = procurar_vivo(elementos, size, pos);

Abordagem II
retirando os elementos que morrem e diminuindo o tamanho do vetor.
reposicione os elementos “puxando” todos os que estiverem à frente
//faça a funcao matar que remove o elemento do vetor
//perceba que TUDO após pos, vai diminuir em 1
int elementos[size];
matar(elementos, size, pos);
size -= 1;
pos = pos % size; //se ele era o último agora é o zero
Comparação
Qual dos algoritmos você acha que é mais eficiente?
Implemente os dois e vá aumentando a instância do problema e veja o resultado.
Testes:
>>>>>>>> 01
3 1
========
[ 1> 2 3 ]
[ 1 3> ]
[ 3> ]
<<<<<<<<

>>>>>>>> 02
3 2
========
[ 1 2> 3 ]
[ 1> 2 ]
[ 1> ]
<<<<<<<<

>>>>>>>> 03
3 3
========
[ 1 2 3> ]
[ 2> 3 ]
[ 2> ]
<<<<<<<<

>>>>>>>> 04
6 3
========
[ 1 2 3> 4 5 6 ]
[ 1 2 3 5> 6 ]
[ 1> 2 3 5 ]
[ 1 3> 5 ]
[ 1> 3 ]
[ 1> ]
<<<<<<<<

>>>>>>>> 05
9 9
========
[ 1 2 3 4 5 6 7 8 9> ]
[ 2> 3 4 5 6 7 8 9 ]
[ 2 4> 5 6 7 8 9 ]
[ 2 4 6> 7 8 9 ]
[ 2 4 6 8> 9 ]
[ 2> 4 6 8 ]
[ 2 6> 8 ]
[ 2> 6 ]
[ 2> ]
<<<<<<<<

>>>>>>>> 06
20 1
========
[ 1> 2 3 4 5 6 7 8 9 10 11 12 13 14 15 16 17 18 19 20 ]
[ 1 3> 4 5 6 7 8 9 10 11 12 13 14 15 16 17 18 19 20 ]
[ 1 3 5> 6 7 8 9 10 11 12 13 14 15 16 17 18 19 20 ]
[ 1 3 5 7> 8 9 10 11 12 13 14 15 16 17 18 19 20 ]
[ 1 3 5 7 9> 10 11 12 13 14 15 16 17 18 19 20 ]
[ 1 3 5 7 9 11> 12 13 14 15 16 17 18 19 20 ]
[ 1 3 5 7 9 11 13> 14 15 16 17 18 19 20 ]
[ 1 3 5 7 9 11 13 15> 16 17 18 19 20 ]
[ 1 3 5 7 9 11 13 15 17> 18 19 20 ]
[ 1 3 5 7 9 11 13 15 17 19> 20 ]
[ 1> 3 5 7 9 11 13 15 17 19 ]
[ 1 5> 7 9 11 13 15 17 19 ]
[ 1 5 9> 11 13 15 17 19 ]
[ 1 5 9 13> 15 17 19 ]
[ 1 5 9 13 17> 19 ]
[ 1> 5 9 13 17 ]
[ 1 9> 13 17 ]
[ 1 9 17> ]
[ 9> 17 ]
[ 9> ]
<<<<<<<<*/

#include <stdio.h>

int matar(int [], int, int);

int main() {
    int N, E;
    scanf("%d%d", &N, &E);
    int v[N];
    // Preenche o vetor com valores de 1 a N
    for(int i = 0; i < N; i++) {
        v[i] = i + 1;
    }

    int vivos = N, venc = E-1;
    while(vivos > 1) {
        // Vetor formatado
        printf("[ ");
        for(int i = 0; i < N; i++) {
            if(v[i] == 0) continue;
            if(i == venc) {
                // Marca quem está com a espada
                printf("%d> ", v[i]);
            } else {
                printf("%d ", v[i]);
            }
        }
        printf("]\n");

        // Chamada da funcao para encontrar o indice vencedor da rodada
        venc = matar(v, N, venc);
        vivos--;
    }
    printf("[ %d> ]\n", v[venc]);

    return 0;
}

// Elimina a pessoa imediatamente após x (em ordem circular)
// Retorna o índice do próximo vivo que receberá a espada
int matar(int v[], int n, int x) {
    // Índice da próxima pessoa a morrer (circular)
    int iAlvo = (x + 1) % n;
    while(v[iAlvo] == 0) {
        iAlvo = (iAlvo + 1) % n; // Faz o calculo ate encontrar um vivo alvo vivo
    }
    v[iAlvo] = 0; // Mata o alvo

    // Encontra o indice do elemento vivo imediatamente depois do alvo que vai receber usar a espada dentro dos limites do vetor
    int iProx = (iAlvo + 1) %  n;
    while(v[iProx] == 0){
        iProx = (iProx + 1) % n; // Enquando o proximo a usar a espada estiver morto, o calculo eh refeito para encontrar um vivo
    }
    return iProx;
}