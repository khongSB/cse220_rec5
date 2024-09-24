#include <stdio.h>
#include <stdlib.h>

void allocate_array(int **arr, int size) {
    *arr = (int *)malloc(size * sizeof(int)); // what does *arr mean?
    if (*arr == NULL) {
        printf("Memory allocation failed\n");
        return;
    }
    for (int i = 0; i < size; i++) {
        (*arr)[i] = i * 2; // Initialize the array with some values
    }
}

int main() {
    int *arr;
    int size = 5;

    allocate_array(&arr, size);  // &arr is address of the pointer

    // Print the array
    for (int i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");

    // Free the memory
    free(arr);

    return 0;
}
