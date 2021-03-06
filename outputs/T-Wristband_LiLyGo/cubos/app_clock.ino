#define appNameClass    ClockApp          // App name without spaces
#define appName         "Clock"              // App name with spaces 

#ifndef APP_CLOCK_POWER_AFTER_SECONDS
    #define APP_CLOCK_POWER_AFTER_SECONDS 0 
#endif

#ifdef PLATFORM_PC_EMULATOR
    long get_pedometer_days_steps(){
        return 12315;
    }
#endif

class appNameClass: public Application{
    public:
        bool isfullScreen         = true;
        virtual void onLoop() override;
        virtual void onDestroy() override;
        virtual void onEvent(unsigned char event, int val1, int val2) override;

        void onCreate();
        appNameClass(){ 
            fillScreen(0, 0, 0); 
            this->showStatusBar = false;
            super_onCreate(); 
            onCreate(); 
        };
        static unsigned const char* getParams(const unsigned char type){
            switch(type){ 
              case PARAM_TYPE_NAME: return (unsigned char*)appName; 
              case PARAM_TYPE_ICON: return icon;
              default: return (unsigned char*)""; }
        };
        const static unsigned char icon[] PROGMEM;

        void draw_current_time(bool draw);
        String timeString;

        unsigned char last_seconds  = 0;
        String last_hours           = "";
        String last_minutes         = "";

        String last_date            = "";
        String sleep_time           = "";

        #ifdef BATTERY_ENABLE
            unsigned char last_battery  = 0;
            bool last_battery_charging  = "";
        #endif

        #if defined(PEDOMETER_ENABLE) || defined(PEDOMETER_EMULATOR)
            unsigned int last_pedometer   = 0;
        #endif

        void drawSecondsCircle(bool draw, unsigned char second);
        #ifdef PEDOMETER_ENABLE
            void drawStepsCircle(bool draw);
        #endif
      
};

#define SECONDS_CIRCLE_X        (SCREEN_WIDTH/2)
#define SECONDS_CIRCLE_Y        (SCREEN_HEIGHT/2 - 20)
#define SECONDS_CIRCLE_RADIUS   (SCREEN_WIDTH/2-2)
#define BATTERY_LABEL_Y_POSITION (STYLE_STATUSBAR_HEIGHT/2 + 2)

void appNameClass::onCreate(){
    DRAW_LIMITS_setEnable(true);
    DRAW_LIMIT_reset();
    
    setBackgroundColor(0,0,0);
    setContrastColor(255, 255, 255);

    setDrawColor(48, 48, 48);
    drawCircle(SECONDS_CIRCLE_X, SECONDS_CIRCLE_Y, SECONDS_CIRCLE_RADIUS-1, true);

    this->last_seconds = core_time_getSeconds_byte();
    for(unsigned char isecond=0; isecond<=this->last_seconds; isecond++) this->drawSecondsCircle(true, isecond);
    this->draw_current_time(true);
    #ifdef PEDOMETER_ENABLE
        this->drawStepsCircle(true);
    #endif

    this->sleep_device_after = APP_CLOCK_POWER_AFTER_SECONDS;

}

void appNameClass::onLoop(){
    /*
        Write you code onLoop here
    */
}

void appNameClass::onDestroy(){
    /*
        Write you code onDestroy here
    */
}

void appNameClass::onEvent(unsigned char event, int val1, int val2){
    
    if(event==EVENT_BUTTON_PRESSED){
        // Write you code on [val1] button pressed here
        #if DRIVER_CONTROLS_TOTALBUTTONS > 3
            if(val1==BUTTON_BACK){
                startApp(-1);
            }
        #else 
            if(val1==BUTTON_POWER){
                startApp(-1);
            }    
        #endif
        
    }else if(event==EVENT_BUTTON_RELEASED){
        // Write you code on [val1] button released here
    }else if(event==EVENT_BUTTON_LONG_PRESS){
        // Write you code on [val1] button long press here
        if(val1==BUTTON_SELECT){

            #if DRIVER_CONTROLS_TOTALBUTTONS == 1
                startApp(-1);
            #elif DRIVER_CONTROLS_TOTALBUTTONS == 2
                startApp(-1);
            #else
            #endif
        }
    }else if(event==EVENT_ON_TIME_CHANGED){
        // Write you code on system time changed
        this->draw_current_time(false);
        this->draw_current_time(true);
    }else if(event==EVENT_ON_GOING_TO_SLEEP){
        this->draw_current_time(false);
    }else if(event==EVENT_ON_WAKE_UP){
        this->draw_current_time(true);
    }else if(event==EVENT_ON_TOUCH_DOUBLE_PRESS){
        if(val1==BUTTON_SELECT){
            startApp(-1);
        }
    }
    
}

