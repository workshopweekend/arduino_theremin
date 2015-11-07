int trigger = 3;
int echo = 4;
int led1 = 13;
int led2 = 12;
int led3 = 11;
int led4 = 10;
int led5 = 9;
int led6 = 8;
int led7 = 7;

unsigned long count = 0;
unsigned long distanceInCm = 0;
void setup()
{
  pinMode (trigger, OUTPUT);
  pinMode(echo, INPUT);
  pinMode(led, OUTPUT);
  digitalWrite(trigger, LOW);
  Serial.begin(9600);
}

void loop()
{
  // Hold trigger pin high for 10 microseconds
  digitalWrite(trigger, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigger, LOW);

  // Get the width of the pulse with pulseIn
  count = pulseIn(echo, HIGH);
  // get distance in cm. Divide by 148 for inches
  distanceInCm = count / 58;
  Serial.println(distanceInCm);
  if((distanceInCm > 4) && (distanceInCm < 25))
  {
    digitalWrite(led1, HIGH);
    digitalWrite(led2, HIGH);
    digitalWrite(led3, HIGH);
    digitalWrite(led4, HIGH);
    digitalWrite(led5, HIGH);
    digitalWrite(led6, HIGH);
    digitalWrite(led7, HIGH);
  }
  else
  {
    digitalWrite(led1, LOW);
    digitalWrite(led2, LOW);
    digitalWrite(led3, LOW);
    digitalWrite(led4, LOW);
    digitalWrite(led5, LOW);
    digitalWrite(led6, LOW);
    digitalWrite(led7, LOW);
  }
  count = 0;
  
  // add a delay for stable behaviour
  delay(200);
}
