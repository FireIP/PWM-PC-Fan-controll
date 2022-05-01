#include <SPI.h>
#include <Ethernet.h>
#include "SdFat.h"

int8_t fan1 = 10;
int8_t fan2 = 9;
int8_t fan3 = 3;

int fan1rpm = 0;
int fan2rpm = 0;

boolean isAuto = true;

int8_t LM35 = 7;
int LM35Read;
int temperatur = 0;
int tempOffset = -30;
int analogPin = 3; // Potentiometer auf Pin 3 verbunden
int val = 0; // Variable, um den gelesenen Wert zu speichern
int fan = 0;

int16_t tempFan1 = 0;
int16_t tempFan3 = 0;

int8_t stufe;

long startTime = 0;
boolean timer = false;
boolean showSeg = true;

boolean readHtm = true;

String request = "";
boolean isGet = false;
boolean isFin = false;

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
  pinMode(fan2, OUTPUT); // Setzt den Pin als output.
  pinMode(fan3, OUTPUT);

  //Sieben-Seg Pins
  //  ----2----
  //  |       |
  //  6       4
  //  |       |
  //  ----9----
  //  |       |
  //  7       5
  //  |       |
  //  ----8----
  pinMode(2, OUTPUT);
  pinMode(4, OUTPUT);
  pinMode(5, OUTPUT);
  pinMode(6, OUTPUT);
  pinMode(7, OUTPUT);
  pinMode(8, OUTPUT);
  pinMode(9, OUTPUT);

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
  val = analogRead(analogPin); // Liest den Wert vom Pin ein
  LM35Read = analogRead(LM35);
  temperatur= map(LM35Read, 0, 307, 0, 150);

  tempFan1 = fan + ((tempOffset + temperatur) * 5) - 0;
  tempFan3 = fan + ((tempOffset + temperatur) * 4) - 0;

  if(fan != 0){
    showSeg = true;
    timer = false;
    if (tempFan1 >= 255){
      analogWrite(fan1, 255);
      analogWrite(fan2, 255);
    }
    else if(tempFan1 <= 103){
      analogWrite(fan1, 25);
      analogWrite(fan2, 25);
    }
    else{
      analogWrite(fan1, tempFan1);
      analogWrite(fan2, tempFan1);
    }

    if (tempFan3 >= 255){
      analogWrite(fan3, 255);
    }
    else if(tempFan3 <= 103){
      analogWrite(fan3, 25);
    }
    else{
      analogWrite(fan3, tempFan3);
    }
  }
  else{
    analogWrite(fan1, fan);
    analogWrite(fan2, fan);
    analogWrite(fan3, fan);

    if(!timer){
      timer = true;
      startTime = millis()/1000;
    }
    else{
      if((millis()/1000) - startTime >= 3){
        showSeg = false;
      }
    }
  }

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

void outSeg(int i){
  if(showSeg){
    digitalWrite(2, seg[i][0]);
    for(int8_t z = 1; z <= 9; z++){
      digitalWrite(z+3, seg[i][z]);
    }
  }
  else{
    digitalWrite(2, LOW);
    for(int8_t z = 4; z <= 9; z++){
      digitalWrite(z, LOW);
    }
  }
  stufe = i;
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
          Serial.println(request);
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

void sendHtmFile(File32 file, EthernetClient client) {
  char line[70];
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
      out.replace("#placeAktTemp#", String(temperatur));
      out.replace("#placeAktFan#", String(fan));
      out.replace("#placeAktStufe#", String(stufe));
      if(!readHtm){
        out.replace("#placeFan1rpm#", String(fan1rpm));
        out.replace("#placeFan2rpm#", String(fan2rpm));
        out.replace("#placeAktAuto#", String(isAuto));
      }
      client.println(out);
      Serial.println(out);
    } else {
      // no '\n' - line too long or missing '\n' at EOF
      // handle error
    }
  }
}
