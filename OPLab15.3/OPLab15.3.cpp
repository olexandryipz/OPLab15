#include <stdio.h>
#include <math.h>
#include <Windows.h>
#include <stdlib.h>
#include <time.h>

void bubbleSort(double arr[], int n) {
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                double temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
}

void insertionSort(double arr[], int n) {
    int i, j;
    double key;
    for (i = 1; i < n; i++) {
        key = arr[i];
        j = i - 1;

        while (j >= 0 && arr[j] > key) {
            arr[j + 1] = arr[j];
            j = j - 1;
        }
        arr[j + 1] = key;
    }
}

int main() {
    int rows, cols;

    printf("Введіть кількість рядків матриці: ");
    scanf_s("%d", &rows);
    printf("Введіть кількість стовпців матриці: ");
    scanf_s("%d", &cols);

    double matrix[100][100];

    printf("Введіть елементи матриці:\n");
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            scanf_s("%lf", &matrix[i][j]);
        }
    }

    double Array[100];
    int k = 0;

    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            Array[k++] = matrix[i][j];
        }
    }

    bubbleSort(Array, rows * cols);

    k = 0;
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            matrix[i][j] = Array[k++];
        }
    }

    printf("Відсортована матриця:\n");
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            printf("%lf\t", matrix[i][j]);
        }
        printf("\n");
    }

    return 0;
}