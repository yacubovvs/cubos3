#define appNameClass    InternetApp          // App name without spaces
#define appName         "Internet"              // App name with spaces 

class appNameClass: public Application{
    public:
        virtual void onLoop() override;
        virtual void onDestroy() override;
        virtual void onEvent(unsigned char event, int val1, int val2) override;

        void onCreate();
        appNameClass(){ fillScreen(0, 0, 0); super_onCreate(); onCreate(); };
        static unsigned const char* getParams(const unsigned char type){
            switch(type){ 
              case PARAM_TYPE_NAME: return (unsigned char*)appName; 
              case PARAM_TYPE_ICON: return icon;
              default: return (unsigned char*)""; }
        };
        const static unsigned char icon[] PROGMEM;
      
};

void appNameClass::onCreate(){
    /*
        Write you code onCreate here
    */
    setDrawColor(255, 255, 255);
    drawString(appName, 5, STYLE_STATUSBAR_HEIGHT + 10, 2);
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

const unsigned char appNameClass::icon[] PROGMEM = {
    
	/*            PUT YOUR ICON HERE            */

        0x02,0x01,0x02,0x20,0x02,0x20,0x04,0x33,0xff,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
        0x00,0x03,0xC0,0x00,0x40,0x07,0xF0,0x00,0xE0,0x0F,0xF0,0x00,0xF0,0x1F,0xC0,0x03,0xF8,0x1F,0x00,0x03,0xF8,0x3F,0x00,0x07,0xFC,
        0x3E,0x00,0x0F,0xFC,0x3E,0x00,0x0E,0xFC,0x7E,0x00,0x3A,0x7E,0x7C,0x00,0x3A,0x76,0x70,0x00,0x38,0xC0,0x40,0x00,0x00,0x20,0x70,
        0x00,0x0F,0xE0,0x78,0x00,0x1F,0xF0,0x7F,0x00,0x3F,0xF0,0x7F,0x80,0x3F,0xF0,0x3F,0x80,0x3F,0xF0,0x3F,0x80,0x1F,0xF0,0x3F,0x80,
        0x0F,0xE0,0x1F,0x00,0x01,0xE8,0x1E,0x00,0x01,0xE8,0x0E,0x00,0x00,0xE0,0x06,0x00,0x00,0xC0,0x02,0x00,0x00,0x00,0x00,0x00,0x00,
        0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x04,0x00,0x66,0xff,0x00,0x00,0x00,0x00,0x00,0x0F,0xF0,0x00,
        0x00,0x7F,0xFE,0x00,0x01,0xFF,0xFF,0x80,0x00,0x3F,0xFF,0x80,0x00,0x0F,0xFF,0x00,0x00,0x0F,0xFF,0x00,0x00,0x3F,0xFC,0x00,0x00,
        0xFF,0xFC,0x00,0x00,0xFF,0xF8,0x00,0x01,0xFF,0xF0,0x00,0x01,0xFF,0xF1,0x00,0x01,0xFF,0xC5,0x80,0x03,0xFF,0xC5,0x88,0x0F,0xFF,
        0xC7,0x3E,0x3F,0xFF,0xFF,0xDE,0x0F,0xFF,0xF0,0x1E,0x07,0xFF,0xE0,0x0E,0x00,0xFF,0xC0,0x0E,0x00,0x7F,0xC0,0x0E,0x00,0x7F,0xC0,
        0x0C,0x00,0x7F,0xE0,0x0C,0x00,0x7F,0xF0,0x1C,0x00,0xFF,0xFE,0x10,0x01,0xFF,0xFE,0x10,0x01,0xFF,0xFF,0x10,0x01,0xFF,0xFF,0x20,
        0x01,0xFF,0xFF,0xC0,0x01,0xFF,0xFF,0x80,0x00,0x7F,0xFE,0x00,0x00,0x0F,0xF0,0x00,0x00,0x00,0x00,0x00,0x04,0x00,0x00,0x00,0x00,
        0x0F,0xF0,0x00,0x00,0x70,0x0E,0x00,0x01,0x80,0x01,0x80,0x02,0x00,0x00,0x40,0x04,0x00,0x00,0x20,0x08,0x00,0x00,0x10,0x10,0x00,
        0x00,0x08,0x20,0x00,0x00,0x04,0x20,0x00,0x00,0x04,0x40,0x00,0x00,0x02,0x40,0x00,0x00,0x02,0x40,0x00,0x00,0x02,0x80,0x00,0x00,
        0x01,0x80,0x00,0x00,0x01,0x80,0x00,0x00,0x01,0x80,0x00,0x00,0x01,0x80,0x00,0x00,0x01,0x80,0x00,0x00,0x01,0x80,0x00,0x00,0x01,
        0x80,0x00,0x00,0x01,0x40,0x00,0x00,0x02,0x40,0x00,0x00,0x02,0x40,0x00,0x00,0x02,0x20,0x00,0x00,0x04,0x20,0x00,0x00,0x04,0x10,
        0x00,0x00,0x08,0x08,0x00,0x00,0x10,0x04,0x00,0x00,0x20,0x02,0x00,0x00,0x40,0x01,0x80,0x01,0x80,0x00,0x70,0x0E,0x00,0x00,0x0F,
        0xF0,0x00,

};