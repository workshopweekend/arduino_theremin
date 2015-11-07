int trigger = 4;
int echo = 5;
int led = 13;

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
    digitalWrite(led, HIGH);
  }
  else
  {
    digitalWrite(led, LOW);
  }
  count = 0;
  
  // add a delay for stable behaviour
  delay(200);
}
