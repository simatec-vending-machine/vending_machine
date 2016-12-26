#include "SIM900.h"
#include <SoftwareSerial.h>

#include "sms.h"
SMSGSM sms;

int numdata;
boolean started=false;
char current_sms[160]={0};
char smsbuffer[160] = {0};
char n[20];

#define SIM800_TX_PIN 12
#define SIM800_RX_PIN 13
SoftwareSerial gsm_serial(SIM800_TX_PIN,SIM800_RX_PIN);

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  while (!Serial){};
  gsm_serial.begin(9600);
  Serial.println("GSM Shield testing.");
  //Start configuration of shield with baudrate.
  //For http uses is reccomended to use 4800 or slower.
  if (gsm.begin(2400)){
    Serial.println("\nstatus=READY");
    started=true;  
  }
  else Serial.println("\nstatus=IDLE");
  
  if(started){
    //Enable this two lines if you want to send an SMS.
    //if (sms.SendSMS("3471234567", "Arduino SMS"))
      //Serial.println("\nSMS sent OK");
  }
};

void loop() {
  // put your main code here, to run repeatedly:
  if(started){
    //Read if there are messages on SIM card and print them.
    if(gsm.readSMS(smsbuffer, 160, n, 20))
    {
      if ((memcmp(smsbuffer, current_sms, 160)==0))
      {
        gsm.SimpleWrite("AT+CMGD=1");
        Serial.println("Deleted Something");
        memcpy(smsbuffer,0,160);
        
      }
      else
      {
        Serial.println(n);
        Serial.print("current sms: ");
        Serial.println(current_sms);
        Serial.println(smsbuffer);

        memcpy(current_sms, smsbuffer, 160);
      }
    }
    delay(1000);
  }
};
