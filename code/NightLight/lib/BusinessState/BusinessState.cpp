#include "BusinessState.h"

// Constructeur
BusinessState::BusinessState() {}

// Getters
String BusinessState::getStaSsid() const {
    return ssid;
}

String BusinessState::getStaPassword() const {
    return password;
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

int BusinessState::getNetworkDisableDelaySeconds() const {
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

void BusinessState::setNetworkDisableDelaySeconds(int delay) {
    network_disable_delay_seconds = delay;
}