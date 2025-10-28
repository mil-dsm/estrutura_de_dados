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
arquivo_insertion = os.path.join(diretorio_script, "../resultados/resultadoInsertion.txt")
arquivo_selection = os.path.join(diretorio_script, "../resultados/resultadoSelection.txt")
arquivo_saida = os.path.join(diretorio_script, "comparativoAlgoritmos_n2.png")

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
t_insertion, tempo_insertion = ler_dados(arquivo_insertion)
t_selection, tempo_selection = ler_dados(arquivo_selection)

# Criar o gráfico
plt.figure(figsize=(12,7))

plt.plot(
    t_bubble, tempo_bubble,
    color='#1f77b4',   # azul
    marker='o',
    markersize=6,
    linestyle='-',
    linewidth=2,
    label='Bubble Sort'
)

plt.plot(
    t_insertion, tempo_insertion,
    color='#2ca02c',   # laranja
    marker='^',        # quadrado
    markersize=6,
    linestyle='-',
    linewidth=2,
    label='Insertion Sort'
)

plt.plot(
    t_selection, tempo_selection,
    color='#d62728',   # laranja
    marker='v',        # quadrado
    markersize=6,
    linestyle='-',
    linewidth=2,
    label='Selection Sort'
)

# Estilo do gráfico
plt.xlabel("Tamanho do Vetor", fontsize=14, fontweight='bold')
plt.ylabel("Microssegundos", fontsize=14, fontweight='bold')
plt.title("Comparativo — Algoritmos O(n²)", fontsize=16, fontweight='bold')
plt.grid(True, linestyle='--', alpha=0.6)
plt.xticks(fontsize=12)
plt.yticks(fontsize=12)
plt.legend(fontsize=12)

# Forçar notação científica no eixo Y com '1e7'
import matplotlib.ticker as ticker
plt.ticklabel_format(style='sci', axis='y', scilimits=(0,0))
plt.gca().yaxis.get_offset_text().set_fontsize(12)  # deixa o '1e7' legível

# Salvar e mostrar
plt.ticklabel_format(style='plain', axis='y')
plt.tight_layout()
plt.savefig(arquivo_saida, dpi=300)
plt.show()