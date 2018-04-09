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

}

// this is the gimbal loop
// catches response to a read request from the gimbal controller
// pulls values into cortex buffer
// delays
/// makes another request
void readGimbals() {
  int i = 0;
  Wire.requestFrom(10,4);
  while(Wire.available()){
    readBuffer[i] = Wire.read();
    i++;
  }
  delay(delayMills);
  requestGimbals();
}



void readSynthetics(){
  //bit shift over 4 bytes, read pre-defined number of bytes from synthetic states

}

void requestSynthetics(){

}

void startControlLoop(){
  // this will kick off the loop for reading the gimbals
    requestGimbals();
 // this will kick off the loop for reading synthetic readValues
    requestSynthetics();
}



void setup() {
  Serial.begin(9600);                // join i2c bus with address #8
  Wire.onReceive(readGimbals); // register event
  //startControlLoop();
}

// simply send the buffers from gimbal, switch and synthetic values to the radio module via i2c
void loop() {
  //transmitReadings();
  delay(delayMills);
  Serial.println("YO");
}
