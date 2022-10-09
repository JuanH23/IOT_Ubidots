// This example retrieves last value of a variable from the Ubidots API
// using HTTP protocol.

/****************************************
 * Include Libraries
 ****************************************/

#include "Ubidots.h"

/****************************************
 * Define Constants
 ****************************************/

const char* UBIDOTS_TOKEN = "BBFF-B3opm3LHhAYXD5KlZcGkIggTt0VuFB";                                     // Put here your Ubidots TOKEN
const char* WIFI_SSID = "AZXY";                                         // Put here your Wi-Fi SSID
const char* WIFI_PASS = "1000940167";                                         // Put here your Wi-Fi password
//const char* DEVICE_LABEL_TO_RETRIEVE_VALUES_FROM = "weather-station";  // Replace with your device label
//const char* VARIABLE_LABEL_TO_RETRIEVE_VALUES_FROM = "humidity";       // Replace with your variable label

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
  // ubidots.setDebug(true); //Uncomment this line for printing debug messages
}

void loop() {
  float value1=random(0 , 9) * 10;
  float value2=random(0 , 9) * 100;
  float value3=random(0 , 9) * 1000;
  ubidots.add("Variable_Name_One",value1);
  ubidots.add("Variable_Name_Two",value2);
  ubidots.add("Variable_Name_Three",value3);
  
  bool bufferSent=false;
  bufferSent= ubidots.send();
  if(bufferSent){
    Serial.print("Values sent by the device");
  }

  delay(5000);
}