#include <Servo.h>


Servo flapout ;
double angle = 0; //don't fix
double dangle = 0; //don't fix
double hangle = 90; //home angle  

void setup()
{
  Serial.begin(9600);
  flapout.attach(9);
  Serial.println("Hello");
  Serial.println("Control flap angle");
  Serial.println("Input 0-45 degree; to home position(degree = 0) type 999");
  flapout.write(hangle);
  Serial.println("Now @" + String(dangle) + " degree");
}

void loop()
{
  if(Serial.available()){
    angle = Serial.parseInt();
  }
  if (angle > 0 && angle <= 45){
    if (angle != dangle && angle != 999){
      flapout.write(hangle-angle);
      Serial.println("flap angle now = "+ String(angle) + " degree");
    }
  }
  if (angle == 999){
    flapout.write(hangle);
    Serial.println("flap angle now @ home position ; " + String(dangle) + " degree");
  }
  if ((angle < 0 || angle > 45)&& angle != 999)
  {
    Serial.println("Error out of range. : angle = " + String(angle));
  }
}
