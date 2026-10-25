#ifndef NODE_H
#define NODE_H

#include <ostream>

template <typename T>
class Node {
	public:
		T data;
		Node<T>* next;
		Node(T data, Node<T>*next=nullptr);
		friend std::ostream& operator <<(std::ostream &out, const Node<T> &node);

};

template <typename T>
Node<T>::Node(T data, Node<T>* next){
	this->data = data;
	this->next = next;
}

#endif
