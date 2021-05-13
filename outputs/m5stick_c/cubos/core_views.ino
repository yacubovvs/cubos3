/*
    ############################################################################################
    #                                                                                          #
    #                                        STATUSBAR +                                       #
    #                                                                                          #
    ############################################################################################
*/

// background
#define STYLE_STATUSBAR_BACKGROUND_RED      116
#define STYLE_STATUSBAR_BACKGROUND_GREEN    0
#define STYLE_STATUSBAR_BACKGROUND_BLUE     176

// text color
#define STYLE_STATUSBAR_TEXT_RED      255
#define STYLE_STATUSBAR_TEXT_GREEN    255
#define STYLE_STATUSBAR_TEXT_BLUE     255

#ifdef BATTERY_ENABLE
    // BATTERY 100% ICON
    const unsigned char battery100[] PROGMEM = {
        0x02,0x01,0x02,0x20,0x02,0x10,0x04,0xff,0xff,0xff,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x3F,0xFF,0xFF,
        0xF0,0x40,0x00,0x00,0x08,0x9F,0xFF,0xFF,0xE4,0xBF,0xFF,0xFF,0xF4,0xBF,0xFF,0xFF,0xF7,0xBF,0xFF,0xFF,0xF7,
        0xBF,0xFF,0xFF,0xF7,0xBF,0xFF,0xFF,0xF7,0xBF,0xFF,0xFF,0xF4,0x9F,0xFF,0xFF,0xE4,0x40,0x00,0x00,0x0C,0x3F,
        0xFF,0xFF,0xF8,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
    };

    // BATTERY 90% ICON
    const unsigned char battery90[] PROGMEM = {
        0x02,0x01,0x02,0x20,0x02,0x10,0x04,0xff,0xff,0xff,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x3F,0xFF,0xFF,
        0xF0,0x40,0x00,0x00,0x08,0x9F,0xFF,0xFF,0x84,0xBF,0xFF,0xFF,0x84,0xBF,0xFF,0xFF,0x87,0xBF,0xFF,0xFF,0x87,
        0xBF,0xFF,0xFF,0x87,0xBF,0xFF,0xFF,0x87,0xBF,0xFF,0xFF,0x84,0x9F,0xFF,0xFF,0x84,0x40,0x00,0x00,0x0C,0x3F,
        0xFF,0xFF,0xF8,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
    };

    // BATTERY 80% ICON
    const unsigned char battery80[] PROGMEM = {
        0x02,0x01,0x02,0x20,0x02,0x10,0x04,0xff,0xff,0xff,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x3F,0xFF,0xFF,
        0xF0,0x40,0x00,0x00,0x08,0x9F,0xFF,0xFE,0x04,0xBF,0xFF,0xFE,0x04,0xBF,0xFF,0xFE,0x07,0xBF,0xFF,0xFE,0x07,
        0xBF,0xFF,0xFE,0x07,0xBF,0xFF,0xFE,0x07,0xBF,0xFF,0xFE,0x04,0x9F,0xFF,0xFE,0x04,0x40,0x00,0x00,0x0C,0x3F,
        0xFF,0xFF,0xF8,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
    };

    // BATTERY 70% ICON
    const unsigned char battery70[] PROGMEM = {
        0x02,0x01,0x02,0x20,0x02,0x10,0x04,0xff,0xff,0xff,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x3F,0xFF,0xFF,
        0xF0,0x40,0x00,0x00,0x08,0x9F,0xFF,0xF0,0x04,0xBF,0xFF,0xF0,0x04,0xBF,0xFF,0xF0,0x07,0xBF,0xFF,0xF0,0x07,
        0xBF,0xFF,0xF0,0x07,0xBF,0xFF,0xF0,0x07,0xBF,0xFF,0xF0,0x04,0x9F,0xFF,0xF0,0x04,0x40,0x00,0x00,0x0C,0x3F,
        0xFF,0xFF,0xF8,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
    };

    // BATTERY 60% ICON
    const unsigned char battery60[] PROGMEM = {
        0x02,0x01,0x02,0x20,0x02,0x10,0x04,0xff,0xff,0xff,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x3F,0xFF,0xFF,
        0xF0,0x40,0x00,0x00,0x08,0x9F,0xFF,0x80,0x04,0xBF,0xFF,0x80,0x04,0xBF,0xFF,0x80,0x07,0xBF,0xFF,0x80,0x07,
        0xBF,0xFF,0x80,0x07,0xBF,0xFF,0x80,0x07,0xBF,0xFF,0x80,0x04,0x9F,0xFF,0x80,0x04,0x40,0x00,0x00,0x0C,0x3F,
        0xFF,0xFF,0xF8,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
    };

    // BATTERY 50% ICON
    const unsigned char battery50[] PROGMEM = {
        0x02,0x01,0x02,0x20,0x02,0x10,0x04,0xff,0xff,0xff,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x3F,0xFF,0xFF,
        0xF0,0x40,0x00,0x00,0x08,0x9F,0xFC,0x00,0x04,0xBF,0xFC,0x00,0x04,0xBF,0xFC,0x00,0x07,0xBF,0xFC,0x00,0x07,
        0xBF,0xFC,0x00,0x07,0xBF,0xFC,0x00,0x07,0xBF,0xFC,0x00,0x04,0x9F,0xFC,0x00,0x04,0x40,0x00,0x00,0x0C,0x3F,
        0xFF,0xFF,0xF8,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
    };

    // BATTERY 40% ICON
    const unsigned char battery40[] PROGMEM = {
        0x02,0x01,0x02,0x20,0x02,0x10,0x04,0xff,0xff,0xff,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x3F,0xFF,0xFF,
        0xF0,0x40,0x00,0x00,0x08,0x9F,0xF0,0x00,0x04,0xBF,0xF0,0x00,0x04,0xBF,0xF0,0x00,0x07,0xBF,0xF0,0x00,0x07,
        0xBF,0xF0,0x00,0x07,0xBF,0xF0,0x00,0x07,0xBF,0xF0,0x00,0x04,0x9F,0xF0,0x00,0x04,0x40,0x00,0x00,0x0C,0x3F,
        0xFF,0xFF,0xF8,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
    };

    // BATTERY 30% ICON
    const unsigned char battery30[] PROGMEM = {
        0x02,0x01,0x02,0x20,0x02,0x10,0x04,0xff,0xff,0xff,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x3F,0xFF,0xFF,
        0xF0,0x40,0x00,0x00,0x08,0x9F,0x80,0x00,0x04,0xBF,0x80,0x00,0x04,0xBF,0x80,0x00,0x07,0xBF,0x80,0x00,0x07,
        0xBF,0x80,0x00,0x07,0xBF,0x80,0x00,0x07,0xBF,0x80,0x00,0x04,0x9F,0x80,0x00,0x04,0x40,0x00,0x00,0x0C,0x3F,
        0xFF,0xFF,0xF8,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
    };

    // BATTERY 20% ICON
    const unsigned char battery20[] PROGMEM = {
        0x02,0x01,0x02,0x20,0x02,0x10,0x04,0xff,0xff,0xff,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x3F,0xFF,0xFF,
        0xF0,0x40,0x00,0x00,0x08,0x9C,0x00,0x00,0x04,0xBC,0x00,0x00,0x04,0xBC,0x00,0x00,0x07,0xBC,0x00,0x00,0x07,
        0xBC,0x00,0x00,0x07,0xBC,0x00,0x00,0x07,0xBC,0x00,0x00,0x04,0x9C,0x00,0x00,0x04,0x40,0x00,0x00,0x0C,0x3F,
        0xFF,0xFF,0xF8,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
    };

    // BATTERY 10% ICON
    const unsigned char battery10[] PROGMEM = {
        0x02,0x01,0x02,0x20,0x02,0x10,0x04,0xff,0xff,0xff,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x3F,0xFF,0xFF,
        0xF0,0x40,0x00,0x00,0x08,0x90,0x00,0x00,0x04,0xB0,0x00,0x00,0x04,0xB0,0x00,0x00,0x07,0xB0,0x00,0x00,0x07,
        0xB0,0x00,0x00,0x07,0xB0,0x00,0x00,0x07,0xB0,0x00,0x00,0x04,0x90,0x00,0x00,0x04,0x40,0x00,0x00,0x0C,0x3F,
        0xFF,0xFF,0xF8,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
    };

    // BATTERY 0% ICON
    const unsigned char battery0[] PROGMEM = {
        0x02,0x01,0x02,0x20,0x02,0x10,0x04,0xff,0xff,0xff,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x3F,0xFF,0xFF,
        0xF0,0x40,0x00,0x00,0x08,0x80,0x00,0x00,0x04,0x80,0x00,0x00,0x04,0x80,0x00,0x00,0x07,0x80,0x00,0x00,0x07,
        0x80,0x00,0x00,0x07,0x80,0x00,0x00,0x07,0x80,0x00,0x00,0x04,0x80,0x00,0x00,0x04,0x40,0x00,0x00,0x0C,0x3F,
        0xFF,0xFF,0xF8,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
    };
