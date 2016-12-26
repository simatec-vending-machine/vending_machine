#include "Arduino.h"
#include <EDB.h>

#include <SPI.h>
#include <SD.h>

#define SD_PIN 4
#define TABLE_SIZE 8192

#define RECORDS_TO_CREATE 10

char* db_name = "/db/edb_test.db";
File dbFile;

struct LogEvent{
  int id;
  char username[];
  int temperature;
}
logEvent;

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
      } 
    }else {
        Serial.println("ERROR");
        Serial.println("Did not find database in the file " + String(db_name));
        Serial.print("Creating new table... ");
        db.create(0, TABLE_SIZE, (unsigned int)sizeof(logEvent));
        Serial.println("DONE");
        return;
      }
    } else {
      Serial.print("Creating table... ");
      dbFile = SD.open(db_name, FILE_WRITE);
      db.create(0, TABLE_SIZE, (unsigned int)sizeof(logEvent));
      Serial.println("DONE");
    }
    recordLimit();
    countRecords();
    createRecords(RECORDS_TO_CREATE);
    countRecords();
    selectAll();
    deleteOneRecord(RECORDS_TO_CREATE / 2);
    countRecords();
    selectAll();
    appendOneRecord(RECORDS_TO_CREATE + 1);
    countRecords();
    selectAll();
    updateOneRecord(RECORDS_TO_CREATE);
    selectAll();
    countRecords();
    deleteAll();
    Serial.println("Use insertRec() and deleteRec() carefully, they can be slow");
    countRecords();
    for (int i = 1; i <= 20; i++) insertOneRecord(1);
    countRecords();
    for (int i = 1; i <= 20; i++) deleteOneRecord(1);
    countRecords();

    dbFile.close();
    
  }
  
void recordLimit()
{
  Serial.print("Record Limit: ");
  Serial.println(db.limit());
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
void countRecords()
{
  Serial.print("Record Count: ");
  Serial.println(db.count());
}
void createRecords(int num_recs)
{
  Serial.print("Creating Records... ");
  for (int recno = 1; recno <= num_recs; recno++)
  {
    logEvent.id = recno;
    logEvent.temperature = random(1, 125);
    EDB_Status result = db.appendRec(EDB_REC logEvent);
    if (result != EDB_OK) printError(result);
  }
  Serial.println("DONE");
}

void selectAll()
{
  for (int recno=1; recno <= db.count(); recno++)
  {
    EDB_Status result = db.readRec(recno, EDB_REC logEvent);
    if (result == EDB_OK)
    {
      Serial.print("Recno: ");
      Serial.print(recno);
      Serial.print("ID: ");
      Serial.print(logEvent.id);
      Serial.print("Temp: ");
      Serial.println(logEvent.temperature);
    }
    else printError(result);
  }
}
void updateOneRecord(int recno)
{
  Serial.print("Updating record at recno: ");
  Serial.print(recno);
  Serial.print("... ");
  logEvent.id = 1234;
  logEvent.temperature = 4321;
  EDB_Status result = db.updateRec(recno, EDB_REC logEvent);
  if (result != EDB_OK) printError(result);
  Serial.println("DONE");
}
void insertOneRecord(int recno)
{
 Serial.print("Inserting record at recno; ");
 Serial.print(recno);
 Serial.print("... ");
 logEvent.id = recno;
 logEvent.temperature = random(1, 125);
 EDB_Status result = db.insertRec(recno, EDB_REC logEvent);
 if (result != EDB_OK) printError(result);
 Serial.println("DONE"); 
}
void appendOneRecord(int id)
{
  Serial.print("Appending record... ");
  logEvent.id = id;
  logEvent.temperature = random(1, 125);
  EDB_Status result = db.appendRec(EDB_REC logEvent);
  if (result != EDB_OK) printError(result);
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

void loop() {
  // put your main code here, to run repeatedly:

}
