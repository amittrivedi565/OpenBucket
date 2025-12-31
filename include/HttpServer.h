#ifndef OPENBUCKET_HTTPSERVER_H
#define OPENBUCKET_HTTPSERVER_H
#include "httplib.h"

class HttpServer {
public:
    explicit HttpServer(int port = 8080);
    void start();
private:
    void registerRoutes();
    httplib::Server server;
    int port;
};
#endif //OPENBUCKET_HTTPSERVER_H