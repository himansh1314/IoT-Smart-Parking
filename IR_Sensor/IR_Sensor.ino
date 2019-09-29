#include<ESP8266WiFi.h>
#include<FirebaseArduino.h>
#define FIREBASE_HOST "nodemcu-912e0.firebaseio.com"
#define WIFI_SSID "SSID"
#define PASSWORD "PASSWORD"
uint8_t arr[4];
void setup() {
  // put your setup code here, to run once:
  Serial.begin(115200);
  Serial.print("Connecting to Wifi");  
  WiFi.begin (WIFI_SSID, PASSWORD);
   while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
  }
  Serial.println("");
  Serial.println("=================================Connected to WiFi=================================");
  Serial.print("IP Address is");
  Serial.println(WiFi.localIP());
  Serial.println("=====================Attempting to connect to firebase database====================");
  Firebase.begin(FIREBASE_HOST);
  Serial.println("===============================Firebase connected==================================");
  pinMode(D0,INPUT);
  pinMode(D1,INPUT);
  pinMode(D2,INPUT);
  pinMode(D3,INPUT);
  pinMode(D5, OUTPUT);
  pinMode(D6, OUTPUT);
  digitalWrite(D5,HIGH);
  digitalWrite(D6,LOW);
}

void loop() {
  // put your main code here, to run repeatedly:
  arr[0] = digitalRead(D0);
  arr[1] = digitalRead(D1);
  arr[2] = digitalRead(D2);
  arr[3] = digitalRead(D3);
  
  if(!Firebase.failed()){
    
    Serial.println("Sensor 1");
    if(arr[0]==HIGH){
      Firebase.setFloat("Sensor1", 0);
      Serial.println("HIGH");
    }
    else{
      Firebase.setFloat("Sensor1",1);
      Serial.println("LOW");
    }
    Serial.println("Sensor 2");
    if(arr[1]==HIGH){
      Firebase.setFloat("Sensor2",0);
      Serial.println("HIGH");
    }
    else{
      Firebase.setFloat("Sensor2",1);
      Serial.println("LOW");
    }Serial.println("Sensor 3");
    if(arr[2]==HIGH){
      Firebase.setFloat("Sensor3", 0);
      Serial.println("HIGH");
    }
    else{
      Firebase.setFloat("Sensor3",1);
      Serial.println("LOW");
    }
    Serial.println("Sensor 4");
    if(arr[3]==HIGH){
      Firebase.setFloat("Sensor4",0);
      Serial.println("HIGH");
    }
    else{
      Firebase.setFloat("Sensor4",1);
      Serial.println("LOW");
    }    
  }
  else Serial.println("Firebase failed");
  
}
