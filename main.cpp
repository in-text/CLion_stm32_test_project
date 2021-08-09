#include "stm32f072xb.h"

int main() {
    _RCC->AHBENR |= RCC_AHBENR_GPIOAEN;
    _GPIOA->MODER |= GPIO_MODER_MODER5_0;

    for (;;) {
        _GPIOA->BSRR |= GPIO_BSRR_BS_5;
        for (int i = 0; i < 1000000; i++) { asm("nop"); }
        _GPIOA->BSRR |= GPIO_BSRR_BR_5;
        for (int i = 0; i < 1000000; i++) { asm("nop"); }
    }
}
