#ifndef __SIMPLEDATASTRUCTURES_CHAPTER_6__
#define __SIMPLEDATASTRUCTURES_CHAPTER_6__

#include <baseDef.h>

namespace SimpleDataStructures
{

bool CreateBinarySortTree();

bool ClearBinarySortTree();

// 前序遍历
void PreOrderTraverse(BinaryNode* node);
// 中序遍历
void InOrderTraverse(BinaryNode* node);
// 后序遍历
void PostOrderTraverse(BinaryNode* node);
}

#endif