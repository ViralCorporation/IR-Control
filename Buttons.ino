int button_1 = 10;
int button_2 = 11;

//Pino A2, A3 (RELES)
int rele_1 = 16;
int rele_2 = 17;

void setup()  
{  
  pinMode(rele_1, OUTPUT);   
  pinMode(rele_2, OUTPUT);  
  pinMode(button_1,INPUT);
  pinMode(button_2, INPUT);

  Serial.begin(9600);
}  

void loop()
{
  if(digitalRead(button_1)== HIGH){
    Serial.println("Relé 1 -> HIGH");
    digitalWrite(rele_1, HIGH);  
  }
  else if (digitalRead(button_1)== LOW){
    Serial.println("Relé 1 -> LOW");
    digitalWrite(rele_1, LOW);  
  }

  if(digitalRead(button_2)== HIGH){
    Serial.println("Relé 2 -> HIGH");
    digitalWrite(rele_2, HIGH);  
  }
  else if (digitalRead(button_2)== LOW){
    Serial.println("Relé 2 -> LOW");
    digitalWrite(rele_2, LOW);
  }
}  
