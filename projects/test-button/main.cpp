/*
 * Copyright 2013 OpenMote Technologies, S.L.
 */

/**
 *
 * @file       test-button.cpp
 * @author     Pere Tuset-Peiro (peretuset@openmote.com)
 * @version    v0.1
 * @date       May, 2014
 * @brief
 * @ingroup
 *
 */

/*================================ include ==================================*/

#include "FreeRTOS.h"
#include "task.h"
#include "semphr.h"

#include "openmote-cc2538.h"

#include "Callback.h"

/*================================ define ===================================*/

#define GREEN_LED_TASK_PRIORITY             ( tskIDLE_PRIORITY + 1 )
#define BUTTON_TASK_PRIORITY                ( tskIDLE_PRIORITY + 0 )

/*================================ typedef ==================================*/

/*=============================== variables =================================*/

static xSemaphoreHandle xSemaphoreButton;

/*=============================== prototypes ================================*/

static void prvGreenLedTask(void *pvParameters);
static void prvButtonTask(void *pvParameters);

static void button_user_callback(void);

/*================================= public ==================================*/

int main (void)
{
    // Set the TPS62730 in bypass mode (Vin = 3.3V, Iq < 1 uA)
    tps62730.setBypass();

    // Create two FreeRTOS tasks
    xTaskCreate(prvGreenLedTask, (const char *) "Green", 128, NULL, GREEN_LED_TASK_PRIORITY, NULL);
    xTaskCreate(prvButtonTask, (const char *) "Button", 128, NULL, BUTTON_TASK_PRIORITY, NULL);

    // Kick the FreeRTOS scheduler
    vTaskStartScheduler();
}

/*================================ private ==================================*/

static void button_user_callback(void)
{
    static BaseType_t xHigherPriorityTaskWoken;

    xHigherPriorityTaskWoken = pdFALSE;

    xSemaphoreGiveFromISR(xSemaphoreButton, &xHigherPriorityTaskWoken);

    portYIELD_FROM_ISR(xHigherPriorityTaskWoken);
}

static void prvButtonTask(void *pvParameters)
{
    static GenericCallback genericCallback(button_user_callback);

    xSemaphoreButton = xSemaphoreCreateMutex();

    button_user.setCallback(&genericCallback);
    button_user.enableInterrupt();

    while(true)
    {
        /* The second parameter indicates the interval at which the xSempahore
           is polled and, thus, it determines latency and energy consumption. */
        if (xSemaphoreTake(xSemaphoreButton, (TickType_t) portMAX_DELAY) == pdTRUE)
        {
            led_red.toggle();
        }
    }
}

static void prvGreenLedTask(void *pvParameters)
{
    while(true)
    {
        led_green.on();
        vTaskDelay(50 / portTICK_RATE_MS);
        led_green.off();
        vTaskDelay(950 / portTICK_RATE_MS);
    }
}
