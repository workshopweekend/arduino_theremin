/*************************************************
 * Note Constants Start
 *************************************************/
#define NOTE_B0  31
#define NOTE_C1  33
#define NOTE_CS1 35
#define NOTE_D1  37
#define NOTE_DS1 39
#define NOTE_E1  41
#define NOTE_F1  44
#define NOTE_FS1 46
#define NOTE_G1  49
#define NOTE_GS1 52
#define NOTE_A1  55
#define NOTE_AS1 58
#define NOTE_B1  62
#define NOTE_C2  65
#define NOTE_CS2 69
#define NOTE_D2  73
#define NOTE_DS2 78
#define NOTE_E2  82
#define NOTE_F2  87
#define NOTE_FS2 93
#define NOTE_G2  98
#define NOTE_GS2 104
#define NOTE_A2  110
#define NOTE_AS2 117
#define NOTE_B2  123
#define NOTE_C3  131
#define NOTE_CS3 139
#define NOTE_D3  147
#define NOTE_DS3 156
#define NOTE_E3  165
#define NOTE_F3  175
#define NOTE_FS3 185
#define NOTE_G3  196
#define NOTE_GS3 208
#define NOTE_A3  220
#define NOTE_AS3 233
#define NOTE_B3  247
#define NOTE_C4  262
#define NOTE_CS4 277
#define NOTE_D4  294
#define NOTE_DS4 311
#define NOTE_E4  330
#define NOTE_F4  349
#define NOTE_FS4 370
#define NOTE_G4  392
#define NOTE_GS4 415
#define NOTE_A4  440
#define NOTE_AS4 466
#define NOTE_B4  494
#define NOTE_C5  523
#define NOTE_CS5 554
#define NOTE_D5  587
#define NOTE_DS5 622
#define NOTE_E5  659
#define NOTE_F5  698
#define NOTE_FS5 740
#define NOTE_G5  784
#define NOTE_GS5 831
#define NOTE_A5  880
#define NOTE_AS5 932
#define NOTE_B5  988
#define NOTE_C6  1047
#define NOTE_CS6 1109
#define NOTE_D6  1175
#define NOTE_DS6 1245
#define NOTE_E6  1319
#define NOTE_F6  1397
#define NOTE_FS6 1480
#define NOTE_G6  1568
#define NOTE_GS6 1661
#define NOTE_A6  1760
#define NOTE_AS6 1865
#define NOTE_B6  1976
#define NOTE_C7  2093
#define NOTE_CS7 2217
#define NOTE_D7  2349
#define NOTE_DS7 2489
#define NOTE_E7  2637
#define NOTE_F7  2794
#define NOTE_FS7 2960
#define NOTE_G7  3136
#define NOTE_GS7 3322
#define NOTE_A7  3520
#define NOTE_AS7 3729
#define NOTE_B7  3951
#define NOTE_C8  4186
#define NOTE_CS8 4435
#define NOTE_D8  4699
#define NOTE_DS8 4978
/*************************************************
 * Note Constants Done
 *************************************************/

int piezo = 3;
int trigger = 4;
int echo = 5;

int ledg3 = 6;
int ledg2 = 7;
int ledg1 = 8;
int ledy2 = 9;
int ledy1 = 10;
int ledr3 = 11;
int ledr2 = 12;
int ledr1 = 13;

unsigned long count = 0;
unsigned long distanceInCm = 0;

void setup()
{
  pinMode(trigger, OUTPUT);
  pinMode(echo, INPUT);
  pinMode(piezo, OUTPUT);
  
  pinMode(ledr1, OUTPUT);
  pinMode(ledr2, OUTPUT);
  pinMode(ledr3, OUTPUT);
  pinMode(ledy1, OUTPUT);
  pinMode(ledy2, OUTPUT);
  pinMode(ledg1, OUTPUT);
  pinMode(ledg2, OUTPUT);
  pinMode(ledg3, OUTPUT);

  digitalWrite(trigger, LOW);

  Serial.begin(9600);
}

