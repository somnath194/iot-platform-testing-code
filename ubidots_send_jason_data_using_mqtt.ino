/******************************************
 *
 * This example works for both Industrial and STEM users.
 * If you are using the old educational platform,
 * please consider to migrate your account to a STEM plan
 *
 * ****************************************/

/****************************************
 * Include Libraries
 ****************************************/
#include "UbidotsESPMQTT.h"

/****************************************
 * Define Constants
 ****************************************/
#define TOKEN "BBFF-zEblWVrq11wZUyPJ9h9GM1kiCMNO0A"     // Your Ubidots TOKEN
#define WIFINAME "hi"  // Your SSID
#define WIFIPASS "12345678"  // Your Wifi Pass

Ubidots client(TOKEN);

/****************************************
 * Auxiliar Functions
 ****************************************/

void callback(char* topic, byte* payload, unsigned int length) {
  Serial.print("Message arrived [");
  Serial.print(topic);
  Serial.print("] ");
  for (int i = 0; i < length; i++) {
    Serial.print((char)payload[i]);
  }
  Serial.println();
}

/****************************************
 * Main Functions
 ****************************************/

void setup() {
  // put your setup code here, to run once:
  Serial.begin(115200);
  client.setDebug(true);  // Pass a true or false bool value to activate debug messages
  client.wifiConnection(WIFINAME, WIFIPASS);
  client.begin(callback);
}

void loop() {
  // put your main code here, to run repeatedly:
  if (!client.connected()) {
    client.reconnect();
  }

  // Publish values to 2 different data sources

  float value1 =random(40);
  client.add("val",value1);
  client.ubidotsPublish("nodemcu");
  client.loop();
  delay(5000);
}
