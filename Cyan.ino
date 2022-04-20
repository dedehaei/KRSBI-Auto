//#include "track.h"
#include mode.h
String in;
unsigned long now = 0;
unsigned long prev = 0;
int state = 0;
void setup() {

  Serial.begin(9600);

}

void loop() {

  while (Serial.available() > 0) {
    in = Serial.readStringUntil('\n');
    String Bolax = getValue(in, 'B', 1);
    String Bolay = getValue(in, 'B', 1);
    String Magentax = getValue(in, 'M', 1);
    String Magentaa = getValue(in, 'm', 1);
    String Gatex = getValue(in, 'G', 1);
    String Gatea = getValue(in, 'g', 1);
    int bolax = Bolax.toInt();
    int bolay = Bolay.toInt();
    int magentax = Magentax.toInt();
    int magentaa = Magentaa.toInt();
    int gatex = Gatex.toInt();
    int gatea = Gatea.toInt();
    track track(bolax, bolay, magentax, magentaa, gatex, gatea);
    mode mode(limit());
    if(cmd == 1){
      mode.1();
    }
    else if (cmd == 2){
      mode.2();
    }
    else if(cmd == 3){
      mode.3();
    }
    else if(cmd == 4){
      mode.4();
    }
  }
}

int limit() {
  bool in = digitalRead(26);

  if (in == true) {
    now = millis();
    if ((now - prev) >= 2000) {
      state += state;
    }
    else {
      state = state;
    }
  }
  return state;
}
String getValue(String data, char separator, int index)
{
  int found = 0;
  int strIndex[] = {
    0, -1
  };
  int maxIndex = data.length();

  for (int i = 0; i <= maxIndex && found <= index; i++) {
    if (data.charAt(i) == separator || i == maxIndex) {
      found++;
      strIndex[0] = strIndex[1] + 1;
      strIndex[1] = (i == maxIndex) ? i + 1 : i;
    }
  }
  return found > index ? data.substring(strIndex[0], strIndex[1]) : "";
}
