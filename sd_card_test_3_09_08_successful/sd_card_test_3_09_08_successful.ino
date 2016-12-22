#include "Arduino.h"
#include <EDB.h>

#include <SPI.h>
#include <SD.h>

#define SD_PIN 4
#define TABLE_SIZE 3686793216

//#define RECORDS_TO_CREATE 10

char* db_name = "/db/test_db.db";
File dbFile;

struct LogEvent{
  int id;
  int username;
  int password;
  char trans_no[12];
  int amount;
  char timestamp[6];
  char datestamp[12];
  float liquid_price;
  String phone_number;
  float liquid_amount;
  bool delivered;
}
logEvent;

//test variables 
int test_id = 1;
char test_trans_no[12] = "KH93FBA73R";
int test_amount = 500;
char test_timestamp[6] = "10:30";
char test_datestamp[12] = "10/08/2016";
float test_liquid_amount = 10;
bool test_delivered = false;


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
        db.create(0, TABLE_SIZE, (unsigned int)sizeof(logEvent));
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
      db.create(0, TABLE_SIZE, (unsigned int)sizeof(logEvent));
      Serial.println("DONE");
    }
    countRecords();
    showAll();
    createRecords(1);
    countRecords();
    createRecords(1);
    countRecords();
    deleteOneRecord(10);
    countRecords();
    deleteAll();
    countRecords();
    showAll();
    createRecords(1);
    countRecords();
    createRecords(1);
    countRecords();
}
//end of void setup
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
void createRecords(int num_recs)
{
    Serial.print("Creating Records... ");
    for (int recno = 1; recno <= num_recs; recno++)
    {
        logEvent.id = recno ;
        memcpy(logEvent.trans_no, test_trans_no, 12);
        logEvent.amount = test_amount;
        memcpy(logEvent.timestamp, test_timestamp, 6);
        memcpy(logEvent.datestamp, test_datestamp, 12);
        logEvent.liquid_amount = test_liquid_amount;
        logEvent.delivered = test_delivered;
        EDB_Status result = db.appendRec(EDB_REC logEvent);
        if (result != EDB_OK) printError(result);
    }
    Serial.println("DONE");
}
void readRecord()
{
  
}
void updateOneRecord()
{
  
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
void showAll()
{
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
            Serial.print("Time: ");
            Serial.print(logEvent.timestamp);
            Serial.print("  ");
            Serial.print("Date: ");
            Serial.print(logEvent.datestamp);
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

  int default_id = 1;
  int default_username = 0702034103;
  int default_password = 0000;
  char default_trans_no[11] = "AAAAAAAAAA" ;
  int default_amount = 0;
  char default_timestamp[6] = "00:00";
  char default_datestamp[11] = "01/01/2016";
  float default_liquid_price = 0.0;
  char default_phone_number[11] = "0700000000";
  float default_liquid_amount = 0.0;
  bool default_delivered = true;

void loop() {
  // put your main code here, to run repeatedly:

}
