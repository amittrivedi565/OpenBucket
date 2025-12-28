#ifndef OPENBUCKET_STORAGE_ENGINE_H
#define OPENBUCKET_STORAGE_ENGINE_H

#include "PutObjectRequest.h"
class StorageEngine {
public:
    bool putObject(const PutObjectRequest& req);
private:
    std::string buildObjectPath(const std::string& bucketName, const std::string& key);
};

#endif //OPENBUCKET_STORAGE_ENGINE_H