/*
#define NARROW_CLOCK_STRING1 18
#define NARROW_CLOCK_STRING2 73
#define NARROW_CLOCK_STRING3 125
*/

#ifdef PEDOMETER_ENABLE
    void appNameClass::drawStepsCircle(bool draw){
        if(draw){
            //int grad_i = (long)360 * (long)6800 / (long)10000;
            int grad_i = (long)360 * (long)get_pedometer_days_steps() / (long)get_pedometer_days_steps_min_limit();
            if(grad_i>360) grad_i = 360;
            for(int grad=0; grad<=grad_i; grad++){
                
                setGradientColor(46, 255, 0, 255, 85, 0, 360, grad);
                drawArc(SECONDS_CIRCLE_X, SECONDS_CIRCLE_Y, SECONDS_CIRCLE_RADIUS-4, -90 + grad, -90 + grad + 2, 8, true);
            }
        }else{
            setDrawColor_BackGroundColor();
            int grad = 360;
            drawArc(SECONDS_CIRCLE_X, SECONDS_CIRCLE_Y, SECONDS_CIRCLE_RADIUS-4, -90 + 0, -90 + grad + 8, 8, true);
        }
    }
#endif

void appNameClass::drawSecondsCircle(bool draw, unsigned char second){
    if(draw) setDrawColor(0, 0, 255);
    else setDrawColor_BackGroundColor();

    int grad = 6*second;
 
    drawArc(SECONDS_CIRCLE_X, SECONDS_CIRCLE_Y, SECONDS_CIRCLE_RADIUS, -90 + grad, -90 + grad + 6, 4, true);
}

