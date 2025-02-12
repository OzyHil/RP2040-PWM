# Projeto de Controle de Servomotor por PWM com RP2040

## Vídeo de Demonstração

O vídeo de demonstração: https://youtu.be/tBq8psnrne4?si=nQwpR_wb9TBF4SvX

## Descrição

Este projeto foi desenvolvido por mim, **Hilquias Rodrigues de Oliveira**, com o objetivo de demonstrar o controle de um servomotor utilizando PWM no microcontrolador **RP2040**, através do **Pico SDK** e do simulador de eletrônica online **Wokwi**. O projeto envolve a manipulação do servomotor para ajustar sua posição entre os ângulos de 0 e 180 graus, com a implementação de movimentações suaves. Além disso, foi realizado um experimento com um **LED RGB** na **GPIO 12** utilizando a ferramenta educacional **BitDogLab**.

## Funcionalidades

1. **Controle do Servomotor**: O servomotor é controlado em três posições distintas:
   - 180 graus (ciclo ativo de 2.400µs).
   - 90 graus (ciclo ativo de 1.470µs).
   - 0 graus (ciclo ativo de 500µs).
   
2. **Movimentação Suave**: O servomotor se move suavemente entre os ângulos de 0 e 180 graus, com um incremento de ciclo ativo de ±5µs e atraso de 10ms.

3. **Controle de LED RGB**: O LED RGB foi controlado na GPIO 12 utilizando a ferramenta BitDogLab.

## Componentes Utilizados

- **Microcontrolador Raspberry Pi Pico W** (RP2040)
- **Servomotor Micro Servo Padrão** (Simulado no Wokwi)
- **LED RGB** (GPIO 12)
- **Botões** (Para interações com o código, se necessário no experimento)

## Aspectos do Projeto

- Implementação do controle de servomotor por PWM com ciclos de trabalho específicos.
- Movimentação suave do servomotor entre 0 e 180 graus.
- Experimento com controle de LED RGB utilizando a ferramenta BitDogLab.
- Código bem estruturado e comentado.
- Repositório no GitHub para versionamento e acompanhamento do projeto.

## Como Executar

Obs: Certifique-se de que você tem o ambiente configurado: 
- Pico SDK instalado
- Extensões Raspberry Pi Pico, Wokwi Simulator, CMake e C/C++

- **Após clonar este projeto, escolha uma das duas pastas e importe-a em "Import Project", opção esta que fica na extensão do Raspberry Pi Pico**

# Simulador
2. Realize a compilação
3. Abra o arquivo diagram.json e dê play no simulador

# Placa
2. A extensão **Pi Pico** criará automaticamente a pasta `build`.  
3. Clique em **Compile** na barra inferior do VSCode (ao lado esquerdo de "RUN | PICO SDK").  
4. Verifique se o arquivo `.uf2` foi gerado corretamente na pasta `build`.  
5. **Conecte a placa BitDogLab via USB** e coloque-a em **modo BOOTSEL**. 
6. Arraste o arquivo **`.uf2`** gerado para dentro da unidade de armazenamento da placa.  
7. O código será carregado e **executado automaticamente**.  
8. O LED RGB piscará continuamente a cada 0.2 segundos (5Hz) e será mostrado o número 0 na matriz.
9. Interaja com o sistema pressionando os botões A e B para alterar o número exibido na matriz de LEDs.
