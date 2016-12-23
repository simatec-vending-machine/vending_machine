//Initial Declarations

#include "Nextion.h"
#include "Arduino.h"
#include <EDB.h>

#include <SPI.h>
#include <SD.h>


SoftwareSerial HMISerial(10,11);

// Component Declarations
NexPage homepage = NexPage(0, 0, "homepage");
  //NexButton bn_buy_liquid = NexButton(0, 1, "bn_buy_liquid");
  //NexButton bn_admin_login = NexButton(0, 2, "bn_admin_login");

  //NexText text_date_0 = NexText(0, 3, "text_date_0");
  //NexText text_time_0 = NexText(0, 4, "text_time_0");
  //NexText text_status_0 = NexText(0, 5, "text_status_0");
  
NexPage buy_liquid = NexPage(1, 0, "buy_liquid");
  //NexButton bn_home_1 = NexButton(1, 1, "bn_home_1");
  //NexButton bn_con_trans = NexButton(1, 2, "bn_con_trans");

  //NexText text_date_1 = NexText(1, 3, "text_date_1");
  //NexText text_time_1 = NexText(1, 4, "text_time_1");
  //NexText text_status_1 = NexText(1, 5, "text_status_1");

NexPage con_trans = NexPage(2, 0, "con_trans");
  //NexButton bn_home_2 = NexButton(2, 1, "bn_home_2");
  NexButton bn_con_details = NexButton(2, 2, "bn_con_details");

  NexText text_phone_no = NexText(2, 3, "text_phone_no");
  NexText text_amount_2 = NexText(2, 4, "text_amount_2");
  
  //NexText text_date_2 = NexText(2, 5, "text_date_2");
  //NexText text_time_2 = NexText(2, 6, "text_time_2");
  //NexText text_status_2 = NexText(2, 7, "text_status_2");

  //Keypads
  //NexButton bn_phone_1 = NexButton(2, 8, "bn_phone_1");
  //NexButton bn_phone_2 = NexButton(2, 9, "bn_phone_2");
  //NexButton bn_phone_3 = NexButton(2, 10, "bn_phone_3");
  //NexButton bn_phone_4 = NexButton(2, 11, "bn_phone_4");
  //NexButton bn_phone_5 = NexButton(2, 12, "bn_phone_5");
  //NexButton bn_phone_6 = NexButton(2, 13, "bn_phone_6");
  //NexButton bn_phone_7 = NexButton(2, 14, "bn_phone_7");
  //NexButton bn_phone_8 = NexButton(2, 15, "bn_phone_8");
  //NexButton bn_phone_9 = NexButton(2, 16, "bn_phone_9");
  //NexButton bn_phone_0 = NexButton(2, 17, "bn_phone_0");
  NexButton bn_phone_ok = NexButton(2, 18, "bn_phone_ok");
  //NexButton bn_phone_cl = NexButton(2, 19, "bn_phone_cl");

  //NexButton bn_amount_1 = NexButton(2, 20, "bn_amount_1");
  //NexButton bn_amount_2 = NexButton(2, 21, "bn_amount_2");
  //NexButton bn_amount_3 = NexButton(2, 22, "bn_amount_3");
  //NexButton bn_amount_4 = NexButton(2, 23, "bn_amount_4");
  //NexButton bn_amount_5 = NexButton(2, 24, "bn_amount_5");
  //NexButton bn_amount_6 = NexButton(2, 25, "bn_amount_6");
  //NexButton bn_amount_7 = NexButton(2, 26, "bn_amount_7");
  //NexButton bn_amount_8 = NexButton(2, 27, "bn_amount_8");
  //NexButton bn_amount_9 = NexButton(2, 28, "bn_amount_9");
  //NexButton bn_amount_0 = NexButton(2, 29, "bn_amount_0");
  NexButton bn_amount_ok = NexButton(2, 30, "bn_amount_ok");
  //NexButton bn_amount_cl = NexButton(2, 31, "bn_amount_cl");

  
NexPage trans_failed = NexPage(3, 0, "trans_failed");
  //NexButton bn_home_3 = NexButton(3, 1, "bn_home_3");
  //NexButton bn_try_again = NexButton(3, 2, "bn_try_again");
  //NexButton bn_cancel_3 = NexButton(3, 3, "bn_cancel_3");

  //NexText text_date_3 = NexText(3, 4, "text_date_3");
  //NexText text_time_3 = NexText(3, 5, "text_time_3");
  //NexText text_status_3 = NexText(3, 6, "text_status_3");

NexPage trans_success = NexPage(4, 0, "trans_success");
  //NexButton bn_home_4 = NexButton(4, 1, "bn_home_4");
  NexButton bn_pour_liquid = NexButton(4, 2, "bn_pour_liquid");

  NexText text_amount_4 = NexText(4, 3, "text_amount_4");
  NexText text_quantity = NexText(4, 4, "text_quantity");
  
  //NexText text_date_4 = NexText(4, 5, "text_date_4");
  //NexText text_time_4 = NexText(4, 6, "text_time_4");
  //NexText text_status_4 = NexText(4, 7, "text_status_4");
  
NexPage admin_login = NexPage(5, 0, "admin_login");
  //NexButton bn_home_5 = NexButton(5, 1, "bn_home_5");
  NexButton bn_login_5 = NexButton(5, 2, "bn_login_5");
  //NexButton bn_cancel_5 = NexButton(5, 3, "bn_cancel_5");

  NexText text_user_id_5 = NexText(5, 4, "text_user_id_5");
  NexText text_pass_5 = NexText(5, 5, "text_pass_5");

  //NexText text_date_5 = NexText(5, 6, "text_date_5");
  //NexText text_time_5 = NexText(5, 7, "text_time_5");
  //NexText text_status_5 = NexText(5, 8, "text_status_5");

  //Keypads
  //NexButton bn_user_5_1 = NexButton(5, 9, "bn_user_5_1");
  //NexButton bn_user_5_2 = NexButton(5, 10, "bn_user_5_2");
  //NexButton bn_user_5_3 = NexButton(5, 11, "bn_user_5_3");
  //NexButton bn_user_5_4 = NexButton(5, 12, "bn_user_5_4");
  //NexButton bn_user_5_5 = NexButton(5, 13, "bn_user_5_5");
  //NexButton bn_user_5_6 = NexButton(5, 14, "bn_user_5_6");
  //NexButton bn_user_5_7 = NexButton(5, 15, "bn_user_5_7");
  //NexButton bn_user_5_8 = NexButton(5, 16, "bn_user_5_8");
  //NexButton bn_user_5_9 = NexButton(5, 17, "bn_user_5_9");
  //NexButton bn_user_5_0 = NexButton(5, 18, "bn_user_5_0");
  NexButton bn_user_5_ok = NexButton(5, 19, "bn_user_5_ok");
  //NexButton bn_user_5_cl = NexButton(5, 20, "bn_user_5_cl");

  //NexButton bn_pass_5_1 = NexButton(5, 21, "bn_pass_5_1");
  //NexButton bn_pass_5_2 = NexButton(5, 22, "bn_pass_5_2");
  //NexButton bn_pass_5_3 = NexButton(5, 23, "bn_pass_5_3");
  //NexButton bn_pass_5_4 = NexButton(5, 24, "bn_pass_5_4");
  //NexButton bn_pass_5_5 = NexButton(5, 25, "bn_pass_5_5");
  //NexButton bn_pass_5_6 = NexButton(5, 26, "bn_pass_5_6");
  //NexButton bn_pass_5_7 = NexButton(5, 27, "bn_pass_5_7");
  //NexButton bn_pass_5_8 = NexButton(5, 28, "bn_pass_5_8");
  //NexButton bn_pass_5_9 = NexButton(5, 29, "bn_pass_5_9");
  //NexButton bn_pass_5_0 = NexButton(5, 30, "bn_pass_5_0");
  NexButton bn_pass_5_ok = NexButton(5, 31, "bn_pass_5_ok");
  //NexButton bn_pass_5_cl = NexButton(5, 32, "bn_pass_5_cl");

