/*Atividade Continuada 03
Disciplina: Estruturas de Dados
Turma: 01A
Nome: Milena de Sousa Mesquita
Matrícula: 581180*/

/**
 * @file main.c
 * @author Milena de Sousa Mesquita (milenadsmesquita@alu.ufc.br)
 * @brief Avaliação Continuada 03
 * @version 0.1
 * @date 2025-10-13
 * 
 * @copyright Copyright (c) 2025
*/

#include <stdio.h>
#include <stdlib.h> 
#include <time.h>
#include <stdbool.h>

/**
 * Implementacao de dos algoritmos:
*/

// Função Heapify é uma função auxiliar do algoritmo Heap Sort que promete
// manter a propriedade de heap máximo em uma subárvore com raiz no índice 'i'.
// Para isso, compara o nó pai com seus filhos e garante que o maior valor
// fique no topo da subárvore. Caso necessário, realiza trocas e aplica
// recursivamente a mesma verificação na posição afetada.
// Entrada: vetor 'A[0...n-1]', tamanho 'n' do heap e índice 'i'.
// Saída: vetor com o maior elemento da subárvore movido para a posição correta.
void Heapify(int A[], int n, int i){
    int maior = i;
    int esq = 2 * i + 1;
    int dir = 2 * i + 2;
    if(esq < n && A[esq] > A[maior]){
        maior = esq;
    }
    if(dir < n && A[dir] > A[maior]){
        maior = dir;
    }
    if(maior != i){
        int aux = A[i];
        A[i] = A[maior];
        A[maior] = aux;
        Heapify(A, n, maior);
    }
}

// Algoritmo Heap Sort é uma função que promete ordenar um vetor A[0...n-1] de
// forma crescente, utilizando a estrutura de heap máximo. O maior elemento é
// colocado no final do vetor a cada iteração, e o heap é reajustado para manter
// sua propriedade. Esse processo é repetido até que o vetor esteja totalmente
// ordenado.
// Entrada: tamanho 'n' do vetor e vetor 'A[0...n-1]'.
// Saída: vetor ordenado em ordem crescente.
void HeapSort(int n, int A[]){
	for(int i=n/2-1; i>=0; i--){
        Heapify(A, n, i);
    }
    for(int i=n-1; i>0; i--){
        int aux = A[0];
        A[0] = A[i];
        A[i] = aux;
        Heapify(A, i, 0);
    }
}

// Algoritmo Bubble Sort é uma função que promete ordenar um vetor A[0...n-1]
// de forma crescente, comparando pares adjacentes e trocando-os sempre que
// estiverem fora de ordem. A cada passagem pelo vetor, o maior elemento é
// "empurrado" para o final, como bolhas subindo à superfície.
// Entrada: tamanho 'n' do vetor, vetor 'A[0...n-1]'.
// Saída: vetor ordenado em ordem crescente;
void BubbleSort(int n, int A[]) {   
    for (int i = 0; i < n-1; ++i) {
		for (int j = n-1; j > i; --j) { // j percorre o vetor decrescendo até i
			if (A[j] < A[j-1]) { // Se A[j] for maior que o anterior, trocam de posição
				int aux = A[j];
				A[j] = A[j-1];
				A[j-1] = aux;  
			}
		}
	}
}

// Algoritmo Insertion Sort é uma função que promete ordenar um vetor A[0...n-1]
// de forma crescente, inserindo cada elemento em sua posição correta dentro
// do subvetor já ordenado à esquerda. O processo é feito por comparações com
// os elementos anteriores e deslocamentos até encontrar o local apropriado.
// Entrada: tamanho 'n' do vetor, vetor 'A[0...n-1]'.
// Saída: vetor ordenado em ordem crescente.
void InsertionSort(int n, int A[]){
    for(int j=1; j<n; j++){
        int key = A[j]; // Decidi-se a chave para comparações
        int i = j - 1;
        while(i >= 0 && A[i] > key){ // Se A[i] for maior que a chave e i for maior ou igual a 0, A[i] muda de lugar
            A[i+1] = A[i];
            i--;
        }
        A[i+1] = key;
    }
}

