#include <Servo.h>

// =========================
// PINOS
// =========================
const int PIN_JOY_X = A0;
const int PIN_JOY_Y = A1;

const int PIN_SERVO_X = 9;
const int PIN_SERVO_Y = 10;

// =========================
// OBJETOS
// =========================
Servo servoX;
Servo servoY;

// =========================
// POSIÇÕES INICIAIS
// =========================
float posX = 90;
float posY = 90;

// =========================
// AJUSTES RÁPIDOS
// =========================
const int DEADZONE = 60;
const int LOOP_DELAY = 20; // ms
const int JOY_CENTER = 512;

// Velocidade máxima por ciclo
// Diminua para um guindaste mais lento
const float X_MAX_STEP = 1.0;
const float Y_MAX_STEP = 1.0;

// Sensibilidade geral
const float X_SENSITIVITY = 1.0;
const float Y_SENSITIVITY = 1.0;

// Limites mecânicos do projeto
const int X_MIN_ANGLE = 20;
const int X_MAX_ANGLE = 160;

const int Y_MIN_ANGLE = 30;
const int Y_MAX_ANGLE = 150;

// =========================
// FUNÇÕES AUXILIARES
// =========================
float normalizeJoystick(int value) {
  float n = (value - JOY_CENTER) / 512.0;

  if (abs(value - JOY_CENTER) < DEADZONE) {
    return 0.0;
  }

  if (n > 1.0) n = 1.0;
  if (n < -1.0) n = -1.0;

  return n;
}

void setup() {
  Serial.begin(9600);

  servoX.attach(PIN_SERVO_X);
  servoY.attach(PIN_SERVO_Y);

  servoX.write((int)posX);
  servoY.write((int)posY);

  delay(500);
}

void loop() {
  int rawX = analogRead(PIN_JOY_X);
  int rawY = analogRead(PIN_JOY_Y);

  float joyX = normalizeJoystick(rawX);
  float joyY = normalizeJoystick(rawY);

  // =========================
  // EIXO X
  // =========================
  float stepX = joyX * X_MAX_STEP * X_SENSITIVITY;
  posX += stepX;
  posX = constrain(posX, X_MIN_ANGLE, X_MAX_ANGLE);

  // =========================
  // EIXO Y
  // =========================
  float stepY = joyY * Y_MAX_STEP * Y_SENSITIVITY;
  posY += stepY;
  posY = constrain(posY, Y_MIN_ANGLE, Y_MAX_ANGLE);

  servoX.write((int)posX);
  servoY.write((int)posY);

  Serial.print("rawX: ");
  Serial.print(rawX);
  Serial.print(" | rawY: ");
  Serial.print(rawY);
  Serial.print(" | joyX: ");
  Serial.print(joyX, 2);
  Serial.print(" | joyY: ");
  Serial.print(joyY, 2);
  Serial.print(" | posX: ");
  Serial.print(posX);
  Serial.print(" | posY: ");
  Serial.println(posY);

  delay(LOOP_DELAY);
}