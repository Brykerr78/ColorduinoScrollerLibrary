/*
	Standalone Scrolling text using only the Colorduino Library
	Based of functions from within the scroll library
*/

//Libraries
#include <Colorduino.h>
#include <ColorTools.h>

// External Font
extern const unsigned char font8_8[92][8];

// Functions
void DispShowChar(char chr,unsigned char R,unsigned char G,unsigned char B, char bias)
{
  unsigned char cur_char_row;
  unsigned char Char;
  unsigned char chrtemp[8] = {0};

  // Return immediately if not required to draw
  if ((bias > 8) || (bias < -8))
    return;
 
  // Map ASCII to font Array
  Char = chr-32;
  // Read character from font file
  for(int i = 0; i < 8; i++){
      chrtemp[i] = pgm_read_byte(&(font8_8[Char][i]));
  }
  //Loop through each bit of the 8x8 character array
  for(int cur_row = 0;cur_row < 8; cur_row++) {
    cur_char_row = chrtemp[cur_row];
    // Check if whole row is off
    if(cur_char_row == 0x0){
      continue; 
    }
    for(int cur_col = 0;cur_col < 8; cur_col++){
      int led_x = (cur_row-2)+bias;
      int led_y = 7-cur_col;
      // Check if led should be colored
      if(cur_char_row & 0x01){
         Colorduino.SetPixel(led_x,led_y,R,G,B);
      } else {
         Colorduino.SetPixel(led_x,led_y,0,0,0);
      }
      // Test the next bit
      cur_char_row >>= 1;
    }
  }

}
void DispBlank(){
  for(int x=0; x<8; x++){
    for(int y=0; y<8; y++){
       Colorduino.SetPixel(x,y,0,0,0);
    }
  }
}

void setup() {
  // Initiate the Colorduino
  Colorduino.Init();
  Serial.begin(9600);
  // Balance colors
  unsigned char whiteBalVal[3] = {36,63,63};
  Colorduino.SetWhiteBal(whiteBalVal);
  
  // Display Test Char
 }

void loop() {
  String text = "HELLO GITHUB";
  int num_char = text.length();  
  int char_width = 6;
  for(int i=(num_char*char_width+8);i>0;i--){
    DispBlank();
    for(int cur_char=0;cur_char<num_char;cur_char++){
      DispShowChar(text.charAt(cur_char),0,0,255,i-((num_char-cur_char)*char_width));
    }
    Colorduino.FlipPage();
    delay(250);
  }
}