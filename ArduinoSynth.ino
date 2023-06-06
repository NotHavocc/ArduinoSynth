#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>

const int button1 = 10;
const int button2 = 5;
const int button3 = 11;
const int button4 = 8;
int countValue = 0;
long seconds;
const int led1 = 7;
const int led2 = 3;
const int led3 = 2;
const int buzz = 9;
const int pot = A0;
int freq;
int dura;
int buttonRead1;
int buttonRead2;
int buttonRead3;
int buttonRead4;

#define SCREEN_WIDTH 128
#define SCREEN_HEIGHT 64

Adafruit_SSD1306 display(SCREEN_WIDTH, SCREEN_HEIGHT, &Wire, -1);

void setup() {
  display.begin(SSD1306_SWITCHCAPVCC, 0x3C);
  display.clearDisplay();
  freq = 500;
  dura = 50;
  pinMode(button1, INPUT_PULLUP);
  pinMode(button2, INPUT_PULLUP);
  pinMode(button3, INPUT_PULLUP);
  pinMode(button4, INPUT_PULLUP);
  pinMode(led1, OUTPUT);
  pinMode(led2, OUTPUT);
  pinMode(led3, OUTPUT);
  Serial.begin(9600);
  display.clearDisplay();
  display.setTextSize(1);
  display.setTextColor(WHITE);
  display.setCursor(0, 10);
  display.print("Notes:");
  display.display();
}

void loop() {
  buttonRead1 = digitalRead(button1);
  buttonRead2 = digitalRead(button2);
  buttonRead3 = digitalRead(button3);
  buttonRead4 = digitalRead(button4);
  int potValue = analogRead(A0);
  int lastState = HIGH;
  long freqValue1 = map(potValue, 0, 1023, 0, 880);
  long freqValue2 = map(potValue, 0, 1023, 0, 988);
  long freqValue3 = map(potValue, 0, 1023, 0, 1109);

  display.clearDisplay();
  display.setTextSize(1);
  display.setTextColor(WHITE);
  display.setCursor(0, 20);
  display.print(freqValue1);
  display.setCursor(30, 20);
  display.print(freqValue2);
  display.setCursor(55, 20);
  display.print(freqValue3);
  display.setCursor(85, 20);
  display.print(seconds);
  display.setCursor(0, 10);
  display.print("Notes:");
  display.display();

  if (buttonRead1 == 0) {
    tone(buzz, freqValue1, dura);
    delay(seconds);
    digitalWrite(led1, HIGH);
  } else {
    //noTone(buzz);
    digitalWrite(led1, LOW);
  }
  if (buttonRead2 == 0) {
    tone(buzz, freqValue2, 50);
    delay(seconds);
    digitalWrite(led2, HIGH);
  } else {
    //noTone(buzz);
    digitalWrite(led2, LOW);
  }
  if (buttonRead3 == 0) {
    tone(buzz, freqValue3, 50);
    delay(seconds);
    //noTone(buzz);
    digitalWrite(led3, HIGH);
  } else {
    //noTone(buzz);
    digitalWrite(led3, LOW);
  }

  if (buttonRead4 == 0) {
    countValue++;
    Serial.println(countValue);
    delay(100);
  }
  if (countValue >= 6) {
    countValue = 0;
  }
  switch (countValue) {

    case 0:
      seconds = 0;
      break;

    case 1:
      seconds = 50;
      break;

    case 2:
      seconds = 100;
      break;

    case 3:
      seconds = 200;
      break;

    case 4:
      seconds = 500;
      break;

    case 5:
      seconds = 1000;
      break;
  }
}
