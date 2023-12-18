#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int sum(int a, int b){
    return a+b;
}

int searchValue(int arr[], int size, int value) {
    int i;
    for (i = 0; i < size; ++i) {
        if (arr[i] == value) {
            return i;
        }
    }
    return -1;
}
void printArray(int arr[], int size) {
    printf("Array: ");
    int i;
    for (i = 0; i < size; ++i) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

int binarySearch(int arr[], int size, int target) {
    int left = 0;
    int right = size - 1;

    while (left <= right) {
        int mid = left + (right - left) / 2;

        if (arr[mid] == target) {
            return mid;
        } else if (arr[mid] < target) {
            left = mid + 1;
        } else {
            right = mid - 1;
        }
    }

    return -1;
}


void printElapsedTime() {
    clock_t start_time = clock();
    clock_t current_time;

    while (1) {
        current_time = clock();
        double elapsed_seconds = (double)(current_time - start_time) / CLOCKS_PER_SEC;

        // Print elapsed time in seconds
        printf("Elapsed Time: %.2f seconds\n", elapsed_seconds);

        // Sleep for 1 second (optional, requires including <unistd.h>)
        // sleep(1);

        // Break the loop after a certain condition (e.g., after 10 seconds)
        if (elapsed_seconds >= 10.0) {
            break;
        }
    }
}


int main()
{
    int a;
    int b;
    printf("choose value for a: ");
    scanf("%d", &a);
    printf("choose value for b: ");
    scanf("%d", &b);
    int c = sum(a,b);
    printf("%d + %d = %d\n", a,b, c);

    if (a<b){
        printf("b is bigger\n");
    }
    else if(a==b){
        printf("a and b are equal\n");
    }
    else
    {
        printf("a is bigger\n");
    }

    int i;
    for (i=0;i<100;i++){
        printf("%d ", i);
    }
    int d;
    printf("\ninsert value ");
    scanf("%d", &d);

    printf("the value of the variable is %d and its address is %d", d, &d);

    int size=4;
    int array[4] = {25, 50, 75, 100};
    printf("\n");
    printArray(array,size);
    int value_to_search;
    printf("Insert value to search in Array: ");
    scanf("%d", &value_to_search);

    int index = searchValue(array, size, value_to_search);
    printf("\nindex of the value: %d", index);

    int index_binary = binarySearch(array, size, value_to_search);
    printf("\nindex of the value with binary search: %d", index_binary);

    printElapsedTime();

    return 0;
}
