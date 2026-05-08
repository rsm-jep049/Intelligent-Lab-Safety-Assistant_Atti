#include <Keyboard.h>
#include <SoftwareSerial.h>
SoftwareSerial bluetooth(8,9);
void setup() {
  Serial.begin(9600);
  bluetooth.begin(9600);
  Keyboard.begin();
 
  // put your setup code here, to run once:
}
void loop() {
  if(bluetooth.available()){
    //Serial.write(bluetooth.read());
    char data=bluetooth.read();
    Serial.write(data);
    Serial.println();

    if(data=='1')
    {
      Keyboard.press(KEY_LEFT_CTRL);
      Keyboard.press(KEY_LEFT_ALT);
      Keyboard.press('f');
      Keyboard.releaseAll();
      delay(2000);
    }
    else if(data=='2')
    {
      Keyboard.press(KEY_LEFT_CTRL);
      Keyboard.press(KEY_LEFT_ALT);
      Keyboard.press('g');
      Keyboard.releaseAll();
    }    
  }
  if(Serial.available()){
    bluetooth.write(Serial.read());
  }
  // put your main code here, to run repeatedly:
}
