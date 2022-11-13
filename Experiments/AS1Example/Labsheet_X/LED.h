#ifndef LEDS
#define LEDS


#define OFF false 
#define ON true 

#define YELLOW 13 // yellow LED pin
#define RED 17 // red LED pin
#define GREEN 30 // green LED pin

class LED{
  public:
  
  LED(){}

  bool yellow_state = OFF;
  bool red_state = OFF;
  bool green_state = OFF;

  void initialise(){
    pinMode(YELLOW, OUTPUT);
    pinMode(RED, OUTPUT);
    pinMode(GREEN, OUTPUT);
  }

  void yellowToggle(){
    // toggle the yellow LED
    if(yellow_state){
      digitalWrite(YELLOW, LOW);// if on: turn off
      yellow_state = ON;
    }
    else{
      digitalWrite(YELLOW, HIGH);// if off: turn on
      yellow_state = OFF;
    }
  }

  void yellowOn(){
    // turn on the yellow LED
    digitalWrite(YELLOW, HIGH);
    yellow_state = ON;
  }

  void yellowOff(){
    // turn off the yellow LED
    digitalWrite(YELLOW, LOW);
    yellow_state = OFF;
  }

};

#endif