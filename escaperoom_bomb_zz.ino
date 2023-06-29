#include <Wire.h>
#include <hd44780.h>
#include <hd44780ioClass/hd44780_I2Cexp.h>

hd44780_I2Cexp lcd;

int buzV = 0;
int minute=0, second=10;
int buzzer = 11;
int good = 0;
int star = 3;

void setup() {
  Serial.begin(115200);
  pinMode(3, INPUT);
  pinMode(4, INPUT);
  pinMode(5, INPUT);
  pinMode(6, INPUT);
  pinMode(7, INPUT);
  pinMode(8, INPUT);
  pinMode(buzzer, OUTPUT);  
  
  lcd.begin(16, 2);
  lcd.setCursor(0, 0);
  lcd.print("TIMER:");
  lcd.setCursor(0,1);
  lcd.print("***");
}

void loop() {

  if (good == 0){
    delay(1000);

    digitalWrite(buzzer,buzV);
    if(buzV == 0){
      buzV = 1;
      tone(buzzer, 277);
    }
    else{
      buzV = 0;
      noTone(buzzer);
    }
  
  if(second < 1 and minute < 1){
    good = 4;
  }
  else{
    if (second > 0) 
    {
    second--;
    }
    else if (minute > 0) 
    {
    minute--;
    second = 59;
    }
  
  lcd.setCursor(7,0);
  lcd.print("0");
  lcd.print(minute);
  lcd.print(":");
  if (second < 10) {
    lcd.print("0");
  }
  lcd.print(second);
}

if ((digitalRead(3) == LOW) and (digitalRead(4), digitalRead(5), digitalRead(6), digitalRead(7), digitalRead(8) == HIGH)){
  good = 1;
  star = star - 1;
}
else if (digitalRead(3), digitalRead(4), digitalRead(5), digitalRead(6), digitalRead(7), digitalRead(8) == HIGH){
  good = 0;
}
else{
  good = 4;
}

}

else if (good == 1){
  lcd.setCursor(star, 1);
  lcd.print(' ');  
      delay(1000);

    digitalWrite(buzzer,buzV);
    if(buzV == 0){
      buzV = 1;
      tone(buzzer, 277);
    }
    else{
      buzV = 0;
      noTone(buzzer);
    }
  
  if(second < 1 and minute < 1){
    good = 4;
  }
  else{
    if (second > 0) 
    {
    second--;
    }
    else if (minute > 0) 
    {
    minute--;
    second = 59;
    }
  
  lcd.setCursor(7,0);
  lcd.print("0");
  lcd.print(minute);
  lcd.print(":");
  if (second < 10) {
    lcd.print("0");
  }
  lcd.print(second);
}



if ((digitalRead(4) == LOW) and (digitalRead(5), digitalRead(6), digitalRead(7), digitalRead(8) == HIGH)){
  good = 2;
  star = star - 1;
}
else if (digitalRead(4), digitalRead(5), digitalRead(6), digitalRead(7), digitalRead(8) == HIGH){
  good = 1;
}
else{
  good = 4;
}
 
}

else if (good == 2){
  lcd.setCursor(star, 1);
  lcd.print(' ');  
      delay(1000);

    digitalWrite(buzzer,buzV);
    if(buzV == 0){
      buzV = 1;
      tone(buzzer, 277);
    }
    else{
      buzV = 0;
      noTone(buzzer);
    }
  
  if(second < 0 and minute < 0){
    good = 4;
  }
  else{
    if (second > 0) 
    {
    second--;
    }
    else if (minute > 0) 
    {
    minute--;
    second = 59;
    }
  
  lcd.setCursor(7,0);
  lcd.print("0");
  lcd.print(minute);
  lcd.print(":");
  if (second < 10) {
    lcd.print("0");
  }
  lcd.print(second);
}



if ((digitalRead(7) == LOW) and (digitalRead(5), digitalRead(6),  digitalRead(8) == HIGH)){
  good = 3;
  star = star - 1;
}
else if (digitalRead(4), digitalRead(5), digitalRead(6), digitalRead(7), digitalRead(8) == HIGH){
  good = 2;
}
else{
  good = 4;
}
  
}

else if (good == 3){
    lcd.clear();
    lcd.setCursor(0,0);
    lcd.print("bomb defused");
    lcd.setCursor(0,1);
    lcd.print("key is yours");
}


else if (good == 4){
    lcd.clear();
    lcd.setCursor(0,0);
    lcd.print("bomb exploded");
    lcd.setCursor(0,1);
    lcd.print("you failed");
    tone(buzzer, 277);
}
else{
  lcd.clear();
    lcd.setCursor(0,0);
    lcd.print("bomb exploded");
    lcd.setCursor(0,1);
    lcd.print("you failed");
    tone(buzzer, 277);  
}
}

//  lcd.setCursor(2, 0);
//  lcd.print(' ');
//
//  if (digitalRead(3), digitalRead(4)
//
//  
//  
//}
