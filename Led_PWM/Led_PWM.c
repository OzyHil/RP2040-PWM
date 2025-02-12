#include <stdio.h>
#include "pico/stdlib.h"
#include "hardware/pwm.h"

#define PWM_LED 13  // Pino do LED conectado à GPIO como PWM
const uint16_t WRAP_PERIOD = 20000; // Período do PWM para 50Hz
const float PWM_DIVISER = 125.0f;   // Divisor de clock do PWM

// Definição dos valores de PWM para o LED
const uint16_t MIN_DUTY = 1000;  // Pulso mínimo (LED com brilho baixo, mas não apagado)
const uint16_t MAX_DUTY = 2000; // Pulso máximo (LED com brilho alto, mas não totalmente aceso)
const uint16_t MID_DUTY = 1500; // Pulso intermediário (LED com brilho médio)

// Parâmetros da movimentação suave
const int STEP_SIZE = 5;   // Incremento do ciclo ativo em microssegundos
const int STEP_DELAY = 10; // Atraso de ajuste em milissegundos

void pwm_setup() {
    gpio_set_function(PWM_LED, GPIO_FUNC_PWM); // Habilita GPIO como PWM
    uint slice = pwm_gpio_to_slice_num(PWM_LED); // Obtém slice PWM
    pwm_set_clkdiv(slice, PWM_DIVISER); // Configura divisor de clock
    pwm_set_wrap(slice, WRAP_PERIOD); // Configura o valor de wrap
    pwm_set_enabled(slice, true); // Habilita o PWM
}

void fade_led_smooth() {
    while (true) {
        // Aumento do brilho do LED (de baixo para alto)
        for (uint16_t duty = MIN_DUTY; duty <= MAX_DUTY; duty += STEP_SIZE) {
            pwm_set_gpio_level(PWM_LED, duty);
            sleep_ms(STEP_DELAY);
        }
        
        // Diminuição do brilho do LED (de alto para baixo)
        for (uint16_t duty = MAX_DUTY; duty >= MIN_DUTY; duty -= STEP_SIZE) {
            pwm_set_gpio_level(PWM_LED, duty);
            sleep_ms(STEP_DELAY);
        }
    }
}

int main() {
    stdio_init_all(); 
    pwm_setup(); 

    // LED com brilho máximo, mas não totalmente aceso
    pwm_set_gpio_level(PWM_LED, MAX_DUTY);
    sleep_ms(5000);

    // LED com brilho intermediário
    pwm_set_gpio_level(PWM_LED, MID_DUTY);
    sleep_ms(5000);

    // LED com brilho baixo, mas não apagado
    pwm_set_gpio_level(PWM_LED, MIN_DUTY);
    sleep_ms(5000);

    // Movimentação suave do brilho do LED...
    fade_led_smooth();
}
