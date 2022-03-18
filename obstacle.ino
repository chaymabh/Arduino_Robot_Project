#include <Servo.h>  //servo library
Servo myservo;      // create servo object to control servo

#define A4
#define A5

int Echo = A4;  
int Trig = A5; 


#define LT_R !digitalRead(10)
#define LT_M !digitalRead(4)
#define LT_L !digitalRead(2)

#define ENA 5
#define ENB 6
#define IN1 7
#define IN2 8
#define IN3 9
#define IN4 11
#define carSpeed 100

#define LEDRPIN  14    //LED Front Right   pin A0 for Arduino Uno
#define LEDGPIN  15    //LED Front Left    pin A1 for Arduino Uno
#define BuzzPIN 18    //Horn Buzzer       pin A4 for Arduino Uno

bool R = true ;
int rightDistance = 0, leftDistance = 0, middleDistance = 0;

void back(){ 
  analogWrite(ENA, carSpeed);
  analogWrite(ENB, carSpeed);
  digitalWrite(IN1, HIGH);
  digitalWrite(IN2, LOW);
  digitalWrite(IN3, LOW);
  digitalWrite(IN4, HIGH);
  Serial.println("Forward");
}

void forward() {
  analogWrite(ENA, carSpeed);
  analogWrite(ENB, carSpeed);
  digitalWrite(IN1, LOW);
  digitalWrite(IN2, HIGH);
  digitalWrite(IN3, HIGH);
  digitalWrite(IN4, LOW);
  Serial.println("Back");
}

void left() {
  analogWrite(ENA, carSpeed);
  analogWrite(ENB, carSpeed);
  digitalWrite(IN1, LOW);
  digitalWrite(IN2, HIGH);
  digitalWrite(IN3, LOW);
  digitalWrite(IN4, HIGH); 
  Serial.println("Left");
}

void right() {
  analogWrite(ENA, carSpeed);
  analogWrite(ENB, carSpeed);
  digitalWrite(IN1, HIGH);
  digitalWrite(IN2, LOW);
  digitalWrite(IN3, HIGH);
  digitalWrite(IN4, LOW);
  Serial.println("Right");
}

void stop() {
  digitalWrite(ENA, LOW);
  digitalWrite(ENB, LOW);
  Serial.println("Stop!");
} 

//Ultrasonic distance measurement Sub function

int Distance_test() {
  digitalWrite(Trig, LOW);   
  delayMicroseconds(2);
  digitalWrite(Trig, HIGH);  
  delayMicroseconds(20);
  digitalWrite(Trig, LOW);   
  float Fdistance = pulseIn(Echo, HIGH);  
  Fdistance= Fdistance / 58;       
  return (int)Fdistance;
  
}  

 // Path Change 
void ChangePath () { 
         
if ( R = true )  { 

      delay(1000);
      myservo.write(90);              
      delay(1000);                                                  
      myservo.write(180);              
      delay(1000); 
      leftDistance = Distance_test();
      while ( leftDistance<= 40){
        forward();
      }
      forward();
      left();
      leftDistance = Distance_test();
      while ( leftDistance<= 40){
        forward();
      }
      left();
      leftDistance = Distance_test();
      while ( leftDistance<= 40 && !(LT_M)){
        forward();
      }
      right();
}
else if ( R = false )  { 

      delay(1000);
      myservo.write(90);              
      delay(500);                         
      myservo.write(10);          
      delay(1000);      
      rightDistance = Distance_test();
      
      while ( rightDistance<= 40){
        forward();
      }
      right();
      while ( rightDistance<= 40){
        forward();
      }
      forward();
      right();
      while ( rightDistance<= 40&& !(LT_M)){
        forward();
      }
      left();
}
}

void setup () {              
    myservo.attach(3);  // attach servo on pin 3 to servo object
  Serial.begin(9600); 

  pinMode(Echo, INPUT);    
  pinMode(Trig, OUTPUT); 
  
  pinMode(LT_R,INPUT);
  pinMode(LT_M,INPUT);
  pinMode(LT_L,INPUT); 
     
  pinMode(IN1, OUTPUT);
  pinMode(IN2, OUTPUT);
  pinMode(IN3, OUTPUT);
  pinMode(IN4, OUTPUT);
  pinMode(ENA, OUTPUT);
  pinMode(ENB, OUTPUT);
  
  pinMode (BuzzPIN, OUTPUT);  
  pinMode (LEDRPIN, OUTPUT); 
  pinMode (LEDGPIN, OUTPUT); 
  stop();
  }
  
void loop() { 
    myservo.write(90);  //setservo position according to scaled value
    delay(500); 
    middleDistance = Distance_test();

    if(middleDistance <= 40) {     
      stop();
      digitalWrite (BuzzPIN, HIGH);  
      digitalWrite (LEDRPIN, HIGH); 
      digitalWrite (LEDGPIN, LOW); 
      delay(500);                         
      myservo.write(10);          
      delay(1000);      
      rightDistance = Distance_test();
      
      delay(500);
      myservo.write(90);              
      delay(1000);                                                  
      myservo.write(180);              
      delay(1000); 
      leftDistance = Distance_test();
      
      delay(500);
      myservo.write(90);              
      delay(1000);
      if(rightDistance >= leftDistance) {
        right();
        ChangePath ();
        delay(360);
      }
      
      else if(rightDistance < leftDistance) {
        left();
        R = false ;
        ChangePath ();
        delay(360);
      }

     else if((rightDistance <= 40) && (leftDistance <= 40)) {
        stop();
        digitalWrite (BuzzPIN, HIGH);  
        digitalWrite (LEDRPIN,HIGH ); 
        digitalWrite (LEDGPIN,LOW); 
        delay(180);
      }
      else {
        forward();
        digitalWrite (BuzzPIN, LOW);  
        digitalWrite (LEDRPIN,LOW ); 
        digitalWrite (LEDGPIN,HIGH); 
      }
    }  
    else {
        forward();
        digitalWrite (BuzzPIN, LOW);  
        digitalWrite (LEDRPIN,LOW ); 
        digitalWrite (LEDGPIN,HIGH); 
    }                     
}
