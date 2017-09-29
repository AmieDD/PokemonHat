

//amiedd
//www.amiedd.com
//8/18/16
//pokeball 3D Print Wearable hat

#include <Adafruit_CircuitPlayground.h>
#include <Wire.h>
#include <SPI.h>

// we light one pixel at a time, this is our counter
uint8_t pixeln = 0;

void setup() {
  //while (!Serial);
  Serial.begin(9600);
  Serial.println("Circuit Playground test!");

  CircuitPlayground.begin();
}


void loop() {
  // test Red #13 LED
  CircuitPlayground.redLED(HIGH);
  delay(100);
  CircuitPlayground.redLED(LOW);
  delay(100);

  /************* TEST CAPTOUCH */
  Serial.print("Capsense #3: "); Serial.println(CircuitPlayground.readCap(3));
  Serial.print("Capsense #2: "); Serial.println(CircuitPlayground.readCap(2));
  Serial.print("Capsense #0: "); Serial.println(CircuitPlayground.readCap(0));
  Serial.print("Capsense #1: "); Serial.println(CircuitPlayground.readCap(1));
  Serial.print("Capsense #12: "); Serial.println(CircuitPlayground.readCap(12));
  Serial.print("Capsense #6: "); Serial.println(CircuitPlayground.readCap(6));
  Serial.print("Capsense #9: "); Serial.println(CircuitPlayground.readCap(9));
  Serial.print("Capsense #10: "); Serial.println(CircuitPlayground.readCap(10));
  
  /************* TEST SLIDE SWITCH */
  if (CircuitPlayground.slideSwitch()) {
    Serial.println("Slide to the left");
  } else {
    Serial.println("Slide to the right");
    CircuitPlayground.playTone(500 + pixeln * 500, 250);
  }

  /************* TEST 10 NEOPIXELS */
 CircuitPlayground.setPixelColor(0, 240, 0, 0);
 CircuitPlayground.setPixelColor(1,240,0,0);
 CircuitPlayground.setPixelColor(2,240,0,0);
 CircuitPlayground.setPixelColor(3,240,0,0);
 CircuitPlayground.setPixelColor(4,240,0,0);
//
 CircuitPlayground.setPixelColor(5,240,240,240);
 CircuitPlayground.setPixelColor(6,240,240,240);
 CircuitPlayground.setPixelColor(7,240,240,240);
 CircuitPlayground.setPixelColor(8,240,240,240);
 CircuitPlayground.setPixelColor(9,240,240,240);

//  CircuitPlayground.setPixelColor(pixeln++, CircuitPlayground.colorWheel(25 * pixeln));
  if (pixeln == 11) {
   pixeln = 0;
   CircuitPlayground.clearPixels();
  }


  /************* TEST BOTH BUTTONS */
  if (CircuitPlayground.leftButton()) {
    Serial.println("Left button pressed!");
  }
  if (CircuitPlayground.rightButton()) {
    Serial.println("Right button pressed!");
  }

  /************* TEST LIGHT SENSOR */
  Serial.print("Light sensor: ");
  Serial.println(CircuitPlayground.lightSensor());

  /************* TEST SOUND SENSOR */
  Serial.print("Overload.wav");
  Serial.println(CircuitPlayground.soundSensor());

  /************* TEST ACCEL */
  // Display the results (acceleration is measured in m/s*s)
  Serial.print("X: "); Serial.print(CircuitPlayground.motionX());
  Serial.print(" \tY: "); Serial.print(CircuitPlayground.motionY());
  Serial.print(" \tZ: "); Serial.print(CircuitPlayground.motionZ());
  Serial.println(" m/s^2");

  /************* TEST THERMISTOR */
  Serial.print("Temperature ");
  Serial.print(CircuitPlayground.temperature());
  Serial.println(" *C");
}
