//functions to handle the setup display used in the beginning. I only edited the values and slightly adjusted the logic, so there isn't really any annotation as I don't really understand it myself. Works, but is quite unreliable

#define PINA 10 //clock pin of rotary encoder
#define PINB 11 //data pin of rotary encoder
#define PUSHP 12 //button of rotary encoder
#define INTERRUPT 10  // same as PINA
#define INTERRUPTB 12  // same as PINB

volatile boolean turned;   // rotary was turned
volatile boolean fired;    // knob was pushed
volatile boolean up;  // true when turned cw

unsigned long previousTime = 0;
unsigned long currentTime = 0;


int Maxlines;
int CursorLine = 0;
int DisplayFirstLine = 0;
int MenueItems;
char* MenueLine[] = {"1. Spiel starten", "2. Spieleranzahl", "3. Standardstellung", "4. Lichtshow", "5. Spiel verlassen"};
char* MenueLine1[] = {"1. 1 Spieler", "2. 2 Spieler", "3. zurueck"};
char* MenueLine2[] = {"1. Weiss/Rot", "2. Blau/Gelb", "3. zurueck"};
char* MenueLine3[] = {" Sicher?", "1. Ja", "2. Nein"};
char* MenueLine4[] = {"  Standardstellung?", "1. Ja", "2. Nein"};

//help variables
int zuruck = 0;
int zuruck1 = 0;
int zuruck2 = 0;
int zuruck3 = 0;
int i = 0;
int k = 0;

//Server variables
int UbergangLcdRessourcen = 0;
int blau = 0;
int weiss = 0;
int zweiSpieler = 0;
int spielAus = 0;
int standard = 0;
String standardS = "Nein";
boolean resStart = 1;


// Interrupt Service Routine for a change to pushpin
void isrp ()
{
  if (!digitalRead (PUSHP))
    fired = true;
}  // end of isr

// Interrupt Service Routine for a change to encoder pin A
void isr ()
{
  if (digitalRead (PINA))
    up = digitalRead (PINB);
  else
    up = !digitalRead (PINB);
  turned = true;

}
/*
  int pot;
  int led;
*/
/* §§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§ */

void setuplcd ()
{
  digitalWrite (PINA, HIGH);     // enable pull-ups
  digitalWrite (PINB, HIGH);
  digitalWrite (PUSHP, HIGH);
  attachInterrupt (INTERRUPT, isr, CHANGE);
  attachInterrupt (INTERRUPTB, isrp, FALLING);

  lcd.init();
  lcd.backlight();

  lcd.setCursor(0, 0);
  lcd.print("Siedler von Muenchen");
  lcd.setCursor(5, 2);
  lcd.print("Willkommen");
  delay(3000);
  //MenueItems = sizeof(MenueLine)/sizeof(MenueLine[0]);
#ifdef DEBUG
  Serial.println("Siedler von Muenchen");
  Serial.print("Willkommen");
  Serial.println(MenueItems);
#endif
  lcd.clear();
  print_menue(MenueLine, 4);
#ifdef I2CDISPLAY
  lcd.cursor_on();
#else
  lcd.cursor();
#endif
  lcd.blink();

  //  pinMode(6, OUTPUT);

  
  
  while (resStart) {
    if (turned)
    {
      if (up)
        move_up(MenueLine, 4, 5);
      else
        move_down(MenueLine, 4, 5);
      turned = false;
    }
    else if (fired)
    {
      lcd.setCursor(0, 0);
      selection();
      delay(200);
      fired = false;
    }


  }


}


/* §§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§ */


void print_menue(char * *MenueLine, int Maxlines) {
  int i;
  lcd.clear();
  lcd.setCursor(0, 0);
  for (i = 0; i < Maxlines; i++) {
    lcd.setCursor(0, i);
    lcd.print(MenueLine[DisplayFirstLine + i]);
  }
  i = 0;
  lcd.setCursor(0, (CursorLine - DisplayFirstLine));

}

void move_down(char * *MenueLine, int Maxlines, int MenueItems) {
  if (CursorLine == (DisplayFirstLine + Maxlines - 1)) {
    DisplayFirstLine++;
  }
  if (CursorLine == (MenueItems - 1)) {
    CursorLine = 0;
    DisplayFirstLine = 0;
  }
  else {
    CursorLine = CursorLine + 1;
  }
  print_menue(MenueLine, Maxlines);
}

