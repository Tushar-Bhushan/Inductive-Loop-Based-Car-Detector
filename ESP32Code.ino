#define BLYNK_TEMPLATE_ID "TMPL3H-oy1mU2"
#define BLYNK_TEMPLATE_NAME "Quickstart Template"
#define BLYNK_AUTH_TOKEN "KbAZB0Fz3tsz65TL7JS1SCkeHgmuKHBo"

 /* Comment this out to disable prints and save space */
 #define BLYNK_PRINT Serial

 // My variables for Serial Transmission
 #define RXp 3
 #define TXp 1
 String park_string;
 int park_status;

 #include <WiFi.h>
 #include <WiFiClient.h>
 #include <BlynkSimpleEsp32.h>

 // Your WiFi credentials.
 // Set password to "" for open networks.
 char ssid[] = "iQOO_9T_Sahil";
 char pass[] = "nhibtarha";

 BlynkTimer timer;

 // This function is called every time the Virtual Pin 0 statechanges
BLYNK_WRITE(V0)
{
 // Set incoming value from pin V0 to a variable
 int value = param.asInt();
 // Update state
Blynk.virtualWrite(V1, value);
 }
 BLYNK_CONNECTED()

{
// Change Web Link Button message to "Congratulations!"
Blynk.setProperty(V3, "offImageUrl", "https://static-image.nyc3.cdn.digitaloceanspaces.com/general/fte/congratulations.png");
Blynk.setProperty(V3, "onImageUrl", "https://static-image.nyc3.cdn.digitaloceanspaces.com/general/fte/congratulations_pressed.png");
Blynk.setProperty(V3, "url", "https://docs.blynk.io/en/getting-started/what-do-i-need-to-blynk/how-quickstartdevice-was-made");
}

// This function sends Arduino’s uptime every second toVirtual Pin 2.
void myTimerEvent()
 {
// You can send any value at any time.
// Please don’t send more that 10 values per second.
Blynk.virtualWrite(V2, millis() / 1000);
}

void setup()
 {
Serial.begin(115200);
Serial2.begin(9600, SERIAL_8N1, RXp, TXp);
 Blynk.begin(BLYNK_AUTH_TOKEN, ssid, pass);

// Setup a function to be called every second
timer.setInterval(1000L, myTimerEvent);
 }

void loop()
 {
 Blynk.run();
 timer.run();
 park_string=Serial2.readString();
park_string.trim();
Serial.println(park_string);
 if(park_string=="Empty")
{
 park_status=0;

}
else if(park_string=="Parked")
 {
park_status=1;
 }
 else
{
park_status=8;
 }
 Serial.println(park_status);
 Blynk.virtualWrite(V1,park_status);
 Blynk.virtualWrite(V1,park_status);
 }
