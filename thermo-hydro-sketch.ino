// Make sure you install the ESP8266 Board Package via the Arduino IDE Board Manager and select the correct ESP8266 board before compiling. 

//#define CAYENNE_DEBUG
#define CAYENNE_PRINT Serial
#include <CayenneMQTTESP8266.h>
#include <DHT.h>
#include <DHT_U.h>
#define DHTPIN 0 //This is PIN D8 on the board
#define DHTTYPE DHT11
DHT_Unified dht(DHTPIN, DHTTYPE);

// WiFi network info.
char ssid[] = "your_ssid";
char wifiPassword[] = "your_wifiPassword";

unsigned long lastMillis = 0;

// Cayenne authentication info. This should be obtained from the Cayenne Dashboard.
char username[] = "your_username";
char password[] = "your_password";
char clientID[] = "your_clientID";

void setup() {
  Serial.begin(9600);
  Cayenne.begin(username, password, clientID, ssid, wifiPassword);
  dht.begin();
  sensor_t sensor;
}

void loop() {
  Cayenne.loop();
  //Publish data every 30 seconds (30000 milliseconds). Change this value to publish at a different interval.
  if (millis() - lastMillis > 30000) {
    lastMillis = millis();
    float seconds = (lastMillis / 1000);
    //float minutes = (seconds / 60);
    //float hours = (minutes / 60);
    //float days = (hours / 24);
    float days = (seconds / 86400);
    //Write data to Cayenne here. This example just sends the current uptime in milliseconds.
    //Cayenne.virtualWrite(0, minutes);
    Cayenne.virtualWrite(0, days);

    sensors_event_t event;  
    dht.temperature().getEvent(&event);
    //Cayenne.celsiusWrite(1, event.temperature);
    Cayenne.virtualWrite(1, C2F(event.temperature), "temp", "f");
    dht.humidity().getEvent(&event);
    Cayenne.virtualWrite(2, event.relative_humidity, "rel_hum", "p");
  }
}

//Default function for processing actuator commands from the Cayenne Dashboard.
//You can also use functions for specific channels, e.g CAYENNE_IN(1) for channel 1 commands.
CAYENNE_IN_DEFAULT()
{
  CAYENNE_LOG("CAYENNE_IN_DEFAULT(%u) - %s, %s", request.channel, getValue.getId(), getValue.asString());
  //Process message here. If there is an error set an error message using getValue.setError(), e.g getValue.setError("Error message");
}

// Convert C to F
double C2F(double celsius)
{
  return 1.8 * celsius + 32;
}
