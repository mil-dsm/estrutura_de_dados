#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include "Tree.h"
#include "GenericQueue.h"
#include "GenericStack.h"

struct arv {
    int chave;
    struct arv *esq;
    struct arv *dir;
    struct arv *pai; // Questão 18 lista 5
    int height; // Questão 2 slides
    char *code; // Questão 3 slides
};

// Cria uma árvore vazia
NoArv* arv_cria_vazia(void) {
    return NULL;
}

// Cria árvore a partir de duas subárvores
NoArv* arv_cria(int value, NoNoArv* sae, NoNoArv* sad) {
    NoArv* raiz = (NoArv*)malloc(sizeof(NoArv));
    raiz->chave = valor;
    raiz->esq = sae;
    raiz->dir = sad;
    return raiz;
}

// Verifica se a árvore é vazia
bool arv_vazia(NoArv* raiz) {
    return raiz == NULL;
}

// Imprime valores da árvore
void arv_print(NoArv* raiz) {
    if(raiz != NULL) {
        printf("%d ", raiz->chave);
        arv_print(raiz->esq);
        arv_print(raiz->dir);
    }
}

// Libera nós da árvore
NoArv* arv_free(NoArv* raiz) {
    if(raiz == NULL) {
        return NULL;
    } else {
        raiz->esq = arv_free(raiz->esq);
        raiz->dir = arv_free(raiz->dir);
        printf("arv_free: %d\n", raiz->chave);
        free(raiz);
    }
}

// Verifica a existência de um valor entre os nós da árvore
bool arv_pertence(NoArv* raiz, int value) {
    if(raiz == NULL) {
        return false;
    } else {
        bool sae = arv_pertence(raiz->esq, valor);
        bool sad = arv_pertence(raiz->dir, valor);
        return raiz->chave == valor || sae || sad;
    }
}

// Imprime os valores de uma árvore em percurso de ordem simétrica
void arv_print_os(NoArv* raiz) {
    if(raiz == NULL) {
        return;
    } else {
        arv_print_os(raiz->esq);
        printf("%d ", raiz->chave);
        arv_print_os(raiz->dir);
    }
}

// Imprime os valores de uma árvore em percurso de pós-órdem
void arv_print_po(NoArv* raiz) {
    if(raiz == NULL) {
        return;
    } else {
        arv_print_po(raiz->esq);
        arv_print_po(raiz->dir);
        printf("%d ", raiz->chave);
    }
}

// Coloca os valores de uma árvore em percurso por largura em uma fila
void arv_largura(NoArv *raiz, Queue *q) {
    if(raiz == NULL) {
        return;
    }
    queue_push(q, raiz->chave);
    arv_largura(raiz->esq, q);
    arv_largura(raiz->dir, q);
}

// TODO: REVISAR
// Cria uma string serial da arvore binaria
void arv_serializar(NoArv* r, char *str);

// TODO: REVISAR
// Cria uma arvore binaria a partir duma string serial valida
NoArv* arv_deserializar(char *str, int *idx);

// Calula o número de nós de uma árvore
int bt_size(NoArv *raiz) {
    if(raiz == NULL) {
        return 0;
    }
    return 1 + bt_size(raiz->esq) + bt_size(raiz->dir);
}

// Calcula a altura da árvore
int bt_height(NoArv *raiz) {
    if(raiz == NULL) {
        return NULL;
    }
    int sae = bt_height(raiz->esq);
    int sad = bt_height(raiz_dir);
    raiz->height = 1 + ((sae > sad) ? sae : sad);
    return raiz->height;
} 