void loop()
{
  // hold trigger high for 10us to trigger the ultrasonic distance sensor
  digitalWrite(trigger, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigger, LOW);

  // Get the width of the pulse on echo
  count = pulseIn(echo, HIGH);
  
  // get distance in cm. Divide by 148 for inches
  distanceInCm = count / 58;
  Serial.println(distanceInCm);
  
  if((distanceInCm > 4) && (distanceInCm < 25))
  {
    if(distanceInCm < 8)
    {
      tone(piezo,NOTE_C3);
      digitalWrite(ledr1, HIGH);
      digitalWrite(ledr2, HIGH);
      digitalWrite(ledr3, LOW);
      digitalWrite(ledy1, LOW);
      digitalWrite(ledy2, LOW);
      digitalWrite(ledg1, LOW);
      digitalWrite(ledg2, LOW);
      digitalWrite(ledg3, LOW);
    } 
    else if(distanceInCm < 10)
    {
      tone(piezo,NOTE_F3);
      digitalWrite(ledr1, HIGH);
      digitalWrite(ledr2, HIGH);
      digitalWrite(ledr3, HIGH);
      digitalWrite(ledy1, LOW);
      digitalWrite(ledy2, LOW);
      digitalWrite(ledg1, LOW);
      digitalWrite(ledg2, LOW);
      digitalWrite(ledg3, LOW);
    }
    else if(distanceInCm < 12)
    {
      tone(piezo,NOTE_C4);
      digitalWrite(ledr1, HIGH);
      digitalWrite(ledr2, HIGH);
      digitalWrite(ledr3, HIGH);
      digitalWrite(ledy1, HIGH);
      digitalWrite(ledy2, LOW);
      digitalWrite(ledg1, LOW);
      digitalWrite(ledg2, LOW);
      digitalWrite(ledg3, LOW);
    }
    else if(distanceInCm < 14)
    {
      tone(piezo,NOTE_F4);
      digitalWrite(ledr1, HIGH);
      digitalWrite(ledr2, HIGH);
      digitalWrite(ledr3, HIGH);
      digitalWrite(ledy1, HIGH);
      digitalWrite(ledy2, HIGH);
      digitalWrite(ledg1, LOW);
      digitalWrite(ledg2, LOW);
      digitalWrite(ledg3, LOW);
    }
    else if(distanceInCm < 18)
    {
      tone(piezo,NOTE_C5);
      digitalWrite(ledr1, HIGH);
      digitalWrite(ledr2, HIGH);
      digitalWrite(ledr3, HIGH);
      digitalWrite(ledy1, HIGH);
      digitalWrite(ledy2, HIGH);
      digitalWrite(ledg1, HIGH);
      digitalWrite(ledg2, LOW);
      digitalWrite(ledg3, LOW);
    }
    else if(distanceInCm < 22)
    {
      tone(piezo,NOTE_F5);
      digitalWrite(ledr1, HIGH);
      digitalWrite(ledr2, HIGH);
      digitalWrite(ledr3, HIGH);
      digitalWrite(ledy1, HIGH);
      digitalWrite(ledy2, HIGH);
      digitalWrite(ledg1, HIGH);
      digitalWrite(ledg2, HIGH);
      digitalWrite(ledg3, LOW);
    }
    else
    {
      tone(piezo,NOTE_C6);
      digitalWrite(ledr1, HIGH);
      digitalWrite(ledr2, HIGH);
      digitalWrite(ledr3, HIGH);
      digitalWrite(ledy1, HIGH);
      digitalWrite(ledy2, HIGH);
      digitalWrite(ledg1, HIGH);
      digitalWrite(ledg2, HIGH);
      digitalWrite(ledg3, HIGH);
    }
  }
  else
  {
    noTone(piezo);
    digitalWrite(ledr1, LOW);
    digitalWrite(ledr2, LOW);
    digitalWrite(ledr3, LOW);
    digitalWrite(ledy1, LOW);
    digitalWrite(ledy2, LOW);
    digitalWrite(ledg1, LOW);
    digitalWrite(ledg2, LOW);
    digitalWrite(ledg3, LOW);
  }
  count = 0;
  
  delay(100);
}
