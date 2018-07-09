/*
  Scroll.h - Library for scrolling text on colorduino
*/
#ifndef Scroll_h
#define Scroll_h

#include <Colorduino.h>
#include <ColorTools.h>
#include "Arduino.h"
#include <String.h>

class Scroll
{
  public:
    Scroll();
	void setScrollSpeed(int scrollSpeed);
	void setScrollText(String text);
	void run();
  private:
	int _scrollSpeed;
	String _scrollText;
    void _dispDrawChar(char chr,unsigned char R,unsigned char G,unsigned char B, char bias);
	void _dispBlank();
};

#endif