#include "BusinessState.h"

// Constructeur
BusinessState::BusinessState() {}

// Getters
String BusinessState::getSsid() const {
    return ssid;
}

String BusinessState::getPassword() const {
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

int BusinessState::getNetworkAutodisableDelaySeconds() const {
    return network_autodisable_delay_seconds;
}

// Setters
void BusinessState::setSsid(const String& s) {
    ssid = s;
}

void BusinessState::setPassword(const String& p) {
    password = p;
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
    network_autodisable_delay_seconds = delay;
}