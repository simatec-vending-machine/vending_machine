//Initial Declarations

#include "Nextion.h"

SoftwareSerial HMISerial(0,1);

// Component Declarations
NexPage homepage = NexPage(0, 0, "homepage");
  NexButton bn_buy_liquid = NexButton(0, 1, "bn_buy_liquid");
  NexButton bn_admin_login = NexButton(0, 2, "bn_admin_login");

  NexText text_date_0 = NexText(0, 3, "text_date_0");
  NexText text_time_0 = NexText(0, 4, "text_time_0");
  NexText text_status_0 = NexText(0, 5, "text_status_0");
  
NexPage buy_liquid = NexPage(1, 0, "buy_liquid");
  NexButton bn_home_1 = NexButton(1, 1, "bn_home_1");
  NexButton bn_con_trans = NexButton(1, 2, "bn_con_trans");

  NexText text_date_1 = NexText(1, 3, "text_date_1");
  NexText text_time_1 = NexText(1, 4, "text_time_1");
  NexText text_status_1 = NexText(1, 5, "text_status_1");

NexPage con_trans = NexPage(2, 0, "con_trans");
  NexButton bn_home_2 = NexButton(2, 1, "bn_home_2");
  NexButton bn_con_details = NexButton(2, 4, "bn_con_details");

  NexText text_phone_no = NexText(2, 11, "text_phone_no");
  NexText text_amount_2 = NexText(2, 12, "text_amount");
  
  NexText text_date_2 = NexText(2, 5, "text_date_2");
  NexText text_time_2 = NexText(2, 6, "text_time_2");
  NexText text_status_2 = NexText(2, 7, "text_status_2");

NexPage trans_failed = NexPage(3, 0, "trans_failed");
  NexButton bn_home_3 = NexButton(3, 1, "bn_home_3");
  NexButton bn_try_again = NexButton(3, 2, "bn_try_again");
  NexButton bn_cancel_3 = NexButton(3, 3, "bn_cancel");

  NexText text_date_3 = NexText(3, 4, "text_date_3");
  NexText text_time_3 = NexText(3, 5, "text_time_3");
  NexText text_status_3 = NexText(3, 6, "text_status_3");

NexPage trans_success = NexPage(4, 0, "trans_success");
  NexButton bn_home_4 = NexButton(4, 6, "bn_home_4");
  NexButton bn_pour_liquid = NexButton(4, 5, "bn_pour_liquid");

  NexText text_amount_4 = NexText(4, 7, "text_amount");
  NexText text_quantity = NexText(4, 8, "text_quantity");
  
  NexText text_date_4 = NexText(4, 9, "text_date_4");
  NexText text_time_4 = NexText(4, 10, "text_time_4");
  NexText text_status_4 = NexText(4, 11, "text_status_4");
  
NexPage admin_login = NexPage(5, 0, "admin_login");
  NexButton bn_home_5 = NexButton(5, 1, "bn_home_5");
  NexButton bn_login_5 = NexButton(5, 2, "bn_login_5");
  NexButton bn_cancel_5 = NexButton(5, 3, "bn_cancel_5");

  NexText text_user_id_5 = NexText(5, 12, "text_user_id");
  NexText text_pass_5 = NexText(5, 13, "text_pass_5");

  NexText text_date_5 = NexText(5, 6, "text_date_5");
  NexText text_time_5 = NexText(5, 7, "text_time_5");
  NexText text_status_5 = NexText(5, 8, "text_status_5");

NexPage login_success = NexPage(6, 0, "login_success");
  NexButton bn_liq_level_6 = NexButton(6, 1, "bn_liquid_level_6");
  NexButton bn_trans_his_6 = NexButton(6, 2, "bn_trans_his_6");
  NexButton bn_settings_6 = NexButton(6, 3, "bn_settings_6");
  NexButton bn_home_6 = NexButton(6, 4, "bn_home_6");

  NexText text_date_6 = NexText(6, 8, "text_date_6");
  NexText text_time_6 = NexText(6, 9, "text_time_6");
  NexText text_status_6 = NexText(6, 10, "text_status_6");

NexPage login_failed = NexPage(7, 0, "login_failed");
  NexButton bn_home_7 = NexButton(7, 1, "bn_home_7");
  NexButton bn_login_7 = NexButton(7, 4, "bn_login_7");
  NexButton bn_cancel_7 = NexButton(7, 5, "bn_cancel_7");

  NexText text_user_id_7 = NexText(7, 9, "text_user_id_7");
  NexText text_pass_7 = NexText(7, 10, "text_pass_7");

  NexText text_date_7 = NexText(7, 11, "text_date_7");
  NexText text_time_7 = NexText(7, 12, "text_time_7");
  NexText text_status_7 = NexText(7, 13, "text_status_7");
  
