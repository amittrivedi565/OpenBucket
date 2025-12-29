cmake_minimum_required(VERSION 4.1)
project(OpenBucket)

set(CMAKE_CXX_STANDARD 20)

add_executable(OpenBucket main.cpp
        lib/BucketManager.cpp
        include/BucketManager.h
        include/StorageEngine.h
        include/Object.h
        http/httplib.h
)
