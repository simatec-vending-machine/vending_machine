#include "SIM900.h"
#include <SoftwareSerial.h>
#include "sms.h"

SMSGSM sms;

int numdata;
boolean started = false;
char smsbuffer[160];
char n[20];

void setup() {
  Serial.begin(9600);
  Serial.println("GSM Shield Testing.");

  if (gsm.begin(4800)){
    Serial.println("\n Status: Ready");
    started = true;
  }
  else Serial.println("\n Status: IDLE");
}

void loop() {
 Serial.println("Into loop");
 if (started)
 {
  if (gsm.readSMS(smsbuffer, 160, n, 20))
  {
    Serial.println("Kuna sms");
    Serial.println(n);
    Serial.println(smsbuffer); 
  }
  delay(150);
 }

}
