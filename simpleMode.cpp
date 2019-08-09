#include "Arduino.h"
#include <ArduinoJson.h>
#include <Encoder.h>
#include <Time.h>
#include <TimeLib.h>

float simpleModeProgramStr(String programStr)
{
  float targetTemp = 5.0f;
  Serial.println("simpleModeProgramStr entered.");
  Serial.println("parsing program: " + programStr);
  StaticJsonBuffer<1500> JSONBuffer;   //Memory pool
  JsonObject& parsed = JSONBuffer.parseObject(programStr);
 //{"SensorId":"000-00000-007","TimeOfCreation":1542192927,"programItems":[{"ProgramItemId":0,"Seconds":21600,"TargetValue":23.0},{"ProgramItemId":1,"Seconds":68400,"TargetValue":18.0}]}
 //{"SensorId":"000-00000-007","TimeOfCreation":1542192927,"programItems":[{"ProgramItemId":0,"Seconds":21600,"TargetValue":23.0},{"ProgramItemId":1,"Seconds":68400,"TargetValue":18.0}]}

  if (!parsed.success()) 
  {   
    Serial.println("Parsing failed");
    delay(500);  
    return(targetTemp);    
  }
  Serial.println("parsed program: " + programStr);
  
  float serverTemperatureValue = parsed["programItems"][0]["TargetValue"];

  int secondsSinceMidnight = second() + 60 * minute() + 3600 * hour();
  Serial.print("secondsSinceMidnight: ");
  Serial.println(secondsSinceMidnight);
  JsonArray&arr=parsed["programItems"];
  JsonArray::iterator it;
  for(it=arr.begin(); it!=arr.end();++it) 
  {
    JsonObject&elem=*it;
    if(elem["Seconds"].as<String>().toInt() < secondsSinceMidnight)
    {
      targetTemp = elem["TargetValue"].as<String>().toFloat();
      Serial.println(elem["Seconds"].as<String>().toInt());
      Serial.println(targetTemp);
    }
  }
  
  //int serverUpdateTime = parsed["TimeOfCreation"];
  return(targetTemp);
}
