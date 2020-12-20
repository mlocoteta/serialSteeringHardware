void setup() {
  Serial.begin(152000); // Setup USB
  EPStoLKAS.begin(9600, SERIAL_8E1);
  LKAStoEPS.begin(9600, SERIAL_8E1);
  pinSetup();
  delay(100);
  setupSettings();
  can1.begin();
  can1.setBaudRate(500000);
  can3.begin();
  can3.setBaudRate(500000);
}

void loop() {
  EPS_Serial();
  LKAS_Serial();
  LEDtimer();
  readPB();
  repeatCAN();

  if (i > 7) {
    i = 0;
//    Serial.println(msg);
  }
}
