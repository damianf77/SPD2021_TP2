//SPD TP1, FIGUEROA Y FERNANDEZ
//https://www.tinkercad.com/things/bMZ7P5wJ4lu-spd-tp-1-dado-electronico

#define LED1 11
#define LED2 10
#define LED3 9
#define LED4 8
#define LED5 7
#define LED6 6
#define LED7 5
#define UP 4
#define DOWN 3
#define PULSADOR 2

int resultado = 0; 
int resultadoUP = 0;
int resultadoDown = 0;

int estadoSalidaUP;
int salidaBotonUP;
int estadoBotonUP;

int estadoSalidaDown;
int salidaBotonDown;
int estadoBotonDown;
  
void setup(){
  pinMode(LED1, OUTPUT);
  pinMode(LED2, OUTPUT);
  pinMode(LED3, OUTPUT);
  pinMode(LED4, OUTPUT);
  pinMode(LED5, OUTPUT);
  pinMode(LED6, OUTPUT);
  pinMode(LED7, OUTPUT);
  
  pinMode(PULSADOR, INPUT);
  pinMode(UP, INPUT);
  pinMode(DOWN, INPUT);
  Serial.begin(9600);
}

int pulsadorAntes = LOW;
int antesUp = LOW;
int antesDown = LOW;

void loop(){

int pulsadorAhora = digitalRead(PULSADOR);
int ahoraUp = digitalRead(UP);
int ahoraDown = digitalRead(DOWN);
  
  if(digitalRead(PULSADOR) == HIGH && pulsadorAntes == LOW) {
    resultado = random(1,7);
    Serial.println(resultado);

  }else if(ahoraUp == HIGH || ahoraDown == HIGH){
      
  }

  pulsadorAntes = pulsadorAhora;
  delay(50);
  
 
  switch(resultado) {
    case 1:
    digitalWrite(LED1, LOW);
    digitalWrite(LED2, LOW);
    digitalWrite(LED3, LOW);
    digitalWrite(LED4, HIGH);
    digitalWrite(LED5, LOW);
    digitalWrite(LED6, LOW);
    digitalWrite(LED7, LOW);
    break;
    
    case 2:
    digitalWrite(LED1, HIGH);
    digitalWrite(LED2, LOW);
    digitalWrite(LED3, LOW);
    digitalWrite(LED4, LOW);
    digitalWrite(LED5, HIGH);
    digitalWrite(LED6, LOW);
    digitalWrite(LED7, LOW);
    break;
    
    case 3:
    digitalWrite(LED1, HIGH);
    digitalWrite(LED2, LOW);
    digitalWrite(LED3, LOW);
    digitalWrite(LED4, HIGH);
    digitalWrite(LED5, HIGH);
    digitalWrite(LED6, LOW);
    digitalWrite(LED7, LOW);
    break;
    
    case 4:
    digitalWrite(LED1, HIGH);
    digitalWrite(LED2, LOW);
    digitalWrite(LED3, HIGH);
    digitalWrite(LED4, LOW);
    digitalWrite(LED5, HIGH);
    digitalWrite(LED6, LOW);
    digitalWrite(LED7, HIGH);
    break;
    
    case 5:
    digitalWrite(LED1, HIGH);
    digitalWrite(LED2, LOW);
    digitalWrite(LED3, HIGH);
    digitalWrite(LED4, HIGH);
    digitalWrite(LED5, HIGH);
    digitalWrite(LED6, LOW);
    digitalWrite(LED7, HIGH);
    break;
    
    case 6:
    digitalWrite(LED1, HIGH);
    digitalWrite(LED2, HIGH);
    digitalWrite(LED3, HIGH);
    digitalWrite(LED4, LOW);
    digitalWrite(LED5, HIGH);
    digitalWrite(LED6, HIGH);
    digitalWrite(LED7, HIGH);
    break; 
  }
  
  // BOTON UP
  
  if(ahoraUp == HIGH && antesUp == LOW) {
    if(resultado == 6) {
      Serial.println("El valor maximo del dado es 6");
    } else {
        resultado++;
      resultadoUP = resultado;
      Serial.println(resultadoUP);
    }
    salidaBotonUP = !salidaBotonUP;
    digitalWrite(UP, salidaBotonUP);
  }
  antesUp = ahoraUp;
  
  // BOTON DOWN
  
  if (ahoraDown == HIGH && antesDown == LOW) {
    if(resultado == 1) {
      Serial.println("El valor minimo del dado es 1");
    } else {
        resultado--;
      resultadoDown = resultado;
      Serial.println(resultadoDown);
    }
    salidaBotonDown = !salidaBotonDown;
    digitalWrite(DOWN, salidaBotonDown);
  }
  antesDown = ahoraDown;
}
