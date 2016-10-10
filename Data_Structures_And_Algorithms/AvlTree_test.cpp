#include"AvlTree.h"

void AvlTree_test()
{
	AvlTree<int> avl;
	for (int i = 0;i < 15;i++)
	{
		avl.insert(i);
	}
	avl.printTree();
	std::cout << std::endl;
	avl.preorderPrintTree();
	std::cout << std::endl;
	avl.postorderPrintTree();
	std::cout << std::endl;
	std::cout << "tree height: " << avl.height() << std::endl;

	/*std::cout << "Max: " << avl.findMax() << std::endl;
	std::cout << "Min: " << avl.findMin() << std::endl;

	if(avl.contains(6))
		std::cout << "contain" << std::endl;
	else
		std::cout << "not contain" << std::endl;

	AvlTree<int> AvlT_copy = avl;
	std::cout << "copy:";
	AvlT_copy.printTree();
	std::cout << std::endl;

	avl.remove(3);
	avl.printTree();
	std::cout << std::endl;
	std::cout << "tree height: " << avl.height() << std::endl;

	if (avl.isEmpty())
		std::cout << "Empty" << std::endl;
	else
		std::cout << "not Empty" << std::endl;*/
}