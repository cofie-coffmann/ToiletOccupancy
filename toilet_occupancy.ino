#define trigpin 6
#define echopin 7

int occupied = 8;
int notoccupied = 9;

int fan = 10;
#include <LiquidCrystal.h>
LiquidCrystal lcd(12, 11, 5, 4, 3, 2);

void setup() {
  
  pinMode(trigpin,OUTPUT);
  pinMode(echopin,INPUT);
  
  pinMode(occupied,OUTPUT);
  pinMode(notoccupied,OUTPUT);

  pinMode(fan,OUTPUT);
  
  lcd.begin(16, 2);
  Serial.begin(9600);
}  

void loop() {
long duration,distance;
digitalWrite(trigpin,LOW);
  delayMicroseconds(8);
  digitalWrite(trigpin,HIGH);
     delayMicroseconds(10);
  duration = pulseIn (echopin,HIGH);
  distance = (duration*0.034/2); //calculates distance from 
Serial.print(distance);
Serial.println("cm");
delay(300);

  if (distance < 90)
{
 lcd.setCursor(0, 0);
  lcd.print("TOILET OCCUPIED");
   lcd.setCursor(0, 1);
  lcd.print("               ");
digitalWrite(occupied,LOW);
digitalWrite(notoccupied,HIGH);



}

else 
{
   
    lcd.setCursor(0, 0);
  lcd.print("    TOILET     ");
  
   lcd.setCursor(0, 1);
  lcd.print("  NOT OCCUPIED ");

  digitalWrite(occupied,HIGH);
  digitalWrite(notoccupied,LOW);

  digitalWrite(fan,HIGH);
  delay(800);
  digitalWrite(fan,LOW);
  delay(1200);
}

} 

