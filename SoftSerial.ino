void softSerial(){ //Relay Serial in both directions
    if (bluetoothSerial.available() > 0) { //if vs while
      w = bluetoothSerial.read();
      data = String(w);
      Serial.write(w);
    }

    //hook
    if (data.equals("p")){
      int cm = Sonar.convert_cm(Sonar.ping_median(7));
      bluetoothSerial.println("Pong: " + String(cm) + "cm");
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
