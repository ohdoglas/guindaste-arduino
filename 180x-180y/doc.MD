
Documentação 2 — Guindaste com 2 servos 180° (eixo X e eixo Y)

```md
# Guindaste de Papelão com Joystick  
## Versão: 2 Servos 180° (eixo X e eixo Y)

## Visão Geral

Este projeto utiliza um **Arduino**, um **joystick HW-504** e **dois servos 180°** para controlar um guindaste simples de papelão com dois eixos de movimento.

Nesta versão:

- um servo 180° controla o **eixo X**;
- outro servo 180° controla o **eixo Y**.

Diferente da versão com servo contínuo, aqui os dois eixos possuem **controle de posição angular**, permitindo movimentos mais precisos e previsíveis.

O código foi desenvolvido para que o joystick mova os servos de forma lenta e progressiva, simulando melhor o comportamento de um guindaste.

---

## Categoria

Robótica educacional / Arduino / Controle de servos / Projeto mecânico simples

---

## Componentes Utilizados

- 1 Arduino
- 1 Joystick HW-504
- 2 Microservos 180°
- Estrutura de papelão para o guindaste
- Jumpers
- Fonte de alimentação adequada para os servos (recomendado)

---

## Função de Cada Componente

### Arduino
Lê o joystick e converte seus valores em comandos para os servos.

### Joystick HW-504
Oferece dois eixos analógicos para controle:

- **VRx**: controla o movimento do eixo X
- **VRy**: controla o movimento do eixo Y

### Servo 180° do eixo X
Responsável por girar o braço do guindaste para a esquerda e para a direita.

### Servo 180° do eixo Y
Responsável por controlar o movimento vertical ou angular do segundo mecanismo do guindaste.

---

## Aplicação no Guindaste

### Eixo X
Pode ser usado para o giro lateral do braço.

### Eixo Y
Pode ser usado para:

- inclinação de braço;
- elevação angular;
- ajuste fino da posição de uma haste;
- movimento vertical limitado por braço articulado.

Como ambos são servos 180°, esta versão é ideal quando se deseja parar o mecanismo em ângulos específicos.

---

## Ligações

## Joystick HW-504

- `VCC` → `5V` do Arduino
- `GND` → `GND` do Arduino
- `VRx` → `A0`
- `VRy` → `A1`

## Servo do eixo X

- Fio de sinal → `D9`
- VCC → `5V` externo ou alimentação apropriada
- GND → `GND comum`

## Servo do eixo Y

- Fio de sinal → `D10`
- VCC → `5V` externo ou alimentação apropriada
- GND → `GND comum`

---

## Atenção na Alimentação

Dois servos trabalhando juntos podem exigir mais corrente do que o Arduino consegue fornecer com estabilidade.

Problemas comuns quando a alimentação é inadequada:

- servo tremendo;
- servo sem força;
- Arduino reiniciando;
- travamentos;
- resposta inconsistente.

### Recomendação
Usar fonte externa de `5V` para os servos e unir o **GND da fonte ao GND do Arduino**.

---

## Lógica de Funcionamento

O joystick fornece leituras analógicas de `0` a `1023`.

O centro aproximado é `512`.

O código converte essas leituras para uma faixa proporcional e utiliza esse valor para aumentar ou diminuir lentamente a posição de cada servo.

### Eixo X
Quando o joystick se move para a esquerda ou direita, a posição do servo X é alterada de forma gradual.

### Eixo Y
Quando o joystick se move para cima ou para baixo, a posição do servo Y também é alterada de forma gradual.

---

## Movimento Suave

Ao invés de mandar o servo ir diretamente para uma posição distante, o código aplica pequenas variações por ciclo.

Isso gera:

- movimento mais lento;
- melhor controle;
- aparência mais realista;
- menor impacto mecânico na estrutura de papelão.

---

## Recurso de Zona Morta

O código usa uma **zona morta** para ignorar pequenas oscilações do joystick perto do centro.

Isso é importante para:

- evitar tremores;
- impedir movimentos involuntários;
- melhorar a estabilidade do sistema.

---

## Ajustes Rápidos no Código

A seguir estão os parâmetros mais importantes para regular o comportamento do guindaste.

### 1. Sensibilidade do joystick
```cpp
const int DEADZONE = 60;