#include<Wire.h>
#include<LiquidCrystal_I2C.h>
#include<ESP8266WiFi.h>
#include<Servo.h>
#include<FirebaseArduino.h>
#define FIREBASE_HOST "nodemcu-912e0.firebaseio.com"
#define WIFI_SSID "ASUS"
#define PASSWORD "himansh1314"
LiquidCrystal_I2C lcd(0x27, 16, 2);
Servo gate;
uint8_t pos = 0;
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
  lcd.begin();
  lcd.backlight();
  lcd.print("Welcome");
  gate.attach(D4);
  pinMode(D3, INPUT);
  digitalWrite(D3, HIGH);
  digitalWrite(D3, LOW);
}

void loop() {
  // put your main code here, to run repeatedly:
  arr[0] = Firebase.getFloat("Sensor1");
  arr[1] = Firebase.getFloat("Sensor2");
  arr[2] = Firebase.getFloat("Sensor3");
  arr[3] = Firebase.getFloat("Sensor4");
  Serial.println(arr[0]);
  Serial.println(arr[1]);
  Serial.println(arr[2]);
  Serial.println(arr[3]);
  if(digitalRead(D3)==LOW){
    Serial.println("Checking for parking");
    arr[0] = Firebase.getFloat("Sensor1");
    arr[1] = Firebase.getFloat("Sensor2");
    arr[2] = Firebase.getFloat("Sensor3");
    arr[3] = Firebase.getFloat("Sensor4");
    if((arr[0]&&arr[1]&&arr[2]&&arr[3])){
    lcd.print("Sorry, parking is full");
    Serial.println("Sorry, parking is full");
   }
   else{
    lcd.print("Parking vacant");
    while(pos<90){
      gate.write(pos++);
      delay(10);
    }
    delay(2000);
    while(pos>0){
      gate.write(pos--);
      delay(10);
    }
   }
  }
  Serial.println("====================================================================================");
}
//void checkForParking(){
//   Serial.println("=========================checkForParking Interrupt subroutine invoked!=============================");
//    arr[0] = Firebase.getFloat("Sensor1");
//    arr[1] = Firebase.getFloat("Sensor2");
//    arr[2] = Firebase.getFloat("Sensor3");
//    arr[3] = Firebase.getFloat("Sensor4");
//   if(!(arr[0]&&arr[1]&&arr[2]&&arr[3])){
//    lcd.print("Sorry, parking is full");
//    Serial.println("Sorry, parking is full");
//   }
//   else{
//    lcd.print("Parking vacant");
//    while(pos<90){
//      gate.write(pos++);
//      delay(10);
//    }
//    delay(2000);
//    while(pos>0){
//      gate.write(pos--);
//      delay(10);
//    }
//   }
//}
//void closeGate(){
//  Serial.println("===============================closeGate invoked====================================================");
//  while(pos>0){
//    gate.write(pos--);
//    delay(10);
//  }
//}
