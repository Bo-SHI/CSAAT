#ifndef __SIMPLEDATASTRUCTURES_CHAPTER_8__
#define __SIMPLEDATASTRUCTURES_CHAPTER_8__


namespace SimpleDataStructures
{
/* 顺序查找 a为数组 n为数组的元素个数 key为要超找的值*/
int Sequential_Search(int* a, int n, int key);

/* 折半查找(二分查找) a为有序数组 n为数组的元素个数 key为要超找的值 */
int Binary_Search(int* a, int n, int key);

/* 插值查找 a为有序数组 n为数组的元素个数 key为要超找的值 */
int Interpolation_Search(int* a, int n, int key);

}

#endif