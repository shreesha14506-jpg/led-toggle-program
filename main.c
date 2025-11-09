#include <stdio.h>
#include "led.h"

int main() {
    int n, m;
    printf("Enter number of LEDs: ");
    scanf("%d", &n);
    printf("Enter toggle cycles: ");
    scanf("%d", &m);

    LED *leds = create_led_array(n);
    for (int i = 0; i < n; i++)
        initialize_led(&leds[i], i+1);

    printf("Initial status:\n");
    display_led_status(leds, n);

    toggle_alternately(leds, n, m);

    deallocate_leds(leds, n);
    return 0;
}
