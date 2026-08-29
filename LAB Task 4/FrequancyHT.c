#include <stdio.h>

#define SIZE 100

int hashTable[SIZE];

int main() {
    int n, i, value;

    for (i = 0; i < SIZE; i++)
        hashTable[i] = 0;

    printf("Enter number of elements: ");
    scanf("%d", &n);

    printf("Enter elements:\n");

    for (i = 0; i < n; i++) {
        scanf("%d", &value);

        if (value >= 0 && value < SIZE)
            hashTable[value]++;
    }

    printf("\nFrequency:\n");

    for (i = 0; i < SIZE; i++) {
        if (hashTable[i] > 0)
            printf("%d : %d\n", i, hashTable[i]);
    }

    return 0;
}
