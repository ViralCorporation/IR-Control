#include <IRremote.h>  

int button_1 = 10;
int button_2 = 11;

//Pino A2, A3 (RELES)
int rele_1 = 16;
int rele_2 = 17;

//IR
int RECV_PIN = 15;

//Variavel que varia de acordo com valor recebido
long int armazenavalor; 

//Inicia a recepção de dados infravermelho
IRrecv irrecv(RECV_PIN);  
decode_results results; 

void setup()  
{  
  Serial.begin(9600);  
  irrecv.enableIRIn(); // Inicializa o receptor IR
}  

void loop()
{
  if (irrecv.decode(&results))  
  {  
    Serial.print("Valor lido : ");  
    Serial.println(results.value, HEX);  
    Serial.println(armazenavalor);
    armazenavalor = (results.value);  
 
  irrecv.resume(); //Le o próximo valor  
  }  
}  
