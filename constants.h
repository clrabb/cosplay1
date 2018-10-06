#ifndef CONSTANTS_H
#define CONSTANTS_H

#include <stdint.h>


#ifdef ARDUINO_AVR_GEMMA
/* ----------------- PINS ----------------------*/
static const unsigned short BRIGHTNESS_BTN_PIN  = 0;
static const unsigned short COMMAND_BTN_PIN     = 1;
static const unsigned short PIXEL_ARRAY_PIN     = 2;
#else
static const unsigned short BRIGHTNESS_BTN_PIN  = 3;
static const unsigned short COMMAND_BTN_PIN     = 4;
static const unsigned short PIXEL_ARRAY_PIN     = 5;
#endif // GEMMA

/* ----------------- PIXELS --------------------*/

static const uint8_t NUM_PIXELS                 = 5;
static const uint8_t PIXEL_MAX_BRIGHTNESS       = 255;

/* ---------------- COMMANDS -------------------*/
static const uint8_t NUM_COMMANDS               = 5;

/* ---------------- SIMPLE_BLINK ---------------*/
static const int SIMPLE_BLINK_DURATION_MILLS    = 200;

/* ---------------- RAINBOW --------------------*/
static const uint32_t RAINBOW_LOOP_DELAY_MILLS  = 50;

/* ---------------- BUTTON CONSTANTS ---------- */
static const int BTN_LATCHED_MILLS   = 700;
static const int BTN_UPDATE_SP_DELAY = 20;      // Time beteween setpoint updates in fast mode.
static const int MAX_SETPOINT        = 1800;    // The highest temp the buttons will let you go
static const int MIN_SETPOINT        = 0;       // The lowest temp the buttons will let you go

/* ---------------- GENERAL CONSTANTS ----------*/
static const int LED_ABSOLUTE_BRIGHTNESS        = 5;
static const int MILLS_BETWEEN_HEARTBEATS       = 1000;
static const int HEARTBEAT_LENGTH_MILLS         = 200; 

#endif // CONSTANTS_H
