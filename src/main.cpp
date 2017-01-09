#include <iostream>
#include <chapter8.h>

using namespace std;

int main()
{
	int arr[] = {1, 2, 3, 4, 5, 6};
	int res = SimpleDataStructures::Sequential_Search(arr, 6, 4);

	std::cout << res << std::endl;
	return 0;
}