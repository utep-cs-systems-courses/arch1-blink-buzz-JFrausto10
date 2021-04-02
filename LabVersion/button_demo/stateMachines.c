#include "led.h"
#include "switches.h"

void switchSM(){
  if(switch_state_down1) red_on ^= 1;
  if(switch_state_down2) green_on ^= 1;
  /*
  if(switch_state_down3 && !switch_state_down1) buzzer_set_period(2000);
  else if (switch_state_down3 && switch_state_down1) buzzer_set_period(1000);
  else buzzer_set_period(0);
  */
  led_changed = 1;
  led_update();
}

/*
void stateMachine1(){
  static char state = 0;
  switch(state){
  case 0: red_on = 1; state++; break;
  case 1: green_on = 1; state++; break;
  default: state = 0;
  }
*/
