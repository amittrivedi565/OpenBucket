#ifndef OPENBUCKET_OBJECT_H
#define OPENBUCKET_OBJECT_H

#include <string>

struct Object {
    std::string bucketName;
    std::string key;
    std::string filePath;
    std::uint64_t fileSize;

    Object(std::string bucket,
           std::string key_,
           std::string path,
           std::uint64_t size)
        : bucketName(std::move(bucket)),
          key(std::move(key_)),
          filePath(std::move(path)),
          fileSize(size) {}
};

#endif
