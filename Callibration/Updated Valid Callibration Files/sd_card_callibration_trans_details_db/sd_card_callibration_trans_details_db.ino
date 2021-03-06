#include "Arduino.h"
#include <EDB.h>

#include <SPI.h>
#include <SD.h>

#define SD_PIN 4
#define TABLE_SIZE 3686793216

char* trans_db = "/db/trans_db.db";
char* trans_details_db = "/db/tran_det.db";
File dbFile;

struct LogEventRead{
  int id;
  char trans_no[11];
  char timestamp[6];
  char datestamp[11];
}
logEventRead;


struct LogEventWrite{
  int id;
  char trans_no[11];
  char timestamp[6];
  char datestamp[11];
}
logEventWrite;

struct LogEventtransno{
  int id;
  char trans_no[11];
  int amount;
  char phone_number[11];
  float liquid_price;
  float liquid_amount;
  bool delivered;
}
logEventtransno;


int default_id = 1;
char default_trans_no[11] = "AAAAAAAAAA" ;
char default_timestamp[6] = "00:00";
char default_datestamp[11] = "01/01/2016";

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

void setup()
{
  pinMode(13, OUTPUT);
  digitalWrite(13, LOW);

  Serial.begin(9600);
  Serial.println("Creation of Transaction Details Database ");
  Serial.println();

  randomSeed(analogRead(0));

  if (!SD.begin(SD_PIN)){
    Serial.println("No SD-card.");
    return;
  }
  if (!SD.exists("/db")){
    Serial.println("Error: Transaction Database Does not Exist...");
    SD.mkdir("/db");
  }

  if (SD.exists(trans_db)){
    dbFile = SD.open(trans_db, FILE_WRITE);

    if (!dbFile){
      Serial.println("Error: Transaction Database Does not Exist...");
      return;
    }
    if (dbFile){
      Serial.print("Opening current table... ");
      EDB_Status result = db.open(0);
      if (result == EDB_OK){
        Serial.println("DONE");
    }else {
        Serial.println("ERROR");
        Serial.println("Did not find database in the file " + String(trans_details_db));
        return;
      }
    }else {
            Serial.println("Could not open file " + String(trans_details_db));
            return;
        } 
    }else {
      Serial.println("Error: Transaction Database Does not Exist...");
      return;
    }

//-------------------------------------------------------------------------------
//   Read function of transaction number
//---------------------------------------------------------------------------------

Serial.println("Reading Transaction No: ");

EDB_Status result = db.readRec(1, EDB_REC logEventtransno);
if (result == EDB_OK)
  {
    memcpy(default_trans_no,logEventtransno.trans_no, 11);      
  }
Serial.print("Transaction No: ");
Serial.println(default_trans_no);

//----------------------------------------------------------------------------------
//    Initialization of trans_details_db
//----------------------------------------------------------------------------------

  if (SD.exists(trans_details_db)){
    dbFile = SD.open(trans_details_db, FILE_WRITE);

    if (!dbFile){
      dbFile = SD.open(trans_details_db, FILE_WRITE);
    }
    if (dbFile){
      Serial.print("Opening current table... ");
      EDB_Status result = db.open(0);
      if (result == EDB_OK){
        Serial.println("DONE");
    }else {
        Serial.println("ERROR");
        Serial.println("Did not find database in the file " + String(trans_details_db));
        Serial.print("Creating new table... ");
        db.create(0, TABLE_SIZE, (unsigned int)sizeof(logEventWrite));
        Serial.println("DONE");
        return;
      }
    }else {
            Serial.println("Could not open file " + String(trans_details_db));
            return;
        } 
    }else {
      Serial.print("Creating table... ");
      dbFile = SD.open(trans_details_db, FILE_WRITE);
      db.create(0, TABLE_SIZE, (unsigned int)sizeof(logEventWrite));
      Serial.println("DONE");
    }

    deleteAll();
    createRecord();
    showAll();


    
}

void loop()
{
  
}

void createRecord()
{
  Serial.print("Creating master record on database.. ");
  logEventWrite.id = 1;
  memcpy(logEventWrite.trans_no,default_trans_no,10);
  memcpy(logEventWrite.timestamp,default_timestamp,5);
  memcpy(logEventWrite.datestamp,default_datestamp,10);
  
  EDB_Status result = db.appendRec(EDB_REC logEventWrite);
  if (result != EDB_OK) printError(result);
  
  Serial.println("Creating Master Record Complete");
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

            Serial.print("ID: ");
            Serial.print(logEventRead.id);
            Serial.print("  ");
            
            Serial.print(" Transaction No: ");
            Serial.print(logEventRead.trans_no);
            Serial.print("  ");

            Serial.print("Time: ");
            Serial.print(logEventRead.timestamp);
            Serial.print("  ");

            Serial.print("Date: ");
            Serial.print(logEventRead.datestamp);
            Serial.print("  ");

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


