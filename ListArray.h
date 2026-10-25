#include <ostream>
#include <stdexcept>
#include "List.h"

template <typename T>
class ListArray : public List <T> {
	private:
		T* arr;
		int max;
		int n;
		static const int MINSIZE;
		void resize (int new_size);

	public:
		ListArray();
		~ ListArray() override;
		T operator[](int pos);
		friend std::ostream&operator<<(std::ostream &out, ListArray<T> &list);

};
template <typename T>
const int ListArray<T>::MINSIZE = 2;

template <typename T>
ListArray<T>::ListArray(){
	arr = new T[MINSIZE];
	max = MINSIZE;
	n = 0;
}

template<typename T>
ListArray<T>::~ ListArray() {
	delete[] arr;
}

template <typename T>
T ListArray<T>::operatorint pos {
	if (pos < 0 || pos >= n)
		throw std::out_of_range("Posicion fuera de rango");
	return arr[pos];
}

template <typename T>
void ListArray<T>::resize(int new_size){
	T* nuevo = new T[new_size];

	for (int i = 0; i < n; i++){
		nuevo[i] = arr[i];
}

delete[] arr;

arr = nuevo;
max = new_size;
}

template <typename T>
int ListArray<T>::size(){
	return n;
}

template <typename T>
bool ListArray<T>::empty(){
	return n == 0;
}

template <typename T>
T ListArray<T>::get(int pos){
	if (pos < 0 || pos >= n)
		throw std::out_of_range("Posicion fuera de rango");
	return arr[pos];
}

template <typename T>
int ListArray<T>::search(T e){
	for (int i = 0; i < n; i++) {
		if (arr[i] == e)
			return i;
	}
	return -1;
}

template <typename T>
void ListArray<T>::append(T e) {
	if (n == max)
		resize(max * 2);
	arr[n] = e;
	n++;
}

template <typename T>
void ListArray<T>::prepend(T e){
	if (n == max)
		resize(max*2);
	for (int i = n; i > 0; i--){
		arr[i] = arr[i - 1];
	}

	arr[0] = e;
	n++;
}

template <typename T>
void ListArray<T>::insert(int pos, T e){
	if (pos < 0 || pos >n)
		throw std::out_of_range("Posicion fuera de rango");
	if (n == max)
		resize(max * 2);
	for (int i = n; i>pos; i--){
		arr[i] = arr[i-1];
	}

	arr[pos] = e;
	n++;
}

template <typename T>
T ListArray <T>::remove(int pos){

	if (pos<0 || pos>=n)
		throw std::out_of_range("Posicion fuera de rango");
	T eliminado = arr[pos];
	for (int i = pos; i < n-1; i++){
		arr[i] = arr[i+1];
	}

	n--;
	
	if (n <= max / 4 && max / 2 >= MINSIZE)
		resize(max / 2);
	return eliminado;
}

template <typename T>
std::ostream& operator<<(std::ostream& out, ListArray<T>& list) {
	out << "[";

	for (int i=0; i<list.n; i++){
		if (i < list.n - 1)
			out << ",";
	}

	out << "]";

	return out;
}


