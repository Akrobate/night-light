#pragma once

#include <Arduino.h>

class BusinessState {

    public:

        BusinessState();
        String ssid = "";
        String password = "";
        String ap_name = "";
        String ap_password = "";
        
        bool network_enabled = true;
        int network_autodisable_delay_seconds = 100;

        // Getters
        String getSsid() const;
        String getPassword() const;
        String getApName() const;
        String getApPassword() const;
        bool isNetworkEnabled() const;
        int getNetworkAutodisableDelaySeconds() const;

        // Setters
        void setSsid(const String& s);
        void setPassword(const String& p);
        void setApName(const String& name);
        void setApPassword(const String& pass);
        void setNetworkEnabled(bool enabled);
        void setNetworkAutodisableDelaySeconds(int delay);
};

