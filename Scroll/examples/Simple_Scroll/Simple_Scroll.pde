#include <Adafruit_GFX.h>
#include <Colorduino_GFX.h>
#include <Scroll.h>

void setup(){
}

void loop(){
//Scroll("String!", delay, textcolred, textcolgreen, textcolblue, bgcolred, bgcolgreen, bgcolblue, displaynumber)
  Scroll("The time has come, the walrus said", 150, 0, 0, 255, 0, 0, 0, 1);
  Scroll("Green", 150, 0, 255, 0, 0, 0, 0, 1);
}
