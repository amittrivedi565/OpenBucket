#ifndef OPENBUCKET_STORAGE_ENGINE_H
#define OPENBUCKET_STORAGE_ENGINE_H

#include "Object.h"

class StorageEngine {
public:
    static bool putObject(Object obj);
    static bool deleteObject(Object obj);
};

#endif //OPENBUCKET_STORAGE_ENGINE_H