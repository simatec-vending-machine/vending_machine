#include <Nextion.h>
#include <NextionPage.h>
#include <NextionVariableString.h>
#include <NextionVariableNumeric.h>
#include <SoftwareSerial.h>

SoftwareSerial nextionSerial(0,1);

Nextion nex(nextionSerial);
//NextionPage pgVariable(nex, 4, 4, "liquid_pour");
NextionVariableNumeric liquid_pour(nex, 4, 4, "liquid_pour");


void setup() {
  // initialize digital pin 13 as an output.
  Serial.begin(9600);

  nextionSerial.begin(9600);
    
  pinMode(13, OUTPUT);
}

// the loop function runs over and over again forever
void loop() {
  nex.init();
  Serial.println(liquid_pour.getValue());
  
  digitalWrite(13, HIGH);   // turn the LED on (HIGH is the voltage level)
  delay(1000);              // wait for a second
  digitalWrite(13, LOW);    // turn the LED off by making the voltage LOW
  delay(1000);              // wait for a second
}
