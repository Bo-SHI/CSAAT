#include <iostream>

#include <baseDefSO.h>
#include <exerUnitTest.h>

namespace SwordOfferUnitTest
{

void ConstructBinaryTree_Unit_Test()
{
	int preOrder[] = {1,2,4,7,3,5,6,8};
	int inOrder[] = {4,7,2,1,5,3,8,6};
	SwordOffer::Construct(preOrder, inOrder, 8);
}

void VerifySequenceOfBST_Unit_Test()
{
	int arr_0[] = {5,7,6,9,11,10,8};
	int arr_1[] = {7,4,6,5};

	std::cout << "数组:\n";
	for(int i = 0; i < 7; ++i) {
		std::cout << *(arr_0 + i) << " ";
	}

	if(SwordOffer::VerifySequenceOfBST(arr_0, 7)) {
		std::cout << " is a Binary Sort Tree PostOrderTraverse.\n";
	} else {
		std::cout << " is not a Binary Sort Tree PostOrderTraverse.\n";
	}

	std::cout << "数组:\n";
	for(int i = 0; i < 4; ++i) {
		std::cout << *(arr_1 + i) << " ";
	}
	if(SwordOffer::VerifySequenceOfBST(arr_1, 4)) {
		std::cout << " is a Binary Sort Tree PostOrderTraverse.\n";
	} else {
		std::cout << " is not a Binary Sort Tree PostOrderTraverse.\n";
	}

}

}
