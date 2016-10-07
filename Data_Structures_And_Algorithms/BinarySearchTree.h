#pragma once
#ifndef BINARYSEARCHTREE_H
#define BINARYSEARCHTREE_H


template<typename Object, typename Comparator=less<Object>>
class BinarySearchTree
{
public:
	BinarySearchTree()=default;
	BinarySearchTree(const BinarySearchTree &rhs);
	~BinarySearchTree();

	const Object &findMin() const;
	const Object &findMax() const;
	bool contains(const Object &x) const;
	bool isEmpty() const;
	void printTree() const;

	void makeEmpty();
	void insert(const Obiect &x);
	void remove(const Object &x);

	const BinarySearchTree &opearator = (const BinarySearchTree &rhs);

private:
	struct BinaryNode
	{
		Object element;
		BinaryNode *left;
		BinaryNode *right;

		BinaryNode(const Object theElement, BinaryNode *lt, BinaryNode *rt)
			:element(theElement), left(lt), right(rt) {}
	};

	BinaryNode *root;
	Comparator isLessThan;

	void insert(const Object &x, BinaryNode *&t) const;
	void remove(const Object &x, BinaryNode *&t) const;

	BinaryNode *findMix(BinaryNode *t) const;
	BinaryNode *findMax(BinaryNode *t) const;

	void makeEmpty(BinaryNode *&t);
	void printTree(BinaryNode *t) const;
	BinaryNode *clone(BinaryNode *t) const;

	bool contains(const Object &x, BinaryNode *t) const;

};

template<typename Object, typename Comparator=less<Object>>
bool BinarySearchTree<Object>::contains(const Object &x, BinaryNode *t) const
{
	if (t == nullptr)
		return false;
	else if (isLessThan(x, t->element))
		return contains(x, t->left);
	else if (isLessThan(t->element, x))
		return contains(x, t->right);
	else
		return true;
}

template<typename Object, typename Comparator=less<Object>>
bool BinarySearchTree<Object>::contains(const Object &x) const
{
	return contains(x, root);
}

template<typename Object, typename Comparator=less<Object>>
BinaryNode *BinarySearchTree<Object>::findMin(BinaryNode *t) const
{
	if (t == nullptr)
		return nullptr;
	if (t->left == nullptr)
		return t;
	return findMin(t->left);
}

template<typename Object, typename Comparator = less<Object>>
const Object &BinarySearchTree<Object>::findMin() const
{
	return findMix(root);
}

template<typename Object, typename Comparator = less<Object>>
BinaryNode *BinarySearchTree<Object>::findMax(BinaryNode *t) const
{
	if (!t = nullptr)
		while (t->right != nullptr)
			t = t->right;
	return t;
}

template<typename Object, typename Comparator = less<Object>>
const Object &BinarySearchTree<Object>::findMax() const
{
	return findMax(root);
}

template<typename Object, typename Comparator = less<Object>>
void BinarySearchTree<Object>::insert(const Object &x, BinaryNode *&t) const
{
	if (t == nullptr)
		t = new BinaryNode(x, nullptr, nullptr);
	else if (x < t->element)
		insert(x, t->left);
	else if (t->element < x)
		insert(x, t->right);
	else
		return;                             //do nothing
}

template<typename Object, typename Comparator = less<Object>>
void BinarySearchTree<Object>::insert(const Obiect &x)
{
	insert(x, root);
}

template<typename Object, typename Comparator = less<Object>>
void BinarySearchTree<Object>::remove(const Object &x, BinaryNode *&t) const
{
	if (t == nullptr)
		return;
	else if (x < t->element)
		remove(x, t->left);
	else if (t->element < x)
		remove(x, t->right);
	else if (t->left != nullptr &&t->right != nullptr)
	{
		t->element = findMin(t->right)->element;
		remove(t->element, t->right);
	}
	else
	{
		BinaryNode *oldNode = t;
		t = (t->left != nullptr) ? t->left : t->right;
		delete oldNode;
	}
}
template<typename Object, typename Comparator = less<Object>>
void BinarySearchTree<Object>::remove(const Object &x)
{
	remove(x, root);
}

#endif // !BINARYSEARCHTREE_H