# Readme for Payphone Keyboard Projects

  - Aboard is attached to the back of the red payphone keys with matrix wiring by Jaguar
  - The wires go to a teensy chip on a breadboard
  - We use arduino with a teensy extension/library to run c code
  - We also use the keyboard library as in this video: 
  https://www.youtube.com/watch?v=H4fkLxeXRiA&
  - The c code uses the teensy digital pins. It sets one row to LOW at a time, and then checks for which column on which row is low. In this way, the keys can be identified. See final.ccp
  - To push to Teensy (flash Teensy) code can be compiled in the ariduino ide, then press the reset button as in the above youtube video ( https://www.youtube.com/watch?v=H4fkLxeXRiA& )
  - This page from Teensy has all the keyboard functions. Looks nice! :D We can map the keys to anything. (https://www.pjrc.com/teensy/td_keyboard.html)


Since we are using ardiduino software to drive this thing in C we should use the debounce function here
https://www.youtube.com/watch?v=jYOYgU2vlSE

I will try add that to the code on Friday 12/02/2021 
Please wish me luck : )

## Contributors
- Jaguar for the board, teensy, soldering, and research
- Claus for helping with hardware, software, and championing the project
- Ryan L for software
- Woz for mapping things out and software / hardware strategy
- Mana for the digital pin idea
- Patrick for C programming help
