
#include "fsm_automatic.h"

/* Define -----*/
//State of fsm
#define INIT 0
#define RED_STATE 1
#define YELLOW_STATE 2
#define GREEN_STATE 3
//Clock counter
#define CLOCK_TIME 1000

/* Init -----*/
int status_auto_ver = INIT;
int status_auto_hor = INIT;

/* Function -----*/
void fsm_auto_ver(void) {
  if(isTimerFlag(CLOCK_TIMER1)) {
    time_ver--;
    setTimer(CLOCK_TIME, CLOCK_TIMER1);
  }
  switch(status_auto_ver) {
  case INIT:
    status_auto_ver = RED_STATE;
    time_ver = time_red;
    setTimer(time_red * TIME_UNIT, VER_TIMER);
    setTimer(CLOCK_TIME, CLOCK_TIMER1);
    break;
  case RED_STATE:
	LED_on_ver(RED);
	if(isTimerFlag(VER_TIMER) == 1) {
	  status_auto_ver = GREEN_STATE;
	  time_ver = time_green;
	  setTimer(time_green * TIME_UNIT, VER_TIMER);
	  setTimer(CLOCK_TIME, CLOCK_TIMER1);
	}
    break;
  case YELLOW_STATE:
	LED_on_ver(YELLOW);
	if(isTimerFlag(VER_TIMER) == 1) {
	  status_auto_ver = RED_STATE;
	  time_ver = time_red;
	  setTimer(time_red * TIME_UNIT, VER_TIMER);
	  setTimer(CLOCK_TIME, CLOCK_TIMER1);
	}
    break;
  case GREEN_STATE:
	LED_on_ver(GREEN);
	if(isTimerFlag(VER_TIMER) == 1) {
	  status_auto_ver = YELLOW_STATE;
	  time_ver = time_yellow;
	  setTimer(time_yellow * TIME_UNIT, VER_TIMER);
	  setTimer(CLOCK_TIME, CLOCK_TIMER1);
	}
    break;
  }
}
void fsm_auto_hor(void) {
  if(isTimerFlag(CLOCK_TIMER2)) {
    time_hor--;
    setTimer(CLOCK_TIME, CLOCK_TIMER2);
  }
  switch(status_auto_hor) {
  case INIT:
    status_auto_hor = GREEN_STATE;
    time_hor = time_green;
    setTimer(time_green * TIME_UNIT, HOR_TIMER);
    setTimer(CLOCK_TIME, CLOCK_TIMER2);
    break;
  case RED_STATE:
	LED_on_hor(RED);
	if(isTimerFlag(HOR_TIMER) == 1) {
	  status_auto_hor = GREEN_STATE;
	  time_hor = time_green;
	  setTimer(time_green * TIME_UNIT, HOR_TIMER);
	  setTimer(CLOCK_TIME, CLOCK_TIMER2);
	}
    break;
  case YELLOW_STATE:
	LED_on_hor(YELLOW);
	if(isTimerFlag(HOR_TIMER) == 1) {
	  status_auto_hor = RED_STATE;
	  time_hor = time_red;
	  setTimer(time_red * TIME_UNIT, HOR_TIMER);
	  setTimer(CLOCK_TIME, CLOCK_TIMER2);
	}
    break;
  case GREEN_STATE:
	LED_on_hor(GREEN);
	if(isTimerFlag(HOR_TIMER) == 1) {
	  status_auto_hor = YELLOW_STATE;
	  time_hor = time_yellow;
	  setTimer(time_yellow * TIME_UNIT, HOR_TIMER);
	  setTimer(CLOCK_TIME, CLOCK_TIMER2);
	}
    break;
  }
}
//Set state to INIT
void setInit(void) {
  status_auto_ver = INIT;
  status_auto_hor = INIT;
}
