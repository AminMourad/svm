#include <FastLED.h>
#include <PCA95x5.h>
#include <TimerThree.h>
#include <Wire.h>
#include <string.h>
#include <stdlib.h>
#include <LiquidCrystal_I2C.h>
#include <TeensyID.h>


#define NUM 126


uint8_t serialnumber[4]; //create variable for serialnumber

int brett = 1;
int sp1 = 1;
int sp2 = 2;
int sp3 = 3;
int sp4 = 4;

extern unsigned long _heap_start;
extern unsigned long _heap_end;
extern char *__brkval;

//LCD initialization
LiquidCrystal_I2C lcd(lcdAdr, 20, 4);
LiquidCrystal_I2C lcd1(lcd1Adr, 40, 2);
LiquidCrystal_I2C lcd2(lcd2Adr, 40, 2);


//***** variables that show ressource count.******
int hopfen1 = 0, holz1 = 0, schaf1 = 0, lehm1 = 0, erz1 = 0, monopol1 = 0, erfindung1 = 0, ritter1 = 0;

int hopfen2 = 0, holz2 = 0, schaf2 = 0,  lehm2 = 0, erz2 = 0, monopol2 = 0, erfindung2 = 0, ritter2 = 0;

//initialize array for use in server query
int b[40];



int log_num = 1;
int farbe;
int spieler;    // gibt an wer am Zug ist
//1  3  5  7  9  11 13 15 17 19 21  23  25  27  29  31  33  35  37  39  41  43  45  47  49  51  53  55  57  59  61  63  65  67  69  71  73  75  77  79  81  83  85  87  89  91  93  95  97  99  101 103 105 107 109 111 113 115 117 119 121 123 125
bool haus[NUM] = {1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1, 1, 0, 1, 0, 0, 1, 0, 1, 0, 0, 1, 0, 1, 0, 0, 1, 0, 1, 0, 0, 1, 0, 1, 0, 1, 0, 0, 1, 0, 1, 0, 0, 1, 0, 1, 0, 0, 1, 0, 1, 0, 0, 1, 0, 1, 0, 0, 1, 0, 1, 0, 1, 0, 1, 0, 0, 1, 0, 1, 0, 0, 1, 0, 1, 0, 0, 1, 0, 1, 0, 0, 1, 0, 1, 1, 0, 0, 1, 0, 1, 0, 0, 1, 0, 1, 0, 0, 1, 0, 1, 0, 0, 1, 0, 1, 0, 0, 1, 0, 1, 0, 1, 0, 0, 1, 0, 1, 0, 0, 1, 0, 1, 0};
int magnet[NUM];
int imagnet[NUM];

CRGB leds[NUM];
bool red, green, blue;
int ired, igreen, iblue, j;
int gebaut[NUM];
bool bleds[NUM];
bool bpressed;

PCA9555 ioex0;
PCA9555 ioex1;

bool taster0[15];   //12 buttons at one of the resource displays and 2 at the rotary encoder
bool taster1[13];   //12 buttons at the other ressource display



