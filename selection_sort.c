#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    int n, i, j, min, temp;

    // Input number of elements
    printf("Enter the number of elements: ");
    scanf("%d", &n);
    
    int array[n];
    srand(time(0));
    
    // Generating random elements and storing them in the array
    for (i = 0; i < n; i++) 
        array[i] = rand() % 100;
    
    // Printing the original array
    printf("Original array:\n");
    for (i = 0; i < n; i++) 
        printf("%d ", array[i]);
    printf("\n");
    
    clock_t start = clock();
    
    // Selection sort algorithm
    for (i = 0; i < n - 1; i++) {
        min = i;
        for (j = i + 1; j < n; j++)
            if (array[j] < array[min])
                min = j;
        temp = array[min];
        array[min] = array[i];
        array[i] = temp;
    }
    
    clock_t end = clock();
    
    // Printing the sorted array
    printf("Sorted array:\n");
    for (i = 0; i < n; i++) 
        printf("%d ", array[i]);
    printf("\n");
    
    // Printing the time taken to sort the array
    printf("Time: %f seconds\n", ((double)(end - start)) / CLOCKS_PER_SEC);
    
    getchar();  // Prevents the console from closing immediately
    getchar();  // Ensures the console waits for input before closing

    return 0;
}
