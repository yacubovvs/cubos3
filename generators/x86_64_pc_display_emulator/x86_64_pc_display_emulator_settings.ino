
/*
    ############################################################################################
    #                                                                                          #
    #                                    x86_64 SETTINGS +                                     #
    #                                                                                          #
    ############################################################################################
*/

// ! ! ! ! ! ! ! ! ! ! ! ! ! ! ! ! ! ! ! ! ! ! !
//      FOR ESP8266 USE NONOSSDK 2.2.2 +
// ! ! ! ! ! ! ! ! ! ! ! ! ! ! ! ! ! ! ! ! ! ! !

//#define DEBUG_SERIAL
//#define DEBUG_ON_SCREEN
#define TERMINAL_DEBUG

#define SCREEN_WIDTH            240     // Screen resolution width
#define SCREEN_HEIGHT           240     // Screen resolution height

#define FONT_CHAR_WIDTH         6     // Font letter size width
#define FONT_CHAR_HEIGHT        8     // Font letter size height

//#define device_has_battery

#define PLATFORM_PC_EMULATOR
#define BLUETOOTH_ENABLE
#define WIFI_ENABLE

//#define SMOOTH_ANIMATION
//#define NARROW_SCREEN

#define ON_TIME_CHANGE_EVERY_MS 1000

#define HARDWARE_BUTTONS_ENABLED        // Conf of controls with hardware btns    
#define TOUCH_SCREEN_ENABLE

#define TOUCH_SCREEN_DELTA_MOVE_FOR_DRAG 7
#define TOUCH_SCREEN_TIME_MS_FOR_LONG_TOUCH 300

#define COLOR_SCREEN                     // Screen is colored
//#define NO_ANIMATION                   // Caurse of framebuffer type

//#define toDefaultApp_onLeftLongPress

#define STARTING_APP_NUMM   -1    // for Mainmenu (default app)
#define STARTING_APP_NUMM   11     // for App number 7

#undef CPU_SLEEP_ENABLE
#undef POWERSAVE_ENABLE
//#define CPU_SLEEP_TIME_DELAY 25000

#define BUTTON_UP       0
#define BUTTON_SELECT   1
#define BUTTON_DOWN     2
#define BUTTON_BACK     3

#define BATTERY_ENABLE
#define CLOCK_ENABLE
//#define USE_PRIMITIVE_HARDWARE_DRAW_ACCELERATION

#define RTC_ENABLE
#define FONT_SIZE_DEFAULT 2
#define SCREEN_ROTATION_0
//#define SCREEN_ROTATION_90
//#define SCREEN_ROTATION_180
//#define SCREEN_ROTATION_270

//#define PEDOMETER_ENABLE
//#define ACCELEROMETER_ENABLE
#define STYLE_STATUSBAR_HEIGHT  20

#undef I2C_ENABLE
#undef CPU_CONTROLL_ENABLE

#define PEDOMETER_EMULATOR
#define FONT_SIZE_DEFAULT   1

/*
#define SOFTWARE_BUTTONS_ENABLE
#define SOFTWARE_BUTTONS_PORITION_RIGHT

#define SOFTWARE_BUTTONS_BAR_SIZE 30
#define SOFTWARE_BUTTONS_PADDING 50
*/

#define SOFTWARE_KEYBOARD_ENABLE

//#define FRAMEBUFFER_ENABLE
//#define FRAMEBUFFER_TWIN_FULL
//#define FRAMEBUFFER_BYTE_PER_PIXEL 2
//#define FRAMEBUFFER_PSRAM

//#define NARROW_SCREEN
/*
    ############################################################################################
    #                                                                                          #
    #                                    x86_64 SETTINGS -                                     #
    #                                                                                          #
    ############################################################################################
*/