void setup() {
  // put your setup code here, to run once:
  delay(10);
  welcome1();  //**** Welcome display 1 ****
  welcome2();  //**** Welcome display 2 ****

  Serial.begin(115200);
  Serial1.begin(115200);
  while (!Serial1) {}; //wait for connection to esp to establish
  delay(500);

  if (CrashReport) {            //print crash report if available
    Serial.print(CrashReport);
    Serial.println(" ");
  }

  Serial1.println("print(uart.setup(0, 115200, 8, uart.PARITY_NONE, uart.STOPBITS_1, 0))");
  while (Serial1.available() == 0) {};
  s1flush();

//put board number from serial number so both boards can run the same code
  teensySN(serialnumber);
  Serial.println(serialnumber[2]);
  if (serialnumber[2] >= teensySNin) {
    brett = 2;
    sp1 = 3;
    sp2 = 4;
    sp3 = 1;
    sp4 = 2;
  }

//run script to commence connection with ESP and the internet
  conn();
  Serial.println("VERBUNDEN");



  log_num = 1;    //reset log position
  spieler = 1;    //set player ones turn as default

  //Initialisierung IO Expander
  Wire.begin();
  ioex0.attach(Wire, ioex0Adr);
  ioex0.polarity(PCA95x5::Polarity::ORIGINAL_ALL);
  ioex0.direction(PCA95x5::Direction::IN_ALL);

  ioex1.attach(Wire, ioex1Adr);
  ioex1.polarity(PCA95x5::Polarity::ORIGINAL_ALL);
  ioex1.direction(PCA95x5::Direction::IN_ALL);


  //Initialisierung Analog-Inputs
  pinMode(A0, INPUT);
  pinMode(A1, INPUT);
  pinMode(A2, INPUT);
  pinMode(A3, INPUT);
  pinMode(A6, INPUT);
  pinMode(A7, INPUT);
  pinMode(A8, INPUT);
  pinMode(A9, INPUT);
  pinMode(A10, INPUT);
  pinMode(A11, INPUT);
  pinMode(A12, INPUT);
  pinMode(A13, INPUT);
  pinMode(A14, INPUT);
  pinMode(A15, INPUT);
  pinMode(A16, INPUT);
  pinMode(A17, INPUT);

  pinMode(s0, OUTPUT);
  pinMode(s1, OUTPUT);
  pinMode(s2, OUTPUT);

  bpressed = false;

  for (int i = 0; i < NUM; i++)
    gebaut[i] = 0;
  FastLED.addLeds<WS2812, LEDPin, GRB>(leds, NUM);
  for (int i = 0; i < NUM; i++)
    bleds[i] = false;
  sleds();
  lightshow(100);
  cled();
  //lightshow();

  Timer3.initialize(10000);
  Timer3.attachInterrupt(readt); // blinkLED to run every 0.01 seconds

  //calibrating magnets
  readmagnet();
  for (int i = 0; i < NUM; i++)
    imagnet[i] = magnet[i];

  //Custom-Character-Setup
  charsetup();

  delay(10);

  //start setuo
  setuplcd();
  delay(500);
  //start game
  startloop();
  delay (2000);

  Serial.println(log_num);

  //LCD-Clear after game start
  lcd1.clear();
  lcd2.clear();
  lcd1.setCursor(0, 0);
  lcd2.setCursor(0, 0);

  putLcd1();
  putLcd2();

  Serial.println("Start zuende!");

}

