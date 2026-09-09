#include <WiFi.h>

WiFiServer server;

void setup() {

  Serial.begin(115200);

  const String SSID = "xxxxxxxxx";  // Router SSID / Name
  const String PASSWORD = "xxxxxxxxx";         // Router Access Password

  WiFi.begin(SSID, PASSWORD);

  while (WiFi.status() != WL_CONNECTED) {
    Serial.print(".");
    delay(500);
  }

  Serial.println("WIFI Router Connected");
  Serial.println(WiFi.localIP());  // get Wifi ip address

  WiFiServer(80);  // ----> Create new Object,
                   //this is short version to Create object in C++ ( WiFiServer server = WiFiServer(80))
  server.begin();
}

void loop() {

  WiFiClient client = server.available();

  if (client) {
    client.println("HTTP/1.1 200 OK");
    client.println("Content-Type: text/html");
    client.println();

    client.println("<html>");

    client.println("<head>");
    client.println("<title>ESP 32</title>");
    client.println("<link rel=\"icon\" type=\"image/png\" href=\"https://img.icons8.com/sci-fi/48/server.png\">");
   
    // Simple CSS Design
    client.println("<style>");
    client.println("body { font-family: Arial, sans-serif; background-color: #1a1a1a; color: #ffffff; text-align: center; margin-top: 50px; }");
    client.println(".card { background-color: #2a2a2a; padding: 30px; border-radius: 10px; display: inline-block; box-shadow: 0 4px 8px rgba(0,0,0,0.3); }");
    client.println("h1 { color: #00adb5; }");
    client.println("p { color: #eeeeee; }");
    client.println("</style>");

    client.println("</head>");

    client.println("<body>");
    client.println("<div class=\"card\">");
    client.println("<h1>Hello! I'm ESP32</h1>");
    client.println("<p>Web server is running successfully.</p>");
    client.println("</div>");
    client.println("</body>");

    client.println("</html>");
    client.stop();
  }
}
