#ifndef FILAESTATICA_HPP
#define FILAESTATICA_HPP

#include <cstdlib>
#include "Config.hpp"
#include <cmath>

template <class T>
struct static_node
{
	T* element;
};

template <class T>
class FilaEstatica
{
public:
	FilaEstatica(int max_length = MAX_length);
	~FilaEstatica();

	/**************************************
	* enqueue the element                 *
	* if the queue is full, returns error *
	* else returns succsess               *
	**************************************/
	int enqueue(T* element);

	/***********************************************
	* dequeue and returns the element at the front *
	* if the queue is empty, returns nullptr       *
	***********************************************/
	T* dequeue();

	/*************************************************************
	* returns the element at the front without remove it, if any *
	* else returns nullptr                                       *
	*************************************************************/
	T* front();

	/**********************************
	* returns the length of the queue *
	**********************************/
	int length();

	/*************************************
	* returns true if the queue is empty *
	*************************************/
	bool isEmpty();

	/************************************
	* returns true if the queue is full *
	************************************/
	bool isFull();
	
private:
	int Length;
	int max_length;
	int Front;
	int back;
	struct static_node<T>* fila;
};

template<class T>
FilaEstatica<T>::FilaEstatica(int max_length)
{
	Length = 0;
	this->max_length = max_length;
	Front = -1;
	back = -1;
	fila = new struct static_node<T>[max_length];
}

template<class T>
FilaEstatica<T>::~FilaEstatica()
{
	delete(fila);
}

template<class T>
int FilaEstatica<T>::enqueue(T* element)
{
	if ( isFull() )
		return ERROR;

	if ( isEmpty() )
	{
		Front = 0;
		back = 0;
		fila[back].element = element;
		Length++;

		return SUCCESS;
	}

	back++;
	back = back % max_length;
	fila[back].element = element;
	Length++;

	return SUCCESS;
}

template<class T>
T* FilaEstatica<T>::dequeue()
{
	T* element;

	if ( isEmpty() )
		return nullptr;

	element = fila[Front].element;
	Front++;
	Front = Front % max_length;
	Length--;

	if( isEmpty() )
	{
		Front = -1;
		back = -1;
	}

	return element;
}

template<class T>
T* FilaEstatica<T>::front()
{
	if ( isEmpty() )
		return nullptr;

	return fila[Front].element;
}

template<class T>
int FilaEstatica<T>::length()
{
	return Length;
}

template<class T>
bool FilaEstatica<T>::isEmpty()
{
	return (Length == 0);
}

template<class T>
bool FilaEstatica<T>::isFull()
{
	return (Length == max_length);
}

#endif
