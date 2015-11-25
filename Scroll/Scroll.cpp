#include <Adafruit_GFX.h>
#include <Colorduino_GFX.h>
#include <Scroll.h>
ColorduinoPanel Colorduino; 




Scroll::Scroll(String text, int scrollspeed, int tr, int tg, int tb, int br, int bg, int bb, int displaynumber){

  int startdelay = scrollspeed*8*displaynumber;
  randomSeed(analogRead(0));

  Colorduino.init();


  Colorduino.setWhiteBalance(36, 63, 63); // Set white balance
  delay(startdelay);


  int numberofcharacters = text.length();
  for(int xv = 10; xv > -((numberofcharacters+1)*6) ; xv--){

    GFX_Color_t textcolor = Colorduino.color(tr, tg, tb);//Color of text to scroll Default: White
    GFX_Color_t textBG = Colorduino.color(br, bg, bb);//Color of text background Default: Black/Nothing

	   for(int index = 0; index < numberofcharacters ; index++){
		   Colorduino.drawChar(xv+6*(index+1), 1, text.charAt(index), textcolor, textBG, 1); 
	   }

      
      Colorduino.swapBuffers(true);
    delay(scrollspeed); 

    }



  }


