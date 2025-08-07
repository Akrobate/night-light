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
    Serial.begin(115200); // 74880

    business_state = new BusinessState();
    led_interface = new LedInterface();
    wifi_service = new WifiService();
    night_light_server = new NightLightServer();

    night_light_server->injectBusinessState(business_state);
    wifi_service->injectBusinessState(business_state);

}


void loop() {


    wifi_service->update();
    led_interface->update();
    business_state->update();


}
