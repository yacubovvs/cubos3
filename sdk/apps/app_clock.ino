#define appNameClass    ClockApp          // App name without spaces
#define appName         "Clock"              // App name with spaces 

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
      
};

void appNameClass::onCreate(){
    DRAW_LIMITS_setEnable(true);
    DRAW_LIMIT_reset();
    //DRAW_LIMITS_setEnable(STYLE_STATUSBAR_HEIGHT, -1, -1, -1);

    setBackgroundColor(0,0,0);
    setContrastColor(255, 255, 255);
    this->draw_current_time(true);
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


#define NARROW_CLOCK_STRING1 18
#define NARROW_CLOCK_STRING2 73
#define NARROW_CLOCK_STRING3 125
void appNameClass::draw_current_time(bool draw){
    if(draw){
        // Draw
        setDrawColor_ContrastColor();
        this->timeString = core_time_getHourMinuteSecondsTime();
        #ifdef NARROW_SCREEN
            #define GRAY_HOURS 128

            setDrawColor(GRAY_HOURS, GRAY_HOURS, GRAY_HOURS);
            drawString_centered_fontSize(this->timeString.substring(0,2), NARROW_CLOCK_STRING1, 6);
            setDrawColor(255, 255, 255);
            drawString_centered_fontSize(this->timeString.substring(3,5), NARROW_CLOCK_STRING2, 6);
            setDrawColor(GRAY_HOURS, 0, 0);
            drawString_centered_fontSize(this->timeString.substring(6,8), NARROW_CLOCK_STRING3, 4);
            
        #else
            drawString(this->timeString, 2, 90, 5);
        #endif
    }else{
        // Clear
        setDrawColor_BackGoundColor();
        #ifdef NARROW_SCREEN
            drawString_centered_fontSize(this->timeString.substring(0,2), NARROW_CLOCK_STRING1, 6);
            drawString_centered_fontSize(this->timeString.substring(3,5), NARROW_CLOCK_STRING2, 6);
            drawString_centered_fontSize(this->timeString.substring(6,8), NARROW_CLOCK_STRING3, 4);
        #else
            clearString(this->timeString, 2, 90, 5);
        #endif
    }

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