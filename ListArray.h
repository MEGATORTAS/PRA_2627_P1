#include <ostream>
#include <stdexcept>
#include "List.h"

template <typename T> 
class ListArray : public List<T> {

    private:
        // miembros privados
	T* arr;
	int max;
	int n;
	static const int MINSIZE=2;
	void resize (int new_size);

    public:
        // miembros públicos, incluidos los heredados de List<T>
    	ListArray(){
		arr = new T*[MINSIZE];
		max= MINSIZE;
		n=0;
	}

	~ListArray() override{
		delete[] arr;
	}

	T operator[] (int pos){
		if (pos < 0 || pos > n){
			throw std::out_of_range ("Posición inválida");
		}
		return arr[pos];
	}

	friend std::ostream& operator<< (std::ostream &out, ListArray<T> &list){
		out << "[ ";
		for(int i=0;i<list.n;i++){
			out << list.arr[i];
			if(i< list.n-1){
				out<< ", ";
			}
		}
		out << "]";
		return out;
	}



};
