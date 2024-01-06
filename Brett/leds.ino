//function to light only the bottom leds of a ressource card to show ressource distribution in the beginning
void feldres(int feld, int res) {
  switch (res) {
    case 2:   //red brick
      ired = 255;
      igreen = 0;
      iblue = 0;
      break;
    case 1:   //dark green wood
      ired = 1;
      igreen = 50;
      iblue = 32;
      break;
    case 5:   //light green wool
      ired = 40;
      igreen = 200;
      iblue = 30;
      break;
    case 3:   // white ore
      ired = 150;
      igreen = 150;
      iblue = 150;
      break;
    case 4:   //yellow crops
      ired = 180;
      igreen = 180;
      iblue = 0;
      break;
    default:
      break;
  }
  switch (feld) { // leds according to selected ressource card
    case 1:          
      leds[27] = CRGB(ired, igreen, iblue);
      leds[31] = CRGB(ired, igreen, iblue);
      leds[30] = CRGB(ired, igreen, iblue);
      leds[29] = CRGB(ired, igreen, iblue);
      leds[28] = CRGB(ired, igreen, iblue);
      break;
    case 2:
      leds[22] = CRGB(ired, igreen, iblue);
      leds[23] = CRGB(ired, igreen, iblue);
      leds[24] = CRGB(ired, igreen, iblue);
      leds[25] = CRGB(ired, igreen, iblue);
      leds[26] = CRGB(ired, igreen, iblue);
      break;
    case 3:
      leds[17] = CRGB(ired, igreen, iblue);
      leds[21] = CRGB(ired, igreen, iblue);
      leds[18] = CRGB(ired, igreen, iblue);
      leds[19] = CRGB(ired, igreen, iblue);
      leds[20] = CRGB(ired, igreen, iblue);

      break;
    case 4:
      leds[52] = CRGB(ired, igreen, iblue);
      leds[53] = CRGB(ired, igreen, iblue);
      leds[54] = CRGB(ired, igreen, iblue);
      leds[55] = CRGB(ired, igreen, iblue);
      leds[56] = CRGB(ired, igreen, iblue);

      break;
    case 5:
      leds[63] = CRGB(ired, igreen, iblue);
      leds[64] = CRGB(ired, igreen, iblue);
      leds[65] = CRGB(ired, igreen, iblue);
      leds[66] = CRGB(ired, igreen, iblue);
      leds[67] = CRGB(ired, igreen, iblue);

      break;
    case 6:
      leds[102] = CRGB(ired, igreen, iblue);
      leds[103] = CRGB(ired, igreen, iblue);
      leds[104] = CRGB(ired, igreen, iblue);
      leds[105] = CRGB(ired, igreen, iblue);
      leds[106] = CRGB(ired, igreen, iblue);
      break;
    case 7:
      leds[111] = CRGB(ired, igreen, iblue);
      leds[112] = CRGB(ired, igreen, iblue);
      leds[113] = CRGB(ired, igreen, iblue);
      leds[114] = CRGB(ired, igreen, iblue);
      leds[115] = CRGB(ired, igreen, iblue);
      break;
    case 8:
      leds[116] = CRGB(ired, igreen, iblue);
      leds[117] = CRGB(ired, igreen, iblue);
      leds[118] = CRGB(ired, igreen, iblue);
      leds[119] = CRGB(ired, igreen, iblue);
      leds[120] = CRGB(ired, igreen, iblue);
      break;
    case 9:
      leds[121] = CRGB(ired, igreen, iblue);
      leds[122] = CRGB(ired, igreen, iblue);
      leds[123] = CRGB(ired, igreen, iblue);
      leds[124] = CRGB(ired, igreen, iblue);
      leds[125] = CRGB(ired, igreen, iblue);
      break;
    case 10:
      leds[87] = CRGB(ired, igreen, iblue);
      leds[88] = CRGB(ired, igreen, iblue);
      leds[89] = CRGB(ired, igreen, iblue);
      leds[90] = CRGB(ired, igreen, iblue);
      leds[91] = CRGB(ired, igreen, iblue);
      break;
    case 11:
      leds[34] = CRGB(ired, igreen, iblue);
      leds[83] = CRGB(ired, igreen, iblue);
      leds[84] = CRGB(ired, igreen, iblue);
      leds[85] = CRGB(ired, igreen, iblue);
      leds[86] = CRGB(ired, igreen, iblue);
      break;
    case 12:
      leds[37] = CRGB(ired, igreen, iblue);
      leds[38] = CRGB(ired, igreen, iblue);
      leds[39] = CRGB(ired, igreen, iblue);
      leds[40] = CRGB(ired, igreen, iblue);
      leds[41] = CRGB(ired, igreen, iblue);
      break;
    case 13:

      leds[42] = CRGB(ired, igreen, iblue);
      leds[43] = CRGB(ired, igreen, iblue);
      leds[44] = CRGB(ired, igreen, iblue);
      leds[45] = CRGB(ired, igreen, iblue);
      leds[46] = CRGB(ired, igreen, iblue);
      break;
    case 14:

      leds[47] = CRGB(ired, igreen, iblue);
      leds[48] = CRGB(ired, igreen, iblue);
      leds[49] = CRGB(ired, igreen, iblue);
      leds[50] = CRGB(ired, igreen, iblue);
      leds[51] = CRGB(ired, igreen, iblue);
      break;
    case 15:
      leds[68] = CRGB(ired, igreen, iblue);
      leds[69] = CRGB(ired, igreen, iblue);
      leds[70] = CRGB(ired, igreen, iblue);
      leds[71] = CRGB(ired, igreen, iblue);
      leds[72] = CRGB(ired, igreen, iblue);
      break;
    case 16:
      leds[97] = CRGB(ired, igreen, iblue);
      leds[98] = CRGB(ired, igreen, iblue);
      leds[99] = CRGB(ired, igreen, iblue);
      leds[100] = CRGB(ired, igreen, iblue);
      leds[101] = CRGB(ired, igreen, iblue);
      break;
    case 17:

      leds[92] = CRGB(ired, igreen, iblue);
      leds[93] = CRGB(ired, igreen, iblue);
      leds[94] = CRGB(ired, igreen, iblue);
      leds[95] = CRGB(ired, igreen, iblue);
      leds[96] = CRGB(ired, igreen, iblue);
      break;
    case 18:
      leds[78] = CRGB(ired, igreen, iblue);
      leds[79] = CRGB(ired, igreen, iblue);
      leds[80] = CRGB(ired, igreen, iblue);
      leds[81] = CRGB(ired, igreen, iblue);
      leds[82] = CRGB(ired, igreen, iblue);
      break;
    case 19:
      leds[73] = CRGB(ired, igreen, iblue);
      leds[74] = CRGB(ired, igreen, iblue);
      leds[75] = CRGB(ired, igreen, iblue);
      leds[76] = CRGB(ired, igreen, iblue);
      leds[77] = CRGB(ired, igreen, iblue);
      break;
    default:
      break;
  }
  FastLED.show();
}

