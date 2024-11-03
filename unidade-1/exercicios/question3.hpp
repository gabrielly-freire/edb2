#ifndef ORDENACAO_HPP
#define ORDENACAO_HPP

#include <stdlib.h>
#include <cstdlib>
#include <stack>

using namespace std;

class Ordenacao {
    public:
        static void bubblesort_iterativo(int *v, int n);
        static void bubblesort_recursivo(int *v, int n);
        static void mergesort_iterativo(int *v, int n);
        static void mergesort_recursivo(int *v, int n);
        static void quicksort_iterativo(int *v, int n);
        static void quicksort_recursivo(int *v, int n);
    private:
        static void trocar(int *v, int i, int j);
        static void juntar(int *v, int n, int m);
        static int separar(int *v, int n);
        static int min(int a, int b);
};

#endif