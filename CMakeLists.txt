cmake_minimum_required(VERSION 4.1)
project(OpenBucket)

set(CMAKE_CXX_STANDARD 20)

add_executable(OpenBucket main.cpp
        include/BucketManager.h
        lib/BucketManager.cpp
        include/StorageEngine.h
        lib/StorageEngine.cpp
        include/Object.h
)
