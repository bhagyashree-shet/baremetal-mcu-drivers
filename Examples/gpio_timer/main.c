#include <stdint.h>
#include "gpio.h"
#include "timer.h"
#if !defined(__SOFT_FP__) && defined(__ARM_FP)
  #warning "FPU is not initialized, but the project is compiling for an FPU. Please initialize the FPU before use."
#endif

void led_toggle_task(void){

	gpio_toggle(GPIO_PORT_C , GPIO_PIN_13);
}
int main(void)
{    gpio_init(GPIO_PORT_C , GPIO_PIN_13 , GPIO_OUTPUT);
    /* Loop forever */
	tim2_init(7199 , 9999 ); //1 second
    tim2_register_callback(led_toggle_task);
	tim2_start();

	for(;;);

}
