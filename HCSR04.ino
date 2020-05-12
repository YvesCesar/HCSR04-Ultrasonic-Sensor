#include <Ultrasonic.h> 

const int echoPin = 7; //Digital Pin Echo, que irá receber
const int trigPin = 6; //Digital Pin Trig, que irá enviar
int buzzer = 10; //Digital Pin para Buzzer

//Inicializando os pinos 
Ultrasonic ultrasonic(trigPin,echoPin); 

int distance; //Variável que irá receber valores de distância em cm
String result;  //Variável que irá converter a distance em String

void setup(){
  pinMode(echoPin, INPUT); 
  pinMode(trigPin, OUTPUT);

  //Definindo Pinos do LED: 
  pinMode(2, OUTPUT);
  pinMode(3, OUTPUT);
  pinMode(4, OUTPUT);

  //Definindo Buzzer como saída:
  pinMode(buzzer, OUTPUT);
  
  Serial.begin(9600);
  }
void loop(){
  
  ultrasonicSensor();
  Serial.print("Distance: ");
  Serial.print(result);
  Serial.println("cm"); 

  //Condição para tratar Distâncias:
  if ( distance < 21) {
    digitalWrite(2, HIGH);
    digitalWrite(3, HIGH);
    digitalWrite(4, HIGH);
    tone(buzzer, 261, 250); //Toca uma nota com buzzer
    delay(250);
    noTone(buzzer);//Para a nota
  } else {
    digitalWrite(2, LOW);
    digitalWrite(3, LOW);
    digitalWrite(4, LOW);
  }
  
}


void ultrasonicSensor(){
    digitalWrite(trigPin, LOW); 
    delayMicroseconds(2); 
    digitalWrite(trigPin, HIGH); 
    delayMicroseconds(10); 
    digitalWrite(trigPin, LOW);
    
    //Função Ranging(), faz a conversão do tempo de resposta do Echo em centímetros.
    distance = (ultrasonic.Ranging(CM)); 
    result = String(distance); 
    delay(500); 
 }
