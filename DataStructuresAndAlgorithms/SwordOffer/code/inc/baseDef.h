#ifndef __SWORD_BASE_DEF__
#define __SWORD_BASE_DEF__


namespace SWORD_OFFER
{
	template <typename T>
	struct BinaryNode
	{
		T t;
		BinaryNode* left;
		BinaryNode* right;
	};
}

#endif