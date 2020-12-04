// This example sends data to multiple variables to
// Ubidots through HTTP protocol.

/****************************************
 * Include Libraries
 ****************************************/

#include "Ubidots.h"

/****************************************
 * Define Instances and Constants
 ****************************************/

const char* UBIDOTS_TOKEN = "BBFF-zEblWVrq11wZUyPJ9h9GM1kiCMNO0A";  // Put here your Ubidots TOKEN
const char* WIFI_SSID = "hi";      // Put here your Wi-Fi SSID
const char* WIFI_PASS = "12345678";      // Put here your Wi-Fi password
Ubidots ubidots(UBIDOTS_TOKEN, UBI_HTTP);

/****************************************
 * Auxiliar Functions
 ****************************************/

// Put here your auxiliar functions

/****************************************
 * Main Functions
 ****************************************/

void setup() {
  Serial.begin(115200);
  ubidots.wifiConnect(WIFI_SSID, WIFI_PASS);
  // ubidots.setDebug(true);  // Uncomment this line for printing debug messages
}

void loop() {
  float value1 = random(0, 9) * 10;
  float value2 = random(0, 9) * 100;
  float value3 = random(0, 9) * 1000;
  ubidots.add("Variable1", value1);  // Change for your variable name
  ubidots.add("Variable2", value2);
  ubidots.add("Variable3", value3);

  bool bufferSent = false;
  bufferSent = ubidots.send("nodemcu");  // Will send data to a device label that matches the device Id

  if (bufferSent) {
    // Do something if values were sent properly
    Serial.println("Values sent by the device");
  }

  delay(5000);
}
