
#ifndef CLOCK_H_
#define CLOCK_H_


typedef enum {
    CLOCK_GPIOA,
    CLOCK_GPIOB,
	CLOCK_GPIOC,
    CLOCK_AFIO,
	CLOCK_TIM2
} clk_id_t;

void clock_enable(clk_id_t clk);

#endif /* CLOCK_H_ */

