// default display when other players turn
void putLcd1() {
  lcd1.clear();
  lcd1.setCursor(0, 0);
  lcd1.print("Hopfen");
  lcd1.setCursor(7, 0);
  lcd1.print("Holz");
  lcd1.setCursor(13, 0);
  lcd1.print("Schaf");
  lcd1.setCursor(21, 0);
  lcd1.print("Lehm");
  lcd1.setCursor(28, 0);
  lcd1.print("Erz");
  lcd1.setCursor(2, 1);
  lcd1.print(hopfen1);
  lcd1.setCursor(8, 1);
  lcd1.print(holz1);
  lcd1.setCursor(15, 1);
  lcd1.print(schaf1);
  lcd1.setCursor(22, 1);
  lcd1.print(lehm1);
  lcd1.setCursor(28, 1);
  lcd1.print(erz1);
}

// default function to loop when other players turn to check for trading inputs
void runLcd1() {
  if (taster0[1]) {
    hopfen1++;
    abfrage("handel.php?f=" + String(sp1) + "&r=4&o=1");
    
    putLcd1();
  }

  if (taster0[2]) {
    hopfen1--;
    if (hopfen1 < 0)
      hopfen1 = 0;
    else {
      abfrage("handel.php?f=" + String(sp1) + "&r=4&o=0");
      
      putLcd1();
    }
  }

  if (taster0[3]) {
    holz1++;
    abfrage("handel.php?f=" + String(sp1) + "&r=1&o=1");
    
    putLcd1();
  }

  if (taster0[4]) {
    holz1--;
    if (holz1 < 0)
      holz1 = 0;
    else {
      abfrage("handel.php?f=" + String(sp1) + "&r=1&o=0");
      
      putLcd1();
    }
  }
  if (taster0[5]) {
    schaf1++;
    abfrage("handel.php?f=" + String(sp1) + "&r=5&o=1");
    
    putLcd1();
  }

  if (taster0[6]) {
    schaf1--;
    if (schaf1 < 0)
      schaf1 = 0;
    else {
      abfrage("handel.php?f=" + String(sp1) + "&r=5&o=0");
      
      putLcd1();
    }
  }

  if (taster0[7]) {
    lehm1++;
    abfrage("handel.php?f=" + String(sp1) + "&r=2&o=1");
    
    putLcd1();
  }

  if (taster0[8]) {
    lehm1--;
    if (lehm1 < 0)
      lehm1 = 0;
    else {
      abfrage("handel.php?f=" + String(sp1) + "&r=2&o=0");
      
      putLcd1();
    }
  }

  if (taster0[9]) {
    erz1++;
    abfrage("handel.php?f=" + String(sp1) + "&r=3&o=1");
    
    putLcd1();
  }

  if (taster0[10]) {
    erz1--;
    if (erz1 < 0)
      erz1 = 0;
    else {
      abfrage("handel.php?f=" + String(sp1) + "&r=3&o=0");
      
      putLcd1();
    }
  }
}

//analog to putLcd1
void putLcd2() {
  lcd2.clear();
  lcd2.setCursor(0, 0);
  lcd2.print("Hopfen");
  lcd2.setCursor(7, 0);
  lcd2.print("Holz");
  lcd2.setCursor(13, 0);
  lcd2.print("Schaf");
  lcd2.setCursor(21, 0);
  lcd2.print("Lehm");
  lcd2.setCursor(28, 0);
  lcd2.print("Erz");
  lcd2.setCursor(2, 1);
  lcd2.print(hopfen2);
  lcd2.setCursor(8, 1);
  lcd2.print(holz2);
  lcd2.setCursor(15, 1);
  lcd2.print(schaf2);
  lcd2.setCursor(22, 1);
  lcd2.print(lehm2);
  lcd2.setCursor(28, 1);
  lcd2.print(erz2);

}

//analog to runLcd1
void runLcd2() {        // **** Standard Anzeige 2 im Loop ****
  // *** Um die Zahl zu erhöhen bzw. zu veringern ***

  if (taster1[1]) {
    hopfen2++;
    abfrage("handel.php?f=" + String(sp2) + "&r=4&o=1");
    putLcd2();
  }

  if (taster1[2]) {
    hopfen2--;
    if (hopfen2 < 0)
      hopfen2 = 0;
    else {
      abfrage("handel.php?f=" + String(sp2) + "&r=4&o=0");
      putLcd2();
    }
  }

  if (taster1[3]) {
    holz2++;
    abfrage("handel.php?f=" + String(sp2) + "&r=1&o=1");
    putLcd2();
  }

  if (taster1[4]) {
    holz2--;
    if (holz2 < 0)
      holz2 = 0;
    else {
      abfrage("handel.php?f=" + String(sp2) + "&r=1&o=0");
      putLcd2();
    }
  }
  if (taster1[5]) {
    schaf2++;
    abfrage("handel.php?f=" + String(sp2) + "&r=5&o=1");
    putLcd2();
  }

  if (taster1[6]) {
    schaf2--;
    if (schaf2 < 0)
      schaf2 = 0;
    else {
      abfrage("handel.php?f=" + String(sp2) + "&r=5&o=0");
      putLcd2();
    }
  }

  if (taster1[7]) {
    lehm2++;
    abfrage("handel.php?f=" + String(sp2) + "&r=2&o=1");
    
    putLcd2();
  }

  if (taster1[8]) {
    lehm2--;
    if (lehm2 < 0)
      lehm2 = 0;
    else {
      abfrage("handel.php?f=" + String(sp2) + "&r=2&o=0");
      
      putLcd2();
    }
  }

  if (taster1[9]) {
    erz2++;
    abfrage("handel.php?f=" + String(sp2) + "&r=3&o=1");
    
    putLcd2();
  }

  if (taster1[10]) {
    erz2--;
    if (erz2 < 0)
      erz2 = 0;
    else {
      abfrage("handel.php?f=" + String(sp2) + "&r=3&o=0");
      
      putLcd2();
    }
  }
}

//game start displays
void welcome1() {
  lcd1.init();
  lcd1.clear();
  lcd1.backlight();
  lcd1.noBlink();
  lcd1.setCursor(3, 0);
  lcd1.print("Wilkommen zu Siedler von Muenchen");
  lcd1.setCursor(10, 1);
  lcd1.print("Viel Spass beim Spielen :-)");
}
void welcome2() {
  lcd2.init();
  lcd2.clear();
  lcd2.backlight();
  lcd2.noBlink();
  lcd2.setCursor(4, 0);
  lcd2.print("Wilkommen zu Siedler von Muenchen");
  lcd2.setCursor(8, 1);
  lcd2.print("Viel Spass beim Spielen :-)");

}