NexPage liquid_level = NexPage(8, 0, "liquid_level");
  NexButton bn_liq_level_8 = NexButton(8, 1, "bn_liquid_level_8");
  NexButton bn_trans_his_8 = NexButton(8, 2, "bn_trans_his_8");
  NexButton bn_settings_8 = NexButton(8, 3, "bn_settings_8");
  NexButton bn_home_8 = NexButton(8, 4, "bn_home_8"); 

  NexText text_date_8 = NexText(8, 6, "text_date_8");
  NexText text_time_8 = NexText(8, 7, "text_time_8");
  NexText text_status_8 = NexText(8, 8, "text_status_8");

NexPage trans_his = NexPage(9, 0, "trans_his");
  NexButton bn_liq_level_9 = NexButton(9, 1, "bn_liquid_level_9");
  NexButton bn_trans_his_9 = NexButton(9, 2, "bn_trans_his_9");
  NexButton bn_settings_9 = NexButton(9, 3, "bn_settings_9");
  NexButton bn_home_9 = NexButton(9, 4, "bn_home_9"); 

  NexText text_date_9 = NexText(9, 5, "text_date_9");
  NexText text_time_9 = NexText(9, 6, "text_time_9");
  NexText text_status_9 = NexText(9, 7, "text_status_9");

NexPage settings_menu = NexPage(10, 0, "settings_menu");
  NexButton bn_datetime_10 = NexButton(10, 1, "bn_datetime_10");
  NexButton bn_liqprice_10 = NexButton(10, 2, "bn_liqprice_10");
  NexButton bn_access_10 = NexButton(10, 3, "bn_access_10");
  NexButton bn_home_10 = NexButton(10, 4, "bn_home_10");

  NexText text_date_10 = NexText(10, 5, "text_date_10");
  NexText text_time_10 = NexText(10, 6, "text_time_10");
  NexText text_status_10 = NexText(10, 7, "text_status_10");

NexPage datetime = NexPage(11, 0, "datetime");
  NexButton bn_datetime_11 = NexButton(11, 1, "bn_datetime_11");
  NexButton bn_liqprice_11 = NexButton(11, 2, "bn_liqprice_11");
  NexButton bn_access_11 = NexButton(11, 3, "bn_access_11");
  NexButton bn_home_11 = NexButton(11, 4, "bn_home_11");
  NexButton bn_adjdatetime = NexButton(11, 5, "bn_adjdatetime");

  NexText text_dateday = NexText(11, 17, "text_dateday");
  NexText text_datemonth = NexText(11, 16, "text_datemonth");
  NexText text_dateyear = NexText(11, 18, "text_dateyear");

  NexText text_timehour = NexText(11, 19, "text_timehour");
  NexText text_timemin = NexText(11, 20, "text_timemin");

  NexText text_date_11 = NexText(11, 13, "text_date_11");
  NexText text_time_11 = NexText(11, 14, "text_time_11");
  NexText text_status_11 = NexText(11, 15, "text_status_11");

NexPage liqprice = NexPage(12, 0, "liqprice");
  NexButton bn_datetime_12 = NexButton(12, 1, "bn_datetime_12");
  NexButton bn_liqprice_12 = NexButton(12, 2, "bn_liqprice_12");
  NexButton bn_access_12 = NexButton(12, 3, "bn_access_12");
  NexButton bn_home_12 = NexButton(12, 4, "bn_home_12");
  NexButton bn_adjliqprice = NexButton(12, 5, "bn_adjliqprice");

  NexText text_currprice = NexText(12, 13, "text_currprice");
  NexText text_newprice = NexText(12, 14, "text_newprice");

  NexText text_date_12 = NexText(12, 10, "text_date_12");
  NexText text_time_12 = NexText(12, 11, "text_time_12");
  NexText text_status_12 = NexText(12, 12, "text_status_12");

NexPage access = NexPage(13, 0, "access");
  NexButton bn_datetime_13 = NexButton(13, 1, "bn_datetime_13");
  NexButton bn_liqprice_13 = NexButton(13, 2, "bn_liqprice_13");
  NexButton bn_access_13 = NexButton(13, 3, "bn_access_13");
  NexButton bn_home_13 = NexButton(13, 4, "bn_home_13");
  NexButton bn_adjpass_13 = NexButton(13, 8, "bn_adjpass_13");

  NexText text_pass_13 = NexText(13, 12, "text_pass_13");
  NexText text_newpass13 = NexText(13, 13, "text_newpass13");
  NexText text_conpass13 = NexText(13, 14, "text_conpass13");

  NexText text_date_13 = NexText(13, 9, "text_date_13");
  NexText text_time_13 = NexText(13, 10, "text_time_13");
  NexText text_status_13 = NexText(13, 11, "text_status_13");

