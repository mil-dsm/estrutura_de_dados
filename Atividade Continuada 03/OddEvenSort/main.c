/*Atividade Continuada 03
Disciplina: Estruturas de Dados
Turma: 01A
Nome: Milena de Sousa Mesquita
Matrícula: 581180*/

/**
 * @file main.c
 * @author your name (you@domain.com)
 * @brief Avaliação Continuada 03
 * @version 0.1
 * @date 2025-10-13
 * 
 * @copyright Copyright (c) 2025
 * 
 */
#include <stdio.h>
#include <stdlib.h> 
#include <time.h>
#include <stdbool.h>

/**
 * Implementacao de dos algoritmos:
 */

// Algoritmo OddEven Sort
void OddevenSort(int n, int A[]){
    int trocou = 1;
    while(trocou){
        trocou = 0;
        for(int i=0; i<=n-2; i+=2){
            if(A[i] > A[i+1]){
                int aux = A[i];
                A[i] = A[i+1];
                A[i+1] = aux;
                trocou = 1;
            }
        }
        for(int i=1; i<=n-2; i+=2){
            if(A[i] > A[i+1]){
                int aux = A[i];
                A[i] = A[i+1];
                A[i+1] = aux;
                trocou = 1;
            }
        }
    }
}

// Algoritmo BubbleSort
// Ordena um vetor A[0..n-1]
void BubbleSort(int n, int A[]) {   
    for (int i = 0; i < n-1; ++i) {   
		for (int j = n-1; j > i; --j) {
			if (A[j] < A[j-1]) { 
				int aux = A[j];
				A[j] = A[j-1];
				A[j-1] = aux;  
			}
		}
	}
}

// Algorítmo: Insertion Sort
// Ordena um vetor A[0..n-1]
void InsertionSort(int n, int A[]){
    for(int j=1; j<n; j++){
        int key = A[j];
        int i = j - 1;
        while(i >= 0 && A[i] > key){
            A[i+1] = A[i];
            i--;
        }
        A[i+1] = key;
    }
}

// Algorítmo: Selection Sort
// Ordena um vetor A[0..n-1]
void SelectionSort(int n, int A[]){
    for(int i=0; i<n-1; i++){
        int indexMin = i;
        for(int j=i+1; j<n; j++){
            if(A[j]<A[indexMin]){
                indexMin = j;
            }
        }
        int aux = A[i];
        A[i] = A[indexMin];
        A[indexMin] = aux;
    }
}

