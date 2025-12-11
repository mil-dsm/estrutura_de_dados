// Função Intercala é uma função auxiliar do algoritmo Merge Sort que promete
// unir dois subvetores já ordenados, A[p...q] e A[q+1...r], em um único vetor
// ordenado A[p...r]. Essa etapa combina os resultados das chamadas recursivas
// do Merge Sort, mantendo a ordenação crescente.
// Entrada: vetor 'A[0...n-1]' e índices 'p', 'q' e 'r'
// Saída: vetor 'A[p...r]' reorganizado em ordem crescente.
void Intercala(int A[], int p, int q, int r){
	int B[r-p+1], i = p, j = q + 1, k = 0;
	// Intercala A[p...q] e A[q+1...r], colocando o valor do menor elemento em B[p...r]
	while(i <= q && j <= r){
		if(A[i] <= A[j]){
			B[k++] = A[i++];
		}
		else{
			B[k++] = A[j++];
		}
	}
	// Caso ainda tenham sobrado números, são copiados para o vetor auxiliar B[p...r]
	while(i <= q){
		B[k++] = A[i++];
	}
	while(j <= r){
		B[k++] = A[j++];
	}
	// Copia vetor ordenado B[p...r] para o vetor A[p...r]
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
		int q = (p + r) / 2; // Dividir em dois subvetores
		// Conquistar: ordenar os dois subvetores
		MergeSort(A, p, q);
		MergeSort(A, q+1, r);
		// Combinar os dois subvetores ordenados
		Intercala(A, p, q, r);
	}
}