//function to light all leds around a ressource card
void rled(int feld, int res, int hel) {   //feld->shich ressource field    res->which ressource hel->brightness
  switch (res) {
    case 1:   //white
      red = true;
      green = true;
      blue = true;
      break;
    case 2:   //blue
      red = false;
      green = false;
      blue = true;
      break;
    case 3: // red
      red = true;
      green = false;
      blue = false;
      break;
    case 4: //green
      red = true;
      green = true;
      blue = false;
      break;
    case 5: //dark green
      red = false;
      green = true;
      blue = true;
      break;
    default:
      break;
  }
  int x = hel;
  switch (feld) {
    case 1:   //feld 1
      leds[0] = CRGB(x * red, x * green, x * blue);
      leds[1] = CRGB(x * red, x * green, x * blue);
      leds[2] = CRGB(x * red, x * green, x * blue);
      leds[3] = CRGB(x * red, x * green, x * blue);
      leds[4] = CRGB(x * red, x * green, x * blue);
      leds[26] = CRGB(x * red, x * green, x * blue);
      leds[25] = CRGB(x * red, x * green, x * blue);
      //
      leds[27] = CRGB(x * red, x * green, x * blue);
      leds[28] = CRGB(x * red, x * green, x * blue);
      leds[29] = CRGB(x * red, x * green, x * blue);
      leds[30] = CRGB(x * red, x * green, x * blue);
      leds[31] = CRGB(x * red, x * green, x * blue);
      break;
    case 2:
      leds[4] = CRGB(x * red, x * green, x * blue);
      leds[5] = CRGB(x * red, x * green, x * blue);
      leds[6] = CRGB(x * red, x * green, x * blue);
      leds[7] = CRGB(x * red, x * green, x * blue);
      leds[8] = CRGB(x * red, x * green, x * blue);
      leds[21] = CRGB(x * red, x * green, x * blue);
      leds[20] = CRGB(x * red, x * green, x * blue);

      leds[22] = CRGB(x * red, x * green, x * blue);
      leds[23] = CRGB(x * red, x * green, x * blue);
      leds[24] = CRGB(x * red, x * green, x * blue);
      leds[25] = CRGB(x * red, x * green, x * blue);
      leds[26] = CRGB(x * red, x * green, x * blue);
      break;
    case 3:
      leds[8] = CRGB(x * red, x * green, x * blue);
      leds[9] = CRGB(x * red, x * green, x * blue);
      leds[10] = CRGB(x * red, x * green, x * blue);
      leds[11] = CRGB(x * red, x * green, x * blue);
      leds[12] = CRGB(x * red, x * green, x * blue);
      leds[16] = CRGB(x * red, x * green, x * blue);
      leds[15] = CRGB(x * red, x * green, x * blue);

      leds[17] = CRGB(x * red, x * green, x * blue);
      leds[21] = CRGB(x * red, x * green, x * blue);
      leds[18] = CRGB(x * red, x * green, x * blue);
      leds[19] = CRGB(x * red, x * green, x * blue);
      leds[20] = CRGB(x * red, x * green, x * blue);
      break;
    case 4:
      leds[15] = CRGB(x * red, x * green, x * blue);
      leds[14] = CRGB(x * red, x * green, x * blue);
      leds[13] = CRGB(x * red, x * green, x * blue);
      leds[17] = CRGB(x * red, x * green, x * blue);
      leds[18] = CRGB(x * red, x * green, x * blue);
      leds[57] = CRGB(x * red, x * green, x * blue);
      leds[58] = CRGB(x * red, x * green, x * blue);

      leds[52] = CRGB(x * red, x * green, x * blue);
      leds[53] = CRGB(x * red, x * green, x * blue);
      leds[54] = CRGB(x * red, x * green, x * blue);
      leds[55] = CRGB(x * red, x * green, x * blue);
      leds[56] = CRGB(x * red, x * green, x * blue);
      break;
    case 5:
      leds[55] = CRGB(x * red, x * green, x * blue);
      leds[56] = CRGB(x * red, x * green, x * blue);
      leds[57] = CRGB(x * red, x * green, x * blue);
      leds[59] = CRGB(x * red, x * green, x * blue);
      leds[60] = CRGB(x * red, x * green, x * blue);
      leds[61] = CRGB(x * red, x * green, x * blue);
      leds[62] = CRGB(x * red, x * green, x * blue);

      leds[63] = CRGB(x * red, x * green, x * blue);
      leds[64] = CRGB(x * red, x * green, x * blue);
      leds[65] = CRGB(x * red, x * green, x * blue);
      leds[66] = CRGB(x * red, x * green, x * blue);
      leds[67] = CRGB(x * red, x * green, x * blue);
      break;
    case 6:
      leds[64] = CRGB(x * red, x * green, x * blue);
      leds[65] = CRGB(x * red, x * green, x * blue);
      leds[66] = CRGB(x * red, x * green, x * blue);
      leds[68] = CRGB(x * red, x * green, x * blue);
      leds[69] = CRGB(x * red, x * green, x * blue);
      leds[107] = CRGB(x * red, x * green, x * blue);
      leds[108] = CRGB(x * red, x * green, x * blue);

      leds[102] = CRGB(x * red, x * green, x * blue);
      leds[103] = CRGB(x * red, x * green, x * blue);
      leds[104] = CRGB(x * red, x * green, x * blue);
      leds[105] = CRGB(x * red, x * green, x * blue);
      leds[106] = CRGB(x * red, x * green, x * blue);
      break;
    case 7:
      leds[102] = CRGB(x * red, x * green, x * blue);
      leds[105] = CRGB(x * red, x * green, x * blue);
      leds[104] = CRGB(x * red, x * green, x * blue);
      leds[101] = CRGB(x * red, x * green, x * blue);
      leds[100] = CRGB(x * red, x * green, x * blue);
      leds[109] = CRGB(x * red, x * green, x * blue);
      leds[110] = CRGB(x * red, x * green, x * blue);

      leds[111] = CRGB(x * red, x * green, x * blue);
      leds[112] = CRGB(x * red, x * green, x * blue);
      leds[113] = CRGB(x * red, x * green, x * blue);
      leds[114] = CRGB(x * red, x * green, x * blue);
      leds[115] = CRGB(x * red, x * green, x * blue);
      break;
    case 8:
      leds[95] = CRGB(x * red, x * green, x * blue);
      leds[100] = CRGB(x * red, x * green, x * blue);
      leds[96] = CRGB(x * red, x * green, x * blue);
      leds[97] = CRGB(x * red, x * green, x * blue);
      leds[99] = CRGB(x * red, x * green, x * blue);
      leds[114] = CRGB(x * red, x * green, x * blue);
      leds[115] = CRGB(x * red, x * green, x * blue);

      leds[116] = CRGB(x * red, x * green, x * blue);
      leds[117] = CRGB(x * red, x * green, x * blue);
      leds[118] = CRGB(x * red, x * green, x * blue);
      leds[119] = CRGB(x * red, x * green, x * blue);
      leds[120] = CRGB(x * red, x * green, x * blue);
      break;
    case 9:
      leds[119] = CRGB(x * red, x * green, x * blue);
      leds[120] = CRGB(x * red, x * green, x * blue);
      leds[90] = CRGB(x * red, x * green, x * blue);
      leds[91] = CRGB(x * red, x * green, x * blue);
      leds[92] = CRGB(x * red, x * green, x * blue);
      leds[94] = CRGB(x * red, x * green, x * blue);
      leds[95] = CRGB(x * red, x * green, x * blue);

      leds[121] = CRGB(x * red, x * green, x * blue);
      leds[122] = CRGB(x * red, x * green, x * blue);
      leds[123] = CRGB(x * red, x * green, x * blue);
      leds[124] = CRGB(x * red, x * green, x * blue);
      leds[125] = CRGB(x * red, x * green, x * blue);
      break;
    case 10:
      leds[87] = CRGB(x * red, x * green, x * blue);
      leds[88] = CRGB(x * red, x * green, x * blue);
      leds[89] = CRGB(x * red, x * green, x * blue);
      leds[90] = CRGB(x * red, x * green, x * blue);
      leds[91] = CRGB(x * red, x * green, x * blue);

      leds[92] = CRGB(x * red, x * green, x * blue);
      leds[93] = CRGB(x * red, x * green, x * blue);
      leds[79] = CRGB(x * red, x * green, x * blue);
      leds[80] = CRGB(x * red, x * green, x * blue);
      leds[81] = CRGB(x * red, x * green, x * blue);
      leds[83] = CRGB(x * red, x * green, x * blue);
      leds[84] = CRGB(x * red, x * green, x * blue);
      break;
    case 11:
      leds[35] = CRGB(x * red, x * green, x * blue);
      leds[36] = CRGB(x * red, x * green, x * blue);
      leds[37] = CRGB(x * red, x * green, x * blue);
      leds[40] = CRGB(x * red, x * green, x * blue);
      leds[39] = CRGB(x * red, x * green, x * blue);
      leds[81] = CRGB(x * red, x * green, x * blue);
      leds[82] = CRGB(x * red, x * green, x * blue);

      leds[34] = CRGB(x * red, x * green, x * blue);
      leds[83] = CRGB(x * red, x * green, x * blue);
      leds[84] = CRGB(x * red, x * green, x * blue);
      leds[85] = CRGB(x * red, x * green, x * blue);
      leds[86] = CRGB(x * red, x * green, x * blue);
      break;
    case 12:
      leds[42] = CRGB(x * red, x * green, x * blue);
      leds[43] = CRGB(x * red, x * green, x * blue);
      leds[28] = CRGB(x * red, x * green, x * blue);
      leds[29] = CRGB(x * red, x * green, x * blue);
      leds[30] = CRGB(x * red, x * green, x * blue);
      leds[32] = CRGB(x * red, x * green, x * blue);
      leds[33] = CRGB(x * red, x * green, x * blue);

      leds[37] = CRGB(x * red, x * green, x * blue);
      leds[38] = CRGB(x * red, x * green, x * blue);
      leds[39] = CRGB(x * red, x * green, x * blue);
      leds[40] = CRGB(x * red, x * green, x * blue);
      leds[41] = CRGB(x * red, x * green, x * blue);
      break;
    case 13:
      leds[23] = CRGB(x * red, x * green, x * blue);
      leds[24] = CRGB(x * red, x * green, x * blue);
      leds[25] = CRGB(x * red, x * green, x * blue);
      leds[27] = CRGB(x * red, x * green, x * blue);
      leds[28] = CRGB(x * red, x * green, x * blue);
      leds[47] = CRGB(x * red, x * green, x * blue);
      leds[48] = CRGB(x * red, x * green, x * blue);

      leds[42] = CRGB(x * red, x * green, x * blue);
      leds[43] = CRGB(x * red, x * green, x * blue);
      leds[44] = CRGB(x * red, x * green, x * blue);
      leds[45] = CRGB(x * red, x * green, x * blue);
      leds[46] = CRGB(x * red, x * green, x * blue);
      break;
    case 14:
      leds[18] = CRGB(x * red, x * green, x * blue);
      leds[19] = CRGB(x * red, x * green, x * blue);
      leds[20] = CRGB(x * red, x * green, x * blue);
      leds[22] = CRGB(x * red, x * green, x * blue);
      leds[23] = CRGB(x * red, x * green, x * blue);
      leds[52] = CRGB(x * red, x * green, x * blue);
      leds[53] = CRGB(x * red, x * green, x * blue);

      leds[47] = CRGB(x * red, x * green, x * blue);
      leds[48] = CRGB(x * red, x * green, x * blue);
      leds[49] = CRGB(x * red, x * green, x * blue);
      leds[50] = CRGB(x * red, x * green, x * blue);
      leds[51] = CRGB(x * red, x * green, x * blue);
      break;
    case 15:
      leds[50] = CRGB(x * red, x * green, x * blue);
      leds[51] = CRGB(x * red, x * green, x * blue);
      leds[52] = CRGB(x * red, x * green, x * blue);
      leds[54] = CRGB(x * red, x * green, x * blue);
      leds[55] = CRGB(x * red, x * green, x * blue);
      leds[66] = CRGB(x * red, x * green, x * blue);
      leds[67] = CRGB(x * red, x * green, x * blue);

      leds[68] = CRGB(x * red, x * green, x * blue);
      leds[69] = CRGB(x * red, x * green, x * blue);
      leds[70] = CRGB(x * red, x * green, x * blue);
      leds[71] = CRGB(x * red, x * green, x * blue);
      leds[72] = CRGB(x * red, x * green, x * blue);
      break;
    case 16:
      leds[69] = CRGB(x * red, x * green, x * blue);
      leds[70] = CRGB(x * red, x * green, x * blue);
      leds[71] = CRGB(x * red, x * green, x * blue);
      leds[73] = CRGB(x * red, x * green, x * blue);
      leds[74] = CRGB(x * red, x * green, x * blue);
      leds[102] = CRGB(x * red, x * green, x * blue);
      leds[103] = CRGB(x * red, x * green, x * blue);

      leds[97] = CRGB(x * red, x * green, x * blue);
      leds[98] = CRGB(x * red, x * green, x * blue);
      leds[99] = CRGB(x * red, x * green, x * blue);
      leds[100] = CRGB(x * red, x * green, x * blue);
      leds[101] = CRGB(x * red, x * green, x * blue);
      break;
    case 17:
      leds[74] = CRGB(x * red, x * green, x * blue);
      leds[75] = CRGB(x * red, x * green, x * blue);
      leds[76] = CRGB(x * red, x * green, x * blue);
      leds[78] = CRGB(x * red, x * green, x * blue);
      leds[79] = CRGB(x * red, x * green, x * blue);
      leds[97] = CRGB(x * red, x * green, x * blue);
      leds[98] = CRGB(x * red, x * green, x * blue);

      leds[92] = CRGB(x * red, x * green, x * blue);
      leds[93] = CRGB(x * red, x * green, x * blue);
      leds[94] = CRGB(x * red, x * green, x * blue);
      leds[95] = CRGB(x * red, x * green, x * blue);
      leds[96] = CRGB(x * red, x * green, x * blue);
      break;
    case 18:
      leds[40] = CRGB(x * red, x * green, x * blue);
      leds[41] = CRGB(x * red, x * green, x * blue);
      leds[42] = CRGB(x * red, x * green, x * blue);
      leds[44] = CRGB(x * red, x * green, x * blue);
      leds[45] = CRGB(x * red, x * green, x * blue);
      leds[76] = CRGB(x * red, x * green, x * blue);
      leds[77] = CRGB(x * red, x * green, x * blue);

      leds[78] = CRGB(x * red, x * green, x * blue);
      leds[79] = CRGB(x * red, x * green, x * blue);
      leds[80] = CRGB(x * red, x * green, x * blue);
      leds[81] = CRGB(x * red, x * green, x * blue);
      leds[82] = CRGB(x * red, x * green, x * blue);
      break;
    case 19:
      leds[45] = CRGB(x * red, x * green, x * blue);
      leds[46] = CRGB(x * red, x * green, x * blue);
      leds[47] = CRGB(x * red, x * green, x * blue);
      leds[49] = CRGB(x * red, x * green, x * blue);
      leds[50] = CRGB(x * red, x * green, x * blue);
      leds[71] = CRGB(x * red, x * green, x * blue);
      leds[72] = CRGB(x * red, x * green, x * blue);

      leds[73] = CRGB(x * red, x * green, x * blue);
      leds[74] = CRGB(x * red, x * green, x * blue);
      leds[75] = CRGB(x * red, x * green, x * blue);
      leds[76] = CRGB(x * red, x * green, x * blue);
      leds[77] = CRGB(x * red, x * green, x * blue);
      break;
    default:
      break;
  }

  FastLED.show();

}

