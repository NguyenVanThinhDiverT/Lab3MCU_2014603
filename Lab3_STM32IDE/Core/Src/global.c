
#include "global.h"

/* Init -----*/
int time_ver = 0;
int time_hor = 0;
int time_red = 5;
int time_yellow = 2;
int time_green = 3;

/* Function -----*/
//Check index (0 <= Index < max)
int checkIndex(int index, int max) {
  if(index >= 0 && index < max) {
	return 1;
  }
  return 0;
}
