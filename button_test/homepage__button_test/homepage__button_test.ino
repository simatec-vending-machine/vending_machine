#include <Nextion.h>
#include <NextionPage.h>
#include <NextionButton.h>
#include <SoftwareSerial.h>

SoftwareSerial serialConnection(0, 1);

Nextion nex(serialConnection);
NextionPage Homepage(nex, 0, 0, "Homepage");
NextionButton buy_liquid_button(nex, 0, 1, "b0");
NextionButton admin_login_button(nex, 0, 2, "b1");

void setup() {
  // put your setup code here, to run once:
Serial.begin(9600);
pinMode(13, OUTPUT);

serialConnection.begin(9600);
nex.init();

Serial.println(Homepage.show());

Serial.println(buy_liquid_button.attachCallback(&callback));
Serial.println(admin_login_button.attachCallback(&callback));
  
char buffer[50];
buy_liquid_button.getText(buffer, 50);
Serial.println(buffer);

}

void callback(NextionEventType type, INextionTouchable *widget)
{
  if (type == NEX_EVENT_PUSH)
  {
    digitalWrite(13, HIGH);
    Serial.println("You just pressed something. I do not know what yet.");
  }
 else if (type == NEX_EVENT_POP)
 {
    digitalWrite(13, LOW);
    Serial.println("I think this means you've released something");
 }
}

void loop() {
  // put your main code here, to run repeatedly:
  nex.poll();
}
