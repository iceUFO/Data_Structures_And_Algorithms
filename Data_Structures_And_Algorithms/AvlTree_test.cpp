#include"AvlTree.h"

void AvlTree_test()
{
	AvlTree<int> avl;
	for (int i = 0;i < 10;i++)
	{
		avl.insert(i);
	}
	avl.insert(-1);
	avl.printTree();
	std::cout << std::endl;
	
}