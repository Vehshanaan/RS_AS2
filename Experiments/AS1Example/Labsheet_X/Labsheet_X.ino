#include "motors.h"
#include "LineSensor.h"

#include "LED.h"
#include "pid.h"

#define LINE_SENSOR_UPDATE 100
#define MOTOR_UPDATE 2000

LineSensor ls;
Motors motor;
LED led;

unsigned long ls_ts = millis();    // line sensor time stomp
unsigned long motor_ts = millis(); // motor time stomp
unsigned long set;
int state = 0;
int x = 0;

void LineFollow()
{
  ls.updateLineSensor();
  ls.at_line();
  if (ls.online == 1)
  {
    led.yellowOn();
    motor.setMotorPower(motor.LMPower * motor.L_DIR * ls.score + 15, motor.RMPower * motor.R_DIR * (-ls.score) + 15);
  }
  else
    led.yellowOff();
}

// put your setup code here, to run once:
void setup()
{

  Serial.begin(9600);
  delay(800);
  Serial.println("***RESET***");

  led.initialise();
  motor.init();
  ls.init(3);
  motor.setMotorPower(18, 18);
  set = millis();
}
int counter = 0;

unsigned long before_start = millis(); // mark the loop elapse time counting start point
unsigned long longest_loop = 0;        // loop duration

// put your main code here, to run repeatedly:
void loop()
{
  // put your main code here, to run repeatedly:

  // compute the elapsed time since the last time motors update

  if (state == 0)
  {
    ls.updateLineSensor();
    int a = 0;
    for (int i = 0; i < ls.number; i++)
    {
      if (ls.sensor_read[i] > 1000)
        a = a + 1;
    }
    if (a == 3)
    {
      delay(100);
      motor.setMotorPower(-10, 10);
      int remain = 1;
      while (remain)
      {
        ls.updateLineSensor();
        for (int i = 0; i < ls.number; i++)
        {
          if (ls.sensor_read[i] > 1000)
          {
            remain = 0;
            state = 1;
          }
        }
      }
    }
  }

  else if (state == 1)
  {
    int b = 0;
    LineFollow();
    for (int i = 0; i < ls.number; i++)
    {
      if (ls.sensor_read[i] < 1000)
        b = b + 1;
    }
    if (b == 3 && x == 0)
    {
      set = millis();
      x = 1;
    }
    else if (b == 3 && x == 1)
    {
      if (millis() - set > 4000)
      {
        state = 2;
        motor.setMotorPower(0, 0);
      }
    }
    if (ls.online == 1)
      x = 0;
  }
  else if (state == 2)
  {
  }

  delay(100);
}