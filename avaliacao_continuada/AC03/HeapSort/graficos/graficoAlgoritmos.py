# Algoritmos de ordenação
# Disciplina: Estruturas de Dados
# Turma: 01A
# Nome: Milena de Sousa Mesquita
# Matrícula: 581180

import os
import matplotlib.pyplot as plt

# Caminho dos arquivos
diretorio_script = os.path.dirname(os.path.abspath(__file__))
arquivo_bubble = os.path.join(diretorio_script, "../resultados/resultadoBubble.txt")
arquivo_heap = os.path.join(diretorio_script, "../resultados/resultadoHeap.txt")
arquivo_insertion = os.path.join(diretorio_script, "../resultados/resultadoInsertion.txt")
arquivo_selection = os.path.join(diretorio_script, "../resultados/resultadoSelection.txt")
arquivo_merge = os.path.join(diretorio_script, "../resultados/resultadoMerge.txt")
arquivo_quick = os.path.join(diretorio_script, "../resultados/resultadoQuick.txt")
arquivo_saida = os.path.join(diretorio_script, "comparativoAlgoritmos.png")

# Função para ler arquivo com duas colunas
def ler_dados(caminho):
    tamanhos = []
    tempos = []
    with open(caminho, 'r') as f:
        for linha in f:
            if linha.strip() == "":
                continue
            partes = linha.split()
            tamanhos.append(int(partes[0]))
            tempos.append(float(partes[1]))
    return tamanhos, tempos

# Ler os dados
t_bubble, tempo_bubble = ler_dados(arquivo_bubble)
t_heap, tempo_heap = ler_dados(arquivo_heap)
t_insertion, tempo_insertion = ler_dados(arquivo_insertion)
t_selection, tempo_selection = ler_dados(arquivo_selection)
t_merge, tempo_merge = ler_dados(arquivo_merge)
t_quick, tempo_quick = ler_dados(arquivo_quick)

# Criar o gráfico
plt.figure(figsize=(12,7))

plt.plot(
    t_bubble, tempo_bubble,
    color='#1f77b4',     # azul
    marker='o',          # marcador circular
    markersize=6,        # tamanho do marcador
    linestyle='-',       # linha sólida
    linewidth=2,         # espessura da linha
    label='Bubble Sort'
)

plt.plot(
    t_heap, tempo_heap,
    color='#ff7f0e',     # laranja
    marker='s',          # marcador quadrado
    markersize=6,        # tamanho do marcador
    linestyle='-',       # linha sólida
    linewidth=2,         # espessura da linha
    label='Heap Sort'
)

plt.plot(
    t_insertion, tempo_insertion,
    color='#2ca02c',     # verde
    marker='^',          # marcador triangular
    markersize=6,        # tamanho do marcador
    linestyle='-',       # linha sólida
    linewidth=2,         # espessura da linha
    label='Insertion Sort'
)

plt.plot(
    t_selection, tempo_selection,
    color='#d62728',     # vermelho
    marker='v',          # marcador triangular invertido
    markersize=6,        # tamanho do marcador
    linestyle='-',       # linha sólida
    linewidth=2,         # espessura da linha
    label='Selection Sort'
)

plt.plot(
    t_merge, tempo_merge,
    color='#9467bd',     # roxo
    marker='>',          # marcador de seta para a direita
    markersize=6,        # tamanho do marcador
    linestyle='-',       # linha sólida
    linewidth=2,         # espessura da linha
    label='Merge Sort'
)

plt.plot(
    t_quick, tempo_quick,
    color='#8c564b',     # marrom
    marker='<',          # marcador de seta para a esquerda
    markersize=6,        # tamanho do marcador
    linestyle='-',       # linha sólida
    linewidth=2,         # espessura da linha
    label='Quick Sort'
)

# Estilo do gráfico
plt.xlabel("Tamanho do Vetor", fontsize=14, fontweight='bold')
plt.ylabel("Microssegundos", fontsize=14, fontweight='bold')
plt.title("Comparativo de Desempenho dos Algoritmos de Ordenação", fontsize=16, fontweight='bold')
plt.grid(True, which='both', linestyle='--', alpha=0.6)
plt.xticks(fontsize=12)
plt.yticks(fontsize=12)

# Legenda fora da área, sem cortar
plt.legend(fontsize=12, loc='upper left', bbox_to_anchor=(1,1))

# Escala log com rótulos 10^k
from matplotlib.ticker import LogLocator, LogFormatterMathtext, NullFormatter
ax = plt.gca()
ax.set_yscale('log')

# Ticks maiores em potências de 10, menores entre elas
ax.yaxis.set_major_locator(LogLocator(base=10))
ax.yaxis.set_major_formatter(LogFormatterMathtext())  # mostra 10^3, 10^4...
ax.yaxis.set_minor_locator(LogLocator(base=10, subs=range(2,10)))
ax.yaxis.set_minor_formatter(NullFormatter())

plt.tight_layout()
plt.savefig(arquivo_saida, dpi=300, bbox_inches='tight')
plt.show()