#include <Wire.h> 
 
#define adress_2 0x2
#define adress_1 0x1
    
const int buttonPin[4]={2,3,4,5};
int buttonState[4]={0,0,0,0};
int lastButtonState[4]={0,0,0,0};
int startPressed[4]={0,0,0,0};
int endPressed[4]={0,0,0,0};
int timeHold[4]={0,0,0,0};
int timeReleased[4]={0,0,0,0};

char timeHoldS[10];
char nota[10];
char durata[10];
char structura[20];

void setup() {
  Serial.begin(9600);
  pinMode(buttonPin[0], INPUT);
  pinMode(buttonPin[1], INPUT);
  pinMode(buttonPin[2], INPUT);
  pinMode(buttonPin[3], INPUT);
  Wire.begin(adress_1);
}

void loop() {
  buttonState[0] = digitalRead(buttonPin[0]);

  if (buttonState[0] != lastButtonState[0]) {
     
      if (buttonState[0] == HIGH) {
          startPressed[0] = millis();
          timeReleased[0] = startPressed[0] - endPressed[0];
          itoa(261,nota,10);
          itoa(0,durata,10);
          strncpy(structura,nota,10);
          for(int i=strlen(nota); i<=10; i++)
            structura[i]=' ';
          strncpy(structura+10,durata,10);
          Serial.print(structura);
          Wire.beginTransmission(adress_2);
          Wire.write(20);
          Wire.write(structura);
          Wire.endTransmission();

      } else {
      
          endPressed[0] = millis();
          timeHold[0] = endPressed[0] - startPressed[0];
          itoa(0,nota,10);
          itoa(timeHold[0],durata,10);
           strncpy(structura,nota,10);
          for(int i=strlen(nota); i<=10; i++)
            structura[i]=' ';
          strncpy(structura+10,durata,10);
          Serial.print(structura);
          Wire.beginTransmission(adress_2);
          Wire.write(20);
          Wire.write(structura);
          Wire.endTransmission();
      }
  }

   buttonState[1] = digitalRead(buttonPin[1]);

  if (buttonState[1] != lastButtonState[1]) {
      
      if (buttonState[1] == HIGH) {
          startPressed[1] = millis();
          timeReleased[1] = startPressed[1] - endPressed[1];

          itoa(293,nota,10);
          itoa(0,durata,10);
          strncpy(structura,nota,10);
          for(int i=strlen(nota); i<=10; i++)
            structura[i]=' ';
          strncpy(structura+10,durata,10);
          Serial.print(structura);
          Wire.beginTransmission(adress_2);
          Wire.write(20);
          Wire.write(structura);
          Wire.endTransmission();

      } else {
      
          endPressed[1] = millis();
          timeHold[1] = endPressed[1] - startPressed[1];
          itoa(0,nota,10);
          itoa(timeHold[1],durata,10);
           strncpy(structura,nota,10);
          for(int i=strlen(nota); i<=10; i++)
            structura[i]=' ';
          strncpy(structura+10,durata,10);
          Serial.print(structura);
          Wire.beginTransmission(adress_2);
          Wire.write(20);
          Wire.write(structura);
          Wire.endTransmission();
           
      }

  }

  buttonState[2] = digitalRead(buttonPin[2]);

  if (buttonState[2] != lastButtonState[2]) {
      
      if (buttonState[2] == HIGH) {
          startPressed[2] = millis();
          timeReleased[2] = startPressed[2] - endPressed[2];
          itoa(329,nota,10);
          itoa(0,durata,10);
          strncpy(structura,nota,10);
          for(int i=strlen(nota); i<=10; i++)
            structura[i]=' ';
          strncpy(structura+10,durata,10);
          Serial.print(structura);
          Wire.beginTransmission(adress_2);
          Wire.write(20);
          Wire.write(structura);
          Wire.endTransmission();

      } else {
      
          endPressed[2] = millis();
          timeHold[2] = endPressed[2] - startPressed[2];
          itoa(0,nota,10);
          itoa(timeHold[2],durata,10);
           strncpy(structura,nota,10);
          for(int i=strlen(nota); i<=10; i++)
            structura[i]=' ';
          strncpy(structura+10,durata,10);
          Serial.print(structura);
          Wire.beginTransmission(adress_2);
          Wire.write(20);
          Wire.write(structura);
          Wire.endTransmission();

      }

  }

  buttonState[3] = digitalRead(buttonPin[3]);

  if (buttonState[3] != lastButtonState[3]) {
      
      if (buttonState[3] == HIGH) {
          startPressed[3] = millis();
          timeReleased[3] = startPressed[3] - endPressed[3];

          itoa(349,nota,10);
          itoa(0,durata,10);
          strncpy(structura,nota,10);
          for(int i=strlen(nota); i<=10; i++)
            structura[i]=' ';
          strncpy(structura+10,durata,10);
          Serial.print(structura);
          Wire.beginTransmission(adress_2);
          Wire.write(20);
          Wire.write(structura);
          Wire.endTransmission();

      } else {
      
          endPressed[3] = millis();
          timeHold[3] = endPressed[3] - startPressed[3];
          itoa(0,nota,10);
          itoa(timeHold[3],durata,10);
           strncpy(structura,nota,10);
          for(int i=strlen(nota); i<=10; i++)
            structura[i]=' ';
          strncpy(structura+10,durata,10);
          Serial.print(structura);
          Wire.beginTransmission(adress_2);
          Wire.write(20);
          Wire.write(structura);
          Wire.endTransmission();
          
      }

  }
  lastButtonState[0] = buttonState[0];
  lastButtonState[1] = buttonState[1];
  lastButtonState[2] = buttonState[2];
  lastButtonState[3] = buttonState[3];
}

