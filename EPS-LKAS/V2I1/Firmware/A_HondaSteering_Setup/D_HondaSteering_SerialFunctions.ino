/******************Read EPS to LKAS data *************************************
  Read EPS serial, spoof small torque (spoofbytes) if timer is > 4000 ms.
******************************************************************************/
void EPS_Serial() {
  if (messageCounter > (numberOfMessages)) {
    messageCounter = 0;
    timer = 0;
  }
  if (EPStoLKAS.available()) {       //Check if serial is available
    currentByte = EPStoLKAS.read();  //Read current byte
//    Serial.println(currentByte, BIN);

    if (currentByte == 0 && timer > timeBetweenSpoofs) { //Goto spoof function
      SpoofSteeringData();
    } else {
      EPStoLKAS.write(currentByte); //passthrough if spoof criteria not met.
    }
  }
}

/****************** Manipulate EPS to LKAS data ********************************
  Sents message "SpoofBytes" to simulate driver touching the steering wheel.
  Effectively disables the "Steering Required" message.
******************************************************************************/
void SpoofSteeringData() {
  ManipulateLED=1;
  while (messageCounter < numberOfMessages + 1) {
    if (EPStoLKAS.available()) {
      messageCounter++;
      EPStoLKAS.write(SpoofBytes[messageCounter]);
    }
  }
}

/******************Read LKAS to EPS data ********************************
  Read and repeat the LKAS to EPS data.
*************************************************************************/
void LKAS_Serial() {
  if (LKAStoEPS.available()) {       //Check if serial is available
    currentByte = LKAStoEPS.read();  // Currentbyte is passthrough
    LKAStoEPS.write(currentByte);
  }
}


void repeatCAN() {
  if ( can1.read(msg) ) {
    can3.write(msg);
  }
  else if ( can3.read(msg) ) {
    can1.write(msg);
  }
}