NexPage login_success = NexPage(6, 0, "login_success");
  //NexButton bn_liq_level_6 = NexButton(6, 1, "bn_liquid_level_6");
  //NexButton bn_trans_his_6 = NexButton(6, 2, "bn_trans_his_6");
  //NexButton bn_settings_6 = NexButton(6, 3, "bn_settings_6");
  //NexButton bn_home_6 = NexButton(6, 4, "bn_home_6");

  //NexText text_date_6 = NexText(6, 5, "text_date_6");
  //NexText text_time_6 = NexText(6, 6, "text_time_6");
  //NexText text_status_6 = NexText(6, 7, "text_status_6");
  
NexPage liq_level = NexPage(8, 0, "liq_level");
  //NexButton bn_liq_level_8 = NexButton(8, 1, "bn_liq_level_8");
  //NexButton bn_trans_his_8 = NexButton(8, 2, "bn_trans_his_8");
  //NexButton bn_settings_8 = NexButton(8, 3, "bn_settings_8");
  //NexButton bn_home_8 = NexButton(8, 4, "bn_home_8"); 

  //NexText text_date_8 = NexText(8, 5, "text_date_8");
  //NexText text_time_8 = NexText(8, 6, "text_time_8");
  //NexText text_status_8 = NexText(8, 7, "text_status_8");

NexPage trans_his = NexPage(9, 0, "trans_his");
  //NexButton bn_liq_level_9 = NexButton(9, 1, "bn_liq_level_9");
  //NexButton bn_trans_his_9 = NexButton(9, 2, "bn_trans_his_9");
  //NexButton bn_settings_9 = NexButton(9, 3, "bn_settings_9");
  //NexButton bn_home_9 = NexButton(9, 4, "bn_home_9"); 

  //NexText text_date_9 = NexText(9, 5, "text_date_9");
  //NexText text_time_9 = NexText(9, 6, "text_time_9");
  //NexText text_status_9 = NexText(9, 7, "text_status_9");

NexPage settings_menu = NexPage(10, 0, "settings_menu");
  //NexButton bn_datetime_10 = NexButton(10, 1, "bn_datetime_10");
  //NexButton bn_liqprice_10 = NexButton(10, 2, "bn_liqprice_10");
  //NexButton bn_access_10 = NexButton(10, 3, "bn_access_10");
  //NexButton bn_home_10 = NexButton(10, 4, "bn_home_10");

  //NexText text_date_10 = NexText(10, 5, "text_date_10");
  //NexText text_time_10 = NexText(10, 6, "text_time_10");
  //NexText text_status_10 = NexText(10, 7, "text_status_10");

NexPage datetime = NexPage(11, 0, "datetime");
  //NexButton bn_datetime_11 = NexButton(11, 1, "bn_datetime_11");
  //NexButton bn_liqprice_11 = NexButton(11, 2, "bn_liqprice_11");
  //NexButton bn_access_11 = NexButton(11, 3, "bn_access_11");
  //NexButton bn_home_11 = NexButton(11, 4, "bn_home_11");
  NexButton bn_adjdatetime = NexButton(11, 5, "bn_adjdatetime");

  NexText text_dateday = NexText(11, 6, "text_dateday");
  NexText text_datemonth = NexText(11, 7, "text_datemonth");
  NexText text_dateyear = NexText(11, 8, "text_dateyear");

  NexText text_timehour = NexText(11, 9, "text_timehour");
  NexText text_timemin = NexText(11, 10, "text_timemin");

  //NexText text_date_11 = NexText(11, 11, "text_date_11");
  //NexText text_time_11 = NexText(11, 12, "text_time_11");
  //NexText text_status_11 = NexText(11, 13, "text_status_11");
