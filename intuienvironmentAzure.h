#ifndef HEADER_INTUIAZURE
  #define HEADER_INTUIAZURE
   
  //Prototype for helper_function found in HelperFunctions.cpp
  String registerSensorAzure(const char* intuiSmartHomeFunction, char* sensorId, char* sensorSecurePin, const char* functionCode);
  String getProgramFromAzure(const char* intuiSmartHomeFunction, char* sensorId, const char* functionCode);
  void sendEventToAzure(const char* intuiSmartHomeFunction, String sensorId, String event, const char* functionCode);
  void sendDataToAzure(const char* intuiSmartHomeFunction, String temperature, String humidity, String sensorId, const char* functionCode);
#endif
