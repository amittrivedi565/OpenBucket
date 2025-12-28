#include "headers/StorageEngine.h"
#include <filesystem>
#include <fstream>
#include <iostream>

namespace fs = std::filesystem;

bool StorageEngine::putObject(const PutObjectRequest &req) {
    fs::path path = buildObjectPath(req.bucket, req.key);
    fs::create_directories(path.parent_path());

    std::ofstream file(path, std::ios::binary);
    if (!file) return false;

    file << req.data.rdbuf();
    return true;

}

std::string StorageEngine::buildObjectPath(const std::string &bucketName, const std::string &key) {
    return "./data/" + bucketName + "/" + key;
}
