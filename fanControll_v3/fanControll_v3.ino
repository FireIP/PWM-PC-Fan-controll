#include <SPI.h>
#include <Ethernet.h>
#include "SdFat.h"
#include "sdios.h"

int AbfrZeit = 2000; // Zeitabstand für die Abfragen des Tachosignals

int8_t fan1 = 10;
int8_t fan1Tacho = A1;
long TachoMillis1 = AbfrZeit; // Zeitabstand für Pulse Stretching Funktion
float RPS1 = 0; // Variable mit Kommastelle für die Berechnung der Umdrehungen pro Sekunde
int RPM1 = 0; // Variable für die gemittelte Drehzahl
float UmdrZeit1 = 0; // Variable mit Kommastelle für die Zeit pro Umdrehung des Lüfters
float FlankenZeit1 =0; // Variable mit Kommastelle für die Zeit pro Puls des Lüfters 

int8_t fan2 = 9;
int8_t fan2Tacho = A2;
long TachoMillis2 = AbfrZeit; // Zeitabstand für Pulse Stretching Funktion
float RPS2 = 0; // Variable mit Kommastelle für die Berechnung der Umdrehungen pro Sekunde
int RPM2 = 0; // Variable für die gemittelte Drehzahl
float UmdrZeit2 = 0; // Variable mit Kommastelle für die Zeit pro Umdrehung des Lüfters
float FlankenZeit2 =0; // Variable mit Kommastelle für die Zeit pro Puls des Lüfters 

int8_t fan3 = 3;

int8_t LM35 = 7;
int LM35Read;
byte temperatur = 0;
int8_t tempOffset = -30;
int8_t analogPin = 6; // Potentiometer auf Pin 3 verbunden
int val = 0; // Variable, um den gelesenen Wert zu speichern
int fan = 0;

int tempFan1 = 0;
int tempFanOnline = 0;

int8_t stufe;

long startTime = 0;
boolean showSeg = true;

boolean readHtm = true;

//web
String request = "";
boolean isGet = false;
boolean isFin = false;
boolean onlineCtr = false;
boolean wertOnline = false;
int8_t stufeOnline = 0;

//SPI CS
const int8_t sdRead = A5;
const int8_t eth = A3;

//Ethernet
byte mac[] = {
  0xDE, 0xAD, 0xBE, 0xEF, 0xFE, 0xED
};
IPAddress ip(192, 168, 178, 18);
EthernetServer server(80);

//SD
SdFat32 sd;
File32 fileRead;
File32 fileDisplay;

#define SPI_SPEED SD_SCK_MHZ(50)//set to 50 when on PCB

//Lookup7-Seg                    2  4  5  6  A0 8  9      7 := dot
const byte seg[10][7] PROGMEM ={{1, 0, 1, 1, 1, 1, 1},
                                {1, 0, 0, 0, 0, 1, 0},
                                {1, 1, 0, 1, 1, 0, 1},
                                {1, 1, 0, 0, 1, 1, 1},
                                {1, 1, 1, 0, 0, 1, 0},
                                {0, 1, 1, 0, 1, 1, 1},
                                {0, 1, 1, 1, 1, 1, 1},
                                {1, 0, 0, 0, 0, 1, 1},
                                {1, 1, 1, 1, 1, 1, 1},
                                {1, 1, 1, 0, 1, 1, 1}};

