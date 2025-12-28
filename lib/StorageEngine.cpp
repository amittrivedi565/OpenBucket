#include "../include/StorageEngine.h"
#include <filesystem>
#include <fstream>
#include <iostream>

namespace fs = std::filesystem;

/**
 *
 * @param req PutObjectRequest Object contains required fields
 * @return true if file saved successfully else false
 */
bool StorageEngine::putObject(const PutObjectRequest &req) {
    fs::path path = buildObjectPath(req.bucket, req.key);
    fs::create_directories(path.parent_path());

    std::ofstream file(path, std::ios::binary);
    if (!file) return false;

    file << req.data.rdbuf();
    return true;

}

/**
 *
 * @param bucketName Bucket name in which content to be saved
 * @param key File's name which to be saved
 * @return Path where the file to be saved
 */
std::string StorageEngine::buildObjectPath(const std::string &bucketName, const std::string &key) {
    return "./data/" + bucketName + "/" + key;
}
