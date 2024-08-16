// merge_sort
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    int n;
    printf("Enter the number of elements : ");
    scanf("%d", &n);
    srand(time(0));
    int arr[n];
    for (int i = 0; i < n; i++) arr[i] = rand() % 200;
    for (int i = 0; i < n; i++) printf("%d ", arr[i]);

    clock_t start = clock();
    for (int size = 1; size < n; size *= 2)
    for (int left = 0; left < n - size; left += 2 * size) {
        int mid = left + size, right = (left + 2 * size < n) ? left + 2 * size : n;
        int i = 0, j = mid, k = left;
        while (i < mid && j < right) arr[k++] = (arr[i] <= arr[j]) ? arr[i++] : arr[j++];
        while (i < mid) arr[k++] = arr[i++];
        while (j < right) arr[k++] = arr[j++];
    }
    clock_t end = clock();
    printf("Sorted array:\n");
    for (int i = 0; i < n; i++) printf("%d ", arr[i]);
    printf("\n");
    printf("\nTime: %f seconds\n", ((double)(end - start)) / CLOCKS_PER_SEC);
        
    return 0;
}

//n_queens
#include <stdio.h>
#define N 4

int board[N][N] = {0};

int isSafe(int r, int c) {
    for (int i = 0; i < c; i++)
        if (board[r][i] || (r >= i && board[r-i][c-i]) || (r + i < N && board[r+i][c-i]))
            return 0;
    return 1;
}

void printSolution() {
    for (int i = 0; i < N; i++, printf("\n"))
        for (int j = 0; j < N; j++)
            printf("%c ", board[i][j] ? 'Q' : '.');
    printf("\n");
}

int solvenqeen(int c) {
    if (c == N) { 
        printSolution(); return 1; 
    }
    for (int i = 0; i < N; i++)
        if (isSafe(i, c)) {
            board[i][c] = 1;
            solvenqeen(c + 1);
            board[i][c] = 0;
        }
    return 0;
}
