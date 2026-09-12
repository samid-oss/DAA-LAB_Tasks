#include <stdio.h>

#define MAX 8

void add(int A[MAX][MAX], int B[MAX][MAX],
         int C[MAX][MAX], int n) {
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            C[i][j] = A[i][j] + B[i][j];
}

void subtract(int A[MAX][MAX], int B[MAX][MAX],
              int C[MAX][MAX], int n) {
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            C[i][j] = A[i][j] - B[i][j];
}

void strassen(int A[MAX][MAX], int B[MAX][MAX],
              int C[MAX][MAX], int n) {

    if (n == 1) {
        C[0][0] = A[0][0] * B[0][0];
        return;
    }

    int k = n / 2;

    int A11[MAX][MAX] = {0};
    int A12[MAX][MAX] = {0};
    int A21[MAX][MAX] = {0};
    int A22[MAX][MAX] = {0};

    int B11[MAX][MAX] = {0};
    int B12[MAX][MAX] = {0};
    int B21[MAX][MAX] = {0};
    int B22[MAX][MAX] = {0};

    int M1[MAX][MAX] = {0};
    int M2[MAX][MAX] = {0};
    int M3[MAX][MAX] = {0};
    int M4[MAX][MAX] = {0};
    int M5[MAX][MAX] = {0};
    int M6[MAX][MAX] = {0};
    int M7[MAX][MAX] = {0};

    int T1[MAX][MAX] = {0};
    int T2[MAX][MAX] = {0};

    for (int i = 0; i < k; i++) {
        for (int j = 0; j < k; j++) {

            A11[i][j] = A[i][j];
            A12[i][j] = A[i][j + k];
            A21[i][j] = A[i + k][j];
            A22[i][j] = A[i + k][j + k];

            B11[i][j] = B[i][j];
            B12[i][j] = B[i][j + k];
            B21[i][j] = B[i + k][j];
            B22[i][j] = B[i + k][j + k];
        }
    }

    add(A11, A22, T1, k);
    add(B11, B22, T2, k);
    strassen(T1, T2, M1, k);

    add(A21, A22, T1, k);
    strassen(T1, B11, M2, k);

    subtract(B12, B22, T2, k);
    strassen(A11, T2, M3, k);

    subtract(B21, B11, T2, k);
    strassen(A22, T2, M4, k);

    add(A11, A12, T1, k);
    strassen(T1, B22, M5, k);

    subtract(A21, A11, T1, k);
    add(B11, B12, T2, k);
    strassen(T1, T2, M6, k);

    subtract(A12, A22, T1, k);
    add(B21, B22, T2, k);
    strassen(T1, T2, M7, k);

    for (int i = 0; i < k; i++) {
        for (int j = 0; j < k; j++) {

            C[i][j] =
                M1[i][j] + M4[i][j] - M5[i][j] + M7[i][j];

            C[i][j + k] =
                M3[i][j] + M5[i][j];

            C[i + k][j] =
                M2[i][j] + M4[i][j];

            C[i + k][j + k] =
                M1[i][j] - M2[i][j] + M3[i][j] + M6[i][j];
        }
    }
}

int main() {

    int A[MAX][MAX] = {
        {1, 2},
        {3, 4}
    };

    int B[MAX][MAX] = {
        {5, 6},
        {7, 8}
    };

    int C[MAX][MAX] = {0};

    strassen(A, B, C, 2);

    printf("Result Matrix:\n");

    for (int i = 0; i < 2; i++) {
        for (int j = 0; j < 2; j++)
            printf("%d ", C[i][j]);

        printf("\n");
    }

    return 0;
}
