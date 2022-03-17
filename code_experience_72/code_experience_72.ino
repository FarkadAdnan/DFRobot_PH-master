/*
 By:Farkad Adnan
 E-mail: farkad.hpfa95@gmail.com
 inst : farkadadnan
 #farkadadnan , #farkad_adnan , فرقد عدنان#
 FaceBook: كتاب عالم الاردوينو
 inst : arduinobook
 #كتاب_عالم_الاردوينو  #كتاب_عالم_الآردوينو 
 */
#include "DFRobot_PH.h"
#include <EEPROM.h>
#define PH_PIN A1
float voltage,phValue,temperature = 25;
DFRobot_PH ph;
void setup(){
    Serial.begin(115200);  
    ph.begin();
}
void loop(){
    static unsigned long timepoint = millis();
    if(millis()-timepoint>1000U){                  
        timepoint = millis();
        voltage = analogRead(PH_PIN)/1024.0*5000;  
        phValue = ph.readPH(voltage,temperature);  
        Serial.print("temperature:");
        Serial.print(temperature,1);
        Serial.print("^C  pH:");
        Serial.println(phValue,2);
    }
    ph.calibration(voltage,temperature);          
}
float readTemperature(){
}
