#include "../../../include/client/ChatUI/chatbox.hpp"

ChatBoxUI::ChatBoxUI(const char* partner_name)
{
    this->partner_name = partner_name;
    init();
}

ChatBoxUI::~ChatBoxUI()
{
    
}

void ChatBoxUI::init()
{

}

void ChatBoxUI::draw()
{
    ImGui::Begin("CHAT HERE");
    ImVec2 window_size = ImGui::GetWindowSize();
    ImVec2 text_size = ImGui::CalcTextSize(this->partner_name);
    ImGui::SetCursorPosX((window_size.x - text_size.x) * 0.5f);
    ImGui::Text("%s", partner_name);

    // ImGui::InputText();
    ImGui::End();
}