void loop() {

  readmagnet();
  calmagnets();

  logabfrage();

  //mled();
  //sleds();

  FastLED.show();



}
void logabfrage() {
  multiabfrage("logabfrage.php?b=" + String(brett) + "&nr=" + log_num); //get latest log entry, results stored in Array b
  if (b[0])
    Serial.println(b[0]);
  switch (b[0]) {
    case 0:
      runLcd1(); //  *** Standard Display1 in loop ***
      runLcd2(); //  *** Standard Display2 in loop ***
      return;
      break;
    case 1: //house built on other board, light led
      led(b[1], b[3], 1);
      break;
    case 2: //city built on other board, light led
      led(b[1], b[3], 2);
      break;
    case 3: //street built on other board, light led
      led(b[1], b[3], 1);
      break;
    case 4: // other board rolled the dice, show result
      writewuerfel(3, b[2]);
      upres();
      putLcd1();
      putLcd2();
      break;
    case 5: // other board stole a ressource from one of the players
      if (b[3] == sp1) {
        lcd1.clear();
        lcd1.setCursor(14, 0);
        lcd1.print(zahlZuSpieler(b[3]));
        lcd1.print(" hat dir");
        lcd1.setCursor(11, 1);
        lcd1.print("ein ");
        lcd1.print(zahlZuRes(b[4]));
        lcd1.print(" gestohlen!");
        upres();
        delay(2000);
        putLcd1();
      } else {
        lcd2.clear();
        lcd2.setCursor(14, 0);
        lcd2.print(zahlZuSpieler(b[3]));
        lcd2.print(" hat dir");
        lcd2.setCursor(11, 1);
        lcd2.print("ein ");
        lcd2.print(zahlZuRes(b[4]));
        lcd2.print(" gestohlen!");
        upres();
        delay(2000);
        putLcd2();
      }
      break;
    case 6: // other board placed robber
      lcd1.clear();
      lcd2.clear();
      lcd1.setCursor(1, 0);
      lcd1.print("Rauber wurde auf Feld ");
      lcd1.print(b[1]);
      lcd1.print(" gesetzt.");
      lcd2.setCursor(1, 0);
      lcd2.print("Rauber wurde auf Feld ");
      lcd2.print(b[1]);
      lcd2.print(" gesetzt.");
      delay(3000);
      runLcd1();
      runLcd2();
      putLcd1();
      putLcd2();
      break;
    case 7: // player on other board played knight card
      lcd1.clear();
      lcd2.clear();
      lcd1.setCursor(1, 0);
      lcd1.print(zahlZuSpieler(b[3]));
      lcd1.print(" hat einen Ritter ausgespielt.");
      lcd2.setCursor(1, 0);
      lcd2.print(zahlZuSpieler(b[3]));
      lcd2.print(" hat einen Ritter ausgespielt.");
      if (b[1] == 1) {
        lcd1.setCursor(1, 1);
        lcd1.print("und besitzt jetzt die Rittermacht ");
        lcd2.setCursor(1, 1);
        lcd2.print("und besitzt jetzt die Rittermacht ");
      }
      delay(3000);
      putLcd1();
      putLcd2();
      runLcd1();
      runLcd2();
      break;
    case 8: // player on other board played development card
      lcd1.clear();
      lcd2.clear();
      lcd1.setCursor(14, 0);
      lcd2.setCursor(14, 0);
      lcd1.print(zahlZuSpieler(b[3]));
      lcd2.print(zahlZuSpieler(b[3]));
      lcd1.print(" hat eine");
      lcd2.print(" hat eine");
      lcd1.setCursor(8, 1);
      lcd2.setCursor(8, 1);
      lcd1.print("Entwicklungskarte gekauft!");
      lcd2.print("Entwicklungskarte gekauft!");
      delay(3000);
      putLcd1();
      putLcd2();
      runLcd1();
      runLcd2();
      break;
    case 9: // someone won
      if (b[0] == sp1) {
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
      }
      else if (b[0] == sp2) {
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
      }
      else if (b[0] == sp3 || b[0] == sp4) {
        lcd1.clear();
        lcd2.clear();
        lcd1.setCursor(11, 0);
        lcd1.print(zahlZuSpieler(sp1));
        lcd1.print(" hat gewonnen!");
        lcd2.setCursor(11, 0);
        lcd2.print(zahlZuSpieler(sp1));
        lcd2.print(" hat gewonnen!");
        while (true);
      }
      while (true);
      break;
    case 10: // other player played monopoly
      lcd1.clear();
      lcd2.clear();
      lcd1.setCursor(14, 0);
      lcd2.setCursor(14, 0);
      lcd1.print(zahlZuSpieler(b[3]));
      lcd2.print(zahlZuSpieler(b[3]));
      lcd1.print(" hat alles");
      lcd2.print(" hat alles");
      lcd1.setCursor(8, 1);
      lcd2.setCursor(8, 1);
      lcd1.print(zahlZuRes(b[4]) + "geklaut!");
      lcd2.print(zahlZuRes(b[4]) + "geklaut!");
      upres();
      delay(3000);
      putLcd1();
      putLcd2();
      runLcd1();
      runLcd2();
      break;
    case 11: // turn of either player on this board
      spieler = b[3];
      if (spieler == sp1) {
        amZug1();
      } else if (spieler == sp2) {
        amZug2();
      }
      putLcd1();
      putLcd2();
      runLcd1();
      runLcd2();
      break;
    case 12: // turn of player on other board
      if (b[3] == sp3 || b[3] == sp4) {
        lcd1.clear();
        lcd2.clear();
        lcd2.setCursor(11, 0);
        lcd2.print(zahlZuSpieler(b[3]));
        lcd2.print(" ist am Zug.");
        lcd1.setCursor(11, 0);
        lcd1.print(zahlZuSpieler(b[3]));
        lcd1.print(" ist am Zug.");
        delay(3000);
        putLcd1();
        putLcd2();
        runLcd1();
        runLcd2();
      }
      break;
  }
  log_num++;
}


