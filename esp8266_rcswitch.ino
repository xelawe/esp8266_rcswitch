#define serdebug
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



void setup() {
  // put your setup code here, to run once:

#ifdef serdebug
  Serial.begin(115200);
#endif

  DebugPrintln("\n" + String(__DATE__) + ", " + String(__TIME__) + " " + String(__FILE__));


  wifi_init(gv_hostname);
  delay(500);

  init_ota(gv_hostname);

  init_switch();

}

void loop() {
  // put your main code here, to run repeatedly:

  check_ota();

  check_switch();

  send_switch(1);
  delay(2000);
  send_switch(0);
  delay(2000);

  delay(100);

}

