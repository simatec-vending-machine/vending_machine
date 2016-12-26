#include <Nextion.h>
#include <NextionPage.h>
#include <NextionButton.h>
#include <NextionNumber.h>
#include <NextionVariableNumeric.h>
#include <SoftwareSerial.h>

SoftwareSerial nextionSerial(0, 1);

Nextion nex(nextionSerial);
NextionPage page0(nex, 0, 0, "page0");
NextionPage page1(nex, 1, 0, "page1");
NextionButton add(nex, 0, 2, "b1");
NextionButton subtract(nex, 0, 1, "b0");
NextionButton page2_button(nex, 0, 5, "b2");
NextionButton page1_button(nex, 1, 1, "b1");
NextionNumber subject_number(nex, 0, 4, "n0");


void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);

  nextionSerial.begin(9600);
  nex.init();

  delay(1000);
  nex.sleep();
  delay(2000);
  nex.wake();
}

void loop() {
  // put your main code here, to run repeatedly:
  nex.poll();
}
