#include <DmxSimple.h>

int DMX_dir = 4;

byte rgb[] = { 0, 0, 0 };
byte ctr = 0;

void setup() {
  Serial.begin(115200);
  
  pinMode(DMX_dir, OUTPUT);
  digitalWrite(DMX_dir, HIGH);
  
  DmxSimple.usePin(2);
  DmxSimple.write((int) 1, (int) 81);
  
  updateColors();
}

void loop() {
  while (Serial.available()) {
    byte b = Serial.read();
    if (b != 1) {
      rgb[ctr++] = b;
      ctr %= 3;
    } else {
      ctr = 0;
      updateColors();
      Serial.write(32);
    }
  }
}

void updateColors() {
  DmxSimple.write((int) 3, (uint8_t) rgb[0]);
  DmxSimple.write((int) 4, (uint8_t)rgb[1]);
  DmxSimple.write((int) 5, (uint8_t)rgb[2]);
}

