const int analogInPin = A0;


int potVal = 0;
int speed = 0;

void setup()
{
  pinMode(9, OUTPUT);
  pinMode(6, OUTPUT);
  Serial.begin(9600);
}

void loop()
{  
  potVal = analogRead(analogInPin);
  speed = map(potVal, 0, 1023, 255, -255);
  
  Serial.print("Pot Val: ");
  Serial.print(potVal);
  if(potVal >= 501 && potVal <= 530){
    speed = 0;
    analogWrite(9, speed);
    analogWrite(6, speed);
  }
  if(potVal <= 500){
    analogWrite(9, speed);
    analogWrite(6, 0);
  }
  else{
    //if(speed < 0){
      //speed += 256;
    //}
    speed = speed * -1;
    analogWrite(6, speed);
    analogWrite(9, 0);
  }
  Serial.print("Speed: ");
  Serial.print(speed);
  delay(1000);
}