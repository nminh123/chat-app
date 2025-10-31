cmake_minimum_required(VERSION 3.28...4.2)
project(chat-app LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)

include(FetchContent)
FetchContent_Declare(ENET
    GIT_REPOSITORY https://github.com/lsalzman/enet.git
    GIT_TAG 2662c0de09e36f2a2030ccc2c528a3e4c9e8138a
    GIT_SHALLOW ON
    EXCLUDE_FROM_ALL
    SYSTEM)

FetchContent_Declare(IMGUI
    GIT_REPOSITORY https://github.com/ocornut/imgui.git
    GIT_TAG 9a5d5c45f54b1301ea471622eddede70384243af
    GIT_SHALLOW ON
    EXCLUDE_FROM_ALL
    SYSTEM)
FetchContent_MakeAvailable(ENET IMGUI)

file(GLOB_RECURSE SHARED_SOURCES CONFIGURE_DEPENDS src/shared/*.cpp)
add_library(shared ${SHARED_SOURCES})

target_include_directories(shared
        PUBLIC
            ${PROJECT_SOURCE_DIR}/include
            ${PROJECT_SOURCE_DIR}/src/shared/include
            ${enet_SOURCE_DIR}/include
            ${imgui_SOURCE_DIR}/*)
target_link_libraries(shared PUBLIC enet)

#server
add_executable(server src/server/main.cpp)
target_link_libraries(server PRIVATE shared)

#client
add_executable(client src/client/main.cpp)
target_link_libraries(client PRIVATE shared)