// function to handle development card submenu
void eKarten1() {
  lcd1.clear();
  lcd1.setCursor(0, 0);
  lcd1.print("Bauen");
  lcd1.setCursor(1, 1);
  lcd1.write((byte)6);
  lcd1.setCursor(6, 0);
  lcd1.print("Ritter");
  lcd1.setCursor(8, 1);
  lcd1.print(ritter1);
  lcd1.setCursor(13, 0);
  lcd1.print("Erfindung");
  lcd1.setCursor(15, 1);
  lcd1.print(erfindung1);
  lcd1.setCursor(26, 0);
  lcd1.print("Monopol");
  lcd1.setCursor(30, 1);
  lcd1.print(monopol1);
  lcd1.setCursor(34, 0);
  lcd1.print("Kaufen");
  lcd1.setCursor(33, 1);
  lcd1.print("Zurueck");
  int ungedruckt = 1;
  delay(300);
  while (ungedruckt) {
    runLcd2();
    if (taster0[11]) {        //buying a development card
      lcd1.clear();
      switch (abfrage("entwicklungskarten.php")) {
        case 0: // not enough ressources
          lcdText(1, 0, "Du hast nicht", 1);
          lcdText(1, 1, "genug Ressourcen!", 1);
          delay(2500);
          putLcd2();
          break;
        case 1: // knight drawn and added to inventory
          lcdText(1, 0, "Du hast einen", 1);
          lcdText(1, 1, "Ritter gezogen!", 1);
          lcdText(2, 0, "Dein gegenueber hat eine", 1);
          lcdText(2, 1, "Entwicklungskarte gekauft!", 1);
          ritter1++;
          delay(3000);
          putLcd2();
          break;
        case 2: // invention drawn and andded to inventory
          lcdText(1, 0, "Du hast eine", 1);
          lcdText(1, 1, "Erdfindung gezogen!", 1);
          lcdText(2, 0, "Dein gegenueber hat eine", 1);
          lcdText(2, 1, "Entwicklungskarte gekauft!", 1);
          erfindung1++;
          delay(3000);
          putLcd2();
          break;
        case 3: // two streets drawn and added to inventory, can be used by just building the streets as they would be built with ressources
          lcdText(1, 0, "Du hast zwei Strassen gezogen!", 1);
          lcdText(1, 1, "Setze sie zu einer beliebigen Zeit.", 1);
          lcdText(2, 0, "Dein gegenueber hat eine", 1);
          lcdText(2, 1, "Entwicklungskarte gekauft!", 1);
          delay(3000);
          putLcd2();
          break;
        case 4: // monopoly drawn and added to inventory
          lcdText(1, 0, "Du hast ein", 1);
          lcdText(1, 1, "Monopol gezogen!", 1);
          lcdText(2, 0, "Dein gegenueber hat eine", 1);
          lcdText(2, 1, "Entwicklungskarte gekauft!", 1);
          monopol1++;
          delay(3000);
          putLcd2();
          break;
        case 5: // victory point drawn and added to point total
          lcdText(1, 0, "Du hast einen Siegpunkt gezogen!", 1);
          lcdText(1, 1, "Er wurde dir hinzugefuegt.", 1);
          lcdText(2, 0, "Dein gegenueber hat eine", 1);
          lcdText(2, 1, "Entwicklungskarte gekauft!", 1);
          delay(3000);
          putLcd2();
          break;
      }
      upres();
      ungedruckt = 0;
    }
    if (taster0[10]) {        // playing a monopoly and selectig the ressource
      if (monopol1 > 0) {
        lcd1.clear();
        lcd1.setCursor(0, 1);
        lcd1.print("Hopfen");
        lcd1.setCursor(7, 1);
        lcd1.print("Holz");
        lcd1.setCursor(13, 1);
        lcd1.print("Schaf");
        lcd1.setCursor(21, 1);
        lcd1.print("Lehm");
        lcd1.setCursor(28, 1);
        lcd1.print("Erz");
        int r = 0;
        delay(500);
        while (r == 0) {
          delay(10);
          runLcd2();
          if (taster0[2]) {
            r = 4;
            break;
          }
          if (taster0[4]) {
            r = 1;
            break;
          }
          if (taster0[6]) {
            r = 5;
            break;
          }
          if (taster0[8]) {
            r = 2;
            break;
          }
          if (taster0[10]) {
            r = 3;
            break;
          }
        }
        lcd1.clear();
        monopol1--;
        switch (abfrage((String)"monopol.php?r=" + r)) {
          case 5:
            lcdText(1, 0, "Du hast ein Monopol ausgespielt", 1);
            lcdText(1, 1, "aber niemand hatte die Ressource.", 1);
            delay(5000);
            break;
          case 6:
            lcdText(1, 0, "Du hast dein Monopol", 1);
            lcdText(1, 1, "erfolgreich ausgespielt!", 1);
            lcdText(2, 0, "Dein Gegenueber hat alle", 1);
            lcdText(2, 1, zahlZuRes(r) + " an sich genommen!", 1);
            upres();
            delay(4000);
            putLcd2();
        }
      }
      ungedruckt = 0;
    }
    if (taster0[4]) {         // playing the knight and selecting where the robber goes
      if (ritter1 > 0) {
        int r = rauswahl(1);
        multiabfrage((String)"raeuber.php?ritter=1&r=" + r);
        switch (b[0]) {
          case 1:
            lcd2.clear();
            lcdText(2, 0, "Dein Gegenueber hat einen Ritter", 1);
            lcdText(2, 0, "   ausgespielt. Raueber auf Feld ", 0);
            lcd2.print(r);
            klauen(1);
            putLcd2();
            break;
          case 2:
            lcd1.clear();
            lcd2.clear();
            lcdText(1, 0, "Du hast die", 1);
            lcdText(1, 1, "Rittermacht!", 1);
            lcdText(2, 0, "Dein Gegenueber hat die Rittermacht!", 1);
            lcdText(2, 1, "   Der Raueber steht nun auf Feld ", 0);
            lcd2.print(r);
            delay(3000);
            klauen(1);
            putLcd2();
            break;
        }
        ritter1--;
      }
      ungedruckt = 0;
    }
    if (taster0[6]) {         // playing the invention, player can just add two ressourcces of his choice as if he would trade
      if (erfindung1) {
        lcd1.clear();
        lcdText(1, 0, "Goenne dir zwei Ressourcen", 1);
        lcdText(1, 1, "ueber das Handelsmenue!", 1);
        erfindung1--;
        delay(3000);
      }
      ungedruckt = 0;
    }
    if (taster0[2]) {         // building whatever is placed on the board, can only handle one builing at a time
      bauen(1);
      ungedruckt = 0;
    }
    if (taster0[12]) { // going back to main menu
      ungedruckt = 0;
    }
  }


}

