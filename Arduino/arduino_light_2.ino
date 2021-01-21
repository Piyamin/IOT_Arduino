#include <ESP8266WiFi.h>              // Include main library
#include <ArduinoHttpClient.h>
#include <ArduinoJson.h>
DynamicJsonDocument doc(256);
const char* ssid     = "A4";
const char* password = "19032542";
const char* host = "thing.tpk-learning.site";
const int httpPort = 80;

int fire = D9;
int motopin4 = D6;
int motopin5 = D5;
int h;
int l;
int w;

#include "DHT.h"
#include <Wire.h>
#include <SPI.h>
#include <BH1750.h>
BH1750 lightMeter;
long distance = 0;
#define DHTTYPE DHT11
#define DHTPIN D4
DHT dht(DHTPIN,DHTTYPE,15);

void setup() {
  Serial.begin(9600);
  pinMode(motopin4,OUTPUT);
  pinMode(motopin5,OUTPUT);
  pinMode(fire,OUTPUT);
  Wire.begin();
  lightMeter.begin();
  
  Serial.print("Connecting to ");
  Serial.println(ssid);
  WiFi.begin(ssid, password);
  while (WiFi.status() != WL_CONNECTED) 
  {
    delay(500);
    Serial.print(".");                // Print WiFi status
  }
  Serial.println("");
  Serial.println("WiFi connected");   // Print connect status
  Serial.println("IP address: ");     
  Serial.println(WiFi.localIP());
}
void loop() {

  uint16_t lux = lightMeter.readLightLevel();
    Serial.print("Light: ");
    Serial.print(lux);
    Serial.println(" lx");
    delay(500);
    if(lux < 60){
      digitalWrite(fire,1);
      l=1;
    }
    else {
      digitalWrite(fire,0);
      l=0;
    }

    
    
  float h = dht.readHumidity();
  Serial.println("\nH : "+String(h,0));
  if(h>60){
    w=1;
    wiper();
  }
  else{
    w=0;
    }
  
  WiFiClient client;
  if (!client.connect(host, httpPort))// Test connection 
  {
    Serial.println("connection failed"); // Print connection fail message
    return;
  }
  HttpClient http = HttpClient(client, host, httpPort);
  Serial.println("updating...");
  String contentType = "application/x-www-form-urlencoded";
  String postData = "status="+String(w);
  http.post("/61105631_IOT/set_wiper_status.php", contentType, postData);
  int statusCode = http.responseStatusCode();
  String response = http.responseBody();
  Serial.print("Status code: ");
  Serial.println(statusCode);
  Serial.print("Response: ");
  Serial.println(response);

  postData = "status="+String(l);
  http.post("/61105631_IOT/set_light_status.php", contentType, postData);
  

 deserializeJson(doc, response);
  String text = doc[0]["status"];
  int signal = text.toInt();
  Serial.println(text);
  delay(1000);

   Serial.println("Wait two seconds");
  for(int i = 0;i<2;i++){
    Serial.print(".");
    delay(1000);
  }
}
void wiper(){
  motoLeft();
  Serial.println("wiper left.");
  delay(1000);
  motoStop();
  delay(500);
  motoRight();
  Serial.println("wiper left.");
  delay(1000);
  motoStop();
}
void motoLeft(){
  digitalWrite(motopin4,1);
  digitalWrite(motopin5,0);
}
void motoRight(){
  digitalWrite(motopin4,0);
  digitalWrite(motopin5,1);
}
void motoStop(){
  digitalWrite(motopin4,0);
  digitalWrite(motopin5,0);
}
