#ifndef CONSTANTS_H
#define CONSTANTS_H

#include <arduino.h>

static const uint8_t PIXEL_ARRAY_MAX_BRIGHTNESS = 255;
static const uint8_t PIXEL_ARRAY_MIN_BRIGHTNESS = 0; 
static const short   PIXEL_ARRAY_PIN            = 2;
static const short   NUM_PIXELS                 = 7;
static const uint8_t RAINBOW_SPEED_FAST         = 2;  // how quicky the colors change (quick)
static const uint8_t RAINBOW_SPEED_SLOW         = 50; // ..slower

/* ---------------- BUTTON CONSTANTS ---------- */
static const int BTN_LATCHED_MILLS   = 700;
static const int BTN_UPDATE_SP_DELAY = 20;      // Time beteween setpoint updates in fast mode.
static const int MAX_SETPOINT        = 1800;    // The highest temp the buttons will let you go
static const int MIN_SETPOINT        = 0;       // The lowest temp the buttons will let you go

#endif // CONSTANTS_H