// TODO: REVISAR
// Suponha agora que todo nó da árvore tem um campo adicional code, do tipo string, 
// capaz de armazenar uma cadeia de caracteres de tamanho variável.
// Essa função reencha o campo code de cada nó com o código do nó. Se dor para esquerda,
// o código é 0, e se for pra direita, o código é 1.
void bt_code(NoArv *raiz, char *code) {
    if(raiz == NULL) {
        return;
    } else {
        // Atribui o código passado ao nó raiz
        raiz->code = (char*)malloc(strlen(code)+1); // +1 para o '\0'
        strcpy(raiz->code, code);

        // Realoca com mais 1 de espaço o código da esquerda e direita
        if(raiz->esq != NULL) {
            // Nó à esquerda, aloca mais um espaço para seu código e concatena com 0
            char *code_sae = (char*)malloc(strlen(code)+2); // +1 para o código, +1 para o '\0'
            strcpy(code_sae, code);
            strcat(code_sae, "0");
            bt_code(raiz->esq, code_sae);
            free(code_sae);
        }
        if(raiz->dir != NULL) {
            // Nó à direita, aloca mais um espaço para seu código e concatena com 1
            char *code_sad = (char*)malloc(strlen(code)+2); // +1 para o código, +1 para o '\0'
            strcpy(code_sad, code);
            strcat(code_sad, "1");
            bt_code(raiz->dir, code_sad);
            free(code_sad);
        }
    }
}

/* Lista 05 - Árvores Binárias */

// Questão 1: Calcula o número de nós
int arv_conta_nos(NoArv *raiz) {
    if(raiz == NULL) {
        return 0;
    }
    return 1 + arv_conta_nos(raiz->esq) + arv_conta_nos(raiz->dir);
}

// Questão 2: Calcula o número de folhas
int arv_conta_folhas(NoArv *raiz) {
    if(raiz == NULL) {
        return 0;
    }
    if(raiz->esq == NULL && raiz->dir == NULL) {
        return 1;
    }
    return arv_conta_folhas(raiz->esq) + arv_conta_folhas(raiz->dir);
}

// Questão 3: Destroi folhas
NoArv* arv_deleta_folhas(NoArv *raiz) {
    if(raiz == NULL) {
        return NULL;
    }
    if(raiz->esq == NULL && raiz->dir == NULL) {
        printf("Folha deletada: %d\n", raiz->chave);
        free(raiz);
        return NULL;
    }
    raiz->esq = arv_deleta_folhas(raiz->esq);
    raiz->dir = arv_deleta_folhas(raiz->dir);
    return raiz;
}

// Questão 4: Conta o número de nós internos de uma árvore binária
int arv_conta_nos_internos(NoArv *raiz) {
    if(raiz == NULL) { // Caso base
        return 0;
    }
    if(raiz->esq == NULL && raiz->dir == NULL) {
        return 0;
    }
    return 1 + arv_conta_nos_internos(raiz->esq) + arv_conta_nos_internos(raiz->dir);
}

// Questão 5: Encontra o nó maior número em uma árvore binária
NoArv* arv_max(NoArv *raiz) {
    if(raiz == NULL) {
        return NULL;
    }
    NoArv *max = raiz;
    NoArv *max_esq = arv_max(raiz->esq);
    NoArv *max_dir = arv_max(raiz->dir);
    if(max_esq != NULL && max->chave < max_esq->chave) {
        max = max_esq;
    }
    if(max_dir != NULL && max->chave < max_dir->chave) {
        max = max_dir;
    }
    return max;
}

// Questão 6
// Escreve uma função que encontre um nó com a chave k em uma ávore binária
// Retorna um ponteiro para o nó, caso ele exista, ou NULL, caso contrário
NoArv* arv_procura(NoArv *raiz, int k) {
    if(raiz == NULL) {
        return NULL;
    }
    if(raiz->chave == k) {
        return raiz;
    }
    if(arv_procura(raiz->esq, k)) {
        return arv_procura(raiz->esq, k);
    }
    return arv_procura(raiz->dir, k);
}

