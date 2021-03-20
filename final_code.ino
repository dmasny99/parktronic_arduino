#include <LiquidCrystal.h>


#define green 4
#define yellow 3
#define red 2
#define trig 5 // поменял местами с эхо
#define echo 6 // поменял местами с триг
#define piezo 7

LiquidCrystal lcd(8,9,10,11,12,13); // поменял аргументы функции

void setup()
{
  pinMode(green, OUTPUT);
  pinMode(yellow, OUTPUT);
  pinMode(red, OUTPUT);
  pinMode(trig, OUTPUT);
  pinMode(echo, INPUT); 
  pinMode(piezo, OUTPUT);
  lcd.begin(16, 2); 
  lcd.print("distance="); 
  Serial.begin(9600);
}

void loop()
{
  
  long duration, distance;
  digitalWrite(trig, LOW);
  delayMicroseconds(2);
  digitalWrite(trig, HIGH); // поменял на хай
  delayMicroseconds(10);
  digitalWrite(trig, LOW);
  duration = pulseIn(echo, HIGH);
  distance = duration / 58,2;
  lcd.setCursor(9, 0); // ок
  lcd.println(distance); // убрал ln
  lcd.print(" cm   "); //
  lcd.setCursor(0, 1);
  lcd.print("        ");
  if (distance < 120) {
    digitalWrite(piezo, HIGH);
    digitalWrite(green, LOW);
    lcd.setCursor(0, 1);
    lcd.print("Caution!");
    if (distance < 60){
      digitalWrite(red, HIGH);
    } 
    else {
      digitalWrite(yellow, HIGH);
    }
    delay(distance * 4);
    digitalWrite(red, LOW);
    digitalWrite(yellow, LOW);
    digitalWrite(piezo, LOW);
    delay(distance * 4);
  } 
  else {
    digitalWrite(green, HIGH);
    digitalWrite(yellow, LOW);
    digitalWrite(red, LOW);
    digitalWrite(piezo, LOW);
    delay(1000);
  }
  Serial.print("distance="); // добавил строчку по тз
  Serial.print(distance);
  Serial.println(" cm");
}