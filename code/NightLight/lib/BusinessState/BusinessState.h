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
        int network_autodisable_delay_seconds= 100;

        

};

