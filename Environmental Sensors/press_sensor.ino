int sensorPin = 0; // sensorPin은 센서에 연결한 analogpin0
int ledPin = 9; // ledPin은 LED에 연결한 9번핀
void setup() {
  pinMode(ledPin, OUTPUT); //ledpin을 출력으로 설정
}
void loop() {

  int value = analogRead(sensorPin); //센서값을 읽어들인다.

  //읽어들인 센서값으로 LED밝기를 조정

  int intensity = map(value, 0, 1023, 0, 255); 

  analogWrite(ledPin, intensity);
  delay(10); //10초 동안 대기

}

