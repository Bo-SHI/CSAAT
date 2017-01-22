#include <iostream>
#include <exercise6.h>

namespace SwordOffer
{

BinaryNodeInt* Construct( int* preOrder, int* inOrder, int length )
{
	if(NULL == preOrder || NULL == inOrder || length <= 0) {
		return NULL;
	}

	return ConstructCore(preOrder, preOrder + length - 1, inOrder, inOrder + length - 1);
}

BinaryNodeInt* ConstructCore( int* startPreOrder, int* endPreOrder, int* startInOrder, int* endInOrder )
{
// 	if(NULL == startPreOrder || NULL == endPreOrder || NULL == startInOrder || NULL == endInOrder) {
// 		throw std::exception("Invalid Input");
// 	}

	// ǰ����� ��һ��ֵ�Ǹ��ڵ��ֵ
	int root = *startPreOrder;
	BinaryNodeInt* rootNode = new BinaryNodeInt;
	if(NULL == rootNode) {
		throw std::exception("new node invalid");
	}

	rootNode->t = root;
	rootNode->left = NULL;
	rootNode->right = NULL;

	if(startPreOrder == endPreOrder) {
		if(startInOrder == endInOrder && *startPreOrder == *startInOrder) {
			return rootNode;
		} else {
			throw std::exception("Invalid Input");
		}
	}

	// ������� �ҵ����ڵ��ֵ
	int* rootInOrder = startInOrder;
	while(*rootInOrder != root) {
		++rootInOrder;
	}

	if(rootInOrder == endInOrder && *rootInOrder != root) {
		throw std::exception("Invalid Input");
	}

	int leftLength = rootInOrder - startInOrder;
	int* leftPreOrderEnd = startPreOrder + leftLength;
	if(leftLength > 0) {
		// ����������
		rootNode->left = ConstructCore(startPreOrder + 1, leftPreOrderEnd, startInOrder, rootInOrder - 1);
	}
	
	if(leftLength < endPreOrder - startPreOrder) {
		// ����������
		rootNode->right = ConstructCore(leftPreOrderEnd + 1, endPreOrder, rootInOrder + 1, endInOrder);
	}

	return rootNode;

}

}

