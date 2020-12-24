void ledReset() {
  digitalWrite(EPS_RX, LOW);
  digitalWrite(EPS_TX, LOW);
  digitalWrite(LKAS_RX, LOW);
  digitalWrite(LKAS_TX, LOW);
  digitalWrite(BLUE_LED, LOW);
}

void setupSettings() {
  if (digitalRead(DIP1) == LOW) {
    Serial.println("DIP 1 Active");
    timeBetweenSpoofs = 6000;

  }
  if (digitalRead(DIP2) == LOW) {
    Serial.println("DIP 2 Active");
    timeBetweenSpoofs = 5000;

  }
  if (digitalRead(DIP3) == LOW) {
    Serial.println("DIP 3 Active");
    timeBetweenSpoofs = 4000;

  }
  if (digitalRead(DIP4) == LOW) {
    Serial.println("DIP 4 Active");
    timeBetweenSpoofs = 3000;

  }
  if (digitalRead(DIP5) == LOW) {
    Serial.println("DIP 5 Active");
    timeBetweenSpoofs = 2000;

  }
  if (digitalRead(DIP6) == LOW) {
    Serial.println("DIP 6 Active");
    timeBetweenSpoofs = 1000;

  }
  if (digitalRead(DIP7) == LOW) {
    Serial.println("DIP 7 Active");
    timeBetweenSpoofs = 500;
  }
}

void readPB() {
  if (PB1.readFalling()) {
    Serial.println("PB1 Active");
    setupSettings();

  }

  if (PB2.readFalling()) {
    Serial.println("PB2 Active");    //DO SOMETHING
  }

  if (PB3.readFalling()) {
    Serial.println("PB3 Active");
  }

  if (PB4.readFalling()) {
    Serial.println("PB4 Active");
  }
}