#endif

void core_views_statusBar_draw(){
    /*
            [ TIME | ----- | NOTIFICATIONS | BATTERY ]
    */
    bool DRAW_LIMITS_wasEnable = DRAW_LIMITS_Enabled;
    DRAW_LIMITS_setEnable(false);
    
    // BACKGROUND
    setDrawColor(STYLE_STATUSBAR_BACKGROUND_RED, STYLE_STATUSBAR_BACKGROUND_GREEN, STYLE_STATUSBAR_BACKGROUND_BLUE);
    drawRect(0, 0, SCREEN_WIDTH, STYLE_STATUSBAR_HEIGHT, true);

    // TIME
    #ifdef CLOCK_ENABLE
        core_views_statusBar_draw_time(true);
    #endif

    // BATTERY
    #ifdef BATTERY_ENABLE
        core_views_draw_statusbar_battery(true, driver_battery_getPercent());
        //drawIcon(true, battery100,SCREEN_WIDTH-32-STYLE_STATUSBAR_HEIGHT/5, STYLE_STATUSBAR_HEIGHT/2 - 8 + 1);
        //if(DRAW_LIMITS_Enabled) debug("Draw limit enabled");
    #endif

    DRAW_LIMITS_setEnable(DRAW_LIMITS_Enabled);
}

