#include <NewPing.h>
#include <AFMotor.h> //library adafruit shield
#include <Servo.h>

#define trigPin A1 // pin trigger untuk ultrasonic di analog karena menggunakan shield
#define echoPin A2 // pin trigger untuk ultrasonic di analog karena menggunakan shield
#define maks_jarak 150
long jarak; // untuk jarak 
long durasi; // untuk durasi 

NewPing ultrasonic(trigPin, echoPin, maks_jarak);

AF_DCMotor motor1(1); // motor servo di M1
AF_DCMotor motor2(2); // motor servo di M2
AF_DCMotor motor3(3); // motor servo di M3
AF_DCMotor motor4(4); // motor servo di M4
Servo servo1; // micro servo

int SetJarak = 50;

int belok_kanan(){
servo1.write(50);
delay(300);
jarak = readPing();
servo1.write(115);
delay(300);
return jarak;
}

int belok_kiri(){
servo1.write(170);
delay(300);
jarak = readPing();
servo1.write(115);
delay(300);
return jarak;
}

int readPing(){
  delay(100);
  int cm = ultrasonic.ping_cm();
  if(cm==0)
  {
    cm = 250; 
  }
  return cm;
}

void setup() {
  
  servo1.attach(10); // menyalakan servo ke shield servo1 yaitu di pin 10
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
  Serial.begin(9600);
  servo1.write(115);


  motor1.setSpeed(80); // kecepatan masing-masing servo
  motor2.setSpeed(80); // kecepatan masing-masing servo
  motor3.setSpeed(80); // kecepatan masing-masing servo
  motor4.setSpeed(80); // kecepatan masing-masing servo

}


void loop() { 
  int jarak_kanan =0;
  int jarak_kiri =0;
  int jarak =0;
  delay(30);

  if(jarak <300){
    motor1.run(RELEASE); 
    motor2.run(RELEASE);
    motor3.run(RELEASE);
    motor4.run(RELEASE);
    delay(100);
    motor1.run(BACKWARD); // alat mundur
    motor2.run(BACKWARD);
    motor3.run(BACKWARD);
    motor4.run(BACKWARD);
    delay(200);
    motor1.run(RELEASE); 
    motor2.run(RELEASE);
    motor3.run(RELEASE);
    motor4.run(RELEASE);
    
    if(jarak_kanan == belok_kanan()){
      motor1.run(FORWARD); //alat belok kanan
      motor2.run(RELEASE);
      motor3.run(RELEASE);
      motor4.run(FORWARD);
    }else{
      motor1.run(RELEASE); //alat belok kiri
      motor2.run(FORWARD);
      motor3.run(FORWARD);
      motor4.run(RELEASE);

      motor1.run(FORWARD); //alat maju kedepan
      motor2.run(FORWARD);
      motor3.run(FORWARD);
      motor4.run(FORWARD);
  }
jarak = readPing();

}

}

  




  
  
