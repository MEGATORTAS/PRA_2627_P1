#ifndef DYV_H
#define DYV_H

#include <vector>
#include <utility>
template <typename T>
int busquedaBinaria(T X, const std::vector<T>& V, int ini, int fin) {
    if (ini > fin) {
        return -1;
    }
    
    int medio = (ini + fin) / 2;
    
    if (V[medio] == X) {
        return medio;
    } else if (V[medio] > X) {
        return busquedaBinaria(X, V, ini, medio - 1);
    } else {
        return busquedaBinaria(X, V, medio + 1, fin);
    }
}

template <typename T>
int Partition(std::vector<T>& V, int ini, int fin) {
    T x = V[fin];
    int i = ini;

    for (int j = ini; j < fin; j++) {
        if (V[j] <= x) {
            std::swap(V[i], V[j]);
            i++;
        }
    }
    std::swap(V[i], V[fin]);
    return i;
}

template <typename T>
void quicksort(std::vector<T>& V, int ini, int fin) {
    if (ini < fin) {
        int pivot = Partition(V, ini, fin);
        quicksort(V, ini, pivot - 1);
        quicksort(V, pivot + 1, fin);
    }
}

#endif
