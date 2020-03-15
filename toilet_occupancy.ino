// ---------------------------Libarires-----------------------------------//
#include <LiquidCrystal.h>
// -------------------Declaration of variables----------------------------//

// Ultrasonic
#define trigpin 6
#define echopin 7
// notifying LEDs
int occupiedLed = 8;
int notoccupiedLed = 9;
// ventilation
int fanRelay = 10;
// LCD display
LiquidCrystal lcd(12, 11, 5, 4, 3, 2);

void setup() {
  // setup Code
  pinMode(trigpin,OUTPUT);
  pinMode(echopin,INPUT);
  
  pinMode(occupiedLed,OUTPUT);
  pinMode(notoccupiedLed,OUTPUT);

  pinMode(fanRelay,OUTPUT);
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
distance = (duration*0.034/2);
Serial.print(distance);   // distance in cm
Serial.println("cm");
delay(300);

if (distance < 90){
 lcd.setCursor(0, 0);
 lcd.print("TOILET OCCUPIED");
 lcd.setCursor(0, 1);
 lcd.print("          ");
 digitalWrite(occupiedLed,LOW);
 digitalWrite(notoccupiedLed,HIGH);
  }
else 
  {
  lcd.setCursor(0, 0);
  lcd.print("    TOILET     ");
  lcd.setCursor(0, 1);
  lcd.print("  NOT OCCUPIED ");
  digitalWrite(occupiedLed,HIGH);
  digitalWrite(notoccupiedLed,LOW);
  digitalWrite(fanRelay,HIGH);
  delay(1000);
  digitalWrite(fanRelay,LOW);
  delay(1000);
  }
} 