// Questão 7
// Função recursiva que apaga todas as folhas de uma árvore que tenha a chave
// igual ao valor dado
NoArv* arv_deleta_folhas_com_valor(NoArv *raiz, int valor) {
    if(raiz == NULL) {
        return NULL;
    }
    if(raiz->chave == valor && raiz->esq == NULL && raiz->dir == NULL) {
        printf("Folha deletada: %d\n", raiz->chave);
        free(raiz);
        return NULL;
    }
    raiz->esq = arv_deleta_folhas_com_valor(raiz->esq, valor);
    raiz->dir = arv_deleta_folhas_com_valor(raiz->dir, valor);
    return raiz;
}

// Questão 8: Algoritmos recursivos e não recursivos que:

// Item (a)
// Determina o número de nós com valores pares em uma árvore binária
int arv_conta_pares(NoArv *raiz) {
    if(raiz == NULL) {
        return 0;
    }
    if(raiz->chave % 2 == 0) {
        return 1 + arv_conta_pares(raiz->esq) + arv_conta_pares(raiz->dir);
    }
    return arv_conta_pares(raiz->esq) + arv_conta_pares(raiz->dir);
}

int arv_nos_pares_iterativa(NoArv *raiz) {
    if(raiz == NULL) {
        return 0;
    }
    int sum = 0;
    Queue *q = queue_create();
    queue_push(q, raiz);
    while(!queue_empty(q)) {
        NoArv *aux = queue_front(q);
        queue_pop(q);
        if(aux->chave % 2 == 0) {
            sum++;
        }
        if(aux->esq != NULL) {
            queue_push(q, aux->esq);
        }
        if(aux->dir != NULL) {
            queue_push(q, aux->dir);
        }
    }
    queue_free(q);
    return sum;
}

// Item (b)
// Soma dos conteudos de todos os nós em uma árvore binária considerando que
// cada nó contém um inteiro
int arv_soma(NoArv *raiz) {
    if(raiz == NULL) {
        return 0;
    }
    return raiz->chave + arv_soma(raiz->esq) + arv_soma(raiz->dir);
}

int arv_soma_iterativa(NoArv *raiz) {
    if(raiz == NULL) {
        return 0;
    }
    Queue q = queue_create();
    queue_push(q, raiz);
    int sum = 0;
    while(!queue_empty(q)) {
        NoArv *aux = queue_front(q);
        queue_pop(q);
        sum += aux->chave;
        if(aux->esq != NULL) {
            queue_push(q, aux->esq);
        }
        if(aux->dir != NULL) {
            queue_push(q, aux->dir);
        }
    }
    queue_free(q);
    return sum;
}

// Item (c)
// Profundidade de uma árvore binária
/* Conceitualmente, a profundidade de um nó é a altura deste nó em específico até a sua raiz.
 * Como a questão não especificou, pode ser interpretado como altura ou profundidade.
 * Como a versão recursiva da altura já foi implementada, vou implementar a versão iterativa
 * da altura, e a versão recursiva e iterativa de profundidade.
*/
int bt_height_iterativa(NoArv *raiz) {
    Queue *q = queue_create();
    queue_push(q, raiz);
    int h = -1;
    while(!queue_empty(q)) {
        int nivel_size = queue_size(q);
        for(int i = 0; i < nivel_size-1; i++) {
            NoArv *aux = queue_front(q);
            queue_pop(q);
            if(aux->esq != NULL) {
                queue_push(q, aux->esq);
            }
            if(aux->dir != NULL) {
                queue_push(q, aux->dir);
            }
        }
        h++;
    }
    return h;
}

int arv_profundidade(NoArv *raiz, int valor) {
    if(raiz == NULL) { // Caso base: não encontrado
        return 0;
    }
    if(raiz->chave == valor) { // Caso geral 1: achou neste nível
        return 1;
    }
    int p_sae = arv_profundidade(raiz->esq, valor); // Caso geral 2: encontrado na esquerda
    if(esq > 0) {
        return 1 + p_sae;
    }
    int p_sad = arv_profundidade(raiz->esq, valor); // Caso geral 3: encontrado na direita
    if(esq > 0) {
        return 1 + p_sad;
    }
    return 0; // Caso geral 4: não encontrado em nenhum lado
}

