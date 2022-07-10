void softSerial(){ //Relay Serial in both directions
    while (bluetoothSerial.available() > 0) { //if vs while
      w = bluetoothSerial.read();
      data = String(w);
      Serial.write(w);
    }

    if (Serial.available() > 0) {
      w = Serial.read();
      bluetoothSerial.write(w);
  
      if (NL) {
        Serial.print(">");
        NL = false;
      }
      Serial.write(w);
      if (w == 10) {
        NL = true;
      }
    }
  
  }
