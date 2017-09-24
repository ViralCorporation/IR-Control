void setup() {
  pinMode(16, OUTPUT);
  pinMode(17, OUTPUT);
}

// the loop function runs over and over again forever
void loop() {
  digitalWrite(16, HIGH);  
  delay(1000);              
  digitalWrite(16, LOW);  
  delay(1000);
  digitalWrite(17, HIGH);  
  delay(1000);             
  digitalWrite(17, LOW);    
  delay(1000);  
}
