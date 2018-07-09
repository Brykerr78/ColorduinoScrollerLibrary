# ColorduinoScrollerLibrary


A simple library for scrolling text on a Colorduino.
Updated for Arduino: 1.8.5

# Dependencies

Relies on Colorduino Library, using our modified fork: https://github.com/Electromondo-Coding/Colorduino

# Methods

## Constructor
Constructor takes no arguments
```cplusplus
Scroll myScroller
```

## setText(String text)
Sets the text used for scrolling, defaults to "EXAMPLE"
```cplusplus
myScroller.setText("HELLO GITHUB");
```

## setColor(int r, int g, int b)
Sets the color of the scrolling text, defaults to green
```cplusplus
myScroller.setColor(255,0,0);
```

## setSpeed(int speed)
Sets the speed between each column change, defaults to 250ms
```cplusplus
myScroller.setSpeed(250);
```
# Example
Here is it as currently in Simple_Scroll.ino
```cplusplus
#include <Scroll.h>

Scroll myScroll;

void setup() {
  myScroll.setText("HELLO GITHUB");
  myScroll.setColor(255,0,0);
  myScroll.setSpeed(300);
}

void loop() {
  myScroll.run();
}
```

# Bugs
- Currently, the library version of the code seems to produce visible flashing on the colorduino. This is currently underinvestigation, in the mean time, code using just the Colorduino library has been provided under `examples/Standalone_Scroll`