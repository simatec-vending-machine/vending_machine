#include "Arduino.h"

#include <SD.h>
#include <Wire.h>

#define SD_PIN 4
#define TABLE_SIZE 3686793216

char *db_name = "/db/test_db.csv";
File dbFile;

struct LogEvent{
  int id;
  char username[11];
  char password[5];
  char trans_no[11];
  int amount;
  char timestamp[6];
  char datestamp[11];
  float liquid_price;
  char phone_number[11];
  float liquid_amount;
  bool delivered;
}
LogEvent;



void setup() {
  // put your setup code here, to run once:
  Wire.begin(9600);
  Serial.begin(9600);
  Serial.println("Initialising Card");
  pinMode(SD_PIN, OUTPUT);

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
      dbFile.println(", , , , , , , , , ,"); //Just a leading blank line, incase there was previous data
      String header = "ID, Username, Password, Transaction, Amount, Time, Date, Liquid Price, Phone No., Amount, Delivered?";
      dbFile.println(header);
      dbFile.close();
      Serial.println(header);
      
    }else {
        Serial.println("ERROR");
        Serial.println("Did not find database in the file " + String(db_name));
        
        return;
      }
    }else {
            Serial.println("Could not open file " + String(db_name));
            return;
        } 
        
}



void loop() {
  // put your main code here, to run repeatedly:

}
