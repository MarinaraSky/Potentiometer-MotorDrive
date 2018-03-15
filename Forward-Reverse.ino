void setup()
{
  pinMode(10, OUTPUT);
  pinMode(11, OUTPUT);
  Serial.begin(9600);
}

void loop()
{
  int potench = analogRead(A1);
  int speed = map(potench, 0, 1023, 255, -255);
  if(potench >= 501 && potench <= 530){
    speed = 0;
    analogWrite(10, speed);
    analogWrite(11, speed);
  }
  if(potench <= 500){
    analogWrite(11, speed);
    analogWrite(10, 0);
  }
  else{
    speed = speed * -1;
    analogWrite(10, speed);
    analogWrite(11, 0);
  }
  Serial.print(speed);
  Serial.print(" ");
}
