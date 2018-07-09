#include <Scroll.h>

Scroll myScroll;

void setup() {
  myScroll.setText("HELLO GITHUB");
  myScroll.setColor(255,0,0);
}

void loop() {
  myScroll.run();
}