//   #include <Keyboard.h>

//Pin layout here
const int rowPin0 = 0;
const int rowPin1 = 1;
const int rowPin2 = 2;
const int rowPin3 = 3;
const int columnPin0 = 4;
const int columnPin1 = 5;
const int columnPin2 = 6;
const int strikePin = 7;
const int keysent=0; //This will record when a key has been sent and delay
boolean buttonState = HIGH; 
char pinCode[4];
int pinIdx=0;
int resetCounter=0;
// const int delayTimeMS=80;
// const int timeDoorOpenMS=10000;

//Debounce function
boolean debounceButton(boolean state,const int currentColumn)
{
  boolean stateNow = digitalRead(currentColumn);
  if(state!=stateNow)
  {
    delay(60);
    stateNow = digitalRead(currentColumn);
  }
  return stateNow;
  
}

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

      digitalWrite(strikePin, LOW);
      
  }

  void loop(){

    // Do row 0
    digitalWrite(rowPin0, LOW);
    digitalWrite(rowPin1, HIGH);
    digitalWrite(rowPin2, HIGH);
    digitalWrite(rowPin3, HIGH);

    
    if (debounceButton(buttonState,columnPin0) == LOW && buttonState==HIGH) {
    //   Keyboard.set_key1(KEY_1);
    //   digitalWrite(strikePin, HIGH);
    pinCode[pinIdx]='1';
    pinIdx=(pinIdx+1)%4;
    } else {
      //Keyboard.set_key1(0);
    //   digitalWrite(strikePin, LOW);
    }
    

    if (debounceButton(buttonState,columnPin1) == LOW && buttonState==HIGH) {
    //   Keyboard.set_key1(KEY_2);
    pinCode[pinIdx]='2';
    pinIdx=(pinIdx+1)%4;
      
    } else {
      //Keyboard.set_key1(0);
    }
    


    if (debounceButton(buttonState,columnPin2) == LOW && buttonState==HIGH) {
      //Keyboard.set_key1(KEY_3);
    pinCode[pinIdx]='3';
    pinIdx=(pinIdx+1)%4;
    } else {
      //Keyboard.set_key1(0);
    }
    

    // Do row 1
    digitalWrite(rowPin0, HIGH);
    digitalWrite(rowPin1, LOW);
    digitalWrite(rowPin2, HIGH);
    digitalWrite(rowPin3, HIGH);

    if (debounceButton(buttonState,columnPin0) == LOW && buttonState==HIGH) {
      //Keyboard.set_key1(KEY_4);
      pinCode[pinIdx]='4';
      pinIdx=(pinIdx+1)%4;
      
    } else {
      //Keyboard.set_key1(0);
    }
    

    if (debounceButton(buttonState,columnPin1) == LOW && buttonState==HIGH) {
      //Keyboard.set_key1(KEY_5);
            pinCode[pinIdx]='5';
            pinIdx=(pinIdx+1)%4;
    } else {
      //Keyboard.set_key1(0);
    }
    


      if (debounceButton(buttonState,columnPin2) == LOW && buttonState==HIGH) {
      //Keyboard.set_key1(KEY_6);
      pinCode[pinIdx]='6';
            pinIdx=(pinIdx+1)%4;
    } else {
      //Keyboard.set_key1(0);
    }
    

    // Do row 2
    digitalWrite(rowPin0, HIGH);
    digitalWrite(rowPin1, HIGH);
    digitalWrite(rowPin2, LOW);
    digitalWrite(rowPin3, HIGH);

    if (debounceButton(buttonState,columnPin0) == LOW && buttonState==HIGH) {
      //Keyboard.set_key1(KEY_7);
      pinCode[pinIdx]='7';
            pinIdx=(pinIdx+1)%4;
    } else {
      //Keyboard.set_key1(0);
    }
    

    if (debounceButton(buttonState,columnPin1) == LOW && buttonState==HIGH) {
      //Keyboard.set_key1(KEY_8);
      pinCode[pinIdx]='8';
            pinIdx=(pinIdx+1)%4;
    } else {
      //Keyboard.set_key1(0);
    }
    

      if (debounceButton(buttonState,columnPin2) == LOW && buttonState==HIGH) {
      //Keyboard.set_key1(KEY_9);
      pinCode[pinIdx]='9';
            pinIdx=(pinIdx+1)%4;
    } else {
    //   Keyboard.set_key1(0);
    }
    
int i=0;
char codeCheck[]={'1','8','4','8'};
int correctNumberCount=0;
for (i=0; i<4; i++)
{
    if (pinCode[(pinIdx+i)%4]==codeCheck[i])
    {
        correctNumberCount++;
    }
}

if (correctNumberCount==4) {
    digitalWrite(strikePin, HIGH);

    resetCounter++;

}
else 
{
    digitalWrite(strikePin, LOW);
}
  
//Time the code is correct counter
if (resetCounter> (10000/80))
// if (resetCounter> 125)
{
    digitalWrite(strikePin, LOW);
    resetCounter=0;

    for (i=0; i<4; i++)
    {
        pinCode[i]=0;
    }
}
  
  delay(80);

  } 


  
