//function to handle the start of the game, until last player placed their  two streets and settlements
void startloop() {
  cled();
  boolean a = 1;
  while (1) {
    multiabfrage((String)"logabfrage.php?b="+brett+"&nr=" + log_num);
    if(b[0])
      Serial.println(b[0]);
//    prfr();
    a = 1;
    switch (b[0]) {
      case 13:
        log_num++;
        break;
      case 1:
        led(b[1], b[3], 1);
        delay(5);
        log_num++;
        break;
      case 3:
        led(b[1], b[3], 1);
        delay(5);
        log_num++;
        break;
      case 11:
        spieler = b[3];
        log_num++;
        if(spieler == sp1){
		      amZug1();
		      return;
		    } else if(spieler == sp2){
			    amZug2();
			    return;
			  }
        return;
        break;
      case 12:
        lcd1.clear();
        lcd2.clear();
        lcdText(1, 0, "Die Startphase ist beendet", 1);
        lcdText(1, 1, "und " + zahlZuSpieler(b[3]) + " ist jetzt am Zug!", 1);
        lcdText(2, 0, "Die Startphase ist beendet", 1);
        lcdText(2, 1, "und " + zahlZuSpieler(b[3]) + " ist jetzt am Zug!", 1);
        log_num++;
        return;
        break;
      case 14:
        log_num++;
        while (a) {
          lcd1.clear();
          lcd2.clear();
          if (b[3] == sp1) {
            lcdText(1, 0, "Platziere ein Haus und eine Strasse!", 1);
            lcdText(1, 1, "Platzierung bestaetigen   ", 2);
            lcd1.setCursor(38, 1);
            lcd1.write((byte)6);
            lcdText(2, 0, zahlZuSpieler(b[3])+" ist nun dran.", 1);
            waitconfirm(1);

            switch (startbauen(1)) {
              case 0:
                break;
              case 4:
                lcdText(1, 0, "Die Startphase ist beendet", 1);
                lcdText(1, 1, "und du bist nun am Zug!", 1);
                lcdText(2, 0, "Die Startphase ist beendet", 1);
                lcdText(2, 1, "und " + zahlZuSpieler(b[3]) + " ist jetzt am Zug!", 1);
                spieler = 1;
                readmagnet();
                calmagnets();
                return;
              case 6:
                lcdText(1, 0, "Dein Zug wurde", 1);
                lcdText(1, 1, "erfolgreich ausgefuehrt!", 1);
                a = 0;
                break;

            }
            readmagnet();
            calmagnets();
          }
          if (b[3] == sp2) {
            lcdText(2, 0, "Platziere ein Haus und eine Strasse!", 1);
            lcdText(2, 1, "Platzierung bestaetigen   ", 2);
            lcd2.setCursor(38, 1);
            lcd2.write((byte)6);
            lcdText(1, 0, zahlZuSpieler(b[3])+" ist nun dran.", 1);
            waitconfirm(2);
            switch (startbauen(2)) {
              case 0:
                break;
              case 4:
                lcdText(2, 0, "Die Startphase ist beendet", 1);
                lcdText(2, 1, "und du bist nun am Zug!", 1);
                lcdText(1, 0, "Die Startphase ist beendet", 1);
                lcdText(1, 0, "und " + zahlZuSpieler(b[3]) + " ist jetzt am Zug!", 1);
                spieler = 2;
                readmagnet();
                calmagnets();
                return;
              case 6:
                lcdText(2, 0, "Dein Zug wurde", 1);
                lcdText(2, 1, "erfolgreich ausgefuehrt!", 1);
                a = 0;
                break;

            }
            readmagnet();
            calmagnets();
          }
        }
        break;
      case 15:
        log_num++;
        lcd1.clear();
        lcd2.clear();
        lcdText(1, 0, zahlZuSpieler(b[3]) + " ist jetzt am Zug.", 1);
        lcdText(2, 0, zahlZuSpieler(b[3]) + " ist jetzt am Zug.", 1);
        break;
    }
  }
}
