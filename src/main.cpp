#include <Arduino.h>
#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>
#include <Adafruit_MLX90614.h>

#define CLOCK A5
#define DATA A4
#define laser A0
#define ON 1
#define OFF 0
#define ValueMax 256

Adafruit_SSD1306 display = Adafruit_SSD1306(128, 32, &Wire);
Adafruit_MLX90614 mlx = Adafruit_MLX90614();

double temp = 0;

void display_oled(double temp){
  display.setCursor(0, 0);
  display.clearDisplay();
  display.println("Nhiet do:");
  display.setCursor(12, 16);
  display.print(temp);
  display.print(" Do C");
  display.display();
}

void setup() {
  Wire.begin();
  Serial.begin(115200);
  display.begin(SSD1306_SWITCHCAPVCC, 0x3C);
  mlx.begin();
  pinMode(laser, OUTPUT);
  analogWrite(laser, ValueMax);

  delay(1000);

  display.clearDisplay();
  display.setTextSize(2);
  display.setTextColor(SSD1306_WHITE);

  
  
}

void loop() {
  Serial.print("Ambient = "); 
  Serial.print(mlx.readAmbientTempC()); 
  Serial.print("*C\tObject = "); 
  Serial.print(mlx.readObjectTempC());
  Serial.println();
  display_oled(mlx.readObjectTempC());
  delay(100);
  // display.print("A");
  // delay(10);
  // yield();
  // display.display();
  /* Scanning i2c device*/
//  byte err, adr;
//  int number_of_devices = 0;
//  Serial.println("Scanning...");
//  for (adr = 1; adr < 127; adr++){
//   Wire.beginTransmission(adr);
//   err = Wire.endTransmission();
//   if (err == 0){
//     Serial.print("I2C device at address 0x");
//     Serial.println(adr, HEX);
//     number_of_devices++;
//   }
//   else if (err == 4){
//     Serial.print("Unknown error at address 0x");
//     Serial.println(adr, HEX);
//   }
//  }
//  if (number_of_devices == 0){
//   Serial.println("No I2C device attached");
//  }
//  else {
//   Serial.println("DONE");
//  }
//  delay(5000);
//------------------

}