//function to update ressource values
void upres() {
  multiabfrage((String)"resabfrage.php?b=" + brett);
  if (b[0] == sp1) {
    holz1 = b[2];
    lehm1 = b[3];
    erz1 = b[4];
    hopfen1 = b[5];
    schaf1 = b[6];
    ritter1 = b[8];
    monopol1 = b[10];
    holz2 = b[15];
    lehm2 = b[16];
    erz2 = b[17];
    hopfen2 = b[18];
    schaf2 = b[19];
    ritter2 = b[21];
    monopol2 = b[23];
  }
  else {
    holz2 = b[2];
    lehm2 = b[3];
    erz2 = b[4];
    hopfen2 = b[5];
    schaf2 = b[6];
    ritter2 = b[8];
    monopol2 = b[10];
  }
}


void bauen(int s) {  // function to build whatever is placed on the board
  readmagnet();
  int maxVal = -1;
  int posi = -1;
  int mtype = 0;
  for (int i = 0; i < NUM; i++) {
    int magread = abs(imagnet[i] - magnet[i]);
    if (magread > maxVal) {
      maxVal = magread;
      posi = i;
      if (maxVal < 15) {  //nothing detected if hall sensor deviation from baseline (frequently reset) is less than 15. Value can be tweaked according to sensor setup
        mtype = 0;
      } else if (haus[i]) {
        if (gebaut[i] == 0) {
          mtype = 1;
        } else if (gebaut[i] == 1) {
          mtype = 2;
        } else if (gebaut[i] == 2) {
          mtype = 3;
        }
      } else {
        mtype = 4;
      }
    }
  }

  posi++;
  Serial.println(posi);
  Serial.println("Typ: " + String(mtype));
  switch (mtype) {
    case 0:
      helplcdclear(s);
      lcdText(s, 0, "Nichts erkannt!", 1);
      lcdText(s, 1, "Ok!", 2);
      delay(500);
      waitconfirm(s);
      helphelplcd(s);
      break;
    case 1: //Haus und noch frei
      switch (abfrage((String)"hausbau.php?hp=" + posi)) {
        case -1:
          helplcdclear(s);
          lcdText(s, 0, "Fehler -1", 1);
          lcdText(s, 1, "Ok!", 2);
          delay(500);
          waitconfirm(s);
          helphelplcd(s);
          break;
        case 0:
          helplcdclear(s);
          lcdText(s, 0, "Feld schon besetzt!", 1);
          lcdText(s, 1, "Ok!", 2);
          delay(500);
          waitconfirm(s);
          helphelplcd(s);
          break;
        case 1:
          helplcdclear(s);
          lcdText(s, 0, "Muss an Straße anliegen!", 1);
          lcdText(s, 1, "Ok!", 2);
          delay(500);
          waitconfirm(s);
          helphelplcd(s);
          break;
        case 2:
          helplcdclear(s);
          lcdText(s, 0, "Zu wenig Resourccen!", 1);
          lcdText(s, 1, "Ok!", 2);
          delay(500);
          waitconfirm(s);
          helphelplcd(s);
          break;
        case 3:
          helplcdclear(s);
          lcdText(s, 0, "Zu nahe an anderer Stadt/Siedlung", 1);
          lcdText(s, 1, "Ok!", 2);
          delay(500);
          waitconfirm(s);
          helphelplcd(s);
          break;
        case 5:
          helplcdclear(s);
          lcdText(s, 0, "Es wurden schon 5 Siedlungen gebaut!", 1);
          lcdText(s, 1, "Ok!", 2);
          delay(500);
          waitconfirm(s);
          helphelplcd(s);
          break;
        case 6:
          helplcdclear(s);
          gebaut[posi - 1] = 1;
          lcdText(s, 0, "Haus wurde gebaut!", 1);
          lcdText(s, 1, "Ok!", 2);
          upres();
          delay(500);
          waitconfirm(s);
          helphelplcd(s);
          break;
        default:
          break;
      }
      break;
    case 2:
      switch (abfrage((String)"stadtbau.php?hp=" + posi)) {
        case -1:
          helplcdclear(s);
          lcdText(s, 0, "Fehler -1", 1);
          lcdText(s, 1, "Ok!", 2);
          delay(500);
          waitconfirm(s);
          helphelplcd(s);
          break;
        case 2:
          helplcdclear(s);
          lcdText(s, 0, "Zu wenig Ressourcen!", 1);
          lcdText(s, 1, "Ok!", 2);
          delay(500);
          waitconfirm(s);
          helphelplcd(s);
          break;
        case 4:
          helplcdclear(s);
          lcdText(s, 0, "Kein Haus fuer Stadtbau vorhanden!", 1);
          lcdText(s, 1, "Ok!", 2);
          delay(500);
          waitconfirm(s);
          helphelplcd(s);
          break;
        case 5:
          helplcdclear(s);
          lcdText(s, 0, "Schon 4 Städte gebaut!", 1);
          lcdText(s, 1, "Ok!", 2);
          delay(500);
          waitconfirm(s);
          helphelplcd(s);
          break;
        case 6:
          helplcdclear(s);
          gebaut[posi - 1] = 2;
          lcdText(s, 0, "Stadt wurde gebaut!", 1);
          lcdText(s, 1, "Ok!", 2);
          upres();
          delay(500);
          waitconfirm(s);
          helphelplcd(s);
          break;
        default:
          break;
      }
      break;
    case 3:   //Stadt schon da, nichts mehr zu tun
      helplcdclear(s);
      lcdText(s, 0, "Hier steht schon eine Stadt!", 1);
      lcdText(s, 1, "Ok!", 2);
      delay(500);
      waitconfirm(s);
      helphelplcd(s);
      break;
    case 4:   //Strasse
      switch (abfrage((String)"strassenbau.php?sp=" + posi)) {
        case -1:
          helplcdclear(s);
          lcdText(s, 0, "Fehler -1", 1);
          lcdText(s, 1, "Ok!", 2);
          delay(500);
          waitconfirm(s);
          helphelplcd(s);
          break;
        case 0:
          helplcdclear(s);
          lcdText(s, 0, "Das Feld ist schon besetzt!", 1);
          lcdText(s, 1, "Ok!", 2);
          delay(500);
          waitconfirm(s);
          helphelplcd(s);
          break;
        case 1:
          helplcdclear(s);
          lcdText(s, 0, "Muss an Straße oder Haus/Stadt anliegen", 1);
          lcdText(s, 1, "Ok!", 2);
          delay(500);
          waitconfirm(s);
          helphelplcd(s);
          break;
        case 2:
          helplcdclear(s);
          lcdText(s, 0, "Zu wenig Ressourcen!", 1);
          lcdText(s, 1, "Ok!", 2);
          delay(500);
          waitconfirm(s);
          helphelplcd(s);
          break;
        case 6:
          helplcdclear(s);
          lcdText(s, 0, "Strasse wurde gebaut!", 1);
          lcdText(s, 1, "Ok!", 2);
          upres();
          delay(500);
          waitconfirm(s);
          helphelplcd(s);
          break;
        default:
          break;
      }
      break;
  }
}

