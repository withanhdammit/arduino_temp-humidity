# arduino_thermohygrometer
Uses the WeMos D1 R2 board and a DHT22 thermo-hygrometer sensor.  The boards are available all over the internet
Amazon's choice for the WeMos D1 R2
https://www.amazon.com/dp/B01C6Y5SKY

Amazon's choice for the DHT22
https://www.amazon.com/dp/B0795F19W6

Amazon's choice for breadboard jumpers
https://www.amazon.com/dp/B01L5UKAPI

Connect the DHT22 + to a 3.3V pin
Connect the DHT22 - to a GND pin
Connect the DHT22 data to pin 8 on the D1 board

Create a free account on https://iotinabox.mydevices.com/home/signup

Add a new device and record the username, password, and clientID
Substitute it in the proper location in the code

You may need to add the ESP8266 board to the Arduino IDE, a good tutorial is here:
https://randomnerdtutorials.com/how-to-install-esp8266-board-arduino-ide/

Set the board options to:
Board:        WeMos D1
Upload speed: 115200
CPU freq:     80 MHz
Flash size:   4M (3M SPIFFS)
Upload using: Serial

You'll need these libraries:
CayenneMQTT
ESP8266WiFi
DHT_sensor_library
Adafruit_Unified_Sensor

Enter your wifi SSID & wifiPassword into the code

Push to the device using the Arduino IDE

