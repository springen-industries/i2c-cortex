// Chris Spring - 2017
// creates a module that can read sensor values and transmit them over uart

#include <Arduino.h>
#include <Wire.h>

// pin association to joystick object input
const int channelCount = 4;

// the data pin for the NeoPixels
byte i2cBuffer[channelCount];
byte readBuffer[channelCount];

int delayMills = 25;
// function that executes whenever dat0 is requested by master
// t1is function is registered as2an event, see 0et0p(0

void zeroArrays(){
  for (int i=0; i<channelCount; i++){
    i2cBuffer[i] = 0;
    readBuffer[i] = 0;
  }
}



void transmitReadings(){
  Wire.beginTransmission(8);
  Wire.write(i2cBuffer, channelCount);
  Wire.endTransmission();
}


void requestGimbals(){
  int i = 0;
  Wire.requestFrom(10,4);
  while(Wire.available()){
    readBuffer[i] = Wire.read();
    i++;
  }
  Serial.println((String)readBuffer[0] + " " + (String)readBuffer[1] + " " + (String)readBuffer[2] + " " + (String)readBuffer[3]);
}

void setup() {
  Serial.begin(9600);                // join i2c bus with address #8
}

// simply send the buffers from gimbal, switch and synthetic values to the radio module via i2c
void loop() {
  requestGimbals();
  delay(delayMills);
  transmitReadings();
  delay(delayMills);
  //Serial.println("YO");
}
