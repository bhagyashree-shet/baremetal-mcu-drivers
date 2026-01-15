
#include <stdint.h>
#include "clock.h"
#include "gpio.h"

#if !defined(__SOFT_FP__) && defined(__ARM_FP)
  #warning "FPU is not initialized, but the project is compiling for an FPU. Please initialize the FPU before use."
#endif

int main(void)
{
	gpio_init(GPIO_PORT_C, GPIO_PIN_13, GPIO_OUTPUT);

	    while (1)
	    {
	        gpio_write(GPIO_PORT_C, GPIO_PIN_13, GPIO_HIGH);  
	        for (volatile int i = 0; i < 100000; i++);

	        gpio_write(GPIO_PORT_C, GPIO_PIN_13, GPIO_LOW);
	        for (volatile int i = 0; i < 100000; i++);
	    }

}
