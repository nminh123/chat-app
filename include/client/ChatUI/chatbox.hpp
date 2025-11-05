#pragma once

#include <iostream>
#include <vector>
#include <string>

#include <imgui.h>
#include <imgui_impl_opengl3.h>
#include <imgui_impl_glfw.h>

#include "../../../src/shared/include/render_ui.hpp"

class ChatBoxUI : public Utils::RenderUI
{
public:
    ChatBoxUI(const char* partner_name);
    ~ChatBoxUI();
    void init();
    void draw() override;
private:
    const char* partner_name;
};