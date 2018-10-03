#ifndef CONSTANTS_H
#define CONSTANTS_H

#include <stdint.h>

/* ----------------- PINS ----------------------*/
static const unsigned short BRIGHTNESS_BTN_PIN = 3;

/* ----------------- PIXELS --------------------*/
static const short   PIXEL_ARRAY_PIN            = 4;
static const uint8_t NUM_PIXELS                 = 5;
static const uint8_t PIXEL_MAX_BRIGHTNESS       = 255;

/* ---------------- BUTTON CONSTANTS ---------- */
static const int BTN_LATCHED_MILLS   = 700;
static const int BTN_UPDATE_SP_DELAY = 20;      // Time beteween setpoint updates in fast mode.
static const int MAX_SETPOINT        = 1800;    // The highest temp the buttons will let you go
static const int MIN_SETPOINT        = 0;       // The lowest temp the buttons will let you go

/* ---------------- GENERAL CONSTANTS ----------*/
static const int MAX_BRIGHTNESS_LVL = 5;

#endif // CONSTANTS_H
