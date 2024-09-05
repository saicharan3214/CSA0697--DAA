#include <stdio.h>

int binarySearch(int arr[], int size, int key) {
    int low = 0, high = size - 1;

    while (low <= high) {
        int mid = (low + high) / 2;
        if (arr[mid] == key) {
            return mid;
        } else if (arr[mid] < key) {
            low = mid + 1;
        } else {
            high = mid - 1;
        }
    }
    return -1; // Key not found
}

int main() {
    int arr[] = {2, 4, 7, 10, 14, 18, 21};
    int size = sizeof(arr) / sizeof(arr[0]);
    int key;

    printf("Enter the key to search: ");
    scanf("%d", &key);

    int result = binarySearch(arr, size, key);
    if (result != -1) {
        printf("Element found at index %d.\n", result);
    } else {
        printf("Element not found.\n");
    }

    return 0;
}

