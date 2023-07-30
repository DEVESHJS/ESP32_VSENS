#include "EmonLib.h"        

#define VOLT_CAL 112
int rel=13;
int rel2=12;
EnergyMonitor emon1;             

void setup()
{  
  Serial.begin(9600);
  pinMode(rel,OUTPUT);
  pinMode(rel2,OUTPUT);
  emon1.voltage(34, VOLT_CAL, 1.7);  
}

void loop()
{
  emon1.calcVI(25,1000);         
  digitalWrite(rel,LOW);
  digitalWrite(rel2,LOW);
  float supplyVoltage   = emon1.Vrms;             
  if(supplyVoltage >= 100)
  {
 Serial.print("Voltage : ");  
 Serial.println(supplyVoltage);
  }
  else
 {
   Serial.println("Power OFF");
 }
 }