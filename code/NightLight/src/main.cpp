#include <Arduino.h>
#include <LedInterface.h>
#include <WifiService.h>
#include <NightLightServer.h>
#include <BusinessState.h>

#include <configurations.h>

LedInterface * led_interface = nullptr;
WifiService * wifi_service = nullptr;
NightLightServer * night_light_server = nullptr;
BusinessState * business_state = nullptr;

void setup() {
    Serial.begin(74880); // 115200
}


void loop() {

}