void setup() {
  //Test
  Serial.begin(9600);

  
  TCCR1B = TCCR1B & 0b11111000 | 0x01;
  TCCR2B = TCCR2B & 0b11111000 | 0x01;
  pinMode(fan1, OUTPUT); // Setzt den Pin als output.
  pinMode(fan1Tacho, INPUT);
  pinMode(fan2, OUTPUT); // Setzt den Pin als output.
  pinMode(fan2Tacho, INPUT);
  pinMode(fan3, OUTPUT);

  //Sieben-Seg Pins     7 := dot
  //  ----9----
  //  |       |
  //  5       2
  //  |       |
  //  ----9----
  //  |       |
  //  6       8
  //  |       |
  //  ----A0---
  pinMode(2, OUTPUT);
  pinMode(4, OUTPUT);
  pinMode(5, OUTPUT);
  pinMode(6, OUTPUT);
  pinMode(A0, OUTPUT);
  pinMode(8, OUTPUT);
  pinMode(9, OUTPUT);
  
  pinMode(7, OUTPUT);

  //Ethernet
  pinMode(sdRead, OUTPUT);
  digitalWrite(sdRead, HIGH);
  
  delay(10);
  Ethernet.init(eth);
  delay(10);
  Ethernet.begin(mac, ip);
  delay(10);

  //SD
  Serial.println(true);
  Serial.println(false);

  pinMode(eth, OUTPUT);
  digitalWrite(eth, HIGH);
  
  Serial.println(sd.begin(sdRead, SPI_SPEED));
  delay(10);
  Serial.println(fileRead.open("read.htm", FILE_READ));
  delay(10);
  Serial.println(fileDisplay.open("display.htm", FILE_READ));
  delay(10);
}

void loop() {
  if((millis() - TachoMillis1) >= AbfrZeit && (fan != 0 || ((tempFanOnline != 0 || stufeOnline != 0) && onlineCtr))) {
    pulse_stretch1();
  }
  if((millis() - TachoMillis2) >= AbfrZeit && (fan != 0 || ((tempFanOnline != 0 || stufeOnline != 0) && onlineCtr))) {
    pulse_stretch2();
  }
  if(!(fan != 0 || ((tempFanOnline != 0 || stufeOnline != 0) && onlineCtr))){
    RPM1 = 0;
    RPM2 = 0;
  }
  
  val = analogRead(analogPin); // Liest den Wert vom Pin ein
  LM35Read = analogRead(LM35);
  temperatur= map(LM35Read, 0, 307, 0, 150);

  //test
  //temperatur = 30;

  tempFan1 = fan + ((tempOffset + temperatur) * 5) - 0;

  setFan();

  if(val <= 103){
    outSeg(0);
    fan = 0;
  }
  else if(val <= 206){
    outSeg(1);
    fan = val/4;
  }
  else if(val <= 309){
    outSeg(2);
    fan = val/4;
  }
  else if(val <= 412){
    outSeg(3);
    fan = val/4;
  }
  else if(val <= 515){
    outSeg(4);
    fan = val/4;
  }
  else if(val <= 618){
    outSeg(5);
    fan = val/4;
  }
  else if(val <= 721){
    outSeg(6);
    fan = val/4;
  }
  else if(val <= 824){
    outSeg(7);
    fan = val/4;
  }
  else if(val <= 927){
    outSeg(8);
    fan = val/4;
  }
  else if(val <= 1030){
    outSeg(9);
    fan = val/4;
  }
  webServer();
}

void outSeg(byte i){
  timerSeg(i);
  
  //showSeg = true;
  
  if(showSeg){
    digitalWrite(2, seg[i][0]);
    digitalWrite(4, seg[i][1]);
    digitalWrite(5, seg[i][2]);
    digitalWrite(6, seg[i][3]);
    digitalWrite(A0, seg[i][4]);
    digitalWrite(8, seg[i][5]);
    digitalWrite(9, seg[i][6]);
  }
  else{
    digitalWrite(2, LOW);
    digitalWrite(4, LOW);
    digitalWrite(5, LOW);
    digitalWrite(6, LOW);
    digitalWrite(A0, LOW);
    digitalWrite(8, LOW);
    digitalWrite(9, LOW);
  }
  stufe = i;
}

void setFan(){
  //test
  analogWrite(fan2, 0);
  if(!onlineCtr){
    if(fan != 0){
      if (tempFan1 >= 255){
        analogWrite(fan1, 255);
        //analogWrite(fan2, 255);
        analogWrite(fan3, 255);
      }
      else if(tempFan1 <= 103){
        analogWrite(fan1, 25);
        //analogWrite(fan2, 25);
        analogWrite(fan3, 25);
      }
      else{
        analogWrite(fan1, tempFan1);
        //analogWrite(fan2, tempFan1);
        analogWrite(fan3, tempFan1);
      }
    }
    else{
      analogWrite(fan1, fan);
      //analogWrite(fan2, fan);
      analogWrite(fan3, fan);
    }
  }
  else {
    setFanOnline();
  }
}

