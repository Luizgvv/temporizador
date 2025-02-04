#include "pico/stdlib.h"

// Definição dos pinos dos LEDs e do botão
#define LED_AZUL 12
#define LED_VERMELHO 13
#define LED_VERDE 11
#define BOTAO 5

// Variáveis de controle
volatile int estado_leds = 0;  // Estado dos LEDs
volatile bool interacao_permitida = true;  // Define se o botão pode ser pressionado

// Função de callback do temporizador
int turn_off_callback(alarm_id_t id, void *user_data) {
    if (estado_leds == 1) {
        gpio_put(LED_AZUL, 0);  // Apaga o LED azul
        add_alarm_in_ms(3000, turn_off_callback, NULL, false);  // Agendar próximo estado
        estado_leds++;
    } else if (estado_leds == 2) {
        gpio_put(LED_VERMELHO, 0);  // Apaga o LED vermelho
        add_alarm_in_ms(3000, turn_off_callback, NULL, false);  // Agendar próximo estado
        estado_leds++;
    } else if (estado_leds == 3) {
        gpio_put(LED_VERDE, 0);  // Apaga o LED verde
        interacao_permitida = true;  // Agora o botão pode ser pressionado novamente
        estado_leds = 0;  // Reseta o estado para uma nova interação
    }
    return 0;
}

// Função de callback para o botão
void botao_callback(uint gpio, uint32_t events) {
    if (interacao_permitida) {
        interacao_permitida = false;  // Impede nova interação até que todos os LEDs apaguem

        // Liga todos os LEDs imediatamente
        gpio_put(LED_AZUL, 1);
        gpio_put(LED_VERMELHO, 1);
        gpio_put(LED_VERDE, 1);

        // Inicia a sequência de apagamento dos LEDs
        estado_leds = 1;
        add_alarm_in_ms(3000, turn_off_callback, NULL, false);
    }
}

int main() {
    // Inicializa os pinos GPIO para os LEDs
    gpio_init(LED_AZUL);
    gpio_set_dir(LED_AZUL, GPIO_OUT);
    gpio_init(LED_VERMELHO);
    gpio_set_dir(LED_VERMELHO, GPIO_OUT);
    gpio_init(LED_VERDE);
    gpio_set_dir(LED_VERDE, GPIO_OUT);

    // Inicializa o pino do botão
    gpio_init(BOTAO);
    gpio_set_dir(BOTAO, GPIO_IN);
    gpio_pull_up(BOTAO);  // Habilita o pull-up interno

    // Configura a interrupção para o botão
    gpio_set_irq_enabled_with_callback(BOTAO, GPIO_IRQ_EDGE_FALL, true, botao_callback);

    // Loop principal
    while (true) {
        tight_loop_contents();  // Aguarda interrupções
    }

    return 0;
}
