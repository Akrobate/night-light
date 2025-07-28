#include "NightLightServer.h"


NightLightServer::NightLightServer(int port) {
    this->server = new AsyncWebServer(port);
}


void NightLightServer::begin() {
    this->server->begin();
}


void NightLightServer::injectBusinessState(BusinessState * business_state) {
    this->business_state = business_state;
}


void NightLightServer::initStaticRoutes() {

    this->server->onNotFound(
        [](AsyncWebServerRequest *request){
            request->send(404, "text/html", "Not found");
        }
    );

    this->server->on(
        "/",
        HTTP_GET,
        [](AsyncWebServerRequest *request){
            request->send_P(200, "text/html; charset=UTF-8", night_light_server_static_index_html);
        }
    );

    this->server->on(
        "/style.css",
        HTTP_GET,
        [](AsyncWebServerRequest *request){
            request->send_P(200, "text/css; charset=UTF-8", night_light_server_static_style_css);
        }
    );

    this->server->on(
        "/index.js",
        HTTP_GET,
        [](AsyncWebServerRequest *request){
            request->send_P(200, "application/javascript; charset=UTF-8", night_light_server_static_index_js);
        }
    );

    this->server->on(
        "/repository.js",
        HTTP_GET,
        [](AsyncWebServerRequest *request){
            request->send_P(200, "application/javascript; charset=UTF-8", night_light_server_static_repository_js);
        }
    );

}


void NightLightServer::init() {

    this->initStaticRoutes();
}
