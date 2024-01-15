
#include <stdio.h>
#include <pthread.h>
#include "FreeRTOS.h"
#include "task.h"
#include "timers.h"
#include "semphr.h"
#include "console.h"

/* Priorities at which the tasks are created. */
#define TASK1_PRIORITY  (tskIDLE_PRIORITY + 3)
#define TASK2_PRIORITY  (tskIDLE_PRIORITY + 2)
#define TASK3_PRIORITY  (tskIDLE_PRIORITY + 1)
#define TASK4_PRIORITY  (tskIDLE_PRIORITY)

/* Periods for the tasks. */
#define TASK1_PERIOD    pdMS_TO_TICKS(500)  //execution time of 0.001ms
#define TASK2_PERIOD    pdMS_TO_TICKS(1000) //execution time of 0.0029ms
#define TASK3_PERIOD    pdMS_TO_TICKS(1500) //execution time of 0.0016ms
#define TASK4_PERIOD    pdMS_TO_TICKS(2000) //execution time of 0.002ms


#define mainQUEUE_LENGTH                   ( 4 )


static void vTask1(void *pvParameters);
static void vTask2(void *pvParameters);
static void vTask3(void *pvParameters);
static void vTask4(void *pvParameters);

void main_blinky(void);

void main_blinky(void) {
    /* Create the tasks as described in the comments. */
    xTaskCreate(vTask1, "Task1", configMINIMAL_STACK_SIZE, NULL, TASK1_PRIORITY, NULL);
    xTaskCreate(vTask2, "Task2", configMINIMAL_STACK_SIZE, NULL, TASK2_PRIORITY, NULL);
    xTaskCreate(vTask3, "Task3", configMINIMAL_STACK_SIZE, NULL, TASK3_PRIORITY, NULL);
    xTaskCreate(vTask4, "Task4", configMINIMAL_STACK_SIZE, NULL, TASK4_PRIORITY, NULL);

    /* Start the scheduler. */
    vTaskStartScheduler();

    /* The scheduler should never return. If it does, there was not enough
     * heap available for the idle and/or timer tasks to be created. See
     * the memory management section on the FreeRTOS website. */
    for (;;) {
    }
}

static void vTask1(void *pvParameters) {
    for (;;) {
        printf("Task 1 Working\n");
        vTaskDelay(TASK1_PERIOD);
    }
}

static void vTask2(void *pvParameters) {
    const float fahrenheitValue = 86;

    for (;;) {
        float celsiusValue = (fahrenheitValue - 32) * 5 / 9.0;
        printf("Temperature in Fahrenheit: %.2f, Temperature in Celsius: %.2f\n", fahrenheitValue, celsiusValue);
        vTaskDelay(TASK2_PERIOD);
    }
}

static void vTask3(void *pvParameters) {
    const long int num1 = 2500011;
    const long int num2 = 85479856975;

    for (;;) {
        long int result = num1 * num2;
        printf("Multiplication result: %ld\n", result);
        vTaskDelay(TASK3_PERIOD);
    }
}

static void vTask4(void *pvParameters) {
    for (;;){
    int arr[50];
    int i = 0;

    for (i; i < 50; i++) {
        arr[i] = i + 10 * i;
    }

    int target = 110;
    int low = 0;
    int high = 49;
    int result = -1;

    for (;;) {
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

    if (result != -1)
        printf("Element %d found at index %d.\n", target, result);
    else
        printf("Element %d not found in the list.\n", target);
    
    vTaskDelay(TASK4_PERIOD);
    }
}
