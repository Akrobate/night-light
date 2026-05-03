#include "BusinessState.h"

BusinessState::BusinessState() {}

// Getters
String BusinessState::getStaSsid() const {
    return sta_ssid;
}

String BusinessState::getStaPassword() const {
    return sta_password;
}

String BusinessState::getApName() const {
    return ap_name;
}

String BusinessState::getApPassword() const {
    return ap_password;
}

bool BusinessState::isNetworkEnabled() const {
    return network_enabled;
}

int BusinessState::getNetworkAutodisableDelaySeconds() const {
    return network_disable_delay_seconds;
}

// Setters
void BusinessState::setStaSsid(const String& s) {
    sta_ssid = s;
}

void BusinessState::setStaPassword(const String& p) {
    sta_password = p;
}

void BusinessState::setApName(const String& name) {
    ap_name = name;
}

void BusinessState::setApPassword(const String& pass) {
    ap_password = pass;
}

void BusinessState::setNetworkEnabled(bool enabled) {
    network_enabled = enabled;
}

void BusinessState::setNetworkAutodisableDelaySeconds(int delay) {
    network_disable_delay_seconds = delay;
}