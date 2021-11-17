//SPD TP2, FIGUEROA Y FERNANDEZ

#include<LiquidCrystal.h>
#include<Servo.h>


Servo servoHours; 
Servo servoMinutes; 
Servo servoSeconds; 

//Display LiquidCrystal(rs, e, d4, d5, d6, d7);
LiquidCrystal display(2, 4, 7, 8, 12, 13);




void setup()
{
  //Serial.begin(9600);
  display.begin(16, 2);
  servoSeconds.attach(3);
  servoMinutes.attach(5);
  servoHours.attach(6);  
  for(int i=9; i<=11; i++){
    pinMode(i, OUTPUT);
    digitalWrite(i, LOW);
  }  
}

//variables de tiempo
int hours = 0;
int minutes = 0;
int seconds = 0;
long currentMillis = 0;
long previousMillis = 0;  

int secondsAngle;
int minutesAngle;
int hoursAngle;
int secButton;
int minButton;
int hourButton;
int secButtonBefore = LOW;
int minButtonBefore = LOW;
int hourButtonBefore = LOW;

void loop()
{
  showDisplay();
  
  watch(); 
 
  engines();

  buttons();
  
  
  delay(20);
}
//------------------------------------------------------------------------


//Watch counter function
void watch(){
   currentMillis = millis();
  
  if(currentMillis - 1000 > previousMillis){
    seconds++;
    previousMillis = currentMillis;    
  }
  
  if(seconds == 60){
    minutes++;
    seconds = 0;
  }
  
  if(minutes == 60){
    hours++;
    minutes = 0;
   }
  
  if(hours == 24){
    hours = 0;
  }
}

//Engines function
void engines(){
  
  secondsAngle = seconds*3;
  servoSeconds.write(secondsAngle);
  
  minutesAngle = minutes*3; 
  servoMinutes.write(minutesAngle);
  
  hoursAngle = map(hours, 0, 23, 180, 0);    
  servoHours.write(hoursAngle);  
}

//Watch display funtion: no recibe nada, modifica la variable global
void showDisplay(){
  
	display.setCursor(8,1);
  
    if(seconds < 10)
    {

      display.print(":");
      display.print(00);
      display.print(seconds);
    }
  	else	if(seconds != 60)
    {

      display.print(":");
      display.print(seconds);
    }

  	display.setCursor(5,1);

  	if(minutes < 10)
    {
      display.print(":");
      display.print(00);
      display.print(minutes);
    }
  	else if(minutes != 60)
    {
      display.print(":");
      display.print(minutes);
    }

    display.setCursor(3,1);

    if(hours < 10)
    {
      display.print(00);
      display.print(hours);
    }
  	else if(hours != 24)
    { 
      display.print(hours);
    }
}


//Buttons function
void buttons(){
  
  secButton = digitalRead(9);
  if(secButton == HIGH && secButtonBefore == LOW){
    seconds++;
  }
  
  minButton = digitalRead(10);
  if(minButton == HIGH && minButtonBefore == LOW){
    minutes++;
  }
  
  hourButton = digitalRead(11);
  if(hourButton == HIGH && hourButtonBefore == LOW){
    hours++;
  }
  secButtonBefore = secButton;  
  minButtonBefore = minButton;  
  hourButtonBefore = hourButton;
}