int arv_profundidade_iterativa(NoArv *raiz, int valor) {
    if(raiz == NULL) {
        return 0;
    }
    Queue *q =  queue_create();
    queue_push(q, raiz);
    Queue *nivel = queue_create();
    queue_push(nivel, 0);
    while(!queue_empty(q)) {
        NoArv *aux = queue_front(q);
        int prof = queue_front(nivel);
        queue_pop(q);
        queue_pop(nivel);

        if(aux->chave == valor) {
            queue_free(q);
            queue_free(nivel);
            return prof;
        }
        if(aux->esq != NULL) {
            queue_push(q, aux->esq);
            queue_push(nivel, prof+1);
        }
        if(aux->dir != NULL) {
            queue_push(q, aux->dir);
            queue_push(nivel, prof+1);
        }
    }
    queue_free(q);
    queue_free(nivel);
    return 0;
}

// Questão 9
// Cria uma cópia de una árvore binária
NoArv* bt_copia(NoArv *root) {
    if(raiz == NULL) {
        return NULL;
    }
    NoArv *novo = (NoArv*)malloc(sizeof(NoArv));
    novo->chave = raiz->chave;
    novo->esq = arv_copia(raiz->esq);
    novo->dir = arv_copia(raiz->dir);
    return novo;    
}

// Questão 10
// Retorna a quantidade de nós de uma árvore binária que possuem apenas um filho
int um_filho(NoArv *root) {
    if(raiz == NULL) { // Caso base
        return 0;
    }
    if(raiz->esq == NULL && raiz->dir == NULL) { // Caso geral 1: folha
        return 0;
    }
    if(raiz->esq != NULL || raiz->dir != NULL) {
        return 1 + arv_um_filho(raiz->esq) + arv_um_filho(raiz->dir);
    }
    return 0;
}

// Questão 11: Escreva funções que determinem se uma árvore binária:

// (a) estritamente binária
bool eh_binaria(NoArv *raiz) {
    if(raiz == NULL) {
        return true;
    }
    if(raiz->esq == NULL || raiz->dir == NULL) {
        return false;
    }
    return eh_binaria(raiz->esq) && eh_binaria(raiz->dir);
}

// (b) cheia
bool eh_cheia(NoArv *raiz) {
    if(raiz == NULL) {
        return true;
    }
    if(bt_height(raiz->esq) != bt_height(raiz->dir)) {
        return false;
    }
    return eh_cheia(raiz->esq) && eh_cheia(raiz->dir);
}

// (c) completa
bool eh_completa(NoArv *raiz) {
    if(raiz == NULL) {
        return true;
    }
}

// Questão 12:  Uma árvore é balanceada no sentido AVL se, para todo nó x, as
// alturas das subárvores esquerda e direita de x diferem em no máxima uma unidade.
// Escreva uma função que decida se uma dada árvore é balanceada no sentido AVL.
// Complexidade: O(n²).
bool eh_avl(NoArv *raiz) {
    if(raiz == NULL) {
        return true;
    }
    int sae = bt_height(raiz->esq);
    int sad = bt_height(raiz->dir);
    int dif = sae - sad;
    if(dif < 0) dif *= -1;
    if(dif > 1) {
        return false;
    }
    return eh_avl(raiz->esq) && eh_avl(raiz->dir);
}

// Questão 13: Escreva uma função não-recursiva que realize o percurso em pré-ordem 
// de uma árvore binária. Sugestão: utilizar uma pilha. 
void arv_print_po_iterativa(NoArv *raiz) {
    if(raiz == NULL) {
        return;
    }
    Stack *p = stack_create();
    stack_push(p, raiz);
    while(!stack_empty(p)) {
        int *aux = stack_top(p);
        stack_pop(p);
        printf("%d ", aux->chave);
        if(aux->dir != NULL) {
            stack_push(aux->dir);
        }
        if(aux->esq != NULL) {
            stack_push(aux->esq);
        }
    }
    stack_free(p);
}

