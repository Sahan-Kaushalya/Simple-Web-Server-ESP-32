#include <WiFi.h>

void setup() {

  Serial.begin(115200);

  const String SSID = "";  // Router SSID / Name
  const String PASSWORD = "";         // Router Access Password

  WiFi.begin(SSID, PASSWORD);

  while (WiFi.status() != WL_CONNECTED) {
    Serial.print(".");
    delay(500);
  }

  Serial.println("WIFI Router Connected");
  Serial.println(WiFi.localIP()); // get Wifi ip address

  WiFiServer server(80); // ----> Create new Object, 
                         //this is short version to Create object in C++ ( WiFiServer server = WiFiServer(80))
  server.begin();
}

void loop() {
}
