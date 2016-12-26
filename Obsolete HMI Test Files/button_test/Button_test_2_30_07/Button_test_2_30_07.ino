#include "Nextion.h"

SoftwareSerial HMISerial(0,1);

NexText t0 = NexText(0, 1, "t0");
NexButton b0 = NexButton(0, 2, "b0"); 
NexButton b1 = NexButton(0, 3, "b1");

int number;
char buffer[10] = {0};

NexTouch *nex_listen_list[] =
{
  &t0,
  &b0,
  &b1,
  NULL
};

void t0PopCallback(void *ptr)
{
  //dbSerialPrintln("Text Box PopCallBack");
  t0.setText("60");
}

void b0PopCallback(void *ptr)
{
  //dbSerialPrintln("button Plus PopCallback");

    memset(buffer, 0, sizeof(buffer));
  t0.getText(buffer, sizeof(buffer));

  number = atoi(buffer);
  if (number < 100) number += 1;
  
  memset(buffer, 0, sizeof(buffer));
  itoa(number, buffer, 10);
  t0.setText(buffer);
}

void b1PopCallback(void *ptr)
{
  //dbSerialPrintln("button Minus PopCallback");

  if (number > 0) number -= 1;

  memset(buffer, 0, sizeof(buffer));
  itoa(number, buffer, 10);
  t0.setText(buffer);
}
 
void setup() {
  // put your setup code here, to run once:
  nexInit();
  
  HMISerial.begin(9600);

  t0.attachPop(t0PopCallback);
  
  b0.attachPop(b0PopCallback);

  b1.attachPop(b1PopCallback);

  //dbSerialPrintln("Setup Done");
}

void loop() {
  // put your main code here, to run repeatedly:
  nexLoop(nex_listen_list);
}
