#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <Windows.h>
#include <time.h>

int sumOfNegativeElements(int matrix[][100], int rows, int col) {
    int sum = 0;
    for (int i = 0; i < rows; i++) {
        if (matrix[i][col] < 0 && matrix[i][col] % 2 != 0) {
            sum += abs(matrix[i][col]);
        }
    }
    return sum;
}

void swapColumns(int matrix[][100], int rows, int col1, int col2) {
    for (int i = 0; i < rows; i++) {
        int temp = matrix[i][col1];
        matrix[i][col1] = matrix[i][col2];
        matrix[i][col2] = temp;
    }
}

int main() {
    int rows, cols;

    printf("Введіть кількість рядків матриці: ");
    scanf_s("%d", &rows);
    printf("Введіть кількість стовпців матриці: ");
    scanf_s("%d", &cols);

    int matrix[100][100];

    printf("Введіть елементи матриці:\n");
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            scanf_s("%d", &matrix[i][j]);
        }
    }

    for (int i = 0; i < cols - 1; i++) {
        for (int j = 0; j < cols - i - 1; j++) {
            if (sumOfNegativeElements(matrix, rows, j) < sumOfNegativeElements(matrix, rows, j + 1)) {
                swapColumns(matrix, rows, j, j + 1);
            }
        }
    }

    printf("Відредагована матриця:\n");
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            printf("%d\t", matrix[i][j]);
        }
        printf("\n");
    }

    return 0;
}