void setFanOnline(){
  if(!wertOnline) {
    if(stufeOnline == 0){
      tempFanOnline = 0;
    }
    else if(stufeOnline == 9){
      tempFanOnline = 255;
    }
    else{
      tempFanOnline = (25 * stufeOnline) + 10;
    }
  }
  else{
    stufeOnline = tempFanOnline/25;
    if(stufe > 9){
      stufeOnline = 9;
    }
  }
  analogWrite(fan1, tempFanOnline);
  //analogWrite(fan2, tempFanOnline);
  analogWrite(fan3, tempFanOnline);
  timerSeg(stufe);
}

void timerSeg(byte i) {
  if(i != stufe){
    startTime = millis()/1000;
    showSeg = true;
    onlineCtr = false;
  }
  else if ((millis()/1000) - startTime >= 3) {
    showSeg = false;
  }
}

void webServer(){
  // listen for incoming clients
  EthernetClient client = server.available();
  if (client) {
    //Serial.println("new client");
    // an http request ends with a blank line
    boolean currentLineIsBlank = true;
    while (client.connected()) {
      if (client.available()) {
        char c = client.read();
        if(!isFin){
          request = request + c;
        }

        if(!isGet){
          if(request.endsWith("GET")){
            request = "";
            isGet = true;
          }
        }
        else{
            isFin = request.endsWith("HTTP/1.1");
        }
        
        Serial.write(c);
        // if you've gotten to the end of the line (received a newline
        // character) and the line is blank, the http request has ended,
        // so you can send a reply
        if (c == '\n' && currentLineIsBlank) {
          readHtm = request.indexOf("display") == -1;
          Serial.println(request.indexOf("display"));
          Serial.println(readHtm);
          Serial.println("Request: " + request);

          if(readHtm){
            interpretRequest();
          }
          
          // send a standard http response header
          client.println("HTTP/1.1 200 OK");
          client.println("Content-Type: text/html");
          client.println("Connection: close");  // the connection will be closed after completion of the response
          if(!readHtm){
            client.println("Refresh: 2");  // refresh the page automatically every 5 sec
          }
          client.println();
          client.println("<!DOCTYPE HTML>");
          //------------- read file
          
          if(readHtm){
            sendHtmFile(fileRead, client);
          }
          else{
            sendHtmFile(fileDisplay, client);
          }
        
          
          
          break;
        }
        if (c == '\n') {
          // you're starting a new line
          currentLineIsBlank = true;
        } else if (c != '\r') {
          // you've gotten a character on the current line
          currentLineIsBlank = false;
        }
      }
    }
    // give the web browser time to receive the data
    delay(1);
    // close the connection:
    client.stop();
    request = "";
    isFin = isGet = false;
    //Serial.println("client disconnected");
  }
}

