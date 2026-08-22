#include <stdio.h>

#define MAX 100

int A[MAX], B[MAX], C[MAX];
int topA = -1, topB = -1, topC = -1;

void push(int rod[], int *top, int disk) {
    rod[++(*top)] = disk;
}

int pop(int rod[], int *top) {
    return rod[(*top)--];
}

int peek(int rod[], int *top) {
    if (*top == -1)
        return -1;

    return rod[*top];
}

void legalmove(int rod1[], int *top1, char name1,
               int rod2[], int *top2, char name2) {

    int disk1 = peek(rod1, top1);
    int disk2 = peek(rod2, top2);

    if (disk1 == -1 && disk2 == -1)
        return;

    else if (disk1 == -1) {
        push(rod1, top1, pop(rod2, top2));
        printf("Move disk %d from %c to %c\n",
               disk2, name2, name1);
    }

    else if (disk2 == -1) {
        push(rod2, top2, pop(rod1, top1));
        printf("Move disk %d from %c to %c\n",
               disk1, name1, name2);
    }

    else if (disk1 > disk2) {
        push(rod1, top1, pop(rod2, top2));
        printf("Move disk %d from %c to %c\n",
               disk2, name2, name1);
    }

    else {
        push(rod2, top2, pop(rod1, top1));
        printf("Move disk %d from %c to %c\n",
               disk1, name1, name2);
    }
}

void towerofhanoi(int n) {

    for (int i = n; i >= 1; i--) {
        push(A, &topA, i);
    }

    int totalmoves = (1 << n) - 1;

    for (int i = 1; i <= totalmoves; i++) {

        if (i % 3 == 1)
            legalmove(A, &topA, 'A', C, &topC, 'C');

        else if (i % 3 == 2)
            legalmove(A, &topA, 'A', B, &topB, 'B');

        else
            legalmove(B, &topB, 'B', C, &topC, 'C');
    }
}

int main() {

    int n;

    printf("Enter the number of disks: ");
    scanf("%d", &n);

    towerofhanoi(n);

    return 0;
}