void move_up(char * *MenueLine, int Maxlines, int MenueItems) {
  if ((DisplayFirstLine == 0) & (CursorLine == 0)) {
    DisplayFirstLine = MenueItems - Maxlines;
  }
  else if (DisplayFirstLine == CursorLine) {
    DisplayFirstLine--;
  }
  if (CursorLine == 0) {
    CursorLine = MenueItems - 1;
  }
  else {
    CursorLine = CursorLine - 1;
  }
  print_menue(MenueLine, Maxlines);
}

// function for the server
void server(int blau, int weiss, int zweiSpieler) {
  int x;
  if (blau == 6) x = 1;
  if (weiss == 6) x = 2;
  if (zweiSpieler == 6) x = 3;
  multiabfrage((String)"init.php?b="+brett+"&spieler=" + x + "&s=" + standard);
  //  resStart=0;                                                                                                                      // NOCH NICHT GEMACHT!
}



/* §§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§ */


void selection() { //does according action after selection of a menu item

#ifdef DEBUG
  Serial.print("Menueline ");
  Serial.print(CursorLine);
  Serial.println(" selected");
  Serial.print("..this is Menuetext ");
  Serial.println(MenueLine[CursorLine]);
#endif


  switch (CursorLine) {

    case 0: //start hame if necessary variables were set
      if (blau == 0 && weiss == 0 && zweiSpieler == 0) {
        lcd.clear();
        lcd.setCursor(2, 1);
        lcd.print("Spielerzahl noch");
        lcd.setCursor(1, 2);
        lcd.print("nicht ausgewaehlt!");
        delay(3000);
        break;
      }
      fired = 0;
      UbergangLcdRessourcen = 1;
      lcd.clear();
      lcd.setCursor(0, 1);
      lcd.print("Siedler von Muenchen");
      lcd.setCursor(2, 2);
      lcd.print("wird geladen...");
      delay(200);
      server(blau, weiss, zweiSpieler);
      delay(500);
      for (int i = 1; i < 19; i++) {
        feldres(i, b[i]);
        delay(50);
      }
      lcd.clear();
      lcd.setCursor(2, 0);
      lcd.print("Setze die Felder");
      lcd.setCursor(3, 1);
      lcd.print("wie angegeben.");
      lcd.setCursor(0, 2);
      lcd.print("Die erste Zahl kommt");
      lcd.setCursor(3, 3);
      lcd.print("an Stelle: ");
      lcd.print(b[20]);
      delay(5000);
      while (!fired){
        };
      switch (b[0]) {
        case 2:
          lcd.clear();
          lcd.setCursor(6, 1);
          lcd.print("Warte auf");
          lcd.setCursor(4, 2);
          lcd.print("anderes brett.");
          while (1) {
            multiabfrage("logabfrage.php?b="+String(brett)+"&nr=1");
            if (b[0] == 13) {
              cled();
              lcd.clear();
              lcd.setCursor(3, 1);
              lcd.print("Spiel startet!");
              detachInterrupt(INTERRUPT);
              detachInterrupt(INTERRUPTB);
              delay(3000);
              lcd.noBacklight();
              lcd.noDisplay();
              log_num++;
              break;
            }
          }
          break;
        case 1:
          cled();
          lcd.clear();
          lcd.setCursor(3, 1);
          lcd.print("Spiel startet!");
          detachInterrupt(INTERRUPT);
          detachInterrupt(INTERRUPTB);
          delay(3000);
          lcd.noBacklight();
          lcd.noDisplay();
          break;
      }
      resStart=0;
      return;

    case 1: //select number of players and players color/position when theres only one player
      DisplayFirstLine = 0;
      print_menue(MenueLine1, 3);
      //lcd.setCursor(0,0);
      previousTime = millis();
      zuruck = 0;

      do {

        if (turned)
        {
          if (up)
            move_up(MenueLine1, 3, 3);
          else
            move_down(MenueLine1, 3, 3);
          turned = false;
        }
        if (fired)
        { i = i + 1;
          delay(200);
          fired = false;
          //delay(1000);
          if  (/*fired &&*/ (CursorLine == 2)) zuruck = 1;

          else if (/*fired &&*/ (CursorLine == 0))
          {
            delay(200);
            fired = false;
            DisplayFirstLine = 0;
            print_menue(MenueLine2, 3);
            //lcd.setCursor(0,0);
            previousTime = millis();
            zuruck1 = 0;
            do {
              //delay(1000);
              if (turned)
              {
                if (up)
                  move_up(MenueLine2, 3, 3);
                else
                  move_down(MenueLine2, 3, 3);
                turned = false;
              }
              if (fired)
              { lcd.setCursor(0, 0);
                k = k + 1;
                delay(200);
                fired = false;
                if  (CursorLine == 2) zuruck1 = 1;

                else if (CursorLine == 1) {
                  weiss = 6;
                  blau = 0;
                  zuruck1 = 1;
                }

                else { /*if ((k>1))*/
                  blau = 6;
                  weiss = 0;
                  zuruck1 = 1;
                }

                zuruck = 1;
                delay(200);
                fired = false;
                //k = k+1;
              }
              currentTime = millis();
            } while (((currentTime - previousTime) <= 8000) && (zuruck1 == 0));
            //delay(3000);
            //lcd.setCursor(0,(CursorLine-DisplayFirstLine));
            k = 0;
          }
          //
          //previousTime = millis();
          /* else if (/*fired && (CursorLine == 1)){
             zuruck = 0;
             delay(1000);
             if (fired){
             zweiSpieler = 6;
             zuruck = 1;
            }*/
          else if (i > 1) {
            zweiSpieler = 6;
            zuruck = 1;
          }
          delay(200);
          fired = false;
          i = i + 1;
        }

        currentTime = millis();
      } while (((currentTime - previousTime) <= 10000) && (zuruck == 0)); //go back after no selection is made in ten seconds
      //zuruck = 0;
      //delay(3000);
      //lcd.setCursor(0,(CursorLine-DisplayFirstLine));
      i = 0;
      break;

    case 2: //select default ressource field and number distribution as shown in the settlers of catan quick start manual, opposed to the default random ressource and semi-random number distribution
      lcd.clear();
      DisplayFirstLine = 0;
      print_menue(MenueLine4, 3);
      previousTime = millis();
      zuruck3 = 0;
      lcd.setCursor(0, 0);
      CursorLine = 0;
      fired = false;
      do {
        //delay(1000);
        if (turned)
        {
          if (up)
            move_up(MenueLine4, 3, 3);
          else
            move_down(MenueLine4, 3, 3);
          turned = false;
        }
        if (fired)
        {
          delay(200);
          fired = false;
          if  (CursorLine == 2) {
            standard = 0;
            zuruck3 = 1;
          }
          else if (CursorLine == 1) {
            standard = 1;
            zuruck3 = 1;
          }

          //zuruck2 = 1;
        }
        currentTime = millis();
      } while (((currentTime - previousTime) <= 8000) && (zuruck3 == 0));


      break;
    case 3: //Lightshow selected
      lcd.clear();
      lcd.print("Licht ab!");
      lightshow(200);
      /* previousTime = millis();
         do {

        pot = analogRead(PINA);
        led = map(pot, 0, 1023, 0, 255);

        analogWrite(6, led);
        currentTime = millis();
        }while ((currentTime - previousTime) < 10000);*/
      break;

    case 4: //end game, board will require restart to continue
      lcd.clear();
      DisplayFirstLine = 0;
      print_menue(MenueLine3, 3);
      previousTime = millis();
      zuruck2 = 0;
      CursorLine = 0;
      do {
        //delay(1000);
        if (turned)
        {
          if (up)
            move_up(MenueLine3, 3, 3);
          else
            move_down(MenueLine3, 3, 3);
          turned = false;
        }
        if (fired)
        {
          delay(200);
          fired = false;
          if  (CursorLine == 2)
            zuruck2 = 1;
          else if (CursorLine == 1) {
            delay(5000);
            if (fired) {
              spielAus = 6;
              zuruck2 = 1;
            }
          }
          //zuruck2 = 1;
          delay(200);
          fired = false;
        }
        currentTime = millis();
      } while (((currentTime - previousTime) <= 8000) && (zuruck2 == 0));


      break;
  }
  //delay(1000);
  CursorLine = 0;
  DisplayFirstLine = 0;
  print_menue(MenueLine, 4);
  lcd.setCursor(0, 0);
}