// TODO: REVISAR
// Questão 14: Escreva uma função não-recursiva que realize o percurso em in-ordem 
// (ordem simétrica) de uma árvore binária. Sugestão: utilizar uma pilha.
void arv_print_io(NoArv *raiz) {
    if(raiz == NULL) {
        return;
    }
    Stack *p = stack_create();
    NoArv *atual = raiz;
    while(!stack_free(p) || atual != NULL) {
        while(atual != NULL) {
            stack_push(p, atual);
            atual = atual->esq;
        }
        atual = stack_top(p);
        stack_pop(p);
        printf("%d ", atual->chave);
        atual = atual->dir;
    }
}

// TODO: REVISAR
// Questão 15: Escreva uma função não-recursiva que realize o percurso em pós-ordem de 
// uma árvore binária. Sugestão: faça uma versão que utiliza duas pilhas, depois faça 
// outra que utiliza apenas uma pilha.
void arv_print_po2(NoArv *raiz) {
    if(raiz == NULL) {
        return;
    }
    Stack *p1 = stack_create();
    Stack *p2 = stack_create();
    stack_push(p1, raiz);
    while(!stack_empty(p1)) {
        NoArv *atual = stack_top(p1);
        stack_push(p2, atual);
        stack_pop(p1);
        if(atual->esq != NULL) {
            stack_push(p1, atual->esq);
        }
        if(atual->dir != NULL) {
            stack_push(p1, atual->dir);
        }
    }
    while(!stack_empty(p2)) {
        printf("%d ", (stack_top(p2))->chave);
        stack_pop(p2);
    }
    stack_free(p1);
    stack_free(p2);
}

void arv_print_po1(NoArv *raiz) {
    if(raiz == NULL) {
        return;
    }
    Stack *p = stack_create();
    NoArv *atual = raiz;
    NoArv *ultimo_acesso = NULL;
    while(!stack_empty(p) || atual != NULL) {
        if(atual != NULL) {
            stack_push(p, atual);
            atual = atual->esq;
        } else {
            NoArv *top = stack_top(p);
            if(top->dir != NULL && ultimo_acesso != top->dir) {
                atual = top->dir;
            } else {
                printf("%d ", top->chave);
                stack_pop(p);
                ultimo_acesso = top;
            }
        }
    }
    stack_free(p);
}

// Questão 16: Escreva uma função não-recursiva que calcula o 
// número de nós de uma árvore binária dada como entrada.
int numNos_iterativo(NoArv *no) {
    if(no == NULL) {
        return 0;
    }
    Stack *p = stack_create();
    stack_push(p, no);
    int sum = 0;
    while(!stack_empty(p)) {
        NoArv *atual = stack_top(p);
        stack_pop(p);
        sum++;
        if(atual->esq != NULL) {
            stack_push(p, atual->esq);
        }
        if(atual->dir != NULL) {
            stack_push(p, atual->dir);
        }
    }
    stack_free(p);
    return sum;
}

// Questão 17: Escreva uma função que compara se duas 
// árvores binárias dadas como entrada são iguais.
bool is_identical(NoArv *r1, NoArv *r2) {
    if(r1 == NULL && r2 == NULL) {
        return true;
    }
    if(r1 == NULL || r2 == NULL) {
        return false;
    }
    return (r1->chave == r2->chave) && 
    (is_identical(r1->esq, r2->esq)) && 
    (is_identical(r1->dir, r2->dir));
}

// Questão 18: Ajusta os ponteiros para seu pai respectivo a partir da raiz
void bt_ajusta(NoArv *raiz) {
    if(raiz == NULL) {
        return;
    }
    if(raiz->esq != NULL) {
        raiz->esq->pai = raiz;
    }
    if(raiz->dir != NULL) {
        raiz->dir->pai = raiz;
    }
}

