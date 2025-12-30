#ifndef OPENBUCKET_STORAGE_ENGINE_H
#define OPENBUCKET_STORAGE_ENGINE_H

#include "Object.h"
#include "fstream"
class StorageEngine {
public:
    bool putObject(Object& obj, std::ifstream& data);
    bool deleteObject(const std::string& bucketName, const std::string& key);
};

#endif //OPENBUCKET_STORAGE_ENGINE_H