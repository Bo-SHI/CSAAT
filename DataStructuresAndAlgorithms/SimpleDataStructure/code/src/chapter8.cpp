#include <iostream>
#include <chapter8.h>

namespace SimpleDataStructures
{
	
int Sequential_Search(int* a, int n, int key)
{
	if(NULL == a) {
		return 0;
	}
	
	for(int i = 0; i < n; ++i) {
		if(*(a+i) == key) {
			return i + 1;
		}
	}
	
	return 0;
}

int Binary_Search( int* a, int n, int key )
{
	if(NULL == a) {
		return 0;
	}

	int low = 1;
	int high = n;

	while(low <= high) {
		int mid = (high + low) / 2;

		if(key < *(a+mid - 1)) {
			high = mid - 1;
		} else if(key > *(a+mid - 1)) {
			low = mid + 1;
		} else {
			return mid;
		}
	}

	return 0;
}

int Interpolation_Search( int* a, int n, int key )
{
	if(NULL == a) {
		return 0;
	}

	int low = 1;
	int high = n;

	for(low <= high) {
		int mid = low + (key - *(a + low - 1)) / (*(a + high - 1) - *(a + low - 1)) * (high - low);

		if(key < *(a + mid - 1)) {
			high = mid - 1;
		} else if(key > *(a + mid - 1)) {
			low = mid + 1;
		} else {
			return mid;
		}
	}

	return 0;
}

}