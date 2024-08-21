#include <iostream>   // Inclui a biblioteca padrão de entrada e saída, usada para operações como std::cout.
#include <chrono>     // Inclui a biblioteca para medição de tempo, usada para medir a performance do código.
#include <vector>     // Inclui a biblioteca para uso de std::vector, uma alternativa moderna para arrays dinâmicos.

int manualAlloc() {
    int N = 1000;  // Define o tamanho da matriz como N x N, onde N é 1000.

    // Alocação dinâmica de memória para uma matriz N x N.
    // Primeiro, aloca um array de ponteiros, onde cada ponteiro irá apontar para uma linha da matriz.
    int** matriz = new int*[N];

    // Para cada linha da matriz, aloca um array de inteiros de tamanho N.
    for (int i = 0; i < N; ++i) {
        matriz[i] = new int[N];
    }

    // Aqui você pode inicializar e somar os elementos da matriz.
    // Por exemplo, você pode preencher a matriz com valores e calcular a soma total.
    int soma = 0;
    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < N; ++j) {
            matriz[i][j] = i + j;  // Preenche a matriz com a soma dos índices i e j.
            soma += matriz[i][j];  // Soma o valor atual à variável soma.
        }
    }

    // Imprime a soma total dos elementos da matriz.
    std::cout << "Soma total dos elementos da matriz: " << soma << std::endl;

    // Liberação da memória alocada dinamicamente.
    // Primeiro, libera a memória alocada para cada linha (os arrays de inteiros).
    for (int i = 0; i < N; ++i) {
        delete[] matriz[i];
    }

    // Finalmente, libera a memória alocada para o array de ponteiros.
    delete[] matriz;

    return 0;  // Retorna 0, indicando que o programa terminou com sucesso.
}

int vectorAlloc() {
    int N = 1000;  // Define o tamanho da matriz como N x N, onde N é 1000.

    // Alocação dinâmica de memória para uma matriz N x N usando std::vector.
    // Cria um vetor de vetores de inteiros, onde cada vetor interno representa uma linha da matriz.
    std::vector<std::vector<int>> matriz(N, std::vector<int>(N));

    // Aqui você pode inicializar e somar os elementos da matriz.
    // Por exemplo, você pode preencher a matriz com valores e calcular a soma total.
    int soma = 0;
    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < N; ++j) {
            matriz[i][j] = i + j;  // Preenche a matriz com a soma dos índices i e j.
            soma += matriz[i][j];  // Soma o valor atual à variável soma.
        }
    }

    // Imprime a soma total dos elementos da matriz.
    std::cout << "Soma total dos elementos da matriz: " << soma <<std::endl;

    return 0;  // Retorna 0, indicando que o programa terminou com sucesso.
}

int main(){
    // Medir o tempo de execução de manualAlloc
    auto inicioManual = std::chrono::high_resolution_clock::now();
    manualAlloc();
    auto fimManual = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double> duracaoManual = fimManual - inicioManual;
    std::cout << "Tempo de execução de manualAlloc: " << duracaoManual.count() << " segundos" << std::endl;

    // Medir o tempo de execução de vectorAlloc
    auto inicioVector = std::chrono::high_resolution_clock::now();
    vectorAlloc();
    auto fimVector = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double> duracaoVector = fimVector - inicioVector;
    std::cout << "Tempo de execução de vectorAlloc: " << duracaoVector.count() << " segundos" << std::endl;

    return 0;
}
