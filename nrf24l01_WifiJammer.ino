/*
* Arduino nRF24L01 Noise Gen
*                
* by Hugo Rezende, www.hugorezende.com.br
* 
* Library: TMRh20/RF24, https://github.com/tmrh20/RF24/
*/
#include <SPI.h&gt;
#include <nRF24L01.h&gt;
#include <RF24.h&gt;
RF24 radio(7, 8); // CE, CSN
 
void setup() {
  radio.begin();
  radio.setPALevel(RF24_PA_HIGH);
  radio.stopListening();
}
void loop() {
  //send it throug the channel 4 (2.2417GHz - 2437GHz)
  for(int i=16; i<38; i++){
    radio.setChannel(i);
    const char text[] = "320939210nsdf"; //just some random string
    radio.write(&text, sizeof(text));    //just some random string
  }
}