/*
  //Keypads
  NexButton bn_dd_1 = NexButton(11, 14, "bn_dd_1");
  NexButton bn_dd_2 = NexButton(11, 15, "bn_dd_2");
  NexButton bn_dd_3 = NexButton(11, 16, "bn_dd_3");
  NexButton bn_dd_4 = NexButton(11, 17, "bn_dd_4");
  NexButton bn_dd_5 = NexButton(11, 18, "bn_dd_5");
  NexButton bn_dd_6 = NexButton(11, 19, "bn_dd_6");
  NexButton bn_dd_7 = NexButton(11, 20, "bn_dd_7");
  NexButton bn_dd_8 = NexButton(11, 21, "bn_dd_8");
  NexButton bn_dd_9 = NexButton(11, 22, "bn_dd_9");
  NexButton bn_dd_0 = NexButton(11, 23, "bn_dd_0");
  NexButton bn_dd_ok = NexButton(11, 24, "bn_dd_ok");
  NexButton bn_dd_cl = NexButton(11, 25, "bn_dd_cl");

  NexButton bn_dm_1 = NexButton(11, 26, "bn_dm_1");
  NexButton bn_dm_2 = NexButton(11, 27, "bn_dm_2");
  NexButton bn_dm_3 = NexButton(11, 28, "bn_dm_3");
  NexButton bn_dm_4 = NexButton(11, 29, "bn_dm_4");
  NexButton bn_dm_5 = NexButton(11, 30, "bn_dm_5");
  NexButton bn_dm_6 = NexButton(11, 31, "bn_dm_6");
  NexButton bn_dm_7 = NexButton(11, 32, "bn_dm_7");
  NexButton bn_dm_8 = NexButton(11, 33, "bn_dm_8");
  NexButton bn_dm_9 = NexButton(11, 34, "bn_dm_9");
  NexButton bn_dm_0 = NexButton(11, 35, "bn_dm_0");
  NexButton bn_dm_ok = NexButton(11, 36, "bn_dm_ok");
  NexButton bn_dm_cl = NexButton(11, 37, "bn_dm_cl");

  NexButton bn_dy_1 = NexButton(11, 38, "bn_dy_1");
  NexButton bn_dy_2 = NexButton(11, 39, "bn_dy_2");
  NexButton bn_dy_3 = NexButton(11, 40, "bn_dy_3");
  NexButton bn_dy_4 = NexButton(11, 41, "bn_dy_4");
  NexButton bn_dy_5 = NexButton(11, 42, "bn_dy_5");
  NexButton bn_dy_6 = NexButton(11, 43, "bn_dy_6");
  NexButton bn_dy_7 = NexButton(11, 44, "bn_dy_7");
  NexButton bn_dy_8 = NexButton(11, 45, "bn_dy_8");
  NexButton bn_dy_9 = NexButton(11, 46, "bn_dy_9");
  NexButton bn_dy_0 = NexButton(11, 47, "bn_dy_0");
  NexButton bn_dy_ok = NexButton(11, 48, "bn_dy_ok");
  NexButton bn_dy_cl = NexButton(11, 49, "bn_dy_cl");

  NexButton bn_th_1 = NexButton(11, 50, "bn_th_1");
  NexButton bn_th_2 = NexButton(11, 51, "bn_th_2");
  NexButton bn_th_3 = NexButton(11, 52, "bn_th_3");
  NexButton bn_th_4 = NexButton(11, 53, "bn_th_4");
  NexButton bn_th_5 = NexButton(11, 54, "bn_th_5");
  NexButton bn_th_6 = NexButton(11, 55, "bn_th_6");
  NexButton bn_th_7 = NexButton(11, 56, "bn_th_7");
  NexButton bn_th_8 = NexButton(11, 57, "bn_th_8");
  NexButton bn_th_9 = NexButton(11, 58, "bn_th_9");
  NexButton bn_th_0 = NexButton(11, 59, "bn_th_0");
  NexButton bn_th_ok = NexButton(11, 60, "bn_th_ok");
  NexButton bn_th_cl = NexButton(11, 61, "bn_th_cl");

  NexButton bn_tm_1 = NexButton(11, 62, "bn_tm_1");
  NexButton bn_tm_2 = NexButton(11, 63, "bn_tm_2");
  NexButton bn_tm_3 = NexButton(11, 64, "bn_tm_3");
  NexButton bn_tm_4 = NexButton(11, 65, "bn_tm_4");
  NexButton bn_tm_5 = NexButton(11, 66, "bn_tm_5");
  NexButton bn_tm_6 = NexButton(11, 67, "bn_tm_6");
  NexButton bn_tm_7 = NexButton(11, 68, "bn_tm_7");
  NexButton bn_tm_8 = NexButton(11, 69, "bn_tm_8");
  NexButton bn_tm_9 = NexButton(11, 70, "bn_tm_9");
  NexButton bn_tm_0 = NexButton(11, 71, "bn_tm_0");
  NexButton bn_tm_ok = NexButton(11, 72, "bn_tm_ok");
  NexButton bn_tm_cl = NexButton(11, 73, "bn_tm_cl");
*/
NexPage liqprice = NexPage(12, 0, "liqprice");
  //NexButton bn_datetime_12 = NexButton(12, 1, "bn_datetime_12");
  //NexButton bn_liqprice_12 = NexButton(12, 2, "bn_liqprice_12");
  //NexButton bn_access_12 = NexButton(12, 3, "bn_access_12");
  //NexButton bn_home_12 = NexButton(12, 4, "bn_home_12");
  NexButton bn_adjliqprice = NexButton(12, 5, "bn_adjliqprice");

  NexText text_currprice = NexText(12, 6, "text_currprice");
  NexText text_newprice = NexText(12, 7, "text_newprice");

  //NexText text_date_12 = NexText(12, 8, "text_date_12");
  //NexText text_time_12 = NexText(12, 9, "text_time_12");
  //NexText text_status_12 = NexText(12, 10, "text_status_12");
/*
  //Keypad
  NexButton bn_liqprice_1 = NexButton(12, 11, "bn_liqprice_1");
  NexButton bn_liqprice_2 = NexButton(12, 12, "bn_liqprice_2");
  NexButton bn_liqprice_3 = NexButton(12, 13, "bn_liqprice_3");
  NexButton bn_liqprice_4 = NexButton(12, 14, "bn_liqprice_4");
  NexButton bn_liqprice_5 = NexButton(12, 15, "bn_liqprice_5");
  NexButton bn_liqprice_6 = NexButton(12, 16, "bn_liqprice_6");
  NexButton bn_liqprice_7 = NexButton(12, 17, "bn_liqprice_7");
  NexButton bn_liqprice_8 = NexButton(12, 18, "bn_liqprice_8");
  NexButton bn_liqprice_9 = NexButton(12, 19, "bn_liqprice_9");
  NexButton bn_liqprice_0 = NexButton(12, 20, "bn_liqprice_0");
  NexButton bn_liqprice_ok = NexButton(12, 21, "bn_liqprice_ok");
  NexButton bn_liqprice_cl = NexButton(12, 22, "bn_liqprice_cl");
*/
NexPage access = NexPage(13, 0, "access");
  //NexButton bn_datetime_13 = NexButton(13, 1, "bn_datetime_13");
  //NexButton bn_liqprice_13 = NexButton(13, 2, "bn_liqprice_13");
  //NexButton bn_access_13 = NexButton(13, 3, "bn_access_13");
  //NexButton bn_home_13 = NexButton(13, 4, "bn_home_13");
  NexButton bn_adjpass_13 = NexButton(13, 5, "bn_adjpass_13");

  NexText text_pass_13 = NexText(13, 6, "text_pass_13");
  NexText text_newpass13 = NexText(13, 7, "text_newpass13");
  NexText text_conpass13 = NexText(13, 8, "text_conpass13");

  //NexText text_date_13 = NexText(13, 9, "text_date_13");
  //NexText text_time_13 = NexText(13, 10, "text_time_13");
  //NexText text_status_13 = NexText(13, 11, "text_status_13");

  //Keypads
  NexButton bn_curr_1 = NexButton(13, 12, "bn_curr_1");
  NexButton bn_curr_2 = NexButton(13, 13, "bn_curr_2");
  NexButton bn_curr_3 = NexButton(13, 14, "bn_curr_3");
  NexButton bn_curr_4 = NexButton(13, 15, "bn_curr_4");
  NexButton bn_curr_5 = NexButton(13, 16, "bn_curr_5");
  NexButton bn_curr_6 = NexButton(13, 17, "bn_curr_6");
  NexButton bn_curr_7 = NexButton(13, 18, "bn_curr_7");
  NexButton bn_curr_8 = NexButton(13, 19, "bn_curr_8");
  NexButton bn_curr_9 = NexButton(13, 20, "bn_curr_9");
  NexButton bn_curr_0 = NexButton(13, 21, "bn_curr_0");
  NexButton bn_curr_ok = NexButton(13, 22, "bn_curr_ok");
  NexButton bn_curr_cl = NexButton(13, 23, "bn_curr_cl");

  NexButton bn_new_1 = NexButton(13, 24, "bn_new_1");
  NexButton bn_new_2 = NexButton(13, 25, "bn_new_2");
  NexButton bn_new_3 = NexButton(13, 26, "bn_new_3");
  NexButton bn_new_4 = NexButton(13, 27, "bn_new_4");
  NexButton bn_new_5 = NexButton(13, 28, "bn_new_5");
  NexButton bn_new_6 = NexButton(13, 29, "bn_new_6");
  NexButton bn_new_7 = NexButton(13, 30, "bn_new_7");
  NexButton bn_new_8 = NexButton(13, 31, "bn_new_8");
  NexButton bn_new_9 = NexButton(13, 32, "bn_new_9");
  NexButton bn_new_0 = NexButton(13, 33, "bn_new_0");
  NexButton bn_new_ok = NexButton(13, 34, "bn_new_ok");
  NexButton bn_new_cl = NexButton(13, 35, "bn_new_cl");

  NexButton bn_con_1 = NexButton(13, 36, "bn_con_1");
  NexButton bn_con_2 = NexButton(13, 37, "bn_con_2");
  NexButton bn_con_3 = NexButton(13, 38, "bn_con_3");
  NexButton bn_con_4 = NexButton(13, 39, "bn_con_4");
  NexButton bn_con_5 = NexButton(13, 40, "bn_con_5");
  NexButton bn_con_6 = NexButton(13, 41, "bn_con_6");
  NexButton bn_con_7 = NexButton(13, 42, "bn_con_7");
  NexButton bn_con_8 = NexButton(13, 43, "bn_con_8");
  NexButton bn_con_9 = NexButton(13, 44, "bn_con_9");
  NexButton bn_con_0 = NexButton(13, 45, "bn_con_0");
  NexButton bn_con_ok = NexButton(13, 46, "bn_con_ok");
  NexButton bn_con_cl = NexButton(13, 47, "bn_con_cl");

 
