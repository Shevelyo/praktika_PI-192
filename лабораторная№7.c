#include <stdio.h>
#include <process.h>

#define N 5

//Ввод матрицы matr размерности NxN
void inputMatr(int matr[N][N]){
    printf("Input matr %dx%d\n", N, N);
    for (int i = 0; i < N; ++i)
        for (int j = 0; j < N; ++j)
            scanf("%d", &matr[i][j]);
}

//Вывод массива arr размерности N
void printArr(int arr[N]){
    printf("Your array: ");
    for (int i = 0; i < N; ++i)
        printf("%4d ", arr[i]);
    printf("\n");
}

//Возвращает сумму элементов массива размерности N
//если все элементы в массиве положительны либо отрицательны
//иначе 0
int getSumSignArr(int arr[N]){
    int sum = 0;
    for (int i = 0; i < N; ++i) {
        if (arr[0] * arr[i] <= 0)
            return 0;
        sum += arr[i];
    }
    return sum;
}

//Заполняет массив X суммой элементов строк массива matr
//Если все элементы строки либо положительны либо отрицательны
//Иначе соответсвующий элемент X равен 0
void getXarr(int matr[N][N], int X[N]){
    for (int i = 0; i < N; ++i)
        X[i] = getSumSignArr(matr[i]);
}

//Возвращает сумму элементов массива размерности N
//после первого 0
int getSumPostZero(int arr[N]){
    int sum = 0;
    int zeroPost = 0;
    for (int i = 0; i < N; ++i)
        if(arr[i] == 0)
            zeroPost = 1;
        else if (zeroPost)
            sum += arr[i];

    return sum;
}
int main() {
    int matr[N][N];
    int X[N];
    int Y;
    inputMatr(matr);
    getXarr(matr, X);
    Y = getSumPostZero(X);
    printArr(X);
    printf("Your Y = %d\n", Y);
    system("pause");
    return 0;
}
