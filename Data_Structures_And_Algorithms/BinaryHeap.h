#pragma once
#ifndef BINARYHEAP_H
#define BINARYHEAP_H
#include<vector>
#include<stdexcept>

template<typename T>
class BinaryHeap
{
public:
	explicit BinaryHeap(int capacity = 100) :currentSize(capacity) {}
	explicit BinaryHeap(const std::vector<T> &items);

	bool isEmpty() const;
	const T &findMin() const;

	void insert(const T &x);
	void deleteMin();
	void deleteMin(T &minItem);
	void makeEmpty();

private:
	int currentSize;
	std::vector<T> array;

	void buildHeap();
	void percolateDown(int hole);
};

template<typename T>
BinaryHeap<T>::BinaryHeap(const std::vector<T> &items)
	:array(items.size() + 10), currentSize(items.size())
{
	for (int i = 0;i < items.size();i++)
		array[i + 1] = items[i];
	buildHeap();
}

template<typename T>
void BinaryHeap<T>::buildHeap()
{
	for (int i = currentSize / 2;i > 0;i--)
		percolateDown(i);
}

template<typename T>
void BinaryHeap<T>::percolateDown(int hole)
{
	int child;
	T temp = array[hole];
	for (;hole * 2 <= currentSize;hole = child)
	{
		if (child != currentSize&&array[child + 1] < array[child])
			child++;
		if (array[child] < temp)
			array[hole] = array[child];
		else
			break;
	}
	array[hole] = temp;
}

template<typename T>
bool BinaryHeap<T>::isEmpty() const
{
	if (array.empty())
		return true;
	else
		return false;
}

template<typename T>
const T &BinaryHeap<T>::findMin() const
{
	return array[1];
}

template<typename T>
void BinaryHeap<T>::insert(const T &x)
{
	if (currentSize == array.size() - 1)
		array.resize(array.size() * 2);
	int hole = ++currentSize;
	for (;hole > 1 && x < array[hole / 2];hole /= 2)
	{
		array[hole] = array[hole / 2];
	}
	array[hole] = x;
}

template<typename T>
void BinaryHeap<T>::deleteMin()
{
	if (isEmpty())
		throw std::underflow_error("BinaryHeap is empty!");
	array[1] = array[currentSize--];
	percolateDown(1);
}

template<typename T>
void BinaryHeap<T>::deleteMin(T &minItem)
{
	if (isEmpty())
		throw std::underflow_error("BinaryHeap is empty");
	minItem = array[1];
	array[1] = array[currentSize--];
	percolateDown(1);
}

template<typename T>
void BinaryHeap<T>::makeEmpty()
{
	if (isEmpty())
		throw std::underflow_error("BinaryHeap is empty!");
	array.clear();
}

#endif // !BINARYHEAP_H
