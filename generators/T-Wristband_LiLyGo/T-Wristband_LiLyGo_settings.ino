/*
    ############################################################################################
    #                                                                                          #
    #                                   M5STICK SETTINGS +                                     #
    #                                                                                          #
    ############################################################################################
*/

// ! ! ! ! ! ! ! ! ! ! ! ! ! ! ! ! ! ! ! ! ! ! !
//      USING ESP32 DEV MODULE FOR FLASHING
// ! ! ! ! ! ! ! ! ! ! ! ! ! ! ! ! ! ! ! ! ! ! !

#define SCREEN_WIDTH            80     // Screen resolution width
#define SCREEN_HEIGHT           160     // Screen resolution height

#define FONT_CHAR_WIDTH         6     // Font letter size width
#define FONT_CHAR_HEIGHT        8     // Font letter size height

#define PLATFORM_ESP32
#define BLUETOOTH_ENABLED
#define WIFI_ENABLED

#define ON_TIME_CHANGE_EVERY_MS 1000

#define HARDWARE_BUTTONS_ENABLED              // Conf of controls with hardware btns    

#define DRIVER_CONTROLS_TOTALBUTTONS 1
#define DRIVER_CONTROLS_DELAY_BEFORE_LONG_PRESS 350

#define COLOR_SCREEN                     // Screen is colored

//#define toDefaultApp_onLeftLongPress

#define STARTING_APP_NUMM   -1    // for Mainmenu (default app)
//#define STARTING_APP_NUMM    1 // Settings
//#define STARTING_APP_NUMM    2 // Pedometer
#define STARTING_APP_NUMM    0

#define FONT_SIZE_DEFAULT   1

#define CPU_SLEEP_ENABLE

#define BATTERY_ENABLE
#define CLOCK_ENABLE
//#define USE_PRIMITIVE_HARDWARE_DRAW_ACCELERATION

#define RTC_ENABLE

#define SCREEN_ROTATION_0
//#define SCREEN_ROTATION_90
//#define SCREEN_ROTATION_180
//#define SCREEN_ROTATION_270

#define STYLE_STATUSBAR_HEIGHT  20

#define SMOOTH_ANIMATION
#define NARROW_SCREEN

#define FRAMEBUFFER_ENABLE
#define FRAMEBUFFER_TWIN_FULL
#define FRAMEBUFFER_BYTE_PER_PIXEL 2

//#define SCREEN_INVERT_COLORS
#define SCREEN_CHANGE_BLUE_RED

#define DRIVER_RTC_INTERRUPT_PIN    34

#define IN_APP_SLEEP_TYPE       SLEEP_LIGHT
//#define STAND_BY_SLEEP_TYPE     SLEEP_LIGHT_SCREEN_OFF
#define STAND_BY_SLEEP_TYPE     SLEEP_DEEP

#undef SMOOTH_BACKLIGHT_CONTROL_DELAY_CHANGE
#undef DISPLAY_BACKLIGHT_CONTROL_ENABLE

#define SMOOTH_ANIMATION_COEFFICIENT    4

#define ACCELEROMETER_ENABLE
//#define MAGNITOMETER_ENABLE
#define PEDOMETER_ENABLE
//#define DEBUG_PEDOMETER
#undef DISPLAY_BACKLIGHT_FADE_CONTROL_ENABLE

#define PEDOMETER_STEP_DETECTION_DELAY          20000 // Wake up to check accelerometer
//#define PEDOMETER_STEP_DETECTION_DELAY          1000 // Wake up to check accelerometer
#define DEFAULT_TIME_TO_POWEROFF_DISPLAY        12
#define DEFAULT_DELAY_TO_FADE_DISPLAY           0
#define PEDOMETER_STEP_DETECTION_PERIOD_MS              800
#define PEDOMETER_MESURES_IN_STEP_DETECTION_PERIOD      5
#define PEDOMETER_DAY_STEP_LIMMIT_DEFAULT               10000

#define PEDOMETER_DELTA_VALUE_MIN           0.47f
#define PEDOMETER_CENTRALWIGHT_VALUE_MIN    0.15f

#define PEDOMETER_STEP_DETECTION_DELAY_SEC_MIN          30
#define PEDOMETER_STEP_DETECTION_DELAY_SEC_STEP         30
#define PEDOMETER_STEP_DETECTION_DELAY_SEC_MAX          180 // MAX (255 - PEDOMETER_STEP_DETECTION_PERIOD_MS/1000) and multiple 60 seconds

#define CORE_PEDOMETER_SLEEP_COUNTING_SPOINTS   5 // mesures for sleep detection 
#define CORE_PEDOMETER_SLEEP_MIN_ACCELL_100     3 // acceletometer sensitivity/100*G for sleep detection

#define APP_CLOCK_POWER_AFTER_SECONDS           4

//#define DEBUG_SERIAL
//#define DEBUG_PEDOMETER
//#define WAKEUP_DEBUG
//#define DEBUG_DRIVER_BATTERY
/*
    ############################################################################################
    #                                                                                          #
    #                                   M5STICK SETTINGS -                                     #
    #                                                                                          #
    ############################################################################################
*/