NexPage invalid_pass = NexPage(14, 0, "invalid_pass");
  NexButton bn_datetime_14 = NexButton(14, 1, "bn_datetime_14");
  NexButton bn_liqprice_14 = NexButton(14, 2, "bn_liqprice_14");
  NexButton bn_access_14 = NexButton(14, 3, "bn_access_14");
  NexButton bn_home_14 = NexButton(14, 4, "bn_home_14");
  NexButton bn_adjpass_14 = NexButton(14, 7, "bn_adjpass_14");

  NexText text_pass_14 = NexText(14, 15, "text_pass_14");
  NexText text_newpass14 = NexText(14, 16, "text_newpass14");
  NexText text_conpass14 = NexText(14, 17, "text_conpass14");

  NexText text_date_14 = NexText(14, 12, "text_date_14");
  NexText text_time_14 = NexText(14, 13, "text_time_14");
  NexText text_status_14 = NexText(14, 14, "text_status_14");

NexPage pass_changed = NexPage(15, 0, "pass_changed");
  NexButton bn_datetime_15 = NexButton(15, 1, "bn_datetime_15");
  NexButton bn_liqprice_15 = NexButton(15, 2, "bn_liqprice_15");
  NexButton bn_access_15 = NexButton(15, 3, "bn_access_15");
  NexButton bn_home_15 = NexButton(15, 4, "bn_home_15");

  NexText text_date_15 = NexText(15, 5, "text_date_15");
  NexText text_time_15 = NexText(15, 6, "text_time_15");
  NexText text_status_15 = NexText(15, 7, "text_status_15");


//Variable Initialisations
char system_date[] = "01 / 01 / 2016";
char system_time[] = "00:00";
char system_status[] = "OK";

float unit_price;
float quantity_in_ml;
float amount;

//parameters associated with the pouring of the liquid.
byte statusLed = 13;
int outputValve = 12;

byte sensorInterrupt = 0;
byte sensorPin = 2;
float callibrationFactor = 4.5;
volatile byte pulseCount;
float flowRate;
unsigned int flowMillilitres;
unsigned long totalMillilitres;
unsigned long oldTime;

char buffer[20] = {0};

//List of things (Events)that need to be listened to.
NexTouch *nex_listen_list[] =
{
  &homepage,
    &bn_buy_liquid,
    &bn_admin_login,

    &text_date_0,
    &text_time_0,
    &text_status_0,

  &buy_liquid,
    &bn_home_1,
    &bn_con_trans,

    &text_date_1,
    &text_time_1,
    &text_status_1,

  &con_trans,
    &bn_home_2,
    &bn_con_details,

    &text_phone_no,
    &text_amount_2,
    &text_date_2,
    &text_time_2,
    &text_status_2,

  &trans_failed,
    &bn_home_3,
    &bn_try_again,
    &bn_cancel_3,

    &text_date_3,
    &text_time_3,
    &text_status_3,

  &trans_success,
    &bn_home_4,
    &bn_pour_liquid,

    &text_amount_4,
    &text_quantity,

    &text_date_4,
    &text_time_4,
    &text_status_4,

  &admin_login,
    &bn_home_5,
    &bn_login_5,
    &bn_cancel_5,

    &text_user_id_5,
    &text_pass_5,

    &text_date_5,
    &text_time_5,
    &text_status_5,

  &login_success,
    &bn_liq_level_6,
    &bn_trans_his_6,
    &bn_settings_6,
    &bn_home_6,
    
    &text_date_6,
    &text_time_6,
    &text_status_6,

  &login_failed,
    &bn_home_7,
    &bn_login_7,
    &bn_cancel_7,

    &text_user_id_7,
    &text_pass_7,

    &text_date_7,
    &text_time_7,
    &text_status_7,

  &liquid_level,
    &bn_liq_level_8,
    &bn_trans_his_8,
    &bn_settings_8,
    &bn_home_8,

    &text_date_8,
    &text_time_8,
    &text_status_8,

  &trans_his,
    &bn_liq_level_9,
    &bn_trans_his_9,
    &bn_settings_9,
    &bn_home_9,

    &text_date_9,
    &text_time_9,
    &text_status_9,


  &settings_menu,
    &bn_datetime_10,
    &bn_liqprice_10,
    &bn_access_10,
    &bn_home_10,

    &text_date_10,
    &text_time_10,
    &text_status_10,

  &datetime,
    &bn_datetime_11,
    &bn_liqprice_11,
    &bn_access_11,
    &bn_home_11,
    &bn_adjdatetime,

    &text_dateday,
    &text_datemonth,
    &text_dateyear,
    &text_timehour,
    &text_timemin,

    &text_date_11,
    &text_time_11,
    &text_status_11,
    
  &liqprice,
    &bn_datetime_12,
    &bn_liqprice_12,
    &bn_access_12,
    &bn_home_12,
    &bn_adjliqprice,

    &text_currprice,
    &text_newprice,

    &text_date_12,
    &text_time_12,
    &text_status_12,
    
  &access,
    &bn_datetime_13,
    &bn_liqprice_13,
    &bn_access_13,
    &bn_home_13,
    &bn_adjpass_13,

    &text_pass_13,
    &text_newpass13,
    &text_conpass13,

    &text_date_13,
    &text_time_13,
    &text_status_13,
    
  &invalid_pass,
    &bn_datetime_14,
    &bn_liqprice_14,
    &bn_access_14,
    &bn_home_14,
    &bn_adjpass_14,

    &text_pass_14,
    &text_newpass14,
    &text_conpass14,

    &text_date_14,
    &text_time_14,
    &text_status_14,
    
  &pass_changed,
    &bn_datetime_15,
    &bn_liqprice_15,
    &bn_access_15,
    &bn_home_15,

    &text_date_15,
    &text_time_15,
    &text_status_15,
    NULL
};

