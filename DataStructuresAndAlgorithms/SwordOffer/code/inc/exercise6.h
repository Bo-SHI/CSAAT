#ifndef __SWORD_OFFER_EXERCISE_6__
#define __SWORD_OFFER_EXERCISE_6__

#include <baseDefSO.h>

namespace SwordOffer
{
/*
** ����ĳ��������ǰ���������������Ľ�����ؽ�������
** ���� ǰ���������������в����ظ�����
** ���� ǰ����� {1,2,4,7,3,5,6,8}; ������� {4,7,2,1,5,3,8,6}
*/

	// NOTE:�˺�����������ʵ�����õ��У��ڴ��й©
BinaryNodeInt* Construct(int* preOrder, int* inOrder, int length);


BinaryNodeInt* ConstructCore(int* startPreOrder, int* endPreOrder, int* startInOrder, int* endInOrder);

}

#endif