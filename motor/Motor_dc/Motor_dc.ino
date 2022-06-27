const int pwm = 3;

void setup(){
  Serial.begin(9600);
  pinMode(pwm, OUTPUT); 
}

void loop(){
  for(int x = 0; x <= 255; x++){
    analogWrite(pwm, x); 
    delay(50);
    Serial.println(x);
  }

  Serial.println("Waiting tree seconds");
  delay(3000);

  for(int x = 255; x >= 0; x--){
    analogWrite(pwm, x); 
    delay(50);
    Serial.println(x);
  }
}
