//quick_sort
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    int n;
    printf("Enter number of elements: ");
    scanf("%d", &n);
    srand(time(0));

    int array[n];
    for (int i = 0; i < n; i++) array[i] = rand() % 200;
    for (int i = 0; i < n; i++) printf("%d ", array[i]);

    clock_t start = clock();
    void quicksort(int low, int high) {
        if (low < high) {
            int pivot = array[high], i = low - 1, temp;
            for (int j = low; j < high; j++) {
                if (array[j] < pivot) {
                    temp = array[++i];
                    array[i] = array[j];
                    array[j] = temp;
                }
            }
            temp = array[++i];
            array[i] = array[high];
            array[high] = temp;

            quicksort(low, i - 1);
            quicksort(i + 1, high);
        }
    }

    quicksort(0, n - 1);
    clock_t end = clock();

    printf("Sorted array:\n");
    for (int i = 0; i < n; i++) printf("%d ", array[i]);
    printf("\n");
    printf("\nTime: %f seconds\n", ((double)(end - start)) / CLOCKS_PER_SEC);

    return 0;
}
