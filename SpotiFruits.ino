#include <BLEMIDI_Transport.h>
#include <hardware/BLEMIDI_ESP32.h>
#include <MIDI.h>

BLEMIDI_CREATE_INSTANCE("SpotiFruits",MIDI);  

const int NUMBER_OF_TOUCH_PIN = 9;
const int touchPin[NUMBER_OF_TOUCH_PIN] = {4,2,15,13,12,14,27,33,32}; 
bool touchPinUnlock[NUMBER_OF_TOUCH_PIN];
int touchValue[NUMBER_OF_TOUCH_PIN];

const int threshold = 20;



 //MIDI_CREATE_DEFAULT_INSTANCE();

 //Please name your piezo.
 //The piezo named snare is connected to the A0 pin






void setup(){
  Serial.begin(9600);
  MIDI.begin(10);
  
  
}
void loop(){
  for(int i = 0; i < NUMBER_OF_TOUCH_PIN; i++){ 
    touchValue[i] = touchRead(touchPin[i]);
    if(touchValue[i] < threshold){
      if(touchPinUnlock[i] == true){

     

     
       /***  
        MIDI.sendNoteOn(36, 100, 10);
        MIDI.sendNoteOff(36, 0, 10);
        MIDI.sendNoteOn(44, 100, 10);
        MIDI.sendNoteOff(44, 0, 10);
        ***/

        Serial.print("detect on PIN ");
        Serial.println(touchPin[i]);

        switch(touchPin[i]) {
          case 14:
        MIDI.sendNoteOn(39, 70, 10);
       MIDI.sendNoteOff(39, 0, 10);
        // delay(100);


          break;
           case 15: 
           MIDI.sendNoteOn(37, 100, 10);
           MIDI.sendNoteOff(37, 0, 10);
          //   delay(100);


           break;
          case 33: 
           MIDI.sendNoteOn(36, 100, 10);
           MIDI.sendNoteOff(36, 0, 10);
           //  delay(100);


           break;

           
          break;
           case 4: 
           MIDI.sendNoteOn(38, 100, 10);
           MIDI.sendNoteOff(38, 0, 10);
           //  delay(100);


           break;
          case 27: 
           MIDI.sendNoteOn(40, 100, 10);
           MIDI.sendNoteOff(40, 0, 10);
           //  delay(100);


           break;
           
           default: 
           break;
        }
      }
      else
      {
        touchPinUnlock[i] = true;
      }
    }
    else{
      touchPinUnlock[i] = false;
    }
  }
}
