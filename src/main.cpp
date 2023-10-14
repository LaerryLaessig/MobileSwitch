#include <Arduino.h>
#include <ESP8266WiFi.h>
#include <ESP8266HTTPClient.h>
#include <ESP8266HTTPClient.h>
#include <ESP8266WiFiMulti.h>

ESP8266WiFiMulti wifiMulti;
#include <wifi.h>
#include <api.h>

#define LED D5
void setup()
{
  pinMode(LED, OUTPUT);
  digitalWrite(LED, HIGH);
  Serial.begin(115200);
  while (!Serial)
  {
  }
  Serial.setTimeout(2000);

  Serial.println(WIFI_SSID);

  WiFi.mode(WIFI_STA);
  wifiMulti.addAP(WIFI_SSID, WIFI_PASSWORD);

  while (wifiMulti.run() != WL_CONNECTED)
  {

    Serial.print(".");
    delay(100);
  }
  Serial.println("");
  Serial.println("connected!");
}

void loop()
{
  WiFiClient client;
  HTTPClient http;

  Serial.println("Request remote switch");
  http.begin(client, API_ENDPOINT.c_str());

  int httpCode = http.GET();
  Serial.println(httpCode);
  if (httpCode == 200)
  {
    Serial.println("toggle switch");
    digitalWrite(LED, LOW);
    Serial.println("start deep sleep");
    ESP.deepSleep(0);
  }
}
