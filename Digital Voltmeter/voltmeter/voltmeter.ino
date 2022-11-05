//By HomeMade Electronics
//Subscribe to my channel https://www.youtube.com/channel/UC8isJR_71x1wIfw6jB106pg
//Visit website https://sirboatengonline.com
//for more tutorial videos
//like, share and leave a comment if you need help. Thank you

#include <LiquidCrystal_I2C.h>
#include <Wire.h>

// initialize the I2C LCD Library
LiquidCrystal_I2C lcd(0x38,20,4);

float voltage = 0.0;

float V=0.0;

float R1 = 100000.0; // resistance of R1 (100K)
float R2 = 10000.0; // resistance of R2 (10K)

int analog_value= 0;

void setup()
{
lcd.begin(20, 4);
lcd.setCursor (0,1);
lcd.print("HomeMade Electronics");
lcd.setCursor (0,2);
lcd.print("sirboatengonline.com");
delay(3000);
lcd.clear();
lcd.setCursor(1,1);
lcd.print("Digital Voltmeter");

}

void loop()

{

// read the value at analog input pin A0
//and store it in the variable analog_value

analog_value = analogRead(A0);

voltage = (analog_value * 5.0) / 1024.0;
V = voltage / (R2/(R1+R2));
if (V < 0.1)
{
V = 0.0;//statement to quash undesired reading !
}
// Display the voltage in the serial monitor
Serial.print ("Voltage: ");
Serial.print (V);
Serial.println (" VOLTS");
// Display the voltage in the LCD
lcd.setCursor(0, 3);
lcd.print("Voltage= ");
lcd.print(V);
lcd.setCursor(15,3);
lcd.print("VOLTS");
// Wait 0.5 seconds between the measurements
delay (500);

}
