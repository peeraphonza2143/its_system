#include "FirebaseESP8266.h"
#include <ESP8266WiFi.h>
#define FIREBASE_HOST "its-system-93dd1.firebaseio.com"
#define FIREBASE_AUTH "qOaIA3hJoqTuXnO4vKDSPuPUd9NOjKXwGvpQuvrV"
#define WIFI_SSID "vivo 1907"
#define WIFI_PASSWORD "ployploy"
int Room1 = 0;
int Room2 = 0;
int Room3 = 0;
int Room4 = 0;
int Room5 = 0;
int Room6 = 0;
int Status_Room1 = 0;
int Status_Room2 = 0;
int Status_Room3 = 0;
int Status_Room4 = 0;
int Status_Room5 = 0;
int Status_Room6 = 0;
int Room11, Room22, Room33, Room44, Room55, Room66;
#define Button_1  D1
#define Button_2  D2
#define Button_3  D3
#define Button_4  D4
#define Button_5  D5
#define Button_6  D6
FirebaseData firebaseData;
String Full;
FirebaseJson json;
void printResult(FirebaseData &data);

void setup()
{

  Serial.begin(115200);
  pinMode(Button_1, INPUT_PULLUP); //Button1
  pinMode(Button_2, INPUT_PULLUP); //Button2
  pinMode(Button_3, INPUT_PULLUP); //Button3
  pinMode(Button_4, INPUT_PULLUP); //Button4
  pinMode(Button_5, INPUT_PULLUP); //Button5
  pinMode(Button_6, INPUT_PULLUP); //Button6
  pinMode(D7, OUTPUT);
  pinMode(D8, OUTPUT);
  pinMode(D9, OUTPUT);
  pinMode(D10, OUTPUT);
  WiFi.begin(WIFI_SSID, WIFI_PASSWORD);
  Serial.print("Connecting to Wi-Fi");
  while (WiFi.status() != WL_CONNECTED)
  {
    Serial.print(".");
    delay(300);
  }
  Serial.println();
  Serial.print("Connected with IP: ");
  Serial.println(WiFi.localIP());
  Serial.println();

  Firebase.begin(FIREBASE_HOST, FIREBASE_AUTH);
  Firebase.reconnectWiFi(true);
  digitalWrite(D7, LOW);
  digitalWrite(D8, LOW);
  digitalWrite(D9, LOW);
  digitalWrite(D10, LOW);
}

void loop()
{ Room11 = digitalRead(Button_1);
  Room22 = digitalRead(Button_2);
  Room33 = digitalRead(Button_3);
  Room44 = digitalRead(Button_4);
  Room55 = digitalRead(Button_5);
  Room66 = digitalRead(Button_6);
  //Woman
  if (Status_Room1 == 0)
  {
    if (Room11 == 0)
    { digitalWrite(D7, HIGH);
      Firebase.setDouble(firebaseData, "/Floor3/Position1/Woman/Room3", Room3 = 1);
      Room11 = 1;
      delay(200);
      Status_Room1 = 1;

    }

  }
  if (Status_Room1 == 1)
  {
    if (Room11 == 0)
    { digitalWrite(D7, LOW);
      Firebase.setDouble(firebaseData, "/Floor3/Position1/Woman/Room3", Room3 = 0);
      Room11 = 1;
      delay(200);
      Status_Room1 = 0;
    }

  }

  if (Status_Room2 == 0)
  {
    if (Room22 == 0)
    { digitalWrite(D8, HIGH);
      Firebase.setDouble(firebaseData, "/Floor3/Position1/Woman/Room2", Room2 = 1);
      Room22 = 1;
      delay(200);
      Serial.print("ON");
      Status_Room2 = 1;

    }

  }

  if (Status_Room2 == 1)
  {
    if (Room22 == 0)
    { digitalWrite(D8, LOW);
      Firebase.setDouble(firebaseData, "/Floor3/Position1/Woman/Room2", Room2 = 0);
      Room22 = 1;
      delay(200);
      Status_Room2 = 0;
    }

  }

  if (Status_Room3 == 0)
  {
    if (Room33 == 0)
    {
      Firebase.setDouble(firebaseData, "/Floor3/Position1/Woman/Room1", Room1 = 1);
      Room33 = 1;
      delay(200);
      Status_Room3 = 1;

    }

  }

  if (Status_Room3 == 1)
  {
    if (Room33 == 0)
    {
      Firebase.setDouble(firebaseData, "/Floor3/Position1/Woman/Room1", Room1 = 0);
      Room33 = 1;
      delay(200);
      Status_Room3 = 0;
    }

  }
  //MAN
  if (Status_Room4 == 0)
  {
    if (Room44 == 0)
    { 
      Firebase.setDouble(firebaseData, "/Floor3/Position1/MAN/Room3", Room3 = 1);
      Room44 = 1;
      delay(200);
      Status_Room4 = 1;

    }

  }

  if (Status_Room4 == 1)
  {
    if (Room44 == 0)
    { 
      Firebase.setDouble(firebaseData, "/Floor3/Position1/MAN/Room3", Room3 = 0);
      Room44 = 1;
      delay(200);
      Status_Room4 = 0;
    }

  }

  if (Status_Room5 == 0)
  {
    if (Room55 == 0)
    { digitalWrite(D9, HIGH);
      Firebase.setDouble(firebaseData, "/Floor3/Position1/MAN/Room2", Room2 = 1);
      Room55 = 1;
      delay(200);
      Status_Room5 = 1;

    }

  }

  if (Status_Room5 == 1)
  {
    if (Room55 == 0)
    { digitalWrite(D9, LOW);
      Firebase.setDouble(firebaseData, "/Floor3/Position1/MAN/Room2", Room2 = 0);
      Room55 = 1;
      delay(200);
      Status_Room5 = 0;
    }

  }

  if (Status_Room6 == 0)
  {
    if (Room66 == 0)
    { digitalWrite(D10, HIGH);
      Firebase.setDouble(firebaseData, "/Floor3/Position1/MAN/Room1", Room1 = 1);
      Room66 = 1;
      delay(200);
      Status_Room6 = 1;

    }

  }

  if (Status_Room6 == 1)
  {
    if (Room66 == 0)
    { digitalWrite(D10, LOW);
      Firebase.setDouble(firebaseData, "/Floor3/Position1/MAN/Room1", Room1 = 0);
      Room66 = 1;
      delay(200);
      Status_Room6 = 0;
    }

  }

}
