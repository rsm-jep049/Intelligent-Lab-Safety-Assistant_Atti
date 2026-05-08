#include <DHT.h>
#define DHTPIN4 4
#define DHTPIN5 5
#define DHTPIN6 6
#define DHTPIN7 7
#define DHTTYPE DHT11
DHT dht4(DHTPIN4,DHTTYPE);
DHT dht5(DHTPIN5,DHTTYPE);
DHT dht6(DHTPIN6,DHTTYPE);
DHT dht7(DHTPIN7,DHTTYPE);
#include <SoftwareSerial.h>
/*const int AOUTpin=A0;//the AOUT pin of the alcohol sensor goes into analog pin A0 of the arduino가스감지센서
const int aoutpin=A1;
const int aoutpin2=A2;*/
SoftwareSerial bluetooth(2, 3);  //(tx,rx순서)
void setup() 
{
  Serial.begin(9600);
  bluetooth.begin(9600);
}
void loop()
{
  delay(2000);
  int temp1 = dht4.readTemperature();
    if(temp1>32){
     Serial.println("Fire - Table 1");  
      bluetooth.write('1');
      }
  int temp2 = dht5.readTemperature();
   if(temp2>32){
     Serial.println("Fire - Table 2");  
     bluetooth.write('2');
     }
  int temp3 = dht6.readTemperature();
   if(temp3>32){
    Serial.println("Fire - Table 3");  
    bluetooth.write('3');
    }
  int temp4 = dht7.readTemperature();
    if(temp4>32){
      Serial.println("Fire - Table 4");  
     bluetooth.write('4');
     }
  /*value= analogRead(AOUTpin);//reads the analaog value from the alcohol sensor's AOUT pin
  if(value>200){
    Serial.println("Gas is leaking in second table");  
    bluetooth.write('2');
  }
  value1= analogRead(aoutpin);//reads the analaog value from the alcohol sensor's AOUT pin
  if(value1>60){
//  Serial.print("Alcohol value: ");
//  Serial.println(value);//prints the alcohol value
  Serial.println("Gas is leaking in third table");
  }
  value2= analogRead(aoutpin2);//reads the analaog value from the alcohol sensor's AOUT pin
  if(value2>240){
//  Serial.print("Alcohol value: ");
//  Serial.println("over gas!! danger!!");
  Serial.println("Gas is leaking in forth table");
  }  */
}
