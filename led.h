#ifndef LED_H
#define LED_H

typedef struct {
    int led_no;
    int *status;
} LED;

LED* create_led_array(int n);
void initialize_led(LED *led, int led_number);
void set_led(LED *led);
void reset_led(LED *led);
void toggle_led(LED *led);
void display_led_status(LED *leds, int n);
void toggle_alternately(LED *leds, int n, int m);
void deallocate_leds(LED *leds, int n);

#endif // LED_H
