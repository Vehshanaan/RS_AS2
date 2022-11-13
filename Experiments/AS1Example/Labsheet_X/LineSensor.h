#ifndef LINESENSOR
#define LINESENSOR



// 

#define LS_L_PIN A0//18
#define LS_M_PIN A2//20
#define LS_R_PIN A3//21

#define IR_SWITCH 11//EMIT

#define NB_PINS 3 // define the number of pins im using

//array that include all pin numbers, ready for iteration
int ls_pin[NB_PINS]={LS_L_PIN, LS_M_PIN,LS_R_PIN};

unsigned long timeout = 4000;// Time limit, beyond which the timeout is ruled
unsigned long error_ms = 0;// If the timeout expires, return this value for the error: 0

class LineSensor{

  public:
  unsigned long sensor_read[3]; // array for duration time storage
  unsigned long sensor_init[3];
  int number;
  int online;
  float score;
  LineSensor(){    
  }

  void initialize(){
    
  }
   void init(int n){
      number=n;
      online=0;
      score=0.0;
      pinMode(IR_SWITCH,OUTPUT);
      pinMode(LS_L_PIN,INPUT);
      sensor_read[0]=0;
      sensor_init[0]=9999;
      pinMode(LS_M_PIN,INPUT);
      sensor_read[1]=0;
      sensor_init[1]=9999;
      pinMode(LS_R_PIN,INPUT);
      sensor_read[2]=0;
      sensor_init[2]=9999;
      digitalWrite(IR_SWITCH,HIGH);
    }


  void updateLineSensor(){
   pinMode(LS_L_PIN,OUTPUT);
      digitalWrite(LS_L_PIN,HIGH);
      delayMicroseconds(10);
      pinMode(LS_L_PIN,INPUT);
      pinMode(LS_M_PIN,OUTPUT);
      digitalWrite(LS_M_PIN,HIGH);
      delayMicroseconds(10);
      pinMode(LS_M_PIN,INPUT);
      pinMode(LS_R_PIN,OUTPUT);
      digitalWrite(LS_R_PIN,HIGH);
      delayMicroseconds(10);
      pinMode(LS_R_PIN,INPUT);
      unsigned long start_time;
      start_time = micros();
      unsigned long sensor[3]={0};
      int remaining = number;
      unsigned long timeout=5000;
      while(remaining>0){
        unsigned long current_time=micros();
        unsigned long elapsed_time=current_time-start_time;
        if(digitalRead(LS_L_PIN)==LOW){
          if(sensor[0]==0){
            sensor[0]=elapsed_time;
            remaining--;
          }
        }
        if(digitalRead(LS_M_PIN)==LOW){
          if(sensor[1]==0){
            sensor[1]=elapsed_time;
            remaining--;
          }
        }
        if(digitalRead(LS_R_PIN)==LOW){
          if(sensor[2]==0){
            sensor[2]=elapsed_time;
            remaining--;
          }
        }
        if(elapsed_time>=timeout){
          remaining=0;
        }
      }
      for(int i=0;i<number;i++)sensor_read[i]=sensor[i];
  }
  void printDuration(){
    // simply print all the readings, nothing else
    Serial.print("Duration:");
    for(int i=0;i<number;i++){
      Serial.print(sensor_read[i]);
      Serial.print(" ");
    }
  Serial.println("");
  } 

  void at_line(){
      int a=0;
      for(int i=1;i<number;i++){
        if(sensor_read[i]>1500&&sensor_read[i]<2500)a=1;
      }
      if(a==1){
        online=1;
        score=(float(sensor_read[number-1]-sensor_init[number-1])-float(sensor_read[0]-sensor_init[0]))/2000.0;
        
      }
      else online=0;
    }
 

};





#endif
