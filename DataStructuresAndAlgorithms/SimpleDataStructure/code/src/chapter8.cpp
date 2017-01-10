#include <iostream>
#include <chapter8.h>

namespace SimpleDataStructures
{
	
int Sequential_Search(int* a, int n, int key)
{
	if(NULL == a) {
		return -1;
	}
	
	for(int i = 0; i < n; ++i) {
		if(*(a+i) == key) {
			return i;
		}
	}
	
	return -1;
}

int Binary_Search( int* a, int n, int key )
{
	if(NULL == a) {
		return -1;
	}
	
	if(n == 1) {
		if(key == *(a + 0)) {
			return 0;
		} else {
			return -1;
		}
	}

	int low = 0;
	int high = n - 1;

	while(low <= high) {
		int mid = (high + low) / 2;

		if(key < *(a+mid)) {
			high = mid - 1;
		} else if(key > *(a+mid)) {
			low = mid + 1;
		} else {
			return mid;
		}
	}

	return -1;
}

}