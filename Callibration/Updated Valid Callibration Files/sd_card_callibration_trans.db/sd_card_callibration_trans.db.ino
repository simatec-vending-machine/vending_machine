#include "Arduino.h"
#include <EDB.h>

#include <SPI.h>
#include <SD.h>

#define SD_PIN 4
#define TABLE_SIZE 3686793216

char* trans_db = "/db/trans_db.db";
File dbFile;

struct LogEventRead{
  int id;
  char trans_no[11];
  int amount;
  char phone_number[11];
  float liquid_price;
  float liquid_amount;
  bool delivered;
}
logEventRead;

struct LogEventWrite{
  int id;
  char trans_no[11];
  int amount;
  char phone_number[11];
  float liquid_price;
  float liquid_amount;
  bool delivered;
}
logEventWrite;

  char default_trans_no[11] = "KJ38LZK0NA" ;
  int default_amount = 10;

  char default_phone_number[11] = "0718151850";
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
        db.create(0, TABLE_SIZE, (unsigned int)sizeof(logEventWrite));
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
      db.create(0, TABLE_SIZE, (unsigned int)sizeof(logEventWrite));
      Serial.println("DONE");
    }
    deleteAll();
    createRecord();
    showAll();
}

void loop() {
  // put your main code here, to run repeatedly:

}

void deleteAll()
{
    Serial.print("Truncating table... ");
    db.clear();
    Serial.println("DONE");
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

void createRecord()
{
  Serial.print("Creating New record on database.. ");
  logEventWrite.id = 1;
  memcpy(logEventWrite.trans_no,default_trans_no,10);
  logEventWrite.amount = default_amount;
  logEventWrite.liquid_price = get_liquid_price();
  memcpy(logEventWrite.phone_number,default_phone_number,10);
  logEventWrite.liquid_amount = default_amount/get_liquid_price();
  logEventWrite.delivered = false;
  
  EDB_Status result = db.appendRec(EDB_REC logEventWrite);
  if (result != EDB_OK) printError(result);
  
  Serial.println("Creating New Record Complete");
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
           
            Serial.print("Trans No: ");
            Serial.println(logEventRead.trans_no);
            Serial.print("  ");
            
            Serial.print("Amount: ");
            Serial.print(logEventRead.amount);
            Serial.print("  ");

            Serial.print("Liquid Price: ");
            Serial.print(logEventRead.liquid_price);
            Serial.print("  ");

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
