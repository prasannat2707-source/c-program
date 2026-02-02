#include <stdio.h>
#include <stdlib.h>

int main() {
    int *empids;
    int n, new_n;

    printf("Enter the initial number of employees: ");
    scanf("%d", &n);
    empids = (int *)calloc(n, sizeof(int));
    if (empids == NULL) {
        printf("Memory allocation failed!\n");
        return 1;
    }
    printf("\nInitial employee IDs:\n");
    for (int i = 0; i < n; i++) {
        printf("ID %d: %d\n", i + 1, empids[i]);
    }
    printf("\nEnter employee IDs:\n");
    for (int i = 0; i < n; i++) {
        printf("Enter ID %d: ", i + 1);
        scanf("%d", &empids[i]);
    }
    printf("\nEnter the new total number of employees: ");
    scanf("%d", &new_n);
    empids = (int *)realloc(empids, new_n * sizeof(int));
    if (empids == NULL) {
        printf("Memory reallocation failed!\n");
        free(empids); 
       return 1;
    }
    if (new_n > n) {
        printf("\nEnter the additional employee IDs:\n");
        for (int i = n; i < new_n; i++) {
            printf("Enter ID %d: ", i + 1);
            scanf("%d", &empids[i]);
        }
    }
    printf("\nUpdated list of employee IDs:\n");
    for (int i = 0; i < new_n; i++) {
        printf("ID %d: %d\n", i + 1, empids[i]);
    }

    free(empids);
    printf("\nMemory freed.\n");

    return 0;
}