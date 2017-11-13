#include <ESP8266WiFi.h>
#include <FirebaseArduino.h>

#define FIREBASE_HOST "arduinotest-bd257.firebaseio.com"
#define FIREBASE_AUTH "zs5QPYC5PiVIzFdJ1HAuLLJFJ8KJMPHKHPbgaLU2"
#define WIFI_SSID "ClassicHertz"
#define WIFI_PASSWORD "Cl@ssicH3rtz"

#define deviceID "/parkings/taecP4HPL6NMiUdoXFQyVQc8gLp2"
#define lat " -1.3363068"
#define longit "36.77572380000004"

#define echoPin D7 // Echo Pin
#define trigPin D6 // Trigger Pin
 
long duration, distance; // Duration used to calculate distance


#define ledRed D8 
#define ledGreen D5
 
void setup() {
  Serial.begin (9600);
pinMode(trigPin, OUTPUT);
pinMode(echoPin, INPUT);


  // connect to wifi.
  WiFi.begin(WIFI_SSID, WIFI_PASSWORD);
  Serial.print("connecting");
  while (WiFi.status() != WL_CONNECTED) {
    Serial.print(".");
    delay(500);
  }
  Serial.println();
  Serial.print("connected: ");
  Serial.println(WiFi.localIP());
  
  Firebase.begin(FIREBASE_HOST, FIREBASE_AUTH);
}



void loop() {
// digitalWrite(trigPin, LOW);
// delayMicroseconds(2);
// digitalWrite(trigPin, HIGH);
//  delayMicroseconds(10);
//  digitalWrite(trigPin, LOW);
//  duration = pulseIn(echoPin, HIGH);
//  //Calculate the distance (in cm) based on the speed of sound.
//  distance = duration/58.2;
//  Serial.println(distance);
  //Delay 50ms before next reading.
  
  // if ( distance > 20 ) {
     StaticJsonBuffer<200> jsonBuffer;
        JsonObject& root = jsonBuffer.createObject();
        root["latitude"] = lat;
        root["longitude"] = longit;
     Firebase.push( "/parkings/" , root);
         if (Firebase.failed()) {
        Serial.print("setting /number failed:");
        Serial.println(Firebase.error());  
        return;
        }
   // } else {
      // remove value
    //  Firebase.remove(deviceID);

 // }
 delay(1000);
}
