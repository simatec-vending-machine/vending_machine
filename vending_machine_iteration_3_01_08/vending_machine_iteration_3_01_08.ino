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

  NexText text_phone_no = NexText(2, 9, "text_phone_no");
  NexText text_amount_2 = NexText(2, 10, "text_amount");
  
  NexText text_date_2 = NexText(2, 3, "text_date_2");
  NexText text_time_2 = NexText(2, 4, "text_time_2");
  NexText text_status_2 = NexText(2, 5, "text_status_2");

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

  NexText text_amount_4 = NexText(4, 10, "text_amount");
  NexText text_quantity = NexText(4, 11, "text_quantity");
  
  NexText text_date_4 = NexText(4, 7, "text_date_4");
  NexText text_time_4 = NexText(4, 8, "text_time_4");
  NexText text_status_4 = NexText(4, 9, "text_status_4");
  
NexPage admin_login = NexPage(5, 0, "admin_login");
  NexButton bn_home_5 = NexButton(5, 1, "bn_home_5");
  NexButton bn_login_5 = NexButton(5, 2, "bn_login_5");
  NexButton bn_cancel_5 = NexButton(5, 3, "bn_cancel");

  NexText text_user_id = NexText(5, 12, "text_user_id");
  NexText text_password = NexText(5, 13, "text_password");

  NexText text_date_5 = NexText(5, 6, "text_date_5");
  NexText text_time_5 = NexText(5, 7, "text_time_5");
  NexText text_status_5 = NexText(5, 8, "text_status_5");

NexPage login_success = NexPage(6, 0, "login_success");
  NexButton bn_liq_level = NexButton(6, 1, "bn_liquid_level");
  NexButton bn_trans_hist = NexButton(6, 2, "bn_trans_hist");
  NexButton bn_settings = NexButton(6, 3, "bn_settings");
  NexButton bn_home_6 = NexButton(6, 4, "bn_home_6");

  NexText text_date_6 = NexText(6, 8, "text_date_6");
  NexText text_time_6 = NexText(6, 9, "text_time_6");
  NexText text_status_6 = NexText(6, 10, "text_status_6");


NexPage login_failed = NexPage(7, 0, 

NexPage liquid_level = NexPage(8, 0, "liquid_level");

NexPage trans_history = NexPage(9, 0, "trans_history");

NexPage settings_menu = NexPage(10, 0, "settings_menu");

//Variable Initialisations
char system_date[] = "01 / 01 / 2016";
char system_time[] = "00:00";
char system_status[] = "OK";

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

    &text_user_id,
    &text_password,

    &text_date_5,
    &text_time_5,
    &text_status_5,

  &login_success,
    &bn_liq_level,
    &bn_trans_hist,
    &bn_settings,
    &bn_home_6,
    
    &text_date_6,
    &text_time_6,
    &text_status_6,

  &liquid_level,

  &trans_history,

  &settings_menu,
  
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
  Serial.println("Not Connected to Outlet Pump Yet");
}
void bn_login_5PopCallback(void *ptr)
{
 Serial.println("You haven't done authentication yet");
}
void bn_cancelPopCallback(void *ptr)
{
 text_user_id.setText("");
 text_password.setText(""); 
}
void bn_liq_levelPopCallback(void *ptr)
{
  liquid_level.show();
}
void bn_trans_histPopCallback(void *ptr)
{
  trans_history.show();
}
void bn_settingsPopCallback(void *ptr)
{
  settings_menu.show();
}

void update_system_requirements()
{
  Serial.println("System Checked");
}

void setup() {
  // put your setup code here, to run once:
nexInit();

HMISerial.begin(9600);

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
bn_login_5.attachPop(bn_login_5PopCallback);
bn_cancel_5.attachPop(bn_main_menuPopCallback);

bn_liq_level.attachPop(bn_liq_levelPopCallback);
bn_trans_hist.attachPop(bn_trans_histPopCallback);
bn_settings.attachPop(bn_settingsPopCallback);
bn_home_6.attachPop(bn_main_menuPopCallback);
}

void loop() {
  // put your main code here, to run repeatedly:
nexLoop(nex_listen_list);
}
