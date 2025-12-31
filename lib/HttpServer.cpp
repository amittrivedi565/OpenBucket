#include "../include/httpServer.h"
#include "../include/BucketManager.h"
#include <iostream>

/**
 * Default constructor used to init HTTP server port and to register all routes
 * @param port HTTP server port implicitly passed
 */
HttpServer::HttpServer(int port) : port(port) {
    registerRoutes();
}

/**
 * All the HTTP server endpoints to be created here and register them
 */
void HttpServer::registerRoutes() {

    server.Post("/bucket/create",
        [](const httplib::Request& req, httplib::Response& res) {
            std::cout << "Create Request from: "
                      << req.remote_addr << std::endl;

            const std::string bucketName = req.body;

            if (bucketName.empty()) {
                res.status = 400;
                res.set_content("bucket name is required", "text/plain");
                return;
            }

            const BucketManager bm(bucketName);

            if (bm.create()) {
                res.status = 200;
                res.set_content("Bucket Created", "text/plain");
            } else {
                res.status = 400;
                res.set_content("Bucket Already Exists", "text/plain");
            }
        }
    );

    server.Post("/bucket/delete",
        [](const httplib::Request& req, httplib::Response& res) {
            std::cout << "Delete Request from: "
                      << req.remote_addr << std::endl;

            const std::string bucketName = req.body;

            if (bucketName.empty()) {
                res.status = 400;
                res.set_content("bucket name is required", "text/plain");
                return;
            }

            BucketManager bm(bucketName);

            if (bm.destroy()) {
                res.status = 200;
                res.set_content("Bucket Deleted", "text/plain");
            } else {
                res.status = 409;
                res.set_content(
                    "Bucket not empty or does not exist",
                    "text/plain"
                );
            }
        }
    );
}

/**
 * Start HTTP server
 */
void HttpServer::start() {
    std::cout << "Server started at http://localhost:" << port << "\n";
    server.listen("0.0.0.0", port);
}
