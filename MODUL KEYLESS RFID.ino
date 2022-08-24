byte sda = 10;
byte rst = 9;

#include<KRrfid.h>
#include<ezButton.h>

ezButton standar(4);


const int kontak=2;
const int slnida=5;
const int slnidb=6;

void setup() {
  Serial.begin(9600);
  rfidBegin();
  standar.setDebounceTime(50);
  pinMode(slnida,OUTPUT);
  pinMode(slnidb,OUTPUT);
  pinMode(kontak,OUTPUT);
  digitalWrite(kontak, HIGH);
}

void loop() {
  standar.loop();
  if (standar.isPressed())
    Serial.println("Standar Naik");
  if (standar.isReleased())
    Serial.println("Standar Turun");
    
  int stdr = standar.getState();
  if (stdr == LOW){
    
    getTAG();
    if (TAG=="118514517"){
      Serial.println("TAG : Kartu");
      TAG = "";
      if(digitalRead(kontak)==HIGH) {
      Serial.println("Raspberry Sys ON / Selenoid Narik");  
      digitalWrite(kontak,LOW);
      digitalWrite(slnida,LOW);
      digitalWrite(slnidb,HIGH);
      delay(1500);
      digitalWrite(slnidb,LOW);
      delay(1000);
    }
      else {
      Serial.println("Raspberry Sys OFF / Selenoid Dorong");
      digitalWrite(kontak,HIGH); 
      digitalWrite(slnidb,LOW);
      digitalWrite(slnida,HIGH);
      delay(1500);
      digitalWrite(slnida,LOW);
      delay(1000);
      
      Serial.println(" ");
      }
      //Serial.print("TAG : ");
      //Serial.println(TAG);  
    }
  }
}
