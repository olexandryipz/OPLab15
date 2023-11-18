#include <stdio.h>
#include <math.h>
#include <Windows.h>
#include <stdlib.h>
#include <time.h>

void Array(int arr[], int size) {
    for (int i = 0; i < size; i++)
        printf("%d ", arr[i]);
    printf("\n");
}

void bubbleSort(int arr[], int n) {
    for (int i = 0; i < n - 1; i++)
        for (int j = 0; j < n - i - 1; j++)
            if (arr[j] < arr[j + 1]) {
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
}

void sortDiagonal(int mat[][100], int n) {
    int diagonal[1000];
    int index = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (i == j)
                diagonal[index++] = mat[i][j];
        }
    }
    bubbleSort(diagonal, index);
    index = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (i == j)
                mat[i][j] = diagonal[index++];
        }
    }
}

int main() {
    int n;
    printf("Введіть розмір квадратної матриці: ");
    scanf_s("%d", &n);
    int mat[100][100];
    printf("Введіть елементи квадратної матриці: \n");
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            scanf_s("%d", &mat[i][j]);
    sortDiagonal(mat, n);
    printf("Квадратна матриця після сортування за умовами:\n");
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++)
            printf("%d ", mat[i][j]);
        printf("\n");
    }
    return 0;
}