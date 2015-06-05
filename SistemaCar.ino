#include <SoftwareSerial.h>

#define relayCorriente 5
#define relayArranque 6

SoftwareSerial serial1(0, 1);

boolean b1 = false;

void setup(){

  Serial.begin(9600);
  serial1.begin(9600);
  
  //pinMode(8, OUTPUT);
  //digitalWrite(8, HIGH);
  pinMode(relayCorriente, OUTPUT);
  pinMode(relayArranque, OUTPUT);
  
  digitalWrite(relayCorriente, LOW); 
  digitalWrite(relayArranque, LOW);
  
  Serial.println("SISTEMA DE SEGURIDAD DE CAR");
  
}

void loop(){
  
 if(b1){
     delay(1000);
     digitalWrite(relayArranque, LOW);
     delay(1000);
     b1 = false;
   }
   
   
 if(Serial.available()){
   
   int v = Serial.read();
   Serial.println(v);

   if(v == 48){
       digitalWrite(relayCorriente, LOW);
       delay(1000);
            b1 = false;
   }
   
   if(v == 49){
     digitalWrite(relayCorriente, HIGH);
     delay(1000);
     b1 = true;
   }
   
   if(v == 50){
       digitalWrite(relayArranque, LOW);
       delay(1000);
       
   }
   
   if(v == 51){
     digitalWrite(relayArranque, HIGH);
     delay(1000);
   }
   
 } 
 
 if(serial1.available()){
   Serial.write(serial1.read());
 }
 }
