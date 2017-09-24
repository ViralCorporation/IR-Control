#include <EEPROM.h>
#include <IRremote.h>  

// Definição de pino TSOP
int RECV_PIN = 11;

//Pino A2, A3 (RELES)
int rele_1 = 12;
int rele_2 = 13;

//Buttons
int button_1 = 15;
int button_2 = 11;

//Tempo para que receba apenas um valor.
unsigned long last = 0;

//Contadores de Estado
int state_1 = 0;
int state_2 = 0;

//Endereços
//Relé 1
int address_rele_1 = 0;
//Relé 2
int address_rele_2 = 1;
//Tecla 1
int address_key_1 = 2;
//Tecla 2
int address_key_2 = 6;


//Inicia a recepção de dados infravermelho
IRrecv irrecv(RECV_PIN); 
decode_results results;

void setup(){  
  pinMode(rele_1, OUTPUT);   
  pinMode(rele_2, OUTPUT);  
  pinMode(button_1,INPUT);
  pinMode(button_2, INPUT);
  
  Serial.begin(9600);
  irrecv.enableIRIn(); // Start the receiver 

  digitalWrite(rele_1, EEPROM.read(address_rele_1));
  digitalWrite(rele_2, EEPROM.read(address_rele_2));
  
}

void loop(){
  if(irrecv.decode(&results) && millis() - last > 150)
  {
    if(results.value > 0xFFFFF)
    {
      if (digitalRead(button_1) == HIGH)
      {
        reprograming_1(results.value);
      }
      else if (digitalRead(button_2) == HIGH)
      {
        reprograming_2(results.value);
      }
      else
      { 
        checkUpNewEntries(results.value);
      }
    }
    else
    {
      last = millis()+2000;
    }
   
    last = millis();
    //Leia o próximo valor.
    irrecv.resume(); 
  }
} 

void swap_state_Rele_1(){
  state_1 ^= 1;
  EEPROM.write(address_rele_1, state_1);
  digitalWrite(rele_1, state_1);
  
  Serial.print("Rele 1 alterado: ");
  Serial.println(state_1,BIN);
}

void swap_state_Rele_2(){
  state_2 ^= 1;
  EEPROM.write(address_rele_2, state_2);
  digitalWrite(rele_2, state_2);
  
  Serial.print("Rele 2 alterado: ");
  Serial.println(state_2,BIN);
}

void reprograming_1(unsigned long int armazenavalor){
    //Recebe tecla do controle remoto.
    unsigned long int key_1 = armazenavalor;
    
    // escreve o valor da tecla um correspondente a 32bits na eeprom
    EEPROMWritelong(address_key_1, key_1);

    Serial.print("Tecla armazenada: ");
    Serial.println(armazenavalor,HEX);
    
    Serial.println("Tecla 1 alterada.");
}

void reprograming_2(unsigned long int armazenavalor){
    //Recebe tecla do controle remoto.
    unsigned long int key_2 = armazenavalor;
    
    // escreve o valor da tecla um correspondente a 32bits na eeprom
    EEPROMWritelong(address_key_2, key_2);

    Serial.print("Tecla armazenada: ");
    Serial.println(armazenavalor,HEX);
    
    Serial.println("Tecla 2 alterada.");
}

void checkUpNewEntries(unsigned long int armazenavalor){
  //Lê da EEPROM as teclas cadastradas para comparação.
  unsigned long int key_1 = EEPROMReadlong(address_key_1);
  unsigned long int key_2 = EEPROMReadlong(address_key_2);
  
  Serial.print("Tecla recebida: ");
  Serial.println(armazenavalor,HEX);
  
    if(armazenavalor == key_1){
      swap_state_Rele_1();
    }
    if(armazenavalor == key_2){
      swap_state_Rele_2();
    }
}

//This function will write a 4 byte (32bit) long to the eeprom at
//the specified address to address + 3.
void EEPROMWritelong(int address, long value){
  //Decomposition from a long to 4 bytes by using bitshift.
  //One = Most significant -> Four = Least significant byte
  byte four = (value & 0xFF);
  byte three = ((value >> 8) & 0xFF);
  byte two = ((value >> 16) & 0xFF);
  byte one = ((value >> 24) & 0xFF);
  
  //Write the 4 bytes into the eeprom memory.
  EEPROM.write(address, four);
  EEPROM.write(address + 1, three);
  EEPROM.write(address + 2, two);
  EEPROM.write(address + 3, one);
}

long EEPROMReadlong(long address){
  //Read the 4 bytes from the eeprom memory.
  long four = EEPROM.read(address);
  long three = EEPROM.read(address + 1);
  long two = EEPROM.read(address + 2);
  long one = EEPROM.read(address + 3);
  
  //Return the recomposed long by using bitshift.
  return ((four << 0) & 0xFF) + ((three << 8) & 0xFFFF) + ((two << 16) & 0xFFFFFF) + ((one << 24) & 0xFFFFFFFF);
}

