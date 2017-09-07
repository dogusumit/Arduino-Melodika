#include "notalar.h"
#include "mario.h"

int nota[4][3] = {{NOTE_C4,NOTE_C5,NOTE_A3},{NOTE_A4,NOTE_AS3,NOTE_AS4},{NOTE_F3,NOTE_F4,NOTE_D3},{NOTE_D4,NOTE_DS3,NOTE_DS4}};
int buzzerPin=6;
int echolar[]={2,3,4,5};
int trigler[]={8,9,10,11};
double uzakliklar[4];
double sure[4];

//13 pine +5v verilirse otomatik mario muzigi calar:D


void setup() 
{
  pinMode(buzzerPin,OUTPUT);
  for(int i=0;i<4;i++)
  {
    pinMode(echolar[i],INPUT);
  }
  for(int i=0;i<4;i++)
  {
    pinMode(trigler[i],OUTPUT);
  }
  Serial.begin(9600);
}

void loop() 
{
  if(digitalRead(13)==HIGH)
  mario_cal(buzzerPin);
  else{
    
  
  for (int i = 0; i < 4; ++i)
  {
    digitalWrite(trigler[i], LOW); 
    delayMicroseconds(2); 

    digitalWrite(trigler[i], HIGH);
    delayMicroseconds(10); 
 
    digitalWrite(trigler[i], LOW);
    sure[i] = pulseIn(echolar[i], HIGH);
    uzakliklar[i] = sure[i]/58.2;
  }
  int a=0;
  for (int i = 0; i < 4; ++i)
  {
    Serial.print("sensor ");
    Serial.print(i);
    Serial.print(" = ");
    Serial.print(uzakliklar[i]);
    Serial.println();

    if(uzakliklar[i]>0 && uzakliklar[i]<=10)
      {
        tone(buzzerPin,nota[i][0]);
        //delay(100);
        //noTone(buzzerPin);
        a++;
        break;
      }
        else if(uzakliklar[i]>10 && uzakliklar[i]<=20)
      {
        tone(buzzerPin,nota[i][1]);
        //delay(100);
        //noTone(buzzerPin);
         a++;
        break;
      }
        else if(uzakliklar[i]>20 && uzakliklar[i]<=25)
      {
        tone(buzzerPin,nota[i][2]);
        //delay(100);
        //noTone(buzzerPin);
         a++;
        break;
      }
  }
  if(a==0)
  noTone(buzzerPin);
  }
}
