// read out ioextenders which the buttons are connected to
void readt() {
  int x,y;
  switch(brett){
    case 1:
      x = 2*ioex0.read();
      y = 2*ioex1.read();
      break;
    case 2:
      y = 2*ioex0.read();
      x = 2*ioex1.read();
      break;
    }
    
  for (int i = 0; i < 14; i++)
    taster0[i] = false;
  switch (x) {
    case 1:
      taster0[0] = true;
      break;
    case 2:
      taster0[1] = true;
      break;
    case 4:
      taster0[2] = true;
      break;
    case 8:
      taster0[3] = true;
      break;
    case 16:
      taster0[4] = true;
      break;
    case 32:
      taster0[5] = true;
      break;
    case 64:
      taster0[6] = true;
      break;
    case 128:
      taster0[7] = true;
      break;
    case 256:
      taster0[8] = true;
      break;
    case 512:
      taster0[9] = true;
      break;
    case 1024:
      taster0[10] = true;
      break;
    case 2048:
      taster0[11] = true;
      break;
    case 4096:
      taster0[12] = true;
      break;
    default:
      if (spieler != 0) {
        for (int i = 0; i < 13; i++)
          taster0[i] = false;
        bpressed = false;
      }
      break;
  }
  for (int i = 0; i < 12; i++)
    taster1[i] = false;
  switch (y) {
    case 1:
      taster1[0] = true;
      break;
    case 2:
      taster1[1] = true;
      break;
    case 4:
      taster1[2] = true;
      break;
    case 8:
      taster1[3] = true;
      break;
    case 16:
      taster1[4] = true;
      break;
    case 32:
      taster1[5] = true;
      break;
    case 64:
      taster1[6] = true;
      break;
    case 128:
      taster1[7] = true;
      break;
    case 256:
      taster1[8] = true;
      break;
    case 512:
      taster1[9] = true;
      break;
    case 1024:
      taster1[10] = true;
      break;
    case 2048:
      taster1[11] = true;
      break;
    case 4096:
      taster1[12] = true;
      break;
    default:
      for (int i = 0; i < 13; i++)
        taster1[i] = false;
      bpressed = false;
      break;
  }
}

//function to wait for selected players confirmation of anything, used for startup sequence
void waitconfirm(int pl){
  switch(pl){
    case 1:
      while(!taster0[12]){
        //Experience ... nothingness
        delay(5);
        }
      break;
    case 2:
      while(!taster1[12]){
        //Experience ... nothingness
        delay(5);
        }
      break;
    default:
      break;
    }
  }

//function to calibrate magnets by saving their current value in an array which can be used for comparison when smthing is supposed to be built
void calmagnets(){
  for (int i = 0; i < NUM; i++) {
      imagnet[i] = magnet[i];
    }
  }


// read out all the magnets
void readmagnet() {
  for (int i = 0; i < 8; i++) { //reads analog inputs

    switch (i) { // sets correct multiplexer outputs
      case 0:
        digitalWrite(s0, LOW);
        digitalWrite(s1, LOW);
        digitalWrite(s2, LOW);
        break;
      case 1:
        digitalWrite(s0, HIGH);
        digitalWrite(s1, LOW);
        digitalWrite(s2, LOW);
        break;
      case 2:
        digitalWrite(s0, LOW);
        digitalWrite(s1, HIGH);
        digitalWrite(s2, LOW);
        break;
      case 3:
        digitalWrite(s0, HIGH);
        digitalWrite(s1, HIGH);
        digitalWrite(s2, LOW);
        break;
      case 4:
        digitalWrite(s0, LOW);
        digitalWrite(s1, LOW);
        digitalWrite(s2, HIGH);
        break;
      case 5:
        digitalWrite(s0, HIGH);
        digitalWrite(s1, LOW);
        digitalWrite(s2, HIGH);
        break;
      case 6:
        digitalWrite(s0, LOW);
        digitalWrite(s1, HIGH);
        digitalWrite(s2, HIGH);
        break;
      case 7:
        digitalWrite(s0, HIGH);
        digitalWrite(s1, HIGH);
        digitalWrite(s2, HIGH);
        break;
      default:
        break;

    }
    
    //reads analog inputs
    delay(30);
    magnet[i] = analogRead(A0);
    magnet[i + 1 * 8] = analogRead(A1);
    magnet[i + 2 * 8] = analogRead(A2);
    magnet[i + 3 * 8] = analogRead(A3);
    magnet[i + 4 * 8] = analogRead(A6);
    magnet[i + 5 * 8] = analogRead(A7);
    magnet[i + 6 * 8] = analogRead(A8);
    magnet[i + 7 * 8] = analogRead(A9);
    magnet[i + 8 * 8] = analogRead(A10);
    magnet[i + 9 * 8] = analogRead(A11);
    magnet[i + 10 * 8] = analogRead(A12);
    magnet[i + 11 * 8] = analogRead(A13);
    magnet[i + 12 * 8] = analogRead(A14);
    magnet[i + 13 * 8] = analogRead(A15);
    magnet[i + 14 * 8] = analogRead(A16);
    magnet[i + 15 * 8] = analogRead(A17);


  }

} 
