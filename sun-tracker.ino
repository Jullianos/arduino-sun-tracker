#include <Servo.h>

Servo horizontal;
float servoh = 90;

Servo vertical;
float servov = 90;

int ldrlt = 0; // LDR top left
int ldrrt = 3; // LDR top rigt
int ldrld = 2; // LDR down left
int ldrrd = 1; // LDR down rigt
int ldrc = 5; // LDR center

int lt, rt, ld, rd, c;
int dtime = 5, tol = 20;
int avt, avd, avl, avr;
int dhoriz, dvert;

void setup()
{
  horizontal.attach(9); 
  vertical.attach(8);
}

void mhorizontal() {
  if (avl > avr){
      servoh = servoh - 0.1;
      if (servoh < 0){
        servoh = 0;
      }
    }
    else if (avl < avr){
      servoh = servoh + 0.1;
      if (servoh > 180){
        servoh = 180;
      }
    }
    else if (avl == avr){
      
    }
    horizontal.write(servoh);
}

void mvertical() {
  if (avt > avd){
      servov = servov - 0.1;
      if (servov > 180){
        servov = 180;
      }
    }
    else if (avt < avd){
      servov= servov + 0.1;
      if (servov < 0){
        servov = 0;
      }
    }
    vertical.write(servov);
}

void loop() 
{
  lt = analogRead(ldrlt);
  rt = analogRead(ldrrt);
  ld = analogRead(ldrld);
  rd = analogRead(ldrrd);
  c = analogRead(ldrc);
  
  avt = (lt + rt) / 2; // average value top
  avd = (ld + rd) / 2; // average value down
  avl = (lt + ld) / 2; // average value left
  avr = (rt + rd) / 2; // average value right
  
  dhoriz = avt - avd; // check the diffirence of up and down
  dvert = avl - avr;// check the diffirence og left and rigt

  if (c >= 400) {
    
  } else {
    if (tol > dvert || dvert > tol){ // check if the diffirence is in the tolerance else change vertical angle
      mvertical();
    }
  
    if (tol > dhoriz || dhoriz > tol) {// check if the diffirence is in the tolerance else change horizontal angle
      mhorizontal();
    } 
  }
  
  delay(dtime);
}
