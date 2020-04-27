/* Traffic Lights with a CrossWalk
    By Krystle Hewitt
   When a button is pressed the lights and crosswalk will signal wheather to stop or go.
*/
#define westButton 3
#define eastButton 13
#define westRed 2
#define westYellow 1
#define westGreen 0
#define westCrossRed 4
#define westCrossBlue 5
#define eastRed  12
#define eastYellow 11
#define eastGreen 10
#define eastCrossRed 9
#define eastCrossBlue 8
#define yellowBlinkTime 500
boolean trafficWest = true;
int flowTime  = 5000;
int changeDelay = 2000;

void setup() {
  pinMode(westButton, INPUT); /*Setting the buttons as the input and setting the LEDs as outputs*/
  pinMode(eastButton, INPUT);
  pinMode(westRed, OUTPUT);
  pinMode(westYellow, OUTPUT);
  pinMode(westGreen, OUTPUT);
  pinMode(eastRed, OUTPUT);
  pinMode(eastYellow, OUTPUT);
  pinMode(eastGreen, OUTPUT);
  pinMode(westCrossRed, OUTPUT);
  pinMode(westCrossBlue, OUTPUT);
  pinMode(eastCrossRed, OUTPUT);
  pinMode(eastCrossBlue, OUTPUT);

  digitalWrite(westRed,  LOW); /* Setting the LEDs to their beginning state.*/
  digitalWrite(westYellow,  LOW);
  digitalWrite(westGreen,  HIGH);
  digitalWrite(eastRed, HIGH);
  digitalWrite(eastYellow, LOW);
  digitalWrite(eastGreen, LOW);
  digitalWrite(westCrossRed,  LOW);
  digitalWrite(westCrossBlue,  HIGH);
  digitalWrite(eastCrossRed,  HIGH);
  digitalWrite(eastCrossBlue,  LOW);
}

void blinkYellowLight(int yellowLED , int RedLED)
{
  for ( int i = 0; i < 5; i++ )
  {
    digitalWrite(yellowLED, LOW);
    digitalWrite(RedLED,  LOW);
    delay(yellowBlinkTime);
    digitalWrite(yellowLED, HIGH);
    digitalWrite(RedLED,  HIGH);
    delay(yellowBlinkTime);
  }
}

void greenToYellow(int green, int crossBlue, int yellow)
{
  digitalWrite(green, LOW);
  digitalWrite(crossBlue,  LOW);
  digitalWrite(yellow, HIGH);
  delay(changeDelay);
}

void yellowToRed(int Yellow, int Red, int CrossRed)
{
  digitalWrite(Yellow, LOW);
  digitalWrite(Red, HIGH);
  digitalWrite(CrossRed,  HIGH);
  delay(changeDelay);
}


void loop() {

  if ( digitalRead(westButton) == HIGH ) /* If button is pressed then the lights for TrafficWest will either stay the same or change depending on the previous state.*/
  {
    if ( trafficWest != true )
    {
      trafficWest = true;
      delay(flowTime);

      greenToYellow(eastGreen, eastCrossBlue, eastYellow);

      yellowToRed(eastYellow, eastRed, eastCrossRed)

      blinkYellowLight(westYellow , westCrossRed);

      digitalWrite(westYellow, LOW);
      digitalWrite(westRed, LOW);
      digitalWrite(westCrossRed,  LOW);
      digitalWrite(westGreen, HIGH);
      digitalWrite(westCrossBlue,  HIGH);

    }
  }
  if ( digitalRead(eastButton) == HIGH )/* If button is pressed then the lights for TrafficWest will either stay the same or change depending on the previous state.*/
  {
    if ( trafficWest == true )
    {
      trafficWest = false;
      delay(flowTime);

      greenToYellow(westGreen, westCrossBlue, westYellow);

      yellowToRed( westYellow, westRed, westCrossRed)

      blinkYellowLight(eastYellow, eastCrossRed);

      digitalWrite(eastYellow, LOW);
      digitalWrite(eastRed, LOW);
      digitalWrite(eastCrossRed,  LOW);
      digitalWrite(eastGreen, HIGH);
      digitalWrite(eastCrossBlue,  HIGH);
    }
  }
}
