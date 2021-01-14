#include <dht.h>
#define button 2
#define DHT11_PIN 7
#include <Wire.h> 
#include <LiquidCrystal_I2C.h>
LiquidCrystal_I2C lcd(0x3F, 2, 1, 0, 4, 5, 6, 7, 3, POSITIVE); 
dht DHT;
#define DHT11_PIN 7
int temp = 0;
int hum = 0;
int state = 0;

void setup() {
Serial.begin(38400);
lcd.begin(16,2);
lcd.backlight();
pinMode(button, INPUT);
}

void loop() {
 
  if(Serial.available() > 0){
    state = Serial.read(); }

temp = 1;
  
 String input;
lcd.clear();

  
  
while(temp == 1){
  delay(1000);
float chk = DHT.read11(DHT11_PIN);
lcd.setCursor(0,0);
lcd.println("Temperature:        ");
Serial.print("Temperature   ");
lcd.setCursor(0,1);
lcd.print(DHT.temperature);
Serial.println(DHT.temperature);
lcd.print(" C");
if(digitalRead(button) == LOW){
  temp++;
}
}



  
while (temp == 2){
float chk = DHT.read11(DHT11_PIN);
lcd.clear();
lcd.setCursor(0,0); 
lcd.println("Humidity:        ");
Serial.print("Humidity   ");
lcd.setCursor(0,1);
lcd.print(DHT.humidity);
Serial.println(DHT.humidity);
delay(1000);
if(digitalRead(button) == LOW){
  temp--;
}
  
}

 }
