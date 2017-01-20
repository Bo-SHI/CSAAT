#include <iostream>
#include <exercise24.h>

namespace SwordOffer
{

bool VerifySequenceOfBST( int* _arr, int count )
{
	if(NULL == _arr || count <= 0) {
		return false;
	}

	int root = *(_arr + count - 1);

	int leftCount = 0;
	while(*(_arr+leftCount) < root) {
		++leftCount;
	}

	int rightCount = count - leftCount - 1;
	for(int i = leftCount; i < count - 1; ++i) {
		if(*(_arr + i) < root) {
			return false;
		}
	}

	bool leftRes = true;
	if(rightCount > 0) {
		leftRes = VerifySequenceOfBST(_arr, leftCount);
	}

	bool rightRes = true;
	if(rightCount > 0) {
		rightRes = VerifySequenceOfBST(_arr + leftCount, rightCount);
	}

	return leftRes && rightRes;
}

}

