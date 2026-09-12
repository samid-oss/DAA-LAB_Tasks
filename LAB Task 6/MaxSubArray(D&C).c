#include <stdio.h>

int max(int a, int b) {
    return (a > b) ? a : b;
}

int maxCrossingSum(int arr[], int low, int mid, int high) {
    int leftSum = -1000000;
    int sum = 0;

    for (int i = mid; i >= low; i--) {
        sum += arr[i];

        if (sum > leftSum)
            leftSum = sum;
    }

    int rightSum = -1000000;
    sum = 0;

    for (int i = mid + 1; i <= high; i++) {
        sum += arr[i];

        if (sum > rightSum)
            rightSum = sum;
    }

    return leftSum + rightSum;
}

int maxSubarraySum(int arr[], int low, int high) {
    if (low == high)
        return arr[low];

    int mid = (low + high) / 2;

    int left = maxSubarraySum(arr, low, mid);
    int right = maxSubarraySum(arr, mid + 1, high);
    int cross = maxCrossingSum(arr, low, mid, high);

    return max(max(left, right), cross);
}

int main() {
    int arr[] = {-2, 1, -3, 4, -1, 2, 1, -5, 4};
    int n = sizeof(arr) / sizeof(arr[0]);

    int result = maxSubarraySum(arr, 0, n - 1);

    printf("Maximum Subarray Sum = %d\n", result);

    return 0;
}
