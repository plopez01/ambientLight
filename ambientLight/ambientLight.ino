#include <IRremote.h>

#include "RemoteCodes.h"

#define IR_SEND_PIN 2

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  Serial.print(F("Ready to send IR signals at pin "));
  Serial.println(IR_SEND_PIN);
  
  IrSender.begin(IR_SEND_PIN);
}

void loop() {
  int incomingByte = 0;
  
  if (Serial.available() > 0) {
    // read the incoming byte:
    incomingByte = Serial.parseInt();
    if(incomingByte > 0) {
      send_command(incomingByte);
    }
  }
}

void blink_soft(int stepTime){
  for (int i = 0; i < 4; i++) {
    send_command(BRIGHT_UP);
    delay(stepTime);
  }

  for (int i = 0; i < 4; i++) {
    send_command(BRIGHT_DOWN);
    delay(stepTime);
  }
}

void send_command(int command){
  IrSender.sendNEC(0, command, 2);
  Serial.print("Sending 0x");
  Serial.println(command, HEX);
}
