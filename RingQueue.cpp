#include "RingQueue.h"

//Queue
template<typename T>
RingQueue<T>::RingQueue()
{
	this->maxSize = MAX_SIZE;
	currentSize = 0;
	head = nullptr;
	tail = nullptr;
	LRU = nullptr;
}
template<typename T>
RingQueue<T>::RingQueue(int maxSize)
{
	if (maxSize < 1)
	{
		throw std::logic_error("\nIncorrect size");
	}
	this->maxSize = maxSize;
	currentSize = 0;
	head = nullptr;
	tail = nullptr;
	LRU = nullptr;
}
template<typename T>
RingQueue<T>::RingQueue(const RingQueue<T>& other) :
	maxSize(other.maxSize), currentSize(other.currentSize)
{

	if (other.head == nullptr) {
		head = tail = LRU = nullptr;
		return;
	}

	head = new Node<T>(other.head->data);
	tail = head;

	if (other.LRU == other.head)
	{
		LRU = head;
	}

	Node<T>* otherCurrent = other.head->next;

	while (otherCurrent != nullptr)
	{
		tail->next = new Node<T>(otherCurrent->data);

		if (otherCurrent == other.LRU) LRU = tail->next;

		tail = tail->next;
		otherCurrent = otherCurrent->next;
	}
}
template<typename T>
RingQueue<T>::~RingQueue()
{
	clear();
}
template<typename T>
T& RingQueue<T>::push(T data)
{
	if (isEmpty())
	{
		head = new Node<T>(data);
		tail = LRU = head;
		currentSize = 1;
	}
	else if (isFull())
	{
		LRU->data = data;
		if (LRU == tail) {
			LRU = head;
		}
		else
		{
			LRU = LRU->next;
		}
	}
	else
	{
		tail->next = new Node<T>(data);
		tail = tail->next;
		currentSize += 1;
	}

	return tail->data;
}
template<typename T>
T& RingQueue<T>::front()
{
	if (isEmpty())
		throw std::logic_error("Queue is empty");

	if (currentSize == 1)
		return head->data;

	//head shifts to the end
	tail->next = head; 
	tail = tail->next; 
	head = head->next; 
	tail->next = nullptr;

	return tail->data;
}
template<typename T>
T& RingQueue<T>::back()
{
	if (isEmpty())
		throw std::logic_error("\n\nQueue is empty");

	return tail->data;
}
template<typename T>
void RingQueue<T>::swap(RingQueue<T>& other)
{
	int tmpCurrentSize = other.currentSize;
	int tmpMaxSize = other.maxSize;
	Node<T>* tmpHead = other.head;
	Node<T>* tmpTail = other.tail;
	Node<T>* tmpLRU = other.LRU;

	other.currentSize = this->currentSize;
	other.maxSize = this->maxSize;
	other.head = this->head;
	other.tail = this->tail;
	other.LRU = this->LRU;

	this->currentSize = tmpCurrentSize;
	this->maxSize = tmpMaxSize;
	this->head = tmpHead;
	this->tail = tmpTail;
	this->LRU = tmpLRU;
}
template<typename T>
void RingQueue<T>::pop()
{
	if (isEmpty()) {
		throw std::logic_error("Queue is empty");
	}

	if (LRU == head) {
		LRU = LRU->next;
	}

	Node<T>* temp = head;
	head = head->next;
	delete temp;

	currentSize -= 1;
}
template<typename T>
void RingQueue<T>::clear()
{
	while (!isEmpty())
	{
		pop();
	}
}
template<typename T>
bool RingQueue<T>::isEmpty()
{
	return currentSize == 0;
}
template<typename T>
bool RingQueue<T>::isFull()
{
	return currentSize == maxSize;
}
template<typename T>
int RingQueue<T>::getSize()
{
	return currentSize;
}
template<typename T>
bool RingQueue<T>::operator==(const RingQueue<T>& other) const
{
	if (maxSize != other.maxSize ||
		currentSize != other.currentSize
		)
	{
		return false;
	}

	Node<T>* first = head;
	Node<T>* second = other.head;

	//lists are the same size,  
	//"currentSize" check above
	while (first)
	{
		if (first->data != second->data)
			return false;

		first = first->next;
		second = second->next;
	}

	if (LRU->data != other.LRU->data)
	{
		return false;
	}

	return true;
}
template<typename T>
RingQueue<T>& RingQueue<T>::operator=(const RingQueue<T>& other) {

	if (this == &other) {
		return *this;
	}

	clear();

	*this = RingQueue<T>(other);
	return *this;
}
template<typename T>
typename RingQueue<T>::Node<T>* RingQueue<T>::begin() {
	return head;
}
template<typename T>
typename RingQueue<T>::Node<T>* RingQueue<T>::end()
{
	return nullptr;
}

//Iterator
template<typename T>
RingQueue<T>::Iterator::Iterator(Node<T>* node) :
	current(node){};
template<typename T>
typename RingQueue<T>::Iterator& RingQueue<T>::Iterator::operator++()
{
	current = current->next;
	return *this;
}
template<typename T>
typename RingQueue<T>::Iterator RingQueue<T>::Iterator::operator++(int)
{
	Iterator temp = *this;
	++(*this);
	return temp;
}
template<typename T>
typename T& RingQueue<T>::Iterator::operator*()
{
	return current->data;
}
template<typename T>
typename const T& RingQueue<T>::Iterator::operator*() const
{
	return current->data;
}
template<typename T>
typename bool RingQueue<T>::Iterator::operator!=(const Iterator& other) const
{
	return current != other.current;
}
template<typename T>
typename bool RingQueue<T>::Iterator::operator==(const Iterator& other) const
{
	return current == other.current;
}