NexPage pass_changed = NexPage(15, 0, "pass_changed");
  //NexButton bn_datetime_15 = NexButton(15, 1, "bn_datetime_15");
  //NexButton bn_liqprice_15 = NexButton(15, 2, "bn_liqprice_15");
  //NexButton bn_access_15 = NexButton(15, 3, "bn_access_15");
  //NexButton bn_home_15 = NexButton(15, 4, "bn_home_15");

  //NexText text_date_15 = NexText(15, 5, "text_date_15");
  //NexText text_time_15 = NexText(15, 6, "text_time_15");
  //NexText text_status_15 = NexText(15, 7, "text_status_15");

NexPage manual = NexPage(16,0, "manual");
  NexButton bn_con_manual = NexButton(16,0, "bn_con_manual");
  NexText text_amount_16 = NexText(16, 3, "text_amount_16");
  
  //Keypad
  NexButton bn_manual_1 = NexButton(16, 7, "bn_manual_1");
  NexButton bn_manual_2 = NexButton(16, 8, "bn_manual_2");
  NexButton bn_manual_3 = NexButton(16, 9, "bn_manual_3");
  NexButton bn_manual_4 = NexButton(16, 10, "bn_manual_4");
  NexButton bn_manual_5 = NexButton(16, 11, "bn_manual_5");
  NexButton bn_manual_6 = NexButton(16, 12, "bn_manual_6");
  NexButton bn_manual_7 = NexButton(16, 13, "bn_manual_7");
  NexButton bn_manual_8 = NexButton(16, 14, "bn_manual_8");
  NexButton bn_manual_9 = NexButton(16, 15, "bn_manual_9");
  NexButton bn_manual_0 = NexButton(16, 16, "bn_manual_0");
  NexButton bn_manual_ok = NexButton(16, 17, "bn_manual_ok");
  NexButton bn_manual_cl = NexButton(16, 18, "bn_manual_cl");



//Variable Initialisations
char system_date[] = "01-09-2016";
char system_time[] = "06:04";
char system_status[11] = "System OK ";

float unit_price;
float quantity_in_ml;
float amount;

//space holder for things currently being typed
char current_input[10] = {0};

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

//Page Declaration Variables for Page flipping
uint8_t page_number = 0;
int current_page = 0;


//Database values
#define SD_PIN 4
#define TABLE_SIZE 3686793216

char* trans_db = "/db/trans_db.db";
File dbFile;

char* sys_var = "/db/sys_var.db";
File dbvarFile;

struct LogEventVar{
  int id;
  char username[11];
  char password[5];
  float liquid_price;
  bool delivered;
}
logEventVar;

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


bool pour_condition = true;

char current_liquid_amount[10];
float current_liquid_amount_float = 0.000;

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

//boolean values for the various keypads in the programme
bool text_phone_no_keypad_state = false;
bool text_amount_keypad_state = false;
bool text_user_id_5_keypad_state = false;
bool text_pass_5_keypad_state = false;
bool text_amount_16_keypad_state = false;
char buffer_phone_no[10] = {0};
char buffer_amount[10] = {0};

char buffer_username[11]={0};
char buffer_password[5]={0};

