#ifndef HEADER_INTUISETTINGS
#define HEADER_INTUISETTINGS

#define sensorPin A0
char* ssid = "UPC5292678";
const char* password = "#secret#";
char* ssid2 = "kbu.freifunk.net";
const char* password2 = "";
char* ssid3 = "jLn70750";
const char* password3 = "#secret#";

const char* intuiSmartHomeFunction = "intuicosmostest1.azurewebsites.net";
const char* smartHeatingApi = "smartheatingapi.azurewebsites.net"; 

const char* functionCodeRegister = "#secret#";
const char* functionCodePostDeviceEvent = "#secret#";
const char* functionCodePostSensorData = "#secret#";
const char* functionCodeGetActiveProgram = "#secret#";

char* sensorId = "00000000-0000-0000-0000-000000000005";
char* sensorSecurePin = "0000";

bool disableManualTemperature = true;
//float schmittTriggerDelta = 0.2;

#endif
