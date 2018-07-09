#include <Scroll.h>

extern const unsigned char font8_8[92][8];

// Constructor to initiate colorduino and populate defaults
Scroll::Scroll(){
	Colorduino.Init();
	_scrollSpeed = 250;
	_scrollText = "EXAMPLE";
	_scrollColor.r = 0;
	_scrollColor.g = 255;
	_scrollColor.b = 0;
	unsigned char whiteBalVal[3] = {36,63,63};
	Colorduino.SetWhiteBal(whiteBalVal);
}

// Sets the private scrollspeed variable
void Scroll::setSpeed(int scrollSpeed){
	_scrollSpeed = scrollSpeed;
}

// Sets the private scroll text variable
void Scroll::setText(String text){
	_scrollText = text;
}
void Scroll::setColor(int r, int g, int b){
	_scrollColor.r = r;
	_scrollColor.g = g;
	_scrollColor.b = b;
}
// Private function to draw a character to the display buffer
void Scroll::_dispDrawChar(char chr,unsigned char R,unsigned char G,unsigned char B, char bias)
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

void Scroll::_dispBlank(){
  for(int x=0; x<8; x++){
    for(int y=0; y<8; y++){
       Colorduino.SetPixel(x,y,0,0,0);
    }
  }
}

void Scroll::run(){
	int num_char = _scrollText.length();
	const int CHAR_WIDTH = 6;
	for(int i=(num_char*CHAR_WIDTH+8); i>0; i--){
		_dispBlank();
		for(int cur_char=0; cur_char < num_char; cur_char++){
			int cur_char_offset = i-((num_char-cur_char)*CHAR_WIDTH);
			_dispDrawChar(_scrollText.charAt(cur_char),_scrollColor.r,_scrollColor.g,_scrollColor.b,cur_char_offset);
		}
		Colorduino.FlipPage();
		delay(_scrollSpeed);
	}
}