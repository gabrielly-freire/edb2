#include <iostream>
#include <vector>
#include <fstream>
#include <cstdlib>
#include <chrono>
#include "question3.hpp"

using namespace std;
/**
 * @brief Carrega um vetor de inteiros a partir de um arquivo.
 * 
 * @param nomeArquivo O nome do arquivo a ser carregado.
 */
vector<int> carregarDeArquivo(const string& nomeArquivo) {
    vector<int> numeros;
    ifstream arquivo(nomeArquivo);
    int numero;

    if (arquivo.is_open()) {
        while (arquivo >> numero) {
            numeros.push_back(numero);
        }
        arquivo.close();
    } else {
        cerr << "Erro ao abrir o arquivo " << nomeArquivo << endl;
    }

    return numeros;
}

/**
 * @brief Mede o tempo de execução de um algoritmo de ordenação.
 * 
 * @param algoritmo O algoritmo a ser medido.
 * @param v O vetor a ser ordenado.
 * @param n O tamanho do vetor.
 */
double medirTempo(void (*algoritmo)(int*, int), int* v, int n) {
    auto start = chrono::high_resolution_clock::now();
    algoritmo(v, n); 
    auto end = chrono::high_resolution_clock::now();
    
    return chrono::duration<double, milli>(end - start).count();
}

/**
 * @brief Função principal.
 */
int main() {
    srand(static_cast<unsigned int>(time(0)));

    int tamanhos[] = {1000, 10000, 100000};
    string nomesArquivos[] = {"lista_1000.txt", "lista_10000.txt", "lista_100000.txt"};
    
    ofstream arquivoResultado("resultados_computados.txt");
    
    for (int i = 0; i < 3; i++) {
        vector<int> numeros = carregarDeArquivo(nomesArquivos[i]);

        double tempoBubbleRecursivo = medirTempo(Ordenacao::bubblesort_recursivo, numeros.data(), numeros.size());

        double tempoMergeRecursivo = medirTempo(Ordenacao::mergesort_recursivo, numeros.data(), numeros.size());
    
        double tempoQuickRecursivo = medirTempo(Ordenacao::quicksort_recursivo, numeros.data(), numeros.size());

        double tempoBubbleIterativo = medirTempo(Ordenacao::bubblesort_iterativo, numeros.data(), numeros.size());

        double tempoMergeIterativo = medirTempo(Ordenacao::mergesort_iterativo, numeros.data(), numeros.size());

        double tempoQuickIterativo = medirTempo(Ordenacao::quicksort_iterativo, numeros.data(), numeros.size());

        arquivoResultado << "Resultados para tamanho: " << tamanhos[i] << "\n";
        arquivoResultado << "BubbleSort Recursivo: " << tempoBubbleRecursivo << " ms\n";
        arquivoResultado << "MergeSort Recursivo: " << tempoMergeRecursivo << " ms\n";
        arquivoResultado << "QuickSort Recursivo: " << tempoQuickRecursivo << " ms\n";
        arquivoResultado << "BubbleSort Iterativo: " << tempoBubbleIterativo << " ms\n";
        arquivoResultado << "QuickSort Iterativo: " << tempoQuickIterativo << " ms\n";
        arquivoResultado << "MergeSort Iterativo: " << tempoMergeIterativo << " ms\n\n";
    }
    
    cout << "Resultados salvos em resultados_computados.txt.\n";

    arquivoResultado.close(); 

    return 0;
}
