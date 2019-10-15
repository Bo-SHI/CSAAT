#include <stdio.h>

#include "search.h"

const int MAX_SIZE = 100;

int main(int argc, char *argv[]) {
    int arr[100];
    for (int i = 0; i < MAX_SIZE; ++i) {
        arr[i] = 2 * i + 1;
    }

    int k = binary_search(arr, 0, MAX_SIZE-1, 1);
    printf("%d\n", k);

    return 0;
}
