#include <stdio.h>

// c 递归
static int binary_search_1(const int arr[], int start, int end, int khey) {
    if (start > end) {
        return -1;
    }

    int mid = start + (end - start) / 2; //防止溢出
    printf("k:%d, v : %d\n", mid, arr[mid]);
    if (arr[mid] > khey) {
        return binary_search_1(arr, start, mid - 1, khey);
    } else if (arr[mid] < khey) {
        return binary_search_1(arr, mid + 1, end, khey);
    } else {
        return mid;
    }
}

// c 循环/迭代
static int binary_search_2(const int arr[], int start, int end, int khey) {
    int ret = -1;
    while (start <= end) {
        int mid = start + (end - start) / 2; //防止溢出
        printf("k:%d, v : %d\n", mid, arr[mid]);
        if (arr[mid] > khey) {
            end = mid - 1;
        } else if (arr[mid] < khey) {
            start = mid + 1;
        } else {
            ret = mid;
            break;
        }
    }

    return ret;
}
// 二分查找
int binary_search(const int arr[], int start, int end, int khey) {
    return binary_search_2(arr, start, end, khey);
}
