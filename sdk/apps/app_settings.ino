#define appNameClass    SettingsApp          // App name without spaces
#define appName         "Settings"              // App name with spaces 


#define ELEMENT_POSITION_OFFSET     55
#define ELEMENT_HEIGHT      45

class appNameClass: public Application{
    public:
        virtual void onLoop() override;
        virtual void onDestroy() override;
        virtual void onEvent(byte event, int val1, int val2) override;
        void onCreate();
        appNameClass(){ fillScreen(64, 64, 64); super_onCreate(); onCreate(); };
        static unsigned const char* getParams(const unsigned char type){
            switch(type){ 
              case PARAM_TYPE_NAME: return (unsigned char*)appName; 
              case PARAM_TYPE_ICON: return icon;
              default: return (unsigned char*)""; }
        };
        const static byte icon[] PROGMEM;

        const static byte icon_sound[]      PROGMEM;
        const static byte icon_light[]      PROGMEM;
        const static byte icon_time[]       PROGMEM;
        const static byte icon_date[]       PROGMEM;
        const static byte icon_battery[]    PROGMEM;
        const static byte arrow[]           PROGMEM;
      
};

void appNameClass::onCreate(){ 
    
    drawMenuElement(true, 35, STYLE_STATUSBAR_HEIGHT + 15 + ELEMENT_POSITION_OFFSET*0, SCREEN_WIDTH-10-35, ELEMENT_HEIGHT, this->icon_sound,    "Notifications and sound", "Volume, vibration level");
    drawMenuElement(true, 35, STYLE_STATUSBAR_HEIGHT + 15 + ELEMENT_POSITION_OFFSET*1, SCREEN_WIDTH-10-35, ELEMENT_HEIGHT, this->icon_light,    "Screen light", "100%");
    drawMenuElement(true, 35, STYLE_STATUSBAR_HEIGHT + 15 + ELEMENT_POSITION_OFFSET*2, SCREEN_WIDTH-10-35, ELEMENT_HEIGHT, this->icon_time,     "Setting time", "10:28:01");
    drawMenuElement(true, 35, STYLE_STATUSBAR_HEIGHT + 15 + ELEMENT_POSITION_OFFSET*3, SCREEN_WIDTH-10-35, ELEMENT_HEIGHT, this->icon_date,     "Date", "11.12.2020");
    drawMenuElement(true, 35, STYLE_STATUSBAR_HEIGHT + 15 + ELEMENT_POSITION_OFFSET*3, SCREEN_WIDTH-10-35, ELEMENT_HEIGHT, this->icon_battery,  "Battery", "100%");

    drawIcon(true, this->arrow, 12, STYLE_STATUSBAR_HEIGHT + 15 + ELEMENT_POSITION_OFFSET*0 + ELEMENT_HEIGHT/2 - 4);
    /*
        Write you code onCreate here
    */
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

void appNameClass::onEvent(byte event, int val1, int val2){
    
    if(event==EVENT_BUTTON_PRESSED){
        // Write you code on [val1] button pressed here
        if(val1==BUTTON_BACK){
            startApp(-1);
        }
    }else if(event==EVENT_BUTTON_RELEASED){
        // Write you code on [val1] button released here
    }else if(event==EVENT_BUTTON_LONG_PRESS){
        // Write you code on [val1] button long press here
    }else if(event==EVENT_ON_TIME_CHANGED){
        // Write you code on system time changed
    }
    
}

const byte appNameClass::arrow[] PROGMEM = {
    0x02,0x01,0x02,0x08,0x02,0x08,0x04,0xff,0xff,0xff,0x80,0xE0,0xF8,0xFF,0xFF,0xF8,0xE0,0x80,
};

const byte appNameClass::icon_sound[] PROGMEM = {
    0x02,0x01,0x02,0x10,0x02,0x10,0x04,0xff,0xff,0xff,0x01,0x01,0x03,0x01,0x07,0x05,0x0F,0x05,0x1F,0x15,0xBF,
    0x15,0xBF,0x55,0xBF,0x55,0xBF,0x55,0xBF,0x55,0xBF,0x15,0x1F,0x15,0x0F,0x05,0x07,0x05,0x03,0x01,0x01,0x01,
};

const byte appNameClass::icon_light[] PROGMEM = {
    0x02,0x01,0x02,0x10,0x02,0x10,0x04,0xff,0xd9,0x00,0x03,0xC0,0x0F,0x30,0x1F,0x08,0x3F,0x04,0x7F,0x02,0x7F,
    0x02,0xFF,0x01,0xFF,0x01,0xFF,0x01,0xFF,0x01,0x7F,0x02,0x7F,0x02,0x3F,0x04,0x1F,0x08,0x0F,0x30,0x03,0xC0,
};

const byte appNameClass::icon_time[] PROGMEM = {
    0x02,0x01,0x02,0x10,0x02,0x10,0x04,0xff,0xff,0xff,0x03,0xC0,0x0C,0x30,0x10,0x08,0x20,0x04,0x48,0x32,0x44,
    0x72,0x82,0xE1,0x81,0xC1,0x81,0x81,0x80,0x01,0x40,0x02,0x40,0x02,0x20,0x04,0x10,0x08,0x0C,0x30,0x03,0xC0,
};

const byte appNameClass::icon_date[] PROGMEM = {
    0x02,0x01,0x02,0x10,0x02,0x10,0x04,0xff,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
    0x18,0x00,0x18,0x00,0x00,0x00,0x18,0x00,0x18,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
    0x04,0xff,0xff,0xff,0xFF,0xFF,0x80,0x01,0xFF,0xFF,0xFF,0xFF,0x80,0x01,0x80,0x01,0x80,0x01,0x80,0x01,0x80,
    0x01,0x80,0x01,0x80,0x01,0x80,0x01,0x80,0x01,0x80,0x01,0x80,0x01,0xFF,0xFF,0x04,0xb4,0xb4,0xb4,0x00,0x00,
    0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x19,0x80,0x19,0x80,0x00,0x00,0x19,0x80,0x19,0x80,0x00,0x00,0x19,
    0x80,0x19,0x80,0x00,0x00,0x00,0x00,0x00,0x00,
};

const byte appNameClass::icon_battery[] PROGMEM = {
    0x02,0x01,0x02,0x10,0x02,0x10,0x04,0x33,0xff,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
    0x00,0x1F,0xF8,0x1F,0xF8,0x1F,0xF8,0x1F,0xF8,0x1F,0xF8,0x1F,0xF8,0x1F,0xF8,0x1F,0xF8,0x1F,0xF8,0x00,0x00,
    0x04,0xff,0xff,0xff,0x01,0x80,0x1F,0xF8,0x20,0x04,0x20,0x04,0x20,0x04,0x20,0x04,0x20,0x04,0x20,0x04,0x20,
    0x04,0x20,0x04,0x20,0x04,0x20,0x04,0x20,0x04,0x20,0x04,0x20,0x04,0x3F,0xFC,
};

const byte appNameClass::icon[] PROGMEM = {
    
	/*            PUT YOUR ICON HERE            */

    0x02,0x01,0x02,0x20,0x02,0x20,0x04,0xff,0xff,0xff,0x00,0x00,0x00,0x00,0x00,0x00,
    0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
    0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
    0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x03,0xC0,0x00,0x00,0x07,
    0xE0,0x00,0x00,0x0F,0xF0,0x00,0x00,0x0F,0xF0,0x00,0x00,0x0F,0xF0,0x00,0x00,0x0F,
    0xF0,0x00,0x00,0x07,0xE0,0x00,0x00,0x03,0xC0,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
    0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
    0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
    0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x04,0xb4,0xb4,0xb4,0x00,0x0F,
    0xF0,0x00,0x00,0x0F,0xF0,0x00,0x00,0x0F,0xF0,0x00,0x00,0x0F,0xF0,0x00,0x08,0x0F,
    0xF0,0x10,0x1C,0x3F,0xFC,0x38,0x3E,0x7F,0xFE,0x7C,0x7F,0xF8,0x1F,0xFE,0xFF,0xE0,
    0x07,0xFF,0xFF,0xC0,0x03,0xFF,0x7F,0x80,0x01,0xFE,0x3F,0x00,0x00,0xFC,0x1F,0x00,
    0x00,0xF8,0x0E,0x00,0x00,0x70,0x0E,0x00,0x00,0x70,0x0E,0x00,0x00,0x70,0x0E,0x00,
    0x00,0x70,0x0E,0x00,0x00,0x70,0x0E,0x00,0x00,0x70,0x1F,0x00,0x00,0xF8,0x3F,0x00,
    0x00,0xFC,0x7F,0x80,0x01,0xFE,0xFF,0xC0,0x03,0xFF,0xFF,0xE0,0x07,0xFF,0x7F,0xF8,
    0x1F,0xFE,0x3E,0x7F,0xFE,0x7C,0x1C,0x3F,0xFC,0x38,0x08,0x0F,0xF0,0x10,0x00,0x0F,
    0xF0,0x00,0x00,0x0F,0xF0,0x00,0x00,0x0F,0xF0,0x00,0x00,0x0F,0xF0,0x00,0x04,0x47,
    0x47,0x47,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
    0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x07,
    0xE0,0x00,0x00,0x1F,0xF8,0x00,0x00,0x3F,0xFC,0x00,0x00,0x7F,0xFE,0x00,0x00,0xFF,
    0xFF,0x00,0x00,0xFC,0x3F,0x00,0x01,0xF8,0x1F,0x80,0x01,0xF0,0x0F,0x80,0x01,0xF0,
    0x0F,0x80,0x01,0xF0,0x0F,0x80,0x01,0xF0,0x0F,0x80,0x01,0xF8,0x1F,0x80,0x00,0xFC,
    0x3F,0x00,0x00,0xFF,0xFF,0x00,0x00,0x7F,0xFE,0x00,0x00,0x3F,0xFC,0x00,0x00,0x1F,
    0xF8,0x00,0x00,0x07,0xE0,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
    0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
    0x00,0x00,
};