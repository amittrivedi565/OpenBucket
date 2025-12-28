#include "headers/BucketManager.h"
#include <filesystem>
#include <iostream>

namespace fs = std::filesystem;

/**
 * BucketManager.cpp
 * Implementation of create & destroy bucket operations
 */

/**
 * Default constructor
 * Initializes bucket name and path
 */
BucketManager::BucketManager(const std::string &bucketName){
    this->bucketName = bucketName;
    this->bucketPath = "./data/" + this->bucketName;
}

/**
 * Create Bucket
 * @return return true if bucket create success else false.
 */
bool BucketManager::create() const{
    try {
        return fs::create_directories(this->bucketPath);
    } catch (const fs::filesystem_error& e) {
        std::cerr << "Bucket create failed: " << e.what() << std::endl;
        return false;
    }
}

/**
 * Destroy Bucket
 * @return true if bucket deletion success else false
 */
bool BucketManager::destroy() const{
    try {
        return fs::remove(this->bucketPath);
    } catch (const fs::filesystem_error& e) {
        std::cerr << "Bucket destroy failed: " << e.what() << std::endl;
        return false;
    }
}