unsigned char batteryCharge_last = 0;
void core_views_draw_statusbar_battery(bool draw, unsigned char batteryCharge){
    TEMPORARILY_DISABLE_BACKGROUND();

    setBackgroundColor(STYLE_STATUSBAR_BACKGROUND_RED, STYLE_STATUSBAR_BACKGROUND_GREEN, STYLE_STATUSBAR_BACKGROUND_BLUE);
    if(draw) batteryCharge_last = batteryCharge;

    const unsigned char *batteryIcon;
    if(batteryCharge_last>=100){
        batteryIcon = battery100;
    }else if(batteryCharge_last>=90){
        batteryIcon = battery90;
    }else if(batteryCharge_last>=80){
        batteryIcon = battery80;
    }else if(batteryCharge_last>=70){
        batteryIcon = battery70;
    }else if(batteryCharge_last>=60){
        batteryIcon = battery60;
    }else if(batteryCharge_last>=50){
        batteryIcon = battery50;
    }else if(batteryCharge_last>=40){
        batteryIcon = battery40;
    }else if(batteryCharge_last>=30){
        batteryIcon = battery30;
    }else if(batteryCharge_last>=20){
        batteryIcon = battery20;
    }else if(batteryCharge_last>=10){
        batteryIcon = battery10;
    }else{
        batteryIcon = battery0;
    }

    drawIcon(draw, batteryIcon, SCREEN_WIDTH-32-STYLE_STATUSBAR_HEIGHT/5, STYLE_STATUSBAR_HEIGHT/2 - 8 + 1);

    TEMPORARILY_RESTORE_BACKGROUND();
}

