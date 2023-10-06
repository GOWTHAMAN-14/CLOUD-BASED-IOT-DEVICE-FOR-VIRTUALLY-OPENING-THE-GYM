#include <ESP8266WiFi.h>
#include <ThingSpeak.h>
#include <WiFiClient.h>
int relay = 2;
const char* ssid = ".."; //Your Network SSID
const char* password = "12345678"; //Your Network Password
unsigned long mychannel = 1369831;
const char* mywriteapikey = "5OCYB4N7LXKC5GY0";
const char* myreadapikey = "VB1LDQJA8MF2Y4RI";
WiFiClient client;
void setup(){
  Serial.begin(115200);
  delay(100);
  pinMode(relay,OUTPUT);
  pinMode(relay,HIGH);
  WiFi.hostname("ESP-host");
  WiFi.begin(ssid,password);
  ThingSpeak.begin(client);
}
void loop(){
  int Motor_1 = ThingSpeak.readFloatField(mychannel,1,myreadapikey);
  if(Motor_1 == 1){
    digitalWrite(relay,LOW);
  }
   else if (Motor_1 == 0) {
    digitalWrite(relay,HIGH);
  }
}
