#include <Keypad.h>

int door = 13;
int value = 0;

const byte ROWS = 4;
const byte COLS = 4;


byte rowPins[ROWS] = {8, 9, 10, 11};   
byte colPins[COLS] = {7, 6, 5, 4}; 

char keys[ROWS][COLS] = {
  {'1','2','3','A'},
  {'4','5','6','B'},
  {'7','8','9','C'},
  {'*','0','#','D'}
};

Keypad keypad = Keypad(makeKeymap(keys), rowPins, colPins, ROWS, COLS);

void setup() {
  Serial.begin(9600);
  pinMode(door, OUTPUT); 
}

void loop() {
  char key;
  char buffer[5]; 
  int buttonCount = 0; 


  while (buttonCount < 4) {
    key = keypad.getKey();
    if (key) {
      buffer[buttonCount] = key;
      Serial.print("Button ");
      Serial.print(buttonCount + 1);
      Serial.print(": ");
      Serial.println(key);
      buttonCount++;

    }
  }

  String s1(buffer);
  s1.trim();
  s1.replace("?", "");
  Serial.print("Result: ");
  Serial.println(s1);
  Serial.println("-------------");

  if (s1.toInt() == 7412) {
    Serial.println("confirmed");
    digitalWrite(door, HIGH);
    delay(750);
    digitalWrite(door, LOW);
  }

  while (keypad.getKey()) {

  }
}
