
#include "fsm_manual.h"

/* Define -----*/
//State of fsm
#define INIT 1
#define MAN_RED 2
#define MAN_AMBER 3
#define MAN_GREEN 5
//Time for fsm
#define RETURN_INIT 10000

/* Init -----*/
int status_manual = INIT;

/* Function ----*/
//Auto return to INIT
void returnINIT(void) {
  status_manual = INIT;
  setInit();
}
//Increasing time
void inc_time(void) {
  time_hor++;
  if(time_hor > 99) {
    time_hor = 0;
  }
}
//state machine
void fsm_manual(void) {
  switch(status_manual) {
  case INIT:
    fsm_auto_ver();
    fsm_auto_hor();
    if(isButtonPressed(MODE_BUTTON) == 1) {
      status_manual = MAN_RED;
      time_ver = MAN_RED;
      time_hor = time_red;
      restartDisplay();
      setTimer(RETURN_INIT, INIT_TIMER);
    }
    break;
  case MAN_RED:
	blinkLED(RED);
	if(isButtonPressed(MODE_BUTTON) == 1) {
	  status_manual = MAN_AMBER;
	  time_ver = MAN_AMBER;
	  time_hor = time_yellow;
      restartDisplay();
	  setTimer(RETURN_INIT, INIT_TIMER);
	}
	if(isButtonPressed(MODIFY_BUTTON) == 1) {
	  inc_time();
	  setTimer(RETURN_INIT, INIT_TIMER);
	}
	if(isButtonPressed(SET_BUTTON) == 1) {
	  time_red = time_hor;
	  setTimer(RETURN_INIT, INIT_TIMER);
	}
	if(isTimerFlag(INIT_TIMER) == 1) {
	  restartDisplay();
	  returnINIT();
	}
	break;
  case MAN_AMBER:
	blinkLED(YELLOW);
	if(isButtonPressed(MODE_BUTTON) == 1) {
	  status_manual = MAN_GREEN;
	  time_ver = MAN_GREEN;
	  time_hor = time_green;
      restartDisplay();
	  setTimer(RETURN_INIT, INIT_TIMER);
	}
	if(isButtonPressed(MODIFY_BUTTON) == 1) {
	  inc_time();
	  setTimer(RETURN_INIT, INIT_TIMER);
	}
	if(isButtonPressed(SET_BUTTON) == 1) {
	  time_yellow = time_hor;
	  setTimer(RETURN_INIT, INIT_TIMER);
	}
	if(isTimerFlag(INIT_TIMER) == 1) {
	  restartDisplay();
	  returnINIT();
	}
	break;
  case MAN_GREEN:
	blinkLED(GREEN);
	if(isButtonPressed(MODE_BUTTON) == 1) {
	  status_manual = INIT;
      restartDisplay();
	  setInit();
	}
	if(isButtonPressed(MODIFY_BUTTON) == 1) {
	  inc_time();
	  setTimer(RETURN_INIT, INIT_TIMER);
	}
	if(isButtonPressed(SET_BUTTON) == 1) {
	  time_green = time_hor;
	  setTimer(RETURN_INIT, INIT_TIMER);
	}
	if(isTimerFlag(INIT_TIMER) == 1) {
	  restartDisplay();
	  returnINIT();
	}
	break;
  }
}
