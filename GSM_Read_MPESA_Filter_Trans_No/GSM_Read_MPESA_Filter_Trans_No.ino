#include <Sim800l.h>
#include <SoftwareSerial.h> //is necesary for the library!! 
Sim800l Sim800l;  //to declare the library
String text;     // to storage the text of the sms
int index = 1;   // to indicate the message to read.
String phone_no;

//information picked out from the message
char current_trans_no[11];
char date[9];

char current_digit;

//set of variables used to locate and find the transaction number
int transaction_index=65;
int end_of_trans=0;
bool gotthetrans=false;

//set of variables used to locate and find the date
int date_index=90;
int end_of_date=0;
bool gotthedate=false;


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
  //Serial.println(text);
  //Serial.print("Phone no: ");
  //Serial.println(phone_no);
  
  if(phone_no=="w405543514")
  {
    Serial.println(text);
    Serial.print("Phone no: ");
    Serial.println(phone_no);

    //Start manipulation of SMS Message
    get_trans_no();
       
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

} //end of loop

void get_trans_no()
{
    while (gotthetrans==false)
    {
          current_digit = text.charAt(transaction_index);
          if (current_digit=='\"')
          {
            //Serial.print("Current digit: ");
            //Serial.println(current_digit);
            gotthetrans=true;
          }
          else
          {
            //Serial.print("Current digit: ");
            //Serial.println(current_digit);
            //Serial.print("not there Yet");
            transaction_index++;
          }
          
    }
    gotthetrans=false;
    for (int i=transaction_index+3;i<transaction_index+13;i++)
        {
        current_trans_no[i-(transaction_index+3)] = text.charAt(i);
        }
        Serial.print("Transaction No: ");
        Serial.println(current_trans_no);  
         Serial.println(" ");
         Serial.println(" ");
         Serial.println(" ");

         end_of_trans=transaction_index+13;
         Serial.print("End of trans: ");
         Serial.println(end_of_trans);

         Serial.println(" ");
         Serial.println(" ");
         Serial.println(" ");

     
     transaction_index=65;
}