// second players development card submenu, for comments look eKarten1 function which is analog to this one
void eKarten2() {
  lcd2.clear();
  lcd2.setCursor(0, 0);
  lcd2.print("Bauen");
  lcd2.setCursor(1, 1);
  lcd2.write((byte)6);
  lcd2.setCursor(6, 0);
  lcd2.print("Ritter");
  lcd2.setCursor(8, 1);
  lcd2.print(ritter2);
  lcd2.setCursor(13, 0);
  lcd2.print("Erfindung");
  lcd2.setCursor(15, 1);
  lcd2.print(erfindung2);
  lcd2.setCursor(26, 0);
  lcd2.print("Monopol");
  lcd2.setCursor(30, 1);
  lcd2.print(monopol2);
  lcd2.setCursor(34, 0);
  lcd2.print("Kaufen");
  lcd2.setCursor(33, 1);
  lcd2.print("Zurueck");
  int ungedruckt = 1;
  delay(300);
  while (ungedruckt) {
    runLcd1();
    if (taster1[11]) {
      lcd2.clear();
      switch (abfrage("entwicklungskarten.php")) {
        case 0:
          lcdText(2, 0, "Du hast nicht", 1);
          lcdText(2, 1, "genug Ressourcen!", 1);
          delay(2500);
          putLcd1();
          break;
        case 1:
          lcdText(2, 0, "Du hast einen", 1);
          lcdText(2, 1, "Ritter gezogen!", 1);
          lcdText(1, 0, "Dein gegenueber hat eine", 1);
          lcdText(1, 1, "Entwicklungskarte gekauft!", 1);
          ritter2++;
          delay(3000);
          putLcd1();
          break;
        case 2:
          lcdText(2, 0, "Du hast eine", 1);
          lcdText(2, 1, "Erfindung gezogen!", 1);
          lcdText(1, 0, "Dein gegenueber hat eine", 1);
          lcdText(1, 1, "Entwicklungskarte gekauft!", 1);
          erfindung2++;
          delay(3000);
          putLcd1();
          break;
        case 3:
          lcdText(2, 0, "Du hast zwei Strassen gezogen!", 1);
          lcdText(2, 1, "Setze sie zu einer beliebigen Zeit.", 1);
          lcdText(1, 0, "Dein gegenueber hat eine", 1);
          lcdText(1, 1, "Entwicklungskarte gekauft!", 1);
          delay(3000);
          putLcd1();
          break;
        case 4:
          lcdText(2, 0, "Du hast ein", 1);
          lcdText(2, 1, "Monopol gezogen!", 1);
          lcdText(1, 0, "Dein gegenueber hat eine", 1);
          lcdText(1, 1, "Entwicklungskarte gekauft!", 1);
          monopol2++;
          delay(3000);
          putLcd1();
          break;
        case 5:
          lcdText(2, 0, "Du hast einen Siegpunkt gezogen!", 1);
          lcdText(2, 1, "Er wurde dir hinzugefuegt.", 1);
          lcdText(1, 0, "Dein gegenueber hat eine", 1);
          lcdText(1, 1, "Entwicklungskarte gekauft!", 1);
          delay(3000);
          putLcd1();
          break;
      }
      upres();
      ungedruckt = 0;
    }
    if (taster1[10]) {        //Monopol ausgespielt
      if (monopol2 > 0) {
        lcd2.clear();
        lcd2.setCursor(0, 1);
        lcd2.print("Hopfen");
        lcd2.setCursor(7, 1);
        lcd2.print("Holz");
        lcd2.setCursor(13, 1);
        lcd2.print("Schaf");
        lcd2.setCursor(21, 1);
        lcd2.print("Lehm");
        lcd2.setCursor(28, 1);
        lcd2.print("Erz");
        int r = 0;
        delay(500);
        while (r == 0) {
          delay(10);
          runLcd1();
          if (taster1[2]) {
            r = 4;
            break;
          }
          if (taster1[4]) {
            r = 1;
            break;
          }
          if (taster1[6]) {
            r = 5;
            break;
          }
          if (taster1[8]) {
            r = 2;
            break;
          }
          if (taster1[10]) {
            r = 3;
            break;
          }
        }
        lcd2.clear();
        monopol2--;
        switch (abfrage((String)"monopol.php?r=" + r)) {
          case 5:
            lcdText(2, 0, "Du hast ein Monopol ausgespielt", 1);
            lcdText(2, 1, "aber niemand hatte die Ressource.", 1);
            delay(5000);
            break;
          case 6:
            lcdText(2, 0, "Du hast dein Monopol", 1);
            lcdText(2, 1, "erfolgreich ausgespielt!", 1);
            lcdText(1, 0, "Dein Gegenueber hat alle", 1);
            lcdText(1, 1, zahlZuRes(r) + " an sich genommen!", 1);
            upres();
            delay(4000);
            putLcd1();
        }
      }
      ungedruckt = 0;
    }
    if (taster1[4]) {         //Ritter ausgespielt
      if (ritter2 > 0) {
        int r = rauswahl(2);
        multiabfrage((String)"raeuber.php?ritter=1&r=" + r);
        switch (b[0]) {
          case 1:
            lcd1.clear();
            lcdText(1, 0, "Dein Gegenueber hat einen Ritter", 1);
            lcdText(1, 0, "   ausgespielt. Raueber auf Feld ", 0);
            lcd1.print(r);
            klauen(2);
            putLcd1();
            break;
          case 2:
            lcd1.clear();
            lcd2.clear();
            lcdText(2, 0, "Du hast die", 1);
            lcdText(2, 1, "Rittermacht!", 1);
            lcdText(1, 0, "Dein Gegenueber hat die Rittermacht!", 1);
            lcdText(1, 1, "   Der Raueber steht nun auf Feld ", 0);
            lcd1.print(r);
            delay(3000);
            klauen(2);
            putLcd1();
            break;
        }
        ritter2--;
      }
      ungedruckt = 0;
    }
    if (taster1[6]) {         //Erfindung ausgespielt
      if (erfindung2) {
        lcd2.clear();
        lcdText(2, 0, "Goenne dir zwei Ressourcen", 1);
        lcdText(2, 1, "ueber das Handelsmenue!", 1);
        delay(3000);
      }
      ungedruckt = 0;
    }
    if (taster1[2]) {         //Bauen
      bauen(2);
      ungedruckt = 0;
    }
    if (taster1[12]) {
      ungedruckt = 0;
    }
  }


}

