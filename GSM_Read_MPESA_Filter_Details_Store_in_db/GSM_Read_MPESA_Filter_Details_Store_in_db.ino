#include <Sim800l.h>
#include <SoftwareSerial.h> 
#include <EDB.h>

#include <SPI.h>
#include <SD.h>

#define SD_PIN 4
#define TABLE_SIZE 3686793216
Sim800l Sim800l;  
String text;     // to storage the text of the sms
int index = 1;   // to indicate the message to read.
String phone_no;

//information picked out from the message
char current_trans_no[11];
char current_date[9];
char current_time[9];
char current_amount[6];
int amount_int;
char current_phone[11];

char current_digit;

//database initialization
char* sys_var = "/db/sys_var.db";
char* trans_db = "/db/trans_db.db";
char* trans_details_db = "/db/tran_det.db";
File dbFile;

struct logEventgetsysvar{
  int id;
  char username[11];
  char password[5];
  float liquid_price;
  bool delivered;
}
logEventgetsysvar;

void writer(unsigned long address, byte data){
  digitalWrite(13, HIGH);
  dbFile.seek(address);
  dbFile.write(data);
  dbFile.flush();
  digitalWrite(13, LOW);
}
byte reader(unsigned long address){
  digitalWrite(13, HIGH);
  dbFile.seek(address);
  byte b = dbFile.read();
  digitalWrite(13, LOW);
  return b;
}
EDB db(&writer, &reader);

//set of variables used to locate and find the transaction number
int transaction_index=60;
int end_of_trans=0;
bool gotthetrans=false;

//set of variables used to locate and find the date
int date_index=0;
int end_of_date=0;
bool gotthedate=false;

//set of variables used to locate and find the time
int time_index=0;
int end_of_time=0;
bool gotthetime=false;

//set of variables used to locate and find the amount
int amount_index=0;
int end_of_amount=0;
bool gottheamount=false;

//set of variables used to locate and find the phone number
int phone_index=0;
int end_of_phone=0;
bool gotthephone=false;

//set of variables to store session database Values
char session_username[11];
char session_password[5];
float session_liquid_price;

bool already_run_var=false;




void setup(){
reinitialize:  
Serial.begin(9600); // only for debug the results . 
//SPI.begin();
randomSeed(analogRead(0));

//if (already_run_var==true)
//{
//  goto already_run;
//}
//else
//{
get_sys_var();  //  Initialization of System Variable Database for read of liquid price
//already_run_var=true;
//goto reinitialize;
//}
//already_run:
Sim800l.begin(); // initialize the library. 
Serial.println("Initialization Complete");
}

