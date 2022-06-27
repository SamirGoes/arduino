const int pwm = 3;
const int pot = A0;
int ValorLidoPot_Real = 0;
int ValorLidoPot_Mapeado = 0;

int ledBranco = 11;
int ledVermelho = 10;
int ledAmarelo = 9;
int ledVerde = 8;

void setup(){
  Serial.begin(9600);
  pinMode(pwm, OUTPUT);
  pinMode(pot, INPUT);

  pinMode(ledBranco, OUTPUT);
  pinMode(ledVermelho, OUTPUT);
  pinMode(ledAmarelo, OUTPUT);
  pinMode(ledVerde, OUTPUT);
} 

void loop(){
  ValorLidoPot_Real = analogRead(pot);
  ValorLidoPot_Mapeado = map(ValorLidoPot_Real, 0, 1023, 0, 255);
  
  analogWrite(pwm, ValorLidoPot_Mapeado); 
  analogWrite(ledBranco, ValorLidoPot_Mapeado);
  
  if(ValorLidoPot_Mapeado == 0 && ValorLidoPot_Mapeado <= 85)
  {
    digitalWrite(ledVermelho, HIGH);
    digitalWrite(ledAmarelo, LOW);
    digitalWrite(ledVerde, LOW);
  }
  else if(ValorLidoPot_Mapeado > 86 && ValorLidoPot_Mapeado <= 170)
  {
    digitalWrite(ledVermelho, LOW);
    digitalWrite(ledAmarelo, HIGH);
    digitalWrite(ledVerde, LOW);
  }
  else if(ValorLidoPot_Mapeado > 171 && ValorLidoPot_Mapeado <= 255)
  {
    digitalWrite(ledVermelho, LOW);
    digitalWrite(ledAmarelo, LOW);
    digitalWrite(ledVerde, HIGH);
  }
  
  Serial.println(ValorLidoPot_Mapeado);
  Serial.println(ValorLidoPot_Real);
}
