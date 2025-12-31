#include "../include/StorageEngine.h"
#include "../include/Object.h"
#include <filesystem>
#include <fstream>
#include <iostream>

namespace fs = std::filesystem;

/**
 *
 * @param obj Typeof Object class, contains information about content to be uploaded
 * @param data Input stream for saving
 * @return boolean, true if operation is success else false
 */
bool StorageEngine::putObject(Object& obj, std::ifstream& data) {
    try {
        std::string bucketName = obj.bucketName;
        std::string key = obj.key;

        fs::path path = fs::path("./data") / bucketName / key;
        fs::create_directories(path.parent_path());
        std::ofstream file(path, std::ios::binary);
        if (!file) return false;

        file << data.rdbuf();
        file.close();

        obj.filePath = path.string();
        obj.fileSize = fs::file_size(path);
        return true;
    }catch (std::exception& e) {
        std::cerr << e.what() << std::endl;
        return false;
    }
}

/**
 *
 * @param bucketName bucket in which content resides and to be deleted
 * @param key filename which to be deleted
 * @return boolean, true if success else false
 */
bool StorageEngine::deleteObject(const std::string& bucketName, const std::string& key) {
    try {
        fs::path path = fs::path("./data") / bucketName / key;
        fs::remove(path);
        return true;
    }catch (std::exception& e) {
        std::cerr << e.what() << std::endl;
        return false;
    }
}