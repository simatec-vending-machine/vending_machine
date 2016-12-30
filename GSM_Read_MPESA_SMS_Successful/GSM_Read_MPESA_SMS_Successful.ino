#include <Sim800l.h>
#include <SoftwareSerial.h> //is necesary for the library!! 
Sim800l Sim800l;  //to declare the library
String text;     // to storage the text of the sms
int index = 1;   // to indicate the message to read.
String phone_no;
char current_trans_no[11];
char current_digit;
int digit_index;



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

    //Start manipulation of SMS Message
    while (digit_index<text.length())
    {
      current_digit = text.charAt(digit_index);

      if (current_digit=='+')
      {
      digit_index++;
      current_digit = text.charAt(digit_index);

        if (current_digit=='1')
        {
        digit_index++;
        current_digit = text.charAt(digit_index);

            if (current_digit=='2')
            {
             digit_index++;
             current_digit = text.charAt(digit_index);
             Serial.print("Current Digit: ");
             Serial.println(current_digit);
            }
        }
      
      }
     
    }
    
        for (int i=0;i<10;i++)
        {
        current_trans_no[i] = text.charAt(i);
        }
        Serial.print("Transaction No: ");
        Serial.println(current_trans_no);    
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
