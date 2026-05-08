#include <SoftwareSerial.h>
SoftwareSerial voiceSerial(8, 7);   // Rx, Tx
SoftwareSerial bluetooth(12,13);
char id, accuracy;
void setup()
{  
  Serial.begin(9600);
  bluetooth.begin(9600);
  voiceSerial.begin(9600);
  voiceSerial.listen();
}

void loop()
{  
  if (voiceSerial.available() > 0) 
  {
    id       = voiceSerial.read();
    //Serial.println(id);
   // accuracy = voiceSerial.read();
    switch (id) 
    {
      case '0':
        //Serial.println("1번 테이블 ");
        Serial.write('1');
        bluetooth.write('1');
        break;
      case '1':
        //Serial.println("2번 테이블 ");
        Serial.write('2');
        bluetooth.write('2');
        break;
      case '2':
        //Serial.println("3번 테이블 ");
        Serial.write('3');
        bluetooth.write('3');
        break;
      case '3':
       // Serial.println("4번 테이블 ");
        Serial.write('4');
        bluetooth.write('4');
        break;
      case '4':
        //Serial.println("5번 테이블 ");
        Serial.write('5');
        bluetooth.write('5');
        break;
      case '5':
        Serial.write('6');
        bluetooth.write('6'); // 6번 테이블
        break;
      case '6':
        Serial.write('7'); // 발사
        bluetooth.write('7');
        break;
    }
  }
}
