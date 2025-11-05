#include "../../include/client/ui.hpp"

void ProcessExitInput(GLFWwindow* window, bool should_close)
{
    if(glfwGetKey(window, GLFW_KEY_TAB) == GLFW_PRESS)
    {
        std::cout << "Window closing" << std::endl;
        glfwSetWindowShouldClose(window, should_close);
    }
}

int main(int argc, char **argv)
{
    if (!glfwInit())
    {
        std::cerr << "Cannot initialize glfw" << std::endl;
        return 1;
    }
    const char *glsl_version = "#version 410 core";
    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 4);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 1);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE); // 3.2+ only
    glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE);           // Required on Mac
    glfwWindowHint(GLFW_RESIZABLE, GLFW_FALSE);
    glfwWindowHint(GLFW_POSITION_X, 0);
    glfwWindowHint(GLFW_POSITION_Y, 0);

    // Create window with graphics context
    GLFWwindow *window = glfwCreateWindow(SCREEN_WIDTH, SCREEN_HEIGHT, "Chat App", NULL, NULL);
    if (window == NULL)
        return 1;
    glfwMakeContextCurrent(window);
    glfwSwapInterval(1); // Enable vsync

    if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress))
        throw("Unable to context to OpenGL");

    // int screen_width, screen_height;
    // glfwGetFramebufferSize(window, &screen_width, &screen_height);
    // glViewport(0, 0, screen_width, screen_height);

    UI ui;
    ui.Init(window, glsl_version);
    while(!glfwWindowShouldClose(window))
    {
        glfwPollEvents();
		glClearColor(0.1f, 0.105f, 0.11f, 1.0f);
		glClear(GL_COLOR_BUFFER_BIT);
        ui.NewFrame();
        ui.Update();
        ui.Render();
        glfwSwapBuffers(window);
        ProcessExitInput(window, true);
    }
    ui.Shutdown();
    glfwTerminate();
    return 0;
}