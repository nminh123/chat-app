cmake_minimum_required(VERSION 3.28...4.1.2)
project(chat-app LANGUAGES C CXX)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)

#==========DEOENDENCIES==========
include_directories(
    ${PROJECT_SOURCE_DIR}/dependencies/include
)
#==========GLAD==========
add_library(glad ${PROJECT_SOURCE_DIR}/glad.c)
target_include_directories(glad
    PUBLIC 
        ${PROJECT_SOURCE_DIR}/dependencies/include
)

# ===== Shared Library =====
file(GLOB_RECURSE SHARED_SOURCES CONFIGURE_DEPENDS
    src/shared/*.cpp)
    # ${PROJECT_SOURCE_DIR}/*.cpp)

add_library(shared ${SHARED_SOURCES})
target_link_libraries(shared PUBLIC glad)

target_include_directories(shared
    PUBLIC
        ${PROJECT_SOURCE_DIR}/include
        ${PROJECT_SOURCE_DIR}/src/shared/include
        ${PROJECT_SOURCE_DIR}/dependencies/include
)

#server
add_executable(server src/server/main.cpp)
target_link_libraries(server PRIVATE shared)

#client
add_executable(client src/client/main.cpp)
target_link_libraries(client PRIVATE shared)

#link với client -> server không thể đọc được
target_link_libraries(client
    PRIVATE
        shared
        glad
        "-framework Cocoa"
        "-framework IOKit"
        "-framework CoreVideo"
)

# Link thư viện .dylib trong thư mục /dependencies/library
target_link_libraries(client
    PRIVATE
        ${PROJECT_SOURCE_DIR}/dependencies/library/libglfw.3.4.dylib
        ${PROJECT_SOURCE_DIR}/dependencies/library/libenet.dylib
)
