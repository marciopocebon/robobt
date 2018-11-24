/**
 * Robô BT (controlado via bluetooth)
 * Professor José de Assis
 * http://professorjosedeassis.com.br/
 * http://roboticapratica.com.br/
 */

#include <SoftwareSerial.h>
SoftwareSerial MinhaSerial(2, 3);

#include <PWMServo.h>
PWMServo myservo;

int ENA = 11;
int IN1 = 9;
int IN2 = 8;
int ENB = 5;
int IN3 = 7;
int IN4 = 6;
int velA = 90; //ajuste de velocidade (motor IN1,IN2)
int velB = 119; //ajuste de velocidade (motor IN3,IN4)
char leitor;

void setup() {
  pinMode(ENA, OUTPUT);
  pinMode(IN1, OUTPUT);
  pinMode(IN2, OUTPUT);
  pinMode(ENB, OUTPUT);
  pinMode(IN3, OUTPUT);
  pinMode(IN4, OUTPUT);
  MinhaSerial.begin(9600);
  myservo.attach(SERVO_PIN_B); //pino 10
  myservo.write(130); //posição inicial do servo
}

void loop() {
  if (MinhaSerial.available()) {
    leitor = MinhaSerial.read();
    if (leitor == 'w') {
      frente();
    } else if (leitor == 's') {
      re();
    } else if (leitor == 'a') {
      esquerda();
    } else if (leitor == 'd') {
      direita();
    } else if (leitor == 'p') {
      parar();
    } else if (leitor == 'b') {
      myservo.write(130);
    } else if (leitor == 'x') {
      myservo.write(180);
    }
  }
}

void parar() {
  analogWrite(ENA, 0);
  digitalWrite(IN1, LOW);
  digitalWrite(IN2, LOW);
  analogWrite(ENB, 0);
  digitalWrite(IN3, LOW);
  digitalWrite(IN4, LOW);
}

void frente() {
  analogWrite(ENA, velA);
  digitalWrite(IN1, HIGH);
  digitalWrite(IN2, LOW);
  analogWrite(ENB, velB);
  digitalWrite(IN3, HIGH);
  digitalWrite(IN4, LOW);
}

void re() {
  analogWrite(ENA, velA);
  digitalWrite(IN2, HIGH);
  digitalWrite(IN1, LOW);
  analogWrite(ENB, velB);
  digitalWrite(IN4, HIGH);
  digitalWrite(IN3, LOW);
}

void esquerda() {
  analogWrite(ENA, velA);
  digitalWrite(IN2, HIGH);
  digitalWrite(IN1, LOW);
  analogWrite(ENB, velB);
  digitalWrite(IN3, HIGH);
  digitalWrite(IN4, LOW);
}

void direita() {
  analogWrite(ENA, velA);
  digitalWrite(IN1, HIGH);
  digitalWrite(IN2, LOW);
  analogWrite(ENB, velB);
  digitalWrite(IN4, HIGH);
  digitalWrite(IN3, LOW);
}