void appNameClass::draw_current_time(bool draw){
    #define CLOCK_FONT      2
    #define CLOCK_MARGIN    3
    #define STRINGS_OFFSET  2

    //this->preventSleep         = true;
    //this->preventInAppSleep    = true;

    #ifdef NARROW_SCREEN
        // Draw
        if(draw){
            // SECONDS CIRCLE
            this->timeString = core_time_getHourMinuteSecondsTime();
            unsigned char seconds_draw;
            if(core_time_getSeconds_byte()>this->last_seconds) seconds_draw = core_time_getSeconds_byte() - this->last_seconds;
            else seconds_draw = 1;
            
            this->last_seconds = core_time_getSeconds_byte();
            for(char i_predrawSeconds=0; i_predrawSeconds<seconds_draw; i_predrawSeconds++) this->drawSecondsCircle(draw, this->last_seconds-i_predrawSeconds);

            setDrawColor_ContrastColor();

            this->last_hours    = core_time_getHours_String();
            this->last_minutes  = core_time_getMinutes_String();

            drawString_centered(core_time_getHours_String(), SCREEN_WIDTH/2, STRINGS_OFFSET + SECONDS_CIRCLE_Y-CLOCK_FONT*FONT_CHAR_HEIGHT - CLOCK_MARGIN, CLOCK_FONT);
            drawString_centered(core_time_getMinutes_String(), SCREEN_WIDTH/2, STRINGS_OFFSET + SECONDS_CIRCLE_Y + CLOCK_MARGIN, CLOCK_FONT);
            
        }else{
            if(this->last_seconds>core_time_getSeconds_byte()){
                // if munutes changed
                setDrawColor_BackGroundColor();  
                for(int isecond=0; isecond<60; isecond++){
                    drawSecondsCircle(draw, isecond);
                }

                setDrawColor(48, 48, 48);
                drawCircle(SECONDS_CIRCLE_X, SECONDS_CIRCLE_Y, SECONDS_CIRCLE_RADIUS-1, true);
                
                clearString_centered(last_hours, SCREEN_WIDTH/2, STRINGS_OFFSET + SECONDS_CIRCLE_Y-CLOCK_FONT*FONT_CHAR_HEIGHT - CLOCK_MARGIN, CLOCK_FONT);
                clearString_centered(last_minutes, SCREEN_WIDTH/2, STRINGS_OFFSET + SECONDS_CIRCLE_Y + CLOCK_MARGIN, CLOCK_FONT);
            }

        }


        // BATTERY
        #ifdef BATTERY_ENABLE
            if(draw){        
                last_battery            = driver_battery_getPercent();
                last_battery_charging   = driver_battery_isCharging();
            }

            #define STATUSBAR_LABELS_OFFSET_Y (-3)
            #define BATTERY_LABEL_ICON_OFFSET (-4)

            // (battery icon 32x16 px) 
            drawBatteryIcon(SCREEN_WIDTH/2 + 3 + BATTERY_LABEL_ICON_OFFSET, STATUSBAR_LABELS_OFFSET_Y+ BATTERY_LABEL_Y_POSITION - 8 + 1, last_battery, last_battery_charging, draw);
            String battery_percent_toPrint = String(last_battery) + "%";

            if(draw){
                setDrawColor_ContrastColor();
                drawString(battery_percent_toPrint, SCREEN_WIDTH/2 - battery_percent_toPrint.length()*FONT_CHAR_WIDTH - 3 + BATTERY_LABEL_ICON_OFFSET, STATUSBAR_LABELS_OFFSET_Y + BATTERY_LABEL_Y_POSITION - FONT_CHAR_HEIGHT/2 + 1, 1);
            }else{
                setDrawColor_BackGroundColor();  
                clearString(battery_percent_toPrint, SCREEN_WIDTH/2 - battery_percent_toPrint.length()*FONT_CHAR_WIDTH - 3 + BATTERY_LABEL_ICON_OFFSET, STATUSBAR_LABELS_OFFSET_Y + BATTERY_LABEL_Y_POSITION - FONT_CHAR_HEIGHT/2 + 1, 1);
            } 
        #endif        

        // SLEEP
        #define SLEEP_LABEL_POSITION_Y (SCREEN_HEIGHT - 35)
        // DATE
        #define DATE_LABEL_POSITION_Y (SCREEN_HEIGHT - 54)
        // PEDOMETER
        #define PEDOMETER_LABEL_POSITION_Y (SCREEN_HEIGHT - 14)
        #define PEDOMETER_LABEL_POSITION_X_OFFSET (0)
        #define PEDOMETER_LABEL_POSITION_PADDING (3)

        if(draw){
            this->last_date = core_time_getDateFull();
            setDrawColor(192,192,192);
            drawString_centered(this->last_date, SCREEN_WIDTH/2, DATE_LABEL_POSITION_Y, 1);
        }else{
            setDrawColor_BackGroundColor();  
            clearString_centered(this->last_date, SCREEN_WIDTH/2, DATE_LABEL_POSITION_Y, 1);
        }

        #if defined(PEDOMETER_ENABLE) || defined(PEDOMETER_EMULATOR)
            
            if(draw){
                this->last_pedometer = get_pedometer_days_steps();
                this->sleep_time = get_pedometer_days_sleep_hours();
            }

            String pedometer_toPrint = String(this->last_pedometer);
            String sleep_toPrint = String(this->sleep_time) + "  ";

            // 16px - leg and sleep icon width
            int pedometer_label_width_05 = (PEDOMETER_LABEL_POSITION_PADDING*2 + 16 + pedometer_toPrint.length()*FONT_CHAR_WIDTH)/2;
            int sleep_label_width_05 = (PEDOMETER_LABEL_POSITION_PADDING*2 + 16 + sleep_toPrint.length()*FONT_CHAR_WIDTH)/2;

            drawImage(draw, getIcon_legs_grey(), 
                SCREEN_WIDTH/2 + pedometer_label_width_05 - 16 + PEDOMETER_LABEL_POSITION_X_OFFSET, 
                PEDOMETER_LABEL_POSITION_Y + PEDOMETER_LABEL_POSITION_PADDING - 9
            );

            drawImage(draw, getIcon_sleep_grey(), 
                SCREEN_WIDTH/2 + sleep_label_width_05 - 16 + PEDOMETER_LABEL_POSITION_X_OFFSET, 
                SLEEP_LABEL_POSITION_Y + PEDOMETER_LABEL_POSITION_PADDING - 9
            );

            if(draw){
                
                setDrawColor(192,192,192);

                // PEDOMETER
                drawString(pedometer_toPrint, 
                    SCREEN_WIDTH/2 - pedometer_label_width_05 + PEDOMETER_LABEL_POSITION_X_OFFSET, 
                    PEDOMETER_LABEL_POSITION_Y + 1, 1);

                // SLEEP
                drawString_centered(sleep_toPrint, SCREEN_WIDTH/2, SLEEP_LABEL_POSITION_Y, 1);

            }else{

                setDrawColor_BackGroundColor();  
                
                // PEDOMETER
                clearString(pedometer_toPrint, 
                    SCREEN_WIDTH/2 - pedometer_label_width_05 + PEDOMETER_LABEL_POSITION_X_OFFSET, 
                    PEDOMETER_LABEL_POSITION_Y + 1, 1);
                // SLEEP
                clearString_centered(sleep_toPrint, SCREEN_WIDTH/2, SLEEP_LABEL_POSITION_Y, 1);
            }
            
        #endif
            
    #else
        if(draw){
            setDrawColor_ContrastColor();
            drawString(this->timeString, 2, 90, 5);
        }else{

            setDrawColor_BackGroundColor();
            clearString(this->timeString, 2, 90, 5);
            
        }
    #endif

    /*
    this->timeString = core_time_getHourMinuteSecondsTime();
    setDrawColor(0, 0, 0);
    clearString(this->timeString, 2, 90, 5);
    setDrawColor(255, 255, 255);
    drawString(this->timeString, 2, 90, 5);
    */
}

