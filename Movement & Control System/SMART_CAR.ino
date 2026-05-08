//#include <Servo.h>
#include <SoftwareSerial.h> 
//Servo servo;
int value =0;
#define ENA 6  //pwm
#define EN1 7
#define EN2 3

#define ENB 5
#define EN3 4
#define EN4 2

int DELAY = 10;
int Speed_PWM = 180; //초기속도 제어 0-255

void GO() {
 //Serial.print("success");
  digitalWrite(EN1, HIGH); // 정방향 회전 
  digitalWrite(EN2, LOW); // 정방향 회전
  analogWrite(ENA, Speed_PWM); // 최고 속도
  digitalWrite(EN3, HIGH); // 정방향 회전
  digitalWrite(EN4, LOW); // 정방향 회전
  analogWrite(ENB, Speed_PWM); // 최고 속도
}
void BACK() {
  digitalWrite(EN1, LOW); // 역방향 회전
  digitalWrite(EN2, HIGH); // 역방향 회전
  digitalWrite(EN3, LOW); // 역방향 회전
  digitalWrite(EN4, HIGH); // 역방향 회전
  analogWrite(ENA, Speed_PWM); // 최고 속도
  analogWrite(ENB, Speed_PWM); // 최고 속도
}
void LEFT() {
  digitalWrite(EN1, LOW); // left_wheel
  digitalWrite(EN2, HIGH); // left_wheel
  digitalWrite(EN3, HIGH); // right_wheel
  digitalWrite(EN4, LOW); // right_wheel
  analogWrite(ENA, Speed_PWM); // 최고 속도
  analogWrite(ENB, Speed_PWM); // 최고 속도
}
void RIGHT() {
  digitalWrite(EN1, HIGH); // left_wheel
  digitalWrite(EN2, LOW); // left_wheel
  digitalWrite(EN3, LOW); // right_wheel
  digitalWrite(EN4, HIGH); // right_wheel
  analogWrite(ENA, Speed_PWM); // 최고 속도
  analogWrite(ENB, Speed_PWM); // 최고 속도
}

void STOP() {  
  digitalWrite(EN1, HIGH); // BREAK 정지
  digitalWrite(EN2, HIGH); // 
  digitalWrite(EN3, HIGH); // 
  digitalWrite(EN4, HIGH); // 
}

//13번 핀의 출력을 알 수 있도록 보드에 LED가 내장되어 있으므로 LED핀 번호를 13번으로 바꿔 동작 체크
void setup() {
  pinMode(EN1, OUTPUT); // 방향 핀
  pinMode(EN2, OUTPUT); // 방향 핀
  pinMode(ENA, OUTPUT); // 속도 조절
  pinMode(EN3, OUTPUT); // 방향 핀
  pinMode(EN4, OUTPUT); // 방향 핀
  pinMode(ENB, OUTPUT); // 속도 조절
  Serial.begin(9600);
  Serial1.begin(9600); 
}

void loop() {
  char inx2;
  if(Serial1.available()){
    inx2=Serial1.read();
    Serial.write(inx2);
    switch(inx2){
      case '1':
        GO();
        delay(400);
        STOP();
        break;
      case '2':
        GO();
        delay(800);
        STOP();
        break;
      case '3':
        GO();
        delay(1300);
        STOP();
        break;
      case '4':
        GO();
        delay(1300);
        LEFT();
        delay(450);
        GO();
        delay(900);
        LEFT();
        delay(550);
        GO();
        delay(300);
        STOP();
        break;
      case '5':
        GO();
        delay(1300);
        LEFT();
        delay(500);
        GO();
        delay(900);
        LEFT();
        delay(550);
        GO();
        delay(500);
        STOP();
        break;
        break;
    }
  }
}
