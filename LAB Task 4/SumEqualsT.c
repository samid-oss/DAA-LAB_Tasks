#include <stdio.h>

#define SIZE 100

int hashTable[SIZE];

int main() {
    int n, T, i, value, complement;
    int found = 0;

    for (i = 0; i < SIZE; i++)
        hashTable[i] = 0;

    printf("Enter number of elements: ");
    scanf("%d", &n);

    int arr[n];

    printf("Enter elements:\n");

    for (i = 0; i < n; i++)
        scanf("%d", &arr[i]);

    printf("Enter target T: ");
    scanf("%d", &T);

    for (i = 0; i < n; i++) {
        value = arr[i];
        complement = T - value;

        if (complement >= 0 && complement < SIZE &&
            hashTable[complement] == 1) {
            found = 1;
            break;
        }

        if (value >= 0 && value < SIZE)
            hashTable[value] = 1;
    }

    if (found)
        printf("Pair exists\n");
    else
        printf("Pair does not exist\n");

    return 0;
}
