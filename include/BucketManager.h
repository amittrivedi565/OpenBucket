#ifndef OPENBUCKET_BUCKET_H
#define OPENBUCKET_BUCKET_H

#include<string>

class BucketManager {
public:
    BucketManager(const std::string& bucketName);
    bool create() const;
    bool destroy() const;

private:
    std::string bucketName;
    std::string bucketPath;
};

#endif // OPENBUCKET_BUCKET_H
