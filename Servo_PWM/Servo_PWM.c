#include <stdio.h>
#include "pico/stdlib.h"
#include "hardware/pwm.h"

#define PWM_SERVO_MOTOR 22  // Pino do servo motor conectado à GPIO como PWM
const uint16_t WRAP_PERIOD = 20000; // Período do PWM para 50Hz
const float PWM_DIVISER = 125.0f;   // Divisor de clock do PWM

// Definição dos valores de PWM para o servo
const uint16_t MIN_DUTY = 500;  // Pulso de 0.5ms (posição 0°)
const uint16_t MAX_DUTY = 2400; // Pulso de 2,4ms (posição 180°)
const uint16_t MID_DUTY = 1470; // Pulso de 1.47ms (posição central 90°)

// Parâmetros da movimentação suave
const int STEP_SIZE = 5;   // Incremento do ciclo ativo em microssegundos
const int STEP_DELAY = 10; // Atraso de ajuste em milissegundos

void pwm_setup() {
    gpio_set_function(PWM_SERVO_MOTOR, GPIO_FUNC_PWM); // Habilita GPIO como PWM
    uint slice = pwm_gpio_to_slice_num(PWM_SERVO_MOTOR); // Obtém slice PWM
    pwm_set_clkdiv(slice, PWM_DIVISER); // Configura divisor de clock
    pwm_set_wrap(slice, WRAP_PERIOD); // Configura o valor de wrap
    pwm_set_enabled(slice, true); // Habilita o PWM
}

void move_servo_smooth() {
    while (true) {
        // Movimento de 0° para 180°
        for (uint16_t duty = MIN_DUTY; duty <= MAX_DUTY; duty += STEP_SIZE) {
            pwm_set_gpio_level(PWM_SERVO_MOTOR, duty);
            sleep_ms(STEP_DELAY);
        }
        
        // Movimento de 180° para 0°
        for (uint16_t duty = MAX_DUTY; duty >= MIN_DUTY; duty -= STEP_SIZE) {
            pwm_set_gpio_level(PWM_SERVO_MOTOR, duty);
            sleep_ms(STEP_DELAY);
        }
    }
}

int main() {
    stdio_init_all(); 
    pwm_setup(); 

    // Movendo para posição máxima (180°)
    pwm_set_gpio_level(PWM_SERVO_MOTOR, MAX_DUTY);
    sleep_ms(5000);

    // Movendo para posição central (90°)
    pwm_set_gpio_level(PWM_SERVO_MOTOR, MID_DUTY);
    sleep_ms(5000);

    // Movendo para posição mínima (0°)
    pwm_set_gpio_level(PWM_SERVO_MOTOR, MIN_DUTY);
    sleep_ms(5000);

    // Movimentação periódica suave...
    move_servo_smooth();
}
