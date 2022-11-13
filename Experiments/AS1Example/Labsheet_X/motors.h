// this #ifndef stops this file
// from being included mored than
// once by the compiler. 
#ifndef MOTORS
#define MOTORS
# define L_PWM_PIN 10

# define R_PWM_PIN 9
# define R_DIR_PIN 15
# define L_DIR_PIN 16
# define FWD LOW
# define REV HIGH


// Class to operate the motor(s).
class Motors {
  
  public:
  int LMPower;
  int RMPower;
  int L_DIR,R_DIR;
    // Constructor, must exist.
    Motors() {

    } 

    // Use this function to 
    // initialise the pins and 
    // state of your motor(s).
    void init() {
      pinMode(L_PWM_PIN, OUTPUT);
      pinMode(L_DIR_PIN, OUTPUT);
      pinMode(R_PWM_PIN, OUTPUT);
      pinMode(R_DIR_PIN, OUTPUT);
      digitalWrite(L_DIR_PIN,FWD);
      digitalWrite(R_DIR_PIN,FWD);
      digitalWrite(L_PWM_PIN,0);
      digitalWrite(R_PWM_PIN,0);
      LMPower=0;
      RMPower=0;
      L_DIR=1;
      R_DIR=1;
    }

    void setMotorPower(int L, int R){
    if(L<0){
        LMPower=-L;
        L_DIR=-1;
      }
      else{
        LMPower=L;
        L_DIR=1;
      }
      if(R<0){
        RMPower=-R;
        R_DIR=-1;
      }
      else{
        RMPower=R;
        R_DIR=1;
      }
      if(L_DIR>0)digitalWrite(L_DIR_PIN,FWD);
      else digitalWrite(L_DIR_PIN,REV);
      if(R_DIR>0)digitalWrite(R_DIR_PIN,FWD);
      else digitalWrite(R_DIR_PIN,REV);
      analogWrite(L_PWM_PIN, LMPower);
      analogWrite(R_PWM_PIN, RMPower);
  }
    
};



#endif
