
#include "gpio.h"
#include "clock.h"
#include <stdint.h>

#define GPIOA_BASE 0x40010800UL
#define GPIOB_BASE 0x40010C00UL
#define GPIOC_BASE 0x40011000UL

typedef struct {
    volatile uint32_t CRL;
    volatile uint32_t CRH;
    volatile uint32_t IDR;
    volatile uint32_t ODR;
    volatile uint32_t BSRR;
    volatile uint32_t BRR;
    volatile uint32_t LCKR;
} GPIO_RegDef_t;

#define GPIOA ((GPIO_RegDef_t *)GPIOA_BASE)
#define GPIOB ((GPIO_RegDef_t *)GPIOB_BASE)
#define GPIOC ((GPIO_RegDef_t *)GPIOC_BASE)

static GPIO_RegDef_t *gpio_get_port(gpio_port_t port)
{
    switch (port)
    {
        case GPIO_PORT_A: return GPIOA;
        case GPIO_PORT_B: return GPIOB;
        case GPIO_PORT_C: return GPIOC;
        default: return 0;
    }
}

void gpio_init(gpio_port_t port, gpio_pin_t pin, gpio_mode_t mode)
{

    GPIO_RegDef_t *gpio = gpio_get_port(port);
    if (!gpio) return;

    /* Enable clock for the port */
    if (port == GPIO_PORT_A) clock_enable(CLOCK_GPIOA);
    if (port == GPIO_PORT_B) clock_enable(CLOCK_GPIOB);
    if (port == GPIO_PORT_C) clock_enable(CLOCK_GPIOC);
    uint32_t pos;

    if (pin < 8)
    {
        pos = pin * 4;
        gpio->CRL &= ~(0xF << pos);      // clear 4 bits
        gpio->CRL |=  (0x8 << pos);      // input pull up mode
        gpio->ODR |=  (1U << pin);
    }
    else
    {
        pos = (pin - 8) * 4;
        gpio->CRH &= ~(0xF << pos);
        gpio->CRH |=  (0x8 << pos);
        gpio->ODR |=  (1U << pin);
    }
}

void gpio_write(gpio_port_t port, gpio_pin_t pin, gpio_value_t value)
{
    GPIO_RegDef_t *gpio = gpio_get_port(port);
    if (!gpio) return;

    if (value == GPIO_HIGH)
        gpio->BSRR = (1U << pin);        // set bit
    else
        gpio->BSRR = (1U << (pin + 16)); // reset bit
}

gpio_value_t gpio_read(gpio_port_t port , gpio_pin_t pin)
{
	GPIO_RegDef_t *gpio = gpio_get_port(port);
	if (!gpio) return GPIO_LOW;

	return ( gpio->IDR & ( 1U << pin )) ? GPIO_HIGH :  GPIO_LOW ;

}

