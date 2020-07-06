
#define BLYNK_PRINT Serial
#include <Ultrasonic.h>

#include <SPI.h>
#include <WiFi101.h>
#include <BlynkSimpleMKR1000.h>

String loc = "12.9854628,80.6578416"

// You should get Auth Token in the Blynk App.
// Go to the Project Settings (nut icon).
char auth[] = "Enter Auth token";

// Your WiFi credentials.
// Set password to "" for open networks.
char ssid[] = "SSID";
char pass[] = "p@ss";

BlynkTimer timer;
int distance = 0;
int thresh[3] = {25, 50, 75};
Ultrasonic ultrasonic(12, 13);

WidgetLED green(V1);
WidgetLED orange(V2);
WidgetLED red(V3);



void setup()
{
  // Debug console
  Serial.begin(9600);
  Blynk.begin(auth, ssid, pass);
  
}

void loop()
{
  distance = ultrasonic.distanceRead();
  Serial.println(distance);
  Blynk.run();

  if(distance<thresh[0]){
    green.on();
    }
  else if(distance<thresh[1])
    green.on();
    orange.on();
  }
  else if(distance<thresh[2])
    green.on();
    orange.on();
    red.on();
    Blynk.virtualWrite(V3,loc); // Shows location of the filled bin
  }
  else{
    green.off();
    orange.off();
    red.off();
  delay(100);
}

