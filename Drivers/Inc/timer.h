
#ifndef TIMER_H
#define TIMER_H

#include <stdint.h>

typedef void (*timer_callback_t)(void);

void tim2_init(uint16_t prescaler, uint16_t period);
void tim2_start(void);
void tim2_register_callback(timer_callback_t cb);

#endif
