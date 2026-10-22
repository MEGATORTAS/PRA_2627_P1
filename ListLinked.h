#ifndef LIST_LINKED_H
#define LIST_LINKED_H

#include <ostream>
#include <stdexcept>
#include "List.h"
#include "Node.h"

template <typename T>
class ListLinked : public List<T> {
    private:
        // Puntero al inicio de la lista y contador de elementos
        Node<T>* first;
        int n;

    public:
        // Constructor sin argumentos
        ListLinked() : first(nullptr), n(0) {}

        // Destructor: libera la memoria de los nodos enlazados
        ~ListLinked() {
            while (first != nullptr) {
                Node<T>* aux = first->next;
                delete first;
                first = aux;
            }
        }

        // Operador [] para acceder a elementos
        T operator[](int pos) {
            if (pos < 0 || pos >= n) { // Asumiendo que n equivale a size()
                throw std::out_of_range("Posición fuera de los límites válidos");
            }
            Node<T>* current = first;
            for (int i = 0; i < pos; ++i) {
                current = current->next;
            }
            return current->data;
        }

        // Sobrecarga del operador << para imprimir la lista
        friend std::ostream& operator<<(std::ostream &out, const ListLinked<T> &list) {
            Node<T>* current = list.first;
            while (current != nullptr) {
                out << current->data << " ";
                current = current->next;
            }
            return out;
        }
};

#endif
