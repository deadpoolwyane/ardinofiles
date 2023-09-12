#ifdef ESP32
  #include <WiFi.h>
#else
  #include <ESP8266WiFi.h>
#endif
#include <WiFiClientSecure.h>
#include <UniversalTelegramBot.h>   // Universal Telegram Bot Library written by Brian Lough: https://github.com/witnessmenow/Universal-Arduino-Telegram-Bot
#include <ArduinoJson.h>

// Replace with your network credentials
const char* ssid = "Acutrotechnologies";
const char* password = "acutro@1234$$";

// Initialize Telegram BOT
#define BOTtoken "5911456817:AAHYcQvJYYiWRXZ1zRWty8l80EKElHXIK9c"  // your Bot Token (Get from Botfather)

// Use @myidbot to find out the chat ID of an individual or a group
// Also note that you need to click "start" on a bot before it can
// message you
#define CHAT_ID "5786536176"

#ifdef ESP8266
  X509List cert(TELEGRAM_CERTIFICATE_ROOT);
#endif

WiFiClientSecure client;
UniversalTelegramBot bot(BOTtoken, client);

// Checks for new messages every 1 second.
int botRequestDelay = 1000;
unsigned long lastTimeBotRan;


const int ledPin = D2;
bool ledState = LOW;
const int LedPin1 = D6;
bool LedState1 = LOW;

// Handle what happens when you receive new messages
void handleNewMessages(int numNewMessages) {
  Serial.println("handleNewMessages");
  Serial.println(String(numNewMessages));

  for (int i=0; i<numNewMessages; i++) {
    // Chat id of the requester
    String chat_id = String(bot.messages[i].chat_id);
    if (chat_id != CHAT_ID){
      bot.sendMessage(chat_id, "Unauthorized user", "");
      continue;
    }
    for (int j=0; j<numNewMessages; j++){
      String chat_id = String(bot.messages[j].chat_id);
      if (chat_id !=CHAT_ID){
        bot.sendMessage(chat_id, "Unauthorized user","");
        continue;
      }
    }
   
    // Print the received message
    String text = bot.messages[i].text;
    Serial.println(text);
   // String textln = bot.messages[j].textln;
    //Serial.println(textln);
   
    String from_name = bot.messages[i].from_name;
   //String from_name = bot.messages[j].from_name;
   

    if (text == "/start") {
      String welcome = "Welcome, " + from_name + ".\n";
      welcome += "Use the following commands to control your outputs.\n\n";
      welcome += "/led_on to turn firstled ON \n";
      welcome += "/led_off to turn firstled OFF \n";
      welcome += "/led1_on to turn secondled ON \n";
      welcome += "/led1_off to turn secondled OFF \n";
      welcome += "/state to request current GPIO state \n";
      bot.sendMessage(chat_id, welcome, "");
    }

    if (text == "/led_on") {
      bot.sendMessage(chat_id, "LED state set to ON", "");
      ledState = HIGH;
      digitalWrite(ledPin, ledState);
    }
   
    if (text == "/led_off") {
      bot.sendMessage(chat_id, "LED state set to OFF", "");
      ledState = LOW;
      digitalWrite(ledPin, ledState);
    }
    if (text == "/Led1_on") {
      bot.sendMessage(chat_id, "LED1 state set to ON", "");
      LedState1 = HIGH;
      digitalWrite(LedPin1, LedState1);
    }
   
    if (text == "/Led1_off") {
      bot.sendMessage(chat_id, "LED1 state set to OFF", "");
      LedState1 = LOW;
      digitalWrite(LedPin1, LedState1);
    }
   
    if (text == "/state") {
      if (digitalRead(ledPin)){
        bot.sendMessage(chat_id, "LED is ON", "");
      }
      else{
        bot.sendMessage(chat_id, "LED is OFF", "");
      }
      if (text == "/state"){
        if (digitalRead(LedPin1)){
          bot.sendMessage(chat_id,"LED1 is ON","");
        }
        else{
          bot.sendMessage(chat_id,"LED1 is OFF","");
        }
        if (text == "/mq3")
        {
          bot . sendmessage(chat_id,"mq3 detected");
        }
        }
      }
    }
  }
void setup() {
  Serial.begin(115200);

  #ifdef ESP8266
    configTime(0, 0, "pool.ntp.org");      // get UTC time via NTP
    client.setTrustAnchors(&cert); // Add root certificate for api.telegram.org
  #endif

  pinMode(ledPin, OUTPUT);
  digitalWrite(ledPin, ledState);
  pinMode(LedPin1, OUTPUT);
  digitalWrite(LedPin1, LedState1);
  pinMode (A0,INPUT);
 
  // Connect to Wi-Fi
  WiFi.mode(WIFI_STA);
  WiFi.begin(ssid, password);
  #ifdef ESP32
    client.setCACert(TELEGRAM_CERTIFICATE_ROOT); // Add root certificate for api.telegram.org
  #endif
  while (WiFi.status() != WL_CONNECTED) {
    delay(1000);
    Serial.println("Connecting to WiFi..");
  }
  // Print ESP32 Local IP Address
  Serial.println(WiFi.localIP());
}

void loop() {
  if (millis() > lastTimeBotRan + botRequestDelay)  {
    int numNewMessages = bot.getUpdates(bot.last_message_received + 1);

    while(numNewMessages) {
      Serial.println("got response");
      handleNewMessages(numNewMessages);
      numNewMessages = bot.getUpdates(bot.last_message_received + 1);
    }
    lastTimeBotRan = millis();
  }
  int Sensorvalue= analogRead (A0);
  Serial.print ("value");
  Serial.println (Sensorvalue);
  if (Sensorvalue>200)
  {
    bot.sendmessage(chat_id,"detected");
    Serial.println ("detected");
    delay (1000);
  }
}
