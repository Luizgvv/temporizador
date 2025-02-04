# Atividade 2: Temporizador de um Disparo (One Shot)

## Descrição

Este projeto implementa um sistema de temporização para o acionamento de LEDs utilizando a função `add_alarm_in_ms()` do Pico SDK. O sistema é acionado a partir do clique em um botão (pushbutton). Quando o botão é pressionado, os LEDs são ligados, e a cada 3 segundos ocorre uma mudança de estado entre os LEDs.

O sistema é desenvolvido utilizando o microcontrolador Raspberry Pi Pico W, com 3 LEDs (azul, vermelho e verde) e um botão. O temporizador é configurado para fazer a troca de estados dos LEDs após um intervalo de 3 segundos.

## Componentes

- **Microcontrolador**: Raspberry Pi Pico W
- **LEDs**: 3 LEDs (azul, vermelho, verde)
- **Resistores**: 3 resistores de 330 Ω
- **Botão A**: Pushbutton
- **Ferramenta de Simulação**: Wokwi

## Diagrama de Circuito

| Componente     | GPIO  |
|----------------|-------|
| LED Azul       | 12    |
| LED Vermelho   | 13    |
| LED Verde      | 11    |
| Botão A        | 05    |

## Funcionamento

1. Quando o usuário pressiona o botão A (pushbutton), todos os LEDs são ligados (em nível alto).
2. Após 3 segundos, um LED será desligado e, em seguida, outro LED será desligado a cada 3 segundos.
3. O temporizador (almacenado com `add_alarm_in_ms()`) gerencia o controle de tempo para desligar os LEDs em sequência.
4. O botão só pode alterar o estado dos LEDs quando o último LED for desligado. Ou seja, não é permitido pressionar o botão novamente enquanto a sequência de temporização estiver em andamento.

### Passos:

- **Passo 1**: O botão A é pressionado.
- **Passo 2**: Todos os LEDs são acesos.
- **Passo 3**: Após 3 segundos, o LED azul é desligado.
- **Passo 4**: Após mais 3 segundos, o LED vermelho é desligado.
- **Passo 5**: Após mais 3 segundos, o LED verde é desligado, e o ciclo se encerra.

## Requisitos

- **Hardware**:
  - Microcontrolador Raspberry Pi Pico W
  - 3 LEDs RGB (azul, vermelho e verde)
  - Pushbutton
  - 3 Resistores de 330 Ω
  
- **Software**:
  - Pico SDK (Raspberry Pi Pico SDK)
  - Wokwi (para simulação) ou Raspberry Pi Pico físico

## Código

O código foi implementado em linguagem C utilizando as funções do Pico SDK. A sequência de acionamento dos LEDs é gerenciada por uma rotina de callback associada ao temporizador.

### Funcionalidades Implementadas:
1. **Função `turn_off_callback`**: Função de callback chamada a cada 3 segundos para alterar o estado dos LEDs.

## Instruções de Uso

1. Conecte o circuito conforme descrito acima no Raspberry Pi Pico W ou utilize a simulação do Wokwi.
2. Compile o código com o Pico SDK.
3. Faça o upload para o microcontrolador.
4. Pressione o botão para iniciar o ciclo de acionamento e desligamento dos LEDs.

## Como Executar o Projeto

### 1. Configuração do Ambiente

Certifique-se de ter instalado:

- Raspberry Pi Pico SDK
- Compilador ARM GNU Toolchain
- Wokwi (para simulação) ou Raspberry Pi Pico físico

### 2. Clonar o Repositório

No terminal, execute o comando:

```bash
git clone https://github.com/Luizgvv/temporizador.git
```
### 3. Compile o Código

Isso gerará um arquivo .uf2 que pode ser enviado para o Raspberry Pi Pico.

### 4. Executar a Simulação no Wokwi

Você pode utilizar a simulação do Wokwi do VSCode ou utilizar o link abaixo:

[Demonstração no Wokwi](https://wokwi.com/projects/421826187773240321)

### Autor
Luiz Gustavo do Valle Vieira