//List of things (Events)that need to be listened to.
NexTouch *nex_listen_list[] =
{
  &homepage,
//    &bn_buy_liquid,
//    &bn_admin_login,

//    &text_date_0,
//    &text_time_0,
//    &text_status_0,

  &buy_liquid,
//    &bn_home_1,
//    &bn_con_trans,

//    &text_date_1,
//    &text_time_1,
//    &text_status_1,

  &con_trans,
//    &bn_home_2,
    &bn_con_details,

    &text_phone_no,
    &text_amount_2,
//    &text_date_2,
//    &text_time_2,
//    &text_status_2,

//    &bn_phone_1,
//    &bn_phone_2,
//    &bn_phone_3,
//    &bn_phone_4,
//    &bn_phone_5,
//    &bn_phone_6,
//    &bn_phone_7,
//    &bn_phone_8,
//    &bn_phone_9,
//    &bn_phone_0,
    &bn_phone_ok,
//    &bn_phone_cl,

//    &bn_amount_1,
//    &bn_amount_2,
//    &bn_amount_3,
//    &bn_amount_4,
//    &bn_amount_5,
//    &bn_amount_6,
//    &bn_amount_7,
//    &bn_amount_8,
//    &bn_amount_9,
//    &bn_amount_0,
    &bn_amount_ok,
//    &bn_amount_cl,
    
    
  &trans_failed,
//    &bn_home_3,
//    &bn_try_again,
//    &bn_cancel_3,

//    &text_date_3,
//    &text_time_3,
//    &text_status_3,

  &trans_success,
//    &bn_home_4,
    &bn_pour_liquid,

    &text_amount_4,
    &text_quantity,

//    &text_date_4,
//    &text_time_4,
//    &text_status_4,

  &admin_login,
//    &bn_home_5,
    &bn_login_5,
//    &bn_cancel_5,

    &text_user_id_5,
    &text_pass_5,

//    &text_date_5,
//    &text_time_5,
//    &text_status_5,

 //   &bn_user_5_1,
//    &bn_user_5_2,
//    &bn_user_5_3,
//    &bn_user_5_4,
//    &bn_user_5_5,
//    &bn_user_5_6,
//    &bn_user_5_7,
//    &bn_user_5_8,
//    &bn_user_5_9,
//    &bn_user_5_0,
    &bn_user_5_ok,
//    &bn_user_5_cl,

//    &bn_pass_5_1,
//    &bn_pass_5_2,
//    &bn_pass_5_3,
//    &bn_pass_5_4,
//    &bn_pass_5_5,
//    &bn_pass_5_6,
//    &bn_pass_5_7,
//    &bn_pass_5_8,
//    &bn_pass_5_9,
//    &bn_pass_5_0,
    &bn_pass_5_ok,
//    &bn_pass_5_cl,

  &login_success,
//    &bn_liq_level_6,
//    &bn_trans_his_6,
//    &bn_settings_6,
//    &bn_home_6,
    
//    &text_date_6,
//    &text_time_6,
//    &text_status_6,

  &liq_level,
//    &bn_liq_level_8,
//    &bn_trans_his_8,
//    &bn_settings_8,
//    &bn_home_8,

//    &text_date_8,
//    &text_time_8,
//    &text_status_8,

  &trans_his,
//    &bn_liq_level_9,
//    &bn_trans_his_9,
//    &bn_settings_9,
//    &bn_home_9,

//    &text_date_9,
//    &text_time_9,
//    &text_status_9,


  &settings_menu,
//    &bn_datetime_10,
//    &bn_liqprice_10,
//    &bn_access_10,
//    &bn_home_10,

//    &text_date_10,
//    &text_time_10,
//    &text_status_10,

  &datetime,
//    &bn_datetime_11,
//    &bn_liqprice_11,
//    &bn_access_11,
//    &bn_home_11,
    &bn_adjdatetime,

    &text_dateday,
    &text_datemonth,
    &text_dateyear,
    &text_timehour,
    &text_timemin,

//    &text_date_11,
//    &text_time_11,
//    &text_status_11,
    
  &liqprice,
//    &bn_datetime_12,
//    &bn_liqprice_12,
//    &bn_access_12,
 //   &bn_home_12,
    &bn_adjliqprice,

    &text_currprice,
    &text_newprice,

//    &text_date_12,
//    &text_time_12,
//    &text_status_12,
    
  &access,
//    &bn_datetime_13,
//    &bn_liqprice_13,
//    &bn_access_13,
//    &bn_home_13,
    &bn_adjpass_13,

    &text_pass_13,
    &text_newpass13,
    &text_conpass13,

//    &text_date_13,
//    &text_time_13,
//    &text_status_13,

    &bn_curr_1,
    &bn_curr_2,
    &bn_curr_3,
    &bn_curr_4,
    &bn_curr_5,
    &bn_curr_6,
    &bn_curr_7,
    &bn_curr_8,
    &bn_curr_9,
    &bn_curr_0,
    &bn_curr_ok,
    &bn_curr_cl,
    
    &bn_new_1,
    &bn_new_2,
    &bn_new_3,
    &bn_new_4,
    &bn_new_5,
    &bn_new_6,
    &bn_new_7,
    &bn_new_8,
    &bn_new_9,
    &bn_new_0,
    &bn_new_ok,
    &bn_new_cl,

    &bn_con_1,
    &bn_con_2,
    &bn_con_3,
    &bn_con_4,
    &bn_con_5,
    &bn_con_6,
    &bn_con_7,
    &bn_con_8,
    &bn_con_9,
    &bn_con_0,
    &bn_con_ok,
    &bn_con_cl,
    
    
  &pass_changed,
//    &bn_datetime_15,
//    &bn_liqprice_15,
//    &bn_access_15,
//    &bn_home_15,

//    &text_date_15,
//    &text_time_15,
//    &text_status_15,

  &manual,
      &bn_con_manual,
      &text_amount_16,

      &bn_manual_1,
      &bn_manual_2,
      &bn_manual_3,
      &bn_manual_4,
      &bn_manual_5,
      &bn_manual_6,
      &bn_manual_7,
      &bn_manual_8,
      &bn_manual_9,
      &bn_manual_0,
      &bn_manual_ok,
      &bn_manual_cl,
      
    NULL
};
//General Functions
/*void update_system_requirements()
{
  text_date_0.setText(system_date);
  text_time_0.setText(system_time);
  text_status_0.setText(system_status);

  text_date_1.setText(system_date);
  text_time_1.setText(system_time);
  text_status_1.setText(system_status);

  text_date_2.setText(system_date);
  text_time_2.setText(system_time);
  text_status_2.setText(system_status);
  
  text_date_3.setText(system_date);
  text_time_3.setText(system_time);
  text_status_3.setText(system_status);

  text_date_4.setText(system_date);
  text_time_4.setText(system_time);
  text_status_4.setText(system_status);

  text_date_5.setText(system_date);
  text_time_5.setText(system_time);
  text_status_5.setText(system_status);

  text_date_6.setText(system_date);
  text_time_6.setText(system_time);
  text_status_6.setText(system_status);

  text_date_8.setText(system_date);
  text_time_8.setText(system_time);
  text_status_8.setText(system_status);

  text_date_9.setText(system_date);
  text_time_9.setText(system_time);
  text_status_9.setText(system_status);

  text_date_10.setText(system_date);
  text_time_10.setText(system_time);
  text_status_10.setText(system_status);

  text_date_11.setText(system_date);
  text_time_11.setText(system_time);
  text_status_11.setText(system_status);

  text_date_12.setText(system_date);
  text_time_12.setText(system_time);
  text_status_12.setText(system_status);

  text_date_13.setText(system_date);
  text_time_13.setText(system_time);
  text_status_13.setText(system_status);

  text_date_15.setText(system_date);
  text_time_15.setText(system_time);
  text_status_15.setText(system_status);

}
*/
/*
void text_datePopCallback(void *ptr)
{
  update_system_requirements();
}
void text_timePopCallback(void *ptr)
{
  update_system_requirements();
}
void text_statusPopCallback(void *ptr)
{
  update_system_requirements();
}
*/
/*void bn_main_menuPopCallback(void *ptr)
{
  homepage.show();
  text_date_0.setText(system_date);
  text_time_0.setText(system_time);
  text_status_0.setText(system_status);
}
*/
//Functions for each of the individual buttons and text fields:
/*void homepagePopCallback(void *ptr)
{
  text_date_0.setText(system_date);
  text_time_0.setText(system_time);
  text_status_0.setText(system_status);
}
*/
/*void bn_buy_liquidPopCallback(void *ptr)
{
  buy_liquid.show();
  text_date_1.setText(system_date);
  text_time_1.setText(system_time);
  text_status_1.setText(system_status); 
}
void bn_admin_loginPopCallback(void *ptr)
{
  admin_login.show();
  text_date_5.setText(system_date);
  text_time_5.setText(system_time);
  text_status_5.setText(system_status);
}
*/
/*void bn_con_transPopCallback(void *ptr)
{
  con_trans.show();
  text_phone_no_keypad_hide();
  text_date_2.setText(system_date);
  text_time_2.setText(system_time);
  text_status_2.setText(system_status);  
}
*/
/*
 * 
 * 
 * 
 * 
 * 
 * 
 * 
 * 
 * 
 * 
 * 
 * 
 * 
 * 
 * 
 */
