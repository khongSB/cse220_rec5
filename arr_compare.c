#include <stdio.h>
#include <stdlib.h>
#define ROWS 2
#define COLS 3

int main(void) {
    int two[][COLS] = {{1, 2, 3}, {4, 5, 6}};

    for (int row = 0; row < ROWS; row++) {
        printf("two[%d]: %p\n", row, (void*)two[row]);
        for (int col = 0; col < COLS; col++) {
            printf("two[%d][%d]: array indexing:\t%d (%p)\n", row, 
 				col, two[row][col], (void*)&two[row][col]);
            printf("two[%d][%d]: double dereference:\t%d (%p)\n", 
				row, col, *(*(two + row) + col), 
(void*)(*(two + row) + col));
            printf("two[%d][%d]: single dereference:\t%d (%p)\n", 
				row, col, *((int*)two + row * COLS + col),
                   (void*)(two + row * COLS + col));
        }
    }

    int* ptrs[ROWS];
    ptrs[0] = malloc(3 * sizeof(int));
    ptrs[1] = malloc(3 * sizeof(int));

    for (int row = 0; row < ROWS; row++) {
        for (int col = 0; col < COLS; col++) {
            ptrs[row][col] = two[row][col];
        }
    }

    for (int row = 0; row < ROWS; row++) {
        printf("ptrs[%d]: %p\n", row, (void*)ptrs[row]);
        for (int col = 0; col < COLS; col++) {
            printf("ptrs[%d][%d]: array indexing:\t%d (%p)\n", row, 
				col, ptrs[row][col], (void*)&ptrs[row][col]);
            printf("ptrs[%d][%d]: double dereference:\t%d (%p)\n", 
				row, col, *(*(ptrs + row) + col), 
				(void*)(*(ptrs + row) + col));
            printf("ptrs[%d][%d]: single dereference:\t%d (%p)\n", 
				row, col, *((int*)ptrs + row * COLS + col),
                   (void*)(ptrs + row * COLS + col));
        }
    }

    return 0;
}
