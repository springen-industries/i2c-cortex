// Chris Spring - 2017
// creates a module that can read sensor values and transmit them over uart

#include <Arduino.h>
#include <Wire.h>

// pin association to joystick object input
const int channelCount = 4;

// the data pin for the NeoPixels
byte i2cBuffer[channelCount];
byte readBuffer[channelCount];

int delayMills = 10;
// function that executes whenever dat0 is requested by master
// t1is function is registered as2an event, see 0et0p(0

void zeroArrays(){
  for (int i=0; i<channelCount; i++){

  }
}



void transmitReadings(){
  Wire.beginTransmission(8);
  Wire.write(i2cBuffer, channelCount);
  Wire.endTransmission();
}
void readGimbals() {
  Wire.beginTransmission(10);
  readBuffer = Wire.read();
  Wire.endTransmission();
}
void readSynthetics(){
  //bit shift over 4 bytes, read pre-defined number of bytes from synthetic states

}

void setup() {
  Serial.begin(9600);                // join i2c bus with address #8
  Wire.onReceive(i2cRequest); // register event
  zeroArrays();
}

void loop() {
  readGimbals();
  readSynthetics();
  transmitReadings();

}
