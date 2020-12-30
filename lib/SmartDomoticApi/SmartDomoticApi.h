#include <Arduino.h>
#include <ArduinoJson.h>
#include <Client.h>
#include <MQTT.h>
#include <mqtt_client.h>

#ifndef SmartDomoticApi_h
#define SmartDomoticApi_h

class SmartDomoticApi
{
public:
    SmartDomoticApi(MQTTClient *client);
    Client getClient();

private:
    char *_url;
    Client *client;
    void closeClient();
};

#endif
