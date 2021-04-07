#include "led.h"
#include "switches.h"
#include "stateMachines.h"

char tempo;

void switchSM(){  
  if(switch_state_down1 && switch_state_down2){
    red_on ^= 1;
    if(red_on == 1) buzzer_set_period(4000);
    else buzzer_set_period(0);
  }
  
  else if (switch_state_down3){
    green_on ^= 1;
    if(green_on == 1) buzzer_set_period(2000);
    else buzzer_set_period(0);
  }
  else if (switch_state_down4){
    stateMachine1();  
  }
  
  else buzzer_set_period(0);
  
  led_changed = 1;
  led_update();
}


void stateMachine1(){
   static char state = 0;
   switch(state){
   case 0: red_on = 1; green_on = 0; state++;led_update(); break;
   case 1: green_on = 1; red_on = 0; state = 0;led_update(); break;
   }
   led_changed = 1;
   led_update();
}