String core_views_statusBar_draw_time_TimeString = "";
void core_views_statusBar_draw_time(bool draw){
    bool lastLimits = DRAW_LIMITS_getEnable();
    DRAW_LIMITS_setEnable(false);
    if(draw){
        setDrawColor(STYLE_STATUSBAR_TEXT_RED, STYLE_STATUSBAR_TEXT_GREEN, STYLE_STATUSBAR_TEXT_BLUE);
        core_views_statusBar_draw_time_TimeString = core_time_getHourMinuteTime();
        drawString(core_views_statusBar_draw_time_TimeString, 5, STYLE_STATUSBAR_HEIGHT/2 - FONT_CHAR_HEIGHT/2 + ( (STYLE_STATUSBAR_HEIGHT)%2 ) + ( (FONT_CHAR_HEIGHT)%2 ) + 2, FONT_SIZE_DEFAULT);
    }else{
        setDrawColor(STYLE_STATUSBAR_BACKGROUND_RED, STYLE_STATUSBAR_BACKGROUND_GREEN, STYLE_STATUSBAR_BACKGROUND_BLUE);
        clearString(core_views_statusBar_draw_time_TimeString, 5, STYLE_STATUSBAR_HEIGHT/2 - FONT_CHAR_HEIGHT/2 + ( (STYLE_STATUSBAR_HEIGHT)%2 ) + ( (FONT_CHAR_HEIGHT)%2 ) + 2, FONT_SIZE_DEFAULT);
    }
    DRAW_LIMITS_setEnable(lastLimits);
}


/*
    ############################################################################################
    #                                                                                          #
    #                                        STATUSBAR -                                       #
    #                                                                                          #
    ############################################################################################
*/

/*
    ############################################################################################
    #                                                                                          #
    #                                       PAGES LIST +                                       #
    #                                                                                          #
    ############################################################################################
*/

#define CORE_VIEWS_PAGES_LIST_ELEMENT_SIZE                  4
#define CORE_VIEWS_PAGES_LIST_BETWEEN_ELEMENTS_SIZE         20


int core_views_pages_list_get_element_position_x(int pages_quantity, int position){
    return ( (pages_quantity%2==1) ? (-pages_quantity/2 + position) * CORE_VIEWS_PAGES_LIST_BETWEEN_ELEMENTS_SIZE : -((-CORE_VIEWS_PAGES_LIST_BETWEEN_ELEMENTS_SIZE/2) ) + (-pages_quantity/2 + position) * CORE_VIEWS_PAGES_LIST_BETWEEN_ELEMENTS_SIZE);
}

void core_views_draw_pages_list_simple(
    bool draw, // true - draw, false - clear
    int y0,
    unsigned char pages_quantity
){
    //SCREEN_WIDTH
    //SCREEN_HEIGHT

    if(draw) setDrawColor(128, 128, 128);
    else setDrawColor(getBackgroundColor_red(), getBackgroundColor_green(), getBackgroundColor_blue());

    for(int i=0; i<pages_quantity; i++){
        int element_x = SCREEN_WIDTH/2 + core_views_pages_list_get_element_position_x(pages_quantity, i);
        int element_y = y0;
        drawRect(element_x - CORE_VIEWS_PAGES_LIST_ELEMENT_SIZE, element_y - CORE_VIEWS_PAGES_LIST_ELEMENT_SIZE, element_x + CORE_VIEWS_PAGES_LIST_ELEMENT_SIZE, element_y + CORE_VIEWS_PAGES_LIST_ELEMENT_SIZE);
    }
}

void core_views_draw_active_page(
    bool draw, // true - draw, false - clear
    int y0,
    unsigned char pages_quantity,
    unsigned char position
){
    #ifdef NARROW_SCREEN
        //if(draw) setDrawColor(getContrastColor_red(), getContrastColor_green(), getContrastColor_blue());
        #define GRAY_COLOR 164
        if(draw) setDrawColor(GRAY_COLOR, GRAY_COLOR, GRAY_COLOR);
        else setDrawColor(getBackgroundColor_red(), getBackgroundColor_green(), getBackgroundColor_blue());

        //drawString_centered(String(position) + "/" + String(pages_quantity), y0, 1);
        String activePageString = String(position + 1) + "/" + String(pages_quantity);
        drawString(activePageString, (SCREEN_WIDTH - activePageString.length()*FONT_CHAR_WIDTH*2)/2, y0 - FONT_CHAR_HEIGHT, 2);
    #else
        if(draw) setDrawColor(0, 255, 0);
        else setDrawColor(getBackgroundColor_red(), getBackgroundColor_green(), getBackgroundColor_blue());

        int element_x = SCREEN_WIDTH/2 + core_views_pages_list_get_element_position_x(pages_quantity, position);
        int element_y = y0;
        drawRect(element_x - (CORE_VIEWS_PAGES_LIST_ELEMENT_SIZE-1), element_y - (CORE_VIEWS_PAGES_LIST_ELEMENT_SIZE-1), element_x + (CORE_VIEWS_PAGES_LIST_ELEMENT_SIZE-1), element_y + (CORE_VIEWS_PAGES_LIST_ELEMENT_SIZE-1), true);
    #endif

}

