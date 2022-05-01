int fan1 = 11;
int fan2 = 3;
int LM35 = 7;
int LM35Read;
int temperatur = 0;
int tempOffset = -30;
int analogPin = 3; // Potentiometer auf Pin 3 verbunden
int val = 0; // Variable, um den gelesenen Wert zu speichern
int fan = 0;

int tempFan1 = 0;
int tempFan2 = 0;

long startTime = 0;
boolean timer = false;
boolean showSeg = true;

//Lookup7-Seg           2  4  5  6  7  8  9
const int seg[10][7] ={{1, 1, 1, 1, 1, 1, 0},
                       {0, 1, 1, 0, 0, 0, 0},
                       {1, 1, 0, 0, 1, 1, 1},
                       {1, 1, 1, 0, 0, 1, 1},
                       {0, 1, 1, 1, 0, 0, 1},
                       {1, 0, 1, 1, 0, 1, 1},
                       {1, 0, 1, 1, 1, 1, 1},
                       {1, 1, 1, 0, 0, 0, 0},
                       {1, 1, 1, 1, 1, 1, 1},
                       {1, 1, 1, 1, 0, 1, 1}};

void setup() {
  TCCR2B = TCCR2B & 0b11111000 | 0x01;
  pinMode(fan1, OUTPUT); // Setzt den Pin als output.
  pinMode(fan2, OUTPUT); // Setzt den Pin als output.

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
}

void loop() {
  val = analogRead(analogPin); // Liest den Wert vom Pin ein
  LM35Read = analogRead(LM35);
  temperatur= map(LM35Read, 0, 307, 0, 150);

  tempFan1 = fan + ((tempOffset + temperatur) * 5) - 0;
  tempFan2 = fan + ((tempOffset + temperatur) * 4) - 0;

  if(fan != 0){
    showSeg = true;
    timer = false;
    if (tempFan1 >= 255){
      analogWrite(fan1, 255);
    }
    else if(tempFan1 <= 103){
      analogWrite(fan1, 25);
    }
    else{
      analogWrite(fan1, tempFan1);
    }

    if (tempFan2 >= 255){
      analogWrite(fan2, 255);
    }
    else if(tempFan2 <= 103){
      analogWrite(fan2, 25);
    }
    else{
      analogWrite(fan2, tempFan2);
    }
  }
  else{
    analogWrite(fan1, fan);
    analogWrite(fan2, fan);

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
}

void outSeg(int i){
  if(showSeg){
    digitalWrite(2, seg[i][0]);
    digitalWrite(4, seg[i][1]);
    digitalWrite(5, seg[i][2]);
    digitalWrite(6, seg[i][3]);
    digitalWrite(7, seg[i][4]);
    digitalWrite(8, seg[i][5]);
    digitalWrite(9, seg[i][6]);
  }
  else{
    digitalWrite(2, LOW);
    digitalWrite(4, LOW);
    digitalWrite(5, LOW);
    digitalWrite(6, LOW);
    digitalWrite(7, LOW);
    digitalWrite(8, LOW);
    digitalWrite(9, LOW);
  }
}