int rauswahl(int sp) {
  if (sp == 1) {
    lcd1.clear();
    lcd1.setCursor(0, 0);
    lcd1.write((byte)0);
    lcd1.write((byte)5);
    lcd1.write((byte)4);
    lcd1.write((byte)0);
    lcd1.write((byte)2);
    lcd1.print("   1      2      3      4      5");
    lcd1.setCursor(0, 1);
    lcd1.print(" 6      7      8      9      10    ");
    lcd1.write((byte)3);
    lcd1.write((byte)1);
    lcd1.print("  ");
    lcd1.write((byte)1);
    int zwischen = 0;
    int zehner = 0;
    while (1) {
      if (taster0[1]) {
        if (zehner) {
          zehner = 0;
          lcd1.clear();
          lcd1.setCursor(0, 0);
          lcd1.write((byte)0);
          lcd1.write((byte)4);
          lcd1.write((byte)5);
          lcd1.write((byte)0);
          lcd1.write((byte)2);
          lcd1.print("   1      2      3      4      5");
          lcd1.setCursor(0, 1);
          lcd1.print(" 6      7      8      9      10    ");
          lcd1.write((byte)3);
          lcd1.write((byte)1);
          lcd1.setCursor(39, 1);
          lcd1.write((byte)1);
          delay(100); //debounce
        } else {
          zehner = 1;
          lcd1.clear();
          lcd1.setCursor(0, 0);
          lcd1.write((byte)0);
          lcd1.write((byte)4);
          lcd1.write((byte)0);
          lcd1.write((byte)0);
          lcd1.write((byte)2);
          lcd1.setCursor(5, 0);
          lcd1.print("   11     12     13     14     15");
          lcd1.setCursor(0, 1);
          lcd1.print(" 16     17     18     19     10    ");
          lcd1.write((byte)3);
          lcd1.write((byte)1);
          lcd1.setCursor(39, 1);
          lcd1.write((byte)1);
        }
        delay(150); //debounce
      }

      if (taster0[2]) {
        switch (zehner) {
          case 0:
            zwischen = 6;
            lcd1.setCursor(37, 1);
            lcd1.print(" 6");
            break;
          case 1:
            zwischen = 16;
            lcd1.setCursor(37, 1);
            lcd1.print("16");
            break;
        }
      }

      if (taster0[3]) {
        switch (zehner) {
          case 0:
            zwischen = 1;
            lcd1.setCursor(37, 1);
            lcd1.print(" 1");
            break;
          case 1:
            zwischen = 11;
            lcd1.setCursor(37, 1);
            lcd1.print("11");
            break;
        }
      }

      if (taster0[4]) {
        switch (zehner) {
          case 0:
            zwischen = 7;
            lcd1.setCursor(37, 1);
            lcd1.print(" 7");
            break;
          case 1:
            zwischen = 17;
            lcd1.setCursor(37, 1);
            lcd1.print("17");
            break;
        }
      }
      if (taster0[5]) {
        switch (zehner) {
          case 0:
            zwischen = 2;
            lcd1.setCursor(37, 1);
            lcd1.print(" 2");
            break;
          case 1:
            zwischen = 12;
            lcd1.setCursor(37, 1);
            lcd1.print("12");
            break;
        }
      }

      if (taster0[6]) {
        switch (zehner) {
          case 0:
            zwischen = 8;
            lcd1.setCursor(37, 1);
            lcd1.print(" 8");
            break;
          case 1:
            zwischen = 18;
            lcd1.setCursor(37, 1);
            lcd1.print("18");
            break;
        }
      }

      if (taster0[7]) {
        switch (zehner) {
          case 0:
            zwischen = 3;
            lcd1.setCursor(37, 1);
            lcd1.print(" 3");
            break;
          case 1:
            zwischen = 13;
            lcd1.setCursor(37, 1);
            lcd1.print("13");
            break;
        }
      }

      if (taster0[8]) {
        switch (zehner) {
          case 0:
            zwischen = 9;
            lcd1.setCursor(37, 1);
            lcd1.print(" 9");
            break;
          case 1:
            zwischen = 19;
            lcd1.setCursor(37, 1);
            lcd1.print("19");
            break;
        }
      }

      if (taster0[9]) {
        switch (zehner) {
          case 0:
            zwischen = 4;
            lcd1.setCursor(37, 1);
            lcd1.print(" 4");
            break;
          case 1:
            zwischen = 4;
            lcd1.setCursor(37, 1);
            lcd1.print("14");
            break;
        }
      }

      if (taster0[10]) {
        zwischen = 10;
        lcd1.setCursor(37, 1);
        lcd1.print("10");
      }


      if (taster0[11]) {
        switch (zehner) {
          case 0:
            zwischen = 5;
            lcd1.setCursor(37, 1);
            lcd1.print(" 5");
            break;
          case 1:
            zwischen = 15;
            lcd1.setCursor(37, 1);
            lcd1.print("15");
            break;
        }
      }

      if (taster0[12]) {
        return (zwischen);
      }
    }
  } else {
    lcd2.clear();
    lcd2.setCursor(0, 0);
    lcd2.write((byte)0);
    lcd2.write((byte)5);
    lcd2.write((byte)4);
    lcd2.write((byte)0);
    lcd2.write((byte)2);
    lcd2.print("   1      2      3      4      5");
    lcd2.setCursor(0, 1);
    lcd2.print(" 6      7      8      9      10    ");
    lcd2.write((byte)3);
    lcd2.write((byte)1);
    lcd2.print("  ");
    lcd2.write((byte)1);
    int zwischen = 0;
    int zehner = 0;
    while (1) {
      if (taster1[1]) {
        if (zehner) {
          zehner = 0;
          lcd2.clear();
          lcd2.setCursor(0, 0);
          lcd2.write((byte)0);
          lcd2.write((byte)4);
          lcd2.write((byte)5);
          lcd2.write((byte)0);
          lcd2.write((byte)2);
          lcd2.print("   1      2      3      4      5");
          lcd2.setCursor(0, 1);
          lcd2.print(" 6      7      8      9      10    ");
          lcd2.write((byte)3);
          lcd2.write((byte)1);
          lcd2.setCursor(39, 1);
          lcd2.write((byte)1);
        } else {
          zehner = 1;
          lcd2.clear();
          lcd2.setCursor(0, 0);
          lcd2.write((byte)0);
          lcd2.write((byte)4);
          lcd2.write((byte)0);
          lcd2.write((byte)0);
          lcd2.write((byte)2);
          lcd2.setCursor(5, 0);
          lcd2.print("   11     12     13     14     15");
          lcd2.setCursor(0, 1);
          lcd2.print(" 16     17     18     19     10    ");
          lcd2.write((byte)3);
          lcd2.write((byte)1);
          lcd2.setCursor(39, 1);
          lcd2.write((byte)1);
        }
      }

      if (taster1[2]) {
        switch (zehner) {
          case 0:
            zwischen = 6;
            lcd2.setCursor(37, 1);
            lcd2.print(" 6");
            break;
          case 1:
            zwischen = 16;
            lcd2.setCursor(37, 1);
            lcd2.print("16");
            break;
        }
      }

      if (taster1[3]) {
        switch (zehner) {
          case 0:
            zwischen = 1;
            lcd2.setCursor(37, 1);
            lcd2.print(" 1");
            break;
          case 1:
            zwischen = 11;
            lcd2.setCursor(37, 1);
            lcd2.print("11");
            break;
        }
      }

      if (taster1[4]) {
        switch (zehner) {
          case 0:
            zwischen = 7;
            lcd2.setCursor(37, 1);
            lcd2.print(" 7");
            break;
          case 1:
            zwischen = 17;
            lcd2.setCursor(37, 1);
            lcd2.print("17");
            break;
        }
      }
      if (taster1[5]) {
        switch (zehner) {
          case 0:
            zwischen = 2;
            lcd2.setCursor(37, 1);
            lcd2.print(" 2");
            break;
          case 1:
            zwischen = 12;
            lcd2.setCursor(37, 1);
            lcd2.print("12");
            break;
        }
      }

      if (taster1[6]) {
        switch (zehner) {
          case 0:
            zwischen = 8;
            lcd2.setCursor(37, 1);
            lcd2.print(" 8");
            break;
          case 1:
            zwischen = 18;
            lcd2.setCursor(37, 1);
            lcd2.print("18");
            break;
        }
      }

      if (taster1[7]) {
        switch (zehner) {
          case 0:
            zwischen = 3;
            lcd2.setCursor(37, 1);
            lcd2.print(" 3");
            break;
          case 1:
            zwischen = 13;
            lcd2.setCursor(37, 1);
            lcd2.print("13");
            break;
        }
      }

      if (taster1[8]) {
        switch (zehner) {
          case 0:
            zwischen = 9;
            lcd2.setCursor(37, 1);
            lcd2.print(" 9");
            break;
          case 1:
            zwischen = 19;
            lcd2.setCursor(37, 1);
            lcd2.print("19");
            break;
        }
      }

      if (taster1[9]) {
        switch (zehner) {
          case 0:
            zwischen = 4;
            lcd2.setCursor(37, 1);
            lcd2.print(" 4");
            break;
          case 1:
            zwischen = 4;
            lcd2.setCursor(37, 1);
            lcd2.print("14");
            break;
        }
      }

      if (taster1[10]) {
        zwischen = 10;
        lcd2.setCursor(37, 1);
        lcd2.print("10");
      }


      if (taster1[11]) {
        switch (zehner) {
          case 0:
            zwischen = 5;
            lcd2.setCursor(37, 1);
            lcd2.print(" 5");
            break;
          case 1:
            zwischen = 15;
            lcd2.setCursor(37, 1);
            lcd2.print("15");
            break;
        }
      }

      if (taster1[12]) {
        if (zwischen)
          return (zwischen);
      }
    }
  }
}