//lightshow to show at startup
void lightshow(int fast) { //variable to select speed of animation
  if(!fast){
    fast=100;
    }
  rled(1, 1, 127);
  delay(fast);
  rled(2, 2, 255);
  delay(fast);
  rled(3, 3, 127);
  delay(fast);
  rled(4, 4, 255);
  delay(fast);
  rled(5, 5, 127);
  delay(fast);
  rled(6, 1, 255);
  delay(fast);
  rled(7, 2, 127);
  delay(fast);
  rled(8, 3, 255);
  delay(fast);
  rled(9, 4, 127);
  delay(fast);
  rled(10, 5, 255);
  delay(fast);
  rled(11, 1, 127);
  delay(fast);
  rled(12, 2, 255);
  delay(fast);
  rled(13, 3, 127);
  delay(fast);
  rled(14, 4, 255);
  delay(fast);
  rled(15, 5, 127);
  delay(fast);
  rled(16, 1, 255);
  delay(fast);
  rled(17, 2, 127);
  delay(fast);
  rled(18, 3, 255);
  delay(fast);
  rled(19, 4, 127);
  delay(fast);
  cled();

}

//light up specific LED when other board built something
void led(int pos, int player, int city) { //pos ->which LED      player->which color/player    city->differentiate between settlement or street (1, brighter) and city (2, darker)
  switch (player) {
    case 1:   //weiß
      red = true;
      green = true;
      blue = true;
      break;
    case 2:   //Blau
      red = false;
      green = false;
      blue = true;
      break;
    case 3:   //rot
      red = true;
      green = false;
      blue = false;
      break;
    case 4:   //gelb
      red = true;
      green = true;
      blue = false;
      break;
    default:
      break;
  }
  if (city == 2)
    leds[pos - 1] = CRGB(20 * red, 20 * green, 20 * blue);
  else
    leds[pos - 1] = CRGB(255 * red, 255 * green, 255 * blue);
  
  FastLED.show();
  delay(1);
  FastLED.show();
}

//clear all leds, somtimes has to be called twice to clear all LEDs reliably
void cled() {
  for (int i = 0; i < NUM; i++)
  {
    leds[i] = CRGB(0, 0, 0);
  }
  FastLED.show();
  delay(1);
  FastLED.show();
}

// deprecated, at the one place it's called it will clear the leds unless the startup sequence failed somehow
void sleds() {
  for (int i = 0; i < NUM; i++) {
    if (bleds[i])
      leds[i] = CRGB(126, 126, 126);
  }
  for (int i = 0; i < NUM; i++) {
    if (!bleds[i])
      leds[i] = CRGB(0, 0, 0);
  }
  FastLED.show();
}
