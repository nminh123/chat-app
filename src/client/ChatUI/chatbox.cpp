#include "../../../include/client/ChatUI/chatbox.hpp"
using namespace std;

ChatBoxUI::ChatBoxUI(const char* partner_name, ImGuiIO& io) : io(io)
{
    this->partner_name = partner_name;
    init();
}

ChatBoxUI::~ChatBoxUI()
{
    large_font = nullptr;
    delete large_font;
}

void ChatBoxUI::init()
{
    io.Fonts->AddFontDefault();
    large_font = io.Fonts->AddFontFromFileTTF(FONT_PATH, 32);
}

void ChatBoxUI::draw()
{
    ImGui::Begin("CHAT HERE");
    ImVec2 window_size = ImGui::GetWindowSize();
    ImVec2 text_size = ImGui::CalcTextSize(this->partner_name);
    ImGui::SetCursorPosX((window_size.x - text_size.x) * 0.5f);
    ImGui::PushFont(large_font);
    ImGui::Text("%s", partner_name);
    ImGui::PopFont();

    ImGui::InputText(" ", this->inputTextBuffer, sizeof(inputTextBuffer));
    ImGui::SameLine();
    auto send_button = ImGui::Button("Send");
    ImGui::End();
}