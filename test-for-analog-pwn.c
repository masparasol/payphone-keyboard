//This file should read voltage values from the Teensy

#include <Keyboard.h>

int ledPin=12;
int analogPin=20;          
int val;

void setup()
{      
pinMode(ledPin, OUTPUT);
}

void loop()                     
{
  analogWrite(ledPin, 250);
  delay(10);
  val = analogRead(analogPin);
  
  //Keyboard.println(0);
  
  analogWrite(ledPin, 0);

Keyboard.println(val);

delay(230);
// if ( analogRead(20) 
// {
// Keyboard.set_key1(KEY_Z);
// Keyboard.send_now();
// }
// else
// {
// Keyboard.set_key1(0);
// Keyboard.send_now();
// }


 }
  
