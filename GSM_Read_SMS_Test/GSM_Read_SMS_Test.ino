#include <Sim800l.h>
#include <SoftwareSerial.h> //is necesary for the library!! 
Sim800l Sim800l;  //to declare the library
String text;     // to storage the text of the sms
int index = 1;   // to indicate the message to read.
String phone_no;

void setup(){
	Serial.begin(9600); // only for debug the results . 
	Sim800l.begin(); // initializate the library. 
  Serial.println("Initialization Complete");
	  
}

void loop(){
	//do nothing
  Serial.println("Starting to Read");
  text=Sim800l.readSms(index); 
  phone_no=Sim800l.getNumberSms(index);   
  
  if(phone_no=="w405543514")
  {
    Serial.println(text);
    Serial.print("Phone no: ");
    Serial.println(phone_no);

     Serial.println(" ");
     
  }
  else if (phone_no.length()<1)
  {
    Serial.println("End of SMS");
    index=0;

    //Place holders
    Serial.println(" ");
    Serial.println(" ");
    Serial.println(" ");
  }
  else
  {
    Serial.println("Not an MPESA Message. Don't bother");

     Serial.println(" ");
     Serial.println(" ");
  }
  delay(500);

 //Sim800l.delAllSms();
 //Serial.println("Deleting Everything");
 //delay(2000);

 index++;
 
}
