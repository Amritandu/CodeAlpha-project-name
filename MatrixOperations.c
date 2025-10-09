#include <stdio.h>

#define MAX 10   // maximum matrix size

// Function prototypes
void inputMatrix(int matrix[MAX][MAX], int rows, int cols);
void displayMatrix(int matrix[MAX][MAX], int rows, int cols);
void addMatrix(int A[MAX][MAX], int B[MAX][MAX], int result[MAX][MAX], int rows, int cols);
void multiplyMatrix(int A[MAX][MAX], int B[MAX][MAX], int result[MAX][MAX], int r1, int c1, int c2);
void transposeMatrix(int A[MAX][MAX], int result[MAX][MAX], int rows, int cols);

int main() {
    int choice;
    int A[MAX][MAX], B[MAX][MAX], result[MAX][MAX];
    int r1, c1, r2, c2;

    while (1) {
        printf("\nMatrix Operations Menu\n");
        printf("----------------------\n");
        printf("1. Matrix Addition\n");
        printf("2. Matrix Multiplication\n");
        printf("3. Matrix Transpose\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("\nEnter rows and columns of matrices: ");
                scanf("%d%d", &r1, &c1);

                printf("Enter elements of Matrix A:\n");
                inputMatrix(A, r1, c1);

                printf("Enter elements of Matrix B:\n");
                inputMatrix(B, r1, c1);

                addMatrix(A, B, result, r1, c1);
                printf("\nResult of Matrix Addition:\n");
                displayMatrix(result, r1, c1);
                break;

            case 2:
                printf("\nEnter rows and columns of Matrix A: ");
                scanf("%d%d", &r1, &c1);
                printf("Enter rows and columns of Matrix B: ");
                scanf("%d%d", &r2, &c2);

                if (c1 != r2) {
                    printf("Error: Matrix multiplication not possible (c1 != r2)\n");
                    break;
                }

                printf("Enter elements of Matrix A:\n");
                inputMatrix(A, r1, c1);

                printf("Enter elements of Matrix B:\n");
                inputMatrix(B, r2, c2);

                multiplyMatrix(A, B, result, r1, c1, c2);
                printf("\nResult of Matrix Multiplication:\n");
                displayMatrix(result, r1, c2);
                break;

            case 3:
                printf("\nEnter rows and columns of Matrix: ");
                scanf("%d%d", &r1, &c1);

                printf("Enter elements of Matrix A:\n");
                inputMatrix(A, r1, c1);

                transposeMatrix(A, result, r1, c1);
                printf("\nTranspose of Matrix:\n");
                displayMatrix(result, c1, r1);
                break;

            case 4:
                printf("Exiting program...\n");
                return 0;

            default:
                printf("Invalid choice! Try again.\n");
        }
    }

    return 0;
}

// Function to input matrix
void inputMatrix(int matrix[MAX][MAX], int rows, int cols) {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            scanf("%d", &matrix[i][j]);
        }
    }
}

// Function to display matrix
void displayMatrix(int matrix[MAX][MAX], int rows, int cols) {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            printf("%d\t", matrix[i][j]);
        }
        printf("\n");
    }
}

// Function to add two matrices
void addMatrix(int A[MAX][MAX], int B[MAX][MAX], int result[MAX][MAX], int rows, int cols) {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            result[i][j] = A[i][j] + B[i][j];
        }
    }
}

// Function to multiply two matrices
void multiplyMatrix(int A[MAX][MAX], int B[MAX][MAX], int result[MAX][MAX], int r1, int c1, int c2) {
    for (int i = 0; i < r1; i++) {
        for (int j = 0; j < c2; j++) {
            result[i][j] = 0;
            for (int k = 0; k < c1; k++) {
                result[i][j] += A[i][k] * B[k][j];
            }
        }
    }
}

// Function to find transpose of a matrix
void transposeMatrix(int A[MAX][MAX], int result[MAX][MAX], int rows, int cols) {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            result[j][i] = A[i][j];
        }
    }
}
