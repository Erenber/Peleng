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

	T& push(T); //add an item to the queue
	T& front(); //taking the first element + putting it in the tail (RING queue)
	T& back();  //taking the last element

	void swap(RingQueue<T>&);

	Node<T>* begin();//methods for the iterator (but can be used not for it)
	Node<T>* end();

	void pop(); //completely REMOVE the first element (without returning to the end of the queue)
	void clear(); //completely clear the queue

	bool isEmpty();
	bool isFull();

	int getSize(); //get current size

	bool operator==(const RingQueue<T>&) const; 
	RingQueue<T>& operator=(const RingQueue<T>&);
};

template class RingQueue<int>;