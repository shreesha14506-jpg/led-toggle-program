#include "led.h"
#include <stdio.h>
#include <stdlib.h>

LED* create_led_array(int n) {
    LED *leds = (LED *)malloc(n * sizeof(LED));
    for (int i = 0; i < n; i++) {
        leds[i].status = (int *)malloc(sizeof(int));
    }
    return leds;
}

void initialize_led(LED *led, int led_number) {
    led->led_no = led_number;
    *(led->status) = 0;
}

void set_led(LED *led) { *(led->status) = 1; }
void reset_led(LED *led) { *(led->status) = 0; }

void toggle_led(LED *led) {
    *(led->status) = !(*(led->status));
}

void display_led_status(LED *leds, int n) {
    for (int i = 0; i < n; i++) {
        printf("LED%d: %s  ", leds[i].led_no, *(leds[i].status) ? "ON" : "OFF");
    }
    printf("\n");
}

void toggle_alternately(LED *leds, int n, int m) {
    for (int k = 0; k < m; k++) {
        for (int i = 0; i < n; i += 2) {
            toggle_led(&leds[i]);
        }
        display_led_status(leds, n);
        for (int i = 1; i < n; i += 2) {
            toggle_led(&leds[i]);
        }
        display_led_status(leds, n);
    }
}

void deallocate_leds(LED *leds, int n) {
    for (int i = 0; i < n; i++)
        free(leds[i].status);
    free(leds);
}
