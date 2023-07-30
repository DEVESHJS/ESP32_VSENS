

#define BLYNK_PRINT Serial

#include <WiFi.h>
#include <WiFiClient.h>
 
#define vCalibration 83.3
#define currCalibration 0.50
int led=23;
int leds;
int rel=13;
int rel2=12;
 
char auth[] = "ywgi-9wMDYDrKZ6kbhJFJgWZH1Vs4a1w";
char ssid[] = "Santharaj";
char pass[] = "devesh@12345";
 
void setup()
{
  pinMode(led,OUTPUT);
  pinMode(rel,OUTPUT);
  pinMode(rel2,OUTPUT);
  Serial.begin(115200);
  delay(1000);
}
 
void loop()
{
  leds=analogRead(4);
  int v_value=analogRead(34);
  int len = log10(v_value);
  if(leds<755)
  {
    digitalWrite(led,HIGH);
    digitalWrite(rel,LOW);
    digitalWrite(rel2,HIGH);
  }
  else
  {
    digitalWrite(led,LOW);
    digitalWrite(rel,HIGH);
    digitalWrite(rel2,LOW);
  }
  //float div = pow(10, len);
  //int rounded = ceil(v_value / div) * div;
  //float rounded = round(v_value / 10) * 10;
  Serial.print(v_value);
  Serial.println(leds);
  delay(500);
}