#ifndef WEBSERVER_H
#define WEBSERVER_H

#include "module.h"

class WebServer : public Module
{
private:

public:
  WebServer();
  void moduleLoop();
  static void handleRoot();
};
#endif
