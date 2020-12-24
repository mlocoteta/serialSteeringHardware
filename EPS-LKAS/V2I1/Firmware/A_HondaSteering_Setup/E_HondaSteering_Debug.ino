void LEDtimer(){
  if(ManipulateLED){
    BLUE_LED_ON;
    ManipulateLED=0;
    LEDtime = 0;
  } 
  if(LEDtime > LEDtimeON){
    BLUE_LED_OFF;
    LEDtime=500;
  }
}

//switch (debugCase){
//  case 'a': 
//}