void interpretRequest(){
  byte ind = request.indexOf("stufe") + 6;
  Serial.println(ind);
  String tempS = request.substring(ind);
  Serial.println(tempS);
  
  byte i = 0;
  Serial.println("int: " + String(isDigit(tempS.charAt(i))) + "    c: " + String(tempS.charAt(i)));
  while(isDigit(tempS.charAt(i))){
    i++;
    Serial.println("int: " + String(isDigit(tempS.charAt(i))) + "    c: " + String(tempS.charAt(i)));
  }
  tempS = tempS.substring(0, i);
  Serial.println(tempS);
  if(tempS.length() > 0){
    onlineCtr = true;
  }
  stufeOnline = tempS.toInt();
  fan = 1;

  if(stufe < 0){
    stufeOnline = 0;
  }
  else if(9 < stufe) {
    stufeOnline = 9;
  }

  ind = request.indexOf("wert") + 5;
  Serial.println(ind);
  tempS = request.substring(ind);
  Serial.println(tempS);
  
  i = 0;
  Serial.println("int: " + String(isDigit(tempS.charAt(i))) + "    c: " + String(tempS.charAt(i)));
  while(isDigit(tempS.charAt(i))){
    i++;
    Serial.println("int: " + String(isDigit(tempS.charAt(i))) + "    c: " + String(tempS.charAt(i)));
  }
  tempS = tempS.substring(0, i);
  Serial.println(tempS);
  if(tempS.length() > 0){
    wertOnline = true;
    onlineCtr = true;
    tempFanOnline = tempS.toInt();
    fan = tempFanOnline;
    
    if(tempFanOnline < 25){
      tempFanOnline = 0;
    }
    else if(255 < stufe) {
      tempFanOnline = 255;
    }
  }
  else if(readHtm){
    wertOnline = false;
  }
  
}

void sendHtmFile(File32 file, EthernetClient client) {
  char line[30];
  int n;
  
  // check for open error
  //if (!file.isOpen()) Serial.println("demoFgets");

  // read lines from the file
  while ((n = file.fgets(line, sizeof(line))) > 0) {
    if (line[n - 1] == '\n') {
      // remove '\n'
      line[n-1] = 0;
      // replace next line with LCD call to display line
      String out = String(line);
      out.replace("#AktTemp#", String(temperatur));
      if(onlineCtr){
        out.replace("#AktFan#", String(tempFanOnline));
        out.replace("#AktStufe#", String(stufeOnline));
      }
      else{
        out.replace("#AktFan#", String(fan));
        out.replace("#AktStufe#", String(stufe));
      }
      
      if(!readHtm){
        out.replace("#Fan1rpm#", String(RPM1));
        out.replace("#Fan2rpm#", String(RPM2));
        out.replace("#AktAuto#", String(onlineCtr));
      }
      client.println(out);
      Serial.println(out);
    } else {
      // no '\n' - line too long or missing '\n' at EOF
      // handle error
    }
  }
}

void pulse_stretch1() {

  analogWrite(fan1, 255); // Den Lüfter konstant mit Strom versorgen damit das Tachosignal funktioniert
  FlankenZeit1 = pulseIn(fan1Tacho, HIGH); // Abfrage der Zeit pro Puls in Mikrosekunden
  setFan(); // Setzt die Lüftergeschwindigkeit zurück
  UmdrZeit1 = ((FlankenZeit1 * 4)/1000); // Berechnung der Zeit pro Umdrehung in Millisekunden
  RPS1 = (1000/UmdrZeit1); // Umrechnung auf Umdrehungen pro Sekunde
  RPM1 = (RPS1*60); // Umrechnung auf Umdrehungen pro Minute
  
  //Serial.println(RPM1); // Ausgabe der Drehzahl im Seriellen Monitor
  
  TachoMillis1 = millis(); // Die TachoMillis werden aktualisiert um die nächsten 2000ms zählen zu können
}
void pulse_stretch2() {

  analogWrite(fan3, 255); // Den Lüfter konstant mit Strom versorgen damit das Tachosignal funktioniert
  FlankenZeit2 = pulseIn(fan2Tacho, HIGH); // Abfrage der Zeit pro Puls in Mikrosekunden
  setFan(); // Setzt die Lüftergeschwindigkeit zurück
  UmdrZeit2 = ((FlankenZeit2 * 4)/1000); // Berechnung der Zeit pro Umdrehung in Millisekunden
  RPS2 = (1000/UmdrZeit2); // Umrechnung auf Umdrehungen pro Sekunde
  RPM2 = (RPS2*60); // Umrechnung auf Umdrehungen pro Minute
  
  //Serial.println(RPM1); // Ausgabe der Drehzahl im Seriellen Monitor
  
  TachoMillis2 = millis(); // Die TachoMillis werden aktualisiert um die nächsten 2000ms zählen zu können
}
