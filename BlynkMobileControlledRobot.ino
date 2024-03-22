#define BLYNK_TEMPLATE_ID "Insert Blyk template id" //Enter Blynk template id
#define BLYNK_TEMPLATE_NAME "Insert Blyk template name" //Enter Blynk template name
#define BLYNK_AUTH_TOKEN "Insert Blynk Authen token here" //Enter Blynk auth token
#define BLYNK_PRINT Serial
#include <WiFi.h>
#include <WiFiClient.h>
#include <BlynkSimpleEsp32.h>

// Define the motor pins
#define ENA 18
#define IN1 5
#define IN2 16
#define IN3 25
#define IN4 27
#define ENB 33
 
bool forward = 0;
bool backward = 0;
bool left = 0;
bool right = 0;
int Speed;
char auth[] = "Insert Blynk Authen token here"; //Enter your Blynk auth token
char ssid[] = "Insert Wifi ID here"; // Enter Wifi ID here
char pass[] = "Insert Wifi password here"; //Enter Wifi password here

void setup() {
  Serial.begin(115200);
  pinMode(ENA, OUTPUT);
  pinMode(IN1, OUTPUT);
  pinMode(IN2, OUTPUT);
  pinMode(IN3, OUTPUT);
  pinMode(IN4, OUTPUT);
  pinMode(ENB, OUTPUT);
  Blynk.begin(auth, ssid, pass);
}
 
BLYNK_WRITE(V0) {
  forward = param.asInt();
}
 
BLYNK_WRITE(V1) {
  backward = param.asInt();
}
 
BLYNK_WRITE(V2) {
  left = param.asInt();
}
 
BLYNK_WRITE(V3) {
  right = param.asInt();
}
 
BLYNK_WRITE(V4) {
  Speed = param.asInt();
}
 
void smartcar() {
  if (forward == 1) {
    carforward();
  } else if (backward == 1) {
    carbackward();
  } else if (left == 1) {
    carturnleft();
  } else if (right == 1) {
    carturnright();
  } else if (forward == 0 && backward == 0 && left == 0 && right == 0) {
    carStop();
  }
}
void loop() {
  Blynk.run();
  smartcar();
}
 
void carforward() {
  analogWrite(ENA, Speed);
  analogWrite(ENB, Speed);
  digitalWrite(IN1, LOW);
  digitalWrite(IN2, HIGH);
  digitalWrite(IN3, LOW);
  digitalWrite(IN4, HIGH);
}
void carbackward() {
  analogWrite(ENA, Speed);
  analogWrite(ENB, Speed);
  digitalWrite(IN1, HIGH);
  digitalWrite(IN2, LOW);
  digitalWrite(IN3, HIGH);
  digitalWrite(IN4, LOW);
}
void carturnleft() {
  analogWrite(ENA, Speed);
  analogWrite(ENB, Speed);
  digitalWrite(IN1, LOW);
  digitalWrite(IN2, HIGH);
  digitalWrite(IN3, HIGH);
  digitalWrite(IN4, LOW);
}
void carturnright() {
  analogWrite(ENA, Speed);
  analogWrite(ENB, Speed);
  digitalWrite(IN1, HIGH);
  digitalWrite(IN2, LOW);
  digitalWrite(IN3, LOW);
  digitalWrite(IN4, HIGH);
}
void carStop() {
  digitalWrite(IN1, LOW);
  digitalWrite(IN2, LOW);
  digitalWrite(IN3, LOW);
  digitalWrite(IN4, LOW);
}
