#ifndef OPENBUCKET_BUCKET_H
#define OPENBUCKET_BUCKET_H

#include<string>

class BucketManager {
public:
    explicit BucketManager(const std::string& bucketName);

    bool create() const; // create bucket directory
    bool destroy() const; // remove bucket directory

private:
    std::string bucketName;
    std::string bucketPath;

};

#endif // OPENBUCKET_BUCKET_H
