#ifndef __SIMPLEDATASTRUCTURES_CHAPTER_8__
#define __SIMPLEDATASTRUCTURES_CHAPTER_8__


namespace SimpleDataStructures
{
/* ˳����� aΪ���� nΪ�����Ԫ�ظ��� keyΪҪ���ҵ�ֵ*/
int Sequential_Search(int* a, int n, int key);

/* �۰����(���ֲ���) aΪ�������� nΪ�����Ԫ�ظ��� keyΪҪ���ҵ�ֵ */
int Binary_Search(int* a, int n, int key);

/* ��ֵ���� aΪ�������� nΪ�����Ԫ�ظ��� keyΪҪ���ҵ�ֵ */
int Interpolation_Search(int* a, int n, int key);

/* ���������� */
struct BinaryNode
{
	int value;
	BinaryNode* left;
	BinaryNode* right;

	BinaryNode(int _val) : value(_val), left(NULL), right(NULL) {}
};

class BinarySortTree
{
public:
	BinarySortTree() : root (NULL) {}
	~BinarySortTree();

	//{{ ��ʱ�ӿ� ����
	bool add(int _val);
	bool del(int _val);
	bool search(int _val);
	//}}

	// _val<==>ֵ _objParentNode<==>˫�׽ڵ� _objNode<==>Ŀ��ڵ�
	// ����ֵΪ _val ��Ŀ��ڵ��Լ�˫�׽ڵ�
	// ָ����Ϊ�β� ʵ����Ҳ��ֵ���� Ҫ��ı�ָ��ʵ�� ����ָ���ָ��
	bool find(int _val, BinaryNode** _objParentNode = NULL, BinaryNode** _objNode = NULL);

	// �����µĽڵ� ���Ѵ���ֵΪ_val�Ľڵ� ����ʧ��
	bool insert(int _val);
	
	// �ڴ��ͷ�
	bool clear();

private:
	//{{ ��ʱ�ӿ� ����
	bool _search(BinaryNode* node, int _val);
	BinaryNode* _searchParentNode(BinaryNode* parentNode, int _val);
	//}

	bool _clear(BinaryNode* node);

	bool _find(BinaryNode* _node, int _val, BinaryNode** _objParentNode, BinaryNode** _objNode);

private:
	BinaryNode* root;
};

}

#endif