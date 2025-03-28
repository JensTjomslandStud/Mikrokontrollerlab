#include <stdint.h>

#define GPIO ((NRF_GPIO_REGS*)0x50000000)

#define __BUTTON_1_PIN__ 13
#define __BUTTON_2_PIN__ 14
#define __BUTTON_3_PIN__ 15
#define __BUTTON_4_PIN__ 16


typedef struct {
	volatile uint32_t RESERVED0[321];
	volatile uint32_t OUT;
	volatile uint32_t OUTSET;
	volatile uint32_t OUTCLR;
	volatile uint32_t IN;
	volatile uint32_t DIR;
	volatile uint32_t DIRSET;
	volatile uint32_t DIRCLR;
	volatile uint32_t LATCH;
	volatile uint32_t DETECTMODE;
	volatile uint32_t RESERVED1[118];
	volatile uint32_t PIN_CNF[32];
} NRF_GPIO_REGS;

void button_init(){ 
	GPIO->PIN_CNF[__BUTTON_1_PIN__] = (3 << 2);
	GPIO->PIN_CNF[__BUTTON_2_PIN__] = (3 << 2);
	GPIO->PIN_CNF[__BUTTON_3_PIN__] = (3 << 2);
	GPIO->PIN_CNF[__BUTTON_4_PIN__] = (3 << 2);
	//setter knapper aktivt lav
	// Fill inn the configuration for the remaining buttons 
}

int button_pressed(int button_index) {
	return (!(GPIO->IN & (1<<button_index)));
}

void set_led_matrix () {
	for(int i = 17; i <= 20; i++){
		GPIO->DIRSET = (1 << i); 
		GPIO->OUTCLR = (1 << i);
	}
}

void clr_led_matrix () {
	for(int i = 17; i <= 20; i++){
		GPIO->DIRSET = (1 << i); 
		GPIO->OUTSET = (1 << i);
	}
}




int main(){
	// Configure LED Matrix
	for(int i = 17; i <= 20; i++){
		GPIO->DIRSET = (1 << i); 
		GPIO->OUTCLR = (1 << i);
	} //sets lights on in the beginning. 

	// Configure buttons -> see button_init()
	button_init();

	int sleep = 0;
	while(1){

		/* Check if button 1 is pressed;
		 * turn on LED matrix if it is. */
		 
		if (button_pressed(13)) {
			set_led_matrix();
		}
		/* Check if button 2 is pressed;
		 * turn off LED matrix if it is. */
		if (button_pressed(14)) {
			clr_led_matrix();
		}
		sleep = 10000;
		while(--sleep); // Delay
	}
	return 0;
}
