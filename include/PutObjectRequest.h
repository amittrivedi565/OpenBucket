#ifndef OPENBUCKET_PUT_OBJECT_REQUEST_H
#define OPENBUCKET_PUT_OBJECT_REQUEST_H

#include <string>
#include <istream>

struct PutObjectRequest {
    std::string bucket;
    std::string key;
    std::istream& data;      // streaming upload
};

#endif
