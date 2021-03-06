#include"BinarySearchTree.h"


void BinarySearchTree_test()
{
	BinarySearchTree<int> bst;
	for (int i = 0;i < 10;i++)
	{
		bst.insert(i);
	}
	bst.insert(-1);
	std::cout << "inorder print: ";
	bst.printTree();
	std::cout << std::endl << "preorder print: ";
	bst.preorderPrintTree();
	std::cout << std::endl << "postorder print:";
	bst.postorderPrintTree();
	std::cout << std::endl;

	std::cout << "Max:" << bst.findMax() << std::endl;
	std::cout << "Min" << bst.findMin() << std::endl;

	if (bst.contains(6))
		std::cout << "contain" << std::endl;
	else
		std::cout << "not contain" << std::endl;

	BinarySearchTree<int> T_copy = bst;
	std::cout << "copy: ";
	T_copy.printTree();
	std::cout << std::endl;

	bst.remove(3);
	std::cout << "after delete: ";
	bst.printTree();
	std::cout << std::endl;

	if (bst.isEmpty())
		std::cout << "Empty" << std::endl;
	else
		std::cout << "not Empty" << std::endl;
}