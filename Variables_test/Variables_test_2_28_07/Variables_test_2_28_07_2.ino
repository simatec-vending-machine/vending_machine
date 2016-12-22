#include <Nextion.h>
#include <NextionPage.h>
#include <NextionNumber.h>
#include <NextionVariableNumeric.h>
#include <SoftwareSerial.h>

SoftwareSerial nextionSerial(0, 1);

Nextion nex(nextionSerial);
NextionPage page0(nex, 0, 0, "page0");
NextionNumber subject_number(nex, 0, 4, "n0");
NextionVariableNumeric subject_variable(nex, 0, 3, "va0");

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);

  nextionSerial.begin(9600);
  nex.init();

  page0.show();
  delay(3000);
  Serial.print("Page Showing: ");
  Serial.println(page0.isShown());
  subject_variable.setValue(4);
  subject_number.setValue(4);
  Serial.print("Number Value: ");
  Serial.println(subject_number.getValue());
}

void loop() {
  // put your main code here, to run repeatedly:
  nex.poll();
  
}
