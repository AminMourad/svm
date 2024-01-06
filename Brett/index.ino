/********Board Config Changes********/

//LED-Control-Pin
#define LEDPin 9

//Analog Multiplexer Pins
#define s0 35 
#define s1 36
#define s2 37

//LCD display I2C adresses
#define lcdAdr 0x24   //setup LCD
#define lcd1Adr 0x25
#define lcd2Adr 0x26

//IO extender I2c Adresses
#define ioex0Adr 0x20
#define ioex1Adr 0x27

//Value inbetween both teensies serial numbers for setting board number without running different code
#define teensySNin 70


/********Server Config Changes********/
//Server adress with complete URL path short of the php file, i.e. if the index.php's adress is http://example.com/svm/index.php you put example.com/svm/. Has to allow http without encryption
String Serveradress = "replacewithyours.com/svm/"




