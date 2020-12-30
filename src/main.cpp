#include <Arduino.h>
#include <WiFi.h>
#include <PubSubClient.h>
#include <WiFiClient.h>

const char *ssid = "CONNECT_MARIVALDA";
const char *pass = "marivaldanet";
const char *brokerUser = "nerdbroz2@gmail.com";
const char *brokerPass = "";
const char *broker = "mqtt.dioty.co";

WiFiClient espClient;
PubSubClient client(espClient);

void setupWifi()
{
  delay(100);
  Serial.print("\nConnecting to");
  Serial.println(ssid);

  WiFi.begin(ssid, pass);
  while (WiFi.status() != WL_CONNECTED)
  {
    delay(100);
    Serial.print(".");
  }
  Serial.print("\nConnected to");
  Serial.println(ssid);
}

void reconnect()
{
  while (!client.connected())
  {
    Serial.print("\nConnecting to");
    Serial.println(broker);
    if (client.connect("koikoikoi", brokerUser, brokerPass))
    {
      Serial.print("\nConnected to");
      Serial.println(broker);
    }
    else
    {
      Serial.println("\nTrying connect again");
      delay(5000);
    }
  }
}

void setup()
{
  Serial.begin(115200);
  setupWifi();
  client.setServer(broker, 1883);
}

void loop()
{
  // put your main code here, to run repeatedly:
  if (!client.connected())
  {
    reconnect();
  }
  client.loop();
}