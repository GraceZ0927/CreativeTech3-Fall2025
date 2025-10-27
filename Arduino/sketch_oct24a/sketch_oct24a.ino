#include "config.h"
#define POT_PIN A2

AdafruitIO_Feed *potFeed = io.feed("potentiameter");

void setup() {
  // put your setup code here, to run once:
  pinMode(POT_PIN,INPUT);

  Serial.begin(115200);

  while(! Serial);

  Serial.print("Connecting to Adafruit IO");
  io.connect();

  while(io.status() < AIO_CONNECTED) {
    Serial.print(".");
    delay(500);
  }
  Serial.println();
  Serial.println(io.statusText());
}

void loop() {
  io.run();
  // put your main code here, to run repeatedly:
  float current = analogRead(POT_PIN);
  Serial.print("sending -> ");
  Serial.println(current);
  potFeed->save(current);

  delay(3000);
}
