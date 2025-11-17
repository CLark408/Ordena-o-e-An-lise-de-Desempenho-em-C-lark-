Quick Sort - Análise de Desempenho (RGM)
🎯 Descrição
Este projeto em C implementa o algoritmo de ordenação Quick Sort utilizando o esquema de Partição de Lomuto. Seu objetivo principal é ordenar os dígitos de um número de Registro Geral de Matrícula (RGM) específico e realizar uma análise detalhada do desempenho do algoritmo neste cenário de "caso real" com um pequeno conjunto de dados.
O código rastreia e exibe métricas essenciais, como o número de comparações, o número de trocas e o tempo de execução.
✨ Funcionalidades
Implementação Quick Sort: Utiliza a técnica de ordenação Quick Sort (Partição de Lomuto).
Contagem de Métricas: Rastreia o número exato de comparações e trocas (swaps) realizadas.
Medição de Tempo: Calcula o tempo de execução da ordenação em milissegundos (ms).
Conversão RGM: Converte a string do RGM em um vetor de dígitos inteiros.
Saída CSV: Gera os resultados em um formato de tabela CSV para fácil importação e análise de dados.
🔢 RGM Alvo
O código está configurado para ordenar os dígitos do seguinte RGM:
code
C
const char *rgm = "44947615"; // N = 8
⚙️ Pré-requisitos
Para compilar e executar este código, você precisará de um compilador C instalado no seu sistema (ex: GCC, Clang, etc.).
🚀 Compilação e Execução
Siga os passos abaixo em um terminal Linux, macOS ou similar (ou use o ambiente de desenvolvimento de sua preferência):
Salve o código: Salve o código-fonte como um arquivo (por exemplo, quick_sort_rgm.c).
Compile: Use o GCC para compilar o arquivo.
code
Bash
gcc quick_sort_rgm.c -o quick_sort_rgm
Execute: Execute o programa compilado.
code
Bash
./quick_sort_rgm
🖥️ Exemplo de Saída
A execução do programa no terminal deve produzir uma saída semelhante a esta:
code
Code
========================================
  ORDENAÇÃO DE RGM - QUICK SORT
========================================

RGM: 44947615

Dígitos do RGM (antes da ordenação):
Vetor Original: 4 4 9 4 7 6 1 5 

----------------------------------------
Executando Quick Sort...
----------------------------------------
Vetor Ordenado: 1 4 4 4 5 6 7 9 

========================================
  RESULTADOS (Formato CSV)
========================================

metodo,N,caso,comparacoes,trocas,tempo_ms
quick_sort,8,rgm,16,6,0.003120

========================================
  MÉTRICAS DETALHADAS
========================================
Método:       Quick Sort (Partição Lomuto)
Tamanho (N):  8 dígitos
Caso:         RGM
Comparações:  16
Trocas:       6
Tempo:        0.003120 ms
========================================
Nota: Os valores de Comparações, Trocas e Tempo podem variar dependendo da arquitetura do processador e do compilador/biblioteca C utilizados.
📂 Estrutura do Código
Função / Estrutura	Descrição
Metricas	Estrutura para rastrear comparacoes e trocas.
trocar	Função auxiliar que incrementa o contador de trocas.
particionar	Implementa o esquema de Partição de Lomuto.
quick_sort_recursivo	Lógica recursiva principal do Quick Sort.
quick_sort	Função wrapper que inicializa as métricas.
converter_rgm_para_vetor	Converte a string RGM em um array de inteiros.
executar_ordenacao	Função de benchmark: copia o vetor, mede o tempo e chama a ordenação.
main	Função principal que orquestra a execução, exibindo os resultados.
