
#include <stdint.h>
#include "clock.h"
#include "gpio.h"

#if !defined(__SOFT_FP__) && defined(__ARM_FP)
  #warning "FPU is not initialized, but the project is compiling for an FPU. Please initialize the FPU before use."
#endif

int main(void)
{
    /* Loop forever */
	gpio_init(GPIO_PORT_A , GPIO_PIN_3 , GPIO_INPUT_PULLUP);

	while(1){

		gpio_read(GPIO_PORT_A , GPIO_PIN_3);


	}
}
