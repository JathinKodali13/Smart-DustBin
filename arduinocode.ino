#include <Servo.h>

Servo myservo;
int trigPin = 9;
int echoPin = 10;
long duration;
int distance;

void setup() {
  myservo.attach(3);
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
  Serial.begin(9600);
  myservo.write(0); // Lid closed
}

void loop() {
  // Send ultrasonic pulse
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);

  // Measure echo time
  duration = pulseIn(echoPin, HIGH);
  distance = duration * 0.034 / 2; // convert to cm

  Serial.print("Distance: ");
  Serial.println(distance);

  if (distance < 15) { // Object detected within 15cm
    myservo.write(90); // Open lid
    delay(2000);       // Wait 2 seconds
    myservo.write(0);  // Close lid
  }

  delay(200);
}
