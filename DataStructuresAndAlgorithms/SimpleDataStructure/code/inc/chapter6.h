#ifndef __SIMPLEDATASTRUCTURES_CHAPTER_6__
#define __SIMPLEDATASTRUCTURES_CHAPTER_6__

#include <baseDef.h>

namespace SimpleDataStructures
{

bool CreateBinarySortTree();

bool ClearBinarySortTree();

// ǰ�����
void PreOrderTraverse(BinaryNode* node);
// �������
void InOrderTraverse(BinaryNode* node);
// �������
void PostOrderTraverse(BinaryNode* node);
}

#endif