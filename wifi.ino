#include "FirebaseESP8266.h"
#include <ESP8266WiFi.h>

#include <SoftwareSerial.h>

#define WIFI_SSID "V6"
#define WIFI_PASSWORD "123456789"
#define FIREBASE_HOST "https://arotest-2.firebaseio.com"
#define FIREBASE_AUTH "2pqGjjdi7P0rOH912JlgaxZwEFphqEBdK1XFxv3H"

#define localis "L_T_F_40_"
#define erreur "No erreur"
 int vitesse =0;
 String next_path ="___";
 
FirebaseData firebaseData;

void wifiConnect()
{
    Serial.begin(115200);
 // connect to wifi.
  WiFi.begin(WIFI_SSID, WIFI_PASSWORD);
  Serial.print("connecting");
  while (WiFi.status() != WL_CONNECTED) {
    Serial.print(".");
    delay(300);
  }

  int teller = 0;
  while (WiFi.status() != WL_CONNECTED)
  { // Wait for the Wi-Fi to connect
    delay(1000);
    Serial.print(++teller);
    Serial.print(' ');
  }
  Serial.println("Connection established!");
  Serial.print("IP address:\t");
  Serial.println(WiFi.localIP());         // Send the IP address of the ESP8266 to the computer
}

void fire_fail(){

//Failed?, get the error reason from firebaseData

    Serial.print("Error in setting ");
    Serial.println(firebaseData.errorReason());
    }
    
void data_transfer(){
if(Firebase.setInt(firebaseData,"/robot",vitesse))
  {
    //Success
    Serial.println("Set int data success");

  }else{
fire_fail();
  }
delay(10);
if(Firebase.setString(firebaseData,"/robot/erreur", erreur))
  {
    //Success
  Serial.println("Set string data success");

  }else{
fire_fail();
  }
delay(10);
if(Firebase.setString(firebaseData,"/robot/obstacle","hi"))
  {
    //Success
  Serial.println("Set string data success");

  }else{
fire_fail();
  }
delay(10);
if(Firebase.getInt(firebaseData, "/robot/vitesse"))
  {
    //Success
    vitesse=firebaseData.intData();
    Serial.println(vitesse);

  }else{
 fire_fail();
  }
 delay(10); 
if(Firebase.getString(firebaseData, "/robot/next_path"))
  {
    //Success
   // Serial.print("Get string data success, String = ");
     next_path=firebaseData.stringData();
     Serial.println( next_path);

  }else{
 fire_fail();
  }
 delay(10);
return;
}

void data_bridge(){ 
 String message = "";
  while (Serial.available())
    message.concat((char) Serial.read());
  if (message != "")
    Serial.println(message);
  
  delay(1000);
}

void setup()
{
  Serial.begin(115200);
  delay(1000);
  Serial.println('\n');
  wifiConnect();

  Firebase.begin(FIREBASE_HOST, FIREBASE_AUTH);
  Firebase.reconnectWiFi(true);
  delay(30);
  Serial.begin(115200);
while (!Serial) {
; // wait for serial port to connect. Needed for native USB port only
}
}

void loop()
{
  data_transfer();
  Serial.println( next_path+"#"+vitesse);
  data_bridge();
  
  if (WiFi.status() != WL_CONNECTED)
  {
    wifiConnect();
  }
  delay(1000);
}
