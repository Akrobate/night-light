#pragma once

#include <Arduino.h>

class BusinessState {

    public:

        BusinessState();
        String sta_ssid = "";
        String sta_password = "";
        String ap_name = "";
        String ap_password = "";
        
        bool network_enabled = true;
        int network_disable_delay_seconds = 100;

        // Getters
        String getStaSsid() const;
        String getStaPassword() const;
        String getApName() const;
        String getApPassword() const;
        bool isNetworkEnabled() const;
        int getNetworkAutodisableDelaySeconds() const;

        // Setters
        void setStaSsid(const String& s);
        void setStaPassword(const String& p);
        void setApName(const String& name);
        void setApPassword(const String& pass);
        void setNetworkEnabled(bool enabled);
        void setNetworkAutodisableDelaySeconds(int delay);
};

