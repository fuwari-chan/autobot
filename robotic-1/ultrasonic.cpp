#include <Servo.h>

int motor1Pin1 = 2; // Pin untuk motor 1

int motor1Pin2 = 3; // Pin untuk motor 2

int trigPin = 7;    // Pin trigger sensor ultrasonik

int echoPin = 6;    // Pin echo sensor ultrasonik

long duration;

int distance;

void setup() {

  pinMode(motor1Pin1, OUTPUT);

  pinMode(motor1Pin2, OUTPUT);

  pinMode(trigPin, OUTPUT);

  pinMode(echoPin, INPUT);

  Serial.begin(9600);

}

void loop() {

  digitalWrite(trigPin, LOW);

  delayMicroseconds(2);

  digitalWrite(trigPin, HIGH);

  delayMicroseconds(10);

  digitalWrite(trigPin, LOW);

  duration = pulseIn(echoPin, HIGH);

  distance = duration * 0.034 / 2;

  Serial.print("Distance: ");

  Serial.println(distance);

  if (distance > 10) {

    // Move forward

    digitalWrite(motor1Pin1, HIGH);

     digitalWrite(motor1Pin2, LOW);

  } else {

    // Stop and turn

    digitalWrite(motor1Pin1, LOW);

    digitalWrite(motor1Pin2, LOW);

    delay(500);

    // Turn right (adjust as needed)

    digitalWrite(motor1Pin1, HIGH);

    digitalWrite(motor1Pin2, HIGH);

    delay(500);

  }

}
