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

}