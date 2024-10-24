#include <iostream>
#include <vector>
#include <cstdlib>
#include <ctime>
#include <chrono>
#include <algorithm>

using namespace std;

/**
 * @brief Gera um vetor de números aleatórios.
 *
 * Esta função gera um vetor contendo números aleatórios entre 0 e 1000.
 *
 * @param n O número de números a serem gerados.
 * @return Um vetor contendo os números gerados.
 */
vector<int> gerarNumeros(int n){
    vector<int> idades(n);
    for (int i = 0; i < n; i++) {
        idades[i] = rand() % 101;
    }
    return idades;
}

/**
 * @brief Realiza a busca binária em um vetor ordenado.
 *
 * @param A O vetor onde a busca será realizada.
 * @param x O valor a ser buscado.
 * @return O índice do elemento se encontrado, ou -1 se não encontrado.
 */
int buscaBinaria(const vector<int>& A, int x) {
    int esq = 0;
    int dir = A.size() - 1;

    while (esq <= dir) {
        int m = (esq + dir) / 2;

        if (A[m] == x) {
            return m;
        } else if (x > A[m]) {
            esq = m + 1;
        } else {
            dir = m - 1;
        }
    }

    return -1;
}

/**
 * @brief Realiza a busca binária recursiva em um vetor ordenado.
 *
 * @param A O vetor onde a busca será realizada.
 * @param esq O índice inicial da busca.
 * @param dir O índice final da busca.
 * @param x O valor a ser buscado.
 * @return O índice do elemento se encontrado, ou -1 se não encontrado.
 */
int bBinRec(const vector<int>& A, int esq, int dir, int x) {
    if (esq > dir) {
        return -1;
    }

    int m = (esq + dir) / 2;

    if (A[m] == x) {
        return m;
    }

    if (A[m] > x) {
        return bBinRec(A, esq, m - 1, x);
    } else {
        return bBinRec(A, m + 1, dir, x);
    }
}

/**
 * @brief Mede o tempo de execução de uma função de busca binária.
 *
 * Esta função mede quanto tempo uma função leva para realizar uma busca
 * binária e imprime o resultado em milissegundos.
 *
 * @param func Um ponteiro para a função de busca binária a ser medida.
 * @param idades Um vetor de inteiros ordenado.
 * @param valor O valor a ser buscado no vetor.
 */
void medeTempo(int (*func)(const vector<int>&, int), vector<int>& idades, int valor) {
    auto start = chrono::high_resolution_clock::now();
    int resultado = func(idades, valor);
    auto end = chrono::high_resolution_clock::now();

    chrono::duration<double, milli> duration = end - start;
    cout << "Tempo de execução: " << duration.count() << " ms" << endl;
}

/**
 * @brief Mede o tempo de execução da busca binária recursiva.
 *
 * Função wrapper para passar a assinatura correta da função `bBinRec` para `medeTempo`.
 *
 * @param A O vetor onde a busca será realizada.
 * @param x O valor a ser buscado.
 * @return O índice do elemento se encontrado, ou -1 se não encontrado.
 */
int bBinRecWrapper(const vector<int>& A, int x) {
    return bBinRec(A, 0, A.size() - 1, x); 
}

int main(){
    srand(time(0));

    cout << "Teste com n = 100:" << endl;
    vector<int> idades100 = gerarNumeros(100);
    sort(idades100.begin(), idades100.end());
    int valor100 = rand() % 101;
    medeTempo(buscaBinaria, idades100, valor100);
    medeTempo(bBinRecWrapper, idades100, valor100);

    cout << "\nTeste com n = 1000:" << endl;
    vector<int> idades1000 = gerarNumeros(1000);
    sort(idades1000.begin(), idades1000.end());
    int valor1000 = rand() % 101;
    medeTempo(buscaBinaria, idades1000, valor1000);
    medeTempo(bBinRecWrapper, idades1000, valor1000);

    cout << "\nTeste com n = 10.000:" << endl;
    vector<int> idades10000 = gerarNumeros(10000);
    sort(idades10000.begin(), idades10000.end());
    int valor10000 = rand() % 101;
    medeTempo(buscaBinaria, idades10000, valor10000);
    medeTempo(bBinRecWrapper, idades10000, valor10000);

    return 0;
}
