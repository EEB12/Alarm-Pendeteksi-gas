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
