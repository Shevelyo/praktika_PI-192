#include <stdio.h>
#include <process.h>

//Ввод матрицы A размерности nxn
void inputMatr(int n, int A[n][n]){
    printf("Input matr %dx%d:\n", n, n);
    for (int i = 0; i < n; ++i)
        for (int j = 0; j < n; ++j)
            scanf("%d", &A[i][j]);
}

//Вывод матрицы A размерности nxn
void printMatr(int n, int A[n][n]){
    printf("Your matr %dx%d:\n", n, n);
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j)
            printf("%4d", A[i][j]);
        printf("\n");
    }
    printf("\n");
}

//Заполняет массив maxArr максимальными элементами
//Соответствующих столбцов матрицы А размерности nxn
void getMaxEl(int n, int A[n][n], int maxArr[n]){
    for (int i = 0; i < n; ++i) {
        int max = A[0][i];
        for (int j = 0; j < n; ++j)
            if(A[j][i] > max)
                max = A[j][i];
        maxArr[i] = max;
    }
}

void swapInt(int *a, int *b){
    int tmp = *a;
    *a = *b;
    *b = tmp;
}

//Меняет местами i и j столбцы матрицы A размерности nxn
void swapCollumn(int n, int A[n][n], int i, int j){
    int tmp;
    for (int k = 0; k < n; ++k)
        swapInt(&A[k][i], &A[k][j]);
}

//Сортирует матрицу А размерности nxn
//по убыванию их наибольших элементов
void sortMatr(int n, int A[n][n]){
    int maxArr[n];
    getMaxEl(n, A, maxArr);

    for (int i = 0; i < n - 1; ++i) {
        int indexMax = i;
        for (int j = i; j < n; ++j)
            if(maxArr[j] > maxArr[indexMax])
                indexMax = j;

        if(i != indexMax) {
            swapCollumn(n, A, i, indexMax);
            swapInt(&maxArr[i], &maxArr[indexMax]);
        }
    }
}
int main() {
    int n;
    printf("Input n: ");
    scanf("%d", &n);
    int A[n][n];

    inputMatr(n, A);
    printMatr(n, A);

    sortMatr(n, A);

    printf("Sort...\n");
    printMatr(n, A);

    system("pause");
    return 0;
}
