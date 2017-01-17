#include <iostream>
#include <chapter8UnitTest.h>

namespace SimpleDataStructuresTest
{

void Chapter8UnitTest::Sequential_Search_Unit_Test()
{
	int res = SimpleDataStructures::Sequential_Search(arr_unorder, sizeof(arr_unorder)/sizeof(int), 2);	
	std::cout << res << std::endl;
}

void Chapter8UnitTest::Binary_Search_Unit_test()
{
	int res = SimpleDataStructures::Binary_Search(arr_order, sizeof(arr_order)/sizeof(int), 3);
	std::cout << res << std::endl;
}

void Chapter8UnitTest::Binary_Sort_Tree_Unit_Test()
{
	SimpleDataStructures::BinarySortTree* binarySortTree = new SimpleDataStructures::BinarySortTree;
	binarySortTree->insert(62);
	binarySortTree->insert(58);
	binarySortTree->insert(88);
	binarySortTree->insert(47);
	binarySortTree->insert(73);
	binarySortTree->insert(99);
	binarySortTree->insert(35);
	binarySortTree->insert(51);
	binarySortTree->insert(93);
	binarySortTree->insert(29);
	binarySortTree->insert(37);
	binarySortTree->insert(49);
	binarySortTree->insert(56);
	binarySortTree->insert(36);
	binarySortTree->insert(48);
	binarySortTree->insert(50);

	SimpleDataStructures::BinaryNode* objNode = NULL;
	SimpleDataStructures::BinaryNode* objParentNode = NULL;

	binarySortTree->find(1, &objParentNode, &objNode);

	binarySortTree->del(47);

	delete binarySortTree;
	binarySortTree = NULL;
}

}