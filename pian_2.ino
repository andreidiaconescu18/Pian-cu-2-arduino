#include <IRremote.h>

#include <Wire.h>

#define adress_2 0x2
#define adress_1 0x1

int RECV_PIN = 11;
IRrecv irrecv(RECV_PIN);
decode_results results;

int vec_note[100];
int dur_note[100];
int nr_note=0;
int buzzer=5;
const int songspeed = 2;

int selectie = 1;

void setup() {
  pinMode(buzzer,OUTPUT);
  Serial.begin(9600);
  Wire.begin(adress_2);
  Wire.onReceive(receive_func);
  irrecv.enableIRIn();
}

void loop() {
  if (irrecv.decode(&results))
    {
      if(results.value==0xFF6897)
        selectie=0;
     if(results.value==0xFF30CF)
        selectie=1;
     if(results.value==0xFF18E7)
        selectie=2;
      if(results.value==0xFF7A85)
        selectie=3;
     irrecv.resume();
  }
  if(selectie==3)
    {
      for(int i=0; i<nr_note; i++)
        {
          int wait = dur_note[i] * songspeed;
          tone(buzzer,vec_note[i],wait);
          delay(wait);
        }
       selectie=1;
    }
  else
    if(selectie==0)
      {
        nr_note=0;
        selectie=1;
      }
}

char buff[100];
char nota_s[15];
char durata_s[10];

void receive_func(int howMany) {
  if(Wire.available()>0){
    byte l = Wire.read();
    for(int i=0; i<l; i++)
    {
      char c = Wire.read();
      buff[i]=c;
    }
    buff[l]='\0';
    strncpy(nota_s,buff,10);
    strncpy(durata_s,buff+10,10);
    int nota = atoi(nota_s);
    int durata = atoi(durata_s);
    Serial.print(nota);
    Serial.print("  ");
    Serial.println(durata);
    if(selectie==1)
      command(nota,durata);
    else
      {
          if(nota!=0)
            vec_note[nr_note]=nota;
          if(nota==0)
            {
              dur_note[nr_note]=durata;
              nr_note++;  
            }
           command(nota,durata);
      }
  }
}

void command(int nota, int durata)
{
      tone(buzzer,nota,durata);
}