//fucntion to handle stealing when playing the robber is moved
void klauen(int sp) {
  if (sp == 1) {
    lcd1.clear();
    int s;
    if (b[2]) {
      lcdText(1, 0, "Wähle einen Spieler von dem du klauen willst:", 1);
      lcd1.setCursor(1, 8);
      lcd1.print(zahlZuSpieler(b[1]));
      lcd1.setCursor(1, 15);
      lcd1.print(zahlZuSpieler(b[2]));
      if (b[3]) {
        lcd1.setCursor(1, 22);
        lcd1.print(zahlZuSpieler(b[3]));
      }
      int u = 1;
      while (u) {
        if (taster0[4]) {
          s = b[1];
          u = 1;
        }
        if (taster0[6]) {
          s = b[2];
          u = 1;
        }
        if (taster0[8] && b[3]) {
          s = b[3];
          u = 1;
        }
      }
    } else if (b[1]) {
      s = b[1];
    } else {
      lcdText(1, 0, "Kein anliegender Spieler.", 1);
      delay(3000);
      return;
    }
    lcd1.clear();
    switch (abfrage((String)"klauen.php?fk=" + s)) {
      case 1:
        lcdText(sp, 0, "Du bekommst ein Holz!", 1);
        if (s == 2) {
          lcdText(2, 0, "Dein Gegenueber hat dir", 1);
          lcdText(2, 1, "ein " + zahlZuRes(1) + " geklaut!", 1);
        }
        delay(3000);
        break;
      case 2:
        lcdText(sp, 0, "Du bekommst ein Lehm!", 1);
        if (s == 2) {
          lcdText(2, 0, "Dein Gegenueber hat dir", 1);
          lcdText(2, 1, "ein " + zahlZuRes(2) + " geklaut!", 1);
        }
        delay(3000);
        break;
      case 3:
        lcdText(sp, 0, "Du bekommst ein Erz!", 1);
        if (s == 2) {
          lcdText(2, 0, "Dein Gegenueber hat dir", 1);
          lcdText(2, 1, "ein " + zahlZuRes(3) + " geklaut!", 1);
        }
        delay(3000);
        break;
      case 4:
        lcdText(sp, 0, "Du bekommst ein Hopfen!", 1);
        if (s == 2) {
          lcdText(2, 0, "Dein Gegenueber hat dir", 1);
          lcdText(2, 1, "ein " + zahlZuRes(4) + " geklaut!", 1);
        }
        delay(3000);
        break;
      case 5:
        lcdText(sp, 0, "Du bekommst ein Schaf!", 1);
        if (s == 2) {
          lcdText(2, 0, "Dein Gegenueber hat dir", 1);
          lcdText(2, 1, "ein " + zahlZuRes(5) + " geklaut!", 1);
        }
        delay(3000);
        break;
      case 7:
        lcdText(sp, 0, "Der gewählte Spieler", 1);
        lcdText(sp, 1, "hat keine Ressourcen.", 1);
        delay(5000);
        break;
    }


  } else if (sp == 2) {
    lcd2.clear();
    int s;
    if (b[2]) {
      lcdText(1, 0, "Wähle einen Spieler von dem du klauen willst:", 1);
      lcd2.setCursor(1, 8);
      lcd2.print(zahlZuSpieler(b[1]));
      lcd2.setCursor(1, 15);
      lcd2.print(zahlZuSpieler(b[2]));
      if (b[3]) {
        lcd2.setCursor(1, 22);
        lcd2.print(zahlZuSpieler(b[3]));
      }
      int u = 1;
      while (u) {
        if (taster1[4]) {
          s = b[1];
          u = 1;
        }
        if (taster1[6]) {
          s = b[2];
          u = 1;
        }
        if (taster1[8] && b[3]) {
          s = b[3];
          u = 1;
        }
      }
    } else if (b[1]) {
      s = b[1];
    } else {
      lcdText(sp, 0, "Kein anliegender Spieler.", 1);
      delay(3000);
      return;
    }
    lcd2.clear();
    switch (abfrage((String)"klauen.php?fk=" + s)) {
      case 1:
        lcdText(sp, 0, "Du bekommst ein Holz!", 1);
        if (s == 1) {
          lcdText(1, 0, "Dein Gegenueber hat dir", 1);
          lcdText(1, 1, "ein " + zahlZuRes(1) + " geklaut!", 1);
        }
        delay(3000);
        break;
      case 2:
        lcdText(sp, 0, "Du bekommst ein Lehm!", 1);
        if (s == 1) {
          lcdText(1, 0, "Dein Gegenueber hat dir", 1);
          lcdText(1, 1, "ein " + zahlZuRes(2) + " geklaut!", 1);
        }
        delay(3000);
        break;
      case 3:
        lcdText(sp, 0, "Du bekommst ein Erz!", 1);
        if (s == 1) {
          lcdText(1, 0, "Dein Gegenueber hat dir", 1);
          lcdText(1, 1, "ein " + zahlZuRes(3) + " geklaut!", 1);
        }
        delay(3000);
        break;
      case 4:
        lcdText(sp, 0, "Du bekommst ein Hopfen!", 1);
        if (s == 1) {
          lcdText(1, 0, "Dein Gegenueber hat dir", 1);
          lcdText(1, 1, "ein " + zahlZuRes(4) + " geklaut!", 1);
        }
        delay(3000);
        break;
      case 5:
        lcdText(sp, 0, "Du bekommst ein Schaf!", 1);
        if (s ==   1) {
          lcdText(1, 0, "Dein Gegenueber hat dir", 1);
          lcdText(1, 1, "ein " + zahlZuRes(5) + " geklaut!", 1);
        }
        delay(3000);
        break;
      case 7:
        lcdText(sp, 0, "Der gewählte Spieler", 1);
        lcdText(sp, 1, "hat keine Ressourcen.", 1);
        delay(5000);
        break;
    }

  }
}

