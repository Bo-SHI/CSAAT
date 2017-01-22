#ifndef __SWORD_OFFER_EXERCISE_6__
#define __SWORD_OFFER_EXERCISE_6__

#include <baseDefSO.h>

namespace SwordOffer
{
/*
** 输入某二叉树的前序遍历和中序遍历的结果，重建二叉树
** 假设 前序遍历和中序遍历中不含重复数字
** 假设 前序遍历 {1,2,4,7,3,5,6,8}; 中序遍历 {4,7,2,1,5,3,8,6}
*/

	// NOTE:此函数不能用于实际运用当中，内存会泄漏
BinaryNodeInt* Construct(int* preOrder, int* inOrder, int length);


BinaryNodeInt* ConstructCore(int* startPreOrder, int* endPreOrder, int* startInOrder, int* endInOrder);

}

#endif