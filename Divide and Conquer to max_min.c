#include <stdio.h>

struct MinMax {
    int min;
    int max;
};

struct MinMax findMinMax(int arr[], int left, int right) {
    struct MinMax result, leftMinMax, rightMinMax;
    int mid;

    // If there's only one element in the subarray
    if (left == right) {
        result.min = arr[left];
        result.max = arr[right];
        return result;
    }

    // If there are two elements in the subarray
    if (right - left == 1) {
        if (arr[left] < arr[right]) {
            result.min = arr[left];
            result.max = arr[right];
        } else {
            result.min = arr[right];
            result.max = arr[left];
        }
        return result;
    }

    // Divide the array into two halves
    mid = (left + right) / 2;

    // Recursively find the minimum and maximum in the left and right halves
    leftMinMax = findMinMax(arr, left, mid);
    rightMinMax = findMinMax(arr, mid + 1, right);

    // Compare the minimum and maximum from both halves
    if (leftMinMax.min < rightMinMax.min) {
        result.min = leftMinMax.min;
    } else {
        result.min = rightMinMax.min;
    }

    if (leftMinMax.max > rightMinMax.max) {
        result.max = leftMinMax.max;
    } else {
        result.max = rightMinMax.max;
    }

    return result;
}

int main() {
    int arr[] = {3, 7, 1, 9, 4, 6, 8, 2};
    int arr_size = sizeof(arr) / sizeof(arr[0]);

    struct MinMax result = findMinMax(arr, 0, arr_size - 1);

    printf("Minimum value: %d\n", result.min);
    printf("Maximum value: %d\n", result.max);

    return 0;
}
