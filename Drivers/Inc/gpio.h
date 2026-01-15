
#ifndef GPIO_H_
#define GPIO_H_
#include <stdint.h>

typedef enum {
    GPIO_PORT_A,
    GPIO_PORT_B,
    GPIO_PORT_C
} gpio_port_t;

typedef enum {
    GPIO_PIN_0,
    GPIO_PIN_1,
    GPIO_PIN_2,
    GPIO_PIN_3,
    GPIO_PIN_4,
    GPIO_PIN_5,
    GPIO_PIN_6,
    GPIO_PIN_7,
    GPIO_PIN_8,
    GPIO_PIN_9,
    GPIO_PIN_10,
    GPIO_PIN_11,
    GPIO_PIN_12,
    GPIO_PIN_13,
    GPIO_PIN_14,
    GPIO_PIN_15
} gpio_pin_t;

typedef enum {
    GPIO_OUTPUT,
	GPIO_INPUT_PULLUP,
	GPIO_INPUT_PULLDOWN,
	GPIO_INPUT_ANALOG,
	GPIO_INPUT_FLOAT

} gpio_mode_t;

typedef enum {
    GPIO_LOW,
    GPIO_HIGH
} gpio_value_t;

void gpio_init(gpio_port_t port, gpio_pin_t pin, gpio_mode_t mode);
void gpio_write(gpio_port_t port, gpio_pin_t pin, gpio_value_t value);
gpio_value_t  gpio_read(gpio_port_t port , gpio_pin_t pin);
#endif

