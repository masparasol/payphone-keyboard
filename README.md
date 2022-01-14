# Readme for Payphone Keyboard Projects

  - A board is attached to the back of the red payphone keys with matrix wiring by Jaguar
  - The wires go to a teensy chip on a breadboard
  - We use arduino with a teensy extension/library to run c code
  - The c code uses the teensy digital pins. It sets one row to LOW at a time, and then checks for which column on which row is low. In this way, the keys can be identified. See final.ccp
  - To push to Teensy (flash Teensy) code can be compiled in the ariduino ide, then press the reset button as in the above youtube video ( https://www.youtube.com/watch?v=H4fkLxeXRiA& )
  - The teensy currently takes the keypress and runs the logic to either open the door or keep it closed

Teensy also has an inbuilt debounce function we plan to use in 2022.

For more info, see the Noisebridge Wikipage for the phone:
https://www.noisebridge.net/wiki/Payphone

This looks like a good starting point for getting the Teensy to play audio:
https://forum.pjrc.com/threads/27372-Playing-audio-files-from-Teensy-on-board-memory?p=60614&viewfull=1

## Contributors
- Jaguar for the board, teensy, soldering, and research
- Claus for helping with hardware, software, and championing the project
- Ryan L for software
- Woz for mapping things out and software / hardware strategy
- Mana for the digital pin idea
- Patrick for C programming help

Thank You! ***
