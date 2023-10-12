#pragma once
#include<iostream>

#define MAX_SIZE 10

template<typename T>
class RingQueue
{
private:

	template<typename T>
	class Node
	{
	public:
		Node* next;
		T data;

		Node(T data = T(), Node* next = nullptr)
		{
			this->data = data;
			this->next = next;
		}
	};

	int maxSize;
	int currentSize;

	Node<T>* head;
	Node<T>* tail;
	Node<T>* LRU; //least recently used

public:

	class Iterator
	{
	private:
		Node<T>* current;
	public:
		Iterator(Node<T>*);
		Iterator& operator++();
		Iterator operator++(int);
		T& operator*();
		const T& operator*() const;
		bool operator==(const Iterator&) const;
		bool operator!=(const Iterator&) const;
	};


	RingQueue();
	RingQueue(int);
	RingQueue(const RingQueue<T>&);
	~RingQueue();

	T& push(T); //добавление элемента в очередь
	T& front(); //вз€тие первого элемента + помещение его в хвост (т.к. кольцева€ очередь)
	T& back();  //вз€тие последнего элемента

	void swap(RingQueue<T>&); //обмен очередей между собой

	Node<T>* begin(); //методы дл€ итератора (но можно использовать и не дл€ него)
	Node<T>* end();

	void pop(); //полностью ”ƒјЋ»“№ первый элемент (без возврата в конец очереди)
	void clear(); //полна€ очистка очереди

	bool isEmpty(); //проверка на пустой список
	bool isFull(); //проверка на полное заполнение

	int getSize(); //текущий размер

	bool operator==(const RingQueue<T>&) const; 
	RingQueue<T>& operator=(const RingQueue<T>&);
};

template class RingQueue<int>;