// Algoritmo Selection Sort é uma função que promete ordenar um vetor A[0...n-1]
// de forma crescente, encontrando o menor elemento em cada passagem e trocando-o
// de posição com o primeiro elemento do subvetor desordenado. A cada iteração,
// o menor valor é colocado em sua posição correta, expandindo a parte ordenada
// do vetor da esquerda para a direita.
// Entrada: tamanho 'n' do vetor, vetor 'A[0...n-1]'.
// Saída: vetor ordenado em ordem crescente.
void SelectionSort(int n, int A[]){
    for(int i=0; i<n-1; i++){
        int indexMin = i;
		// Descobre-se o menor elemento
        for(int j=i+1; j<n; j++){
            if(A[j]<A[indexMin]){
                indexMin = j;
            }
        }
		// O menor elemento é colocado em seu lugar
        int aux = A[i];
        A[i] = A[indexMin];
        A[indexMin] = aux;
    }
}

// Função Intercala é uma função auxiliar do algoritmo Merge Sort que promete
// unir dois subvetores já ordenados, A[p...q] e A[q+1...r], em um único vetor
// ordenado A[p...r]. Essa etapa combina os resultados das chamadas recursivas
// do Merge Sort, mantendo a ordenação crescente.
// Entrada: vetor 'A[0...n-1]' e índices 'p', 'q' e 'r'
// Saída: vetor 'A[p...r]' reorganizado em ordem crescente.
void Intercala(int A[], int p, int q, int r){
	int B[r-p+1], i = p, j = q + 1, k = 0;
	// Intercala A[p...q] e A[q+1...r]
	while(i <= q && j <= r){
		if(A[i] <= A[j]){
			B[k++] = A[i++];
		}
		else{
			B[k++] = A[j++];
		}
	}
	// Caso ainda tenham sobrado números, são copiados para o vetor auxiliar
	while(i <= q){
		B[k++] = A[i++];
	}
	while(j <= r){
		B[k++] = A[j++];
	}
	// Copia vetor ordenado B para o vetor A
	for(int i = p; i <= r; i++){
		A[i] = B[i-p];
	}
}

// Algoritmo Merge Sort é uma função que promete ordenar um vetor A[p...r]
// de forma crescente. O vetor é dividido em duas metades, cada uma ordenada
// recursivamente, e depois combinadas pela função Intercala.
// Entrada: vetor 'A[p...r]' e índices 'p' (início) e 'r' (fim).
// Saída: vetor 'A[p...r]' ordenado em ordem crescente.
void MergeSort(int A[], int p, int r){
	if(p < r){
		int q = (p + r) / 2; // Dividir
		// Conquistar
		MergeSort(A, p, q);
		MergeSort(A, q+1, r);
		// Combinar
		Intercala(A, p, q, r);
	}
}

// Função Partition é uma função auxiliar do algoritmo Quick Sort que promete
// posicionar o pivô em sua posição correta no vetor. Todos os elementos menores
// ou iguais ao pivô são colocados à esquerda, e os maiores, à direita.
// Entrada: vetor 'A[l...r]', índice inicial 'l' e índice final 'r'.
// Saída: índice 'j' que indica a posição final do pivô no vetor.
int partition(int A[], int l, int r){
    int pivo = A[r];
    int j = l;
    for(int i=l; i<r; i++){ // Percorre o vetor e controi dois subvetores dentro, de menores e maiores
        if(A[i] <= pivo){
            int aux = A[i];
            A[i] = A[j];
            A[j++] = aux;
        }
    }
    A[r] = A[j]; // Atualiza-se a posição do vetor
    A[j] = pivo;
    return j;
}

// Algoritmo Quick Sort é uma função que promete ordenar um vetor A[l...r] de
// forma crescente. O vetor é particionado com base em um pivô, que separa os 
// elementos menores e maiores. O processo é aplicado recursivamente às duas 
// partes até que o vetor esteja ordenado.
// Entrada: vetor 'A[l...r]', índice inicial 'l' e índice final 'r'.
// Saída: vetor 'A[l...r]' ordenado em ordem crescente.
void QuickSort(int A[], int l, int r){
    if(l<r){
		// Dividir: descobrir a posição do pivô
        int j = partition(A, l, r);
		// Conquistar: chamada recursiva dos dois lados do pivô
        QuickSort(A, l, j-1);
        QuickSort(A, j+1, r);
    }
}

// ----------------------------------------------------------------------

/** 
 * Função que gera arquivos binários, cada um contendo números aleatórios.
 * Essa função recebe um array 'vetor_tam' que contém todos os tamanhos N
 * de vetores aleatórios que serão gerados. O parâmetro 'num_iteracoes' é
 * o tamanho do array 'vetor_tam' 
 */
