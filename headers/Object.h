#ifndef OPENBUCKET_OBJECT_H
#define OPENBUCKET_OBJECT_H
#include <string>

struct Object {
    std::string bucketName;
    std::string key;
    std::string filePath;
    std::uint64_t fileSize;
};

#endif //OPENBUCKET_OBJECT_H