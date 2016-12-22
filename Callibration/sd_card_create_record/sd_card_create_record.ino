#include "Arduino.h"
#include <EDB.h>

#include <SPI.h>
#include <SD.h>

#define SD_PIN 4
#define TABLE_SIZE 33554432

char* db_name = "/db/test_db.db";
File dbFile;

struct LogEventRead {
  int id;
  //char username[11];
  //char password[5];
  char trans_no[11];
  int amount;
  //char timestamp[6];
  //char datestamp[11];
  //float liquid_price;
  char phone_number[11];
  float liquid_amount; 
  bool delivered;
}
logEventRead;

struct LogEventWrite {
  int id;
  //char username[11];
  //char password[5];
  char trans_no[11];
  int amount;
  //char timestamp[6];
  //char datestamp[11];
  //float liquid_price;
  char phone_number[11];
  float liquid_amount;
  bool delivered;
}
logEventWrite;

  //char default_username[11] = "0000000000";
  //char default_password[5] = "0000";
  char default_trans_no[11] = "KI28LXK0IQ" ;
  int default_amount = 167;
  //char default_timestamp[6] = "09:19";
  //char default_datestamp[11] = "02/09/2016";
  //float default_liquid_price = 50.0;
  
  char default_phone_number[11] = "0702034103";
  float default_liquid_amount = 50.0;
  bool default_delivered = false;
  
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


void setup() {
  // put your setup code here, to run once:
  pinMode(13, OUTPUT);
  digitalWrite(13, LOW);

  Serial.begin(9600);
  Serial.println(" Extended Database Library + External SD Card Storage Demo ");
  Serial.println();

  randomSeed(analogRead(0));

  if (!SD.begin(SD_PIN)){
    Serial.println("No SD-card.");
    return;
  }
  if (!SD.exists("/db")){
    Serial.println("Dir for db files does not exist, creating...");
    SD.mkdir("/db");
  }

  if (SD.exists(db_name)){
    dbFile = SD.open(db_name, FILE_WRITE);

    if (!dbFile){
      dbFile = SD.open(db_name, FILE_WRITE);
    }
    if (dbFile){
      Serial.print("Opening current table... ");
      EDB_Status result = db.open(0);
      if (result == EDB_OK){
        Serial.println("DONE");
    }else {
        Serial.println("ERROR");
        Serial.println("Did not find database in the file " + String(db_name));
        Serial.print("Creating new table... ");
        db.create(0, TABLE_SIZE, (unsigned int)sizeof(logEventWrite)+(unsigned int)sizeof(logEventRead));
        Serial.println("DONE");
        return;
      }
    }else {
            Serial.println("Could not open file " + String(db_name));
            return;
        } 
    }else {
      Serial.print("Creating table... ");
      dbFile = SD.open(db_name, FILE_WRITE);
      db.create(0, TABLE_SIZE, (unsigned int)sizeof(logEventWrite)+(unsigned int)sizeof(logEventRead));
      Serial.println("DONE");
    } 
    countRecords();
    //deleteAll();
    createRecord();
    countRecords();
    showAll();
    countRecords();
}

void loop() {
  // put your main code here, to run repeatedly:

}
void countRecords()
{
    Serial.print("Record Count: ");
    Serial.println(db.count());
}
void recordLimit()
{
  Serial.print("Record Limit: ");
  Serial.println(db.limit());
}
/*
float get_liquid_price()
{
  EDB_Status result = db.readRec(1, EDB_REC logEventRead);
  if (result == EDB_OK)
        {
          float default_liquid_price = logEventRead.liquid_price;

          return default_liquid_price;
        }
  else {
          printError(result);
        }
  
}
*/
void createRecord()
{
  Serial.print("Creating new record on database.. ");
  int current_record = (int) db.count();
  int new_record = (current_record + 1);
  logEventWrite.id = new_record;
  //memcpy(logEventWrite.username,default_username,10);
  //memcpy(logEventWrite.password,default_password,4);
  memcpy(logEventWrite.trans_no,default_trans_no,10);
  logEventWrite.amount = default_amount;
  //memcpy(logEventWrite.timestamp,default_timestamp,5);
  //memcpy(logEventWrite.datestamp,default_datestamp,10);
  //logEventWrite.liquid_price = default_liquid_price;
  memcpy(logEventWrite.phone_number,default_phone_number,10);
  //default_liquid_amount = get_liquid_price()/default_amount;
  logEventWrite.liquid_amount = default_liquid_amount;
  logEventWrite.delivered = true;
  //db.appendRec(EDB_REC logEvent);
  EDB_Status result = db.appendRec(EDB_REC logEventWrite);
  if (result != EDB_OK) printError(result);
  
  Serial.println("Creating new Record Complete");
}
void showAll()
{
  Serial.println("Started Reading Records");
    for (int recno = 1; recno <= db.count(); recno++)
    {
        EDB_Status result = db.readRec(recno, EDB_REC logEventRead);
        if (result == EDB_OK)
        {
            Serial.print("Recno: ");
            Serial.print(recno);
            Serial.print("  ");
            
            Serial.print(" ID: ");
            Serial.print(logEventRead.id);
            Serial.print("  ");
/*
            Serial.print("Username: ");
            Serial.print(logEventRead.username);
            Serial.print("  ");

            Serial.print("Password: ");
            Serial.print(logEventRead.password);
            Serial.print("  ");
*/            
            Serial.print("Trans No: ");
            Serial.println(logEventRead.trans_no);
            Serial.print("  ");
            
            Serial.print("Amount: ");
            Serial.print(logEventRead.amount);
            Serial.print("  ");
/*
            Serial.print("Time: ");
            Serial.print(logEventRead.timestamp);
            Serial.print("  ");
           
            Serial.print("Date: ");
            Serial.print(logEventRead.datestamp);
            Serial.print("  ");

            Serial.print("Liquid Price: ");
            Serial.print(logEventRead.liquid_price);
            Serial.print("  ");
*/
            Serial.print("Phone No: ");
            Serial.print(logEventRead.phone_number);
            Serial.print("  ");
         
            Serial.print("Amount of liquid");
            Serial.print(logEventRead.liquid_amount);
            Serial.print("  ");
      
            Serial.print("Delivered?");
            Serial.print(logEventRead.delivered);
            Serial.println();
        }
        else printError(result);
    }
}
void deleteOneRecord(int recno)
{
    Serial.print("Deleting recno: ");
    Serial.println(recno);
    db.deleteRec(recno);
}
void deleteAll()
{
    Serial.print("Truncating table... ");
    db.clear();
    Serial.println("DONE");
}
void printError(EDB_Status err)
{
    Serial.print("ERROR: ");
    switch (err)
    {
        case EDB_OUT_OF_RANGE:
            Serial.println("Recno out of range");
            break;
        case EDB_TABLE_FULL:
            Serial.println("Table full");
            break;
        case EDB_OK:
        default:
            Serial.println("OK");
            break;
    }
}
