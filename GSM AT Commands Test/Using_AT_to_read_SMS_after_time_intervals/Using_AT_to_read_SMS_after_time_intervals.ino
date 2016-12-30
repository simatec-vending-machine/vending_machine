#include "SIM900.h"
#include <SoftwareSerial.h>
#include "sms.h"  //Will we need this
SMSGSM sms;       //Will we need this?

int message_length = 160;
boolean gsm_started = false;
char last_sms[160];
char phone_no [20];

char atcommand[40]="AT+CMGL=\"REC UNREAD\",1";

SoftwareSerial gsmSerial (12,13);

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  gsmSerial.begin(9600);
  Serial.println("GSM Trial One");

  if (gsm.begin(9600))
  {
    Serial.println("Status Ready");
    gsm_started=true;
  }
}

void loop() {
  // put your main code here, to run repeatedly:
  if (gsm_started)
  {
    sms.SimpleWriteln(atcommand);
    Serial.println(atcommand);
    //Serial.println("AT+CMGL=\"REC UNREAD\",1");
    delay(3000);
  }
  else
  {
    Serial.println("GSM Error");
  }
}
