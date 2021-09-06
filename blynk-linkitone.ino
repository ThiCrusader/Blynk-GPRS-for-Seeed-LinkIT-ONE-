#include "common.h"

#define BLYNK_PRINT Serial

void setup()
{
  Serial.begin(115200);
  //LGPS.powerOn();
  delay(3000);
  connectNetwork();
  delay(1000);
  connectBlynk();
  Blynk.begin(client, auth);
}

void loop()
{
  delay(1500);
  if (!client.connected()) {
    connectBlynk();
    return;
  }
  Blynk.run();
 
}
