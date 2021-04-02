#include <LiquidCrystal.h>
LiquidCrystal lcd(5,6,8,9,10,11); // menginisiasi pin berapa aja untuk lcd

int redled=3;	//pin output untuk led merah
int greenled=2;	// pin output untuk led hijau
int buzzer=4;	// pin output untuk buzzer
int sensor= A0;	// pin input untuk sensor
int Pembatas=380; // batasan untuk sensor
void setup()
{
pinMode(redled,OUTPUT);		//mengatur mode led merah
pinMode(greenled,OUTPUT);	//mengatur mode led hijau
pinMode(buzzer,OUTPUT);		// mengatur mode buzzer
pinMode(sensor,INPUT);		// mengatur mode sensor asap
Serial.begin(9600);
lcd.begin(16,2);
}


void loop()
{
int analogValue= analogRead(sensor);
Serial.print(analogValue);
Serial.print("\n");
if(analogValue>Pembatas) // jika value analog melebihi batasan 
{
  
digitalWrite(redled,HIGH);	//menyalakan led merah
digitalWrite(greenled,LOW); // mematikan led hijau
tone(buzzer,1000,10000);	//membunyikan buzzer
lcd.clear();				//
lcd.setCursor(0,1);
lcd.print("GAS TERDETEKSI");
delay(1000);
lcd.clear();
lcd.setCursor(0,1);
lcd.print("BAHAYA");
delay(1000);
}
else
{
digitalWrite(greenled,HIGH);
digitalWrite(redled,LOW);
noTone(buzzer);
lcd.clear();
lcd.setCursor(0,0);
lcd.print("Aman");
delay(1000);
lcd.clear();
lcd.setCursor(0,1);
lcd.print("tidak ada gas");
delay(1000);
}
}
  
  