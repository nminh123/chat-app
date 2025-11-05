#pragma once

#include <GLFW/glfw3.h>
#include <glad/glad.h>

#include "ChatUI/chatbox.hpp"

typedef std::unique_ptr<ChatBoxUI> cbu_uptr;

class UI
{
public:
    void Init(GLFWwindow *window, const char *glsl_version);
    virtual void Update();
    void NewFrame();
    void Render();
    void Shutdown();
private:
    cbu_uptr cbu;
};