#include "LinkedList.h"

struct node {
    int data;
    struct node *next;
};


// Função que cria uma lista vazia
// sem nó sentinela
Node *list_create(void) {
    return NULL;
}

// Insere um valor no início da lista
// e retorna a lista modificada.
Node *list_push_front(Node *list, int value) {
    Node* novo = (Node*) malloc(sizeof(Node));
    novo->data = value;
    novo->next = list;
    return novo;
}

// Insere um valor ao final da lista
// e retorna a lista modificada.
Node *list_push_back(Node *list, int value) {
    Node *novo = (Node *)malloc(sizeof(Node));
    novo->data = value;
    novo->next = NULL;

    if(list == NULL) {
        return novo;
    } else {
        Node *q = list;
        while(q->next != NULL) {
            q = q->next;
        }
        q->next = novo;
        return list;
    }
}

// Função que recebe um ponteiro para a cabeça da lista e
// imprime o conteúdo dos elementos na tela.
// Formato: [ a1 a2 a3 ... an ]
void list_print(Node *list) {
    printf("[ ");
    while(list != NULL) {
        printf("%d ", list->data);
        list = list->next;
    }
    printf("]\n");
}

// Função que libera todos os nós 
// alocados dinamicamente
void list_free(Node *list) {
    while(list != NULL) {
        Node *aux = list->next;
        printf("list_free: nodo liberado: %d\n", list->data);
        free(list);
        list = aux;
    }
}

// Função que imprime o tamanho da lista (número de nós)
size_t list_size(Node *list) {
    size_t contador = 0;
    for(Node *atual = list; atual != NULL; atual = atual->next) {
        contador++;
    }
    return contador;
}

// Recebe como entrada um nó e devolve o valor dele.
int list_pega_valor(Node *p) {
    return p->data;
}

// Esta função troca o conteúdo das duas listas passadas como parâmetro.
void list_troca(Node **p1, Node **p2) {
    Node *aux = *p1;
    *p1 = *p2;
    *p2 = aux;
}

// Essa função recebe como entrada uma lista e 
// coloca os elementos pares no inı́cio, e os elementos ı́mpares no fim da lista.
// Retorna a lista modificada. Não é permitido usar arrays nem vetores dinâmicos.
// Só é permitido usar ponteiro auxiliar (uma quantidade constante deles).
// Deve-se fazer com complexidade linear O(n).
Node* list_separa_pares_impares(Node *p) {
    if (p == NULL) return NULL; // Se a lista for vazia, retorne NULL
    Node *head_even = NULL, *tail_even = NULL; // Marca o inicio e o fim da lista de pares dentro da lista
    Node *head_odd = NULL, *tail_odd = NULL; // Marca o inicio e o fim da lista de impares dentro da lista
    Node *atual = p; // Ponteiro que percorre os valores da lista
    while(atual != NULL) {
        Node *next = atual->next; // Guarda próximo antes de mexer
        atual->next = NULL; // Desconecta atual da lista original
        if(atual->data % 2 == 0) {
            // Adiciona aos pares
            if(head_even == NULL) {
                head_even = atual; 
                tail_even = atual;
            } else {
                tail_even->next = atual;
                tail_even = atual;
            }
        } else {
            // Adicion aos impares
            if(head_odd == NULL) {
                head_odd = atual;
                tail_odd = atual;
            } else {
                tail_odd->next = atual;
                tail_odd = atual;
            }
        }
        atual = next;
    }
    // Caso a lista nao tenha pares, retorna os impares
    if(head_even == NULL) {
        return head_odd;
    } else { // Caso a lista nao tennha impares, retorna os pares
        tail_even->next = head_odd;
        return head_even;
    }
}

// Essa função recebe como entrada uma lista encadeada com um número ímpar de elementos e 
// Encontra o elemento central da lista e retorna um ponteiro para ele.
// Se a lista for vazia, retorna NULL.
// Por exemplo, se tivermos a lista [2,3,4,5,6], a função retorna um ponteiro para o 4.
Node* list_encontra_centro(Node *p) {
    if(p == NULL) return NULL;
    int size = 0;
    Node *atual = p;
    while(atual != NULL) {
        size++;
        atual = atual->next;
    }
    atual = p;
    int i = 0;
    while(i < size / 2) {
        atual = atual->next;
        i++;
    }
    return atual;
}