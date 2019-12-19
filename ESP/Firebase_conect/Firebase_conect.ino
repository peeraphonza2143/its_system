//Supreme Timer Dashboard

#include <ESP8266WiFi.h>
#include <FirebaseArduino.h>
        
//AIzaSyAbvdZwPhaA2tCtHV10GGHqLVhg4Lqi1GE
//EYrotbmNwLmQzouQg5ro3C8mR3HF7JqB1eeDEFuw
// Set these to run example.
#define FIREBASE_HOST "thaisupremerobot.firebaseio.com"
#define FIREBASE_AUTH "EYrotbmNwLmQzouQg5ro3C8mR3HF7JqB1eeDEFuw"
#define WIFI_SSID "peeraphon"
#define WIFI_PASSWORD "0981545067"

#define INTERVAL 1000

#define ON  0
#define OFF 1

// Timer variable 
int mm = 0; 
int ss = 0; 
int ms = 0;
bool flagStart = 0;
String timeString = "";
String mStr = "";
String sStr = "";

unsigned long previousMillis = 0;

//Sensor Pin 
int sensorStart = D6; 
int sensorStop  = D7;

void setup() {
  Serial.begin(9600);

  //Set pinMode 
  pinMode(sensorStart, INPUT); 
  pinMode(sensorStop, INPUT);
  pinMode(LED_BUILTIN, OUTPUT);
  
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

void setTimeString(){
  if(mm < 10) {mStr = "0" + String(mm);} 
  if(mm >= 10) {mStr = String(mm);}
  if(ss < 10) {sStr = "0" + String(ss);}
  if(ss >= 10) {sStr = String(ss);}
  timeString = mStr + ":" + sStr;
}

void loop() {

    if(flagStart == 0){
      if(digitalRead(sensorStart) == ON){
        flagStart = 1;
        digitalWrite(LED_BUILTIN, HIGH);
      }
    }
    
    if(flagStart == 1){
      if(digitalRead(sensorStop) == OFF){
        //Timer On
        unsigned long currentMillis = millis();
        if(currentMillis - previousMillis <= INTERVAL){
          ms++;
        }
        else{
          ms=0;
          previousMillis = currentMillis;
          if(++ss > 59){
            ss = 0;
            mm++; 
            if(mm > 59){
              mm = 0;
            }
          }

          //Update time to Firebase
          setTimeString();
          Firebase.setString("timer1", timeString);
        }
      }
      else if(digitalRead(sensorStop) == ON){
        flagStart = 0;
        mm = ss = ms = 0;
        timeString="";
        digitalWrite(LED_BUILTIN, LOW);
      }
    }
}