//Functions for each of the buttons and text fields:
void bn_buy_liquidPopCallback(void *ptr)
{
  buy_liquid.show();
  update_system_requirements(); 
}
void bn_admin_loginPopCallback(void *ptr)
{
  admin_login.show();
  update_system_requirements();
}
void bn_main_menuPopCallback(void *ptr)
{
  homepage.show();
  update_system_requirements();
}
void bn_con_transPopCallback(void *ptr)
{
  con_trans.show();
  update_system_requirements();
}
void bn_con_detailsPopCallback(void *ptr)
{
  Serial.println("Not Connected to Database Yet");
}
void bn_try_againPopCallback(void *ptr)
{
  con_trans.show();
  update_system_requirements();
}
void bn_pour_liquidPopCallback(void *ptr)
{
  if ((millis() - oldTime) > 1000)
  {
    while (quantity_in_ml > totalMillilitres)
    {
        digitalWrite (outputValve, HIGH);
        
        detachInterrupt(sensorInterrupt);
        flowRate = ((1000.0/(millis() - oldTime)) * pulseCount) / callibrationFactor;
        oldTime = millis();
        flowMillilitres = (((flowRate / 60) *1000)/2);
    
        totalMillilitres += flowMillilitres;
        pulseCount = 0;
        attachInterrupt(sensorInterrupt, pulseCounter, FALLING);
   }
  }
  totalMillilitres = 0;
  digitalWrite (outputValve, LOW);
        
 homepage.show();       
}
void bn_loginPopCallback(void *ptr)
{
 Serial.println("You haven't done authentication yet");
}
void bn_cancelPopCallback(void *ptr)
{
 text_user_id_5.setText("");
 text_pass_5.setText(""); 

 text_user_id_7.setText("");
 text_pass_7.setText(""); 
}
void bn_liq_levelPopCallback(void *ptr)
{
  liquid_level.show();
}
void bn_trans_hisPopCallback(void *ptr)
{
  trans_his.show();
}
void bn_settingsPopCallback(void *ptr)
{
  settings_menu.show();
}
void bn_datetimePopCallback(void *ptr)
{
  datetime.show();
}
void bn_liqpricePopCallback(void *ptr)
{
  liqprice.show();
}
void bn_accessPopCallback(void *ptr)
{
  access.show();
}
void bn_adjdatetimePopCallback(void *ptr)
{
  Serial.println("You haven't worked out the connection to the RTC yet");
}
void bn_adjliqpricePopCallback(void *ptr)
{
  Serial.println("This is an easier function. Work out the liquid price function");
}
void bn_adjpasswordPopCallback(void *ptr)
{
  Serial.println("Also an easy function. Do this and change password");
}

float get_quantity(float quantity_in_ml)
{
  quantity_in_ml = (amount/unit_price)*1000;
  return quantity_in_ml;
}


void update_system_requirements()
{
  Serial.println("System Checked");
}