//  player 1 turn, analog to player 2, look amZug2 for more comments
void amZug1() {
  spieler = 1;
  putLcd2();
  lcd1.clear();
  lcdText(1, 0, "Du bist nun am Zug.", 1);
  lcdText(1, 1, "Druecke um zu wuerfeln", 1);
  lcd1.setCursor(37, 1);
  lcd1.write((byte)6);


  while (!taster0[12]) {
    runLcd2();
  }

  int wuerfelZahl = abfrage("wurfel.php");

  lcd1.clear();
  lcd2.clear();
  lcd1.setCursor(14, 0);
  lcd1.print("Du hast eine ");
  lcd1.setCursor(14, 1);
  lcd1.print(wuerfelZahl);
  lcd1.setCursor(17, 1);
  lcd1.print("gewuerfelt");
  lcd1.setCursor(35, 1);
  lcd1.print("OK!");
  lcd2.setCursor(10, 0);
  lcd2.print("Dein Gegenueber hat eine ");
  lcd2.print(wuerfelZahl);
  lcd2.setCursor(17, 1);
  lcd2.print("gewuerfelt");
  upres();

  putLcd2();

  while (!taster0[12]) {
    runLcd2();
  }

  if (wuerfelZahl == 7) {
    int r = rauswahl(1);
    multiabfrage((String)"raeuber.php?ritter=0&r=" + r);
    lcd2.clear();
    lcdText(2, 0, "Raueber auf Feld ", 1);
    lcd2.print(r);
    klauen(1);
  }

  putLcd2();
  lcdHelp1();

  delay(500);

  while (1) {

    runLcd2();

    if (taster0[1]) {
      hopfen1++;
      abfrage("handel.php?f=" + String(sp1) + "&r=4&o=1");
      upres();
      lcdHelp1();
    }

    if (taster0[2]) {
      hopfen1--;
      if (hopfen1 < 0)
        hopfen1 = 0;
      else {
        abfrage("handel.php?f=" + String(sp1) + "&r=4&o=0");
        upres();
        lcdHelp1();
      }
    }

    if (taster0[3]) {
      holz1++;
      abfrage("handel.php?f=" + String(sp1) + "&r=1&o=1");
      upres();
      lcdHelp1();
    }

    if (taster0[4]) {
      holz1--;
      if (holz1 < 0)
        holz1 = 0;
      else {
        abfrage("handel.php?f=" + String(sp1) + "&r=1&o=0");
        upres();
        lcdHelp1();
      }
    }
    if (taster0[5]) {
      schaf1++;
      abfrage("handel.php?f=" + String(sp1) + "&r=5&o=1");
      upres();
      lcdHelp1();
    }

    if (taster0[6]) {
      schaf1--;
      if (schaf1 < 0)
        schaf1 = 0;
      else {
        abfrage("handel.php?f=" + String(sp1) + "&r=5&o=0");
        upres();
        lcdHelp1();
      }
    }

    if (taster0[7]) {
      lehm1++;
      abfrage("handel.php?f=" + String(sp1) + "&r=2&o=1");
      upres();
      lcdHelp1();
    }

    if (taster0[8]) {
      lehm1--;
      if (lehm1 < 0)
        lehm1 = 0;
      else {
        abfrage("handel.php?f=" + String(sp1) + "&r=2&o=0");
        upres();
        lcdHelp1();
      }
    }

    if (taster0[9]) {
      erz1++;
      abfrage("handel.php?f=" + String(sp1) + "&r=3&o=1");
      upres();
      lcdHelp1();
    }

    if (taster0[10]) {
      erz1--;
      if (erz1 < 0)
        erz1 = 0;
      else {
        abfrage("handel.php?f=" + String(sp1) + "&r=3&o=0");
        upres();
        lcdHelp1();
      }
    }


    if (taster0[11]) { // ** Entwicklungskarte Menu öffnen.
      while (1) {
        if (!taster0[12]) {
          eKarten1();
          //lcd1.noBlink();
          runLcd2();
          //lcd2.noBlink();
        } else {
          lcdHelp1();
          delay(500);
          break;  //  *** innere schleife endet ****
        }
      }
    }

    if (taster0[12]) { // **** große while Schleife hier endet
      switch (abfrage("zugend.php")) {
        case 6:
          lcd1.clear();
          lcd1.setCursor(10, 0);
          lcd1.print("Dein Zug ist jetzt beendet.");
          delay(1500);
          lcd1.clear();
          spieler = 0;
          return;
          break;
        case 4:
          lcd1.clear();
          lcd1.setCursor(10, 0);
          lcd1.print("Dein Zug ist jetzt beendet.");
          delay(1500);
          lcd1.clear();
          spieler = 2;
          amZug2();
          return;
          break;
        case 5:

        case 3:
          spieler = 1;
          lcd1.clear();
          lcd1.setCursor(6, 0);
          lcd1.print("Hast du die laengste Strasse?");
          lcd1.setCursor(9, 1);
          lcd1.print("JA!");
          lcd1.setCursor(27, 1);
          lcd1.print("NEIN!");
          while (!taster0[4] && !taster0[10]) {
            runLcd2();
          }
          if (taster0[4]) {
            abfrage("ssieg.php?s=1&f=" + sp1);
          }
          else {
            switch (abfrage("ssieg.php?s=0&f=" + sp1)) {
              case 1:
                lcd1.clear();
                lcd1.setCursor(10, 0);
                lcd1.print("Dein Zug ist jetzt beendet");
                delay(1500);
                lcd1.clear();
                spieler = 2;
                return;
                break;
              case 2:
                lcd1.clear();
                lcd1.setCursor(10, 0);
                lcd1.print("Dein Zug ist jetzt beendet");
                delay(1500);
                lcd1.clear();
                spieler = 0;
                return;
                break;
            }
            break;
          }
        case 9:
          lcd1.clear();
          lcd2.clear();
          lcd2.setCursor(11, 0);
          lcd2.print(zahlZuSpieler(sp1));
          lcd2.print(" hat gewonnen!");
          lcd1.setCursor(12, 0);
          lcd1.print("Du hast gewonnen!");
          lcd1.setCursor(9, 1);
          lcd1.print("Herzlichen Glueckwunsch!");
          while (true);
          break;
      }
      break;
    }
  }
}


