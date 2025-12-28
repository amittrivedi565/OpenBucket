#include <iostream>
#include "headers/BucketManager.h"
int main() {
    std::cout << "OpenBucket Started" << std::endl;

    BucketManager bucket("pj");

    if (bucket.create()) {
        std::cout << "Bucket created successfully\n";
    } else {
        std::cout << "Bucket already exists or failed\n";
    }
    return 0;
}