#ifndef LIST_LINKED_H
#define LIST_LINKED_H

#include <ostream>
#include <stdexcept>
#include "List.h"
#include "Node.h"

template <typename T>
class ListLinked : public List<T> {
    private:
        Node<T>* first;
        int n;

    public:
        ListLinked() : first(nullptr), n(0) {}

        // Destructor: libera la memoria de los nodos enlazados
        ~ListLinked() {
            while (first != nullptr) {
                Node<T>* aux = first->next;
                delete first;
                first = aux;
            }
        }

        T operator[](int pos) {
            if (pos < 0 || pos >= n) {
                throw std::out_of_range("Posición fuera de los límites válidos");
            }
            Node<T>* current = first;
            for (int i = 0; i < pos; ++i) {
                current = current->next;
            }
            return current->data;
        }

        friend std::ostream& operator<<(std::ostream &out, const ListLinked<T> &list) {
            Node<T>* current = list.first;
            while (current != nullptr) {
                out << current->data << " ";
                current = current->next;
            }
            return out;
        }
        // --- Métodos heredados de la interfaz List<T> ---
        void insert(int pos, T e) override {
            if (pos < 0 || pos > n) throw std::out_of_range("Posición inválida");
            if (pos == 0) {
                first = new Node<T>(e, first);
            } else {
                Node<T>* aux = first;
                for (int i = 0; i < pos - 1; ++i) aux = aux->next;
                aux->next = new Node<T>(e, aux->next);
            }
            n++;
        }

        void append(T e) override { insert(n, e); }
        void prepend(T e) override { insert(0, e); }

        T remove(int pos) override {
            if (pos < 0 || pos >= n) throw std::out_of_range("Posición inválida");
            Node<T>* aux = first;
            T val;
            if (pos == 0) {
                first = first->next;
                val = aux->data;
                delete aux;
            } else {
                Node<T>* prev = first;
                for (int i = 0; i < pos - 1; ++i) prev = prev->next;
                aux = prev->next;
                prev->next = aux->next;
                val = aux->data;
                delete aux;
            }
            n--;
            return val;
        }

        T get(int pos) override { return operator[](pos); }

        int search(T e) override {
            Node<T>* aux = first;
            for (int i = 0; i < n; ++i) {
                if (aux->data == e) return i;
                aux = aux->next;
            }
            return -1;
        }

        bool empty() override { return n == 0; }
        int size() override { return n; }
};

#endif
