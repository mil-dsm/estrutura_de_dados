/**
 * @file prog2.c
 * @author your name (you@domain.com)
 * @brief Aplicações de Stack com char usando seu TAD correspondente.
 * @version 0.1
 * @date 2025-12-15
 * 
 * @copyright Copyright (c) 2025
 * 
 */

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "StackC.h"

void inverte(char s[]) {
    Stack *p = stack_create();
    for(int i = 0; s[i] != '\0'; i++) {
        if(s[i] == ' ') {
            while(!stack_empty(p)) {
                char t = stack_top(p);
                printf("%c", t);
                stack_pop(p);
            }
            printf(" ");
        }
        stack_push(p, s[i]);
    }
    while(!stack_empty(p)) {
        char t = stack_top(p);
        printf("%c", t);
        stack_pop(p);
    }
    printf("\n");
}

bool str1Cstr2(char str[]) {
    Stack *p = stack_create();
    bool flag = false;

    for(int i = 0; str[i] != '\0'; i++) {
        char c = s[i];
        // Verificar se tem apenas caracteres válidos
        if(c != 'A' && c != 'B' && c != 'C')
            return false;
        
        if(c == 'C') { // Verificar se tem ou não mais de um 'C'
            if(flag == true) return false;
            else flag = true;
        } 
        if(flag == false)
            stack_push(p, c);
        else {
            // Se a stack for vazia e a string 2 ainda não for, é diferente
            // Se o elemento no topo da stack for diferente do caracter atual, é diferente
            if(stack_empty(p) || stack_top(p) != c)
                return false;
            else // Se a stack não for vazia e o topo da stack for igual ao caracter c, continua a análise
                stack_pop(p);
        }
    }
    return (stack_empty(p) && flag); // Retorna o resultado da comparação
}

// Função que recebe uma sequencia de char e verifica se é bem formada.
bool bemformada(char seq[]) {
    Stack *p = stack_create();
    for(int i = 0; seq[i] != '\0'; i++) {
        switch(seq[i]):
            case ')':
                if(!stack_empty(p) && stack_top(p) == '(')
                    stack_pop(p);
                else
                    return false;
                break;
            case ']':
                if(!stack_empty(p) && stack_top(p) == '[')
                    stack_pop(p);
                else
                    return false;
                break;
            default:
                stack_push(seq[i]);
                break;
    }
    bool flag = stack_empty(p);
    stack_free(p);
    return flag;
}



int main(void) {
    char s1[] = "ABABBACABBABA";
    char s2[] = "ABABBACABB";
    char s3[] = "ABA";
    char s4[] = "ABDCDBA";
    
    if(str1Cstr2(s1)) printf("s1 é igual.\n");
    else printf("s1 não é igual.\n");

    if(str1Cstr2(s1)) printf("s2 é igual.\n");
    else printf("s2 não é igual.\n");

    if(str1Cstr2(s1)) printf("s3 é igual.\n");
    else printf("s3 não é igual.\n");

    if(str1Cstr2(s1)) printf("s4 é igual.\n");
    else printf("s4 não é igual.\n");

    // Testando de é bem formada
    printf("\nTeste: Bem Formada.\nDigite o array: ");
    char array[300];
    scanf("%299s", array);
    printf("bem formada? %s\n", bemFormada(array) ? "true" : "false");
    return 0;
}