// Cria uma árvore com subárvores e ponteiros-pai ajustados
NoArv* bt_cria(int valor, NoArv *sae, NoArv *sad) {
    NoArv *novo = (NoArv*)malloc(sizeof(NoArv));
    novo->pai = NULL;
    novo->chave = valor;
    novo->esq = sae;
    sae->pai = novo;
    novo->dir = sad;
    sad->pai = novo;
    return novo;
}

// Questão 19. Escreva um algoritmo que receba uma expressão matemática 
// (composta por operandos compostos por um único algarismo, 
// operações de $+$, $-$, $*$, $/$ e parênteses) representada 
// por uma string e retorne uma árvore binária representando 
// esta expressão.

// Questão 20. Dada uma árvore binária que represente uma expressão matemática, 
// construa um algoritmo que imprima a versão infixa (in-ordem) da expressão.

// Questão 21. Dada uma árvore binária que represente uma expressão matemática, 
// construa um algoritmo que imprima a versão posfixa (ou pós-ordem) da expressão.

// Questão 24: Escreva uma função que recebe uma árvore binária como parâmetro e percorre 
// em nível à árvore binária. Sugestão: utilizar a estutura de dados fila.
void bt_largura(NoArv *raiz) {
    if(raiz == NULL) {
        return;
    }
    Queue q = queue_create();
    queue_push(q, raiz);
    while(!queue_empty(q)) {
        NoArv *atual = queue_front(q);
        queue_pop(q);
        printf("%d ", atual->chave);
        if(atual->esq != NULL) queue_push(q, atual->esq);
        if(atual->dir != NULL) queue_push(q, atual->dir);
    }
    queue_free(q);
}

// Questão 25: Considere que uma árvore vazia é representada como um ponteiro 
// nulo (Uma árvore vazia é, por default, uma árvore quase-cheia).
// Não é permitido implementar funções auxiliares, ou seja, a função quaseCheia 
// deve ser autocontida (porém é permitido chamadas recursivas, se necessário).
// Função que receba uma árvore como parâmetro e retorne um inteiro diferente 
// de 0 se a árvore é quase-cheia ou retorne 0 se a árvore não é quase-cheia.
// Tarefa adicional: Note que a função deve retornar um inteiro diferente de 0 
// caso a árvore seja quase-cheia. Portanto, o retorno pode ser tanto positivo 
// quanto negativo, o que permite representar se a árvore é quase-cheia e cheia 
// ao mesmo tempo ou se ela é apenas quase-cheia. (Uma árvore cheia é uma árvore 
// em que todos os níveis possuem o máximo número de nós possível.)
int bt_quaseCheia(NoArv *root);

/* Livro: Introdução à Estrutura de Dados */

// Imprime valores da árvore com formatação
void arv_print_formatada(NoArv* raiz) {
    printf("<");
    if(raiz != NULL) {
        printf("%d ", raiz->chave);
        arv_print(raiz->esq);
        arv_print(raiz->dir);
    }
    printf(">");
}

// Cria uma folha solta com um valor
NoArv* arv_cria_folha(int value) {
    NoArv* novo = (NoArv*)malloc(sizeof(Arv));
    novo->chave = valor;
    novo->esq = novo->dir = NULL:
    return novo;
}

// Insere uma folha na árvore, usando a ordem de leftuerda para direita
// Se o nó raiz for nulo, ocupa ele, se não, chama a função para a
// sub árvore leftuesrda se dor nula, se não, chama para a árvore direita se for nula
void arv_insere(NoArv* raiz, int value) {
    if(raiz == NULL) {
        raiz = (NoArv*)malloc(sizeof(Arv));
        raiz->chave = valor;
        raiz->esq = raiz->dir = NULL;
    } else if(raiz->esq == NULL){
        raiz->esq = arv_insere(raiz->esq, valor);
    } else {
        raiz->dir = arv_insere(raiz->dir, valor);
    }
}

// Conta quantas ocorrências do valor tem dentro da árvore
int arv_conta_ocorrencias(NoArv *raiz, int value) {
    if(raiz == NULL) {
        return 0;
    }
    return ((raiz->chave == valor) ? 1 : 0) + arv_conta_valor(raiz->esq) + arv_conta_valor(raiz->dir);
}

