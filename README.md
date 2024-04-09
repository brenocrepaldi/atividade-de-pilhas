# Jogo de Cores em Tubos

Este é um jogo desenvolvido como atividade prática da disciplina "Estrutura e Recuperação de Dados" da PUC-Campinas. O jogo consiste em separar cores em tubos, onde o objetivo é organizar cada tubo com uma cor diferente.

## Funcionamento do Jogo

### Regras do Jogo:
1. O jogo é composto por 6 tubos, numerados de 1 a 6.
2. Cada tubo pode conter uma quantidade máxima de 5 elementos.
3. As cores dos elementos são representadas por números de 1 a 5.
4. O objetivo é distribuir as cores nos tubos de forma que cada tubo contenha apenas uma cor e não ultrapasse o limite de 5 elementos.

### Início do Jogo:
Ao iniciar o jogo, as cores são distribuídas aleatoriamente nos tubos. O jogador pode visualizar a disposição das cores nos tubos.

### Jogada:
O jogador pode escolher uma origem e um destino para mover uma cor de um tubo para outro. As jogadas são realizadas informando o número do tubo de origem e destino. O jogo alertará sobre jogadas inválidas, como selecionar tubos vazios ou cheios.

### Fim do Jogo:
O jogo termina quando todas as cores estiverem organizadas em tubos diferentes.

## Compilação e Execução:

### Requisitos:
- Compilador C++
- Sistema operacional Windows (para impressão de cores)

## Observações:
- Este código foi desenvolvido para fins educacionais.
- As bibliotecas `stack.h` e `stack_ld.h` foram utilizadas para implementação das pilhas.