int startbauen(int s) { //function to handle building in the beginning
  int hp = 0;
  int sp = 0;
  Serial.println("vor");
  readmagnet();
  Serial.println("nach");

  //prfr();


  int firstMax = -1;
  int secondMax = -1;
  int firstMaxIndex = -1;
  int secondMaxIndex = -1;

  for (int i = 0; i < NUM; i++) {
    int magread = abs(imagnet[i] - magnet[i]);
    Serial.println(String(i) + "." + String(magread));
    if (magread > firstMax) {
      secondMax = firstMax;
      secondMaxIndex = firstMaxIndex;
      firstMax = magread;
      firstMaxIndex = i;
    } else if (magread > secondMax && magread != firstMax) {
      secondMax = magread;
      secondMaxIndex = i;
    }

    if (haus[i]) {
      if (i == firstMaxIndex || i == secondMaxIndex) {
        if (gebaut[i] == 0) {
          hp = i + 1;
        }
      }
    } else {
      if (i == firstMaxIndex || i == secondMaxIndex) {
        sp = i + 1;
      }
    }
  }

  if ((firstMax < 10) || (secondMax < 10)) {
    lcdText(s, 0, "Keine Platzierung erkannt!", 1);
    lcdText(s, 1, "Ok!", 2);
    delay(500);
    waitconfirm(s);
    return (0);
  }

  //print positions of whatever is detected in console for debugging
  Serial.println("Haus:" + String(hp));
  Serial.println("Strasse:" + String(sp));


  lcd1.clear();
  lcd2.clear();
  int sb = abfrage((String)"startbau.php?hp=" + hp + "&sp=" + sp);
  Serial.println("sb:" + String(sb));
  switch (sb) {
    case -1:
      lcdText(s, 0, "Falsche Eingabe.", 1);
      lcdText(s, 1, "Ok!", 2);
      delay(500);
      waitconfirm(s);
      return (0);
      break;
    case 1:
      lcdText(s, 0, "Feld besetzt", 1);
      lcdText(s, 1, "Ok!", 2);
      delay(500);
      waitconfirm(s);
      return (0);
      break;
    case 2:
      lcdText(s, 0, "Strasse nich an Haus anliegend.", 1);
      lcdText(s, 1, "Ok!", 2);
      delay(500);
      waitconfirm(s);
      return (0);
      break;
    case 3:
      lcdText(s, 0, "Haus zu nah an Gegnern.", 1);
      lcdText(s, 1, "Ok!", 2);
      delay(500);
      waitconfirm(s);
      return (0);
      break;
    case 4:
      gebaut[hp - 1] = 1;
      return (4);
      break;
    case 6:
      gebaut[hp - 1] = 1;
      return (6);
      break;
    default:
      lcdText(s, 0, "Abfragefehler!", 1);
      lcdText(s, 1, "Bau annehmen?", 1);
      lcdText(s, 1, "Ok!", 2);
      lcdText(s, 1, "Nein!", 0);
      delay(500);
      switch (s) {
        case 1:
          while (!taster0[2] && !taster0[12]) {
            delay(1);
          }
          if (taster0[2]) {
            return (0);
          } else {
            return (6);
          }
          break;
        case 2:
          while (!taster1[2] && !taster1[12]) {
            delay(1);
          }
          if (taster1[2]) {
            return (0);
          } else {
            return (6);
          }
          break;
      }

      break;
  }

}

//deprecated and currently unused, formelrly used for diefferent building implementation to set where something was pleced
void mled() {
  for (int i = 0; i < NUM; i++) {
    if (abs((imagnet[i] - magnet[i])) > 40) {
      bleds[i] = true;
    }
    else
      bleds[i] = false;
  }
}
