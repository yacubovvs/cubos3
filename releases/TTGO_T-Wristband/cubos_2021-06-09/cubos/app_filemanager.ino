#define appNameClass    FileManagerApp          // App name without spaces
#define appName         "Files"              // App name with spaces 

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

    0x02,0x01,0x02,0x20,0x02,0x20,0x04,0xff,0xd9,0x00,0x00,0x00,0x00,0x00,0x00,
    0x00,0x00,0x00,0x01,0xF8,0x00,0x00,0x00,0x0C,0x00,0x00,0x00,0x06,0x00,0x00,
    0x00,0x03,0xFF,0xFE,0x1F,0xE0,0x00,0x06,0x3F,0xF0,0x00,0x02,0x7F,0xF8,0x00,
    0x02,0x7F,0xFF,0xFF,0xE2,0x7F,0xFF,0xFF,0xE2,0x7F,0xFF,0xFF,0xE2,0x7F,0xFF,
    0xFF,0xE2,0x7F,0xFF,0xFF,0xE2,0x7F,0xFF,0xFF,0xE2,0x7F,0xFF,0xFF,0xE2,0x7F,
    0xFF,0xFF,0xE2,0x7F,0xFF,0xFF,0xE2,0x7F,0xFF,0xFF,0xE2,0x7F,0xFF,0xFF,0xE2,
    0x7F,0xFF,0xFF,0xE2,0x7F,0xFF,0xFF,0xE2,0x7F,0xFF,0xFF,0xE2,0x7F,0xFF,0xFF,
    0xE2,0x7F,0xFF,0xFF,0xE2,0x7F,0xFF,0xFF,0xE2,0x7F,0xFF,0xFF,0xE0,0x7F,0xFF,
    0xFF,0xE0,0x7F,0xFF,0xFF,0xE0,0x7F,0xFF,0xFF,0xE0,0x7F,0xFF,0xFF,0xE0,0x00,
    0x00,0x00,0x00,0x04,0xff,0xff,0xff,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
    0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x07,0xF0,0x00,0x00,0x00,0x18,0x00,
    0x00,0x00,0x0C,0x00,0x00,0x00,0x07,0xFF,0xF8,0x00,0x00,0x00,0x18,0x00,0x00,
    0x00,0x08,0x00,0x00,0x00,0x08,0x00,0x00,0x00,0x08,0x00,0x00,0x00,0x08,0x00,
    0x00,0x00,0x08,0x00,0x00,0x00,0x08,0x00,0x00,0x00,0x08,0x00,0x00,0x00,0x08,
    0x00,0x00,0x00,0x08,0x00,0x00,0x00,0x08,0x00,0x00,0x00,0x08,0x00,0x00,0x00,
    0x08,0x00,0x00,0x00,0x08,0x00,0x00,0x00,0x08,0x00,0x00,0x00,0x08,0x00,0x00,
    0x00,0x08,0x00,0x00,0x00,0x08,0x00,0x00,0x00,0x08,0x00,0x00,0x00,0x08,0x00,
    0x00,0x00,0x08,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
    0x04,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x01,0xF8,0x00,0x00,0x02,0x04,0x00,
    0x00,0x07,0xF2,0x00,0x00,0x08,0x09,0xFF,0xFE,0x1F,0xE4,0x00,0x01,0x20,0x13,
    0xFF,0xF9,0x40,0x08,0x00,0x05,0x80,0x07,0xFF,0xE5,0x80,0x00,0x00,0x15,0x80,
    0x00,0x00,0x15,0x80,0x00,0x00,0x15,0x80,0x00,0x00,0x15,0x80,0x00,0x00,0x15,
    0x80,0x00,0x00,0x15,0x80,0x00,0x00,0x15,0x80,0x00,0x00,0x15,0x80,0x00,0x00,
    0x15,0x80,0x00,0x00,0x15,0x80,0x00,0x00,0x15,0x80,0x00,0x00,0x15,0x80,0x00,
    0x00,0x15,0x80,0x00,0x00,0x15,0x80,0x00,0x00,0x15,0x80,0x00,0x00,0x15,0x80,
    0x00,0x00,0x15,0x80,0x00,0x00,0x17,0x80,0x00,0x00,0x14,0x80,0x00,0x00,0x14,
    0x80,0x00,0x00,0x1C,0x80,0x00,0x00,0x10,0xFF,0xFF,0xFF,0xF0,

};