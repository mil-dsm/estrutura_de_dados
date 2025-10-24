# Algoritmos de ordenação
# Disciplina: Estruturas de Dados
# Turma: 01A
# Nome: Milena de Sousa Mesquita
# Matrícula: 581180

import matplotlib.pyplot as plt

# Caminho do arquivo de entrada e saída
arquivo_entrada = "../resultados/resultadoInsertion.txt"
arquivo_saida = "graficoInsertion.png"
nome_do_algoritmo = "InsertionSort"

# Listas para armazenar os dados
tamanhos = []
tempos = []

# Ler o arquivo
with open(arquivo_entrada, 'r') as f:
    for linha in f:
        if linha.strip() == "":
            continue
        partes = linha.split()
        tamanhos.append(int(partes[0]))
        tempos.append(float(partes[1]))

# Criar o gráfico
plt.figure(figsize=(12,7))
plt.plot(
    tamanhos, tempos, 
    color='#1f77b4',     # cor azul moderna
    marker='o',          # marcador circular
    markersize=6,        # tamanho do marcador
    linestyle='-',       # linha sólida
    linewidth=2,         # espessura da linha
    label="Tempo " + nome_do_algoritmo
)

# Estilo do gráfico
plt.xlabel("Tamanho do Vetor", fontsize=14, fontweight='bold')
plt.ylabel("Microssegundos", fontsize=14, fontweight='bold')
plt.title("Desempenho do "+nome_do_algoritmo, fontsize=16, fontweight='bold')
plt.grid(True, linestyle='--', alpha=0.6)
plt.xticks(fontsize=12)
plt.yticks(fontsize=12)
plt.legend(fontsize=12)

# Salvar o gráfico em PNG
plt.tight_layout()
plt.savefig(arquivo_saida, dpi=300)
plt.show()