//several connection functions which work via the serial connection to a connected ESP8266 with 'end user setup', 'http', 'wifi' and 'net' modules installed. Firmware can be built at https://nodemcu-build.com/ and has to be flashed manually

String connectcheck = "net.dns.resolve(\"www.google.com\", function(sk, ip) if (ip == nil) then print(\"3\")  else print(\"4\") end  end)";

// flush serial buffer of remaining characters
void s1flush()
{
  Serial1.flush();
  while (Serial1.available())
    Serial1.read();
}

//connect to internet
void conn() {
  s1flush();
  Serial1.println("wifi.setmode(wifi.STATION)");
  Serial1.flush();
  Serial1.println("wifi.sta.connect()");
  delay(3000);

  s1flush();
  Serial1.println(connectcheck); //check if connection is established by resolving google.com, return 3 for no, 4 for yes
  while (Serial1.available() == 0) {}; //wait for feedback from ESP
  int h = Serial1.parseInt();
  while (h == 0) {
    h = Serial1.parseInt();
    delay(100);
  }
  switch (h) {
    case 3:

      s1flush();
      Serial1.println("enduser_setup.start(\"SVMSetup" + String(brett) + "\", function() print(\"2\") end)"); //if no connection is established by default by auto connecting to last network, start setup by creating network which allows seleccting a network with any end device
      while (Serial1.parseInt() != 2) { //wait setup is completed and connection is established
        Serial1.read();
        delay(100);
      }
      s1flush();
      break;
    case 4: //connection is established
      s1flush();
      break;
    default:
      Serial.println("fatal error: ");
      Serial.print(h);
      break;

  }
}

//function to query the server when multiple return values are expected
void multiabfrage(String anfrage) {
  memset(b, 0, sizeof(b));
  s1flush();
  Serial1.println("http.get(\"http://" + Serveradress + anfrage + "\", nil, function(code, data) if (code < 0) then print(\"9.\") else print(data) end end)");
  Serial1.flush();
  int y = 0;
  String re = "";
  while (!Serial1.available()) {}; // Wait for characters
  //clear input until start sign .
  Serial1.readStringUntil('.');
  while (1) {
    //save value until break ,
    re = Serial1.readStringUntil(',');
    //end function when read value is .
    if (re[0] == '.') break;
    //re[re.length() - 1] = '\0';
    b[y] = re.toInt();
    y++;
  }
  s1flush();
}

//function to query the server when a single return value is expected
int abfrage (String anfrage) {
  String re = "";
  s1flush();
  Serial1.println("http.get(\"http://" + Serveradress + anfrage + "\", nil, function(code, data) if (code < 0) then print(\"9.\") else print(data) end end)");
  Serial1.flush();
  while (!Serial1.available()) {}; // Wait for characters
  //clear input until start sign .
  Serial1.readStringUntil('.');
  //save value until end sign ,
  re = Serial1.readStringUntil(',');
  //re[re.length() - 1] = '\0';
  s1flush();
  return re.toInt();
}
