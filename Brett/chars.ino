//custom char setup

byte unterstrich[8] = {
  0b00000,
  0b00000,
  0b00000,
  0b00000,
  0b00000,
  0b00000,
  0b00000,
  0b11111
};
byte oberstrich[8] = {
  0b11111,
  0b00000,
  0b00000,
  0b00000,
  0b00000,
  0b00000,
  0b00000,
  0b00000
};
byte linksstrich[8] = {
  0b10000,
  0b10000,
  0b10000,
  0b10000,
  0b10000,
  0b10000,
  0b10000,
  0b10000
};
byte rechtsstrich[8] = {
  0b00001,
  0b00001,
  0b00001,
  0b00001,
  0b00001,
  0b00001,
  0b00001,
  0b00001
};
byte nullstrich[8] = {
  0b01110,
  0b10001,
  0b10001,
  0b10001,
  0b10001,
  0b10001,
  0b01110,
  0b11111
};
byte einsstrich[8] = {
  0b00100,
  0b01100,
  0b00100,
  0b00100,
  0b00100,
  0b00100,
  0b01110,
  0b11111
};

byte pfeilrunter[8] = {
  0b00000,
  0b00100,
  0b00100,
  0b00100,
  0b00100,
  0b10101,
  0b01110,
  0b00100
};

void charsetup(){
  lcd1.createChar(0, unterstrich);
  lcd2.createChar(0, unterstrich);
  lcd1.createChar(1, oberstrich);
  lcd2.createChar(1, oberstrich);
  lcd1.createChar(2, linksstrich);
  lcd2.createChar(2, linksstrich);
  lcd1.createChar(3, rechtsstrich);
  lcd2.createChar(3, rechtsstrich);
  lcd1.createChar(4, nullstrich);
  lcd2.createChar(4, nullstrich);
  lcd1.createChar(5, einsstrich);
  lcd2.createChar(5, einsstrich);
  lcd1.createChar(6, pfeilrunter);
  lcd2.createChar(6, pfeilrunter);
}
