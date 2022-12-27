#include <IRremote.h>

#include "RemoteCodes.h"

#define IR_RECEIVE_PIN 4
#define IR_SEND_PIN 2

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  Serial.print(F("Ready to send IR signals at pin "));
  Serial.println(IR_SEND_PIN);
  
  IrSender.begin(IR_SEND_PIN);
}

void loop() {
  IrSender.sendNEC(0, BRIGHT_UP, 1);
  Serial.println("Sending");
  delay(1000);
}