/*
    ############################################################################################
    #                                                                                          #
    #                                       PAGES LIST -                                       #
    #                                                                                          #
    ############################################################################################
*/

/*
    ############################################################################################
    #                                                                                          #
    #                                    APPLICATION ICON +                                    #
    #                                                                                          #
    ############################################################################################
*/

#define CORE_VIEWS_APPICON_IMAGE_WIDTH          32
#define CORE_VIEWS_APPICON_IMAGE_HEIGHT         32
#define CORE_VIEWS_APPICON_IMAGE_Y_OFFSET       -10
#define CORE_VIEWS_APPICON_TITLE_Y_OFFSET       20

void core_views_draw_app_icon(bool draw, int x, int y, const unsigned char* title, const unsigned char* icon){
    // image
    drawIcon(draw, icon, x-CORE_VIEWS_APPICON_IMAGE_WIDTH/2, y-CORE_VIEWS_APPICON_IMAGE_HEIGHT/2 + CORE_VIEWS_APPICON_IMAGE_Y_OFFSET);

    // title
    if(draw){
        setDrawColor(255, 255, 255);
        drawString_centered((char*)title, x, y + CORE_VIEWS_APPICON_TITLE_Y_OFFSET);
    }else{
        setDrawColor(getBackgroundColor_red(), getBackgroundColor_green(), getBackgroundColor_blue());
        clearString_centered((char*)title, x, y + CORE_VIEWS_APPICON_TITLE_Y_OFFSET);
    }

    
}


#define CORE_VIEWS_SETTINGS_IMAGE_WIDTH 24
void core_views_draw_settings_item(bool draw, int x, int y, const unsigned char* title, String subTitle, const unsigned char* icon){

    #ifdef NARROW_SCREEN
        drawIcon(draw, icon, x-CORE_VIEWS_SETTINGS_IMAGE_WIDTH/2, y-30);
        uint16_t titleShift = strlen((const char*)title)*FONT_CHAR_WIDTH/2;
        uint16_t subTitleShift = subTitle.length()*FONT_CHAR_WIDTH/2;

        #define TITLE_Y_POSITION y+10
        #define SUBTITLE_Y_POSITION y+30
        x+=2;
        
        if(draw){
            setDrawColor_ContrastColor();
            drawString((char*)title, x - titleShift,    TITLE_Y_POSITION, 1);
            drawString(subTitle, x - subTitleShift,     SUBTITLE_Y_POSITION, 1);
        }else{
            setDrawColor_BackGoundColor();
            clearString((char*)title, x - titleShift,   TITLE_Y_POSITION, 1);
            clearString(subTitle, x - subTitleShift,    SUBTITLE_Y_POSITION, 1);
        }
    #else
        // image
        int left_x = x + CORE_VIEWS_SETTINGS_IMAGE_WIDTH;
        setDrawColor(getBackgroundColor_red(), getBackgroundColor_green(), getBackgroundColor_blue());
        drawIcon(draw, icon, x-CORE_VIEWS_SETTINGS_IMAGE_WIDTH/2, y-CORE_VIEWS_SETTINGS_IMAGE_WIDTH/2);

        // title
        if(draw){
            setDrawColor(255, 255, 255);
            drawString((char*)title, left_x, y-12);
            drawString(subTitle, left_x, y+4);
        }else{    
            clearString((char*)title, left_x, y-12);
            clearString(subTitle, left_x, y+4, 1);
        }
    #endif
    
}

