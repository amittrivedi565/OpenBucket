#include "include/httplib.h"
#include "include/HttpServer.h"
#include <iostream>

int main() {
    std::cout << "[OpenBucket] Started" << std::endl;
    HttpServer server(8080);
    server.start();
    return 0;
}