//Keypad elements of the page con_trans
/*void con_transPopCallback(void *ptr)
{
  text_phone_no_keypad_hide();
}
*/

void text_phone_no_keypad_show()
{
  sendCommand("vis 255,0");
  sendCommand("vis bn_home_2,1");
  sendCommand("vis text_phone_no,1");
  sendCommand("vis text_date_2,1");
  sendCommand("vis text_time_2,1");
  sendCommand("vis text_status_2,1");
  sendCommand("vis bn_phone_1,1");
  sendCommand("vis bn_phone_2,1");
  sendCommand("vis bn_phone_3,1");
  sendCommand("vis bn_phone_4,1");
  sendCommand("vis bn_phone_5,1");
  sendCommand("vis bn_phone_6,1");
  sendCommand("vis bn_phone_7,1");
  sendCommand("vis bn_phone_8,1");
  sendCommand("vis bn_phone_9,1");
  sendCommand("vis bn_phone_0,1");
  sendCommand("vis bn_phone_ok,1");
  sendCommand("vis bn_phone_cl,1");
  
  text_phone_no_keypad_state = true;
}
void text_phone_no_keypad_hide()
{
  sendCommand("vis 255,0");
  
  sendCommand("vis bn_home_2,1");
  sendCommand("vis text_phone_no,1");
  sendCommand("vis text_amount_2,1");
  sendCommand("vis bn_con_details,1"); 
  
  sendCommand("vis text_date_2,1");
  sendCommand("vis text_time_2,1");
  sendCommand("vis text_status_2,1");

  text_phone_no_keypad_state = false;
}
void text_phone_noPopCallback(void *ptr)
{
  if (text_phone_no_keypad_state == false)
  {
    text_phone_no_keypad_show();
  }
  else
  {
    text_phone_no_keypad_hide();
  }
}

void text_amount_2PopCallback(void *ptr)
{
  if (text_amount_keypad_state == false)
  {
    text_amount_2keypad_show();
  }
  else
  {
    text_amount_2keypad_hide();
  }
}
void text_amount_2keypad_show()
{
  sendCommand("vis 255,0");
  sendCommand("vis bn_home_2,1");
  sendCommand("vis text_phone_no,1");
  sendCommand("vis text_amount_2,1");
  sendCommand("vis text_date_2,1");
  sendCommand("vis text_time_2,1");
  sendCommand("vis text_status_2,1");
  sendCommand("vis bn_amount_1,1");
  sendCommand("vis bn_amount_2,1");
  sendCommand("vis bn_amount_3,1");
  sendCommand("vis bn_amount_4,1");
  sendCommand("vis bn_amount_5,1");
  sendCommand("vis bn_amount_6,1");
  sendCommand("vis bn_amount_7,1");
  sendCommand("vis bn_amount_8,1");
  sendCommand("vis bn_amount_9,1");
  sendCommand("vis bn_amount_0,1");
  sendCommand("vis bn_amount_ok,1");
  sendCommand("vis bn_amount_cl,1");
  
  text_amount_keypad_state = true;
}
void text_amount_2keypad_hide()
{
  sendCommand("vis 255,0");
  
  sendCommand("vis bn_home_2,1");
  sendCommand("vis text_phone_no,1");
  sendCommand("vis text_amount_2,1");
  sendCommand("vis bn_con_details,1");
  
  sendCommand("vis text_date_2,1");
  sendCommand("vis text_time_2,1");
  sendCommand("vis text_status_2,1");
    
  text_amount_keypad_state = false;
}
void bn_phone_okPopCallback(void *ptr)
{
  text_phone_no_keypad_hide();
  /*
  memset(buffer, 0, sizeof(buffer));
  text_phone_no.getText(buffer, sizeof(buffer));
  
  strcpy(current_input,buffer);
  
  
  //text_phone_no.getText(buffer,20);
  
  //current_input = current_input + 1;
  text_amount_2.setText(current_input);
  */
}
void bn_amount_okPopCallback(void *ptr)
{
  text_phone_no_keypad_hide();
}
boolean array_cmp(char *a, char *b, char len_a, char len_b){
     int n;

     // if their lengths are different, return false
     if (len_a != len_b) return false;

     // test each element to be the same. if not, return false
     for (n=0;n<len_a;n++) if (a[n]!=b[n]) return false;

     //ok, if we have not returned yet, they are equal :)
     return true;
}
void bn_con_detailsPopCallback(void *ptr)
{
  memset(buffer_phone_no, 0, sizeof(buffer_phone_no));
  text_phone_no.getText(buffer_phone_no, sizeof(buffer_phone_no));
  text_phone_no.setText(buffer_phone_no);

  memset(buffer_amount, 0, sizeof(buffer_amount));
  text_amount_2.getText(buffer_amount, sizeof(buffer_amount));
  int current_amount_input = atoi(buffer_amount);
  //text_amount_2.setText(buffer_amount);
  
  for (int recno = 1; recno <= db.count(); recno++)
  {
        EDB_Status result = db.readRec(recno, EDB_REC logEventRead);
        if (result == EDB_OK)
        {
          text_amount_2.setText(logEventRead.phone_number);
          if (array_cmp(logEventRead.phone_number,buffer_phone_no,11,11) == true)
          {
            if (logEventRead.amount == current_amount_input)
            {
              current_liquid_amount_float = logEventRead.liquid_amount;
              trans_success.show();
              text_amount_4.setText(buffer_amount);
              
              
              String str;
              str = String(logEventRead.liquid_amount);
              str.toCharArray(current_liquid_amount,10);
              text_quantity.setText(current_liquid_amount);
              
              return;
            }
          }
          else{
            trans_failed.show();
          }
        }
        else 
        {
          memcpy(system_status,"DB Error  ",10);
          trans_failed.show();
        }       
  }
  trans_failed.show();
}

/*
 * 
 * 
 * 
 * 
 * 
 * Space for a lot of sad work
 * 
 * 
 * 
 * 
 * 
 */
 /*
void bn_try_againPopCallback(void *ptr)
{
  con_trans.show();
  //update_system_requirements();
  text_phone_no_keypad_hide();
}
*/
//Confirm the contents of this function
void bn_pour_liquidPopCallback(void *ptr)
{
  while (pour_condition == true)
  {
  digitalWrite(outputValve, LOW);
  if ((millis() - oldTime) > 1000)
  {
    detachInterrupt(digitalPinToInterrupt(sensorPin));
    flowRate = ((1000.0/(millis() - oldTime)) * pulseCount) / callibrationFactor;
    oldTime = millis();
    flowMillilitres = (((flowRate / 60) *1000)/2.25);
    
    totalMillilitres += flowMillilitres;
    String str3;
    str3 = String(totalMillilitres);
    char current_liquid_flowing[10];
    str3.toCharArray(current_liquid_flowing,10);
    text_quantity.setText(current_liquid_flowing);
    
    pulseCount = 0;
    attachInterrupt(digitalPinToInterrupt(sensorPin), pulseCounter, FALLING);

    if (totalMillilitres >= 500 )
      {
        digitalWrite(outputValve,HIGH);
        pour_condition = false;
      }
  }
  
  
  }    
 homepage.show();
        
}
void pulseCounter()
{
  // Increment the pulse counter
  pulseCount++;
}


