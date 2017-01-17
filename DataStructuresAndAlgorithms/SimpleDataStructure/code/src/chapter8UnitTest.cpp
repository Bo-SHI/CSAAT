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
	binarySortTree->add(5);
	binarySortTree->add(6);
	binarySortTree->add(7);
	binarySortTree->add(3);
	binarySortTree->add(1);

	SimpleDataStructures::BinaryNode* objNode = NULL;
	SimpleDataStructures::BinaryNode* objParentNode = NULL;
	binarySortTree->find(1, &objParentNode, &objNode);

	int a = 1;

}

}