// Algorítmo auxiliar ao Merge Sort
// Entrada: vetores crescentes A[p...q] e A[q+1...r]
// Rearranja A[p...r] em ordem crescente
void Intercala(int A[], int p, int q, int r){
	int n = r-p+1;
	int B[n];
	int i = p;
	int j = q + 1;
	int k = 0;
	// Intercala A[p...q] e A[q+1...r]
	while(i <= q && j <= r){
		if(A[i] <= A[j]){
			B[k++] = A[i++];
		}
		else{
			B[k++] = A[j++];
		}
	}
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

// Algoritmo Merge Sort
// Ordena um vetor A[0..n-1]
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

// Algorítmo auxiliar ao Quick Sort
// Entrada: vetores crescentes A[l...j-1] e A[j+1...r]
int partition(int A[], int l, int r){
    int pivo = A[r];
    int j = l;
    for(int i=l; i<r; i++){
        if(A[i] <= pivo){
            int aux = A[i];
            A[i] = A[j];
            A[j++] = aux;
        }
    }
    A[r] = A[j];
    A[j] = pivo;
    return j;
}

// Algoritmo QuickSort
// Ordena um vetor A[0..n-1]
void QuickSort(int A[], int l, int r){
    if(l<r){
        int j = partition(A, l, r);
        QuickSort(A, l, j-1);
        QuickSort(A, j+1, r);
    }
}

// ----------------------------------------------------------------------

/** 
 * Funcao que gera arquivos binarios, cada um contendo numeros aleatorios.
 * Essa funcao recebe um array 'vetor_tam' que contem todos os tamanhos N
 * de vetores aleatorios que serao gerados. O parametro 'num_iteracoes' eh
 * o tamanho do array 'vetor_tam' 
 */
void gera_dados(int num_iteracoes, const int vetor_tam[]) 
{
	for(int n = 0; n < num_iteracoes; ++n) {
		// para cada tamanho n, sao gerados 5 vetores de tamanho n com numeros aleatorios
		for(int semente = 0; semente < 5; semente++) {

			char nome_arquivo[150];
            snprintf(nome_arquivo, sizeof(nome_arquivo),
                     "dados/random%d_%d.dat", n, semente);

			FILE *fout = fopen(nome_arquivo, "wb");
            if (fout == NULL) {
                perror("Erro ao criar arquivo");
                exit(EXIT_FAILURE);
            }

			srand((unsigned) time(NULL) + semente); // semente variável
            int tamanho_vetor = vetor_tam[n];
            int r;

			for (int i = 0; i < tamanho_vetor; i++) {
                r = rand() % 1000; // Criar númenos para o vetor no intervalo entre 0 e 999
                fwrite(&r, sizeof(r), 1, fout); // escreve número em binário
            }

            fclose(fout);
		}
	}
}

// ------------------------------------------------------------------

/*
 * Recebe um vetor de inteiros A[0..n-1] como argumento e o preenche
 * com os n inteiros contidos no arquivo binario de mesmo nome que a 
 * string nomeArquivo
 */
void ler_dados(int n, int A[], const char *nomeArquivo) {
    FILE *input_file = fopen(nomeArquivo, "rb"); // abre arquivo binário para leitura
    if (input_file == NULL) {
        perror("Erro ao abrir o arquivo para leitura");
        exit(EXIT_FAILURE);
    }

    size_t lidos = fread(A, sizeof(int), n, input_file);
    if (lidos != (size_t)n) {
        fprintf(stderr, "Aviso: esperava ler %d inteiros, mas leu %zu.\n", n, lidos);
    }

    fclose(input_file); // fecha o arquivo
}


// ----------------------------------------------------------------------------
// Funcao Principal
int main() 
{ 
	// Os tamanhos dos vetores a serem testados estao guardados neste vetor 'tam'	
	// tamanhos reais para o projeto
	/*const int tam[] = {1000, 2000, 3000, 4000, 5000, 6000, 7000, 8000, 9000, 10000, 
	                   11000, 12000, 13000, 14000, 15000, 16000, 17000, 18000, 19000, 
					   20000, 21000, 22000, 23000, 24000, 25000, 26000, 27000, 28000, 
					   29000, 30000, 31000, 32000, 33000, 34000, 35000, 36000, 37000, 
					   38000, 39000, 40000, 41000, 42000, 43000, 44000, 45000, 46000, 
					   47000, 48000, 49000, 50000, 51000, 52000, 53000, 54000, 55000, 
					   56000, 57000, 58000, 59000, 60000, 61000, 62000, 63000, 64000, 
					   65000, 66000, 67000, 68000, 69000, 70000, 71000, 72000, 73000, 
					   74000, 75000, 76000, 77000, 78000, 79000, 80000, 81000, 82000, 
					   83000, 84000, 85000, 86000, 87000, 88000, 89000, 90000, 91000, 
					   92000, 93000, 94000, 95000, 96000, 97000, 98000, 99000, 100000};*/
	
	// tamanho reduzido apenas para teste
	const int tam[] = {1000, 2000, 3000, 4000, 5000, 6000, 7000, 8000, 9000, 10000, 
	                   11000, 12000, 13000, 14000, 15000, 16000, 17000, 18000, 19000, 
					   20000};
	
	const int TOTAL_N = sizeof(tam)/sizeof(tam[0]); // determina tamanho do vetor 'tam'
	
	// ------------------------------------------------------------
	// Etapa 1: Gerar arquivos contendo numeros aleatorios
	// Os arquivos sao gerados e salvos na pasta com nome 'dados'
	gera_dados(TOTAL_N, tam);
	
	// ------------------------------------------------------------
	// Etapa 2 - Execucao do OddevenSort
	// Para cada arquivo gerado na etapa 1, ler o arquivo e popular
	// um vetor de inteiros com os dados lidos.

	FILE *ofs = fopen("resultados/resultadoOddeven.txt", "w"); 
    if (ofs == NULL) {
        perror("Erro ao abrir o arquivo para escrita");
        exit(EXIT_FAILURE);
    }

	for(int iteracao = 0; iteracao < TOTAL_N; iteracao++) 
	{	
		long double duracao_media_oddeven = 0.0;
		const int tamanho_vetor = tam[iteracao]; // pega o tamanho do vetor para esta iteracao
		int vetor[tamanho_vetor]; // cria vetor a ser ordenado
		
		// Para cada tamanho de vetor, a funcao gera_dados() gerou 5 vetores diferentes. 
		// Cada um usou uma semente diferente. Agora, vamos ler cada um desses vetores, 
		// Chamar o oddeven sort para ordena-los e, entao, calcular o tempo medio de 
		// execucao dessas cinco chamadas e depois salvar esse tempo medio em arquivo.
		for(int semente = 0; semente < 5; semente++) 
		{	
			char nome_arquivo[150];
            snprintf(nome_arquivo, sizeof(nome_arquivo),
                     "dados/random%d_%d.dat", iteracao, semente);
			
			ler_dados(tamanho_vetor, vetor, nome_arquivo);
			
			// OddevenSort ------------------------------------------------------
			// obtendo o tempo inicial
			clock_t ini = clock();
		
			OddevenSort(tamanho_vetor, vetor); // ordena o vetor usando o OddevenSort
		
			// obtendo o tempo final
			clock_t fim = clock();

			// obtendo a duracao total da ordenacao
			long double duracao_microsegundos = (double)(fim - ini) * 1e6 / CLOCKS_PER_SEC;
			
			duracao_media_oddeven += duracao_microsegundos;
			
		}
		
		duracao_media_oddeven = duracao_media_oddeven / 5.0;
		printf("[Oddeven] N = %d, tempo medio de execucao = %.2Lf microssegundos\n", tamanho_vetor, duracao_media_oddeven);
		fprintf(ofs, "%d %Lf\n", tamanho_vetor, duracao_media_oddeven);
	}
	
	fclose(ofs);// fecha arquivo de resultados do Oddeven Sort
	// ------------------------------------------------------------
	
	
	// ------------------------------------------------------------
	// Etapa 3 - Execução do BubbleSort
	// Para cada arquivo gerado na etapa 1, ler o arquivo e popular
	// um vetor de inteiros com os dados lidos.
	FILE *ofs2 = fopen("resultados/resultadoBubble.txt", "w"); 
    if (ofs2 == NULL) {
        perror("Erro ao abrir o arquivo para escrita");
        exit(EXIT_FAILURE);
    }
	
	for(int iteracao = 0; iteracao < TOTAL_N; iteracao++) {
		
		long double duracao_media_bubble = 0.0;
		const int tamanho_vetor = tam[iteracao]; // pega o tamanho do vetor para esta iteracao
		int vetor[tamanho_vetor]; // cria vetor a ser ordenado
		
		// Para cada tamanho de vetor, a funcao gera_dados() gerou 5 vetores diferentes. 
		// Cada um usou uma semente diferente. Agora, vamos ler cada um desses vetores, 
		// Chamar o bubblesort para ordena-los e, entao, calcular o tempo medio de 
		// execucao dessas cinco chamadas e depois salvar esse tempo medio em arquivo.
		for(int semente = 0; semente < 5; semente++) 
		{	
			char nome_arquivo[150];
            snprintf(nome_arquivo, sizeof(nome_arquivo),
                     "dados/random%d_%d.dat", iteracao, semente);
			
			ler_dados(tamanho_vetor, vetor, nome_arquivo);
			
			// BubbleSort ---------------------------------------------------------
			// obtendo o tempo inicial
			clock_t ini2 = clock();
		
			BubbleSort(tamanho_vetor, vetor); // ordena o vetor usando o BubbleSort
		
			// obtendo o tempo final
			clock_t fim2 = clock();
		
			// obtendo a duracao total da ordenacao
			long double duracao_bubble = (double)(fim2 - ini2) * 1e6 / CLOCKS_PER_SEC;

			duracao_media_bubble += duracao_bubble;			
		}	
		
		duracao_media_bubble = duracao_media_bubble / 5.0;
		printf("[Bubble] N = %d, tempo medio de execucao = %.2Lf microssegundos\n", tamanho_vetor, duracao_media_bubble);
		fprintf(ofs2, "%d %Lf\n", tamanho_vetor, duracao_media_bubble);
	}
	
	fclose(ofs2); // fecha arquivo de resultados do Bubble Sort
	// ------------------------------------------------------------
	

	// ------------------------------------------------------------
	// Etapa 4 - Execução do InsertionSort
	// Para cada arquivo gerado na etapa 1, ler o arquivo e popular
	// um vetor de inteiros com os dados lidos.
	FILE *ofs3 = fopen("resultados/resultadoInsertion.txt", "w"); 
    if (ofs3 == NULL) {
        perror("Erro ao abrir o arquivo para escrita");
        exit(EXIT_FAILURE);
    }
	
	for(int iteracao = 0; iteracao < TOTAL_N; iteracao++) {
		
		long double duracao_media_insertion = 0.0;
		const int tamanho_vetor = tam[iteracao]; // pega o tamanho do vetor para esta iteracao
		int vetor[tamanho_vetor]; // cria vetor a ser ordenado
		
		// Para cada tamanho de vetor, a funcao gera_dados() gerou 5 vetores diferentes. 
		// Cada um usou uma semente diferente. Agora, vamos ler cada um desses vetores, 
		// Chamar o InsertionSort para ordena-los e, entao, calcular o tempo medio de 
		// execucao dessas cinco chamadas e depois salvar esse tempo medio em arquivo.
		for(int semente = 0; semente < 5; semente++) 
		{	
			char nome_arquivo[150];
            snprintf(nome_arquivo, sizeof(nome_arquivo),
                     "dados/random%d_%d.dat", iteracao, semente);
			
			ler_dados(tamanho_vetor, vetor, nome_arquivo);
			
			// InsertionSort ---------------------------------------------------------
			// obtendo o tempo inicial
			clock_t ini2 = clock();
		
			InsertionSort(tamanho_vetor, vetor); // ordena o vetor usando o InsertionSort
		
			// obtendo o tempo final
			clock_t fim2 = clock();
		
			// obtendo a duracao total da ordenacao
			long double duracao_insertion = (double)(fim2 - ini2) * 1e6 / CLOCKS_PER_SEC;

			duracao_media_insertion += duracao_insertion;			
		}	
		
		duracao_media_insertion = duracao_media_insertion / 5.0;
		printf("[Insertion] N = %d, tempo medio de execucao = %.2Lf microssegundos\n", tamanho_vetor, duracao_media_insertion);
		fprintf(ofs3, "%d %Lf\n", tamanho_vetor, duracao_media_insertion);
	}
	
	fclose(ofs3); // fecha arquivo de resultados do InsertionSort
	// ------------------------------------------------------------
	

	// ------------------------------------------------------------
	// Etapa 5 - Execução do SelectionSort
	// Para cada arquivo gerado na etapa 1, ler o arquivo e popular
	// um vetor de inteiros com os dados lidos.
	FILE *ofs4 = fopen("resultados/resultadoSelection.txt", "w"); 
    if (ofs4 == NULL) {
        perror("Erro ao abrir o arquivo para escrita");
        exit(EXIT_FAILURE);
    }
	
	for(int iteracao = 0; iteracao < TOTAL_N; iteracao++) {
		
		long double duracao_media_selection = 0.0;
		const int tamanho_vetor = tam[iteracao]; // pega o tamanho do vetor para esta iteracao
		int vetor[tamanho_vetor]; // cria vetor a ser ordenado
		
		// Para cada tamanho de vetor, a funcao gera_dados() gerou 5 vetores diferentes. 
		// Cada um usou uma semente diferente. Agora, vamos ler cada um desses vetores, 
		// Chamar o SelectionSort para ordena-los e, entao, calcular o tempo medio de 
		// execucao dessas cinco chamadas e depois salvar esse tempo medio em arquivo.
		for(int semente = 0; semente < 5; semente++) 
		{	
			char nome_arquivo[150];
            snprintf(nome_arquivo, sizeof(nome_arquivo),
                     "dados/random%d_%d.dat", iteracao, semente);
			
			ler_dados(tamanho_vetor, vetor, nome_arquivo);
			
			// SelectionSort ---------------------------------------------------------
			// obtendo o tempo inicial
			clock_t ini2 = clock();
		
			SelectionSort(tamanho_vetor, vetor); // ordena o vetor usando o SelectionSort
		
			// obtendo o tempo final
			clock_t fim2 = clock();
		
			// obtendo a duracao total da ordenacao
			long double duracao_selection = (double)(fim2 - ini2) * 1e6 / CLOCKS_PER_SEC;

			duracao_media_selection += duracao_selection;			
		}	
		
		duracao_media_selection = duracao_media_selection / 5.0;
		printf("[Selection] N = %d, tempo medio de execucao = %.2Lf microssegundos\n", tamanho_vetor, duracao_media_selection);
		fprintf(ofs4, "%d %Lf\n", tamanho_vetor, duracao_media_selection);
	}
	
	fclose(ofs4); // fecha arquivo de resultados do SelectionSort
	// ------------------------------------------------------------

	// ------------------------------------------------------------
	// Etapa 6 - Execução do MergeSort
	// Para cada arquivo gerado na etapa 1, ler o arquivo e popular
	// um vetor de inteiros com os dados lidos.
	FILE *ofs5 = fopen("resultados/resultadoMerge.txt", "w"); 
    if (ofs5 == NULL) {
        perror("Erro ao abrir o arquivo para escrita");
        exit(EXIT_FAILURE);
    }
	
	for(int iteracao = 0; iteracao < TOTAL_N; iteracao++) {
		
		long double duracao_media_merge = 0.0;
		const int tamanho_vetor = tam[iteracao]; // pega o tamanho do vetor para esta iteracao
		int vetor[tamanho_vetor]; // cria vetor a ser ordenado
		
		// Para cada tamanho de vetor, a funcao gera_dados() gerou 5 vetores diferentes. 
		// Cada um usou uma semente diferente. Agora, vamos ler cada um desses vetores, 
		// Chamar o MergeSort para ordena-los e, entao, calcular o tempo medio de 
		// execucao dessas cinco chamadas e depois salvar esse tempo medio em arquivo.
		for(int semente = 0; semente < 5; semente++) 
		{	
			char nome_arquivo[150];
            snprintf(nome_arquivo, sizeof(nome_arquivo),
                     "dados/random%d_%d.dat", iteracao, semente);
			
			ler_dados(tamanho_vetor, vetor, nome_arquivo);
			
			// MergeSort ---------------------------------------------------------
			// obtendo o tempo inicial
			clock_t ini2 = clock();
		
			MergeSort(vetor, 0, tamanho_vetor - 1);; // ordena o vetor usando o MergeSort
		
			// obtendo o tempo final
			clock_t fim2 = clock();
		
			// obtendo a duracao total da ordenacao
			long double duracao_merge = (double)(fim2 - ini2) * 1e6 / CLOCKS_PER_SEC;

			duracao_media_merge += duracao_merge;			
		}	
		
		duracao_media_merge = duracao_media_merge / 5.0;
		printf("[Merge] N = %d, tempo medio de execucao = %.2Lf microssegundos\n", tamanho_vetor, duracao_media_merge);
		fprintf(ofs5, "%d %Lf\n", tamanho_vetor, duracao_media_merge);
	}
	
	fclose(ofs5); // fecha arquivo de resultados do MergeSort
    // ------------------------------------------------------------
	

	// ------------------------------------------------------------
	// Etapa 7 - Execução do QuickSort
	// Para cada arquivo gerado na etapa 1, ler o arquivo e popular
	// um vetor de inteiros com os dados lidos.
	FILE *ofs6 = fopen("resultados/resultadoQuick.txt", "w"); 
    if (ofs6 == NULL) {
        perror("Erro ao abrir o arquivo para escrita");
        exit(EXIT_FAILURE);
    }
	
	for(int iteracao = 0; iteracao < TOTAL_N; iteracao++) {
		
		long double duracao_media_quick = 0.0;
		const int tamanho_vetor = tam[iteracao]; // pega o tamanho do vetor para esta iteracao
		int vetor[tamanho_vetor]; // cria vetor a ser ordenado
		
		// Para cada tamanho de vetor, a funcao gera_dados() gerou 5 vetores diferentes. 
		// Cada um usou uma semente diferente. Agora, vamos ler cada um desses vetores, 
		// Chamar o MergeSort para ordena-los e, entao, calcular o tempo medio de 
		// execucao dessas cinco chamadas e depois salvar esse tempo medio em arquivo.
		for(int semente = 0; semente < 5; semente++) 
		{	
			char nome_arquivo[150];
            snprintf(nome_arquivo, sizeof(nome_arquivo),
                     "dados/random%d_%d.dat", iteracao, semente);
			
			ler_dados(tamanho_vetor, vetor, nome_arquivo);
			
			// QuickSort ---------------------------------------------------------
			// obtendo o tempo inicial
			clock_t ini2 = clock();
		
			QuickSort(vetor, 0, tamanho_vetor - 1); // ordena o vetor usando o QuickSort
		
			// obtendo o tempo final
			clock_t fim2 = clock();
		
			// obtendo a duracao total da ordenacao
			long double duracao_quick = (double)(fim2 - ini2) * 1e6 / CLOCKS_PER_SEC;

			duracao_media_quick += duracao_quick;			
		}	
		
		duracao_media_quick = duracao_media_quick / 5.0;
		printf("[Quick] N = %d, tempo medio de execucao = %.2Lf microssegundos\n", tamanho_vetor, duracao_media_quick);
		fprintf(ofs6, "%d %Lf\n", tamanho_vetor, duracao_media_quick);
	}
	
	fclose(ofs6); // fecha arquivo de resultados do QuickSort
	return 0;
}