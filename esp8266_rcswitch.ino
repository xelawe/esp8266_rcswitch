//#define serdebug
#ifdef serdebug
#define DebugPrint(...) {  Serial.print(__VA_ARGS__); }
#define DebugPrintln(...) {  Serial.println(__VA_ARGS__); }
#else
#define DebugPrint(...) { }
#define DebugPrintln(...) { }
#endif

#include <Ticker.h>
#include "cy_wifi.h"
#include "cy_ota.h"
#include "cy_weather.h"

#include "rcswitch_tool.h"

const char* gv_hostname = "esprcswitch";


const int button1Pin = 0;     // the number of the pushbutton pin
const int button2Pin = 2;     // the number of the pushbutton pin

int button1State = 0;         // variable for reading the pushbutton status
int button2State = 0;         // variable for reading the pushbutton status



void setup() {
  // put your setup code here, to run once:

#ifdef serdebug
  Serial.begin(115200);
#endif

  DebugPrintln("\n" + String(__DATE__) + ", " + String(__TIME__) + " " + String(__FILE__));


  wifi_init(gv_hostname);
  delay(500);
  
  //  pinMode(button1Pin, INPUT);
  //  pinMode(button2Pin, INPUT);
  //  pinMode(BUILTIN_LED, OUTPUT);
   pinMode(3, OUTPUT);

  init_ota(gv_hostname);

  init_switch();

}

void loop() {
  // put your main code here, to run repeatedly:

  check_ota();

  
  //  button1State = digitalRead(button1Pin);
  //  button2State = digitalRead(button2Pin);
  
  //  if ( (button1State == HIGH) && (button2State == HIGH) ) {
  //    // turn LED off:
  //    //    digitalWrite(BUILTIN_LED, HIGH);
  //  } else {
  //    // one Button pressed
  //    // turn LED on:
  //    //    digitalWrite(BUILTIN_LED, LOW);
  //    if (button1State == LOW) {
  //      send_switch(0);
  //    }
  //    if (button2State == LOW) {
  //      send_switch(1);
  //    }
  //  }

  //check_switch();

  send_switch(1);
  delay(2000);
  send_switch(0);
  delay(2000);

  delay(100);

}

