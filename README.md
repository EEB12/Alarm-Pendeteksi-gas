# Alarm Pendeteksi Gas
pada tugas NCC mengenai Arduino kali ini ide saya adalah pendeteksi gas. dulu terdapat kasus dimana orang meninggal karena ketika menyalakan motor lalu ditinggal tidur. 
Gas CO sangatlah susah dibedakan dengan O2. Pada alat pendeteksi yang saya buat ini, jika mendeteksi gas carbon monoksida maka buzzer akan berbunyi dengan keras dan layar LCD akan menampilkan 
udara yang tidak bersih. Berikut adalah skema arduino dari pendeteksi gas.

![alt text](https://github.com/EEB12/Alarm-Pendeteksi-gas/blob/main/Arduino/skema.JPG?raw=true "Ilustrasi" )

cara kerja dari sensor gasnya adalah ketika oksigen tertangkap oleh sensor tersebut maka elektron akan ditarik oleh oksigen tetapi ketika terdapat
gas yang mudah terbakar maka oksigen tersebut akan tertarik dan elektron akan terlepas ke timah dioksida

![alt text](https://lastminuteengineers.com/wp-content/uploads/arduino/MQ2-Gas-Sensor-Working.gif?raw=true "Ilustrasi" )

## Komponen

* Arduino Uno R3
* LCD 16 X 2
* Sensor gas MQ-9
* Piezo
* Resistor 4.7KΩ
* Resistor 1 KΩ
* Resistor 100 Ω
* LED merah
* LED hijau

## Source Code
pada tahapan implementasi dibutuhkan  ``#include <LiquidCrystal.h>`` untuk Layar LCD. lalu untuk menginisiasi LCD menggunakan
``LiquidCrystal lcd(5,6,8,9,10,11);``. Setelah menginisiasi LCD selanjutnya adalah menginisiasi untuk komponen lain

```C
#include <LiquidCrystal.h>
LiquidCrystal lcd(5,6,8,9,10,11); // menginisiasi pin berapa aja untuk lcd

int redled=3;	//pin output untuk led merah
int greenled=2;	// pin output untuk led hijau
int buzzer=4;	// pin output untuk buzzer
int sensor= A0;	// pin input untuk sensor
int sensorThresh=380; // batasan untuk sensor
```

Kemudian kita setup mode untuk tiap komponen yang sudah diinisiasi diatas. untuk lampu LED dan buzzer dijadikan sebagai output sedangkan untuk sensor kita buat sebagai input.

```C
void setup()
{
pinMode(redled,OUTPUT);		//mengatur mode led merah
pinMode(greenled,OUTPUT);	//mengatur mode led hijau
pinMode(buzzer,OUTPUT);		// mengatur mode buzzer
pinMode(sensor,INPUT);		// mengatur mode sensor asap
Serial.begin(9600);
lcd.begin(16,2);
}


```
Kemudian pada fungsi Loop adalah seperti berikut. kita buat value dari variabel analogValue adalah hasil input dari sensor. lalu kita buat permisalan jika analog value melewati 
Pembatas maka LED warna merah akan menyala dan LED hijau menjadi redup. Buzzer akan menyala dan tampilan LCD akan menampilkan "GAS TERDETEKSI" dan "BAHAYA". jika tidak melewati maka
LED hijau menyala dengan terang dan buzzer tidak akan berbunyi.

```C
void loop()
{
int analogValue= analogRead(sensor);
Serial.print(analogValue);
Serial.print("\n");
if(analogValue>sensorThresh) // jika value analog melebihi batasan 
{
  
digitalWrite(redled,HIGH);	//menyalakan led merah
digitalWrite(greenled,LOW); 	// mematikan led hijau
tone(buzzer,1000,10000);	//membunyikan buzzer
lcd.clear();			//clear tampilan LCD
lcd.setCursor(0,1);		//cursor diatur ke baris ke 0 dan kolom ke satu
lcd.print("GAS TERDETEKSI");	//ngeprint "gas terdeteksi"
delay(1000);			//dikasih delay selama 1 detik
lcd.clear();
lcd.setCursor(0,1);
lcd.print("BAHAYA");
delay(1000);
}
else				//jika tidak ada gas
{
digitalWrite(greenled,HIGH);	//lampu hijau akan menyala
digitalWrite(redled,LOW);
noTone(buzzer);			//tidak ada suara
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
```

