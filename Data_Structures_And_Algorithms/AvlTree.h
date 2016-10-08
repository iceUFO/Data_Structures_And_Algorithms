#pragma once
#ifndef AVLTREE_H
#define AVLTREE_H
#include<iostream>
#include<algorithm>

template<typename T>
class AvlTree
{
public:
	AvlTree() :root(nullptr) {}
	AvlTree(const AvlTree &rhs);
	~AvlTree();
    const AvlTree &operator=(const AvlTree &rhs);

	const T &findMin() const;
	const T &findMax() const;
	bool contains(const T &x) const;
	bool isEmpty() const;
	void printTree() const;

	void makeEmpty();
	void insert(const T &x);
	void remove(const T &x);

private:
	struct AvlNode
	{
		T element;
		AvlNode *left;
		AvlNode *right;
		int height;

		AvlNode(const T &theElement, AvlNode *lt, AvlNode *rt, int h = 0)
			:element(theElement), left(lt), right(rt), height(h) {}
	};

	AvlNode *root;

private:
	void rotateWithLeftChild(AvlNode *&k2);
	void rotateWithRightChild(AvlNode *&k2);
	void doubleWithLeftChild(AvlNode *&k3);
	void doubleWithRightChild(AvlNode *&k3);

	int height(AvlNode *t) const;

	void insert(const T &x, AvlNode *&t);
	void remove(const T &x, AvlNode *&t);

	AvlNode *findMin(AvlNode *t) const;
	AvlNode *findMax(AvlNode *t) const;

	bool contains(const T &x, AvlNode *t) const;
	void makeEmpty(AvlNode *&t);
	void printTree(AvlNode *t) const;
	AvlNode *clone(AvlNode *t) const;

};

template<typename T>
bool AvlTree<T>::contains(const T &x, AvlNode *t) const
{
	if (t == nullptr)
		return false;
	else if (x < t->element)
		contains(x, t->left);
	else if (t->element < x)
		contains(x, t->right);
	else
		return true;
}

template<typename T>
bool AvlTree<T>::contains(const T &x) const
{
	return contains(x, root);
}

template<typename T>
typename AvlTree<T>::AvlNode *AvlTree<T>::findMin(AvlNode *t) const
{
	if(t!=nullptr)
		while (t->left!=null)
		{
			t = t->left;
		}
	return t;
}

template<typename T>
const T &AvlTree<T>::findMin() const
{
	return findMin(root)->element;
}

template<typename T>
typename AvlTree<T>::AvlNode *AvlTree<T>::findMax(AvlNode *t) const
{
	if(t!=nullptr)
		while (t->right!=nullptr)
		{
			t = t->right;
		}
	return t;
}

template<typename T>
const T &AvlTree<T>::findMax() const
{
	return findMax(root)->element;
}

template<typename T>
bool AvlTree<T>::isEmpty() const
{
	if (this != nullptr)
		return false;
	return true;
}

template<typename T>
void AvlTree<T>::printTree(AvlNode *t) const
{
	if (t)
	{
		printTree(t->left);
		std::cout << t->element << " ";
		printTree(t->right);
	}
}

template<typename T>
void AvlTree<T>::printTree() const
{
	printTree(root);
}

template<typename T>
void AvlTree<T>::makeEmpty(AvlNode *&t)
{
	if (t != nullptr)
	{
		makeEmpty(t->left);
		makeEmpty(t->right);
		delete t;
	}
	t = nullptr;
}

template<typename T>
void AvlTree<T>::makeEmpty()
{
	makeEmpty(root);
}

template<typename T>
AvlTree<T>::~AvlTree()
{
	makeEmpty();
}

template<typename T>
typename AvlTree<T>::AvlNode *AvlTree<T>::clone(AvlNode *t) const
{
	if (t == nullptr)
		return nullptr;
	return new AvlNode(t->element, clone(t->left), clone(t->right), t->height);
}

template<typename T>
AvlTree<T>::AvlTree(const AvlTree &rhs)
{
	*this = rhs;
}

template<typename T>
const AvlTree<T> &AvlTree<T>::operator=(const AvlTree &rhs)
{
	if (this != &rhs)
	{
		makeEmpty();
		root = clone(rhs.root);
	}
	return *this;
}

template<typename T>
int AvlTree<T>::height(AvlNode *t) const
{
	return t == nullptr ? -1 : t->element;
}

template<typename T>
void AvlTree<T>::rotateWithLeftChild(AvlNode *&k2)
{
	AvlNode *k1 = k2->left;
	k2->left = k1->right;
	k1->right = k2;
	k2->height = std::max(height(k2->left), height(k2->right)) + 1;
	k1->height = std::max(height(k1->left), k2->height) + 1;
	k2 = k1;
}

template<typename T>
void AvlTree<T>::rotateWithRightChild(AvlNode *&k2)
{
	AvlNode *k1 = k2->right;
	k2->rhght = k1->left;
	k1->left = k2;
	k2->height = std::max(height(k2->left), height(k2->right)) + 1;
	k1->height = std::max(k2->height, height(k1->right)) + 1;
	k2 = k1;
}

template<typename T>
void AvlTree<T>::doubleWithLeftChild(AvlNode *&k3)
{
	rotateWithRightChild(k3->left);
	rotateWithLeftChild(k3);
}

template<typename T>
void AvlTree<T>::doubleWithRightChild(AvlNode *&k3)
{
	rotateWithLeftChild(k3->right);
	rotateWithRightChild(k3);
}

template<typename T>
void AvlTree<T>::insert(const T &x, AvlNode *&t)
{
	if (t == nullptr)
		t = new AvlNode(x, nullptr, nullptr);
	else if (x < t->element)
	{
		insert(x, t->left);
		if (height(t->left) - height(t->right) == 2)
		{
			if (x < t->left->element)
				rotateWithLeftChild(t);
			else
				doubleWithLeftChild(t);
		}
	}
	else if (t->element < x)
	{
		insert(x, t->right);
		if (height(t->right) - height(t->left) == 2)
		{
			if (t->right->element < x)
				rotateWithRightChild(t);
			else
				doubleWithRightChild(t);
		}
	}
	else
		return;
	t->height = std::max(height(t->left), height(t->right)) + 1;
}

template<typename T>
void AvlTree<T>::insert(const T &x)
{
	insert(x, root);
}

template<typename T>
void AvlTree<T>::remove(const T &x, AvlNode *&t)
{
	if (t == nullptr)
		return;
	else if (x < t->element)
	{
		remove(x, t->left);
		if (height(t->right) - height(t->left) == 2)
		{
			if (height(t->right->left) <= height(t->right->right))
				rotateWithRightChild(t);
			else
				doubleWithRightChild(t);
		}
	}
	else if (t->element < x)
	{
		remove(x, t->right);
		if (height(t->left) - height(t->right) == 2)
		{
			if (height(t->left->right) <= height(t->left->left))
				rotateWithLeftChild(t);
			else
				doubleWithLeftChild(t);
		}
	}
	else if (t->left != nullptr && t->right != nullptr)
	{
		t->element = findMix(t->right)->element;
		remove(t->element, t->right);
		t->height = std::max(height(t->left), height(t->right)) + 1;
	}
	else
	{
		AvlNode *oldNode = t;
		t = (t->left != nullptr) ? t->left : t->right;
		delete oldNode;
	}

	if (t != nullptr)
		t->height = std::max(height(t->left), height(t->right)) + 1;
}

template<typename T>
void AvlTree<T>::remove(const T &x)
{
	remove(x, root);
}

#endif // ! AVLTREE_H