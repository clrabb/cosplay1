#ifndef CONSTANTS_H
#define CONSTANTS_H

#include <stdint.h>




/* ----------------- PINS ----------------------*/
#ifdef FEATHER_M0
#pragma message "Compiling for FEATHER"
static const unsigned short COMMAND_BTN_PIN     = 11;
static const unsigned short PIXEL_ARRAY_PIN     = 15;
static const unsigned short HEARTBEAT_PIN       = 18; 
#else  // Assume trinket
#pragma message "Compiling for TRINKET"
static const unsigned short COMMAND_BTN_PIN     = 3;
static const unsigned short PIXEL_ARRAY_PIN     = 4;
static const unsigned short HEARTBEAT_PIN       = 2; 
#endif // FEATHER_M0

/* ----------------- HEARTBEAT -----------------*/
static const unsigned long MILLS_BETWEEN_BEATS = 1500;
static const unsigned long MILLS_BEAT_LENGTH   = 150;


/* ----------------- PIXELS --------------------*/

static const uint8_t NUM_PIXELS                 = 8;
static const uint8_t PIXEL_MAX_BRIGHTNESS       = 255;

/* ---------------- COMMANDS -------------------*/
static unsigned long MILLS_BETWEEN_CMD_CHANGE   = 5000;

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
static const int LED_ABSOLUTE_BRIGHTNESS        = 255;

#endif // CONSTANTS_H
