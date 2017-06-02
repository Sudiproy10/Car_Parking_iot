int trigPin = 2;
int echoPin = 4;
int buzzerpin=3;
int Ledpin=5;

void setup() {
  Serial.begin(9600);
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
  pinMode(buzzerpin, OUTPUT);
  pinMode(Ledpin, OUTPUT);
}

void loop()
{
  long duration, inches, cm;
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);

  duration = pulseIn(echoPin, HIGH);

  // convert the time into a distance
  inches = microsecondsToInches(duration);
  cm = microsecondsToCentimeters(duration);
  
  Serial.print(inches);
  Serial.print("in, ");
  Serial.print(cm);
  Serial.print("cm");
  Serial.println();
 delay(100);
  
if(inches<5)
{
  digitalWrite(buzzerpin,HIGH);
  digitalWrite(Ledpin,HIGH);
}
}

long microsecondsToInches(long microseconds)
{
  return microseconds / 74 / 2; //formula
}

long microsecondsToCentimeters(long microseconds)
{
  return microseconds / 29 / 2; //formula
}
