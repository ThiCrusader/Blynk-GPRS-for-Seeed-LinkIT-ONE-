#include <LGPRS.h>
#include <LGPRSClient.h>
#include <LGPRSServer.h>
//#include <LTcpClient.h>
#include <LBattery.h>
#include <LGPS.h>
#include <BlynkSimpleStream.h>
#include <SPI.h>

LGPRSClient client;

//GSM-GPRS Network
const char APN[] = "apn.network.com";
const char APN_USER[] = "";
const char APN_PASSWORD[] = "";

// Blynk server
char host[] = "blynk.server.com";
unsigned int port = 8080;
const char auth[] = "EjSFv5l7-oljm8rEVnOoYTdD_nIslASo";

void connectNetwork()
{
  Serial.println("Connecting to GPRS network.");
  while (!LGPRS.attachGPRS(APN, APN_USER, APN_PASSWORD))
  {
    delay(500);
  }
  delay(3000);
}

void connectBlynk()
{
  Serial.print("Connect to ");
  Serial.println(host);
  if (client.connect(host, port))
  {
    Serial.println("Blynk connected");
    delay(3000);
  }
  else
  {
    Serial.println("Blynk connection failed");
    delay(3000);
  }
}
