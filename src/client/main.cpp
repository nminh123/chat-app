#include <iostream>
#include <GLFW/glfw3.h>
#include <glad/glad.h>
#include "../../shared/include/constants.hpp"

void framebuffer_size_callback(GLFWwindow *window, int width, int height)
{
    // adjust viewport khi cửa sổ thay đổi kích thước
    glViewport(0, 0, width, height);
}

void processInput(GLFWwindow *window)
{
    // đóng cửa sổ khi nhấn ESC
    if (glfwGetKey(window, GLFW_KEY_SPACE) == GLFW_PRESS)
        glfwSetWindowShouldClose(window, true);
}

int main(int argc, char **argv)
{
    // 1) Khởi tạo GLFW
    if (!glfwInit())
    {
        std::cerr << "Failed to initialize GLFW\n";
        return -1;
    }

    // Yêu cầu OpenGL 3.3 core (thay đổi nếu cần)
    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
#ifdef __APPLE__
    glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE); // macOS
#endif

    // 2) Tạo cửa sổ
    const int SCR_WIDTH = 800;
    const int SCR_HEIGHT = 600;
    GLFWwindow *window = glfwCreateWindow(SCR_WIDTH, SCR_HEIGHT, "GLFW + GLAD Window", nullptr, nullptr);
    if (!window)
    {
        std::cerr << "Failed to create GLFW window\n";
        glfwTerminate();
        return -1;
    }
    glfwMakeContextCurrent(window);

    // 3) Khởi tạo GLAD (load OpenGL function pointers)
    if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress))
    {
        std::cerr << "Failed to initialize GLAD\n";
        glfwDestroyWindow(window);
        glfwTerminate();
        return -1;
    }

    // Thiết lập viewport và callback khi resize
    glViewport(0, 0, SCR_WIDTH, SCR_HEIGHT);
    glfwSetFramebufferSizeCallback(window, framebuffer_size_callback);

    // Vòng lặp chính
    while (!glfwWindowShouldClose(window))
    {
        // input
        processInput(window);

        // render - đây chỉ là clear screen với màu
        glClearColor(0.12f, 0.18f, 0.24f, 1.0f); // hơi tối
        glClear(GL_COLOR_BUFFER_BIT);

        // -- ở đây bạn vẽ các đối tượng OpenGL --

        // swap buffers và poll events
        glfwSwapBuffers(window);
        glfwPollEvents();
    }

    // dọn dẹp
    glfwDestroyWindow(window);
    glfwTerminate();
    return 0;
}