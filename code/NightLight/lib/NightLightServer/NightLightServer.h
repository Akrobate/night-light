#pragma once

#include <ESPAsyncWebServer.h>
#include "AsyncJson.h"
#include "ArduinoJson.h"

#include <Updater.h>

#include "static/night_light_server_static_index_html.h"
#include "static/night_light_server_static_style_css.h"
#include "static/night_light_server_static_index_js.h"
#include "static/night_light_server_static_repository_js.h"

#include <BusinessState.h>

class NightLightServer {
    private:
        void initStaticRoutes();

    public:

        AsyncWebServer * server;
        BusinessState * business_state;
        RoundTimer * night_light;
        int channel;

        void injectBusinessState(BusinessState * business_state);

        NightLightServer(int port);

        void init();
        void begin();
};