void loop(){
  
  Serial.println("Starting to Read");
  text=Sim800l.readSms(index); 
  phone_no=Sim800l.getNumberSms(index);   
  //Serial.println(text);
  //Serial.print("Phone no: ");
  //Serial.println(phone_no);
    
if((phone_no=="+254702034103")||(phone_no=="w405543514"))
{
    Serial.println(text);
    Serial.print("Phone no: ");
    Serial.println(phone_no);

    //Start manipulation of SMS Message
    //quick_read();
    fetch_data();
    
    
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
    Serial.print("Phone no: ");
    Serial.println(phone_no);
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
     keep_checking:     
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
    int j=transaction_index+3;
    if ((text.charAt(j)=='/')||(text.charAt(j)==' ')||(text.charAt(j)=='+')||(text.charAt(j)=='\"')||(text.charAt(j-2)==','))
    {
      transaction_index++;
      goto keep_checking;
    }
    else
    {
    }
    for (int i=transaction_index+3;i<transaction_index+13;i++)
        {
        current_trans_no[i-(transaction_index+3)] = text.charAt(i);
        }
        Serial.print("Transaction No: ");
        Serial.println(current_trans_no);  
         //Serial.println(" ");
         //Serial.println(" ");
         //Serial.println(" ");

         end_of_trans=transaction_index+13;
         //Serial.print("End of trans: ");
         //Serial.println(end_of_trans);

         //Serial.println(" ");
         //Serial.println(" ");
         //Serial.println(" ");

     
     transaction_index=50;
}

void get_date()
{
    date_index=end_of_trans+10;
    while (gotthedate==false)
    {
          
          current_digit = text.charAt(date_index);
          if (current_digit=='n')
          {
            //Serial.print("Current digit: ");
            //Serial.println(current_digit);
            gotthedate=true;
          }
          else
          {
            //Serial.print("Current digit: ");
            //Serial.println(current_digit);
            //Serial.print("not there Yet");
            date_index++;
          }
          
    }
    gotthedate=false;
    for (int i=date_index+2;i<date_index+10;i++)
    {
      if (text.charAt(i)==' ')
        {
          current_date[i-(date_index+2)] = ' ';
          current_date[i-(date_index+1)] = ' ';
          goto D; 
        }
      else
        {
        current_date[i-(date_index+2)] = text.charAt(i);
        }
    }

    D:
        Serial.print("Date: ");
        Serial.println(current_date);  

        end_of_date=date_index+10;
        //Serial.print("End of Date: ");
        //Serial.println(end_of_date);  
        //Serial.println(" ");
        //Serial.println(" ");
        //Serial.println(" ");

     date_index=end_of_trans+10;
}

void get_time()
{
    time_index=end_of_date;
    while (gotthetime==false)
    {
          current_digit = text.charAt(time_index);
          if (current_digit=='t')
          {
            //Serial.print("Current digit: ");
            //Serial.println(current_digit);
            gotthetime=true;
          }
          else
          {
            //Serial.print("Current digit: ");
            //Serial.println(current_digit);
            //Serial.print("not there Yet");
            time_index++;
          }
          
    }
    gotthetime=false;
    for (int i=time_index+2;i<time_index+10;i++)
    {
        if (text.charAt(i-1)=='M')
        {
          current_time[i-(time_index+2)] = ' ';
          continue; 
        }
        current_time[i-(time_index+2)] = text.charAt(i);
        
    }
        Serial.print("Time: ");
        Serial.println(current_time);  

        end_of_time=time_index+10;
        //Serial.print("End of Time: ");
        //Serial.println(end_of_time);  
        //Serial.println(" ");
        //Serial.println(" ");
        //Serial.println(" ");

      time_index=end_of_date;
}

void get_amount()
{
    amount_index=end_of_time;
    while (gottheamount==false)
    {
          current_digit = text.charAt(amount_index);
          if (current_digit=='h')
          {
            //Serial.print("Current digit: ");
            //Serial.println(current_digit);
            gottheamount=true;
          }
          else
          {
            //Serial.print("Current digit: ");
            //Serial.println(current_digit);
            //Serial.print("not there Yet");
            amount_index++;
          }
          
    }
    gottheamount=false;
    for (int i=amount_index+1;i<amount_index+5;i++)
    {
        if(text.charAt(i)==',')
        {
        current_amount[i-(amount_index+1)] = text.charAt(i+1);
        current_amount[i-(amount_index)] = text.charAt(i+2);
        current_amount[i-(amount_index-1)] = text.charAt(i+3);
        goto B;
        }
        else if (text.charAt(i)=='.')
        {
         goto B;
        }
        else
        {
        current_amount[i-(amount_index+1)] = text.charAt(i);
        }
    }
    B:
        Serial.print("Amount: ");
        Serial.println(current_amount);  

        amount_int = atoi(current_amount);
        Serial.print("Amount (Integer): ");
        Serial.println(amount_int); 

        end_of_amount=amount_index+10;
         //Serial.print("End of Amount: ");
        //Serial.println(end_of_amount);  
        //Serial.println(" ");
        //Serial.println(" ");
        //Serial.println(" ");

     
     
      amount_index=end_of_time;
}

void get_phone_no()
{
    phone_index=end_of_amount;
    while (gotthephone==false)
    {
          current_digit = text.charAt(phone_index);
          if ((current_digit=='4')||(current_digit=='0'))
          {
            //Serial.print("Current digit: ");
            //Serial.println(current_digit);
            gotthephone=true;
          }
          else
          {
            //Serial.print("Current digit: ");
            //Serial.println(current_digit);
            //Serial.print("not there Yet");
            phone_index++;
          }
          
    }
    gotthephone=false;
    current_phone[0]='0';
    for (int i=phone_index+1;i<phone_index+10;i++)
    {
        if (text.charAt(i)==' ')
        {
         goto C;
        }
        else
        {
        current_phone[i-(phone_index)] = text.charAt(i);
        }
    }
    C:
        Serial.print("Phone No: ");
        Serial.println(current_phone);  

        end_of_phone=phone_index+10;
        // Serial.print("End of Phone: ");
        //Serial.println(end_of_phone);  
        Serial.println(" ");
        Serial.println(" ");
        Serial.println(" ");

    
      phone_index=end_of_amount;
}

void quick_read()
{
  String quick_read;
  for (int i=0; i<25; i++)
  {
    quick_read=Sim800l.readSms(i);
  }
}

void clear_details()
{
   for( int i = 0; i < sizeof(current_amount);  ++i )
     current_amount[i] = (char)0; 
  
}
void fetch_data()
{
    clear_details();
    get_trans_no();
    get_date();
    get_time();
    get_amount();
    get_phone_no();
  
}
void get_sys_var()
{
  
    if (!SD.begin(SD_PIN)){
    Serial.println("No SD-card.");
    return;
  }
 
  if (!SD.exists("/db")){
    Serial.println("Error: System Variable Database Does not Exist...");
    exit;
  }

  if (SD.exists(sys_var)){
    dbFile = SD.open(sys_var, FILE_WRITE);

    if (!dbFile){
      Serial.println("Error: System Variable Database Does not Exist...");
      exit;
    }
    if (dbFile){
      Serial.print("Opening current table... ");
      EDB_Status result = db.open(0);
      if (result == EDB_OK){
        Serial.println("DONE");
    }else {
        Serial.println("ERROR");
        Serial.println("Did not find database in the file " + String(sys_var));
        exit;
        return;
      }
    }else {
            Serial.println("Could not open file " + String(sys_var));
            return;
        } 
    }else {
      Serial.println("Error: System Variable Database Does not Exist...");
      exit;
    }
//-------------------------------------------------------------------------------
//   Read function of liquid price
//---------------------------------------------------------------------------------

Serial.println("Reading Liquid Price: ");

EDB_Status result = db.readRec(1, EDB_REC logEventgetsysvar);
if (result == EDB_OK)
  {
    memcpy(session_username, logEventgetsysvar.username, 11);
    memcpy(session_password, logEventgetsysvar.password, 5);
    session_liquid_price = logEventgetsysvar.liquid_price;      
  }
Serial.print("Username: ");
Serial.println(session_username);

Serial.print("Password: ");
Serial.println(session_password);
  
Serial.print("Liquid Price: ");
Serial.println(session_liquid_price);

SD.end();
}
