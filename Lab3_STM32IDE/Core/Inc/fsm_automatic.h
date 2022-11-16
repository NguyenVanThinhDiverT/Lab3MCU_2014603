
#ifndef INC_FSM_AUTOMATIC_H_
#define INC_FSM_AUTOMATIC_H_

/* Include -----*/
#include "global.h"
#include "output_display.h"
#include "timer_interrupt.h"

/* Function -----*/
void fsm_auto_ver(void);
void fsm_auto_hor(void);
//Set state to INIT
void setInit(void);
#endif /* INC_FSM_AUTOMATIC_H_ */
