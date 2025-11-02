/*🔠 Contando Letras com Recursão
Nesta atividade, você vai praticar o uso de recursão em C para percorrer uma string e contar quantas vezes um determinado caractere aparece nela.

O desafio é simples: dado um texto e um caractere, você deve descobrir quantas vezes esse caractere ocorre na string — mas sem usar nenhum laço de repetição (como for ou while).

Seu programa deve usar apenas chamadas recursivas para percorrer a string, caracter por caracter.

🎯 Objetivo
Implementar uma função recursiva que recebe:

uma string (texto);
um caractere alvo;
e retorna o número de vezes que esse caractere aparece na string.
📥 Entrada
Linha 1: uma string (pode conter letras, espaços e outros caracteres) com até no máximo 500 caracteres;
Linha 2: o caractere que será contado na string anterior.
📤 Saída
Um único número inteiro: o total de ocorrências do caractere na string.
💡 Dica de Implementação
A função recursiva deve verificar um caractere da string por vez:

Se a string estiver vazia → retorne 0.
Se o primeiro caractere for igual ao procurado → some 1 e chame a função para o restante da string.
Se não for igual → apenas chame a função para o restante da string.
👉 Assim, a contagem vai sendo acumulada conforme a função “volta” das chamadas recursivas.

📘 Exemplo
Entrada:
fundamentos de programacao
a

Saída:
4
Neste exemplo, o caractere 'a' aparece quatro vezes na string fornecida.

🧠 Observação
A função main e o protótipo da função recursiva já estão fornecidos no arquivo base da atividade. Sua tarefa é apenas implementar a lógica recursiva corretamente, sem utilizar comandos de repetição.

💬 Dica: pense na string como uma fila de caracteres — a cada chamada recursiva, você processa o primeiro caractere e avança para o próximo!

Arquivos requeridos
cont_char.c
#include <stdio.h>

// Retorna o números de ocorrências do caractere 'c' na string 's' (com 'n' caracteres).
// Algoritmo deve ser recursivo e sem comandos de repetição.
int conta_char_rec(char s[], int n, char c){
    // fazer
}

int main() {
    // fazer
}*/
    
#include <stdio.h>

int conta_char_rec(char [], int, char);

int main(){
    char s[501];
    char c;
    scanf("%[^\n] %c", s, &c);
    printf("%d\n", conta_char_rec(s, 0, c));
}

// Retorna o números de ocorrências do caractere 'c' na string 's' (com 'n' caracteres).
// Algoritmo deve ser recursivo e sem comandos de repetição.
// Entrada: string s, índice da posição a analisar e caracter c.
int conta_char_rec(char s[], int i, char c){
    if(s[i] == '\0')
        return 0;
    if(s[i] == c)
        return 1 + conta_char_rec(s, i+1, c);
    return conta_char_rec(s, i+1, c);
}