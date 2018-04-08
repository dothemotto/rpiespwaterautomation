/*Automatizare pompa
  Citeste valorile de pe un senzor de umiditate cu valori cuprinse intre
  <400 - pamant umed
  >850 && <980 - pamant uscat
  >980 - senzor intrerupt 
*/
#include <RCSwitch.h>

//Definire senzor umiditate
float umidSensor = A0;
int RFPower = 4; 

RCSwitch mySwitch = RCSwitch();

void setup() {

  Serial.begin(9600);
  
  // Transmitter is connected to Arduino Pin #10  
  mySwitch.enableTransmit(10);
  pinMode(RFPower,OUTPUT);
  digitalWrite(RFPower,HIGH);
 
}

void loop() {


  if((analogRead(umidSensor) > 850) && (analogRead(umidSensor) < 950))
    {
      Serial.println("Pamant uscat!");
     /* See Example: TypeA_WithDIPSwitches */
      mySwitch.switchOn("11111", "01000");
      delay(50); 
    }
   else if ((analogRead(umidSensor) > 150) && (analogRead(umidSensor) < 400))
   {
      Serial.println("Pamant ud!");
      mySwitch.switchOff("11111", "01000");
      delay(50);
   }
    else if ((analogRead(umidSensor) < 150) || (analogRead(umidSensor) > 950))
    {
      Serial.print("Eroare: Valoare senzor in scurt sau afara din pamant pompa se va opri: ");
      Serial.println(analogRead(umidSensor));
      mySwitch.switchOff("11111", "01000");
      delay(50);
    }

  delay(2000);
}
