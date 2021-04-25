#define _millis() millis()

unsigned long last_user_activity = _millis();

unsigned char    driver_control_buttonsPins[]  = {37,   39};
bool driver_control_isPositive[]   = {true, true};
// Do not change:
bool driver_control_pressed[]      = {false, false};
byte buttons_purpose[] = {BUTTON_SELECT, BUTTON_BACK};
unsigned long driver_control_time_pressed[]    = {0, 0};


void driver_controls_setup(){
  for (unsigned char i=0; i<DRIVER_CONTROLS_TOTALBUTTONS; i++){
    pinMode(driver_control_buttonsPins[i], INPUT);
  }
  last_user_activity = _millis();
}

/*
#define EVENT_BUTTON_PRESSED            0x00
#define EVENT_BUTTON_RELEASED           0x01
#define EVENT_BUTTON_LONG_PRESS         0x02
*/
void driver_controls_loop(){
  for (unsigned char i=0; i<DRIVER_CONTROLS_TOTALBUTTONS; i++){
    //if (digitalRead(driver_control_buttonsPins[i])){
    if ((driver_control_isPositive[i]==true) ? (!digitalRead(driver_control_buttonsPins[i])) : (digitalRead(driver_control_buttonsPins[i]))){

      last_user_activity = _millis();
      if(driver_control_pressed[i]==false){
        // press start
        driver_control_pressed[i]=true;
        driver_control_time_pressed[i] = _millis();
        onButtonEvent(EVENT_BUTTON_PRESSED, i);
      }else{
        // was pressed
        if(_millis()-driver_control_time_pressed[i]>DRIVER_CONTROLS_DELAY_BEFOR_LONG_PRESS){
          // long press
          driver_control_time_pressed[i]=-1;
          onButtonEvent(EVENT_BUTTON_LONG_PRESS, i);
        }
      }

    }else{
      if(driver_control_pressed[i]==true){
        // released
        driver_control_pressed[i]=false;
        onButtonEvent(EVENT_BUTTON_RELEASED, i);
        if(_millis()-driver_control_time_pressed[i]<DRIVER_CONTROLS_DELAY_BEFOR_LONG_PRESS){
            onButtonEvent(EVENT_BUTTON_SHORT_PRESS, i);
        }
      }
    }
  }

}

unsigned long driver_control_get_last_user_avtivity(){
  return last_user_activity;
}

void driver_control_set_last_user_avtivity(unsigned long time){
  last_user_activity = time;
}

void onButtonEvent(unsigned char event, int button){
  currentApp->onEvent(event, buttons_purpose[button], 0);
}