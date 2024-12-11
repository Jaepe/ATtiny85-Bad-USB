# ATtiny85 Bad USB
This is a project to get an ATtiny85 working as a Bad USB, also known as a Rubber Ducky.
This will cover V-USB, micronucleus, and include basic payloads.
# Micronucleus
[Micronucleus](https://github.com/micronucleus/micronucleus) is a bootloader for AVR ATtiny boards.
## For the ATtiny85
I am recalling this from memory at the time being, so some details may be wrong. I will update this when I look more into it again.
To get the ATtiny85 to work as a keyboard with the DigiKeyboard library you have to downgrade the Micronucleus bootloader, this is because in the newer verison they removed the abality to make it act as a HID since it causes more issues than it solved.
# Arduino IDE
- Add `https://raw.githubusercontent.com/ArminJo/DigistumpArduino/refs/heads/master/package_digistump_index.json` to additional boards in preferences.
- Select the board as the Digispark
- Load any of the ino files or write your own payloads.
- Hit the upload button then plug the USB in. You will have to unplug and replug it in if its already plugged in.
