#include "Arduino.h"
#include <EDB.h>

#include <SPI.h>
#include <SD.h>

#define SD_PIN 4
#define TABLE_SIZE 3686793216

char* trans_db = "/db/trans_db.db";
File dbFile;

struct LogEvent{
  int id;
  char trans_no[11];
  int amount;
  char phone_number[11];
  float liquid_price;
  float liquid_amount;
  bool delivered;
}
logEvent;

  char default_trans_no[11] = "AAAAAAAAAA" ;
  int default_amount = 0.0;

  char default_phone_number[11] = "0700000000";
  float default_liquid_price = 50.0;
  float default_liquid_amount = 0.0;
  bool default_delivered = true;

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

  if (SD.exists(trans_db)){
    dbFile = SD.open(trans_db, FILE_WRITE);

    if (!dbFile){
      dbFile = SD.open(trans_db, FILE_WRITE);
    }
    if (dbFile){
      Serial.print("Opening current table... ");
      EDB_Status result = db.open(0);
      if (result == EDB_OK){
        Serial.println("DONE");
    }else {
        Serial.println("ERROR");
        Serial.println("Did not find database in the file " + String(trans_db));
        Serial.print("Creating new table... ");
        db.create(0, TABLE_SIZE, (unsigned int)sizeof(logEvent));
        Serial.println("DONE");
        return;
      }
    }else {
            Serial.println("Could not open file " + String(trans_db));
            return;
        } 
    }else {
      Serial.print("Creating table... ");
      dbFile = SD.open(trans_db, FILE_WRITE);
      db.create(0, TABLE_SIZE, (unsigned int)sizeof(logEvent));
      Serial.println("DONE");
    }

    deleteAll();
    createMasterRecord();
    showAll();
}

void loop() {
  // put your main code here, to run repeatedly:

}
void showAll()
{
  Serial.println("Started Reading Records");
    for (int recno = 1; recno <= db.count(); recno++)
    {
        EDB_Status result = db.readRec(recno, EDB_REC logEvent);
        if (result == EDB_OK)
        {
            Serial.print("Recno: ");
            Serial.print(recno);
            Serial.print("  ");
            
            Serial.print(" ID: ");
            Serial.print(logEvent.id);
            Serial.print("  ");
           
            Serial.print("Trans No: ");
            Serial.println(logEvent.trans_no);
            Serial.print("  ");
            
            Serial.print("Amount: ");
            Serial.print(logEvent.amount);
            Serial.print("  ");

            Serial.print("Liquid Price: ");
            Serial.print(logEvent.liquid_price);
            Serial.print("  ");

            Serial.print("Phone No: ");
            Serial.print(logEvent.phone_number);
            Serial.print("  ");
         
            Serial.print("Amount of liquid");
            Serial.print(logEvent.liquid_amount);
            Serial.print("  ");
      
            Serial.print("Delivered?");
            Serial.print(logEvent.delivered);
            Serial.println();
        }
        else printError(result);
    }
}
void createMasterRecord()
{
  Serial.print("Creating new record on database.. ");
  logEvent.id = 1;
  memcpy(logEvent.trans_no,default_trans_no,10);
  logEvent.amount = default_amount;
  logEvent.liquid_price = default_liquid_price;
  memcpy(logEvent.phone_number,default_phone_number,10);
  logEvent.liquid_amount = default_liquid_amount;
  logEvent.delivered = true;
  
  EDB_Status result = db.appendRec(EDB_REC logEvent);
  if (result != EDB_OK) printError(result);
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
