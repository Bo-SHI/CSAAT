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

}