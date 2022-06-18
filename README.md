# DFRobot_PH-master
Arduino library for Gravity: Analog pH Sensor / Meter Kit V2, SKU: SEN0161-V2

Chapter 3 code_Project_72 The second part 2 of "The Arduino World Book" code_Project_72
 
- code_Project_72
-  By:Farkad Adnan فرقد عدنان - 
 -E-mail: farkad.hpfa95@gmail.com 
-inst : farkadadnan 
- #farkadadnan , #farkad_adnan , فرقد عدنان# 
- FaceBook: كتاب عالم الاردوينو 
- inst : arduinobook
1. #كتاب_عالم_الاردوينو
2. #كتاب_عالم_الآردوينو
* facebook : https://www.facebook.com/profile.php?id=100002145048612
* instagram:  https://www.instagram.com/farkadadnan/
* linkedin : https://www.linkedin.com/in/farkad-adnan-499972121/

 <p>
 <a href='https://mobile.twitter.com/farkadadnan'>
        <img alt="Twitter Follow" src="https://img.shields.io/twitter/follow/farkadadnan?label=%40farkadadnan&style=social" alt='Twitter' align="center"/>
    </a>
</p>


![SEN0161-V2](https://user-images.githubusercontent.com/35774039/158898998-77b665b1-97e5-410d-836c-3a0ddc83e2ae.png)

# Summary
Analog pH meter V2 is specifically designed to measure the pH of the solution and reflect the acidity or alkalinity. DFRobot ph sensor is commonly used in various applications such as aquaponics, aquaculture, and environmental water testing.

![aa](https://user-images.githubusercontent.com/35774039/158899243-c2ebfa61-9da8-4dee-a860-f17f263c5e0f.JPG)

# enterph 
1. Input enterph command in the serial monitor to enter the calibration mode.
![3](https://user-images.githubusercontent.com/35774039/158907930-ff4285b2-6082-4ca5-a78a-9ef169ea0353.JPG)

2.Input calph commands in the serial monitor to start the calibration. The program will automatically identify which of the two standard buffer solutions is present: either 4.0 and 7.0. In this step, the standard buffer solution of 7.0 will be identified.
![4](https://user-images.githubusercontent.com/35774039/158907955-fc8624a2-4f2a-40f9-8150-05cebf909038.JPG)

3. After the calibration, input exitph command in the serial monitor to save the relevant parameters and exit the calibration mode. Note: Only after inputing exitph command in the serial monitor can the relevant parameters be saved.
![5](https://user-images.githubusercontent.com/35774039/158907974-90209d52-295c-441c-84ad-a86dcf3731c7.JPG)

```
//By:Farkad Adnan
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
```
