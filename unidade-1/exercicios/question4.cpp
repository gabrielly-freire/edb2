#include <iostream>
#include <vector>
#include <fstream>
#include "util.hpp"

using namespace std;

/**
 * @brief Salva um vetor de inteiros em um arquivo de texto.
 *
 * Esta função salva os números inteiros contidos no vetor em um arquivo .txt.
 *
 * @param numeros O vetor de inteiros a ser salvo.
 * @param nomeArquivo O nome do arquivo onde os números serão salvos.
 */
void salvarEmArquivo(const vector<int>& numeros, const string& nomeArquivo) {
    ofstream arquivo(nomeArquivo);
    if (arquivo.is_open()) {
        for (int numero : numeros) {
            arquivo << numero << endl;
        }
        arquivo.close();
        cout << "Arquivo " << nomeArquivo << " salvo com sucesso!" << endl;
    } else {
        cerr << "Erro ao abrir o arquivo " << nomeArquivo << endl;
    }
}

int main() {

    int tamanhos[] = {1000, 10000, 100000};
    string nomesArquivos[] = {"lista_1000.txt", "lista_10000.txt", "lista_100000.txt"};

    for (int i = 0; i < 3; i++) {
        vector<int> numeros = Util::gerarNumeros(tamanhos[i]);
        salvarEmArquivo(numeros, nomesArquivos[i]);
    }

    return 0;
}
