#ifndef __SIMPLEDATASTRUCTURES_CHAPTER_8_UNIT_TEST__
#define __SIMPLEDATASTRUCTURES_CHAPTER_8_UNIT_TEST__

#include <chapter8.h>

static int arr_unorder[] = {10,2,3,0,5,6,13,21};
static int arr_order[] = {1,2,3,4,5,6};
static int arr_one[] = {5};

namespace SimpleDataStructuresTest
{
	struct Chapter8UnitTest
	{
		// test Squential Search
		static void Sequential_Search_Unit_Test();
		// test Binary Search
		static void Binary_Search_Unit_test();
		// test Binary Sort Tree
		static void Binary_Sort_Tree_Unit_Test();
	};
}

#endif