void text_user_id_5PopCallback(void *ptr)
{
  if (text_user_id_5_keypad_state == false)
  {
    text_user_id_5_keypad_show();
  }
  else
  {
    text_user_id_5_keypad_hide();
  }
}

void text_user_id_5_keypad_show()
{
  sendCommand("vis 255,0");
  sendCommand("vis bn_home_5,1");
  sendCommand("vis text_user_id_5,1");
  sendCommand("vis text_date_5,1");
  sendCommand("vis text_time_5,1");
  sendCommand("vis text_status_5,1");
  sendCommand("vis bn_user_5_1,1");
  sendCommand("vis bn_user_5_2,1");
  sendCommand("vis bn_user_5_3,1");
  sendCommand("vis bn_user_5_4,1");
  sendCommand("vis bn_user_5_5,1");
  sendCommand("vis bn_user_5_6,1");
  sendCommand("vis bn_user_5_7,1");
  sendCommand("vis bn_user_5_8,1");
  sendCommand("vis bn_user_5_9,1");
  sendCommand("vis bn_user_5_0,1");
  sendCommand("vis bn_user_5_ok,1");
  sendCommand("vis bn_user_5_cl,1");
  
  text_user_id_5_keypad_state = true;
}
void text_user_id_5_keypad_hide()
{
  sendCommand("vis 255,0");
  
  sendCommand("vis bn_home_5,1");
  sendCommand("vis bn_login_5,1");
  sendCommand("vis bn_cancel_5,1");
  sendCommand("vis text_user_id_5,1");
  sendCommand("vis text_pass_5,1");
  sendCommand("vis text_date_5,1");
  sendCommand("vis text_time_5,1");
  sendCommand("vis text_status_5,1");
  
  text_user_id_5_keypad_state = false;
}

void text_pass_5PopCallback(void *ptr)
{
  if (text_pass_5_keypad_state == false)
  {
    text_pass_5_keypad_show();
  }
  else
  {
    text_pass_5_keypad_hide();
  }
}
void text_pass_5_keypad_show()
{
  sendCommand("vis 255,0");
  sendCommand("vis bn_home_5,1");
  sendCommand("vis text_user_id_5,1");
  sendCommand("vis text_pass_5,1");
  sendCommand("vis text_date_5,1");
  sendCommand("vis text_time_5,1");
  sendCommand("vis text_status_5,1");
  sendCommand("vis bn_pass_5_1,1");
  sendCommand("vis bn_pass_5_2,1");
  sendCommand("vis bn_pass_5_3,1");
  sendCommand("vis bn_pass_5_4,1");
  sendCommand("vis bn_pass_5_5,1");
  sendCommand("vis bn_pass_5_6,1");
  sendCommand("vis bn_pass_5_7,1");
  sendCommand("vis bn_pass_5_8,1");
  sendCommand("vis bn_pass_5_9,1");
  sendCommand("vis bn_pass_5_0,1");
  sendCommand("vis bn_pass_5_ok,1");
  sendCommand("vis bn_pass_5_cl,1");
  
  text_pass_5_keypad_state = true;
}
void text_pass_5_keypad_hide()
{
  sendCommand("vis 255,0");
  
  sendCommand("vis bn_home_5,1");
  sendCommand("vis bn_login_5,1");
  sendCommand("vis bn_cancel_5,1");
  sendCommand("vis text_user_id_5,1");
  sendCommand("vis text_pass_5,1");
  sendCommand("vis text_date_5,1");
  sendCommand("vis text_time_5,1");
  sendCommand("vis text_status_5,1");
  
  text_pass_5_keypad_state = false;
}

void bn_user_5_okPopCallback(void *ptr)
{
  text_user_id_5_keypad_hide();
}
void bn_pass_5_okPopCallback(void *ptr)
{
  text_pass_5_keypad_hide();
}
void bn_login_5PopCallback(void *ptr)
{
  memset(buffer_username, 0, sizeof(buffer_username));
  text_user_id_5.getText(buffer_username, sizeof(buffer_username));

  memset(buffer_password, 0, sizeof(buffer_password));
  text_pass_5.getText(buffer_password, sizeof(buffer_password));

  dbvarFile = SD.open(sys_var, FILE_WRITE);

  if (!dbvarFile)
  {
      dbvarFile = SD.open(sys_var, FILE_WRITE);
  }
  if (dbvarFile)
  {
     EDB_Status result = db.readRec(1, EDB_REC logEventVar);
        if (result == EDB_OK)
        {
          if (array_cmp(logEventVar.username,buffer_username,11,11) == true)
          {
            if (array_cmp(logEventVar.password,buffer_password,5,5) == true)
            {
              login_success.show();              
              return;
            }
          }
          else{
            trans_failed.show();
          }
        }
        else 
        {
          memcpy(system_status,"DB Error  ",10);
          trans_failed.show();
        }
     }
  else
  {
        text_user_id_5.setText("DB Error");
  }

}
/*
void bn_liq_levelPopCallback(void *ptr)
{
  liq_level.show();
  //update_system_requirements();
}
void bn_trans_hisPopCallback(void *ptr)
{
  trans_his.show();
  //update_system_requirements();
}
void bn_settingsPopCallback(void *ptr)
{
  settings_menu.show();
  //update_system_requirements();
}
void bn_datetimePopCallback(void *ptr)
{
  datetime.show();
  //update_system_requirements();
}
void bn_liqpricePopCallback(void *ptr)
{
  liqprice.show();
  //update_system_requirements();
}
void bn_accessPopCallback(void *ptr)
{
  access.show();
  //update_system_requirements();
}
*/

void text_amount_16_keypad_show()
{
  sendCommand("vis 255,0");
  sendCommand("vis bn_home_16,1");
  sendCommand("vis text_amount_16,1");
  sendCommand("vis text_date_16,1");
  sendCommand("vis text_time_16,1");
  sendCommand("vis text_status_16,1");
  sendCommand("vis bn_manual_1,1");
  sendCommand("vis bn_manual_2,1");
  sendCommand("vis bn_manual_3,1");
  sendCommand("vis bn_manual_4,1");
  sendCommand("vis bn_manual_5,1");
  sendCommand("vis bn_manual_6,1");
  sendCommand("vis bn_manual_7,1");
  sendCommand("vis bn_manual_8,1");
  sendCommand("vis bn_manual_9,1");
  sendCommand("vis bn_manual_0,1");
  sendCommand("vis bn_manual_ok,1");
  sendCommand("vis bn_manual_cl,1");
  
  text_amount_16_keypad_state = true;
}

