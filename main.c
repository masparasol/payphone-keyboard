#include <Keyboard.h>

//Pin layout here
const int rowPin0 = 0;
const int rowPin1 = 1;
const int rowPin2 = 2;
const int rowPin3 = 3;
const int columnPin0 = 4;
const int columnPin1 = 5;
const int columnPin2 = 6;


void setup(){
    pinMode(rowPin0, OUTPUT);
    digitalWrite(rowPin0, HIGH);
    pinMode(rowPin1, OUTPUT);
    digitalWrite(rowPin1, HIGH);
    pinMode(rowPin2, OUTPUT);
    digitalWrite(rowPin2, HIGH);
    pinMode(rowPin3, OUTPUT);
    digitalWrite(rowPin3, HIGH);
    pinMode(columnPin0, INPUT_PULLUP);
    
    pinMode(columnPin1, INPUT_PULLUP);
    
    pinMode(columnPin2, INPUT_PULLUP);
    
}

void loop(){
  // Do row 0
  digitalWrite(rowPin0, LOW);
  digitalWrite(rowPin1, HIGH);
  digitalWrite(rowPin2, HIGH);
  digitalWrite(rowPin3, HIGH);

  if (digitalRead(columnPin0) == LOW){
    Keyboard.set_key1(KEY_1);
  } else {
    Keyboard.set_key1(0);
  }
  Keyboard.send_now();

  if (digitalRead(columnPin1) == LOW){
    Keyboard.set_key1(KEY_2);
  } else {
    Keyboard.set_key1(0);
  }
  Keyboard.send_now();


    if (digitalRead(columnPin2) == LOW){
    Keyboard.set_key1(KEY_3);
  } else {
    Keyboard.set_key1(0);
  }
  Keyboard.send_now();

  // Do row 1
  digitalWrite(rowPin0, HIGH);
  digitalWrite(rowPin1, LOW);
  digitalWrite(rowPin2, HIGH);
  digitalWrite(rowPin3, HIGH);

  if (digitalRead(columnPin0) == LOW){
    Keyboard.set_key1(KEY_4);
  } else {
    Keyboard.set_key1(0);
  }
  Keyboard.send_now();

  if (digitalRead(columnPin1) == LOW){
    Keyboard.set_key1(KEY_5);
  } else {
    Keyboard.set_key1(0);
  }
  Keyboard.send_now();


    if (digitalRead(columnPin2) == LOW){
    Keyboard.set_key1(KEY_6);
  } else {
    Keyboard.set_key1(0);
  }
  Keyboard.send_now();

  // Do row 2
  digitalWrite(rowPin0, HIGH);
  digitalWrite(rowPin1, HIGH);
  digitalWrite(rowPin2, LOW);
  digitalWrite(rowPin3, HIGH);

  if (digitalRead(columnPin0) == LOW){
    Keyboard.set_key1(KEY_7);
  } else {
    Keyboard.set_key1(0);
  }
  Keyboard.send_now();

  if (digitalRead(columnPin1) == LOW){
    Keyboard.set_key1(KEY_8);
  } else {
    Keyboard.set_key1(0);
  }
  Keyboard.send_now();

    if (digitalRead(columnPin2) == LOW){
    Keyboard.set_key1(KEY_9);
  } else {
    Keyboard.set_key1(0);
  }
  Keyboard.send_now();

delay(120);

}