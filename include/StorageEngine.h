#ifndef OPENBUCKET_STORAGE_ENGINE_H
#define OPENBUCKET_STORAGE_ENGINE_H

#include "Object.h"
#include "fstream"
class StorageEngine {
public:
    static bool putObject(Object& obj, std::ifstream& data);
    bool deleteObject(std::string key);
};

#endif //OPENBUCKET_STORAGE_ENGINE_H