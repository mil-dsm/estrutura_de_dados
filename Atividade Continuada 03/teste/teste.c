// ------------------------------------------------------------
	// Etapa 2 - Execucao do CocktailSort
	// Para cada arquivo gerado na etapa 1, ler o arquivo e popular
	// um vetor de inteiros com os dados lidos.

	FILE *ofs = fopen("resultados/resultadoCocktail.txt", "w"); 
    if (ofs == NULL) {
        perror("Erro ao abrir o arquivo para escrita");
        exit(EXIT_FAILURE);
    }

	for(int iteracao = 0; iteracao < TOTAL_N; iteracao++) 
	{	
		long double duracao_media_cocktail = 0.0;
		const int tamanho_vetor = tam[iteracao]; // pega o tamanho do vetor para esta iteracao
		int vetor[tamanho_vetor]; // cria vetor a ser ordenado
		
		// Para cada tamanho de vetor, a funcao gera_dados() gerou 5 vetores diferentes. 
		// Cada um usou uma semente diferente. Agora, vamos ler cada um desses vetores, 
		// Chamar o cocktail sort para ordena-los e, entao, calcular o tempo medio de 
		// execucao dessas cinco chamadas e depois salvar esse tempo medio em arquivo.
		for(int semente = 0; semente < 5; semente++) 
		{	
			char nome_arquivo[150];
            snprintf(nome_arquivo, sizeof(nome_arquivo),
                     "dados/random%d_%d.dat", iteracao, semente);
			
			ler_dados(tamanho_vetor, vetor, nome_arquivo);
			
			// CocktailSort ------------------------------------------------------
			// obtendo o tempo inicial
			clock_t ini = clock();
		
			CocktailSort(tamanho_vetor, vetor); // ordena o vetor usando o CocktailSort
		
			// obtendo o tempo final
			clock_t fim = clock();

			// obtendo a duracao total da ordenacao
			long double duracao_microsegundos = (double)(fim - ini) * 1e6 / CLOCKS_PER_SEC;
			
			duracao_media_cocktail += duracao_microsegundos;
			
		}
		
		duracao_media_cocktail = duracao_media_cocktail / 5.0;
		printf("[Cocktail] N = %d, tempo medio de execucao = %.2Lf microssegundos\n", tamanho_vetor, duracao_media_cocktail);
		fprintf(ofs, "%d %Lf\n", tamanho_vetor, duracao_media_cocktail);
	}
	
	fclose(ofs);// fecha arquivo de resultados do CockTail Sort
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

