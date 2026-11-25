int buttonPin1 = 5;
int buttonPin2 = 13;
int buttonVal1;
int buttonVal2;
int LEDbright = 0;
int dt = 300;
int LEDPin = 9;
int buzzerPin = 7;


void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  pinMode(buttonPin1,INPUT);
  pinMode(buttonPin2,INPUT);
  pinMode(LEDPin,OUTPUT);
  pinMode(buzzerPin,OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
  buttonVal1 = digitalRead(buttonPin1);
  buttonVal2 = digitalRead(buttonPin2);
  Serial.print("Button 1: ");
  Serial.print(buttonVal1);
  Serial.print(",");
  Serial.print("Button 2: ");
  Serial.println(buttonVal2);
  delay(dt);

  if (buttonVal1 == 0) {
    LEDbright = LEDbright + 25;
  }

  if (buttonVal2 == 0) {
    LEDbright = LEDbright - 25;
  }

  if (LEDbright > 255) {
    LEDbright = 255;
    digitalWrite(buzzerPin,HIGH);
    delay(dt);
    digitalWrite(buzzerPin,LOW);

  }

  if (LEDbright < 0) {
    LEDbright = 0;
    digitalWrite(buzzerPin,HIGH);
    delay(dt);
    digitalWrite(buzzerPin,LOW);
  }


  analogWrite(LEDPin, LEDbright);


}