#include <DHT.h>
#define DHTPIN 4
//#define DHTPIN5 5
#define DHTTYPE DHT11
DHT dht(DHTPIN,DHTTYPE);
//DHT dht5(DHTPIN5,DHTTYPE);
#include <SoftwareSerial.h>
const int AOUTpin=A0;//the AOUT pin of the alcohol sensor goes into analog pin A0 of the arduino
//const int aoutpin=A1;
int value;

SoftwareSerial bluetooth(2, 3);
void setup() 

{

  Serial.begin(9600);

  bluetooth.begin(9600);

}

void loop()

{
  delay(2000);
  int h = dht.readHumidity(); 
  int t = dht.readTemperature();
//  Serial.print("Humidity: ");  // 문자열 Humidity: 를 출력한다.
//  Serial.print(h);  // 변수 h(습도)를 출력한다.
//  Serial.print(" ");
//  Serial.print("Temperature: ");
//  Serial.print(t);
//  Serial.print(" ");
//  bluetooth.print((int)h);
//  bluetooth.print(" ");
//  bluetooth.println((int)t);
  if(t>20){
    Serial.println("first table is in fire");
  }

//  int a = dht5.readHumidity(); 
//  int b = dht5.readTemperature();
//  Serial.print("Humidity: ");  // 문자열 Humidity: 를 출력한다.
//  Serial.print(a);  // 변수 h(습도)를 출력한다.
//  Serial.print(" ");
//  Serial.print("Temperature: ");
//  Serial.println(b);
//  bluetooth.print((int)a);
//  bluetooth.print(" ");
//  bluetooth.println((int)b);
  
  value= analogRead(AOUTpin);//reads the analaog value from the alcohol sensor's AOUT pin
  if(value>10){
//Serial.print("Alcohol value: ");
  Serial.write("Gas is leaking in third table");
  }
//bluetooth.println(value);
  
//  value= analogRead(aoutpin);//reads the analaog value from the alcohol sensor's AOUT pin
//  Serial.print("Alcohol value: ");
//  Serial.println(value);//prints the alcohol value
//  bluetooth.println(value);
  delay(1000);
}


