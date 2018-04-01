#include <ESP8266HTTPClient.h>
#include <ESP8266WiFi.h>
#include <ArduinoJson.h>

float seconds = 0.0;
 
void setup() {
 
  Serial.begin(115200);                            //Serial connection
  WiFi.begin("SSID", "Password");   //WiFi connection
 
  while (WiFi.status() != WL_CONNECTED) {  //Wait for the WiFI connection completion
 
    delay(500);
    Serial.println("Waiting for connection");
 
  }

pinMode(0, INPUT);
pinMode(2, INPUT);
 
}
 
void loop() {
  
  seconds = seconds+30;
  
  if (WiFi.status() == WL_CONNECTED) { //Check WiFi connection status
 
    StaticJsonBuffer<300> JSONbuffer;   //Declaring static JSON buffer
    JsonObject& JSONencoder = JSONbuffer.createObject(); 
 
    JSONencoder["sensorType"] = "Pin0";
 
    JsonArray& values = JSONencoder.createNestedArray("Valoare"); //JSON array
    values.add(digitalRead(0)); //Add value to array
 
    JsonArray& timestamps = JSONencoder.createNestedArray("Minute"); //JSON array
    timestamps.add(seconds/60); //Add value to array
 
    char JSONmessageBuffer[300];
    JSONencoder.prettyPrintTo(JSONmessageBuffer, sizeof(JSONmessageBuffer));
    Serial.println(JSONmessageBuffer);
 
    HTTPClient http;    //Declare object of class HTTPClient
 
    http.begin("http://alecs220.pythonanywhere.com/postjson");      //Specify request destination
    http.addHeader("Content-Type", "application/json");  //Specify content-type header
 
    int httpCode = http.POST(JSONmessageBuffer);   //Send the request
    String payload = http.getString();                                        //Get the response payload
 
    Serial.println(httpCode);   //Print HTTP return code
    Serial.println(payload);    //Print request response payload
 
    http.end();  //Close connection
 
  } else {
 
    Serial.println("Error in WiFi connection");
 
  }
 
  delay(30000);  //Send a request every 30 seconds
 
}
