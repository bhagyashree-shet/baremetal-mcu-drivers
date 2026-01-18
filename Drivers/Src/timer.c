
#include "timer.h"
#include "clock.h"
#include<stdint.h>

static timer_callback_t tim2_cb = 0;
#define TIM2_BASE 0x40000000UL
#define NVIC_ISER0 (*(volatile uint32_t *)0xE000E100)


typedef struct {
    volatile uint32_t CR1;
    volatile uint32_t CR2;
    volatile uint32_t SMCR;
    volatile uint32_t DIER;
    volatile uint32_t SR;
    volatile uint32_t EGR;
    volatile uint32_t CCMR1;
    volatile uint32_t CCMR2;
    volatile uint32_t CCER;
    volatile uint32_t CNT;
    volatile uint32_t PSC;
    volatile uint32_t ARR;
} TIM_RegDef_t;

#define TIM2 ((TIM_RegDef_t *)TIM2_BASE)

void tim2_register_callback(timer_callback_t cb)
{
    tim2_cb = cb;
}

void tim2_init(uint16_t prescaler, uint16_t period)
{
    /*  Enable TIM2 clock */
    clock_enable(CLOCK_TIM2);

    /* Set prescaler */
    TIM2->PSC = prescaler;
    /* Set ARR (Auto reset reload */
    TIM2->ARR = period;
    /*Reset count*/
    TIM2->CNT = 0;
    /*update flag*/
    TIM2->SR &= ~(1U << 0);
    /*interrupt generation*/
    TIM2->DIER |= (1U << 0);

    NVIC_ISER0 |= (1U << 28);   // TIM2 IRQ enable


}

void tim2_start(void)
{
    TIM2->CR1 |= (1U << 0);  // CEN
}
void tim2_stop(void)
{
    TIM2->CR1 &= ~(1U << 0);
}


void TIM2_IRQHandler(void)
{
    if (TIM2->SR & (1U << 0))  // UIF
    {
        TIM2->SR &= ~(1U << 0);  // clear flag

        if (tim2_cb)
        {
            tim2_cb();  //call function
        }
    }
}









