#include <iostream>
#include <chapter6.h>
#include <chapter8.h>

SimpleDataStructures::BinarySortTree* binarySortTree = NULL;

namespace SimpleDataStructures
{

bool CreateBinarySortTree()
{
	binarySortTree = new BinarySortTree;
	if(NULL == binarySortTree) {
		return false;
	}

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

	return true;
}

bool ClearBinarySortTree()
{
	if(!binarySortTree) {
		return true;
	}

	delete binarySortTree;
	binarySortTree = NULL;
	return true;
}

void PreOrderTraverse( BinaryNode* node )
{
	if(NULL == node) {
		return ;
	}

	std::cout << node->value << " ";
	PreOrderTraverse(node->left);
	PreOrderTraverse(node->right);
}

void InOrderTraverse( BinaryNode* node )
{
	if(NULL == node) {
		return;
	}

	PreOrderTraverse(node->left);
	std::cout << node->value << " ";
	PreOrderTraverse(node->right);
}

void PostOrderTraverse( BinaryNode* node )
{
	if(NULL == node) {
		return;
	}

	PreOrderTraverse(node->left);
	PreOrderTraverse(node->right);
	std::cout << node->value << " ";
}

}