// function to handle player 2 turn from beginning to end
void amZug2() {
  spieler = 2;
  putLcd1();
  lcd2.clear();
  //handle dice roll
  lcdText(2, 0, "Du bist nun am Zug.", 1);
  lcdText(2, 1, "Druecke um zu wuerfeln", 1);
  lcd2.setCursor(37, 1);
  lcd2.write((byte)6);


  while (!taster1[12]) {
    runLcd1();
  }

  int wuerfelZahl = abfrage("wurfel.php");

  lcd2.clear();
  lcd1.clear();
  lcd2.setCursor(14, 0);
  lcd2.print("Du hast eine ");
  lcd2.setCursor(14, 1);
  lcd2.print(wuerfelZahl);
  lcd2.setCursor(17, 1);
  lcd2.print("gewuerfelt");
  lcd2.setCursor(35, 1);
  lcd2.print("OK!");
  lcd1.setCursor(10, 0);
  lcd1.print("Dein Gegenueber hat eine ");
  lcd1.print(wuerfelZahl);
  lcd1.setCursor(17, 1);
  lcd1.print("gewuerfelt");
  upres();


  putLcd1();
  while (!taster1[12]) {
    runLcd1();
  }

  if (wuerfelZahl == 7) {
    int r = rauswahl(2);
    multiabfrage((String)"raeuber.php?ritter=0&r=" + r);
    lcd1.clear();
    lcdText(1, 0, "Raueber auf Feld ", 1);
    lcd1.print(r);
    klauen(2);
  }

  putLcd1();
  lcdHelp2();

  delay(500);

  while (1) {

    runLcd1();
    //first ten buttons handle ressource addition and deduction for trading
    if (taster1[1]) {
      hopfen2++;
      abfrage("handel.php?f=" + String(sp2) + "&r=4&o=1");
      upres();
      lcdHelp2();
    }

    if (taster1[2]) {
      hopfen2--;
      if (hopfen2 < 0)
        hopfen2 = 0;
      else {
        abfrage("handel.php?f=" + String(sp2) + "&r=4&o=0");
        upres();
        lcdHelp2();
      }
    }

    if (taster1[3]) {
      holz2++;
      abfrage("handel.php?f=" + String(sp2) + "&r=1&o=1");
      upres();
      lcdHelp2();
    }

    if (taster1[4]) {
      holz2--;
      if (holz2 < 0)
        holz2 = 0;
      else {
        abfrage("handel.php?f=" + String(sp2) + "&r=1&o=0");
        upres();
        lcdHelp2();
      }
    }
    if (taster0[5]) {
      schaf2++;
      abfrage("handel.php?f=" + String(sp2) + "&r=5&o=1");
      upres();
      lcdHelp2();
    }

    if (taster1[6]) {
      schaf2--;
      if (schaf2 < 0)
        schaf2 = 0;
      else {
        abfrage("handel.php?f=" + String(sp2) + "&r=5&o=0");
        upres();
        lcdHelp2();
      }
    }

    if (taster1[7]) {
      lehm2++;
      abfrage("handel.php?f=" + String(sp2) + "&r=2&o=1");
      upres();
      lcdHelp2();
    }

    if (taster1[8]) {
      lehm2--;
      if (lehm2 < 0)
        lehm2 = 0;
      else {
        abfrage("handel.php?f=" + String(sp2) + "&r=2&o=0");
        upres();
        lcdHelp2();
      }
    }

    if (taster1[9]) {
      erz2++;
      abfrage("handel.php?f=" + String(sp2) + "&r=3&o=1");
      upres();
      lcdHelp2();
    }

    if (taster1[10]) {
      erz2--;
      if (erz2 < 0)
        erz2 = 0;
      else {
        abfrage("handel.php?f=" + String(sp2) + "&r=3&o=0");
        upres();
        lcdHelp2();
      }
    }


    if (taster1[11]) { // open development card and building menu.
      while (1) {
        if (!taster1[12]) {
          eKarten2();
          runLcd1();
        } else {
          lcdHelp2();
          delay(500);
          break;
        }

      }
      lcdHelp2(); // go back to current turn starting page when done

    }

    if (taster1[12]) { //end turn and play according actions
      switch (abfrage("zugend.php")) {
        case 6:
          lcd2.clear();
          lcd2.setCursor(10, 0);
          lcd2.print("Dein Zug ist jetzt beendet.");
          delay(1500);
          lcd2.clear();
          spieler = 0;
          return;
          break;
        case 4:
          lcd2.clear();
          lcd2.setCursor(10, 0);
          lcd2.print("Dein Zug ist jetzt beendet.");
          delay(1500);
          lcd2.clear();
          spieler = 1;
          amZug1();
          return;
          break;
        case 5:

        case 3: // ask player if he has longest street if they could win with it
          spieler = 1;
          lcd2.clear();
          lcd2.setCursor(6, 0);
          lcd2.print("Hast du die laengste Strasse?");
          lcd2.setCursor(9, 1);
          lcd2.print("JA!");
          lcd2.setCursor(27, 1);
          lcd2.print("NEIN!");
          while (!taster1[4] && !taster1[10])
            runLcd1();
          if (taster1[4]) {
            abfrage("ssieg.php?s=1&f=" + String(sp2) + "");
          }
          else {
            switch (abfrage("ssieg.php?s=0&f=" + String(sp2) + "")) {
              case 1:
                lcd2.clear();
                lcd2.setCursor(10, 0);
                lcd2.print("Dein Zug ist jetzt beendet");
                delay(1500);
                lcd2.clear();
                spieler = 1;
                return;
                break;
              case 2:
                lcd2.clear();
                lcd2.setCursor(10, 0);
                lcd2.print("Dein Zug ist jetzt beendet");
                delay(1500);
                lcd2.clear();
                spieler = 0;
                return;
                break;
            }
            break;
          }
        case 9: // player has won
          lcd1.clear();
          lcd2.clear();
          lcd1.setCursor(11, 0);
          lcd1.print(zahlZuSpieler(sp1));
          lcd1.print(" hat gewonnen!");
          lcd2.setCursor(12, 0);
          lcd2.print("Du hast gewonnen!");
          lcd2.setCursor(9, 1);
          lcd2.print("Herzlichen Glueckwunsch!");
          while (true);
          break;
      }
      break;
    }
  }
}


