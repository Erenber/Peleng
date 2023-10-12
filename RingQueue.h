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

	T& push(T); //���������� �������� � �������
	T& front(); //������ ������� �������� + ��������� ��� � ����� (�.�. ��������� �������)
	T& back();  //������ ���������� ��������

	void swap(RingQueue<T>&); //����� �������� ����� �����

	Node<T>* begin(); //������ ��� ��������� (�� ����� ������������ � �� ��� ����)
	Node<T>* end();

	void pop(); //��������� ������� ������ ������� (��� �������� � ����� �������)
	void clear(); //������ ������� �������

	bool isEmpty(); //�������� �� ������ ������
	bool isFull(); //�������� �� ������ ����������

	int getSize(); //������� ������

	bool operator==(const RingQueue<T>&) const; 
	RingQueue<T>& operator=(const RingQueue<T>&);
};

template class RingQueue<int>;