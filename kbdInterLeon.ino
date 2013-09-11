#include <Wire.h>

void setup() {
  Keyboard.begin();
  Wire.begin(4);                // join i2c bus with address #4
  Wire.onReceive(receiveEvent); // register event
}

void loop() {
  //
}

char getSendKey(char in){
   switch(in){
     case 1: return 'a';
   }
}

void receiveEvent(int howMany)
{
  while(Wire.available()) // loop through all but the last
  {
    char mode = Wire.read(); // receive byte as a character
    unsigned char key = Wire.read(); // receive byte as a character    
    if (mode == 0){ //press
      //Keyboard.press(Wire.read());
      char buffer[50];
      sprintf(buffer, "Press: %d", key);
      Keyboard.println(buffer);
    }
    if (mode == 1){ //release
      char buffer[50];
      sprintf(buffer, "Release: %d", key);
      Keyboard.println(buffer);
    }    
  }

}
