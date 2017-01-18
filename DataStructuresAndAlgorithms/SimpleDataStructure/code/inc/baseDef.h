#ifndef __SIMPLEDATASTRUCTURES_BASE_DEF__
#define __SIMPLEDATASTRUCTURES_BASE_DEF__


namespace SimpleDataStructures
{

struct BinaryNode
{
	int value;
	BinaryNode* left;
	BinaryNode* right;

	BinaryNode(int _val) : value(_val), left(NULL), right(NULL) {}
};

}

#endif