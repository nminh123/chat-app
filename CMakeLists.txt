cmake_minimum_required(VERSION 3.28)
project(chat-app LANGUAGES C CXX)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)

#==========DEPENDENCIES==========
include_directories(${PROJECT_SOURCE_DIR}/dependencies/include)

#==========GLAD==========
add_library(glad ${PROJECT_SOURCE_DIR}/glad.c)
target_include_directories(glad PUBLIC ${PROJECT_SOURCE_DIR}/dependencies/include)

#==========IMGUI==========
file(GLOB IMGUI_SOURCES
    ${PROJECT_SOURCE_DIR}/*.cpp
)
add_library(imgui ${IMGUI_SOURCES})
target_include_directories(imgui PUBLIC ${PROJECT_SOURCE_DIR}/dependencies/include)
target_link_libraries(imgui PUBLIC glad)

#==========GLFW==========
set(GLFW_LIB ${PROJECT_SOURCE_DIR}/dependencies/library/libglfw.3.4.dylib)

#==========ENET==========
set(ENET_LIB ${PROJECT_SOURCE_DIR}/dependencies/library/libenet.7.dylib)

#==========SHARED==========
file(GLOB_RECURSE SHARED_SOURCES CONFIGURE_DEPENDS src/shared/*.cpp)
add_library(shared ${SHARED_SOURCES})
target_link_libraries(shared PUBLIC glad)
target_include_directories(shared
    PUBLIC
    ${PROJECT_SOURCE_DIR}/include
    ${PROJECT_SOURCE_DIR}/src/shared/include
    ${PROJECT_SOURCE_DIR}/dependencies/include
)

#==========SERVER==========
file(GLOB_RECURSE SERVER_SRC CONFIGURE_DEPENDS src/server/*.cpp)
add_executable(server ${SERVER_SRC})
target_link_libraries(server PRIVATE shared ${ENET_LIB})
target_include_directories(server PRIVATE ${PROJECT_SOURCE_DIR}/include/server)

#==========CLIENT==========
file(GLOB_RECURSE CLIENT_SRC CONFIGURE_DEPENDS src/client/*.cpp)
add_executable(client ${CLIENT_SRC})
target_link_libraries(client
    PRIVATE
    shared
    imgui
    glad
    ${GLFW_LIB}
    "-framework Cocoa"
    "-framework IOKit"
    "-framework CoreVideo"
)
target_include_directories(client PRIVATE ${PROJECT_SOURCE_DIR}/include/client)