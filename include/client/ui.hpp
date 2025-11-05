#pragma once
#include <iostream>
#include <memory>

#include <GLFW/glfw3.h>
#include <glad/glad.h>
#include <imgui.h>
#include <imgui_impl_opengl3.h>
#include <imgui_impl_glfw.h>

#include "ChatUI/chatbox.hpp"

class UI
{
public:
    void Init(GLFWwindow *window, const char *glsl_version);
    virtual void Update();
    void NewFrame();
    void Render();
    void Shutdown();
private:
    std::unique_ptr<ChatBoxUI> cbu;
};