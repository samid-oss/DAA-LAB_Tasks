#include <stdio.h>

#define SIZE 10

int hashTable[SIZE];

void insert(int key) {
    int index = key % SIZE;
    int i = 0;
    int newIndex;

    while (i < SIZE) {
        newIndex = (index + i * i) % SIZE;

        if (hashTable[newIndex] == -1) {
            hashTable[newIndex] = key;
            return;
        }

        i++;
    }

    printf("Hash table is full\n");
}

void display() {
    int i;

    for (i = 0; i < SIZE; i++) {
        printf("%d : %d\n", i, hashTable[i]);
    }
}

int main() {
    int n, key, i;

    for (i = 0; i < SIZE; i++)
        hashTable[i] = -1;

    printf("Enter number of elements: ");
    scanf("%d", &n);

    printf("Enter elements:\n");

    for (i = 0; i < n; i++) {
        scanf("%d", &key);
        insert(key);
    }

    printf("\nHash Table:\n");
    display();

    return 0;
}