// 4.1. Considere estruturas de árvores binárias que armazenam valores inteiros e 
// implemente uma função que, dada uma árvore, retorne a quantidade de nós que 
// guardam números pares.
int pares(Arv* a) {
    if(a == NULL) {
        return 0;
    }
    return ((a->chave % 2 == 0) ? 1 : 0) + pares(a->esq) + pares(a->dir);
}

// 4.2. Implemente uma função que retorne a quantidade de folhas de uma árvore binária. 
int folhas (Arv* a) {
    if(a == NULL) {
        return 0;
    }
    if(a->esq == NULL && a->dir == NULL) {
        return 1;
    }
    return folhas(a->esq) + folhas(a->dir);
}

// 4.3. Implemente uma função que retorne a quantidade de nós de uma árvore binária que 
// possuem apenas um filho.
int um_filho (Arv* a) {
    if(a == NULL) {
        return 0;
    }
    if(a->esq == NULL && a->dir == NULL) {
        return 0;
    }
    if(a->esq == NULL || a->dir == NULL) {
        return 1 + um_filho(a->esq) + um_filho(a->dir);
    }
    return um_filho(a->esq) + um_filho(a->dir);
}

// 4.4. Implemente uma função que compare se duas árvores binárias são iguais. 
// (Nota: Embora a imagem mostre Arv* igual, o contexto de comparação geralmente 
// sugere um retorno inteiro/booleano para indicar igualdade).
int igual(Arv* a, Arv* b) {
    if(a == NULL && b == NULL) {
        return 1;
    }
    if(a == NULL || b == NULL) {
        return 0;
    }
    if(a->chave != b->chave) {
        return 0;
    }
    return igual(a->esq, b->esq) && igual(a->dir, b->dir);
}

// 4.5. Implemente uma função que crie uma cópia de uma árvore binária.
Arv* copia(Arv* a) {
    if(a == NULL) {
        return NULL;
    }
    NoArv *novo = (NoArv*)malloc(sizeof(NoArv));
    novo->chave = a->chave;
    novo->esq = copia(a->esq);
    novo->dir = copia(a->dir);
    return novo;
}

/* Livro: Algoritmos de Linguagem C */

// 14.2.5 Escreva uma função que faça a varredura r-e-d de uma árvore binária. 
// Escreva uma função que faça a varredura e-d-r de uma árvore binária.

// 14.2.6 Escreva umafunção que receba uma árvore binária não vazia e devolva o
// endereço do primeiro nó da árvore na ordem e-r-d. Faça duas versões: uma iterativa 
// e uma recursiva. Repita o exercício com “último” no lugar de “primeiro”.

// 14.4.2 A profundidade de um nó em uma árvore binária é a distância entre o nó e
// a raiz da árvore. Mais precisamente, a profundidade de um nó X é o comprimento
// do (único) caminho que vai da raiz até X. Por exemplo, a profundidade da raiz é 0
// e a profundidade de qualquer filho da raiz é 1. Escreva uma função que determine a
// profundidade de um nó dado.

// 14.4.4 Escreva uma função que imprima o conteúdo de cada nó de uma árvore binária
// precedido de um recuo em relação à margem esquerda do papel. Esse recuo deve ser
// proporcional à profundidade do nó. Veja Figura 14.4.

// 14.4.5 Heap. Em que condições uma árvore binária pode ser considerada um heap
// (veja Seção 10.1)? Escreva uma função que transforme um max-heap em uma árvore
// binária quase completa. Escreva uma versão da função SacodeHeap (Seção 10.3) para
// um max-heap representado por uma árvore binária

// 14.5.1 Escreva uma função que receba um nó x de uma árvore binária e encontre o nó
// anterior a x na ordem e-r-d.

// 14.5.2 Escreva uma função que faça varredura e-r-d de um