#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define NUM_RUNS 1000

static void vTask1(void *pvParameters);
static void vTask2(void *pvParameters);
static void vTask3(void *pvParameters);
static void vTask4(void *pvParameters);

// Fonction pour mesurer le temps d'exécution
void measureExecutionTime(void (*task)(void *), void *parameters, const char *taskName);

int main() {
    // Mesurer le temps d'exécution de chaque tâche
    measureExecutionTime(vTask1, NULL, "Task 1");
   // measureExecutionTime(vTask2, NULL, "Task 2");
    //measureExecutionTime(vTask3, NULL, "Task 3");
    //measureExecutionTime(vTask4, NULL, "Task 4");

    return 0;
}

static void vTask1(void *pvParameters) {
    printf("Working\n");
}

static void vTask2(void *pvParameters) {
    const float fahrenheitValue = 86; // Example Fahrenheit value
    float celsiusValue;

    for (int i = 0; i < NUM_RUNS; i++) {
        // Convert Fahrenheit to Celsius
        celsiusValue = (fahrenheitValue - 32) * 5 / 9.0;
    }

    // Calculate average time
    double avg_time = ((double) (clock())) / CLOCKS_PER_SEC / NUM_RUNS;

    printf("Average Temperature conversion time: %.6f seconds\n", avg_time);
}

static void vTask3(void *pvParameters) {
    const long int num1 = 123456789;
    const long int num2 = 987654321;

    for (int i = 0; i < NUM_RUNS; i++) {
        // Multiply two numbers
        long int result = num1 * num2;
    }

    // Calculate average time
    double avg_time = ((double) (clock())) / CLOCKS_PER_SEC / NUM_RUNS;

    printf("Average Multiplication time: %.6f seconds\n", avg_time);
}

static void vTask4(void *pvParameters) {
    int arr[50];
    int i = 0;

    for (i; i < 50; i++) {
        arr[i] = i + 10 * i;
    }

    int target = 110; // Element to search for

    for (int i = 0; i < NUM_RUNS; i++) {
        // Binary search
        int low = 0;
        int high = 49;
        int result = -1;

        while (low <= high) {
            int mid = low + (high - low) / 2;

            if (arr[mid] == target) {
                result = mid;
                break;
            }

            if (arr[mid] < target)
                low = mid + 1;
            else
                high = mid - 1;
        }
    }

    // Calculate average time
    double avg_time = ((double) (clock())) / CLOCKS_PER_SEC / NUM_RUNS;

    printf("Average Binary Search time: %.6f seconds\n", avg_time);
}

void measureExecutionTime(void (*task)(void *), void *parameters, const char *taskName) {
    clock_t start, end;
    double cpu_time_used;

    // Mesurer le temps de début
    double max = 0;

    // Exécuter la tâche
    double sum = 0;
    double actual;
    
    for (int i = 0; i < 1000; i++) {
        start = clock();
        task(parameters);
        end = clock();
        
        // Calculer le temps d'exécution en secondes avec une précision de type double
        actual = ((double) (end - start)) / CLOCKS_PER_SEC;
        
        sum += actual;
        
        if (actual > max) {
            max = actual;
        }
    }
    max = max*1000;
    // Afficher le temps d'exécution
    printf("%s executed in %f milliseconds\nMax execution time: %f\n", taskName, sum, max);
}