void gera_dados(int num_iteracoes, const int vetor_tam[]) 
{
	for(int n = 0; n < num_iteracoes; ++n) {
		// Para cada tamanho n, são gerados 5 vetores de tamanho n com numeros aleatórios
		for(int semente = 0; semente < 5; semente++) {

			char nome_arquivo[150];
            snprintf(nome_arquivo, sizeof(nome_arquivo),
                     "dados/random%d_%d.dat", n, semente);

			FILE *fout = fopen(nome_arquivo, "wb");
            if (fout == NULL) {
                perror("Erro ao criar arquivo");
                exit(EXIT_FAILURE);
            }

			srand((unsigned) time(NULL) + semente); // Semente variável
            int tamanho_vetor = vetor_tam[n];
            int r;

			for (int i = 0; i < tamanho_vetor; i++) {
                r = rand() % 1000; // Criar númenos para o vetor no intervalo entre 0 e 999
                fwrite(&r, sizeof(r), 1, fout); // Escreve número em binário
            }

            fclose(fout);
		}
	}
}

// ------------------------------------------------------------------

/*
 * Recebe um vetor de inteiros A[0..n-1] como argumento e o preenche
 * com os n inteiros contidos no arquivo binário de mesmo nome que a 
 * string nomeArquivo
 */
void ler_dados(int n, int A[], const char *nomeArquivo) {
    FILE *input_file = fopen(nomeArquivo, "rb"); // Abre arquivo binário para leitura
    if (input_file == NULL) {
        perror("Erro ao abrir o arquivo para leitura");
        exit(EXIT_FAILURE);
    }

    size_t lidos = fread(A, sizeof(int), n, input_file);
    if (lidos != (size_t)n) {
        fprintf(stderr, "Aviso: esperava ler %d inteiros, mas leu %zu.\n", n, lidos);
    }

    fclose(input_file); // Fecha o arquivo
}