void setup() {
  // put your setup code here, to run once:
nexInit();

HMISerial.begin(9600);

pinMode(outputValve, OUTPUT);
digitalWrite(outputValve, LOW);

pinMode(statusLed, OUTPUT);
digitalWrite(statusLed, HIGH);

pinMode(sensorPin, INPUT);
pinMode(sensorPin, HIGH);

pulseCount = 0;
flowRate = 0.0;
flowMillilitres = 0;
totalMillilitres = 0;
oldTime = 0;

attachInterrupt (sensorInterrupt, pulseCounter, FALLING);

bn_buy_liquid.attachPop(bn_buy_liquidPopCallback);
bn_admin_login.attachPop(bn_admin_loginPopCallback);

bn_home_1.attachPop(bn_main_menuPopCallback);
bn_con_trans.attachPop(bn_con_transPopCallback);

bn_home_2.attachPop(bn_main_menuPopCallback);
bn_con_details.attachPop(bn_con_detailsPopCallback);

bn_home_3.attachPop(bn_main_menuPopCallback);
bn_try_again.attachPop(bn_try_againPopCallback);
bn_cancel_3.attachPop(bn_main_menuPopCallback);

bn_home_4.attachPop(bn_main_menuPopCallback);
bn_pour_liquid.attachPop(bn_pour_liquidPopCallback);

bn_home_5.attachPop(bn_main_menuPopCallback);
bn_login_5.attachPop(bn_loginPopCallback);
bn_cancel_5.attachPop(bn_main_menuPopCallback);

bn_liq_level_6.attachPop(bn_liq_levelPopCallback);
bn_trans_his_6.attachPop(bn_trans_hisPopCallback);
bn_settings_6.attachPop(bn_settingsPopCallback);
bn_home_6.attachPop(bn_main_menuPopCallback);

bn_home_7.attachPop(bn_main_menuPopCallback);
bn_login_7.attachPop(bn_loginPopCallback);
bn_cancel_7.attachPop(bn_main_menuPopCallback);

bn_liq_level_8.attachPop(bn_liq_levelPopCallback);
bn_trans_his_8.attachPop(bn_trans_hisPopCallback);
bn_settings_8.attachPop(bn_settingsPopCallback);

bn_liq_level_9.attachPop(bn_liq_levelPopCallback);
bn_trans_his_9.attachPop(bn_trans_hisPopCallback);
bn_settings_9.attachPop(bn_settingsPopCallback);
bn_home_9.attachPop(bn_main_menuPopCallback);

bn_datetime_10.attachPop(bn_datetimePopCallback);
bn_liqprice_10.attachPop(bn_liqpricePopCallback);
bn_access_10.attachPop(bn_accessPopCallback);
bn_home_10.attachPop(bn_main_menuPopCallback);

bn_datetime_11.attachPop(bn_datetimePopCallback);
bn_liqprice_11.attachPop(bn_liqpricePopCallback);
bn_access_11.attachPop(bn_accessPopCallback);
bn_home_11.attachPop(bn_main_menuPopCallback);
bn_adjdatetime.attachPop(bn_adjdatetimePopCallback);

bn_datetime_12.attachPop(bn_datetimePopCallback);
bn_liqprice_12.attachPop(bn_liqpricePopCallback);
bn_access_12.attachPop(bn_accessPopCallback);
bn_home_12.attachPop(bn_main_menuPopCallback);
bn_adjliqprice.attachPop(bn_adjliqpricePopCallback);

bn_datetime_13.attachPop(bn_datetimePopCallback);
bn_liqprice_13.attachPop(bn_liqpricePopCallback);
bn_access_13.attachPop(bn_accessPopCallback);
bn_home_13.attachPop(bn_main_menuPopCallback);
bn_adjpass_13.attachPop(bn_adjpasswordPopCallback);

bn_datetime_14.attachPop(bn_datetimePopCallback);
bn_liqprice_14.attachPop(bn_liqpricePopCallback);
bn_access_14.attachPop(bn_accessPopCallback);
bn_home_14.attachPop(bn_main_menuPopCallback);
bn_adjpass_14.attachPop(bn_adjpasswordPopCallback);

bn_datetime_15.attachPop(bn_datetimePopCallback);
bn_liqprice_15.attachPop(bn_liqpricePopCallback);
bn_access_15.attachPop(bn_accessPopCallback);
bn_home_15.attachPop(bn_main_menuPopCallback);

}

void loop() {
  // put your main code here, to run repeatedly:
nexLoop(nex_listen_list);
}

void pulseCounter()
{
  pulseCount++;
}

