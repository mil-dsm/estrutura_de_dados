/*Motivação
Imagine que você tem uma lista de números inteiros. A partir dela, vamos construir um triângulo de somas, em que cada nível acima é formado pela soma de pares de números consecutivos do nível imediatamente abaixo — até restar apenas um número no topo. Esse desafio é ideal para praticar recursão.

📖 Descrição
Dado um vetor com n inteiros A = [a0, a1, …, an-1], com n ≥ 0, o programa deve imprimir um triângulo numérico seguindo estas regras:

A base do triângulo contém todos os elementos do vetor original: [a0, …, an-1].
Cada nível acima possui um elemento a menos que o nível imediatamente abaixo.
Cada elemento em um nível é obtido pela soma de dois elementos consecutivos do nível abaixo.
💻 Entrada
Primeira linha: inteiro n, o tamanho do vetor A (n ≥ 0).
Segunda linha: os n elementos do vetor, separados por espaço simples.
📤 Saída
Imprima o triângulo de somas do topo até a base, uma linha por nível. Cada linha deve mostrar a lista de inteiros correspondente, no formato de lista (por exemplo: [1, 2, 3]).

📘 Exemplo 1
Entrada:
5
1 2 3 4 5

Saída:
[48]
[20, 28]
[8, 12, 16]
[3, 5, 7, 9]
[1, 2, 3, 4, 5]
Explicação passo a passo (visual):
No topo:      [48]
              ↑   (20 + 28 = 48)
            [20, 28]
             ↑     ↑
         (8+12)  (12+16)
          [8, 12, 16]
           ↑   ↑   ↑
        (3+5)(5+7)(7+9)
         [3, 5, 7, 9]
          ↑   ↑   ↑   ↑
       (1+2)(2+3)(3+4)(4+5)
        [1, 2, 3, 4, 5]
  
📘 Exemplo 2
Entrada:
7
2 0 -7 8 45 0 33

Saída:
[765]
[237, 528]
[37, 200, 328]
[-11, 48, 152, 176]
[-5, -6, 54, 98, 78]
[2, -7, 1, 53, 45, 33]
[2, 0, -7, 8, 45, 0, 33]
💡 Observação
O problema deve ser resolvido usando recursão. Não é obrigatório, mas pense em imprimir o triângulo do topo até a base (como no exemplo).

🧭 Dica: como pensar de forma recursiva
Uma forma natural de encarar o problema recursivamente é:

Se o vetor tem n = 0, não há nada a imprimir (triângulo vazio).
Se o vetor tem n = 1, o triângulo tem apenas [a0] — imprima e retorne.
Para n > 1:
Calcule o vetor do nível superior (chamemos de B) onde B[i] = A[i] + A[i+1] para i = 0..n-2.
Recursivamente, gere (ou imprima) o triângulo a partir de B — isto produz as linhas do topo até o nível logo acima da base.
Após a chamada recursiva retornar (ou antes, dependendo da ordem desejada), imprima a linha correspondente ao nível atual (por exemplo, A na base).
  
✅ Observações finais:
Imprima exatamente no formato pedido (cada linha como uma lista entre colchetes, separada por quebras de linha).
Considere casos-limite: n = 0 (nenhuma linha), n = 1 (apenas a linha com um número), e valores negativos/positivos no vetor.
Evite soluções puramente iterativas que construam todos os níveis sem usar recursão — o objetivo é treinar o pensamento recursivo.*/

#include <stdio.h>

void lerVetor(int [], int, int);
void trianguloRec(int [], int);
void constVet(int [], int [], int, int);
void imprimirTrianguloRec(int [], int, int);

int main(){
   int n;
   scanf("%d", &n);
   int v[n];
   lerVetor(v, n, 0);
   trianguloRec(v, n);
}

// Função de leitura recursiva do vetor.
// Entrada: vetor 'v' de tamanho 'n' e índice de início 'i' (inicialmente 0).
// Saída: vetor 'v' preenchido.
// Caso base: se o vetor tiver tamanho 0 ou o índice 'i' for igual a 'n', retorna (vetor preenchido).
// Caso geral: lê o elemento na posição 'i' e chama a função recursivamente
void lerVetor(int v[], int n, int i) {
    if(n <= 0 || i == n){
        return;
    }
    scanf("%d", &v[i]);
    lerVetor(v, n, i+1);
}

// Caso base: se o vetor tiver tamanho 1, imprime o elemento e retorna.
// Se o vetor for vazio, retorna sem imprimir nada.
// Caso geral: cria um novo vetor B com os somatórios dos pares consecutivos de A,
// chama a função recursivamente com B, e depois imprime o vetor A.
void trianguloRec(int A[], int n){
   if(n == 0){
      return;
   }
   if(n == 1){
       imprimirTrianguloRec(A, n, 0);
       return;
   }
   int B[n-1];
   constVet(B, A, n, 0);
   trianguloRec(B, n-1);
   imprimirTrianguloRec(A, n, 0);
}

// Função para contruir o novo vetor.
// Entrada: vetor a ser construido 'B' de tamanho 'n-1', vetor original 'A' de tamanho 'n', tamanho 'n' e índice de início 'i'.
// Saída: vetor 'B' preenchido.
// Caso base: se o índice 'i' for igual a 'n-1', retorna (vetor preenchido).
// Caso geral: soma A[i] + A[i+1] e armazena em B[i], depois chama a função recursivamente.
void constVet(int B[], int A[], int n, int i){
   if(i == n-1){ 
      return;
   }
   B[i] = A[i] + A[i+1];
   constVet(B, A, n, i+1);
}

// Função de impressão do vetor.
// Entrada: vetor 'v' de tamanho 'n' e índice de início 'i' (inicialmente 0).
// Saída: imprime o vetor no formato de lista.
// Caso base: se o índice 'i' for igual a 'n', imprime o colchete de fechamento e retorna.
// Caso geral: imprime o elemento na posição 'i' e chama a função recursivamente.
void imprimirTrianguloRec(int v[], int n, int i){
   if(i == 0){
      printf("[");
   }
   if(i > 0 && i < n){
       printf(", ");
   }
   printf("%d", v[i]);
   if(i == n-1){
      printf("]\n");
      return;
   }
   imprimirTrianguloRec(v, n, i+1);
}