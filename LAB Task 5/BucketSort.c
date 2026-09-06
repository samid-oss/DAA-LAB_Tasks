#include <stdio.h>

int main() {
    int n;

    printf("Enter number of elements: ");
    scanf("%d", &n);

    float arr[n];
    float bucket[n][n];
    int count[n];

    // Initialize bucket counts
    for (int i = 0; i < n; i++) {
        count[i] = 0;
    }

    // Input elements
    printf("Enter elements between 0 and 1:\n");

    for (int i = 0; i < n; i++) {
        scanf("%f", &arr[i]);
    }

    // Step 1: Put elements into buckets
    for (int i = 0; i < n; i++) {
        int index = (int)(arr[i] * n);

        bucket[index][count[index]] = arr[i];
        count[index]++;
    }

    // Step 2: Sort each bucket
    for (int i = 0; i < n; i++) {

        for (int j = 0; j < count[i] - 1; j++) {

            for (int k = 0; k < count[i] - j - 1; k++) {

                if (bucket[i][k] > bucket[i][k + 1]) {

                    float temp = bucket[i][k];
                    bucket[i][k] = bucket[i][k + 1];
                    bucket[i][k + 1] = temp;
                }
            }
        }
    }

    // Step 3: Combine buckets
    int index = 0;

    for (int i = 0; i < n; i++) {

        for (int j = 0; j < count[i]; j++) {
            arr[index] = bucket[i][j];
            index++;
        }
    }

    // Display sorted array
    printf("Sorted array:\n");

    for (int i = 0; i < n; i++) {
        printf("%.2f ", arr[i]);
    }

    return 0;
}
