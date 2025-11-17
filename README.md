# Ordena-o-e-An-lise-de-Desempenho-em-C-lark-
Quick Sort Benchmark com Métricas (RGM)
Este projeto em C implementa o algoritmo de ordenação Quick Sort utilizando o esquema de partição de Lomuto. O objetivo principal é não apenas ordenar uma sequência de dígitos (especificamente, os dígitos de um RGM predefinido), mas também rastrear e relatar métricas detalhadas de desempenho, como o número total de comparações e trocas realizadas durante o processo de ordenação, além do tempo de execução.
Estrutura do Código
O código é dividido em seções lógicas para facilitar a manutenção e a análise.
1. Estrutura de Métricas (Metricas)
Define uma estrutura para armazenar os contadores de desempenho:
comparacoes: Número total de comparações realizadas.
trocas: Número total de trocas de elementos realizadas.
Macros (CONTAR_COMPARACAO, CONTAR_TROCA) são usadas para incrementar esses contadores de forma clara dentro das funções de ordenação.
2. Funções Auxiliares
Contém funções utilitárias como:
resetar_metricas: Zera os contadores.
trocar: Realiza a troca de dois elementos, incrementando o contador de trocas.
imprimir_vetor: Imprime os elementos do vetor.
copiar_vetor: Cria uma cópia do vetor para que a ordenação não altere o original, se necessário, ou para preparar o vetor para o benchmark.
3. Quick Sort (Partição Lomuto)
Implementa o algoritmo Quick Sort:
particionar: Implementa a lógica da partição de Lomuto, escolhendo o último elemento como pivô. É nesta função que a maior parte das CONTAR_COMPARACAO e trocar ocorrem.
quick_sort_recursivo: Função recursiva principal do Quick Sort.
quick_sort: Função de entrada que inicializa as métricas e chama a função recursiva.
4. Função de Benchmark (executar_ordenacao)
Responsável por cronometrar a execução da ordenação.
Cria uma cópia do vetor de entrada.
Utiliza clock() para medir o tempo de execução.
Retorna o tempo decorrido em milissegundos.
5. Conversão do RGM
converter_rgm_para_vetor: Converte uma string de RGM (ex: "44947615") em um vetor de inteiros ({4, 4, 9, 4, 7, 6, 1, 5}).
6. Função Principal (main)
Define o RGM a ser ordenado ("44947615").
Executa a conversão e a ordenação.
Imprime o RGM original e o RGM ordenado.
Exibe um resumo final no formato CSV para facilitar a análise de dados.
Como Compilar e Executar
O código pode ser compilado usando um compilador C padrão, como o GCC.
Dependências
stdio.h
stdlib.h
string.h
time.h
Comandos
Salve o código como quicksort_rgm.c.
Compile usando GCC:
code
Bash
gcc quicksort_rgm.c -o quicksort_rgm
Execute o programa:
code
Bash
./quicksort_rgm
Saída Esperada
A saída do programa apresentará o vetor de dígitos antes e depois da ordenação, seguido pelo resumo das métricas em formato CSV.
code
Code
RGM original: 44947615
RGM ordenado: 14456799

=== RESUMO EM FORMATO CSV ===
metodo,N,caso,passos,tempo_ms
quick_sort,8,rgm,<passos_totais_aqui>,<tempo_em_ms_aqui>
Nota: Os valores de <passos_totais_aqui> (Comparações + Trocas) e <tempo_em_ms_aqui> podem variar dependendo do hardware e do compilador, mas o formato será consistente.
