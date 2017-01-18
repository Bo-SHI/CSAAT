#include <iostream>
#include <chapter6UnitTest.h>
#include <chapter8.h>

extern SimpleDataStructures::BinarySortTree* binarySortTree;

namespace SimpleDataStructuresTest
{

bool Chapter6UnitTest::ready()
{
	return SimpleDataStructures::CreateBinarySortTree();
}

bool Chapter6UnitTest::close()
{
	return SimpleDataStructures::ClearBinarySortTree();
}

void Chapter6UnitTest::PreOrderTraverse_Unit_Test()
{
	ready();

	if(NULL == binarySortTree) {
   		return ;
   	}
 
	SimpleDataStructures::PreOrderTraverse(binarySortTree->getRootNode());

	close();
}

}