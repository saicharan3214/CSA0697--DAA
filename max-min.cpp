#include <stdio.h>
#include <limits.h>

struct Result {
    int max;
    int min;
};

struct Result findMaxMin(int arr[], int low, int high) {
    struct Result result;

    if (low == high) {
        result.max = arr[low];
        result.min = arr[low];
        return result;
    }

    if (high == low + 1) {
        result.max = arr[low] > arr[high] ? arr[low] : arr[high];
        result.min = arr[low] < arr[high] ? arr[low] : arr[high];
        return result;
    }

    int mid = (low + high) / 2;
    struct Result left = findMaxMin(arr, low, mid);
    struct Result right = findMaxMin(arr, mid + 1, high);

    result.max = left.max > right.max ? left.max : right.max;
    result.min = left.min < right.min ? left.min : right.min;
    return result;
}

int main() {
    int arr[] = {3, 5, 1, 8, 9, 2, 10};
    int n = sizeof(arr) / sizeof(arr[0]);
    struct Result result = findMaxMin(arr, 0, n - 1);
    printf("Max: %d\nMin: %d\n", result.max, result.min);
    return 0;
}

