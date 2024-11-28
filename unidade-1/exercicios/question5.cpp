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
 * @brief Salva o vetor ordenado em um arquivo.
 * 
 * @param nomeArquivo O nome do arquivo onde o vetor será salvo.
 * @param v O vetor a ser salvo.
 */
void salvarEmArquivo(const string& nomeArquivo, const vector<int>& v) {
    ofstream arquivo(nomeArquivo);
    if (arquivo.is_open()) {
        for (const int& numero : v) {
            arquivo << numero << "\n";
        }
        arquivo.close();
    } else {
        cerr << "Erro ao criar o arquivo " << nomeArquivo << endl;
    }
}

/**
 * @brief Função principal.
 */
int main() {
    srand(static_cast<unsigned int>(time(0)));

    int tamanhos[] = {1000, 10000, 100000};
    string nomesArquivos[] = {"lista_1000.txt", "lista_10000.txt", "lista_100000.txt"};
    
    ofstream arquivoResultado("resultados.txt");
    
    if (!arquivoResultado.is_open()) {
        cerr << "Erro ao abrir o arquivo resultados.txt" << endl;
        return 1; 
    }

    for (int i = 0; i < 3; i++) {
        vector<int> numeros = carregarDeArquivo(nomesArquivos[i]);

        // BubbleSort Recursivo
        vector<int> copia = numeros; 
        double tempoBubbleRecursivo = medirTempo(Ordenacao::bubblesort_recursivo, copia.data(), copia.size());
        salvarEmArquivo("bubblesort_recursivo_" + to_string(tamanhos[i]) + ".txt", copia);

        // MergeSort Recursivo
        copia = numeros;
        double tempoMergeRecursivo = medirTempo(Ordenacao::mergesort_recursivo, copia.data(), copia.size());
        salvarEmArquivo("mergesort_recursivo_" + to_string(tamanhos[i]) + ".txt", copia);

        // QuickSort Recursivo
        copia = numeros;
        double tempoQuickRecursivo = medirTempo(Ordenacao::quicksort_recursivo, copia.data(), copia.size());
        salvarEmArquivo("quicksort_recursivo_" + to_string(tamanhos[i]) + ".txt", copia);

        // BubbleSort Iterativo
        copia = numeros;
        double tempoBubbleIterativo = medirTempo(Ordenacao::bubblesort_iterativo, copia.data(), copia.size());
        salvarEmArquivo("bubblesort_iterativo_" + to_string(tamanhos[i]) + ".txt", copia);

        // MergeSort Iterativo
        copia = numeros;
        double tempoMergeIterativo = medirTempo(Ordenacao::mergesort_iterativo, copia.data(), copia.size());
        salvarEmArquivo("mergesort_iterativo_" + to_string(tamanhos[i]) + ".txt", copia);

        // QuickSort Iterativo
        copia = numeros;
        double tempoQuickIterativo = medirTempo(Ordenacao::quicksort_iterativo, copia.data(), copia.size());
        salvarEmArquivo("quicksort_iterativo_" + to_string(tamanhos[i]) + ".txt", copia);

        cout << "Resultados para tamanho: " << tamanhos[i] << "\n";
        
        arquivoResultado << "Resultados para tamanho: " << tamanhos[i] << "\n";
        
        cout << "BubbleSort Recursivo: " << tempoBubbleRecursivo << " ms\n";
        cout << "MergeSort Recursivo: " << tempoMergeRecursivo << " ms\n";
        cout << "QuickSort Recursivo: " << tempoQuickRecursivo << " ms\n";
        
        cout << "BubbleSort Iterativo: " << tempoBubbleIterativo << " ms\n";
        cout << "MergeSort Iterativo: " << tempoMergeIterativo << " ms\n";
        cout << "QuickSort Iterativo: " << tempoQuickIterativo << " ms\n\n";

        arquivoResultado << "BubbleSort Recursivo: " << tempoBubbleRecursivo << " ms\n";
        arquivoResultado << "MergeSort Recursivo: " << tempoMergeRecursivo << " ms\n";
        arquivoResultado << "QuickSort Recursivo: " << tempoQuickRecursivo << " ms\n";
        
        arquivoResultado << "BubbleSort Iterativo: " << tempoBubbleIterativo << " ms\n";
        arquivoResultado << "MergeSort Iterativo: " << tempoMergeIterativo << " ms\n";
        arquivoResultado << "QuickSort Iterativo: " << tempoQuickIterativo << " ms\n\n";
    }

    arquivoResultado.close();
    
    return 0;
}
