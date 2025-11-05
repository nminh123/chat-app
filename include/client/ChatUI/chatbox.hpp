#pragma once

#include <iostream>
#include <vector>
#include <string>
#include <memory>
#include <filesystem>

#include <imgui.h>
#include <imgui_impl_opengl3.h>
#include <imgui_impl_glfw.h>

#include "../../../src/shared/include/render_ui.hpp"
#include "../../shared/include/constants.hpp"

class ChatBoxUI : public Utils::RenderUI
{
public:
    ChatBoxUI(const char *partner_name, ImGuiIO& io);
    ~ChatBoxUI();
    void init();
    void draw() override;

private:
    ImGuiIO& io;
    ImFont *large_font, *med_font;
    const char *partner_name;
    char inputTextBuffer[256];
};