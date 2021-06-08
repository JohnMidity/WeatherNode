#include "WebServer.h"
#include <ESP8266WebServer.h>

ESP8266WebServer server(80);

WebServer::WebServer()
{
    server.on("/", WebServer::handleRoot);
    server.begin();
}

void WebServer::moduleLoop()
{
    server.handleClient();
}

void WebServer::handleRoot()
{
    digitalWrite(13, 1);
    server.send(200, "text/plain", "Hello from weatherstation!\r\n");
    digitalWrite(13, 0);
}

