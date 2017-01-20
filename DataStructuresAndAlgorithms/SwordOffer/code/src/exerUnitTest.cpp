#include <iostream>
#include <exerUnitTest.h>

namespace SwordOfferUnitTest
{
	
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
