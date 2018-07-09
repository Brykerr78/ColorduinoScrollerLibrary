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
	void setSpeed(int scrollSpeed);
	void setText(String text);
	void setColor(int r, int g, int b);
	void run();
  private:
	int _scrollSpeed;
	String _scrollText;
	ColorRGB _scrollColor;
    void _dispDrawChar(char chr,unsigned char R,unsigned char G,unsigned char B, char bias);
	void _dispBlank();
};

#endif