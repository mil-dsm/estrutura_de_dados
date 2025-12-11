#ifndef LINKED_LIST_H
#include <stdio.h>
#include <stdlib.h>

struct node{
    int data;
    struct node *next;
};

typedef struct node Node;

// Funcao que cria uma lista vazia
// sem no sentinela
Node* list_create(void) {
    return NULL;
}

/*Node* list_create(void) {
    Node *p = (Node *)malloc(sizeof(Node));
    p->next = NULL;
    return p;
}*/

// Insere um valor no inicio da lista
// e retorna a lista modificada
Node* list_push_front(Node *list, int value) {
    // Cria um novo no dinamicamente
    Node *novo = (Node*)malloc(sizeof(Node));
    novo->data = value;
    novo->next = list;

    /*if(list == NULL) {
        novo->data = list;
        // novo->data = NULL;
        return novo;
    } else {
        novo->next = list;
        return novo;
    } é a mesma bosta :P*/
}

// Insere um valor ao final da lista
// e retorna a lista modificada
Node* list_push_back(Node *list, int value) {
    // Aloca o no e ajusta os dados dele
    Node *novo = (Node*)malloc(sizeof(Node));
    if(list == NULL) {
        novo->data = value;
        novo->next = list;
        return novo;
    } else {
        Node *aux;
        while(aux != NULL) {
            aux = aux->next;
        }
        aux->next = novo;
        return list;
    }
}

// Insere um elemento no final da lista
// Recebe como entrada um ponteiro para uma lista e
// retorna um ponteiro para a cabeca da lista modificada
// Funcao recursiva
Node *list_push_back_rec(Node *list, int value) {
    // Caso base: quando chega ao final da lista
    if(list == NULL) {
        Node *new_node = (Node*) malloc(sizeof(Node));
        new_node->data = value;
        new_node->next = list;
        return new_node;
    }
    // Caso geral: nao chegou ao final da lista
    list->next = list_push_back_rec(list->next, value);
    return list;
}

// Funcao que recebe um ponteiro para a cabeca da lista e
// imprime o conteudo dos elementos na tela
// Formato: [a1 a2 a3 ... an]
// Neste caso, podemos utilizar o ponteiro da cabeca e perde-lo, pois ele ao precisa ser retornado
// Como ele eh uma variavel local, isso nao ira afetar na main
void list_print(Node *list) {
    printf("[ ");
    // Node *atual = list; // Variavel local que vai se mover, porem eh desnecessaria
    while(list != NULL) {
        printf("%d ", list->data);
        list = list->next;
    }
    /*for(Node *atual = list; atual != NULL; atual = atual->next) {
        printf("%d ", atual->data);    
    }*/
    printf("]\n");
}

// Funcao que libera todos os nos
// alocados dinamicamente
void list_free(Node *list) {
    while(list != NULL) {
        Node *aux = list->next;
        printf("No deletado: %d\n", list->data);
        free(list);
        list = aux;
    }
}

void list_free_rec(Node *list) {
    // Caso geral
    if(list != NULL) {
        list_free_rec(list->next);
        printf("No deletado: %d\n", list->data);
        free(list);
    }
    // Caso base: faz nada (return)
}

// Funcao que imprime o tamanho da lista (numero de nos)
site_t list_size(Node *list) {
    size_t size = 0;
    for(Node *atual = list; atual != NULL; atual = atual->next)
        size++;
    return size;
}

// Funcao recursiva que imprime o tamanho da lista (numero de nos)
site_t list_size_rec(Node *list) {
    if(list == NULL)
        return 0;
    else
        return 1 + list_size_rec(list->next);
}

// Funcao que retorna a soma dos numeros pares da lista
size_t list_sum_even(Node *list) {
    size_t sum = 0;
    while(list != NULL) {
        if(list->data % 2 == 0)
            sum += list->data;
        list = list->next;
    }
    /*for(Node *i = list; i != NULL; i = i->next) {
        if(list->data % 2 == 0)
            sum += list->data;
    }*/
    return sum;
}

// Funcao recursiva que retorna a soma dos numeros pares da lista
site_t list_sum_even_rec(Node *list) {
    if(list == NULL)
        return 0;
    else {
        size_t res = list_sum_even_rec(list->next);
        if(list->data % 2 == 0)
            return res + list_sum_even(list->next);
            // return list->data + list_sum_par_rec(list);
        else
            return res;
            // return list_sum_par_rec(list->next);
    }
}

// Funcao que procura um valor na lista e retorna seu indice
bool list_index(Node *list, int value, size_t *out_index) {
    if(list == NULL) {
        return false;
    }
    size_t index = 0;
    while(list != NULL) {
        if(list->data == value) {
            *out_index = index;
            return true;
        }
        list = list->next;
        index++;
    }
    return false;
}

// Funcao recursiva que procura um valor na lista e retorna um booleano se o valor esta na lista
bool list_index_rec(Node *list, int value, size_t *out_index, size_t index) {
    if(list == NULL) {
        return false;
    }
    if(list->data == value) {
        *out_index = index;
        return true;
    }
    return list_index_rec(list->next, value, out_index, index+1);
}

// Funcao que procura o maior valor da lista e retorna esse valor
bool list_max(Node *list, *out_max) {
    if(list == NULL) {
        return false;
    }
    else {
        *out_max = list->data;
        list = list->next;
        while(list != NULL) {
            if(list->data > *out_max) {
                *out_max = list->data;
            }
            list = list->next;
        }
        return true;
    }
}

// Funcao recursiva que procura o maior valor da lista e retorna esse valor
bool list_max_rec(Node *list, *out_max) {
    if(list == NULL) {
        return false;
    }
    if(list->data > *out_max) {
        *out_max = list_data;
        return true;
    }
    int max_restante;
    list_max_rec(list, &max_restante);
    *out_max = (*out_max > max_restante) ? *out_max : max_restante;
    return true;
}

// Funcao que procura a mediana da lista, assumindo que esta tem tamanho impar
int list_median(Node *list) {
    size_t size = 0;
    for(Node *atual = list; atual != NULL; atual = atual->next)
        size++;
    int i = 0;
    while(i < size/2) {
        if(i == (size/2)-1) {
            return list->data;
        }
        list = list->next;
        i++;
    }
}

#endif