const unsigned char appNameClass::icon[] PROGMEM = {
    
	/*            PUT YOUR ICON HERE            */

    0x02,0x01,0x02,0x20,0x02,0x20,0x04,0x00,0x66,0xff,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x0F,0xF0,0x00,0x00,0x3F,0xFC,0x00,0x00,
    0xFF,0xFF,0x00,0x01,0xFF,0xFF,0x80,0x03,0xFF,0xFF,0xC0,0x07,0xFF,0xFF,0xE0,0x0F,0xFF,0xFF,0xF0,0x1F,0xFF,0xFF,0xE0,0x19,0xFF,0xFF,0x80,
    0x18,0x7F,0xFE,0x00,0x3E,0x1F,0xF8,0x1C,0x3F,0x87,0xE0,0x7C,0x3F,0xE1,0x81,0xFC,0x3F,0xF8,0x07,0xFC,0x3F,0xFE,0x1F,0xFC,0x3F,0xFE,0x7F,
    0xFC,0x3F,0xFE,0x7F,0xFC,0x3F,0xFE,0x7F,0xFC,0x1F,0xFE,0x7F,0xF8,0x1F,0xFE,0x7F,0xF8,0x0F,0xFE,0x7F,0xF0,0x0F,0xFE,0x7F,0xF0,0x07,0xFE,
    0x7F,0xE0,0x03,0xFE,0x7F,0xC0,0x01,0xFE,0x7F,0x80,0x00,0xFE,0x7F,0x00,0x00,0x3E,0x7C,0x00,0x00,0x0E,0x70,0x00,0x00,0x00,0x00,0x00,0x00,
    0x00,0x00,0x00,0x04,0xff,0xff,0xff,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
    0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x04,0x00,0x00,0x00,0x1C,0x06,0x00,0x00,0x78,0x07,0x80,0x01,
    0xE0,0x01,0xE0,0x07,0x80,0x00,0x78,0x1E,0x00,0x00,0x1E,0x78,0x00,0x00,0x07,0xE0,0x00,0x00,0x01,0x80,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
    0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
    0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
    0x04,0xb4,0xb4,0xb4,0x00,0x0F,0xF0,0x00,0x00,0x7F,0xFE,0x00,0x01,0xF0,0x0F,0x80,0x03,0xC0,0x03,0xC0,0x07,0x00,0x00,0xE0,0x0E,0x00,0x00,
    0x70,0x1C,0x00,0x00,0x38,0x38,0x00,0x00,0x1C,0x30,0x00,0x00,0x08,0x60,0x00,0x00,0x02,0x60,0x00,0x00,0x06,0x60,0x00,0x00,0x06,0xC0,0x00,
    0x00,0x03,0xC0,0x00,0x00,0x03,0xC0,0x00,0x00,0x03,0xC0,0x00,0x00,0x03,0xC0,0x00,0x00,0x03,0xC0,0x00,0x00,0x03,0xC0,0x00,0x00,0x03,0xC0,
    0x00,0x00,0x03,0x60,0x00,0x00,0x06,0x60,0x00,0x00,0x06,0x70,0x00,0x00,0x0E,0x30,0x00,0x00,0x0C,0x38,0x00,0x00,0x1C,0x1C,0x00,0x00,0x38,
    0x0E,0x00,0x00,0x70,0x07,0x00,0x00,0xE0,0x03,0xC0,0x03,0xC0,0x01,0xF0,0x0F,0x80,0x00,0x7E,0x7E,0x00,0x00,0x0E,0x70,0x00,0x04,0x00,0x00,
    0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
    0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x18,0x00,0x00,0x00,0x60,0x00,
    0x00,0x01,0x80,0x00,0x00,0x06,0x00,0x00,0x00,0x18,0x00,0x00,0x00,0x60,0x00,0x00,0x01,0x80,0x00,0x00,0x01,0x80,0x00,0x00,0x01,0x80,0x00,
    0x00,0x01,0x80,0x00,0x00,0x01,0x80,0x00,0x00,0x01,0x80,0x00,0x00,0x01,0x80,0x00,0x00,0x01,0x80,0x00,0x00,0x01,0x80,0x00,0x00,0x01,0x80,
    0x00,0x00,0x01,0x80,0x00,0x00,0x01,0x80,0x00,0x00,0x01,0x80,0x00,0x00,0x01,0x80,0x00,0x00,0x01,0x80,0x00,

   
};