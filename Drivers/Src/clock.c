/*
 * clock.c
 *
 *  Created on: Jan 17, 2026
 *      Author: bhagy
 */

#include "clock.h"
#include <stdint.h>

/* RCC base address (STM32F103) */
#define RCC_BASE       0x40021000UL

/* APB2 peripheral clock enable register */
#define RCC_APB2ENR    (*(volatile uint32_t *)(RCC_BASE + 0x18))
#define RCC_APB1ENR    (*(volatile uint32_t *)(RCC_BASE + 0x1C))

void clock_enable(clk_id_t clk)
{
    switch (clk)
    {
        case CLOCK_GPIOA:
            RCC_APB2ENR |= (1U << 2);   // IOPAEN
            break;

        case CLOCK_GPIOB:
            RCC_APB2ENR |= (1U << 3);   // IOPBEN
            break;

        case CLOCK_GPIOC:
            RCC_APB2ENR |= (1U << 4); //IOPCEN
            break;

        case CLOCK_AFIO:
            RCC_APB2ENR |= (1U << 0);   // AFIOEN
            break;

        case CLOCK_TIM2:
        	RCC_APB1ENR |= (1U << 0); // TIM2EN

        default:
            break;
    }
}
