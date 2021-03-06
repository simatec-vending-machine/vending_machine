#include "Arduino.h"
#include <EDB.h>

#include <SPI.h>
#include <SD.h>

#define SD_PIN 4
#define TABLE_SIZE 3686793216

char* sys_var = "/db/sys_var.db";
File dbFile;

struct LogEvent{
  int id;
  char username[11];
  char password[5];
  float liquid_price;
  bool delivered;
}
logEvent;

//Please input the default user name and password here before running this code.
int default_id = 1;
char default_username[11] = "0702034103";
char default_password[5] = "0000";
char default_liquid_price = 60.0;
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

  if (SD.exists(sys_var)){
    dbFile = SD.open(sys_var, FILE_WRITE);

    if (!dbFile){
      dbFile = SD.open(sys_var, FILE_WRITE);
    }
    if (dbFile){
      Serial.print("Opening current table... ");
      EDB_Status result = db.open(0);
      if (result == EDB_OK){
        Serial.println("DONE");
    }else {
        Serial.println("ERROR");
        Serial.println("Did not find database in the file " + String(sys_var));
        Serial.print("Creating new table... ");
        db.create(0, TABLE_SIZE, (unsigned int)sizeof(logEvent));
        Serial.println("DONE");
        return;
      }
    }else {
            Serial.println("Could not open file " + String(sys_var));
            return;
        } 
    }else {
      Serial.print("Creating table... ");
      dbFile = SD.open(sys_var, FILE_WRITE);
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
void createMasterRecord()
{
  Serial.print("Creating master record on database.. ");
  logEvent.id = default_id;
  memcpy(logEvent.username,default_username,10);
  memcpy(logEvent.password,default_password,4);
  logEvent.liquid_price = default_liquid_price;
  logEvent.delivered = default_delivered;
  
  EDB_Status result = db.appendRec(EDB_REC logEvent);
  if (result != EDB_OK) printError(result);
  
  Serial.println("Creating Master Record Complete");
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

            Serial.print("Username: ");
            Serial.print(logEvent.username);
            Serial.print("  ");

            Serial.print("Password: ");
            Serial.print(logEvent.password);
            Serial.print("  ");

            Serial.print("Liquid Price: ");
            Serial.print(logEvent.liquid_price);
            Serial.print("  ");
     
            Serial.print("Delivered?");
            Serial.print(logEvent.delivered);
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