void text_amount_16_keypad_hide()
{
  sendCommand("vis 255,0");
  
  sendCommand("vis bn_home_16,1");
  sendCommand("vis text_amount_16,1");
  sendCommand("vis bn_con_manual,1");
  
  sendCommand("vis text_date_16,1");
  sendCommand("vis text_time_16,1");
  sendCommand("vis text_status_16,1");
    
  text_amount_16_keypad_state = false;
}
void text_amount_16PopCallback(void *ptr)
{
  if (text_amount_16_keypad_state == false)
  {
    text_amount_16_keypad_show();
  }
  else
  {
    text_amount_16_keypad_hide();
  }
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

float get_quantity()
{
  quantity_in_ml = current_liquid_amount_float * 1000;
  return quantity_in_ml;
}



void setup() {
  // put your setup code here, to run once:
nexInit();
HMISerial.begin(9600);

pinMode(outputValve, OUTPUT);
digitalWrite(outputValve, HIGH);

pinMode(statusLed, OUTPUT);
digitalWrite(statusLed, HIGH);

pinMode(sensorPin, INPUT);
pinMode(sensorPin, HIGH);

pulseCount = 0;
flowRate = 0.0;
flowMillilitres = 0;
totalMillilitres = 0;
oldTime = 0;

//homepage.attachPop(homepagePopCallback);
//bn_buy_liquid.attachPop(bn_buy_liquidPopCallback);
//bn_admin_login.attachPop(bn_admin_loginPopCallback);

//bn_home_1.attachPop(bn_main_menuPopCallback);
//bn_con_trans.attachPop(bn_con_transPopCallback);

//con_trans.attachPop(con_transPopCallback);
//bn_home_2.attachPop(bn_main_menuPopCallback);
text_phone_no.attachPop(text_phone_noPopCallback);
text_amount_2.attachPop(text_amount_2PopCallback);
bn_phone_ok.attachPop(bn_phone_okPopCallback);
bn_amount_ok.attachPop(bn_amount_okPopCallback);
bn_con_details.attachPop(bn_con_detailsPopCallback);


//bn_home_3.attachPop(bn_main_menuPopCallback);
//bn_try_again.attachPop(bn_try_againPopCallback);
//bn_cancel_3.attachPop(bn_main_menuPopCallback);

//bn_home_4.attachPop(bn_main_menuPopCallback);
bn_pour_liquid.attachPop(bn_pour_liquidPopCallback);

//bn_home_5.attachPop(bn_main_menuPopCallback);
bn_login_5.attachPop(bn_login_5PopCallback);
//bn_cancel_5.attachPop(bn_main_menuPopCallback);
bn_user_5_ok.attachPop(bn_user_5_okPopCallback);
bn_pass_5_ok.attachPop(bn_pass_5_okPopCallback);
text_user_id_5.attachPop(text_user_id_5PopCallback);
text_pass_5.attachPop(text_pass_5PopCallback);
//admin_login.attachPop(admin_loginPopCallback);

//bn_liq_level_6.attachPop(bn_liq_levelPopCallback);
//bn_trans_his_6.attachPop(bn_trans_hisPopCallback);
//bn_settings_6.attachPop(bn_settingsPopCallback);
//bn_home_6.attachPop(bn_main_menuPopCallback);

//bn_liq_level_8.attachPop(bn_liq_levelPopCallback);
//bn_trans_his_8.attachPop(bn_trans_hisPopCallback);
//bn_settings_8.attachPop(bn_settingsPopCallback);
//bn_home_8.attachPop(bn_main_menuPopCallback);

//bn_liq_level_9.attachPop(bn_liq_levelPopCallback);
//bn_trans_his_9.attachPop(bn_trans_hisPopCallback);
//bn_settings_9.attachPop(bn_settingsPopCallback);
//bn_home_9.attachPop(bn_main_menuPopCallback);

//bn_datetime_10.attachPop(bn_datetimePopCallback);
//bn_liqprice_10.attachPop(bn_liqpricePopCallback);
//bn_access_10.attachPop(bn_accessPopCallback);
//bn_home_10.attachPop(bn_main_menuPopCallback);

//bn_datetime_11.attachPop(bn_datetimePopCallback);
//bn_liqprice_11.attachPop(bn_liqpricePopCallback);
//bn_access_11.attachPop(bn_accessPopCallback);
//bn_home_11.attachPop(bn_main_menuPopCallback);
bn_adjdatetime.attachPop(bn_adjdatetimePopCallback);

//bn_datetime_12.attachPop(bn_datetimePopCallback);
//bn_liqprice_12.attachPop(bn_liqpricePopCallback);
//bn_access_12.attachPop(bn_accessPopCallback);
//bn_home_12.attachPop(bn_main_menuPopCallback);
bn_adjliqprice.attachPop(bn_adjliqpricePopCallback);

//bn_datetime_13.attachPop(bn_datetimePopCallback);
//bn_liqprice_13.attachPop(bn_liqpricePopCallback);
//bn_access_13.attachPop(bn_accessPopCallback);
//bn_home_13.attachPop(bn_main_menuPopCallback);
bn_adjpass_13.attachPop(bn_adjpasswordPopCallback);

//bn_datetime_15.attachPop(bn_datetimePopCallback);
//bn_liqprice_15.attachPop(bn_liqpricePopCallback);
//bn_access_15.attachPop(bn_accessPopCallback);
//bn_home_15.attachPop(bn_main_menuPopCallback);

if (!SD.begin(SD_PIN))
{
    memcpy(system_status,"DB Error  ",10);
}
if (!SD.exists("/db"))
{
    memcpy(system_status,"DB Error  ",10);
}
if (SD.exists(trans_db)){
    dbFile = SD.open(trans_db, FILE_WRITE);
    
    if (!dbFile)
    {
      memcpy(system_status,"DB Error  ",10);
    }
    if (dbFile){
      EDB_Status result = db.open(0);
      if (result == EDB_OK)
      {
        memcpy(system_status,"System OK ",10);
      }
      else 
      {
        memcpy(system_status,"DB Error  ",10);
      }
    }
    else 
      {
            memcpy(system_status,"DB Error  ",10);
      } 
    }
    else 
    {
      memcpy(system_status,"DB Error  ",10);
    }
//   update_system_requirements();
  attachInterrupt (sensorInterrupt, pulseCounter, FALLING);
}

void loop() {
  // put your main code here, to run repeatedly:
 unsigned long nowtime = millis(); 
 unsigned long update = 0;
 if (nowtime > update)
 {
   pagenumber();
   update += 1000;
 } 
nexLoop(nex_listen_list);
}
void pagenumber()
{
    sendCurrentPageId(&page_number);// call the method to get the page number.

if (page_number == current_page)
{
      
}
else
{ 
  switch(page_number)
  {// use a switch statement for each page. 
         
        case 2:    //for page2
          text_phone_no_keypad_hide();
          current_page = page_number;
       // do something
        break;
        
       case 3:
       
        break;
         
        case 5:    //for page5
          text_user_id_5_keypad_hide();
          current_page = page_number;
          // do something
            break;
           
         case 8:    //for page0
          //dbSerialPrintln(number);// print the page number again for testing.
       // do something
        break;

        default:

        break;
 
       }// close switch statement.
} 
delay(10);
}
//Database functions
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
  logEventWrite.id = db.count()+1;
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

