#include "FreeRTOS.h"
#include "task.h"

#define STACK_SIZE 200
StaticTask_t xTaskBuffer;
StackType_t xStack[ STACK_SIZE ];
TaskHandle_t xHandle = NULL;

volatile uint8_t test = 0;

/* Function that implements the task being created. */
void vTaskCode( void * pvParameters )
{
    /* The parameter value is expected to be 1 as 1 is passed in the
        pvParameters value in the call to xTaskCreateStatic(). */
    configASSERT( ( uint32_t ) pvParameters == 1UL );

    for( ;; )
    {
        /* Task code goes here. */
        vTaskDelay(pdMS_TO_TICKS(1000));
        test++;
    }
}

void vApplicationStackOverflowHook( TaskHandle_t xTask, char * pcTaskName )
{
    /* Check pcTaskName for the name of the offending task,
        * or pxCurrentTCB if pcTaskName has itself been corrupted. */
    ( void ) xTask;
    ( void ) pcTaskName;
}

void App_main(void)
{
    /* Create the task without using any dynamic memory allocation. */
    xHandle = xTaskCreateStatic(
                    vTaskCode,       /* Function that implements the task. */
                    "NAME",          /* Text name for the task. */
                    STACK_SIZE,      /* Number of indexes in the xStack array. */
                    ( void * ) 1,    /* Parameter passed into the task. */
                    tskIDLE_PRIORITY + 1,/* Priority at which the task is created. */
                    xStack,          /* Array to use as the task's stack. */
                    &xTaskBuffer );  /* Variable to hold the task's data structure. */

    vTaskStartScheduler();

    while(1)
    {

    }
}