//display current turn landing page
void lcdHelp1() {
  lcd1.clear();
  lcd1.setCursor(0, 0);
  lcd1.print("Hopfen");
  lcd1.setCursor(7, 0);
  lcd1.print("Holz");
  lcd1.setCursor(13, 0);
  lcd1.print("Schaf");
  lcd1.setCursor(21, 0);
  lcd1.print("Lehm");
  lcd1.setCursor(28, 0);
  lcd1.print("Erz");
  lcd1.setCursor(35, 0);
  lcd1.print("EntWK");
  lcd1.setCursor(2, 1);
  lcd1.print(hopfen1);
  lcd1.setCursor(8, 1);
  lcd1.print(holz1);
  lcd1.setCursor(15, 1);
  lcd1.print(schaf1);
  lcd1.setCursor(22, 1);
  lcd1.print(lehm1);
  lcd1.setCursor(28, 1);
  lcd1.print(erz1);
  lcd1.setCursor(36, 1);
  lcd1.print("Ende");
}



void lcdHelp2() {
  lcd2.clear();
  lcd2.setCursor(0, 0);
  lcd2.print("Hopfen");
  lcd2.setCursor(7, 0);
  lcd2.print("Holz");
  lcd2.setCursor(13, 0);
  lcd2.print("Schaf");
  lcd2.setCursor(21, 0);
  lcd2.print("Lehm");
  lcd2.setCursor(28, 0);
  lcd2.print("Erz");
  lcd2.setCursor(35, 0);
  lcd2.print("EntWK");
  lcd2.setCursor(2, 1);
  lcd2.print(hopfen2);
  lcd2.setCursor(8, 1);
  lcd2.print(holz2);
  lcd2.setCursor(15, 1);
  lcd2.print(schaf2);
  lcd2.setCursor(22, 1);
  lcd2.print(lehm2);
  lcd2.setCursor(28, 1);
  lcd2.print(erz2);
  lcd2.setCursor(35, 1);
  lcd2.print("Ende");
}

// display dice roll on one or both displays
void writewuerfel(int x, int w) {
  if (x == 1) {
    lcd1.clear();
    lcd1.setCursor(13, 0);
    lcd1.print("Es wurde eine");
    lcd1.setCursor(13, 1);
    lcd1.print(w);
    lcd1.setCursor(16, 1);
    lcd1.print("gewuerfelt.");
    delay(2000);
    lcdHelp1();
  }
  if (x == 2) {
    lcd2.clear();
    lcd2.setCursor(13, 0);
    lcd2.print("Es wurde eine");
    lcd2.setCursor(13, 1);
    lcd2.print(w);
    lcd2.setCursor(16, 1);
    lcd2.print("gewuerfelt.");
    delay(2000);
    lcdHelp2();
  }
  if (x == 3) {
    lcd1.clear();
    lcd1.setCursor(13, 0);
    lcd1.print("Es wurde eine");
    lcd1.setCursor(13, 1);
    lcd1.print(w);
    lcd1.setCursor(16, 1);
    lcd1.print("gewuerfelt.");
    lcd2.clear();
    lcd2.setCursor(13, 0);
    lcd2.print("Es wurde eine");
    lcd2.setCursor(13, 1);
    lcd2.print(w);
    lcd2.setCursor(16, 1);
    lcd2.print("gewuerfelt.");
    upres();
    Serial.println("wurfel durch");
    delay(2000);

  }
}

//function to display ressource name from number
String zahlZuRes(int r) {
  switch (r) {
    case 1:
      return ("Holz");
    case 2:
      return ("Lehm");
    case 3:
      return ("Erz");
    case 4:
      return ("Hopfen");
    case 5:
      return ("Schaf");
  }
}


//function to display player colour name from number
String zahlZuSpieler(int s) {
  switch (s) {
    case 1:
      return ("Weiss");
    case 2:
      return ("Blau");
    case 3:
      return ("Rot");
    case 4:
      return ("Gelb");
  }

}

//function to display development card name from number
String zahlZuEKarte(int e) {
  switch (e) {
    case 1:
      return ("Ritter");
    case 2:
      return ("Erfindung");
    case 3:
      return ("Strassenbau");
    case 4:
      return ("Monopol");
    case 5:
      return ("Siegpunkt");
  }
}

void lcdText(int lcd, int row, String text, int ltr) {

  int offset = 0;
  if (lcd == 1) {
    switch (ltr) {

      case (0): //Text to the left
        lcd1.setCursor ( offset, row );
        lcd1.print(text);
        break;

      case (1): //Text mittig
        offset = (40 - text.length()) / 2;
        lcd1.setCursor ( offset, row );
        lcd1.print(text);
        break;

      case (2): //Text to the right
        offset = (40 - text.length());
        lcd1.setCursor ( offset, row );
        lcd1.print(text);
        break;

    }
  } else {
    switch (ltr) {

      case (0): //Text to the left
        lcd2.setCursor ( offset, row );
        lcd2.print(text);
        break;

      case (1): //Text centered
        offset = (40 - text.length()) / 2;
        lcd2.setCursor ( offset, row );
        lcd2.print(text);
        break;

      case (2): //Text to the right
        offset = (40 - text.length());
        lcd2.setCursor ( offset, row );
        lcd2.print(text);
        break;

    }
  }
}

//clear selected lcd
void helplcdclear(int lcd) {
  if (lcd == 1)
    lcd1.clear();
  else
    lcd2.clear();
}

//reset selected lcd to default current turn display
void helphelplcd(int lcd) {
  if (lcd == 1)
    lcdHelp1();
  else
    lcdHelp2();
}