// ----------------------------------------------------------------------------
// Função Principal
int main() 
{ 
	// Os tamanhos dos vetores a serem testados estao guardados neste vetor 'tam'	
	// tamanhos reais para o projeto
	const int tam[] = {1000, 2000, 3000, 4000, 5000, 6000, 7000, 8000, 9000, 10000, 
	                   11000, 12000, 13000, 14000, 15000, 16000, 17000, 18000, 19000, 
					   20000, 21000, 22000, 23000, 24000, 25000, 26000, 27000, 28000, 
					   29000, 30000, 31000, 32000, 33000, 34000, 35000, 36000, 37000, 
					   38000, 39000, 40000, 41000, 42000, 43000, 44000, 45000, 46000, 
					   47000, 48000, 49000, 50000, 51000, 52000, 53000, 54000, 55000, 
					   56000, 57000, 58000, 59000, 60000, 61000, 62000, 63000, 64000, 
					   65000, 66000, 67000, 68000, 69000, 70000, 71000, 72000, 73000, 
					   74000, 75000, 76000, 77000, 78000, 79000, 80000, 81000, 82000, 
					   83000, 84000, 85000, 86000, 87000, 88000, 89000, 90000, 91000, 
					   92000, 93000, 94000, 95000, 96000, 97000, 98000, 99000, 100000};
	
	// tamanho reduzido apenas para teste
	/*const int tam[] = {1000, 2000, 3000, 4000, 5000, 6000, 7000, 8000, 9000, 10000, 
	                   11000, 12000, 13000, 14000, 15000, 16000, 17000, 18000, 19000, 
					   20000};*/
	
	const int TOTAL_N = sizeof(tam)/sizeof(tam[0]); // Determina tamanho do vetor 'tam'
	
	// ------------------------------------------------------------
	// Etapa 1: Gerar arquivos contendo numeros aleatórios
	// Os arquivos são gerados e salvos na pasta com nome 'dados'
	gera_dados(TOTAL_N, tam);
	
	// ------------------------------------------------------------
	// Etapa 2 - Execução do HeapSort
	// Para cada arquivo gerado na etapa 1, ler o arquivo e popular
	// um vetor de inteiros com os dados lidos.

	FILE *ofs = fopen("resultados/resultadoHeap.txt", "w"); 
    if (ofs == NULL) {
        perror("Erro ao abrir o arquivo para escrita");
        exit(EXIT_FAILURE);
    }

	for(int iteracao = 0; iteracao < TOTAL_N; iteracao++) 
	{	
		long double duracao_media_heap = 0.0;
		const int tamanho_vetor = tam[iteracao]; // Pega o tamanho do vetor para esta iteração
		int vetor[tamanho_vetor]; // Cria vetor a ser ordenado
		
		// Para cada tamanho de vetor, a função gera_dados() gerou 5 vetores diferentes. 
		// Cada um usou uma semente diferente. Agora, lê-se cada um desses vetores, 
		// Chamar o Heap Sort para ordená-los e, então, calcular o tempo medio de 
		// execução dessas cinco chamadas e depois salvar esse tempo médio em arquivo.
		for(int semente = 0; semente < 5; semente++) 
		{	
			char nome_arquivo[150];
            snprintf(nome_arquivo, sizeof(nome_arquivo),
                     "dados/random%d_%d.dat", iteracao, semente);
			
			ler_dados(tamanho_vetor, vetor, nome_arquivo);
			
			// HeapSort: Obtendo o tempo inicial
			clock_t ini = clock();
		
			HeapSort(tamanho_vetor, vetor); // Ordena o vetor usando o HeapSort
		
			// Obtendo o tempo final
			clock_t fim = clock();

			// Obtendo a duração total da ordenação
			long double duracao_microsegundos = (double)(fim - ini) * 1e6 / CLOCKS_PER_SEC;
			
			duracao_media_heap += duracao_microsegundos;
			
		}
		
		duracao_media_heap = duracao_media_heap / 5.0;
		printf("[Heap] N = %d, tempo medio de execucao = %.2Lf microssegundos\n", tamanho_vetor, duracao_media_heap);
		fprintf(ofs, "%d %Lf\n", tamanho_vetor, duracao_media_heap);
	}
	
	fclose(ofs); // Fecha arquivo de resultados do Heap Sort
	// ------------------------------------------------------------
	
	
	// ------------------------------------------------------------
	// Etapa 3 - Execução do BubbleSort
	// Para cada arquivo gerado na etapa 3, ler o arquivo e popular
	// um vetor de inteiros com os dados lidos.
	FILE *ofs2 = fopen("resultados/resultadoBubble.txt", "w"); 
    if (ofs2 == NULL) {
        perror("Erro ao abrir o arquivo para escrita");
        exit(EXIT_FAILURE);
    }
	
	for(int iteracao = 0; iteracao < TOTAL_N; iteracao++) {
		
		long double duracao_media_bubble = 0.0;
		const int tamanho_vetor = tam[iteracao]; // Pega o tamanho do vetor para esta iteração
		int vetor[tamanho_vetor]; // Cria vetor a ser ordenado
		
		// Para cada tamanho de vetor, a função gera_dados() gerou 5 vetores diferentes. 
		// Cada um usou uma semente diferente. Agora, vamos ler cada um desses vetores, 
		// Chamar o Bubble Sort para ordenás-los e, então, calcular o tempo médio de 
		// execução dessas cinco chamadas e depois salvar esse tempo médio em arquivo.
		for(int semente = 0; semente < 5; semente++) 
		{	
			char nome_arquivo[150];
            snprintf(nome_arquivo, sizeof(nome_arquivo),
                     "dados/random%d_%d.dat", iteracao, semente);
			
			ler_dados(tamanho_vetor, vetor, nome_arquivo);
			
			// Bubble Sort: Obtendo o tempo inicial
			clock_t ini2 = clock();
		
			BubbleSort(tamanho_vetor, vetor); // Ordena o vetor usando o Bubble Sort
		
			// Obtendo o tempo final
			clock_t fim2 = clock();
		
			// Obtendo a duração total da ordenação
			long double duracao_bubble = (double)(fim2 - ini2) * 1e6 / CLOCKS_PER_SEC;

			duracao_media_bubble += duracao_bubble;			
		}	
		
		duracao_media_bubble = duracao_media_bubble / 5.0;
		printf("[Bubble] N = %d, tempo medio de execucao = %.2Lf microssegundos\n", tamanho_vetor, duracao_media_bubble);
		fprintf(ofs2, "%d %Lf\n", tamanho_vetor, duracao_media_bubble);
	}
	
	fclose(ofs2); // Fecha arquivo de resultados do Bubble Sort
	// ------------------------------------------------------------
	

	// ------------------------------------------------------------
	// Etapa 4 - Execução do Insertion Sort
	// Para cada arquivo gerado na etapa 1, ler o arquivo e popular
	// um vetor de inteiros com os dados lidos.
	FILE *ofs3 = fopen("resultados/resultadoInsertion.txt", "w"); 
    if (ofs3 == NULL) {
        perror("Erro ao abrir o arquivo para escrita");
        exit(EXIT_FAILURE);
    }
	
	for(int iteracao = 0; iteracao < TOTAL_N; iteracao++) {
		
		long double duracao_media_insertion = 0.0;
		const int tamanho_vetor = tam[iteracao]; // Pega o tamanho do vetor para esta iteração
		int vetor[tamanho_vetor]; // Cria vetor a ser ordenado
		
		// Para cada tamanho de vetor, a função gera_dados() gerou 5 vetores diferentes. 
		// Cada um usou uma semente diferente. Agora, vamos ler cada um desses vetores, 
		// Chamar o Insertion Sort para ordená-los e, então, calcular o tempo médio de 
		// execução dessas cinco chamadas e depois salvar esse tempo médio em arquivo.
		for(int semente = 0; semente < 5; semente++) 
		{	
			char nome_arquivo[150];
            snprintf(nome_arquivo, sizeof(nome_arquivo),
                     "dados/random%d_%d.dat", iteracao, semente);
			
			ler_dados(tamanho_vetor, vetor, nome_arquivo);
			
			// Insertion Sort: Obtendo o tempo inicial
			clock_t ini2 = clock();
		
			InsertionSort(tamanho_vetor, vetor); // Ordena o vetor usando o InsertionSort
		
			// Obtendo o tempo final
			clock_t fim2 = clock();
		
			// Obtendo a duração total da ordenação
			long double duracao_insertion = (double)(fim2 - ini2) * 1e6 / CLOCKS_PER_SEC;

			duracao_media_insertion += duracao_insertion;			
		}
		
		duracao_media_insertion = duracao_media_insertion / 5.0;
		printf("[Insertion] N = %d, tempo medio de execucao = %.2Lf microssegundos\n", tamanho_vetor, duracao_media_insertion);
		fprintf(ofs3, "%d %Lf\n", tamanho_vetor, duracao_media_insertion);
	}
	
	fclose(ofs3); // Fecha arquivo de resultados do Insertion Sort
	// ------------------------------------------------------------
	

	// ------------------------------------------------------------
	// Etapa 5 - Execução do Selection Sort
	// Para cada arquivo gerado na etapa 1, ler o arquivo e popular
	// um vetor de inteiros com os dados lidos.
	FILE *ofs4 = fopen("resultados/resultadoSelection.txt", "w"); 
    if (ofs4 == NULL) {
        perror("Erro ao abrir o arquivo para escrita");
        exit(EXIT_FAILURE);
    }
	
	for(int iteracao = 0; iteracao < TOTAL_N; iteracao++) {
		
		long double duracao_media_selection = 0.0;
		const int tamanho_vetor = tam[iteracao]; // Pega o tamanho do vetor para esta iteração
		int vetor[tamanho_vetor]; // Cria vetor a ser ordenado
		
		// Para cada tamanho de vetor, a função gera_dados() gerou 5 vetores diferentes. 
		// Cada um usou uma semente diferente. Agora, vamos ler cada um desses vetores, 
		// Chamar o Selection Sort para ordená-los e, então, calcular o tempo médio de 
		// execução dessas cinco chamadas e depois salvar esse tempo médio em arquivo.
		for(int semente = 0; semente < 5; semente++) 
		{	
			char nome_arquivo[150];
            snprintf(nome_arquivo, sizeof(nome_arquivo),
                     "dados/random%d_%d.dat", iteracao, semente);
			
			ler_dados(tamanho_vetor, vetor, nome_arquivo);
			
			// SelectionSort: Obtendo o tempo inicial
			clock_t ini2 = clock();
		
			SelectionSort(tamanho_vetor, vetor); // ordena o vetor usando o Selection Sort
		
			// Obtendo o tempo final
			clock_t fim2 = clock();
		
			// Obtendo a duração total da ordenação
			long double duracao_selection = (double)(fim2 - ini2) * 1e6 / CLOCKS_PER_SEC;

			duracao_media_selection += duracao_selection;			
		}	
		
		duracao_media_selection = duracao_media_selection / 5.0;
		printf("[Selection] N = %d, tempo medio de execucao = %.2Lf microssegundos\n", tamanho_vetor, duracao_media_selection);
		fprintf(ofs4, "%d %Lf\n", tamanho_vetor, duracao_media_selection);
	}
	
	fclose(ofs4); // Fecha arquivo de resultados do Selection Sort
	// ------------------------------------------------------------

	// ------------------------------------------------------------
	// Etapa 6 - Execução do Merge Sort
	// Para cada arquivo gerado na etapa 1, ler o arquivo e popular
	// um vetor de inteiros com os dados lidos.
	FILE *ofs5 = fopen("resultados/resultadoMerge.txt", "w"); 
    if (ofs5 == NULL) {
        perror("Erro ao abrir o arquivo para escrita");
        exit(EXIT_FAILURE);
    }
	
	for(int iteracao = 0; iteracao < TOTAL_N; iteracao++) {
		
		long double duracao_media_merge = 0.0;
		const int tamanho_vetor = tam[iteracao]; // Pega o tamanho do vetor para esta iteração
		int vetor[tamanho_vetor]; // Cria vetor a ser ordenado
		
		// Para cada tamanho de vetor, a função gera_dados() gerou 5 vetores diferentes. 
		// Cada um usou uma semente diferente. Agora, vamos ler cada um desses vetores, 
		// Chamar o Merge Sort para ordená-los e, entao, calcular o tempo medio de 
		// execucao dessas cinco chamadas e depois salvar esse tempo medio em arquivo.
		for(int semente = 0; semente < 5; semente++) 
		{	
			char nome_arquivo[150];
            snprintf(nome_arquivo, sizeof(nome_arquivo),
                     "dados/random%d_%d.dat", iteracao, semente);
			
			ler_dados(tamanho_vetor, vetor, nome_arquivo);
			
			// MergeSort: Obtendo o tempo inicial
			clock_t ini2 = clock();
		
			MergeSort(vetor, 0, tamanho_vetor - 1);; // Ordena o vetor usando o Merge Sort
		
			// Obtendo o tempo final
			clock_t fim2 = clock();
		
			// Obtendo a duracao total da ordenação
			long double duracao_merge = (double)(fim2 - ini2) * 1e6 / CLOCKS_PER_SEC;

			duracao_media_merge += duracao_merge;			
		}	
		
		duracao_media_merge = duracao_media_merge / 5.0;
		printf("[Merge] N = %d, tempo medio de execucao = %.2Lf microssegundos\n", tamanho_vetor, duracao_media_merge);
		fprintf(ofs5, "%d %Lf\n", tamanho_vetor, duracao_media_merge);
	}
	
	fclose(ofs5); // Fecha arquivo de resultados do Merge Sort
    // ------------------------------------------------------------
	

	// ------------------------------------------------------------
	// Etapa 7 - Execução do Quick Sort
	// Para cada arquivo gerado na etapa 1, ler o arquivo e popular
	// um vetor de inteiros com os dados lidos.
	FILE *ofs6 = fopen("resultados/resultadoQuick.txt", "w"); 
    if (ofs6 == NULL) {
        perror("Erro ao abrir o arquivo para escrita");
        exit(EXIT_FAILURE);
    }
	
	for(int iteracao = 0; iteracao < TOTAL_N; iteracao++) {
		
		long double duracao_media_quick = 0.0;
		const int tamanho_vetor = tam[iteracao]; // Pega o tamanho do vetor para esta iteracao
		int vetor[tamanho_vetor]; // Cria vetor a ser ordenado
		
		// Para cada tamanho de vetor, a função gera_dados() gerou 5 vetores diferentes. 
		// Cada um usou uma semente diferente. Agora, vamos ler cada um desses vetores, 
		// Chamar o MergeSort para ordená-los e, entao, calcular o tempo medio de 
		// execucao dessas cinco chamadas e depois salvar esse tempo medio em arquivo.
		for(int semente = 0; semente < 5; semente++) 
		{	
			char nome_arquivo[150];
            snprintf(nome_arquivo, sizeof(nome_arquivo),
                     "dados/random%d_%d.dat", iteracao, semente);
			
			ler_dados(tamanho_vetor, vetor, nome_arquivo);
			
			// QuickSort: Obtendo o tempo inicial
			clock_t ini2 = clock();
		
			QuickSort(vetor, 0, tamanho_vetor - 1); // ordena o vetor usando o QuickSort
		
			// Obtendo o tempo final
			clock_t fim2 = clock();
		
			// Obtendo a duração total da ordenação
			long double duracao_quick = (double)(fim2 - ini2) * 1e6 / CLOCKS_PER_SEC;

			duracao_media_quick += duracao_quick;			
		}	
		
		duracao_media_quick = duracao_media_quick / 5.0;
		printf("[Quick] N = %d, tempo medio de execucao = %.2Lf microssegundos\n", tamanho_vetor, duracao_media_quick);
		fprintf(ofs6, "%d %Lf\n", tamanho_vetor, duracao_media_quick);
	}
	
	fclose(ofs6); // Fecha arquivo de resultados do Quick Sort
	return 0;
}