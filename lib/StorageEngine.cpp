#include "../include/StorageEngine.h"
#include "../include/Object.h"
#include <filesystem>
#include <fstream>
#include <iostream>

namespace fs = std::filesystem;

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