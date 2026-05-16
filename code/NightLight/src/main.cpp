#include <Arduino.h>
#include <LightAnimation.h>
#include <WifiService.h>
#include <NightLightServer.h>
#include <BusinessState.h>

#include <configurations.h>

LightAnimation * light_animation = nullptr;
WifiService * wifi_service = nullptr;
NightLightServer * night_light_server = nullptr;
BusinessState * business_state = nullptr;

void setup() {
    Serial.begin(115200);

    business_state = new BusinessState();
    light_animation = new LightAnimation();
    wifi_service = new WifiService();
    night_light_server = new NightLightServer(SERVER_PORT);

    night_light_server->injectBusinessState(business_state);
    wifi_service->injectBusinessState(business_state);

}


void loop() {

    wifi_service->update();
    light_animation->update();
}