void core_views_draw_settings_item_noicon(bool draw, int x, int y, String title, String subTitle, unsigned char titleFontSize, unsigned char subTitleFontSize){
    
    if(draw){
        setDrawColor_ContrastColor();
        drawString(
            title,                                                                          // TEXT
            x - title.length()*FONT_CHAR_WIDTH/2*titleFontSize,                             // X
            y - COREVIEWS_NO_ICON_ELEMENT_HEIGHT/2,                                         // Y
            titleFontSize                                                                   // FONT SIZE
        );

        drawString(
            subTitle,                                                                       // TEXT
            x - subTitle.length()*FONT_CHAR_WIDTH/2*subTitleFontSize,                       // X
            y + COREVIEWS_NO_ICON_ELEMENT_HEIGHT/2 - subTitleFontSize * FONT_CHAR_HEIGHT,   // Y
            subTitleFontSize                                                                // FONT SIZE
        );
    }else{
        setDrawColor_BackGoundColor();
        clearString(
            title,                                                                          // TEXT
            x - title.length()*FONT_CHAR_WIDTH/2*titleFontSize,                             // X
            y - COREVIEWS_NO_ICON_ELEMENT_HEIGHT/2,                                         // Y
            titleFontSize                                                                   // FONT SIZE
        );

        clearString(
            subTitle,                                                                       // TEXT
            x - subTitle.length()*FONT_CHAR_WIDTH/2*subTitleFontSize,                       // X
            y + COREVIEWS_NO_ICON_ELEMENT_HEIGHT/2 - subTitleFontSize * FONT_CHAR_HEIGHT,   // Y
            subTitleFontSize                                                                // FONT SIZE
        );
    }
    
}

void drawMenuElement(bool draw, uint16_t x, uint16_t y, uint16_t width, uint16_t height, const unsigned char* icon, String string1, String string2){
    if(draw) setDrawColor(255, 255, 255);
    else setDrawColor(getBackgroundColor_red(), getBackgroundColor_green(), getBackgroundColor_blue());

    drawRect( x, y, x + width, y + height, false);

    drawString(string1, x + 36 + 10, y + height/3 - FONT_CHAR_HEIGHT/2);
    //drawString_rightAlign(string2, x + width - 15, y + height*2/3 - FONT_CHAR_HEIGHT/2);
    drawString(string2, x + 36 + 10, y + height*2/3 - FONT_CHAR_HEIGHT/2);

    drawIcon(draw, icon, x + 10, y + height/2 - 16/2);
}

/*
    ############################################################################################
    #                                                                                          #
    #                                    APPLICATION ICON -                                    #
    #                                                                                          #
    ############################################################################################
*/

const unsigned char icon_arrow_top[] PROGMEM = {
    0x02,0x01,0x02,0x18,0x02,0x10,0x04,0xff,0xff,0xff,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x18,0x00,0x00,0x3C,0x00,0x00,0x7E,0x00,0x00,0xFF,0x00,0x01,0xFF,0x80,0x03,0xFF,0xC0,0x07,0xFF,0xE0,0x0F,0xFF,0xF0,0x1F,0xFF,0xF8,0x3F,0xFF,0xFC,0x7F,0xFF,0xFE,0xFF,0xFF,0xFF,
};

const unsigned char icon_arrow_bottom[] PROGMEM = {
    0x02,0x01,0x02,0x18,0x02,0x10,0x04,0xff,0xff,0xff,0xFF,0xFF,0xFF,0x7F,0xFF,0xFE,0x3F,0xFF,0xFC,0x1F,0xFF,0xF8,0x0F,0xFF,0xF0,0x07,0xFF,0xE0,0x03,0xFF,0xC0,0x01,0xFF,0x80,0x00,0xFF,0x00,0x00,0x7E,0x00,0x00,0x3C,0x00,0x00,0x18,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
};

const byte* getIcon(int icon){

    switch (icon){
        #ifdef BATTERY_ENABLE
            case ICON_BATTERY_100:        return battery100;  
            case ICON_BATTERY_90:         return battery90;  
            case ICON_BATTERY_80:         return battery80;  
            case ICON_BATTERY_70:         return battery70;  
            case ICON_BATTERY_60:         return battery60;  
            case ICON_BATTERY_50:         return battery50;  
            case ICON_BATTERY_40:         return battery40;  
            case ICON_BATTERY_30:         return battery30;  
            case ICON_BATTERY_20:         return battery20;  
            case ICON_BATTERY_10:         return battery10;  
            case ICON_BATTERY_0:          return battery0;
        #endif
        case ICON_ARROW_UP:             return icon_arrow_top;
        case ICON_ARROW_DOWN:           return icon_arrow_bottom;
        default: return {0};
    }
  
}