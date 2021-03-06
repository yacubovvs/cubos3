#define appNameClass    I2CScannerApp          // App name without spaces
#define appName         "I2C scanner"              // App name with spaces 

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

    private:
        void drawStringOnScreen(String string);
        unsigned char currentString = 0;
      
};

#include <Wire.h>

void appNameClass::onCreate(){
    /*
        Write you code onCreate here
    */
    setDrawColor(255, 255, 255);
    

    Wire.begin();
    unsigned char error, address;
    int nDevices;

    drawStringOnScreen("Scanning...");
 
    nDevices = 0;
    for(address = 8; address < 127; address++ ){
        //if(address==104) continue;
        Wire.beginTransmission(address);
        error = Wire.endTransmission();
 
        #ifdef ESP8266
            ESP.wdtDisable();
        #endif

        if (error == 0){
            
            if(address==119) drawStringOnScreen("Barometr " + getHexStringFromByte(address));
            else if(address==13) drawStringOnScreen("Compass " + getHexStringFromByte(address));
            else if(address==104) drawStringOnScreen("RTC " + getHexStringFromByte(address));
            else drawStringOnScreen("I2C device " + getHexStringFromByte(address));
            nDevices++;
        }
        else if (error==4) {
            drawStringOnScreen("ERROR " + getHexStringFromByte(address));
        } 
    }
    if (nDevices == 0)
        drawStringOnScreen("No I2C devices found");
    else
        drawStringOnScreen("done");
 
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

void appNameClass::drawStringOnScreen(String string){
    drawString(string, 5, STYLE_STATUSBAR_HEIGHT + 8 + 20*currentString, 2);
    currentString++;
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

    0x02,0x01,0x02,0x20,0x02,0x20,0x04,0xff,0xd9,0x00,0x00,0x30,0x00,0x00,0x00,0x48,0x00,0x00,0x3C,0x08,0x1F,
    0xE0,0x3C,0x10,0x3F,0xF8,0x3C,0x20,0x78,0x3C,0x3C,0x78,0xF0,0x1C,0x3C,0x00,0xE0,0x1C,0x3C,0x00,0xE0,0x00,
    0x3C,0x00,0xE0,0x00,0x3C,0x00,0xE0,0x00,0x3C,0x00,0xE0,0x00,0x3C,0x00,0xE0,0x00,0x3C,0x00,0xE0,0x00,0x3C,
    0x00,0xE0,0x1C,0x3C,0x00,0xF0,0x1C,0x3C,0x00,0xF8,0x1C,0x3C,0x00,0x7F,0xFC,0x3C,0x00,0x3F,0xF8,0x3C,0x00,
    0x1F,0xF0,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
    0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
    0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x04,0xff,0xff,0xff,0x00,0x00,0x00,0x00,0x00,
    0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
    0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
    0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
    0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
    0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x1F,0x0C,0x30,0xF8,0x18,0xCC,0x33,0x00,0x18,0xCC,
    0x33,0x00,0x1F,0x0C,0x30,0xE0,0x18,0xCC,0x30,0x18,0x18,0xCC,0x30,0x18,0x1F,0x03,0xC3,0xE0,0x04,0xb4,0xb4,
    0xb4,0x00,0x08,0x00,0x00,0x3C,0x24,0x1F,0xE0,0x42,0x04,0x20,0x18,0x42,0x08,0x40,0x04,0x42,0x10,0x87,0xC2,
    0x42,0x05,0x08,0x22,0x42,0x3D,0x10,0x22,0x42,0x01,0x10,0x1C,0x42,0x01,0x10,0x00,0x42,0x01,0x10,0x00,0x42,
    0x01,0x10,0x00,0x42,0x01,0x10,0x00,0x42,0x01,0x10,0x1C,0x42,0x01,0x10,0x22,0x42,0x01,0x08,0x22,0x42,0x01,
    0x07,0xE2,0x42,0x00,0x80,0x02,0x42,0x00,0x40,0x06,0x42,0x00,0x20,0x08,0x3C,0x00,0x1F,0xF0,0x00,0x00,0x00,
    0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x82,0x08,0x04,
    0x04,0x22,0x08,0x80,0x04,0x22,0x08,0x80,0x00,0x82,0x08,0x10,0x04,0x22,0x08,0x04,0x04,0x22,0x08,0x04,0x00,
    0x80,0x20,0x10,

};